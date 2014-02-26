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
    void init(int nParticles, int i);
    void update(int mode, float fader);
    void draw();
    
    //variables
    ofPoint pos;
    ofPoint randomPos;
    ofPoint circlePos;
    ofColor color;
    float size;
    float circleSize;
};