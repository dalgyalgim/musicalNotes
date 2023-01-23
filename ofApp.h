#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void drawColorLetters(int desiredCharacters);
        void drawGradientLetters (int desiredCharacters);
        void drawTimedLetters (int desiredCharacters);
        string getLetters(int number);
    private:
        ofTrueTypeFont korean;
    
        ofxPanel gui;
        ofxToggle color;
        ofxToggle gradient;
        double timeIndicator = 10;
    
};
