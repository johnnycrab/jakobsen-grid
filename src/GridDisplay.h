//
//  GridDisplay.h
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 08.06.16.
//
//

#ifndef __jakobsen_grid__GridDisplay__
#define __jakobsen_grid__GridDisplay__

#include <stdio.h>
#include "Grid.h"
#include "ofxGui.h"

class GridDisplay {
    
protected:
    Grid* grid;
    int gridWidth;
    int gridHeight;
    float gridPointDistance;
public:
    ofxToggle toggle;
    
    // default constructor
    GridDisplay() {};
    
    void setGrid(Grid* _grid) {
        grid = _grid;
        gridWidth = grid->getWidth();
        gridHeight = grid->getHeight();
        gridPointDistance = grid->getPointDistance();
    }
    
    virtual void setup() {};
    virtual void draw() {};
    virtual void update() {};
};

#endif /* defined(__jakobsen_grid__GridDisplay__) */
