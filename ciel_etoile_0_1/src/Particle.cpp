//
//  Particle.cpp
//  ciel_etoile_0_1
//
//  Created by Gabriel Gianordoli on 2/26/14.
//
//

#include "Particle.h"

void Particle::init(int _nParticles, int _i, float _shapeSize, float _size){
    nParticles = _nParticles;
    i = _i;
    color = 0;
    size = _size;
    shapeSize = _shapeSize;
    
    centerPos.x = ofGetWidth()/2;
    centerPos.y = ofGetHeight()/2;
    
    float angle = ofDegToRad(360/float(nParticles));
    randomPos.x = cos(angle*i) * (ofRandom(-ofGetHeight()/2, ofGetHeight()/2));
    randomPos.y = sin(angle*i) * (ofRandom(-ofGetHeight()/2, ofGetHeight()/2));
    
    shapePos.x = cos(angle*i) * shapeSize;
    shapePos.y = sin(angle*i) * shapeSize;
    
    pos = randomPos;
}

void Particle::update(int _nParticles, string shape, string mode, float expander, float _shapeSize, float _size){
//    cout << mode;
    size = _size;
    shapeSize = _shapeSize;
    float angle = ofDegToRad(360/float(nParticles));
    
    if(mode == "fuzz"){
        randomPos.x = cos(angle*i) * (ofRandom(-ofGetHeight()/2, ofGetHeight()/2));
        randomPos.y = sin(angle*i) * (ofRandom(-ofGetHeight()/2, ofGetHeight()/2));
    }
    createShapePos(nParticles, shape, angle);
    pos.x = ofLerp(randomPos.x, shapePos.x, expander);
    pos.y = ofLerp(randomPos.y, shapePos.y, expander);
}

void Particle::draw(){
    ofSetColor(color);
    ofPushMatrix();
    ofTranslate(centerPos.x, centerPos.y);
        ofCircle(pos.x, pos.y, size, size);
    ofPopMatrix();
}

void Particle::createShapePos(int nParticles, string shape, float angle){
    if(shape == "circle"){
        shapePos.x = cos(angle*i) * shapeSize;
        shapePos.y = sin(angle*i) * shapeSize;

    }else if(shape == "spiral"){
        float radius2 = shapeSize * 1.5;
        float radius1 = shapeSize/3;
        float radius = ofMap(sin(angle * (i % 10)), -1, 1, radius1, radius2);
        
        shapePos.x = cos(angle * i) * radius;
        shapePos.y = sin(angle * i) * radius;

    }else if(shape == "star"){
        float radius2 = shapeSize * 2;
        float radius1 = shapeSize;
        float radius = ofMap(sin(float(i)/4), 0, 10, radius1, radius2);
        
        shapePos.x = cos(angle * i) * radius;
        shapePos.y = sin(angle * i) * radius;
    }

}
