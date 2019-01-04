#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(1.5);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(90);

	int radius = 300;
	int deg_span = 10;

	for (int deg_2 = 0; deg_2 <= 180; deg_2 += deg_span) {

		int deg_start = ofNoise(ofRandom(1000), ofGetFrameNum() * 0.002) * 360;
		for (int deg_1 = deg_start; deg_1 < deg_start + 360; deg_1 += deg_span) {

			vector<glm::vec3> vertices_fill;
			vertices_fill.push_back(glm::vec3(
				radius * cos((deg_1 - deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 - deg_span * 0.5) * DEG_TO_RAD),
				radius * sin((deg_1 - deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 - deg_span * 0.5) * DEG_TO_RAD),
				radius * cos((deg_2 - deg_span * 0.5) * DEG_TO_RAD)
			));

			vertices_fill.push_back(glm::vec3(
				radius * cos((deg_1 + deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 - deg_span * 0.5) * DEG_TO_RAD),
				radius * sin((deg_1 + deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 - deg_span * 0.5) * DEG_TO_RAD),
				radius * cos((deg_2 - deg_span * 0.5) * DEG_TO_RAD)
			));

			vertices_fill.push_back(glm::vec3(
				radius * cos((deg_1 + deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 + deg_span * 0.5) * DEG_TO_RAD),
				radius * sin((deg_1 + deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 + deg_span * 0.5) * DEG_TO_RAD),
				radius * cos((deg_2 + deg_span * 0.5) * DEG_TO_RAD)
			));

			vertices_fill.push_back(glm::vec3(
				radius * cos((deg_1 - deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 + deg_span * 0.5) * DEG_TO_RAD),
				radius * sin((deg_1 - deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 + deg_span * 0.5) * DEG_TO_RAD),
				radius * cos((deg_2 + deg_span * 0.5) * DEG_TO_RAD)
			));

			ofSetColor(239);
			ofFill();
			ofBeginShape();
			ofVertices(vertices_fill);
			ofEndShape(true);

			vector<glm::vec3> vertices_noFill;
			vertices_noFill.push_back(glm::vec3(
				(radius + 1) * cos((deg_1 - deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 - deg_span * 0.5) * DEG_TO_RAD),
				(radius + 1) * sin((deg_1 - deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 - deg_span * 0.5) * DEG_TO_RAD),
				(radius + 1) * cos((deg_2 - deg_span * 0.5) * DEG_TO_RAD)
			));

			vertices_noFill.push_back(glm::vec3(
				(radius + 1) * cos((deg_1 + deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 - deg_span * 0.5) * DEG_TO_RAD),
				(radius + 1) * sin((deg_1 + deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 - deg_span * 0.5) * DEG_TO_RAD),
				(radius + 1) * cos((deg_2 - deg_span * 0.5) * DEG_TO_RAD)
			));

			vertices_noFill.push_back(glm::vec3(
				(radius + 1) * cos((deg_1 + deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 + deg_span * 0.5) * DEG_TO_RAD),
				(radius + 1) * sin((deg_1 + deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 + deg_span * 0.5) * DEG_TO_RAD),
				(radius + 1) * cos((deg_2 + deg_span * 0.5) * DEG_TO_RAD)
			));

			vertices_noFill.push_back(glm::vec3(
				(radius + 1) * cos((deg_1 - deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 + deg_span * 0.5) * DEG_TO_RAD),
				(radius + 1) * sin((deg_1 - deg_span * 0.5) * DEG_TO_RAD) * sin((deg_2 + deg_span * 0.5) * DEG_TO_RAD),
				(radius + 1) * cos((deg_2 + deg_span * 0.5) * DEG_TO_RAD)
			));

			ofSetColor(39);
			ofNoFill();
			ofBeginShape();
			ofVertices(vertices_noFill);
			ofEndShape(true);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}