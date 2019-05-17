#ifndef BUMPER_H_
#define BUMPER_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"
#include <list>
#include <string>

using namespace c2d;
using namespace std;

class Bumper {
    public:
        // -1 for shapeID creates circle
        Bumper(C2DRenderer* renderer, b2World& world, int layerID, int shapeID, float x = 0, float y = 0);
        b2Fixture* getFixture();
        b2Body* getBody();
        void update();
        void setHit();
        float getBumpForce();
    private:
        int m_layerID;
        b2Fixture* m_fixture;
        b2Body* m_body;
        C2DTexture* m_texture1;
        C2DTexture* m_texture2;
        float m_bumpForce;
        float m_radius = 0.3;
        float m_sensorRadius = 0.32;
        int m_flashFrames = 16;
        int m_flashFrameCurrent = m_flashFrames;
        vector<float> m_leftCenter = {130, 130};
        vector<float> m_rightCenter = {130, 550};
        vector<float> m_leftKickerCenter = {-20, 32};
        vector<float> m_rightKickerCenter = {-20, 640};
        vector<vector<float>> m_centers = {m_leftCenter, m_rightCenter, m_leftKickerCenter, m_rightKickerCenter};
        vector<float> m_leftBumperShape = {187.5, 152.0, 144.5, 177.0, 143.5, 178.4, 142.6, 179.9, 143.1, 180.4, 143.6, 181.0, 170.4, 170.6, 197.1, 160.2, 212.8, 148.5, 228.5, 136.7, 231.8, 133.7, 235.0, 130.6, 235.0, 128.8, 235.0, 127.0, 232.7, 127.0, 230.5, 127.0, 187.5, 152.0};
        vector<float> m_rightBumperShape = {143.2, 492.7, 143.5, 494.4, 187.0, 519.7, 230.5, 545.0, 232.7, 545.0, 235.0, 545.0, 235.0, 543.2, 235.0, 541.4, 231.8, 538.3, 228.5, 535.3, 212.8, 523.5, 197.1, 511.8, 170.3, 501.4, 143.6, 491.0, 143.2, 492.7};
        vector<float> m_leftKicker = {10.0, 31.0, 10.0, 44.0, 23.5, 44.0, 37.0, 44.0, 37.0, 31.0, 37.0, 18.0, 23.5, 18.0, 10.0, 18.0, 10.0, 31.0};
        vector<float> m_rightKicker = {10.0, 640.5, 10.0, 654.0, 23.5, 654.0, 37.0, 654.0, 37.0, 640.5, 37.0, 627.0, 23.5, 627.0, 10.0, 627.0, 10.0, 640.5};
        vector<vector<float>> m_shapes = {
            m_leftBumperShape, m_rightBumperShape, m_leftKicker, m_rightKicker
        };
};
#endif
