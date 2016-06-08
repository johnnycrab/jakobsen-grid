//
//  Grid.h
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 05.06.16.
//
//

#ifndef __jakobsen_grid__Grid__
#define __jakobsen_grid__Grid__

#include <stdio.h>
#include "ofMain.h"
#include "PointMass.h"

class Grid {
private:
    int width, height;   // dimensions of grid, i.e. num of rows and columns
    float pointDistance; // distance of two point masses. Defines the actual dimensions of the grid in pixels
    
    // the number of iterations used to resolve distances between point masses. the more, the more exact
    int numOfResolveIterations;
    
    vector<PointMass> pointMasses; // list of point masses
    
    // get a point mass at a specified position in the grid (i.e. row y, column x). Row/column numbers start with 0.
    PointMass* getPointMassAt(int x, int y) {
        return &pointMasses.at(y * width + x);
    }
    
public:
    Grid () {}; // std constructor
    Grid (int _width, int _height, float _pointDistance, int _numOfResolveIterations);
    
    // DRAW FLAGS
    bool drawDebug = false;
    
    void debugDrawPoints();
    
    // updates the positions of the point masses by resolving distances
    void update();
    
    // draws all the shit
    void draw();
    
    // moves the point mass at the specified position by adding the moveVec
    void movePointMass(int atX, int atY, ofVec3f moveVec);
    
    // return copy for draw functions
    PointMass pointMassAt(int x, int y) {
        return pointMasses.at(y * width + x);
    }
    
    int getWidth() { return width; }
    int getHeight() { return height; }
    float getPointDistance() { return pointDistance; }
};

#endif /* defined(__jakobsen_grid__Grid__) */
