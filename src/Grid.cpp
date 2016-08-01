//
//  Grid.cpp
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 05.06.16.
//
//

#include "Grid.h"

Grid::Grid (int _width, int _height, float _pointDistance, int _numOfResolveIterations):width(_width),height(_height),pointDistance(_pointDistance),numOfResolveIterations(_numOfResolveIterations) {
    
    // get x,y-coordinates of the to left corner. we assume the center of the grid lies within the center of the screen
    float topLeftX = -0.5 * (width - 1) * pointDistance;
    float topLeftY = -0.5 * (height - 1) * pointDistance;
    
    // initialize the grid with all point masses
    for (int j=0;j<height;j++) {
        for (int i=0; i<width; i++) {
            float x = topLeftX + (i * pointDistance);
            float y = topLeftY + (j * pointDistance);
            
            PointMass p = PointMass(x, y, 0, pointDistance);
            pointMasses.push_back(p);
        }
    }
    
    // set all the links between point masses. We link points like this:
    //  *<---*<---*<-..
    //  ^    ^    ^
    //  |    |    |
    //  *<---*<---*<-..
    //
    // also set the mesh indices
    
    for (int i=0;i<width;i++) {
        for (int j=0; j<height; j++) {
            PointMass* p = getPointMassAt(i,j);
            
            int pIndex = j*width+i;
            
            if (i != 0) {
                // link to left neighbor
                PointMass* ln = getPointMassAt(i-1, j);
                p->linkTo(ln);
            }
            if (j != 0) {
                // link to upper neighbor
                PointMass* un = getPointMassAt(i, j-1);
                p->linkTo(un);
            }
        }
    }
    
    resolveIterationsCount = 0;
}

void Grid::debugDrawPoints() {
    for (int i=0;i<width*height;i++) {
        pointMasses.at(i).debugDraw();
    }
};

void Grid::update() {
    // @deprecated
    /*for (int i=0; i<numOfResolveIterations; i++) {
        for (int j=0; j<width; j++) {
            for (int k=0;k<height;k++) {
                PointMass* p = getPointMassAt(j,k);
                p->resolveLinks();
            }
        }
    }*/
    
    // only resolve a certain number of times
    if (resolveIterationsCount < numOfResolveIterations) {
        resolveIterationsCount++;
        
        for (int j=0; j<width; j++) {
            for (int k=0;k<height;k++) {
                PointMass* p = getPointMassAt(j,k);
                p->resolveLinks();
            }
        }
    }
}

void Grid::draw() {
    if (drawDebug) {
        debugDrawPoints();
    }
}

void Grid::movePointMass(int atX, int atY, ofVec3f moveVec) {
    getPointMassAt(atX, atY)->move(moveVec);
};