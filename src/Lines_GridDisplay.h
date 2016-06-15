//
//  Lines_GridDisplay.h
//  jakobsen_grid
//
//

#ifndef __jakobsen_grid__Lines_GridDisplay__
#define __jakobsen_grid__Lines_GridDisplay__

#include <stdio.h>
#include "GridDisplay.h"

class Lines_GridDisplay : public GridDisplay {
private:
    
public:
    Lines_GridDisplay():GridDisplay() {};
    
    void setup();
    void update();
    void draw();
};

#endif /* defined(__jakobsen_grid__Lines_GridDisplay__) */
