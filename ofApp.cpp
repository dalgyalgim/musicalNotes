#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("♬♬♪♪ Ⴚტ⊙▂⊙ტჂ ♪♪♪♪ (－‸ ლ) ♪♪♬♬ ᕙ(⇀‸↼‶)ᕗ ♬♪♪♬");
    ofSetWindowShape(1200, 1200);
    ofSetFrameRate(10);
    ofBackground(ofColor::white);
    
    // gui Setup
    gui.setup("Different Letters", "settings.xml");
    gui.add( color.setup("colorful notes", false));
    gui.add(gradient.setup("gradient notes", false));
    
    // Font Settings
    ofTrueTypeFontSettings settings("AppleGothic.ttf", 14);
    settings.addRanges(ofAlphabet::Emoji);
    settings.addRanges(ofAlphabet::Korean);
    
    korean.load(settings);
}

//--------------------------------------------------------------
void ofApp::update(){
    timeIndicator += 5;
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    if (!color && !gradient) {drawTimedLetters(20);}
    else if (color) {drawColorLetters(20);}
    else if (gradient) {drawGradientLetters(20);}
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

//--------------------------------------------------------------
string ofApp::getLetters(int number)
{
    int randomNumber = rand() % number;
    if (randomNumber == 0) {return "♭";}
    else if (randomNumber == 1) {return "♩";}
    else if (randomNumber == 2) {return "♪";}
    else if (randomNumber == 3) {return "♬";}
    else if (randomNumber == 4) {return "♭";}
    return "♭";
}

//--------------------------------------------------------------
void ofApp::drawColorLetters(int desiredCharacters)
{
    // Calculate Spacing
    int xSpacing = ofGetWidth()/desiredCharacters;
    int ySpacing = ofGetHeight()/desiredCharacters;
    
    // Print Characters
    for (int i = 20; i < ofGetWidth(); i += xSpacing)
    {
        for (int j = 25; j < ofGetHeight(); j += ySpacing)
        {
            // Bounding Rectangles
            int border = rand() % 3;
            ofSetColor(rand() % 255, rand() % 255, rand() % 255, 45);
            ofDrawRectRounded(i - 5, j - 20, 30, 30, 5);
            if (border == 0)
            {
                ofNoFill();
                ofSetColor(ofColor:: black);
                ofDrawRectRounded(i - 5, j - 20, 30, 30, 4);
                ofFill();
                
            }
            
            // Chracters
            ofSetColor(ofColor::black, rand() % 255);
            korean.drawString(getLetters(5), i, j);
        }
    }
}

//--------------------------------------------------------------
void ofApp::drawGradientLetters(int desiredCharacters)
{
    // Calculate Spacing
    int xSpacing = ofGetWidth()/desiredCharacters;
    int ySpacing = ofGetHeight()/desiredCharacters;
    
    // Print First Half of Diagonal
    int alpha = 255;
    ofSetColor(ofColor::black, alpha);
    korean.drawString(getLetters(5), 20, 25);
    int i = 25 + ySpacing;
    for (; i < ofGetHeight(); i += ySpacing)
    {
        // Color Management
        alpha -= 10;
        if (alpha < 0) {alpha = 0;}
        
        // Initial Values
        int colIndex = 20;
        int rowIndex = i;
        
        // Loop
        while (rowIndex >= 25)
        {
            ofSetColor(ofColor::black, alpha);
            korean.drawString(getLetters(5), colIndex, rowIndex);
            rowIndex -= ySpacing;
            colIndex += xSpacing;
        }
    }
    
    // Print Second Half of Diagonal
    for (int j = 20 + xSpacing; j < ofGetWidth(); j += xSpacing)
    {
        // Color Management
        alpha += 10;
        if (alpha > 255)  {alpha = 255;}
    
        // Initial Values
        int colIndex = j;
        int rowIndex = i - ySpacing;
        
        std::cout << rowIndex << std::endl;
        
        // Loop
        while (colIndex < ofGetWidth())
        {
            ofSetColor(ofColor::black, alpha);
            korean.drawString(getLetters(5), colIndex, rowIndex);
            rowIndex -= ySpacing;
            colIndex += xSpacing;
        }
    }
}

//--------------------------------------------------------------
void ofApp::drawTimedLetters(int desiredCharacters)
{
    // Calculate Spacing and Coordinates;
    int xCoordinate = 20;
    int yCoordinate = 25;
    int xSpacing = ofGetWidth()/desiredCharacters;
    int ySpacing = ofGetHeight()/desiredCharacters;
    
    // Calculate Maximum Number of Characters.
    int maximumCount = pow(desiredCharacters, 2) + 1;
    
    // Calculate Current Characters.
    int countIndicator = timeIndicator / 5;
    if (countIndicator > maximumCount) {countIndicator = maximumCount;}
    
    for (int rowChar = 1; rowChar < countIndicator; rowChar++)
    {
        // (Row by Row)
        ofSetColor(rand() % 255, rand() % 255, rand() % 255, 45);
        
        // Draw Color Background Rectangles.
        ofDrawRectRounded(xCoordinate - 5, yCoordinate - 20, 30, 30, 5);
        
        // Draw Border Rectangles.
        ofNoFill();
        ofSetColor(ofColor::black);
        ofDrawRectRounded(xCoordinate - 5, yCoordinate - 20, 30, 30, 5);
        ofFill();
        
        // Draw String
        korean.drawString(getLetters(5), xCoordinate, yCoordinate);
        xCoordinate += xSpacing;
            
        // Update if 20 Characters have been drawn.
        if (rowChar % desiredCharacters == 0) {yCoordinate += ySpacing; xCoordinate = 20;}
    }
}
