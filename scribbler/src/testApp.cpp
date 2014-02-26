#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    bgColor.set(0, 178, 213);
    fgColor.set(0, 0, 0);
    ofBackground(bgColor);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
	ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofSetColor(fgColor);
        ofNoFill();
        ofSetLineWidth(5);

        ofSetPolyMode(OF_POLY_WINDING_ODD);
    //    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    //    ofSetPolyMode(OF_POLY_WINDING_POSITIVE);
    //    ofSetPolyMode(OF_POLY_WINDING_NEGATIVE);    
    //    ofSetPolyMode(OF_POLY_WINDING_ABS_GEQ_TWO);

        ofBeginShape();
        float angleStep 	= TWO_PI/(100.0f + sin(ofGetElapsedTimef()/5.0f) * 60);
        float radiusAdder 	= 0.5f;
        float radius 		= 0;
        for (int i = 0; i < 200; i++){
            float anglef = (i) * angleStep;
            float x = radius * cos(anglef);
            float y = radius * sin(anglef);
            ofVertex(x,y);
            radius 	+= radiusAdder;
        }
        ofEndShape(FALSE);
	ofPopMatrix();
    
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
