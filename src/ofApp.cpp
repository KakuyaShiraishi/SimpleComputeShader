#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex(); // 0..1 のUV系にしておく

    // 512x512 RGBA32F のテクスチャを用意（Nearest相当）
    ofTextureData td;
    td.width = TEXTURE_WIDTH;
    td.height = TEXTURE_HEIGHT;
    td.glInternalFormat = GL_RGBA32F;
    result.allocate(td);
    result.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);

    // Compute Shader をロード
    compute.setupShaderFromFile(GL_COMPUTE_SHADER, "shaders/simple.comp");
    compute.linkProgram();

    // 画像ユニット0に result を書き込み用として結び付け
    glBindImageTexture(
        0,                                   // image unit
        result.getTextureData().textureID,   // テクスチャID
        0,                                   // mip level
        GL_FALSE,                            // layered
        0,                                   // layer
        GL_WRITE_ONLY,                       // アクセス（書き込みのみ）
        GL_RGBA32F                           // フォーマット
    );

    // Dispatch 一回だけ走らせる
    compute.begin();
    glDispatchCompute(TEXTURE_WIDTH / THREAD_NUM, TEXTURE_HEIGHT / THREAD_NUM, 1);
    compute.end();

    // 書き込み完了を同期（imageStore の可視化バリア）
    glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);

    dispatched = true;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if (dispatched) {
        result.draw(0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT);
        ofDrawBitmapStringHighlight("Compute result (RGBA32F)", 10, TEXTURE_HEIGHT + 20);
    }
    else {
        ofDrawBitmapStringHighlight("Dispatch not done.", 10, 20);
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
