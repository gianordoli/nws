#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableSmoothing();
    ofSetBackgroundAuto(false);
    ofToggleFullscreen();
    
    //    bgColor.set(0, 180, 180);
    //    bgColor.set(0, 180, 180, 20);
    bgColor.set(0, 20);
	ofBackground(bgColor);
    //	ofBackground(255);

    /*------------------- SOUND -------------------*/
    soundStream.listDevices();
  	soundStream.setDeviceID(2);
    
    //soundstream setup
    soundStream.setup(this, 0, 2, 44100, BUFFER_SIZE, 4);
    
	FFTanalyzer.setup(44100, BUFFER_SIZE/2, 2);
	
	FFTanalyzer.peakHoldTime = 15; // hold longer
	FFTanalyzer.peakDecayRate = 0.95f; // decay slower
	FFTanalyzer.linearEQIntercept = 0.9f; // reduced gain at lowest frequency
	FFTanalyzer.linearEQSlope = 0.01f; // increasing gain at higher frequencies
    /*---------------------------------------------*/
    
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
    
    
    /*---------------- BACKGROUND -----------------*/
	tileModes.push_back("3D");
	tileModes.push_back("fragments");
    selectedTileMode = tileModes[1];
    
    int nTiles = int(ofGetWidth()/40) *  int(ofGetHeight()/40);
    int i = 0;
	for (int gridY=0; gridY< ofGetHeight(); gridY += 40) {
		for (int gridX=0; gridX< ofGetWidth(); gridX+= 40) {
			Tiles thisTile;
			thisTile.setup(nTiles, i, selectedTileMode, gridX, gridY);
			myTiles.push_back(thisTile);
            //            cout << gridX << endl;
            i++;
		}
	}
    /*---------------------------------------------*/
    
    setGUI1();
    setGUI2();
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    /*------------------- SOUND -------------------*/
    float avg_power = 0.0f;
	myfft.powerSpectrum(0,(int)BUFFER_SIZE/2, left,BUFFER_SIZE,&magnitude[0],&phase[0],&power[0],&avg_power);
    
	for (int i = 0; i < (int)(BUFFER_SIZE/2); i++){
		freq[i] = magnitude[i];
	}
	
	FFTanalyzer.calculate(freq);
    
    for (int i = 0; i < (int)(BUFFER_SIZE/2 - 1); i++){
        //            ofRect(200+(i*4),600,4,-freq[i]*10.0f);
//        cout << freq[i] << endl;
        }

    //BACKGROUND
	for (int i=0; i < myTiles.size(); i++) {
		myTiles[i].update(selectedTileMode, mouseX, mouseY, freq);
	}
    
    // PARTICLES
    for(int i=0; i < myParticles.size(); i++){
        myParticles[i].update(myParticles.size(), expansion, shapeSize, nVertices, particleSize, selectedShape, selectedMode);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(bgColor);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    //bDrawAverages toggle 2 two different modes: actual FFT (512 values), or averages.
    if (!bDrawAverages) {
        //        cout << "bDrawAverages";
        
//
//        ofSetHexColor(0xffffff);
//        for (int i = 0; i < (int)(BUFFER_SIZE/2 - 1); i++){
//            ofRect(200+(i*4),600,4,-freq[i]*10.0f);
//        }
    }else{
    
    }

    //BACKGROUND
    for (int i = 0; i < myTiles.size(); i++) {
        myTiles[i].draw(mouseX, mouseY, freq);
    }
    
    //PARTICLES
    for(int i=0; i < myParticles.size(); i++){
        myParticles[i].draw(rotation);
    }
    
}

void testApp::audioIn(float * input, int bufferSize, int nChannels){
//    cout << "sound in" << endl;
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];
		right[i] = input[i*2+1];
//        cout << right[i] << endl;
    }
}

void testApp::guiEvent(ofxUIEventArgs &e){
	string name = e.widget->getName();
	int kind = e.widget->getKind();
    
    if(e.getName() == "FULLSCREEN"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        ofSetFullscreen(toggle->getValue());
        
        
        /*----------------- PARTICLES -----------------*/
	}else if(name == "EXPANSION"){
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
        
    }else if(name == "SHAPES"){
        ofxUIRadio *radio = (ofxUIRadio *) e.widget;
        cout << radio->getName() << " value: " << radio->getValue() << " active name: " << radio->getActiveName() << endl;
        selectedShape = radio->getActiveName();
        
    }else if(name == "MODES"){
        ofxUIRadio *radio = (ofxUIRadio *) e.widget;
        cout << radio->getName() << " value: " << radio->getValue() << " active name: " << radio->getActiveName() << endl;
        selectedMode = radio->getActiveName();
        
        
        /*---------------- BACKGROUND -----------------*/
    }else if(name == "TILE MODES"){
        ofxUIRadio *radio = (ofxUIRadio *) e.widget;
        cout << radio->getName() << " value: " << radio->getValue() << " active name: " << radio->getActiveName() << endl;
        selectedTileMode = radio->getActiveName();
    }
}

void testApp::setGUI1(){
    gui1 = new ofxUISuperCanvas("PARTICLES");
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
    gui2 = new ofxUISuperCanvas("BACKGROUND");
    gui2->addSpacer();
    gui2->addRadio("TILE MODES", tileModes, OFX_UI_ORIENTATION_HORIZONTAL);
    gui2->autoSizeToFitWidgets();
    ofAddListener(gui2->newGUIEvent,this,&testApp::guiEvent);
    gui2->loadSettings("gui2Settings.xml");
}

void testApp::exit(){
    gui1->saveSettings("gui1Settings.xml");
    delete gui1;
    gui2->saveSettings("gui2Settings.xml");
    delete gui2;
}



//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key){
        case 'g':{
            gui1->toggleVisible();
        }
            break;

        case 't': case 'T':
            bDrawAverages = !bDrawAverages;
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
