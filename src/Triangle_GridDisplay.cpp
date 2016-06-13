//
//  Triangle_GridDisplay.cpp
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 08.06.16.
//
//

#include "Triangle_GridDisplay.h"
#include "math.h"

void Triangle_GridDisplay::setup() {
    
    // cleanup
    xVals.clear();
    yVals.clear();
    
    // get the points we want to track
    int numOfRandomPoints = floor(gridWidth * gridHeight);
    
    for (int i=0; i<numOfRandomPoints; i++) {
        // get a random point
        int x1 = int(floor(ofRandom(0, gridWidth)));
        int y1 = int(floor(ofRandom(0, gridHeight)));
        
        // take by half chance left neighbor, else right neighbor
        int x2 = ((x1 > 0 && (ofRandom(0,1) < 0.5)) || (x1 == gridWidth-1)) ? x1 - 1 : x1 + 1;
        int y2 = y1;
        
        int x3 = x1;
        int y3 = (y1 > 0) ? y1-1 : y1+1;
        
        xVals.push_back(x1);
        xVals.push_back(x2);
        xVals.push_back(x3);
        yVals.push_back(y1);
        yVals.push_back(y2);
        yVals.push_back(y3);
    }
}

void Triangle_GridDisplay::update() {
}

void Triangle_GridDisplay::draw() {
    ofClear(255,255,255,255);
    ofSetColor(0,0,0,100);
    ofFill();
    
    for (int i=0,s=xVals.size(); i<s; i++) {
        if (i%3 == 0) {
            PointMass p1 = grid->pointMassAt(xVals.at(i), yVals.at(i));
            PointMass p2 = grid->pointMassAt(xVals.at(i+1), yVals.at(i+1));
            PointMass p3 = grid->pointMassAt(xVals.at(i+2), yVals.at(i+2));
            
            ofDrawTriangle(p1.getPosition(), p2.getPosition(), p3.getPosition());
        }
    }
}