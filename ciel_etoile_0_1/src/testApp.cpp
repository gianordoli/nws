#include "testApp.h"

ofColor bgColor;

vector<string> modes;
string selectedMode;
float expansion;
float circleSize;
float particleSize;
vector<Particle> myParticles;

//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableSmoothing();
	
    bgColor.set(0, 180, 180, 20);
    
    ofSetBackgroundAuto(false);
	ofBackground(bgColor);
    
    modes.push_back("static");
    modes.push_back("fuzz");
    selectedMode = modes[0];
    expansion = 0;
    circleSize = 0;
    particleSize = 1;
    
    for(int i=0; i < NUM_PARTICLES; i++){
        Particle thisParticle;
        thisParticle.init(NUM_PARTICLES, i, circleSize, particleSize);
        myParticles.push_back(thisParticle);
    }
    
    gui = new ofxUISuperCanvas("Variables");
    gui->addSpacer();
        gui->addSlider("EXPANSION", 0, 1, expansion);
    gui->addSpacer();
        gui->addSlider("CIRCLE SIZE", 0, ofGetHeight()/2 - 100, circleSize);
    gui->addSpacer();
        gui->addSlider("PARTICLE SIZE", 1, 50, particleSize);
    gui->addSpacer();
    	gui->addRadio("MODES", modes, OFX_UI_ORIENTATION_HORIZONTAL);
    gui->addSpacer();
        gui->addToggle("FULLSCREEN", false);
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);
    gui->loadSettings("guiSettings.xml");
}

//--------------------------------------------------------------
void testApp::update(){
//    float expansionX = mouseX/float(ofGetWidth());
//    cout << expansion;
    for(int i=0; i < myParticles.size(); i++){
        myParticles[i].update(myParticles.size(), selectedMode, expansion, circleSize, particleSize);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(bgColor);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    for(int i=0; i < myParticles.size(); i++){
        myParticles[i].draw();
    }
}

void testApp::guiEvent(ofxUIEventArgs &e){
	string name = e.widget->getName();
	int kind = e.widget->getKind();
	
	if(name == "EXPANSION"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		expansion = slider->getScaledValue();
    }else if(name == "CIRCLE SIZE"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		circleSize = slider->getScaledValue();
    }else if(name == "PARTICLE SIZE"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        particleSize = slider->getScaledValue();
    }else if(e.getName() == "FULLSCREEN"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        ofSetFullscreen(toggle->getValue());
    }else if(name == "MODES"){
        ofxUIRadio *radio = (ofxUIRadio *) e.widget;
        cout << radio->getName() << " value: " << radio->getValue() << " active name: " << radio->getActiveName() << endl;
        selectedMode = radio->getActiveName();
    }

}

void testApp::exit(){
    gui->saveSettings("guiSettings.xml");
    delete gui;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
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
