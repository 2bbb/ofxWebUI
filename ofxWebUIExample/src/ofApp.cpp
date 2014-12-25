#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ui.setup("ofxWebUI Example");
    ofxJsonxx::Object o;
    o << "min" << 0;
    o << "max" << 1000;
    o << "initial" << 500;
    ui.bindParameter("foo", ofxWebUITypeSlider, x, o);
    ui.bindParameter("bar", ofxWebUITypeSlider, y, o);
    ui.bindParameter("buz", ofxWebUITypeSlider, z, o);
    ui.runServer(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    ui.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    ofDrawBitmapString("foo: " + ofToString(x), ofPoint(10, 10));
    ofDrawBitmapString("bar: " + ofToString(y), ofPoint(10, 40));
    ofDrawBitmapString("buz: " + ofToString(z), ofPoint(10, 70));
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
