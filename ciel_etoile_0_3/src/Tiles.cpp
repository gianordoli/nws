/*
 *  Tiles.cpp
 *  ciel_etoile_background
 *
 *  Created by Julie Huynh on 2/26/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "Tiles.h"

void Tiles:: setup(int _nTiles, int _i, string _mode, int tempX, int tempY) {

    nTiles = _nTiles;
    i = _i;
    
    size = 40;
    mode = _mode;
	gridPos.x = tempX;
	gridPos.y = tempY;
    
    color.set(0, 180, 180, 150);
    
    breakage = size;
    createTileVertices();
    createFragmentVertices();
    
    currVertices = tileVertices;
    
//    for(int i = 0; i < currVertices.size(); i++){
//        cout << tileVertices[i].x << endl;
//    }
    
    expansion = 0;
    dir = 0;
    speed = 0.01;
    threshold = 0;
    
}
//--------------------------------------------------------------

void Tiles:: update(string _mode, float mouseX, float mouseY, float freq[], float _threshold, vector<ofVec3f>& accel2, vector<ofVec3f>& magne2) {
    
    mode = _mode;
    threshold = _threshold;
    
    //Calculate index to use based on Tile index
//    int index = ofMap(i, nTiles, 0, 0, 256);
    int index = ofMap(i, nTiles, 0, 0, 128);
//    cout << freq[index] << endl;
    
    //Change direction according to frequency
    if(freq[index] > threshold){
        dir = abs(freq[index])*speed;
    }else{
        dir = - 2*speed;
    }
    dir = ofClamp(dir, -10, 10);

    expansion += dir;
    expansion = ofClamp(expansion, 0, 5);
    if(expansion >= 5){
        dir = - 2*speed;
    }

    if(mode == "3D"){
        
    }else if(mode == "fragments"){
        //Updating the vertices position
        for(int i = 0; i < currVertices.size(); i++){
            currVertices[i].x = ofLerp(tileVertices[i].x, fragmentVertices[i].x, expansion);
            currVertices[i].y = ofLerp(tileVertices[i].y, fragmentVertices[i].y, expansion);
        }
    }else if(mode == "rotation"){
    
    }
    

}

//--------------------------------------------------------------

void Tiles:: draw(float mouseX, float mouseY) {

    ofSetColor(color);

    ofPushMatrix();
    ofTranslate(gridPos.x, gridPos.y);
    
        if(mode == "3D"){

            ofTranslate(0, 0, expansion*20.0f);
            ofRect(0, 0, size, size);
        
        }else if(mode == "fragments"){
            
            ofBeginShape();
            for(int i = 0; i < currVertices.size(); i++){
                ofVertex(currVertices[i]);
            }
            ofEndShape(true);
        }else if(mode == "rotation"){
//            ofRotate(expansion);
            ofRotateY(expansion*30);
            ofRect(-size/2, 0, size, size);
        }
    ofPopMatrix();
}

void Tiles::createTileVertices(){

    ofPoint thisVertex;

    thisVertex.x = 0;
    thisVertex.y = 0;
    tileVertices.push_back(thisVertex);
    
    thisVertex.x = size;
    thisVertex.y = 0;
    tileVertices.push_back(thisVertex);
    
    thisVertex.x = size;
    thisVertex.y = size;
    tileVertices.push_back(thisVertex);
    
    thisVertex.x = 0;
    thisVertex.y = size;
    tileVertices.push_back(thisVertex);
}

void Tiles::createFragmentVertices(){
    ofPoint thisVertex;
    for(int i = 0; i < tileVertices.size(); i++){
        thisVertex.x = tileVertices[i].x + ofRandom(-breakage, breakage);
        thisVertex.y = tileVertices[i].y + ofRandom(-breakage, breakage);
        fragmentVertices.push_back(thisVertex);
    }
}

//--------------------------------------------------------------
