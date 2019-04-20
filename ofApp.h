#pragma once

#include "ofMain.h"
#include "Physics.h"

#define numParticles 10000
#define numAttractors 5

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		float orientation = 0;
		int counter = 0;
		int counterMax = 100;
		int bgColor = 255;
		int repel = 1;
		int minAttractor = 0;
		int activeAttractors = 1;
		int sphereRadius;
		bool fs;
		Particle particle[numParticles];
		Attractor attractor[numAttractors];

		ofLight light;
		ofBoxPrimitive box;
};
