//
//  PointMass.cpp
//  jakobsen_grid
//
//  Created by Jonathan Pirnay on 05.06.16.
//
//

#include "PointMass.h"

void Link::resolve() {
    ofVec3f attractionVector = p1->getPosition() - p2->getPosition();
    float distance = p1->getPosition().distance(p2->getPosition());
    
    // we need the ratio for the attraction vector
    float ratio = (restingDistance - distance) / distance;
    
    // move both point masses half the way
    p2->move(-0.5 * ratio * attractionVector);
    p1->move(0.5 * ratio * attractionVector);
};

// -----------------

PointMass::PointMass(float posX, float posY, float posZ, float distanceToOtherPoints) {
    // set initial position
    position.set(posX, posY, posZ);
    restingDistanceToOtherPoints = distanceToOtherPoints;
};

void PointMass::linkTo(PointMass* p) {
    links.push_back(Link(this, p, restingDistanceToOtherPoints));
};

void PointMass::resolveLinks() {
    for (int i=0,ls=links.size(); i < ls; i++) {
        Link l = links.at(i);
        l.resolve();
    }
};

void PointMass::move(ofVec3f direction) {
    position += direction;
};

void PointMass::debugDraw() {
    ofSetColor(0,0,0);
    ofFill();
    ofDrawSphere(position.x, position.y, position.z, debugSphereRadius);
    
    // draw links
    for (int i=0,ls=links.size(); i<ls; i++) {
        Link l = links.at(i);
        PointMass* p1 = l.getP1();
        PointMass* p2 = l.getP2();
        ofSetColor(0,0,0);
        ofSetLineWidth(2);
        ofDrawLine(p1->getPosition().x, p1->getPosition().y, p1->getPosition().z, p2->getPosition().x, p2->getPosition().y, p2->getPosition().z);
    }
};