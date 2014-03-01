#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ofxUI.h"

#define NUM_PARTICLES 100

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
	void exit();     
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

	void setGUI1();
	void setGUI2();
	
	ofxUISuperCanvas *gui1;
	ofxUISuperCanvas *gui2;
    
	void guiEvent(ofxUIEventArgs &e);
    
};
