//
//  Circles_GridDisplay.cpp
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 08.06.16.
//
//

#include "Circles_GridDisplay.h"

void Circles_GridDisplay::setup() {
}

void Circles_GridDisplay::update() {
}

void Circles_GridDisplay::draw() {
   ofClear(255,255,255,255);
    ofSetColor(fillColor);
    ofFill();
    
    float radius = gridPointDistance / 3;
    
    for (int i=0; i<gridWidth; i++) {
        for (int j=0; j<gridHeight; j++) {
            PointMass p = grid->pointMassAt(i,j);
            ofDrawSphere(p.getPosition(), radius);
        }
    }
}