#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  nbLedProjector = 45;
  dmx.connect("ttyUSB0"); // use the name
  dmx.setChannels(nbLedProjector*3);
  values.resize(nbLedProjector*3);

  ofEnableTextureEdgeHack();
  ofEnableSmoothing(); 
  ofSetCircleResolution(60);

  float width = 14;
  //float height = ofGetHeight()-20; 
  float height = 300; 
  float xInit = OFX_UI_GLOBAL_WIDGET_SPACING; 
  //float length = 320-xInit; 
  float length = ofGetWidth();

  gui = new ofxUICanvas(0, 0, length+xInit, ofGetHeight());

  for (int i = 0; i < (signed) nbLedProjector; i++){
    if (i%17 == 0){
      gui->addWidgetDown(new ofxUILabel("PROJECTEURS RGB", OFX_UI_FONT_MEDIUM));     
      gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);
    }
    gui->addLabel(ofToString(i+1)+".", OFX_UI_FONT_SMALL);     
    gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
    ofxUISlider *w = (ofxUISlider *) gui->addSlider(ofToString(i*3+1), 0.0, 255.0, &values[i*3], width,height);
    w->setIncrement(1);
    w->setColorBack(ofColor(172,162,162));
    w = (ofxUISlider *) gui->addSlider(ofToString(i*3+2), 0.0, 255.0, &values[i*3+1], width,height);
    w->setIncrement(1);
    w->setColorBack(ofColor(162,172,162));
    w = (ofxUISlider *) gui->addSlider(ofToString(i*3+3), 0.0, 255.0, &values[i*3+2], width,height);
    w->setIncrement(1);
    w->setColorBack(ofColor(162,162,172));
      
  }
  gui->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);
  gui->addSpacer(length-xInit, 1);     

  ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);	

}
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e)
{
}

//--------------------------------------------------------------
void testApp::update(){
  if ( dmx.isConnected()){
    for (int i = 0; i < (int)values.size(); i++){ 
      dmx.setLevel(i+1, values[i]);
    }
    cout << "Level: " << (int)dmx.getLevel(1) << "\t" << (int)dmx.getLevel(2) << "\t" << (int)dmx.getLevel(3) << endl;
    dmx.update();
  }
}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
