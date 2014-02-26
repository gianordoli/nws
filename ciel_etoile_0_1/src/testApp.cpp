#include "testApp.h"

int mode;
vector<Particle> myParticles;

//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofBackground(0,130,164);
    
    mode = 0;
    
    for(int i=0; i < NUM_PARTICLES; i++){
        Particle thisParticle;
        thisParticle.init(NUM_PARTICLES, i);
        myParticles.push_back(thisParticle);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    float faderX = mouseX/float(ofGetWidth());
    for(int i=0; i < NUM_PARTICLES; i++){
        myParticles[i].update(mode, faderX);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i < NUM_PARTICLES; i++){
        myParticles[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    //    cout << key;
    mode = key - 48;
    cout << mode;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
