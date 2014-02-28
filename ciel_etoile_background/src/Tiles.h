/*
 *  Tiles.h
 *  ciel_etoile_background
 *
 *  Created by Julie Huynh on 2/26/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */
#pragma once
#include "ofMain.h"

class Tiles : public ofBaseApp{
	
public:
	void setup(int tempX, int tempY);
	void update();
	void draw (float mouseX, float mouseY);
	
	float tileCount;
	ofColor moduleColor;
	int moduleAlpha;
	int max_distance;
	
	int gridX;
	int gridY;	
};

