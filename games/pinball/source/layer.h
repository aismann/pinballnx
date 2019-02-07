#ifndef LAYER_H_
#define LAYER_H_

#include <vector>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace std;

// The pinball table is a series of layers.
// Each layer has it's own set of collision shapes and graphics, 
// Each layer's collision shapes have a category filter for box2d collisions.
// This allows the ball to pass from one layer to another by having the table 
// change the balls collision mask.
class Layer {
    public:
        Layer(C2DRenderer* renderer, b2World& world, int layerID);
        int getLayerID();
    private:
        void loadShape(vector<float> points, C2DRenderer* renderer, b2World& world, int layerID);
        int m_layerID;

        // Launch tube layer
        vector<float> m_tubeLeft = {0.0, 527.8, 0.0, 672.0, 463.8, 671.7, 927.5, 671.4, 939.0, 669.7, 950.5, 667.9, 962.0, 665.4, 973.5, 662.8, 985.5, 658.8, 997.5, 654.8, 1009.0, 649.4, 1020.4, 643.9, 1031.5, 636.6, 1042.5, 629.2, 1051.3, 621.0, 1060.1, 612.7, 1066.3, 604.6, 1072.6, 596.5, 1075.3, 592.3, 1078.0, 588.0, 1074.6, 584.6, 1071.2, 583.0, 1070.2, 583.0, 1069.2, 583.0, 1066.9, 586.7, 1064.6, 590.5, 1058.4, 598.6, 1052.1, 606.8, 1044.3, 614.0, 1036.5, 621.2, 1026.1, 628.1, 1015.8, 635.1, 1005.4, 640.0, 995.1, 645.0, 981.8, 649.4, 968.5, 653.8, 955.5, 656.5, 942.5, 659.2, 933.4, 659.7, 924.3, 660.3, 918.4, 658.5, 912.5, 656.8, 909.5, 655.7, 906.5, 654.7, 900.9, 651.3, 895.2, 648.0, 888.6, 644.8, 883.5, 641.6, 877.5, 638.4, 871.5, 635.3, 864.0, 631.3, 856.5, 627.3, 851.5, 624.1, 846.6, 621.0, 837.6, 616.5, 830.3, 612.0, 823.6, 608.8, 818.5, 605.7, 809.3, 600.8, 800.1, 596.0, 797.1, 596.0, 794.1, 596.0, 791.6, 598.3, 789.0, 600.5, 786.0, 604.5, 783.0, 608.5, 778.0, 615.5, 772.9, 622.5, 767.0, 630.5, 761.0, 638.5, 757.4, 643.7, 753.7, 649.0, 752.2, 649.0, 750.7, 649.0, 740.6, 642.7, 730.5, 636.3, 725.5, 633.8, 720.5, 631.3, 711.6, 625.6, 702.6, 620.0, 689.6, 613.0, 678.4, 606.0, 675.7, 606.0, 673.1, 606.0, 670.5, 607.2, 667.9, 608.4, 654.9, 623.6, 642.0, 638.9, 635.8, 644.4, 629.6, 650.0, 623.1, 651.9, 616.5, 653.8, 611.2, 654.9, 605.9, 656.0, 562.2, 656.0, 518.5, 656.0, 502.8, 654.5, 487.0, 653.1, 480.3, 651.9, 473.5, 650.8, 468.0, 647.7, 462.5, 644.7, 455.8, 639.4, 449.2, 634.0, 446.1, 627.3, 443.0, 620.5, 442.1, 619.0, 441.3, 617.5, 408.4, 617.2, 375.5, 617.0, 356.0, 636.5, 336.4, 656.1, 226.0, 655.7, 115.5, 655.4, 110.1, 653.8, 104.7, 652.1, 100.2, 649.3, 95.7, 646.5, 93.0, 643.0, 90.3, 639.5, 46.0, 513.0, 1.8, 386.5, 0.9, 385.0, 0.0999999999996, 383.5, -3.8660741275e-13, 527.8};
        vector<float> m_tubeRight = {0.1, 144.2, 0.2, 288.5, 1.5, 285.5, 2.8, 282.5, 42.8, 167.0, 82.9, 51.5, 86.5, 41.9, 90.2, 32.2, 93.2, 28.6, 96.1, 25.0, 100.6, 22.4, 105.0, 19.8, 110.2, 18.2, 115.5, 16.6, 226.2, 16.3, 337.0, 15.9, 358.0, 37.0, 379.0, 58.0, 391.0, 69.0, 401.9, 80.0, 452.7, 80.0, 503.5, 80.0, 511.0, 76.2, 518.5, 72.4, 529.6, 65.8, 540.7, 59.2, 565.1, 47.2, 589.5, 35.2, 596.0, 32.2, 602.5, 29.2, 615.0, 25.2, 627.5, 21.2, 635.0, 20.0, 642.5, 18.9, 647.0, 17.8, 651.5, 16.6, 801.5, 16.3, 951.5, 15.9, 962.5, 17.0, 973.5, 18.1, 984.5, 20.5, 995.5, 22.8, 1005.0, 26.0, 1014.5, 29.1, 1026.9, 35.1, 1039.2, 41.0, 1048.9, 47.3, 1058.5, 53.6, 1067.5, 61.2, 1076.5, 68.7, 1082.5, 75.1, 1088.6, 81.5, 1094.2, 88.5, 1099.8, 95.5, 1105.4, 104.2, 1111.1, 112.9, 1117.0, 125.2, 1122.9, 137.5, 1126.0, 147.0, 1129.2, 156.5, 1131.6, 167.8, 1134.0, 179.0, 1135.6, 194.8, 1137.1, 210.5, 1136.5, 366.0, 1135.9, 521.5, 1134.9, 531.0, 1134.0, 540.5, 1131.9, 550.9, 1129.8, 561.3, 1126.3, 571.9, 1122.9, 582.5, 1117.0, 594.8, 1111.1, 607.1, 1105.4, 615.8, 1099.8, 624.5, 1094.2, 631.5, 1088.6, 638.5, 1082.5, 644.9, 1076.5, 651.3, 1067.5, 658.8, 1058.5, 666.4, 1048.9, 672.7, 1039.2, 679.0, 1026.9, 684.9, 1014.5, 690.9, 1003.9, 694.3, 993.3, 697.8, 982.9, 699.9, 972.5, 702.0, 963.5, 703.0, 954.5, 704.0, 477.3, 704.0, 3.41060513165e-13, 704.0, 3.41060513165e-13, 712.0, 3.41060513165e-13, 720.0, 576.0, 720.0, 1152.0, 720.0, 1152.0, 360.0, 1152.0, 0.0, 576.0, 0.0, 4.54747350886e-13, 0.0, 0.1, 144.2};
        vector<vector<float>> m_launchTubeLayer = {
            m_tubeLeft, m_tubeRight
        };

