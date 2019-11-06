#ifndef BALLLOCK_H_
#define BALLLOCK_H_

#include <vector>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace std;

class BallLock {
    public:
        BallLock(C2DRenderer* renderer, b2World& world, int layerID, int shapeID, int releaseLocation);
        b2Fixture* getFixture();
        int getLocation();
    private:
        int m_layerID;
        int m_releaseLocation;
        b2Fixture* m_fixture;
        vector<float> m_upperLock = {843.5, 532.5, 835.8, 540.9, 834.4, 543.6, 833.0, 546.2, 833.0, 548.1, 833.0, 549.9, 850.2, 564.0, 867.4, 578.0, 869.5, 578.0, 871.5, 578.0, 881.8, 567.7, 892.0, 557.5, 892.0, 555.2, 892.0, 553.0, 873.8, 538.5, 855.5, 524.0, 853.3, 524.0, 851.2, 524.0, 843.5, 532.5};
        vector<float> m_leftLock = {1086.2, 23.2, 1085.0, 24.4, 1085.0, 27.5, 1085.0, 30.6, 1086.2, 31.8, 1087.4, 33.0, 1090.5, 33.0, 1093.6, 33.0, 1094.8, 31.8, 1096.0, 30.6, 1096.0, 27.5, 1096.0, 24.4, 1094.8, 23.2, 1093.6, 22.0, 1090.5, 22.0, 1087.4, 22.0, 1086.2, 23.2};
        vector<float> m_middleLock = {767.5, 365.9, 765.5, 366.8, 763.0, 369.5, 760.5, 372.2, 760.5, 377.6, 760.5, 383.0, 763.7, 386.1, 766.9, 389.3, 772.4, 389.8, 777.9, 390.2, 780.9, 386.9, 783.9, 383.6, 784.6, 380.7, 785.2, 377.8, 784.6, 374.6, 784.0, 371.4, 781.1, 368.6, 778.2, 365.8, 773.8, 365.4, 769.5, 365.0, 767.5, 365.9};
        vector<float> m_upperMiddleLock = {787.0, 396.4, 787.0, 409.0, 790.1, 409.0, 793.1, 409.0, 796.0, 405.8, 798.9, 402.6, 799.6, 399.7, 800.2, 396.8, 799.6, 393.6, 799.0, 390.4, 796.2, 387.7, 793.4, 385.0, 790.2, 384.4, 787.0, 383.7, 787.0, 396.4};
        vector<float> m_lowerLock1 = {172.0, 229.0, 172.0, 248.0, 183.5, 248.0, 195.0, 248.0, 195.0, 229.0, 195.0, 210.0, 183.5, 210.0, 172.0, 210.0, 172.0, 229.0};
        vector<float> m_lowerLock2 = {118.0, 351.0, 118.0, 370.0, 129.5, 370.0, 141.0, 370.0, 141.0, 351.0, 141.0, 332.0, 129.5, 332.0, 118.0, 332.0, 118.0, 351.0};
        vector<vector<float>> m_points = {
            m_upperLock, m_leftLock, m_middleLock, m_upperMiddleLock, m_lowerLock1, m_lowerLock2
        };
};

#endif