#include "ofApp.h"
int a, b;
int numWidth, numHeight;

class lineData{
private:
    ofVec2f start, end;
    
public:
    lineData(ofVec2f _start, ofVec2f _end){
        start = _start;
        end = _end;
    }
    
    void draw(){
        ofDrawLine(start, end);
    }
    
    ofVec2f getStart(){
        return start;
    }
    
    ofVec2f getEnd(){
        return end;
    }
    
};

vector<lineData> yama;
vector<lineData> tani;

//--------------------------------------------------------------
void ofApp::setup(){
    a = 60;
    b = 100;
    numWidth = 8;
    numHeight = 6;
    
    //tate
    for(int i=0; i<numWidth+1; i++){
        yama.push_back(lineData(ofVec2f(a*i, 0), ofVec2f(a*i, numHeight*b)));
    }
    
    //nanalme
    for(int i=1; i<=numWidth; i++){
        if(i <= numHeight){
            tani.push_back(lineData(ofVec2f(i*a, 0), ofVec2f(0, i*b)));
            
            tani.push_back(lineData(ofVec2f((numWidth-i)*a, 0), ofVec2f(numWidth*a, i*b)));
            
        }else{
            tani.push_back(lineData(ofVec2f(i*a, 0), ofVec2f((i-numHeight)*a, numHeight*b)));
            
            tani.push_back(lineData(ofVec2f((numWidth-i)*a, 0), ofVec2f((numWidth-(i-numHeight))*a, numHeight*b)));
           
            
        }
        
     
    }
    
    for(int i=1; i<=numHeight; i++){
        tani.push_back(lineData(ofVec2f(numWidth*a, i*b), ofVec2f((numWidth-numHeight+i)*a, numHeight*b)));
        
        tani.push_back(lineData(ofVec2f(0, i*b), ofVec2f((numWidth-(numWidth-numHeight)-i)*a, numHeight*b)));
    }
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::outputFile(){
    string text = "<svg id=\"layer name\" data-name=\"data name\" xmlns=\"http://www.w3.org/2000/svg\" viewBox=\" 0 0 " + ofToString(numWidth*a) + " " + ofToString(numHeight*b) + "\">\n";
    
    text += "<defs>\n\t<style>.cls-1{fill:none;stroke:#000000;}.cls-2{fill:none;stroke:#FF0000;}</style>\n</defs>";
    
    text += "<title>test</title>\n";
    
    for(int i=0; i<yama.size(); i++){
        ofVec2f start = yama[i].getStart();
        ofVec2f end = yama[i].getEnd();
        
        text += "\t<line class=\"cls-1\" x1=\"" + ofToString(start.x) + "\" y1=\"" + ofToString(start.y) +
             "\" x2=\"" + ofToString(end.x) + "\" y2=\"" + ofToString(end.y) + "\"/>\n";
    }
    
    for(int i=0; i<tani.size(); i++){
        ofVec2f start = tani[i].getStart();
        ofVec2f end = tani[i].getEnd();
        
        text += "\t<line class=\"cls-2\" x1=\"" + ofToString(start.x) + "\" y1=\"" + ofToString(start.y) +
             "\" x2=\"" + ofToString(end.x) + "\" y2=\"" + ofToString(end.y) + "\"/>\n";
    }
    
    text += "\n</svg>";
    
    ofBuffer buffer = ofBuffer(text);
    ofBufferToFile("output.svg", buffer);
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    for(int i=0; i<yama.size(); i++){
        ofSetColor(255, 0, 0);
        yama[i].draw();
    }
    for(int i=0; i<tani.size(); i++){
        ofSetColor(0);
        tani[i].draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'a'){
        outputFile();
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
