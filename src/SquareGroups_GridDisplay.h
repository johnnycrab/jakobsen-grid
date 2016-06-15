//
//  SquareGroups_GridDisplay.h
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 15.06.16.
//
//

#ifndef __jakobsen_grid__SquareGroups_GridDisplay__
#define __jakobsen_grid__SquareGroups_GridDisplay__

#include <stdio.h>
#include "GridDisplay.h"

class SquareGroups_GridDisplay : public GridDisplay {
private:
    
    int numOfColors = 3;
    vector<int> colorList;
public:
    SquareGroups_GridDisplay():GridDisplay() {};
    
    void setup();
    void update();
    void draw();
};


#endif /* defined(__jakobsen_grid__SquareGroups_GridDisplay__) */
