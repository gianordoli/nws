//
//  Particle.h
//  ciel_etoile_0_1
//
//  Created by Gabriel Gianordoli on 2/26/14.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    //functions
    void init(int _nParticles, int _i, float _shapeSize, float _size);
    void update(int _nParticles, string shape, string mode, float expander, float _shapeSize, float _size);
    void draw();
    
    void createShapePos(int nParticles, string shape, float angle);
    
    //variables
    int nParticles;
    int i;
    ofPoint pos;
    ofPoint randomPos;
    ofPoint shapePos;
    ofPoint centerPos;
    ofColor color;
    float size;
    float shapeSize;
};