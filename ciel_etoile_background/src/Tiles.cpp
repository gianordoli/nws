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
    
    color.set(0, 180, 180, 60);
    
    breakage = size;
    createTileVertices();
    createFragmentVertices();
    
    currVertices = tileVertices;
    
//    for(int i = 0; i < currVertices.size(); i++){
//        cout << tileVertices[i].x << endl;
//    }
}
//--------------------------------------------------------------

void Tiles:: update(string _mode, float mouseX, float mouseY, float freq[]) {

    mode = _mode;
    
    //Updating the vertices position based on mouseX
    float expansion = ofMap(mouseX, 0, ofGetWidth(), 0, 1);
    for(int i = 0; i < currVertices.size(); i++){
//        currVertices[i].x = ofLerp(tileVertices[i].x, fragmentVertices[i].x, expansion);
//        currVertices[i].y = ofLerp(tileVertices[i].y, fragmentVertices[i].y, expansion);
        
        int index = ofMap(i, 0, nTiles, 0, 256);
        cout << abs(freq[index])*2 << endl;
        currVertices[i].x = ofLerp(tileVertices[i].x, fragmentVertices[i].x, abs(freq[index])/100);
        currVertices[i].y = ofLerp(tileVertices[i].y, fragmentVertices[i].y, abs(freq[index])/100);
        
    }
}

//--------------------------------------------------------------

void Tiles:: draw(float mouseX, float mouseY, float freq[]) {

    ofSetColor(color);

    ofPushMatrix();
    ofTranslate(gridPos.x, gridPos.y);
    
        if(mode == "3D"){

//            float dist = ofDist(mouseX, mouseY, gridPos.x, gridPos.y);
//            float zOffset = ofMap(dist, -ofGetWidth()/4, ofGetWidth()/4, 0, size*10, true);
//            ofTranslate(0, 0, zOffset);
            int index = ofMap(i, 0, nTiles, 0, 256);
            ofTranslate(0, 0, freq[index]*20.0f);
//            cout << freq[index] << endl;
            ofRect(0, 0, size, size);
//            freq[i]*10.0f
        
        }else if(mode == "fragments"){
            
            ofBeginShape();
            for(int i = 0; i < currVertices.size(); i++){
                ofVertex(currVertices[i]);
            }
            ofEndShape(true);
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
