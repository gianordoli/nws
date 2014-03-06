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
//    shapeSize = _shapeSize;
    shapeSize = 100;
    shape = _shape;
    
    centerPos.x = ofGetWidth()/2;
    centerPos.y = ofGetHeight()/2;
    
    createRandomPos();
    createShapePos();
    pos = randomPos;
}

void Particle::update(Boolean GUImode, string _mode, string _shape, float _expansion, float _shapeSize, float _nVertices, float _size, float _rotation, vector<ofVec3f>& accel, vector<ofVec3f>& magne){
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
        if(accel.size() > 0){

//        size = ofMap(accel[accel.size()-1].y, 100, 360, 1, 50);
//        ofPoint accelAverage = average(accel);
//        ofPoint magneAverage = average(magne);
//
//        shapeSize = ofMap(accelAverage.x, 100, 360, 0, ofGetHeight()/2 - 100);
//        rotation = accelAverage.z;
//        size = ofMap(accelAverage.y, 0, 255, 1, 50);

//        ofPoint test = accel[accel.size() - 1];
//        ofPoint test = average(accel);
//        ofPoint test = accel[accel.size() - 1] - accel[accel.size() - 2];
//        ofPoint test = accel[accel.size() - 1] - average(accel);
        ofPoint test = average(accel) - lastAverage;
        test.normalize();
//        float motionAverage = (test.x +test.y + test.z)/3;
//        motionAverage = (motionAverage > 0) ? (motionAverage) : (-motionAverage);
//            ofClamp(motionAverage, 0, 1);
//        cout << motionAverage << endl;
//
//        if(motionAverage < 0.2){
//            motionAverage = -0.2;
//        }
//            cout << test.z;
            
        shapeSize += test.z * 50;
        shapeSize = ofClamp(shapeSize, ofGetWidth()/10, ofGetWidth()/3);
            
            lastAverage = average(accel);

//        cout << "ACCEL x: " + ofToString(accelAverage.x) << " y: " + ofToString(accelAverage.y) << " z: " + ofToString(accelAverage.z) << endl;
//
//        cout << "MAGNE x: " + ofToString(magneAverage.x) << " y: " + ofToString(magneAverage.y) << " z: " + ofToString(magneAverage.z) << endl;

//        shapeSize = ofMap(average(magne).x, 0, 255, 0, ofGetHeight()/2 - 100);
//        rotation = ofMap(average(magne).z, 0, 255, 0, 0, 360);
            
            
        }
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

ofPoint Particle::average(vector<ofVec3f> myVector){
    ofPoint sum;
    for (int i = 0; i < myVector.size(); i++) {
        sum.x += myVector[i].x;
        sum.y += myVector[i].y;
        sum.z += myVector[i].z;
    }
    sum.x /= myVector.size();
    sum.y /= myVector.size();
    sum.z /= myVector.size();
    return sum;
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
