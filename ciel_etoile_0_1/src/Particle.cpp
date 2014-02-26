//
//  Particle.cpp
//  ciel_etoile_0_1
//
//  Created by Gabriel Gianordoli on 2/26/14.
//
//

#include "Particle.h"

void Particle::init(int nParticles, int index, float circleSize, float particleSize){
    i = index;
    color = 0;
    size = particleSize;

    float angle = ofDegToRad(360/float(nParticles));
    randomPos.x = ofGetWidth()/2 +
                  cos(angle*i) * (ofRandom(-ofGetHeight()/2, ofGetHeight()/2));
    randomPos.y = ofGetHeight()/2 +
                  sin(angle*i) * (ofRandom(-ofGetHeight()/2, ofGetHeight()/2));

    circlePos.x = ofGetWidth()/2 + cos(angle*i)*circleSize;
    circlePos.y = ofGetHeight()/2 + sin(angle*i)*circleSize;
    
    pos = randomPos;
}

void Particle::update(int nParticles, string mode, float expander, float circleSize, float particleSize){
//    cout << mode;
    size = particleSize;
    float angle = ofDegToRad(360/float(nParticles));
    
    if(mode == "fuzz"){
        randomPos.x = ofGetWidth()/2 +
                      cos(angle*i) * (ofRandom(-ofGetHeight()/2, ofGetHeight()/2));
        randomPos.y = ofGetHeight()/2 +
                      sin(angle*i) * (ofRandom(-ofGetHeight()/2, ofGetHeight()/2));

    }

    circlePos.x = ofGetWidth()/2 + cos(angle*i)*circleSize;
    circlePos.y = ofGetHeight()/2 + sin(angle*i)*circleSize;
    
    pos.x = ofLerp(randomPos.x, circlePos.x, expander);
    pos.y = ofLerp(randomPos.y, circlePos.y, expander);
}

void Particle::draw(){
    ofSetColor(color);
    ofCircle(pos.x, pos.y, size, size);
}
