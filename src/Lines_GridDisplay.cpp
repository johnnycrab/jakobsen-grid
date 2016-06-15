//
//  Lines_GridDisplay.cpp
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 09.06.16.
//
//

#include "Lines_GridDisplay.h"

void Lines_GridDisplay::setup() {
}

void Lines_GridDisplay::update() {
}

void Lines_GridDisplay::draw() {
    ofClear(255,255,255,255);
    ofSetColor(0,0,0,100);
    ofSetLineWidth(1);
    
    ofMesh mesh;
   
    /*
    mesh.addVertex(ofVec3f(20,20));
    mesh.addColor(ofColor::red);
    mesh.addVertex(ofVec3f(40,20));
    mesh.addColor(ofColor::red);
    mesh.addVertex(ofVec3f(40,40));
    mesh.addColor(ofColor::blue);
    mesh.addVertex(ofVec3f(20,40));
    mesh.addColor(ofColor::blue);
    */
    
    //mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    
    for (int i=0; i<gridWidth - 1; i++) {
        ofMesh mesh;
        ofPath path;
        
        int j=-1;
        while (++j<gridHeight) {
            PointMass p1 = grid->pointMassAt(i, j);
            PointMass p2 = grid->pointMassAt(i + 1, j);
            
            ofVec3f p2Pos = p2.getPosition();
            
            p2Pos.x -= 3;
            
            /*if (i == 0) {
                path.moveTo(p1.getPosition());
            }
            else {
                path.lineTo(p2.getPosition());
            }*/
            
            mesh.addVertex(p1.getPosition()); // make a new vertex
            mesh.addColor(ofFloatColor(0, 0, (i + 10) % 255));  // add a color at that vertex
            mesh.addVertex(p2Pos); // make a new vertex
            mesh.addColor(ofFloatColor(0, 0, (i + 10) % 255));  // add a color at that vertex
            
            //ofDrawLine(p1.getPosition(), p2.getPosition());
            
            /*PointMass p3 = grid->pointMassAt(i + 1, j);
            PointMass p4 = grid->pointMassAt(i + 1, j + 1);
            ofVec3f p4Pos = p4.getPosition();
            p4Pos.z += 10;
            ofDrawLine(p3.getPosition(), p4Pos);*/
        }
        
        //mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
        mesh.setupIndicesAuto();

        mesh.draw();
    }
}