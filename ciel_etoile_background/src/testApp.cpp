#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	

//setup for Tiles	
//	for (int gridY=0; gridY< ofGetWidth(); gridY +=10) {
//		for (int gridX=0; gridX< ofGetHeight(); gridX+=10) {
//			Tiles thisTile;			
//			thisTile.setup(gridX, gridY);
//			myTiles.push_back(thisTile);			
//		}
//	}
	//setup for Fragments
	for (int i=0; i < myFragments.size(); i++) {		
		myFragments[i].setup(mouseX, mouseY);
		}
	}	

//--------------------------------------------------------------
void testApp::update(){

	//draw for Fragments	
	for (int i=0; i < myFragments.size(); i++) {		
		myFragments[i].update(mouseX, mouseY);
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){

//draw for Tiles	
//	for (int i=0; i < myTiles.size(); i++) {		
//		myTiles[i].draw(mouseX, mouseY);
//	}
	//draw for Fragments
	int tileCount = 20;
	for (int gridY=0; gridY<tileCount; gridY++) {
		for (int gridX=0; gridX<tileCount; gridX++) {
			Fragments thisFragment;			
			thisFragment.draw(gridX, gridY);
			myFragments.push_back(thisFragment);
		}

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
