#ifndef OFX_AD_UTILS
#define OFX_AD_UTILS

#include "ofMain.h"

ofFloatColor lerpFloatColors(ofFloatColor c1, ofFloatColor c2, float amt);
ofColor lerpColors(ofColor c1, ofColor c2, float amt);
ofColor randomColorRGB();

class adImageSequenceRecorder {

public:
	adImageSequenceRecorder();
	~adImageSequenceRecorder();
	void setLength(int len);
	void startRecording();
	void setImage(ofFbo* src_fbo);
	void update();

	int sequence_length;
	int current_frame;
	bool isRecording;
	string filename;
	ofFbo* source_fbo;
	ofPixels pixels;
};

#endif