        // Main table layer
        vector<float> m_launchExitLock = {1068.0, 585.4, 1066.8, 586.9, 1067.2, 589.2, 1067.5, 591.5, 1087.9, 606.2, 1108.4, 621.0, 1110.6, 621.0, 1112.8, 621.0, 1114.0, 619.6, 1115.2, 618.1, 1114.8, 615.8, 1114.5, 613.5, 1094.1, 598.8, 1073.6, 584.0, 1071.4, 584.0, 1069.2, 584.0, 1068.0, 585.4};
        vector<float> m_upperWall = {759.0, 53.1, 749.5, 53.9, 741.5, 55.0, 733.5, 56.0, 724.0, 57.6, 714.5, 59.1, 707.5, 60.6, 700.5, 62.1, 696.5, 63.0, 692.5, 63.9, 683.0, 65.5, 673.5, 67.2, 667.0, 69.2, 660.5, 71.1, 649.5, 74.6, 638.5, 78.2, 634.0, 80.2, 629.5, 82.2, 607.3, 93.1, 585.2, 104.0, 584.2, 104.0, 580.9, 105.8, 578.5, 107.7, 574.0, 110.0, 569.5, 112.4, 564.4, 115.7, 559.2, 119.0, 558.6, 120.6, 558.0, 122.2, 558.0, 125.4, 558.0, 128.6, 560.8, 133.1, 563.6, 137.5, 567.0, 145.0, 570.4, 152.5, 573.7, 158.2, 577.1, 164.0, 579.5, 164.6, 581.9, 165.2, 588.2, 161.7, 594.5, 158.2, 601.5, 154.8, 608.5, 151.3, 611.0, 150.1, 613.5, 149.0, 616.6, 147.0, 619.7, 145.0, 629.1, 143.5, 638.5, 142.0, 646.4, 140.9, 654.2, 139.8, 669.9, 140.3, 685.5, 140.7, 694.4, 142.4, 703.3, 144.2, 718.9, 149.4, 734.5, 154.7, 740.0, 157.5, 745.5, 160.3, 750.5, 163.6, 755.5, 166.8, 762.0, 170.4, 768.5, 174.0, 775.7, 177.6, 782.9, 181.2, 782.3, 184.4, 781.7, 187.5, 779.3, 191.9, 777.0, 196.3, 777.0, 198.2, 777.0, 200.1, 775.6, 203.5, 774.1, 206.9, 767.3, 204.9, 760.5, 202.9, 749.1, 200.0, 737.8, 197.0, 723.6, 197.1, 709.5, 197.1, 703.0, 198.0, 696.5, 198.9, 688.1, 201.3, 679.7, 203.6, 673.5, 208.7, 667.3, 213.8, 661.2, 220.9, 655.1, 227.9, 650.1, 235.3, 645.1, 242.8, 640.1, 252.2, 635.0, 261.7, 635.0, 264.6, 635.0, 267.5, 661.3, 301.5, 687.5, 335.5, 690.7, 335.8, 693.9, 336.1, 710.8, 327.6, 727.7, 319.0, 738.2, 308.2, 748.6, 297.4, 753.5, 290.4, 758.3, 283.5, 764.4, 275.0, 770.5, 266.5, 778.3, 251.0, 786.2, 235.5, 794.1, 214.0, 802.1, 192.5, 803.7, 188.0, 805.2, 183.5, 810.9, 172.5, 816.5, 161.5, 821.5, 154.0, 826.5, 146.6, 832.5, 140.6, 838.5, 134.7, 846.5, 128.0, 854.5, 121.3, 860.5, 117.3, 866.5, 113.3, 872.5, 110.2, 878.5, 107.2, 884.0, 105.5, 889.5, 103.7, 927.0, 103.3, 964.5, 102.8, 972.0, 104.4, 979.5, 106.0, 986.5, 109.5, 993.5, 112.9, 999.2, 117.5, 1004.9, 122.1, 1010.0, 128.8, 1015.0, 135.5, 1017.1, 139.8, 1019.3, 144.2, 1020.8, 144.8, 1022.3, 145.3, 1040.9, 143.6, 1059.5, 141.9, 1064.8, 140.9, 1070.0, 139.9, 1070.0, 137.8, 1070.0, 135.8, 1068.4, 129.6, 1066.8, 123.5, 1063.4, 116.2, 1060.0, 108.8, 1055.6, 102.7, 1051.2, 96.5, 1043.9, 89.4, 1036.5, 82.4, 1030.5, 78.3, 1024.5, 74.3, 1016.4, 70.2, 1008.3, 66.2, 997.8, 62.6, 987.2, 59.1, 977.4, 57.1, 967.5, 55.1, 959.5, 53.9, 951.5, 52.7, 860.0, 52.5, 768.5, 52.2, 759.0, 53.1};
        vector<float> m_leftSlide = {125.0, 51.1, 122.5, 52.1, 119.7, 54.8, 116.9, 57.5, 114.5, 62.1, 112.2, 66.7, 108.9, 76.6, 105.7, 86.5, 104.4, 88.5, 103.2, 90.5, 101.5, 96.5, 99.8, 102.5, 99.5, 104.2, 99.1, 105.8, 96.4, 114.2, 93.7, 122.5, 92.8, 123.7, 91.9, 124.8, 89.5, 132.2, 87.2, 139.5, 83.5, 149.0, 79.9, 158.5, 77.5, 165.0, 75.1, 171.5, 72.6, 178.5, 70.0, 185.5, 68.8, 187.5, 67.7, 189.5, 64.3, 198.0, 61.0, 206.4, 61.8, 207.2, 62.6, 208.0, 67.5, 206.3, 72.4, 204.7, 76.6, 205.8, 80.8, 206.9, 84.6, 209.5, 88.3, 212.0, 91.5, 212.0, 94.7, 212.0, 96.7, 209.7, 98.8, 207.5, 100.8, 202.5, 102.9, 197.5, 106.5, 188.0, 110.0, 178.5, 112.5, 172.0, 115.0, 165.5, 118.5, 156.0, 122.0, 146.5, 124.5, 140.0, 127.0, 133.5, 130.5, 124.3, 134.0, 115.0, 136.1, 108.3, 138.2, 101.5, 142.2, 89.5, 146.3, 77.5, 149.0, 71.4, 151.7, 65.3, 154.1, 63.1, 156.5, 60.8, 160.0, 59.1, 163.5, 57.5, 223.4, 57.0, 283.3, 56.5, 284.3, 54.8, 285.4, 53.2, 284.1, 51.6, 282.8, 50.0, 205.1, 50.1, 127.5, 50.1, 125.0, 51.1};
        vector<float> m_rightSlide = {85.2, 461.4, 82.0, 464.8, 77.4, 466.0, 72.8, 467.3, 67.7, 465.7, 62.6, 464.0, 61.8, 464.8, 61.0, 465.6, 64.3, 474.0, 67.7, 482.5, 68.8, 484.5, 70.0, 486.5, 72.6, 493.5, 75.1, 500.5, 77.5, 507.0, 79.9, 513.5, 83.5, 523.0, 87.2, 532.5, 89.5, 539.8, 91.9, 547.2, 92.8, 548.3, 93.7, 549.5, 96.4, 557.8, 99.1, 566.2, 99.5, 567.8, 99.8, 569.5, 101.5, 575.5, 103.2, 581.5, 104.4, 583.5, 105.7, 585.5, 108.9, 595.4, 112.2, 605.3, 114.5, 609.9, 116.9, 614.5, 119.7, 617.2, 122.5, 619.9, 125.3, 620.9, 128.1, 622.0, 205.4, 622.0, 282.8, 622.0, 284.1, 620.4, 285.4, 618.8, 284.3, 617.2, 283.3, 615.5, 223.4, 615.0, 163.5, 614.5, 160.0, 612.9, 156.5, 611.2, 154.1, 608.9, 151.7, 606.7, 149.0, 600.6, 146.3, 594.5, 142.2, 582.5, 138.2, 570.5, 136.1, 563.7, 134.0, 557.0, 130.5, 547.7, 127.0, 538.5, 124.5, 532.0, 122.0, 525.5, 118.5, 516.0, 115.0, 506.5, 112.5, 500.0, 110.0, 493.5, 106.5, 484.0, 102.9, 474.5, 99.6, 466.5, 96.3, 458.5, 92.4, 458.2, 88.5, 458.0, 85.2, 461.4};
        vector<float> m_leftSlideLine = {176.9, 88.6, 175.6, 90.2, 176.7, 91.8, 177.7, 93.5, 217.5, 93.5, 257.3, 93.5, 258.3, 91.8, 259.4, 90.2, 258.1, 88.6, 256.8, 87.0, 217.5, 87.0, 178.2, 87.0, 176.9, 88.6};
        vector<float> m_rightSlideLine = {176.9, 579.6, 175.6, 581.2, 176.7, 582.8, 177.7, 584.5, 217.5, 584.5, 257.3, 584.5, 258.3, 582.8, 259.4, 581.2, 258.1, 579.6, 256.8, 578.0, 217.5, 578.0, 178.2, 578.0, 176.9, 579.6};
        vector<float> m_leftBumper = {169.9, 125.0, 168.3, 126.0, 167.0, 129.2, 165.8, 132.5, 164.0, 136.5, 162.2, 140.5, 159.5, 147.0, 156.7, 153.5, 155.0, 157.5, 153.2, 161.5, 150.6, 168.0, 147.9, 174.5, 146.3, 177.4, 144.8, 180.2, 144.6, 185.6, 144.5, 190.9, 145.8, 192.2, 147.1, 193.5, 151.3, 193.5, 155.5, 193.5, 163.0, 189.0, 170.5, 184.5, 173.0, 183.1, 175.5, 181.7, 179.0, 179.8, 182.5, 177.9, 185.5, 176.1, 188.5, 174.3, 193.0, 171.6, 197.5, 168.9, 200.3, 167.9, 203.0, 166.8, 205.8, 164.1, 208.5, 163.1, 213.5, 160.0, 218.5, 156.9, 221.3, 155.9, 224.0, 154.8, 226.3, 152.5, 228.5, 151.8, 231.5, 149.5, 234.5, 147.3, 236.7, 146.6, 238.8, 145.9, 240.0, 144.5, 241.2, 143.0, 242.7, 143.0, 244.1, 143.0, 246.2, 141.0, 248.4, 139.0, 249.9, 139.0, 251.4, 139.0, 254.2, 136.3, 257.0, 133.6, 257.0, 131.0, 257.0, 128.3, 254.7, 126.2, 252.4, 124.0, 211.9, 124.0, 171.5, 124.1, 169.9, 125.0};
        vector<float> m_rightBumper = {147.4, 478.9, 145.3, 479.8, 144.6, 482.5, 143.9, 485.1, 144.6, 488.8, 145.3, 492.5, 146.6, 495.0, 147.9, 497.5, 150.6, 504.0, 153.2, 510.5, 155.0, 514.5, 156.7, 518.5, 159.5, 525.0, 162.2, 531.5, 164.0, 535.5, 165.8, 539.5, 167.0, 542.8, 168.3, 546.1, 170.1, 547.0, 171.9, 548.0, 212.3, 548.0, 252.7, 548.0, 254.8, 545.7, 257.0, 543.4, 257.0, 541.0, 257.0, 538.6, 254.3, 535.8, 251.6, 533.0, 250.0, 533.0, 248.4, 533.0, 246.2, 531.0, 244.1, 529.0, 242.7, 529.0, 241.2, 529.0, 240.0, 527.5, 238.8, 526.1, 236.7, 525.4, 234.5, 524.7, 231.5, 522.5, 228.5, 520.2, 226.3, 519.5, 224.0, 518.9, 221.3, 516.1, 218.5, 515.1, 213.5, 512.0, 208.5, 508.9, 205.8, 507.9, 203.0, 506.8, 200.3, 504.1, 197.5, 503.1, 193.0, 500.4, 188.5, 497.7, 185.5, 495.9, 182.5, 494.1, 179.0, 492.2, 175.5, 490.3, 173.0, 488.9, 170.5, 487.5, 163.4, 483.2, 156.2, 478.9, 152.9, 478.5, 149.5, 478.0, 147.4, 478.9};
        vector<vector<float>> m_layer1ShapeData = {
            m_tubeRight, m_tubeLeft, m_launchExitLock, m_upperWall, m_leftSlide, m_rightSlide, m_rightSlideLine, m_leftSlideLine, m_leftBumper, m_rightBumper
        };

