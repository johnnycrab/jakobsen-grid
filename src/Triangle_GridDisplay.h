//
//  Triangle_GridDisplay.h
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 08.06.16.
//
//

#ifndef __jakobsen_grid__Triangle_GridDisplay__
#define __jakobsen_grid__Triangle_GridDisplay__

#include <stdio.h>
#include "GridDisplay.h"

class Triangle_GridDisplay : public GridDisplay {
private:
    vector<int> xVals;
    vector<int> yVals;
    
public:
    Triangle_GridDisplay():GridDisplay() {};
    
    void setup();
    void update();
    void draw();
};

#endif /* defined(__jakobsen_grid__Triangle_GridDisplay__) */
