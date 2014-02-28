/*
 *  Tiles.cpp
 *  ciel_etoile_background
 *
 *  Created by Julie Huynh on 2/26/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "Tiles.h"

void Tiles:: setup(int tempX, int tempY) {
	
	gridX = tempX;
	gridY = tempY;	
	
//	cout << "x: " << gridX << ", y: " << gridY << endl;	
	
	tileCount = 20;
	moduleColor.set(0);
	moduleAlpha = 180;
	max_distance = 500; 
	

}
//--------------------------------------------------------------

void Tiles:: update() {
}

//--------------------------------------------------------------

void Tiles:: draw(float mouseX, float mouseY) {

ofNoFill();
ofSetColor(moduleColor, moduleAlpha);
ofSetLineWidth(3);

		
		float diameter = ofDist(mouseX, mouseY, gridX, gridY);
//		cout << mouseX;
		diameter = diameter/max_distance * 40;
		ofPushMatrix();
			ofTranslate(gridX, gridY, diameter*5);
				ofRect(0, 0, diameter, diameter);    //// also nice: ellipse(...)
		ofPopMatrix(); 
//ofRect(gridX, gridY, 20, 20);	

}
//--------------------------------------------------------------
