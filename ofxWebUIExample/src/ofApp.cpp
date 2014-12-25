#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofxWebUI &ui = ofxWebUI::ui();
    ui.setup("ofxWebUI Example");
    
    ofxWebUIOption o1 = ofxWebUIOption::createRangeOption(250, 1000, 2500);
    ui.bindParameter("x", ofxWebUITypeSlider, x, o1);
    
    ofxWebUIOption o2 = ofxWebUIOption::createRangeOption(-10000, 10000, 0);
    ui.bindParameter("property", ofxWebUITypeSlider, foo.p, o2);
    
    ofxWebUIOption o3 = ofxWebUIOption::rangeOption0_255(127);
    ui.bindParameter("r", ofxWebUITypeSlider, r, o3);
    ui.bindParameter("g", ofxWebUITypeSlider, g, o3);
    ui.bindParameter("b", ofxWebUITypeSlider, b, o3);
    
    ui.runServer(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofxWebUI::ui().update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(r, g, b);
    
    ofDrawBitmapString("x: " + ofToString(x), ofPoint(10, 20));
    
    ofDrawBitmapString("property: " + ofToString(foo.p), ofPoint(10, 60));
    
    ofDrawBitmapString("r: " + ofToString((int)r), ofPoint(10, 100));
    ofDrawBitmapString("g: " + ofToString((int)g), ofPoint(10, 130));
    ofDrawBitmapString("b: " + ofToString((int)b), ofPoint(10, 160));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
#if ENABLE_UNBIND
    if(key == 'r') {
        ofxWebUI::ui().unbindParameter("x");
    }
#endif
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
