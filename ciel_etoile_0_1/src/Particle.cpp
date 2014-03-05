//
//  Particle.cpp
//  ciel_etoile_0_1
//
//  Created by Gabriel Gianordoli on 2/26/14.
//
//

#include "Particle.h"

void Particle::init(int _nParticles, int _i, float _shapeSize, float _size, string _shape){
    nParticles = _nParticles;
    i = _i;
//    color = 0;
//    color.set(255);
    color.set(0);
    size = _size;
    shapeSize = _shapeSize;
    shape = _shape;
    
    centerPos.x = ofGetWidth()/2;
    centerPos.y = ofGetHeight()/2;
    
    createRandomPos();
    createShapePos();
    pos = randomPos;
}

void Particle::update(Boolean GUImode, string _mode, string _shape, float _expansion, float _shapeSize, float _nVertices, float _size, float _rotation, vector<ofVec3f>& accel){
//    cout << mode;
    float expansion = _expansion;


    nVertices = _nVertices;
    shape = _shape;
    string mode = _mode;
    
    if(GUImode){
        size = _size;
        shapeSize = _shapeSize;
        rotation = _rotation;
    }else{
        size = ofMap(accel[accel.size()-1].y, 100, 360, 1, 50);
        shapeSize = ofMap(accel[accel.size()-1].x, 100, 360, 0, ofGetHeight()/2 - 100);
//        rotation = ofMap(accel[accel.size()-1].z, 100, 180, 0, 360);
        rotation = accel[accel.size()-1].z;
    }
    
    float angle = ofDegToRad(360/float(nParticles));
    
    if(_mode == "fuzz"){
        randomPos.x = cos(angle*i) * (ofRandom(-ofGetHeight()/2, ofGetHeight()/2));
        randomPos.y = sin(angle*i) * (ofRandom(-ofGetHeight()/2, ofGetHeight()/2));
    }
    createShapePos();
    pos.x = ofLerp(randomPos.x, shapePos.x, expansion);
    pos.y = ofLerp(randomPos.y, shapePos.y, expansion);
}

void Particle::draw(){
    ofSetColor(color);
    ofPushMatrix();
        ofTranslate(centerPos.x, centerPos.y);
        ofRotate(rotation);
            ofCircle(pos.x, pos.y, size, size);
    ofPopMatrix();
}

void Particle::createRandomPos(){
    float angle = ofDegToRad(360/float(nParticles));
    randomPos.x = cos(angle*i) * (ofRandom(-ofGetHeight()/2, ofGetHeight()/2));
    randomPos.y = sin(angle*i) * (ofRandom(-ofGetHeight()/2, ofGetHeight()/2));
}

void Particle::createShapePos(){
    float angle = ofDegToRad(360/float(nParticles));
    if(shape == "circle"){
        shapePos.x = cos(angle*i) * shapeSize;
        shapePos.y = sin(angle*i) * shapeSize;

    }else if(shape == "spiral"){
        float radius2 = shapeSize * 1.5;
        float radius1 = shapeSize/5;
        float radius = ofMap(sin(angle * (i % int(nVertices))), -1, 1, radius1, radius2);
        
        shapePos.x = cos(angle * i) * radius;
        shapePos.y = sin(angle * i) * radius;

    }else if(shape == "star"){
        float radius2 = shapeSize;
        float radius1 = shapeSize * 0.75;
        float radius = ofMap(sin(float(i)/nVertices), -1, 1, radius1, radius2);
        
        shapePos.x = cos(angle * i) * radius;
        shapePos.y = sin(angle * i) * radius;
 
    }else if(shape == "grid"){
        int nColumns = sqrt(nParticles);
        float spacing = ((shapeSize * 2) / nColumns);
        
        shapePos.x = -shapeSize + (i % nColumns) * spacing;
        shapePos.y = -shapeSize + int(i / nColumns) * spacing;
    }

}
