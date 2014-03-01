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
	void setup(string _mode, int tempX, int tempY);
	void update(string _mode, float mouseX, float mouseY);
	void draw (float mouseX, float mouseY);
	
	float tileCount;
	ofColor moduleColor;
	int moduleAlpha;
	
    float size;
    ofPoint gridPos;
    
    string mode;
};

