//
//  Mesh_GridDisplay.h
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 08.06.16.
//
//

#ifndef __jakobsen_grid__Mesh_GridDisplay__
#define __jakobsen_grid__Mesh_GridDisplay__

#include <stdio.h>
#include "GridDisplay.h"

class Mesh_GridDisplay : public GridDisplay {
    
private:
    ofMesh mesh; // have also a mesh representation. useful for whatever
    
public:
    Mesh_GridDisplay():GridDisplay() {};
    
    void setup();
    void update();
    void draw();
};

#endif /* defined(__jakobsen_grid__Mesh_GridDisplay__) */
