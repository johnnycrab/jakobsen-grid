//
//  Lines_GridDisplay.cpp
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 09.06.16.
//
//

#include "Lines_GridDisplay.h"

void Lines_GridDisplay::setup() {
}

void Lines_GridDisplay::update() {
}

void Lines_GridDisplay::draw() {
    ofClear(255,255,255,255);
    ofSetColor(65, 88, 99, 100);
    ofSetLineWidth(1);
    
    //ofMesh mesh;
    
   
    /*
    mesh.addVertex(ofVec3f(20,20));
    mesh.addColor(ofColor::red);
    mesh.addVertex(ofVec3f(40,20));
    mesh.addColor(ofColor::red);
    mesh.addVertex(ofVec3f(40,40));
    mesh.addColor(ofColor::blue);
    mesh.addVertex(ofVec3f(20,40));
    mesh.addColor(ofColor::blue);
    */
    
    //mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    /*primitive.getMesh().addVertex(ofVec3f(20,20));
    primitive.getMesh().addVertex(ofVec3f(40,20));
    primitive.getMesh().addVertex(ofVec3f(40,40));
    primitive.getMesh().addVertex(ofVec3f(20,40));
    primitive.getMesh().setMode(OF_PRIMITIVE_TRIANGLE_FAN);

    primitive.draw();*/
    
    for (int i=0; i<gridWidth - 1; i++) {
        ofMesh mesh;
        ofPath path;
        of3dPrimitive primitive;
        
        int j=-1;
        while (++j<gridHeight - 1) {
            PointMass p1 = grid->pointMassAt(i, j);
            PointMass p2 = grid->pointMassAt(i + 1, j);
            PointMass p3 = grid->pointMassAt(i + 1, j + 1);
            PointMass p4 = grid->pointMassAt(i, j + 1);
            
            //mesh.addTriangle(i * j), i + 1 + , p3.getPosition());
            //mesh.addTriangle(p1.getPosition(), p3.getPosition(), p4.getPosition());
            
            ofVec3f p2Pos = p2.getPosition();
            
            //p2Pos.y -= 3;
            
            /*if (i == 0) {
                path.moveTo(p1.getPosition());
            }
            else {
                path.lineTo(p2.getPosition());
            }*/
            
            mesh.addVertex(p1.getPosition()); // make a new vertex
            mesh.addColor(ofFloatColor(0, 0, (i + 10) % 255));  // add a color at that vertex
            mesh.addVertex(p2Pos); // make a new vertex
            mesh.addColor(ofFloatColor(0, 0, (i + 10) % 255));  // add a color at that vertex
            
            primitive.getMesh().addVertex(p1.getPosition());
            primitive.getMesh().addVertex(p2.getPosition());
            primitive.getMesh().addVertex(p3.getPosition());
            primitive.getMesh().addVertex(p4.getPosition());
            
            //ofDrawLine(p1.getPosition(), p2.getPosition());
            
            /*PointMass p3 = grid->pointMassAt(i + 1, j);
            PointMass p4 = grid->pointMassAt(i + 1, j + 1);
            ofVec3f p4Pos = p4.getPosition();
            p4Pos.z += 10;
            ofDrawLine(p3.getPosition(), p4Pos);*/
        }
        
        //mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
        //mesh.setupIndicesAuto();

        //mesh.draw();
        //mesh.drawWireframe();
        primitive.getMesh().setMode(OF_PRIMITIVE_TRIANGLE_FAN);
        primitive.draw();
    }
}