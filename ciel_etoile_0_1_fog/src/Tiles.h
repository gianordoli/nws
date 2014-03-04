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
    void createTileVertices();
    void createFragmentVertices();
	
    float size;         //tile size
    ofPoint gridPos;    //tile position
    
    //fragments mode
    vector<ofPoint> tileVertices;       //regular tiles vertices
    vector<ofPoint> fragmentVertices;   //fragmented vertices
    vector<ofPoint> currVertices;       //interpolated vertices
    float breakage;                     //fragmentation index
    
    string mode;
    
    ofColor color;
};

