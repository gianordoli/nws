//
//  Particle.cpp
//  ciel_etoile_0_1
//
//  Created by Gabriel Gianordoli on 2/26/14.
//
//

#include "Particle.h"

void Particle::init(int nParticles, int i){

    color = 0;
    size = 10;
    circleSize = 300;
    
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    randomPos = pos;

    float angle = ofDegToRad(360/float(nParticles));
    circlePos.x = ofGetWidth()/2 + cos(angle*i)*circleSize;
    circlePos.y = ofGetHeight()/2 + sin(angle*i)*circleSize;;
    
}

void Particle::update(int mode, float fader){
//    cout << mode;
//    cout << fader;
    if(mode == 1){
        randomPos.x = ofRandomWidth();
        randomPos.y = ofRandomHeight();
    }
    pos.x = ofLerp(randomPos.x, circlePos.x, fader);
    pos.y = ofLerp(randomPos.y, circlePos.y, fader);
}

void Particle::draw(){
    ofSetColor(color);
    ofCircle(pos.x, pos.y, size, size);
}
