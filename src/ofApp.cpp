#include "ofApp.h"

bool arc;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(100);
    ofSetFrameRate(60);
    arc = false;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(100);
    for (int i = 1; i <= 18; i++){
        ofLine(0, ofGetHeight()/18*i, ofGetWidth(), ofGetHeight()/18*i);
    }
    for (int i = 1; i <= 30; i++){
        ofLine(ofGetWidth()/30*i, 0, ofGetWidth()/30*i, ofGetHeight());
    }
    
    ofLine(0, mouseY, ofGetWidth(), mouseY);
    ofLine(mouseX, 0, mouseX, ofGetHeight());
    
    float angle = atan2(mouseX - ofGetWidth()/2, mouseY - ofGetHeight()/2);
    angle = (180 * angle) / PI;
    
    ofSetColor(ofColor::fromHsb(ofMap(angle, -180, 180, 0, 255), 255, 255, 200));
    
    ofVec2f start(ofGetWidth()/2, ofGetHeight()/2);
    ofVec2f end(mouseX, mouseY);
    int distance = start.distance(end);
    ofNoFill();
    
    int vibration = distance - ofRandom(-15, 15);
    
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, vibration);
    
    ofFill();
    
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, vibration/5);
    ofLine(ofGetWidth()/2, ofGetHeight()/2, mouseX, mouseY);
    
    
    
    if (arc == true) {
        ofPath path;
        path.setCircleResolution(100);
        path.setFillColor(ofColor(0, 0, 0, 100));
        path.arc(ofGetWidth()/2, ofGetHeight()/2, distance, distance, 0, 90-angle);
        path.draw();
        
        ofSetColor(0);
        ofDrawBitmapString("radius:" + ofToString(angle), mouseX, mouseY);
        ofDrawBitmapString("deg:" + ofToString(distance), mouseX, mouseY+20);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (arc == true) {
        arc = false;
    }
    else {
        arc = true;
        
    }
    
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
