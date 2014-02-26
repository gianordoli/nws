#include "testApp.h"

int mode;
float fader;
vector<Particle> myParticles;

//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableSmoothing();
	
	ofBackground(0,130,164);
    
    mode = 0;
    fader = 0;
    
    for(int i=0; i < NUM_PARTICLES; i++){
        Particle thisParticle;
        thisParticle.init(NUM_PARTICLES, i);
        myParticles.push_back(thisParticle);
    }
    
    gui = new ofxUISuperCanvas("Variables");
    gui->addSpacer();
        gui->addSlider("FADER", 0, 1, fader);
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);
    gui->loadSettings("guiSettings.xml");
}

//--------------------------------------------------------------
void testApp::update(){
//    float faderX = mouseX/float(ofGetWidth());
//    cout << fader;
    for(int i=0; i < NUM_PARTICLES; i++){
        myParticles[i].update(mode, fader);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i < NUM_PARTICLES; i++){
        myParticles[i].draw();
    }
}

void testApp::guiEvent(ofxUIEventArgs &e){
	string name = e.widget->getName();
	int kind = e.widget->getKind();
	
	if(name == "FADER"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		fader = slider->getScaledValue();
    }
}

void testApp::exit(){
    gui->saveSettings("guiSettings.xml");
    delete gui;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    //    cout << key;
    mode = key - 48;
//    cout << mode;
    switch (key){
        case 'g':{
            gui->toggleVisible();
        }
            break;
        default:
            break;
    }
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
