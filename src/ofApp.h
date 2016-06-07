#pragma once

#include "ofMain.h"
#include "Grid.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        // sets up a new shape randomly
        void setupShape();

        Grid grid;
  
        ofEasyCam cam;
    
        // settings
        int gridWidth = 40;
        int gridHeight = 50;
        int pointDistance = 10;
        int numOfPointsToMove = 30;
        float randomXOffset = 1000;
        float randomYOffset = 1000;
        float randomZOffset = 1000;
    
        // the number of iterations used to resolve. the more, the more exact
        int numOfResolveIterations = 10;
    
        // GUI
        void setupGUI();
        void gridWidthChanged(int &_gridWidth);
        void gridHeightChanged(int &_gridHeight);
        void pointDistanceChanged(float &_pd);
        void numOfPointsToMoveChanged(int &_num);
        void randomXOffsetChanged(float &_offset);
        void randomYOffsetChanged(float &_offset);
        void randomZOffsetChanged(float &_offset);
    
    
        ofxIntSlider    gui_gridWidth;
        ofxIntSlider    gui_gridHeight;
        ofxIntSlider    gui_numOfPointsToMove;
        ofxFloatSlider  gui_pointDistance;
        ofxFloatSlider  gui_randomXOffset;
        ofxFloatSlider  gui_randomYOffset;
        ofxFloatSlider  gui_randomZOffset;
    
        ofxPanel gui;
};