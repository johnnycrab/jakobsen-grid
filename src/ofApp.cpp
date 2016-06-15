#include "ofApp.h"
#include <math.h>

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    
    ofVec3f camTarget;
    camTarget.set(ofGetWidth()/2, ofGetHeight()/2, 0);
    cam.setTarget(camTarget);

    setupGUI();
    
    // REGISTER GRID DISPLAYS HERE!
    
    registerGridDisplay(&meshDisplay, "mesh");
    registerGridDisplay(&circlesDisplay, "circles");
    registerGridDisplay(&triangleDisplay, "triangles");
    registerGridDisplay(&simpleLinesDisplay, "simple lines");
    registerGridDisplay(&squareDisplay, "simple squares");
    registerGridDisplay(&rawDisplay, "raw lines");
    registerGridDisplay(&squareGroupsDisplay, "square groups");
    registerGridDisplay(&ringDisplay, "rings");
    registerGridDisplay(&linesDisplay, "testing");
    // ---
    setupShape();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    grid.update();
    
    for (int i=0; i<gridDisplays.size();i++) {
        gridDisplays.at(i)->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor::white);
    ofEnableAlphaBlending();
//    ofEnableDepthTest();
    
//    cam.begin();
    
    if (saveSvg) {
        ofBeginSaveScreenAsSVG("output.svg");
    }
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    grid.draw();
    for (int i=0; i<gridDisplays.size();i++) {
        if (gridDisplays.at(i)->toggle) {
            gridDisplays.at(i)->draw();
        }
    }
    
    ofPopMatrix();

  //  cam.end();
  //  ofDisableDepthTest();
    
    if (saveSvg) {
        saveSvg = false;
        ofEndSaveScreenAsSVG();
    }
    
    if (doDrawGui) {
        gui.draw();
    }
}

// Register a grid display
void ofApp::registerGridDisplay(GridDisplay* display, string name) {
    gridDisplays.push_back(display);
    gui.add(display->toggle.setup("Show " + name, false));
}

// --------- GUI stuff

void ofApp::setupGUI() {
    gui_gridWidth.addListener(this, &ofApp::gridWidthChanged);
    gui_gridHeight.addListener(this, &ofApp::gridHeightChanged);
    gui_pointDistance.addListener(this, &ofApp::pointDistanceChanged);
    gui_numOfPointsToMove.addListener(this, &ofApp::numOfPointsToMoveChanged);
    gui_randomXOffset.addListener(this, &ofApp::randomXOffsetChanged);
    gui_randomYOffset.addListener(this, &ofApp::randomYOffsetChanged);
    gui_randomZOffset.addListener(this, &ofApp::randomZOffsetChanged);
    
    gui.setup();
    gui.add(gui_gridWidth.setup("Num of rows", gridWidth, 1, 100));
    gui.add(gui_gridHeight.setup("Num of columns", gridHeight, 1, 100));
    gui.add(gui_pointDistance.setup("Point spacing", pointDistance, 1, 200));
    gui.add(gui_numOfPointsToMove.setup("Num of points to move", numOfPointsToMove, 0, gridWidth * gridHeight));
    gui.add(gui_randomXOffset.setup("Max x offset", randomXOffset, 1, 10000));
    gui.add(gui_randomYOffset.setup("Max y offset", randomYOffset, 1, 10000));
    gui.add(gui_randomZOffset.setup("Max z offset", randomZOffset, 1, 10000));
}

void ofApp::gridWidthChanged(int &_gridWidth) {
    gridWidth = _gridWidth;
    gui_numOfPointsToMove.setMax(gridWidth*gridHeight);
    setupShape();
}
void ofApp::gridHeightChanged(int &_gridHeight) {
    gridHeight = _gridHeight;
    gui_numOfPointsToMove.setMax(gridWidth*gridHeight);
    setupShape();
}
void ofApp::pointDistanceChanged(float &_pd) {
    pointDistance = _pd;
    setupShape();
}
void ofApp::numOfPointsToMoveChanged(int &_num) {
    numOfPointsToMove = _num;
    setupShape();
}
void ofApp::randomXOffsetChanged(float &_offset) {
    randomXOffset = _offset;
    setupShape();
}
void ofApp::randomYOffsetChanged(float &_offset) {
    randomYOffset = _offset;
    setupShape();
}
void ofApp::randomZOffsetChanged(float &_offset) {
    randomZOffset = _offset;
    setupShape();
}

//------------
// this function sets up the grid shape and randomly displaces points
// messy, but only for testing purposes

void ofApp::setupShape() {
    grid = Grid(gridWidth, gridHeight, pointDistance, numOfResolveIterations);
    
    for (int i=0; i<gridDisplays.size(); i++) {
        gridDisplays.at(i)->setGrid(&grid);
        meshDisplay.setup();
        gridDisplays.at(i)->setup();
    }
    
    vector <int> usedIndices;
    
    int numDisplaced = 0; // tracks the number of displaced point masses
    
    // out of range prevention
    numOfPointsToMove = min(numOfPointsToMove, gridWidth*gridHeight);
    
    while (numDisplaced < numOfPointsToMove) {
        bool displace = true;
        
        // get a random point
        int randX = int(floor(ofRandom(0, gridWidth)));
        int randY = int(floor(ofRandom(0, gridHeight)));
        
        int index = randY * gridWidth + randX;
        
        // check if we already moved it
        for (int j = 0,uis=usedIndices.size(); j < uis; j++) {
            if (usedIndices[j] == index) {
                displace = false;
                break;
            }
        }
        
        if (displace) {
            numDisplaced++;
            
            // make random movement vector for point mass
            ofVec3f movementVec(ofRandom(-1* randomXOffset, randomXOffset),ofRandom(-1* randomYOffset, randomYOffset),ofRandom(-1* randomZOffset, randomZOffset));
            
            grid.movePointMass(randX, randY, movementVec);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'x'){
        img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
        img.save("screenshot.png");
    }
    if (key == 's') {
        saveSvg = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    // "h"
    if (key == 104) {
        doDrawGui = !doDrawGui;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (button == 2) {
        // when pressing right mouse button, start again
        setupShape();
    }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
