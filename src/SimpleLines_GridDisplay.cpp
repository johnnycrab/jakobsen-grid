//
//  SimpleLines_GridDisplay.cpp
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 09.06.16.
//
//

#include "SimpleLines_GridDisplay.h"

void SimpleLines_GridDisplay::setup() {
}

void SimpleLines_GridDisplay::update() {
}

void SimpleLines_GridDisplay::draw() {
    ofClear(255,255,255,255);
    ofSetColor(0,0,0,100);
    ofSetLineWidth(1);
    
    for (int i=0; i<gridWidth; i++) {
        int j=-1;
        while (++j<gridHeight - 1) {
            PointMass p1 = grid->pointMassAt(i, j);
            PointMass p2 = grid->pointMassAt(i, j+1);
            ofDrawLine(p1.getPosition(), p2.getPosition());
        }
    }
}