        // Layer 2 shapes.
        vector<float> m_innerRails = {779.0, 47.2, 779.0, 52.3, 839.8, 51.7, 900.5, 51.2, 917.0, 52.1, 933.5, 53.0, 946.0, 54.6, 958.5, 56.1, 969.9, 58.6, 981.3, 61.2, 991.4, 64.7, 1001.5, 68.2, 1009.7, 72.5, 1018.0, 76.9, 1023.9, 81.4, 1029.8, 85.9, 1035.4, 91.7, 1041.1, 97.5, 1045.4, 104.0, 1049.8, 110.5, 1052.9, 116.8, 1056.1, 123.2, 1059.0, 132.0, 1061.9, 140.9, 1063.9, 151.2, 1065.9, 161.5, 1067.1, 174.9, 1068.3, 188.4, 1067.8, 196.5, 1067.2, 204.7, 1065.2, 209.3, 1063.2, 213.9, 1059.1, 218.2, 1055.1, 222.6, 1049.6, 225.3, 1044.1, 228.0, 1037.8, 229.8, 1031.5, 231.5, 1008.5, 231.4, 985.5, 231.3, 970.8, 228.7, 956.1, 226.1, 943.3, 223.1, 930.5, 220.1, 917.5, 216.5, 904.5, 213.0, 885.5, 206.9, 866.5, 200.8, 848.5, 194.3, 830.5, 187.8, 808.5, 179.0, 786.5, 170.2, 774.5, 165.0, 762.5, 159.9, 760.5, 157.5, 758.5, 155.2, 752.7, 152.6, 746.9, 150.0, 745.1, 150.0, 743.2, 150.0, 742.1, 151.4, 740.9, 152.9, 741.2, 155.7, 741.5, 158.5, 747.7, 161.5, 753.9, 164.5, 756.2, 166.8, 758.6, 169.0, 768.1, 173.1, 777.5, 177.2, 794.0, 184.0, 810.5, 190.7, 827.0, 197.0, 843.5, 203.2, 860.0, 209.0, 876.5, 214.8, 895.0, 220.3, 913.5, 225.9, 927.5, 229.5, 941.5, 233.1, 956.2, 236.0, 970.9, 239.0, 983.2, 240.5, 995.4, 242.0, 1011.5, 242.0, 1027.5, 242.0, 1036.8, 240.1, 1046.1, 238.1, 1053.5, 234.5, 1060.9, 230.8, 1066.0, 225.4, 1071.1, 220.0, 1073.5, 214.7, 1076.0, 209.4, 1077.0, 204.0, 1078.0, 198.7, 1078.0, 191.6, 1078.0, 184.5, 1077.0, 173.0, 1075.9, 161.5, 1073.9, 150.5, 1071.9, 139.6, 1068.8, 130.0, 1065.8, 120.5, 1061.3, 111.5, 1056.8, 102.5, 1052.3, 96.2, 1047.8, 89.8, 1042.1, 84.1, 1036.5, 78.4, 1029.7, 73.2, 1022.8, 68.1, 1013.2, 63.2, 1003.5, 58.2, 996.2, 55.6, 988.9, 53.0, 979.1, 50.5, 969.3, 48.0, 956.9, 46.1, 944.5, 44.1, 933.0, 43.0, 921.5, 42.0, 850.3, 42.0, 779.0, 42.0, 779.0, 47.2};
        vector<float> m_outerRails = {842.3, 9.7, 775.0, 10.0, 775.0, 15.1, 775.0, 20.3, 872.3, 19.9, 969.5, 19.5, 980.0, 21.8, 990.5, 24.1, 1000.7, 27.5, 1010.8, 30.9, 1018.7, 34.9, 1026.6, 38.8, 1036.1, 45.1, 1045.5, 51.4, 1055.0, 61.0, 1064.5, 70.5, 1070.8, 79.8, 1077.2, 89.1, 1082.5, 99.8, 1087.8, 110.5, 1091.3, 120.6, 1094.8, 130.7, 1097.5, 141.4, 1100.1, 152.2, 1102.6, 168.7, 1105.0, 185.2, 1105.2, 193.4, 1105.4, 201.5, 1104.3, 210.0, 1103.1, 218.5, 1100.5, 227.0, 1097.8, 235.5, 1096.1, 237.5, 1094.4, 239.5, 1091.0, 244.5, 1087.6, 249.5, 1081.2, 254.9, 1074.7, 260.3, 1070.1, 262.1, 1065.5, 263.9, 1057.0, 266.6, 1048.5, 269.3, 1028.0, 270.0, 1007.5, 270.8, 992.5, 270.0, 977.5, 269.2, 962.0, 266.1, 946.5, 262.9, 930.8, 259.0, 915.1, 255.0, 899.7, 250.5, 884.3, 246.1, 865.4, 239.9, 846.5, 233.8, 796.5, 216.5, 746.5, 199.2, 736.1, 197.9, 725.8, 196.6, 724.1, 197.7, 722.5, 198.7, 722.2, 200.9, 721.8, 203.1, 722.9, 204.4, 724.0, 205.7, 733.8, 207.4, 743.5, 209.0, 767.0, 216.9, 790.5, 224.8, 822.5, 236.0, 854.5, 247.1, 875.0, 253.5, 895.5, 259.8, 908.5, 263.5, 921.5, 267.2, 935.5, 270.5, 949.5, 273.8, 963.0, 276.6, 976.5, 279.3, 1011.0, 279.8, 1045.5, 280.2, 1055.6, 277.7, 1065.6, 275.1, 1071.2, 273.0, 1076.8, 270.9, 1084.6, 265.7, 1092.4, 260.5, 1099.6, 249.0, 1106.8, 237.5, 1108.5, 231.0, 1110.3, 224.5, 1111.6, 218.5, 1113.0, 212.5, 1113.0, 190.9, 1113.0, 169.3, 1110.9, 157.0, 1108.8, 144.8, 1105.5, 132.6, 1102.2, 120.4, 1098.4, 111.0, 1094.7, 101.5, 1090.9, 93.9, 1087.1, 86.3, 1079.9, 75.4, 1072.6, 64.5, 1062.0, 54.0, 1051.5, 43.5, 1042.5, 37.4, 1033.5, 31.2, 1024.4, 26.7, 1015.4, 22.1, 1007.4, 19.2, 999.5, 16.3, 990.7, 14.1, 981.9, 11.9, 971.7, 10.5, 961.5, 9.0, 935.5, 9.3, 909.5, 9.5, 842.3, 9.7};
        vector<vector<float>> m_layer2ShapeData = {
            m_innerRails, m_outerRails
        };

        // All the layers
        vector<vector<vector<float>>> m_layerData = {m_launchTubeLayer, m_layer1ShapeData, m_layer2ShapeData};
};
#endif