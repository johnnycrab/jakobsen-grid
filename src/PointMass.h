//
//  PointMass.h
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 05.06.16.
//
//

#ifndef __jakobsen_grid__PointMass__
#define __jakobsen_grid__PointMass__

#include <stdio.h>
#include "ofMain.h"



/**
 * This class handles the linking between two PointMasses. The main function is the `resolve` function where the point masses are being pushed away from / pulled towards each other.
 */

class PointMass; // break circular reference
class Link {
private:
    friend class PointMass;
    
    PointMass* p1;
    PointMass* p2;
    float restingDistance;   // the optimal distance the two points should be away from each other
    
    void resolve();
public:
    Link(PointMass* _p1,PointMass* _p2, float _restingDistance):p1(_p1),p2(_p2),restingDistance(_restingDistance) {};
    
    PointMass* getP1() {
        return p1;
    }
    
    PointMass* getP2() {
        return p2;
    }
    
};

//  ---------------
class Grid; // break circular reference
class PointMass {
    
private:
    friend class Grid;
    
    ofVec3f position;
    vector<Link> links; // stores the links to other point masses
    float restingDistanceToOtherPoints;
    
    ofMesh *parentMesh;
    int parentMeshIndex;
    
    
    // DEBUG variables
    float debugSphereRadius = 5; // radius of the sphere that gets drawn for debug reasons
    
    void linkTo(PointMass* p);
    void resolveLinks();
    
public:
    // std constructor
    PointMass() {};
    
    // constructor. Takes initial coordinates of point mass
    PointMass(float posX, float posY, float posZ, float distanceToOtherPoints);
    
    ofVec3f getPosition() {
        return position;
    }

    
    void move(ofVec3f direction);
    
    // simply draws a small sphere at the current point
    void debugDraw();
};

#endif /* defined(__jakobsen_grid__PointMass__) */
