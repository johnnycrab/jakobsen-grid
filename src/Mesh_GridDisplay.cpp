//
//  Mesh_GridDisplay.cpp
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 08.06.16.
//
//

#include "Mesh_GridDisplay.h"

void Mesh_GridDisplay::setup() {
    mesh = ofMesh();
    
    // set mesh mode
    mesh.setMode(OF_PRIMITIVE_LINES);
    mesh.enableIndices();
    
    for (int j=0;j<gridHeight;j++) {
        for (int i=0; i<gridWidth; i++) {
            
            PointMass p = grid->pointMassAt(i, j);
            
            // set the vertex on the mesh
            mesh.addColor(ofFloatColor(((j%256)*1.0)/256.0, ((i%256)*1.0)/256.0, 0));
            mesh.addVertex(p.getPosition());
        }
    }
    
    for (int i=0;i<gridWidth;i++) {
        for (int j=0; j<gridHeight; j++) {
            
            int pIndex = j*gridWidth+i;
            
            if (i != 0) {
                // link to left neighbor
                mesh.addIndex(pIndex);
                mesh.addIndex(j*gridWidth + i - 1);
            }
            if (j != 0) {
                // link to upper neighbor
                mesh.addIndex(pIndex);
                mesh.addIndex((j-1)*gridWidth + i);
            }
            
            // add mesh index to upper left neighbor
            if (i != 0 && j != 0) {
                mesh.addIndex(pIndex);
                mesh.addIndex((j-1)*gridWidth + i - 1);
            }
        }
    }
}

void Mesh_GridDisplay::update() {
    
    for (int j=0;j<gridHeight;j++) {
        for (int i=0; i<gridWidth; i++) {
            
            PointMass p = grid->pointMassAt(i,j);
            
            // set the position of the point mass on the mesh
            mesh.setVertex(j*gridWidth+i, p.getPosition());
        }
    }
}

void Mesh_GridDisplay::draw() {
    ofClear(255,255,255,255);
    ofSetColor(56,112,188);
    mesh.draw();
}