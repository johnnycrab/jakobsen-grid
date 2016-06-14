//
//  RawGrid_GridDisplay.h
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 14.06.16.
//
//

#ifndef __jakobsen_grid__RawGrid_GridDisplay__
#define __jakobsen_grid__RawGrid_GridDisplay__

#include <stdio.h>
#include "GridDisplay.h"

class RawGrid_GridDisplay : public GridDisplay {
private:
    
public:
    RawGrid_GridDisplay():GridDisplay() {};
    
    void setup();
    void update();
    void draw();
};

#endif /* defined(__jakobsen_grid__RawGrid_GridDisplay__) */
