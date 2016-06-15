//
//  RawGrid_GridDisplay.cpp
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 14.06.16.
//
//

#include "RawGrid_GridDisplay.h"

void RawGrid_GridDisplay::setup() {
}

void RawGrid_GridDisplay::update() {
}

void RawGrid_GridDisplay::draw() {
    ofClear(255,255,255,255);
    ofSetColor(0,0,0);
    ofFill();
    ofSetLineWidth(1.2);
    
    /*for (int i=0; i<gridWidth; i++) {
        for (int j=0; j<gridHeight; j++) {
            PointMass p = grid->pointMassAt(i,j);
            // connect to right neighbor
            if (i < gridWidth - 1) {
                PointMass p1 = grid->pointMassAt(i+1, j);
                ofDrawLine(p1.getPosition(), p.getPosition());
            }
            
            // connect to lower neighbor
            if (j < gridHeight -1) {
                PointMass p2 = grid->pointMassAt(i, j+1);
                ofDrawLine(p2.getPosition(), p.getPosition());
            }
        }
    }*/
    
    for (int j=0; j<gridHeight; j++) {
        for (int i=0; i<gridWidth; i++) {
            if (j<(gridHeight-1)) {
                // draw triangle downwards
                if (i < gridWidth-1) {
                    PointMass p1 = grid->pointMassAt(i, j);
                    PointMass p2 = grid->pointMassAt(i+1, j);
                    PointMass p3 = grid->pointMassAt(i, j+1);
                    
                    ofSetColor(121,136,142);
                    
                    if (j%2 == 0) {
                        ofSetColor(0,0,0);
                    }
                    
                    ofDrawTriangle(p1.getPosition(), p2.getPosition(), p3.getPosition());
                }
            }
            if (j>0) {
                // draw upwards triangle
                if (i > 0) {
                    PointMass p1 = grid->pointMassAt(i, j);
                    PointMass p2 = grid->pointMassAt(i-1, j);
                    PointMass p3 = grid->pointMassAt(i, j-1);
                    
                    ofSetColor(38,102,126);
                    
                    if (j%2 == 0) {
                        ofSetColor(237,238,238);
                        
                    }
                    
                    ofDrawTriangle(p1.getPosition(), p2.getPosition(), p3.getPosition());
                }
            }
        }
    }
}