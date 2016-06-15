//
//  Rings_GridDisplay.cpp
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 15.06.16.
//
//

#include "Rings_GridDisplay.h"

void Rings_GridDisplay::setup() {
    for (int i=0; i<gridWidth; i++) {
        for (int j=0; j<gridHeight; j++) {
            outerRadi.push_back(ofRandom(0.2, 1));
            middleRadi.push_back(ofRandom(0.2, 1));
            innerRadi.push_back(ofRandom(0.2, 1));
        }
    }
}

void Rings_GridDisplay::update() {
}

void Rings_GridDisplay::draw() {
    ofClear(255,255,255,255);

    ofFill();
    
    for (int i=0; i<gridWidth; i++) {
        for (int j=0; j<gridHeight; j++) {
            PointMass p = grid->pointMassAt(i,j);
            
            int index = j*gridWidth + i;
            float outerR = gridPointDistance/2 * outerRadi[index];
            float middleR = outerR * middleRadi[index];
            float innerR = middleR * innerRadi[index];
            
            ofSetColor(66,87,98);
            ofDrawCircle(p.getPosition(), outerR);
            
            ofSetColor(255,255,255);
            ofDrawCircle(p.getPosition(), middleR);
            
            ofSetColor(109,126,135);
            ofDrawCircle(p.getPosition(), innerR);
            
        }
    }
}