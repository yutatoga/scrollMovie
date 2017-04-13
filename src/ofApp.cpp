#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //some path, may be absolute or relative to bin/data
    string path = "movies";
    ofDirectory dir(path);
    //only show png files
    dir.allowExt("mp4");
    //populate the directory object
    dir.listDir();
    
    scrollPlayer.rightViewId = 0;
    
    //go through and print out all the paths
    for(int i = 0; i < (int)dir.size(); i++){
        // set scrollPlayer
        ofVideoPlayer player;
        player.load(dir.getPath(i));
        player.play();
        if(i != 0) player.setVolume(0);
        scrollPlayer.players.push_back(player);
        
        // debug
        ofLogNotice(dir.getPath(i));
    }
    scrollPlayer.rightViewPosition.set(0, 0);
    scrollPlayer.movingSpeed.set(10, 0);
    
    // set window
    if (scrollPlayer.players[0].isLoaded()) {
        ofSetWindowShape(scrollPlayer.players[0].getWidth(), scrollPlayer.players[0].getHeight());
        ofSetWindowPosition(0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // update position
    scrollPlayer.rightViewPosition += scrollPlayer.movingSpeed;
    
    // when the rightViewPosition has reached/passed the end point
    if(scrollPlayer.rightViewPosition.x >= scrollPlayer.players[0].getWidth()){
        // update rightViewId
        scrollPlayer.rightViewId = (scrollPlayer.rightViewId+1)%(int)scrollPlayer.players.size();
        // update rightViewPosition
        scrollPlayer.rightViewPosition -= ofVec2f(scrollPlayer.players[0].getWidth(), 0);
    }
    
    // update 3 of players which are right view, left view, standby view.
    for(int i = scrollPlayer.rightViewId; i < scrollPlayer.rightViewId+3; i++){
        int playerIndex = i%(int)scrollPlayer.players.size();
        scrollPlayer.players[playerIndex].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw 3 of players which are right view, left view, stadnby view.
    for(int i = scrollPlayer.rightViewId; i < scrollPlayer.rightViewId+3; i++){
        int playerIndex = i%(int)scrollPlayer.players.size();
        scrollPlayer.players[playerIndex].draw(scrollPlayer.rightViewPosition-(i-scrollPlayer.rightViewId)*ofVec2f(scrollPlayer.players[0].getWidth(),0));
    }
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
