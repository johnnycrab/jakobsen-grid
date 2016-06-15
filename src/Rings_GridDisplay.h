//
//  Rings_GridDisplay.h
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 15.06.16.
//
//

#ifndef __jakobsen_grid__Rings_GridDisplay__
#define __jakobsen_grid__Rings_GridDisplay__

#include <stdio.h>

#include "GridDisplay.h"

class Rings_GridDisplay : public GridDisplay {
private:
    vector<float> outerRadi;
    vector<float> middleRadi;
    vector<float> innerRadi;
    
    
public:
    Rings_GridDisplay():GridDisplay() {};
    
    void setup();
    void update();
    void draw();
};

#endif /* defined(__jakobsen_grid__Rings_GridDisplay__) */
