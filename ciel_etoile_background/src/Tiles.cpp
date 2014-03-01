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

}
//--------------------------------------------------------------

void Tiles:: update(string _mode, float mouseX, float mouseY) {
    mode = _mode;
}

//--------------------------------------------------------------

void Tiles:: draw(float mouseX, float mouseY) {

    ofSetColor(120, 0, 60);

    ofPushMatrix();
    ofTranslate(gridPos.x, gridPos.y);
    if(mode == "3D"){
        float diameter = ofDist(mouseX, mouseY, gridPos.x, gridPos.y);
        //		cout << mouseX;
        diameter = diameter/500 * 40;
        
        ofTranslate(ofGetWidth()/8, 0, diameter * 10);
        ofRect(0, 0, size/8, size/8);    //// also nice: ellipse(...)
    
    }
    ofPopMatrix();
//ofRect(gridX, gridY, 20, 20);	

}
//--------------------------------------------------------------
