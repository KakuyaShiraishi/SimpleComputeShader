#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

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

	static constexpr int TEXTURE_WIDTH = 512;
	static constexpr int TEXTURE_HEIGHT = 512;
	static constexpr int THREAD_NUM = 8;

	ofShader compute;   // GL_COMPUTE_SHADER
	ofTexture result;   // 書き込み先（RGBA32F）
	bool dispatched = false;

};
