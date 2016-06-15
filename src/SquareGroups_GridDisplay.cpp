//
//  SquareGroups_GridDisplay.cpp
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 15.06.16.
//
//

#include "SquareGroups_GridDisplay.h"
#include "math.h"

void SquareGroups_GridDisplay::setup() {
    for (int i=0; i<gridWidth; i++) {
        for (int j=0; j<gridHeight; j++) {
            colorList.push_back(floor(ofRandom(0, numOfColors)));
        }
    }
}

void SquareGroups_GridDisplay::update() {
}

void SquareGroups_GridDisplay::draw() {
    ofClear(255,255,255,255);
    ofFill();
    
    for (int i=0; i<gridWidth; i++) {
        for (int j=0; j<gridHeight; j++) {
            if (i<gridWidth-1 && j<gridHeight-1) {
                PointMass p1 = grid->pointMassAt(i,j);
                PointMass p2 = grid->pointMassAt(i+1,j);
                PointMass p3 = grid->pointMassAt(i+1,j+1);
                PointMass p4 = grid->pointMassAt(i,j+1);
                
                int c = colorList[j*gridWidth+i];
                
                if (c == 0) {
                    ofSetColor(121,136,142);
                }
                else if (c == 1) {
                    ofSetColor(38,102,126);
                }
                else {
                    ofSetColor(237,238,238);
                }
                
                ofBeginShape();
                ofVertex(p1.getPosition().x,p1.getPosition().y,p1.getPosition().z);
                ofVertex(p2.getPosition().x,p2.getPosition().y,p2.getPosition().z);
                ofVertex(p3.getPosition().x,p3.getPosition().y,p3.getPosition().z);
                ofVertex(p4.getPosition().x,p4.getPosition().y,p4.getPosition().z);
                ofEndShape();
            }
            
            
        }
    }
}