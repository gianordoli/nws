#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableSmoothing();
    ofSetBackgroundAuto(false);
    
	tileModes.push_back("3D");
	tileModes.push_back("fragments");
    selectedTileMode = tileModes[0];

//    setup for Tiles	
	for (int gridY=0; gridY< ofGetWidth(); gridY +=20) {
		for (int gridX=0; gridX< ofGetHeight(); gridX+=20) {
			Tiles thisTile;			
			thisTile.setup(selectedTileMode, gridX, gridY);
			myTiles.push_back(thisTile);			
		}
	}
    
    gui2 = new ofxUISuperCanvas("BACKGROUND");
    gui2->addSpacer();
        gui2->addRadio("TILE MODES", tileModes, OFX_UI_ORIENTATION_HORIZONTAL);
    gui2->addSpacer();
        gui2->addToggle("FULLSCREEN", false);
    gui2->autoSizeToFitWidgets();
    ofAddListener(gui2->newGUIEvent,this,&testApp::guiEvent);
    gui2->loadSettings("gui2Settings.xml");
}

//--------------------------------------------------------------
void testApp::update(){

	for (int i=0; i < myTiles.size(); i++) {
		myTiles[i].update(selectedTileMode, mouseX, mouseY);
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(0, 20);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
	for (int i = 0; i < myTiles.size(); i++) {
        myTiles[i].draw(mouseX, mouseY);
    }

}

void testApp::guiEvent(ofxUIEventArgs &e){
	string name = e.widget->getName();
	int kind = e.widget->getKind();
	
    if(e.getName() == "FULLSCREEN"){
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        ofSetFullscreen(toggle->getValue());
    }else if(name == "TILE MODES"){
        ofxUIRadio *radio = (ofxUIRadio *) e.widget;
        cout << radio->getName() << " value: " << radio->getValue() << " active name: " << radio->getActiveName() << endl;
        selectedTileMode = radio->getActiveName();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
