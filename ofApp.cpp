#include "ofApp.h"
#include <array>;

//--------------------------------------------------------------
void ofApp::setup(){
    // ofEnableLighting();
    ofSetFullscreen(true);
    ofSetWindowShape(1920,1080);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
	ofSetSmoothLighting(true);
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor( 0, 0, 0 );
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    // light.setup();
	// light.setPointLight();
	// light.setPosition(ofGetWidth()/2,ofGetHeight()/2,-200);
	// light.setAttenuation(1, 1, 1);
    // light.disable();


    for (int i = 0; i < numParticles; i++) {
        particle[i].init(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),0,1);
    }

    attractor[0].init(ofGetWidth()/2,ofGetHeight()/2,0,ofGetHeight()/12,25,0.05);

    attractor[1].init(ofGetWidth()/8,ofGetHeight()/8,0,ofGetHeight()/32,25,0.1);
    attractor[2].init(ofGetWidth()/8,(ofGetHeight()/8)*7,0,ofGetHeight()/32,25,0.1);
    attractor[3].init((ofGetWidth()/8)*7,ofGetHeight()/8,0,ofGetHeight()/32,25,0.1);
    attractor[4].init((ofGetWidth()/8)*7,(ofGetHeight()/8)*7,0,ofGetHeight()/32,25,0.1);

    box.set(ofGetWidth()*2);
    box.setPosition(ofGetWidth()/2,ofGetHeight()/2,0);
}

//--------------------------------------------------------------
void ofApp::update(){    
    for(int j=minAttractor; j<activeAttractors;j++){
        attractor[j].setRad(attractor[j].rad + ofRandom(-1,2));
        if(attractor[j].rad > ofGetHeight()/8){attractor[j].setRad(ofGetHeight()/8);}
        if(j!=0){
            if(attractor[j].rad > ofGetHeight()/32){attractor[j].setRad(ofGetHeight()/32);}
        }
        for(int i=0;i<numParticles;i++){
            ofVec3f force = attractor[j].attract(particle[i],repel);
            if(j!=0){force = attractor[j].attract(particle[i],1);}
            particle[i].applyForce(force);
        }
    }
    for (int i=0;i<numParticles;i++){
        particle[i].checkEdges(0,ofGetWidth(),0,ofGetHeight());
        particle[i].update();
    }
    counter++;
    if(counter > counterMax){counter = 0;}
    if(counter == 0){
        repel = ofRandom(0,2);
        bgColor = repel * 255;
        counterMax = ofRandom(50,500);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(bgColor,20);
    ofFill();
    box.draw();
    for (int i=0;i<numParticles;i++){
        particle[i].invert = 0;
        for(int j=minAttractor;j<activeAttractors;j++){
            if(particle[i].pos.distance(attractor[j].pos) < attractor[j].rad){
                particle[i].draw(bgColor,255);
                particle[i].invert = 1;
            }
            else if(particle[i].invert == 0){
                particle[i].draw(255-bgColor,255);
            }
        }
    }
    for(int j=minAttractor;j<activeAttractors;j++){
        attractor[j].draw(255-bgColor,10);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f'){
        fs = !fs;
        ofSetFullscreen(fs);
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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