#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ui.setup("ofxWebUI Example");
    ofxJsonxx::Object o;
    o << "min" << 0;
    o << "max" << 255;
    o << "initial" << 0;
    ui.bindParameter("r", ofxWebUITypeSlider, r, o);
    ui.bindParameter("g", ofxWebUITypeSlider, g, o);
    ui.bindParameter("b", ofxWebUITypeSlider, b, o);
    
    ofxJsonxx::Object o2;
    o2 << "min" << 250;
    o2 << "max" << 10000;
    o2 << "initial" << 875;
    ui.bindParameter("x", ofxWebUITypeSlider, x, o2);
    ui.runServer(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    ui.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(r, g, b);
    ofDrawBitmapString("r: " + ofToString(r), ofPoint(10, 10));
    ofDrawBitmapString("g: " + ofToString(g), ofPoint(10, 40));
    ofDrawBitmapString("b: " + ofToString(b), ofPoint(10, 70));
    ofDrawBitmapString("x: " + ofToString(x), ofPoint(10, 110));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
