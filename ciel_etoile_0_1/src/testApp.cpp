#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableSmoothing();
    ofSetBackgroundAuto(false);
	
    bgColor.set(0, 180, 180, 20);
	ofBackground(bgColor);
    
    /*----------------- PARTICLES -----------------*/
    modes.push_back("static");
    modes.push_back("fuzz");
    selectedMode = modes[0];

    shapes.push_back("circle");
    shapes.push_back("spiral");
    shapes.push_back("star");
    shapes.push_back("grid");    
    selectedShape = shapes[0];
    
    expansion = 0;
    rotation = 0;
    shapeSize = ofGetHeight()/2 - 100;
    particleSize = 1;
    nVertices = 1;
    
    for(int i=0; i < NUM_PARTICLES; i++){
        Particle thisParticle;
        thisParticle.init(NUM_PARTICLES, i, shapeSize, particleSize, selectedShape);
        myParticles.push_back(thisParticle);
    }
    /*---------------------------------------------*/

    setGUI1();
    setGUI2();

}

//--------------------------------------------------------------
void testApp::update(){
//    float expansionX = mouseX/float(ofGetWidth());
//    cout << expansion;
    for(int i=0; i < myParticles.size(); i++){
        myParticles[i].update(myParticles.size(), expansion, shapeSize, nVertices, particleSize, selectedShape, selectedMode);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(bgColor);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    for(int i=0; i < myParticles.size(); i++){
        myParticles[i].draw(rotation);
    }
}

void testApp::guiEvent(ofxUIEventArgs &e){
	string name = e.widget->getName();
	int kind = e.widget->getKind();
	
	if(name == "EXPANSION"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		expansion = slider->getScaledValue();
    }else if(name == "ROTATION"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		rotation = slider->getScaledValue();
    }else if(name == "SHAPE SIZE"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		shapeSize = slider->getScaledValue();
    }else if(name == "VERTICES"){
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		nVertices = slider->getScaledValue();
    }else if(name == "PARTICLE SIZE"){
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        particleSize = slider->getScaledValue();
    }else if(e.getName() == "FULLSCREEN"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        ofSetFullscreen(toggle->getValue());
    }else if(name == "SHAPES"){
        ofxUIRadio *radio = (ofxUIRadio *) e.widget;
        cout << radio->getName() << " value: " << radio->getValue() << " active name: " << radio->getActiveName() << endl;
        selectedShape = radio->getActiveName();
        
    }else if(name == "MODES"){
        ofxUIRadio *radio = (ofxUIRadio *) e.widget;
        cout << radio->getName() << " value: " << radio->getValue() << " active name: " << radio->getActiveName() << endl;
        selectedMode = radio->getActiveName();
    }
}

void testApp::setGUI1(){
    gui1 = new ofxUISuperCanvas("Variables");
    gui1->addSpacer();
    gui1->addSlider("EXPANSION", 0, 1, expansion);
    gui1->addSpacer();
    gui1->addSlider("ROTATION", 0, 360, rotation);
    gui1->addSpacer();
    gui1->addSlider("SHAPE SIZE", 0, ofGetHeight()/2 - 100, shapeSize);
    gui1->addSpacer();
    gui1->addSlider("VERTICES", 1, 6.78, nVertices);
    gui1->addSpacer();
    gui1->addSlider("PARTICLE SIZE", 1, 50, particleSize);
    gui1->addSpacer();
    gui1->addRadio("SHAPES", shapes, OFX_UI_ORIENTATION_HORIZONTAL);
    gui1->addSpacer();
    gui1->addRadio("MODES", modes, OFX_UI_ORIENTATION_HORIZONTAL);
    gui1->addSpacer();
    gui1->addToggle("FULLSCREEN", false);
    gui1->autoSizeToFitWidgets();
    ofAddListener(gui1->newGUIEvent,this,&testApp::guiEvent);
    gui1->loadSettings("gui1Settings.xml");
}

void testApp::setGUI2(){
    
}

void testApp::exit(){
    gui1->saveSettings("gui1Settings.xml");
    delete gui1;
}



//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key){
        case 'g':{
            gui1->toggleVisible();
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
