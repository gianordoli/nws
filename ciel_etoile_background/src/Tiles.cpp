/*
 *  Tiles.cpp
 *  ciel_etoile_background
 *
 *  Created by Julie Huynh on 2/26/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "Tiles.h"

void Tiles:: setup(string _mode, int tempX, int tempY) {
    
    size = 40;
    mode = _mode;
	gridPos.x = tempX;
	gridPos.y = tempY;
    
    breakage = size;
    createTileVertices();
    createFragmentVertices();
    
    currVertices = tileVertices;
}
//--------------------------------------------------------------

void Tiles:: update(string _mode, float mouseX, float mouseY) {

    mode = _mode;
    
    //Updating the vertices position based on mouseX
    float expansion = ofMap(mouseX, 0, ofGetWidth(), 0, 1);
    for(int i = 0; i < currVertices.size(); i++){
        currVertices[i].x = ofLerp(tileVertices[i].x, fragmentVertices[i].x, expansion);
        currVertices[i].y = ofLerp(tileVertices[i].y, fragmentVertices[i].y, expansion);
    }
}

//--------------------------------------------------------------

void Tiles:: draw(float mouseX, float mouseY) {

    ofSetColor(0, 60);

    ofPushMatrix();
    ofTranslate(gridPos.x, gridPos.y);
    
        if(mode == "3D"){
            float diameter = ofDist(mouseX, mouseY, gridPos.x, gridPos.y);
            //		cout << mouseX;
            diameter = diameter/500 * 40;
            
            ofTranslate(ofGetWidth()/8, 0, diameter * 10);
            ofRect(0, 0, size/4, size/4);    //// also nice: ellipse(...)
        
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

    thisVertex.x = gridPos.x;
    thisVertex.y = gridPos.y;
    tileVertices.push_back(thisVertex);
    
    thisVertex.x = gridPos.x + size;
    thisVertex.y = gridPos.y;
    tileVertices.push_back(thisVertex);
    
    thisVertex.x = gridPos.x + size;
    thisVertex.y = gridPos.y + size;
    tileVertices.push_back(thisVertex);
    
    thisVertex.x = gridPos.x;
    thisVertex.y = gridPos.y + size;
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
