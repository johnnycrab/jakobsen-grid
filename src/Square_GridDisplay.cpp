//
//  Square_GridDisplay.cpp
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 13.06.16.
//
//

#include "Square_GridDisplay.h"

void Square_GridDisplay::setup() {
}

void Square_GridDisplay::update() {
}

void Square_GridDisplay::draw() {
    ofClear(255,255,255,255);
    ofSetColor(0,0,0,255);
    ofFill();
    
    float w = gridPointDistance / 2;
    
    for (int i=0; i<gridWidth; i++) {
        for (int j=0; j<gridHeight; j++) {
            PointMass p = grid->pointMassAt(i,j);
            ofDrawRectangle(p.getPosition(), w, w);
        }
    }
}