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
    
    gui = new ofxUISuperCanvas("Variables");
    gui->addSpacer();
        gui->addRadio("TILE MODES", tileModes, OFX_UI_ORIENTATION_HORIZONTAL);
    gui->addSpacer();
        gui->addToggle("FULLSCREEN", false);
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);
    gui->loadSettings("guiSettings.xml");
}

//--------------------------------------------------------------
void testApp::update(){

	//draw for Fragments	
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
    
//draw for Tiles	
//	for (int i=0; i < myTiles.size(); i++) {		
//		myTiles[i].draw(mouseX, mouseY);
//	}
	//draw for Fragments
//	int tileCount = 20;
//	for (int gridY=0; gridY<tileCount; gridY++) {
//		for (int gridX=0; gridX<tileCount; gridX++) {
//			Fragments thisFragment;			
//			thisFragment.draw(gridX, gridY);
//			myFragments.push_back(thisFragment);
//		}
//
//	}
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
