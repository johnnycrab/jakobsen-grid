//
//  SimpleLines_GridDisplay.h
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 09.06.16.
//
//

#ifndef __jakobsen_grid__SimpleLines_GridDisplay__
#define __jakobsen_grid__SimpleLines_GridDisplay__

#include <stdio.h>
#include "GridDisplay.h"

class SimpleLines_GridDisplay : public GridDisplay {
private:
    
public:
    SimpleLines_GridDisplay():GridDisplay() {};
    
    void setup();
    void update();
    void draw();
};

#endif /* defined(__jakobsen_grid__SimpleLines_GridDisplay__) */
