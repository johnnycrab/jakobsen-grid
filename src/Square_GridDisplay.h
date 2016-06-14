//
//  Square_GridDisplay.h
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 13.06.16.
//
//

#ifndef __jakobsen_grid__Square_GridDisplay__
#define __jakobsen_grid__Square_GridDisplay__

#include <stdio.h>
#include "GridDisplay.h"

class Square_GridDisplay : public GridDisplay {
private:
    
public:
    Square_GridDisplay():GridDisplay() {};
    
    void setup();
    void update();
    void draw();
};

#endif /* defined(__jakobsen_grid__Square_GridDisplay__) */
