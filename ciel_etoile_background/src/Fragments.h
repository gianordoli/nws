/*
 *  Fragments.h
 *  ciel_etoile_background
 *
 *  Created by Julie Huynh on 2/26/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */
#pragma once
#include "ofMain.h"

class Fragments : public ofBaseApp{
	
public:
	void setup(int tempX, int tempY);
	void update(float mouseX, float mouseY);
	void draw (float mouseX, float mouseY);
	
	int tileCount;
	int rectSize;
	
	int actRandomSeed;
	
	int gridX;
	int gridY;	
	
};
