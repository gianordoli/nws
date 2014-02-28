/*
 *  Fragments.cpp
 *  ciel_etoile_background
 *
 *  Created by Julie Huynh on 2/26/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "Fragments.h"

void Fragments:: setup(int tempX, int tempY) {
	gridX = tempX;
	gridY = tempY;	
	
	cout << "x: " << gridX << ", y: " << gridY << endl;	
	
	rectSize = 30;
	
	actRandomSeed = 0;	

	
}
//--------------------------------------------------------------

void Fragments:: update(float mouseX, float mouseY) {

	
}

//--------------------------------------------------------------

void Fragments:: draw(float mouseX, float mouseY) {
	
	ofColor(360, 100, 100);
	ofBackground(360);
	ofSetLineWidth(0);
	
	ofFill();
	ofSetColor(192,200,164);
	
	ofSeedRandom(actRandomSeed);
	
//	ofRect(gridX, gridY, 20, 20);
			
			int posX = gridX;
			int posY = gridY;
			
			float shiftX1 = mouseX/20 * ofRandom(-1, 1);
			float shiftY1 = mouseY/20 * ofRandom(-1, 1);
			float shiftX2 = mouseX/20 * ofRandom(-1, 1);
			float shiftY2 = mouseY/20 * ofRandom(-1, 1);
			float shiftX3 = mouseX/20 * ofRandom(-1, 1);
			float shiftY3 = mouseY/20 * ofRandom(-1, 1);
			float shiftX4 = mouseX/20 * ofRandom(-1, 1);
			float shiftY4 = mouseY/20 * ofRandom(-1, 1);
			
			ofBeginShape();
			ofVertex(posX+shiftX1, posY+shiftY1);
			ofVertex(posX+rectSize+shiftX2, posY+shiftY2);
			ofVertex(posX+rectSize+shiftX3, posY+rectSize+shiftY3);
			ofVertex(posX+shiftX4, posY+rectSize+shiftY4);
			ofEndShape();
	
	
}
//--------------------------------------------------------------
