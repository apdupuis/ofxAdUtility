#include "adOfxGeneral.h"

adImageSequenceRecorder::adImageSequenceRecorder() 
{
	isRecording = false;
}
	
adImageSequenceRecorder::~adImageSequenceRecorder()
{

}


void adImageSequenceRecorder::setLength(int len)
{
	sequence_length = len;
}

void adImageSequenceRecorder::startRecording()
{
	ofFileDialogResult result = ofSystemSaveDialog("image_seq", "Save file");
	if (result.bSuccess) {
		filename = result.getPath();
		isRecording = true;
		current_frame = 0;
	}
}

void adImageSequenceRecorder::setImage(ofFbo* src_fbo)
{
	source_fbo = src_fbo;
}

void adImageSequenceRecorder::update()
{
	if (isRecording) {
		source_fbo->readToPixels(pixels);
		string filename_full = filename + "_" + ofToString(current_frame, 5, '0') + ".png";
		ofSaveImage(pixels, filename_full, OF_IMAGE_QUALITY_BEST);
		cout << "saved image " << filename_full << endl;

		current_frame++;
		if (current_frame >= sequence_length) {
			isRecording = false;
		}
	}
}

ofColor lerpColors(ofColor c1, ofColor c2, float amt)
{
	c1.r = ofLerp(c1.r, c2.r, amt);
	c1.g = ofLerp(c1.g, c2.g, amt);
	c1.b = ofLerp(c1.b, c2.b, amt);
	c1.a = ofLerp(c1.a, c2.a, amt);

	return c1;
}

ofFloatColor lerpFloatColors(ofFloatColor c1, ofFloatColor c2, float amt)
{
	c1.r = ofLerp(c1.r, c2.r, amt);
	c1.g = ofLerp(c1.g, c2.g, amt);
	c1.b = ofLerp(c1.b, c2.b, amt);
	c1.a = ofLerp(c1.a, c2.a, amt);

	return c1;
}

ofColor randomColorRGB()
{
	ofColor c;
	c.r = ofRandom(255);
	c.g = ofRandom(255);
	c.b = ofRandom(255);

	return c;
}