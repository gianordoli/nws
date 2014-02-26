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
    void init(int nParticles, int i, float circleSize, float particleSize);
    void update(int nParticles, int mode, float expander, float circleSize, float particleSize);
    void draw();
    
    //variables
    int i;
    ofPoint pos;
    ofPoint randomPos;
    ofPoint circlePos;
    ofColor color;
    float size;
};