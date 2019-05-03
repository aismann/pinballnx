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
        vector<float> m_tubeLeft = {0.0, 527.8, 0.0, 672.0, 463.8, 671.7, 927.5, 671.4, 939.0, 669.7, 950.5, 667.9, 962.0, 665.4, 973.5, 662.8, 985.5, 658.8, 997.5, 654.8, 1009.0, 649.4, 1020.4, 643.9, 1031.5, 636.6, 1042.5, 629.2, 1051.3, 621.0, 1060.1, 612.7, 1066.3, 604.6, 1072.6, 596.5, 1075.3, 592.3, 1078.0, 588.0, 1074.6, 584.6, 1071.2, 583.0, 1070.2, 583.0, 1069.2, 583.0, 1066.9, 586.7, 1064.6, 590.5, 1058.4, 598.6, 1052.1, 606.8, 1044.3, 614.0, 1036.5, 621.2, 1026.1, 628.1, 1015.8, 635.1, 1005.4, 640.0, 995.1, 645.0, 981.8, 649.4, 968.5, 653.8, 955.9, 656.4, 943.3, 659.0, 940.6, 659.0, 938.0, 659.0, 938.0, 660.0, 938.0, 661.0, 926.5, 661.0, 915.0, 661.0, 915.0, 645.5, 915.0, 630.0, 920.3, 630.0, 925.6, 630.0, 935.1, 628.4, 944.5, 626.8, 954.0, 623.8, 963.5, 620.8, 973.7, 616.0, 983.9, 611.2, 992.7, 605.4, 1001.5, 599.7, 1007.5, 595.2, 1013.5, 590.6, 1025.3, 579.1, 1037.0, 567.7, 1037.0, 566.6, 1037.0, 565.5, 1018.1, 547.2, 999.1, 529.0, 994.3, 534.7, 989.5, 540.5, 983.5, 546.5, 977.5, 552.6, 942.0, 584.0, 906.5, 615.4, 896.5, 621.8, 886.5, 628.1, 868.5, 637.0, 850.5, 645.9, 840.5, 649.6, 830.5, 653.3, 819.0, 656.9, 807.5, 660.5, 706.2, 660.8, 604.9, 661.0, 589.0, 658.6, 573.0, 656.1, 561.3, 653.4, 549.5, 650.8, 538.0, 647.3, 526.5, 643.9, 519.0, 640.5, 511.5, 637.2, 496.0, 630.2, 480.5, 623.2, 470.5, 619.9, 460.5, 616.5, 418.3, 616.5, 376.0, 616.5, 356.3, 636.2, 336.5, 656.0, 181.7, 656.0, 27.0, 656.0, 27.0, 638.5, 27.0, 621.0, 55.4, 620.8, 83.7, 620.5, 42.4, 502.6, 1.1, 384.7, 0.5, 384.2, 2.35922392733e-13, 383.7, 2.35922392733e-13, 527.8};
        vector<float> m_tubeRight = {0.1, 144.2, 0.2, 288.5, 1.5, 285.5, 2.8, 282.5, 42.3, 168.5, 81.8, 54.5, 82.5, 52.7, 83.2, 51.0, 55.1, 51.0, 27.0, 51.0, 27.0, 33.5, 27.0, 16.0, 182.0, 16.0, 337.0, 16.0, 337.0, 17.0, 337.0, 18.0, 364.0, 45.0, 391.0, 72.0, 397.9, 72.0, 404.9, 72.0, 411.2, 68.6, 417.5, 65.2, 429.5, 58.6, 441.5, 52.0, 456.5, 45.6, 471.5, 39.2, 485.0, 34.7, 498.5, 30.2, 513.0, 26.6, 527.5, 23.0, 540.6, 21.0, 553.6, 19.0, 567.6, 18.0, 581.5, 17.0, 603.3, 17.0, 625.0, 17.0, 625.0, 33.4, 625.0, 49.9, 623.3, 50.4, 621.5, 50.9, 614.0, 52.5, 606.5, 54.1, 603.5, 55.7, 600.5, 57.3, 598.0, 58.6, 595.5, 59.9, 588.1, 66.8, 580.6, 73.6, 584.7, 79.5, 588.8, 85.5, 591.9, 88.7, 594.9, 92.0, 596.5, 92.0, 598.1, 92.0, 615.3, 83.4, 632.5, 74.7, 645.5, 67.0, 658.5, 59.3, 683.0, 47.2, 707.5, 35.2, 714.0, 32.2, 720.5, 29.2, 733.0, 25.2, 745.5, 21.2, 753.0, 20.0, 760.5, 18.9, 765.0, 17.8, 769.5, 16.7, 860.5, 16.3, 951.5, 15.9, 962.5, 17.0, 973.5, 18.1, 984.5, 20.5, 995.5, 22.8, 1005.0, 26.0, 1014.5, 29.1, 1026.9, 35.1, 1039.2, 41.0, 1048.9, 47.3, 1058.5, 53.6, 1067.5, 61.2, 1076.5, 68.7, 1082.5, 75.1, 1088.6, 81.5, 1094.2, 88.5, 1099.8, 95.5, 1105.4, 104.2, 1111.1, 112.9, 1117.0, 125.2, 1122.9, 137.5, 1126.0, 147.0, 1129.2, 156.5, 1131.6, 167.8, 1134.0, 179.0, 1135.6, 194.8, 1137.1, 210.5, 1136.5, 366.0, 1135.9, 521.5, 1134.9, 531.0, 1134.0, 540.5, 1131.9, 550.9, 1129.8, 561.3, 1126.3, 571.9, 1122.9, 582.5, 1117.0, 594.8, 1111.1, 607.1, 1105.4, 615.8, 1099.8, 624.5, 1094.2, 631.5, 1088.6, 638.5, 1082.5, 644.9, 1076.5, 651.3, 1067.5, 658.8, 1058.5, 666.4, 1048.9, 672.7, 1039.2, 679.0, 1026.9, 684.9, 1014.5, 690.9, 1003.9, 694.3, 993.3, 697.8, 982.9, 699.9, 972.5, 702.0, 963.5, 703.0, 954.5, 704.0, 477.3, 704.0, 5.68434188608e-13, 704.0, 5.68434188608e-13, 712.0, 5.68434188608e-13, 720.0, 576.0, 720.0, 1152.0, 720.0, 1152.0, 360.0, 1152.0, -1.13686837722e-13, 576.0, -1.13686837722e-13, 4.54747350886e-13, -1.13686837722e-13, 0.1, 144.2};
        vector<vector<float>> m_launchTubeLayer = {
            m_tubeLeft, m_tubeRight
        };

        // Main table layer
        vector<float> m_launchExitLock = {1068.0, 585.4, 1066.8, 586.9, 1067.2, 589.2, 1067.5, 591.5, 1087.9, 606.2, 1108.4, 621.0, 1110.6, 621.0, 1112.8, 621.0, 1114.0, 619.6, 1115.2, 618.1, 1114.8, 615.8, 1114.5, 613.5, 1094.1, 598.8, 1073.6, 584.0, 1071.4, 584.0, 1069.2, 584.0, 1068.0, 585.4};
        vector<float> m_upperWall = {786.0, 60.6, 777.5, 62.1, 765.8, 66.0, 754.2, 69.9, 744.5, 74.6, 734.9, 79.2, 723.2, 87.1, 711.5, 95.0, 708.1, 98.0, 704.6, 101.0, 707.4, 103.9, 710.3, 106.9, 714.7, 103.1, 719.0, 99.2, 727.8, 93.4, 736.5, 87.6, 746.8, 82.4, 757.1, 77.2, 767.8, 73.7, 778.5, 70.1, 788.0, 68.5, 797.5, 66.9, 881.5, 67.3, 965.5, 67.6, 977.6, 70.3, 989.7, 73.0, 998.6, 76.1, 1007.5, 79.2, 1015.7, 83.1, 1023.8, 87.0, 1032.7, 92.9, 1041.6, 98.9, 1048.7, 105.4, 1055.7, 111.9, 1061.3, 118.8, 1067.0, 125.7, 1068.8, 129.0, 1070.5, 130.9, 1072.4, 134.5, 1074.4, 138.1, 1073.4, 138.8, 1072.4, 139.5, 1064.4, 145.6, 1056.5, 151.7, 1050.7, 155.5, 1045.0, 159.3, 1039.7, 152.0, 1035.1, 145.5, 1031.3, 141.5, 1027.4, 137.5, 1021.3, 132.0, 1015.2, 126.5, 1007.3, 121.8, 999.4, 117.1, 991.6, 114.0, 983.9, 110.9, 976.4, 109.0, 968.9, 107.1, 958.9, 106.0, 948.8, 105.0, 920.1, 105.0, 891.4, 105.0, 883.2, 106.0, 875.0, 107.1, 866.3, 109.6, 857.5, 112.1, 849.2, 116.0, 840.8, 120.0, 833.7, 124.7, 826.6, 129.5, 817.8, 137.9, 809.0, 146.3, 804.0, 152.5, 799.1, 158.7, 794.5, 166.0, 790.0, 173.4, 790.0, 175.2, 790.0, 177.0, 792.6, 178.2, 795.3, 179.4, 796.6, 177.5, 798.0, 175.5, 803.9, 166.5, 809.8, 157.5, 817.5, 149.3, 825.1, 141.1, 833.1, 135.1, 841.1, 129.1, 851.3, 124.0, 861.5, 119.0, 871.5, 116.3, 881.5, 113.7, 914.0, 113.2, 946.5, 112.8, 957.1, 113.9, 967.8, 115.0, 975.6, 117.1, 983.5, 119.1, 991.1, 122.4, 998.7, 125.7, 1005.7, 130.3, 1012.7, 134.8, 1019.8, 141.4, 1026.8, 148.0, 1030.8, 153.3, 1034.9, 158.5, 1038.2, 164.1, 1041.6, 169.8, 1044.8, 168.5, 1047.9, 167.1, 1054.2, 162.9, 1060.5, 158.7, 1072.3, 149.7, 1084.0, 140.7, 1084.0, 139.5, 1084.0, 138.3, 1079.1, 130.2, 1074.3, 122.1, 1069.2, 115.8, 1064.2, 109.5, 1055.4, 101.0, 1046.5, 92.4, 1037.5, 86.4, 1028.5, 80.4, 1020.0, 76.3, 1011.5, 72.2, 1001.1, 68.6, 990.6, 64.9, 978.6, 62.3, 966.5, 59.6, 880.5, 59.4, 794.5, 59.1, 786.0, 60.6};
        vector<float> m_upperWall2 = {764.0, 450.1, 735.5, 476.1, 725.8, 485.1, 716.0, 494.2, 716.0, 495.4, 716.0, 496.7, 767.3, 545.2, 818.5, 593.6, 819.9, 596.3, 821.3, 598.9, 820.0, 600.5, 818.8, 602.0, 817.3, 602.0, 815.8, 602.0, 813.2, 603.9, 810.5, 605.7, 800.5, 608.8, 790.5, 612.0, 780.8, 613.0, 771.1, 614.0, 763.0, 614.0, 755.0, 614.0, 755.0, 609.0, 755.0, 603.9, 753.5, 600.5, 752.1, 597.0, 750.5, 596.4, 748.9, 595.7, 745.5, 591.3, 742.1, 586.9, 720.6, 565.9, 699.1, 545.0, 696.8, 545.0, 694.5, 545.0, 680.7, 556.1, 667.0, 567.2, 667.0, 569.5, 667.0, 571.8, 678.3, 589.3, 689.5, 606.9, 695.3, 616.0, 701.1, 625.2, 741.3, 624.7, 781.5, 624.2, 793.0, 622.1, 804.5, 620.0, 816.0, 616.4, 827.5, 612.9, 841.5, 606.1, 855.5, 599.2, 863.5, 593.3, 871.5, 587.3, 917.0, 545.6, 962.5, 503.8, 966.8, 499.5, 971.0, 495.1, 971.0, 492.9, 971.0, 490.7, 957.2, 476.6, 943.5, 462.5, 931.9, 450.3, 920.3, 438.2, 917.1, 436.5, 913.9, 434.9, 907.2, 439.4, 900.5, 443.9, 894.4, 445.9, 888.3, 447.9, 881.9, 448.6, 875.5, 449.2, 868.0, 448.1, 860.5, 446.9, 851.9, 444.0, 843.2, 441.1, 827.6, 434.0, 811.9, 427.0, 806.3, 425.5, 800.6, 424.0, 796.5, 424.0, 792.5, 424.0, 764.0, 450.1};
        vector<float> m_upperWall3 = {790.9, 256.3, 788.3, 257.5, 788.8, 259.0, 789.3, 260.5, 793.7, 269.3, 798.1, 278.2, 802.2, 284.3, 806.3, 290.4, 813.4, 297.6, 820.5, 304.7, 828.3, 309.8, 836.1, 314.9, 844.3, 318.0, 852.5, 321.2, 859.0, 322.6, 865.5, 324.0, 921.8, 324.0, 978.1, 324.0, 987.8, 325.0, 997.5, 326.1, 1007.9, 328.6, 1018.2, 331.0, 1025.2, 333.9, 1032.2, 336.9, 1039.1, 341.0, 1046.1, 345.1, 1052.6, 351.3, 1059.2, 357.4, 1063.6, 363.6, 1068.0, 369.8, 1071.5, 377.3, 1075.0, 384.9, 1077.0, 393.2, 1079.0, 401.5, 1079.0, 405.2, 1079.0, 409.0, 1081.4, 409.0, 1083.8, 409.0, 1085.4, 408.4, 1087.0, 407.8, 1087.0, 404.0, 1087.0, 400.3, 1084.6, 390.9, 1082.2, 381.5, 1079.3, 374.9, 1076.3, 368.3, 1072.5, 362.4, 1068.7, 356.5, 1061.1, 348.7, 1053.5, 340.9, 1046.5, 336.3, 1039.6, 331.7, 1032.4, 328.4, 1025.3, 325.1, 1016.4, 322.5, 1007.6, 319.9, 998.5, 318.3, 989.5, 316.7, 925.0, 316.1, 860.5, 315.5, 852.7, 312.7, 844.8, 310.0, 840.7, 307.8, 836.5, 305.7, 830.9, 301.9, 825.3, 298.1, 819.0, 291.8, 812.6, 285.5, 807.2, 277.1, 801.7, 268.7, 798.9, 262.1, 796.1, 255.5, 794.8, 255.3, 793.5, 255.1, 790.9, 256.3};
        vector<float> m_upperWall4 = {791.2, 313.2, 789.5, 316.5, 782.6, 323.7, 775.7, 331.0, 744.8, 346.6, 713.9, 362.1, 709.5, 365.1, 705.1, 368.1, 704.5, 370.1, 703.8, 372.1, 705.6, 377.1, 707.4, 382.0, 709.8, 384.3, 712.2, 386.5, 716.3, 386.4, 720.5, 386.3, 733.9, 380.5, 747.4, 374.8, 753.4, 375.4, 759.3, 376.0, 769.9, 379.6, 780.5, 383.2, 802.0, 392.7, 823.5, 402.2, 834.5, 406.5, 845.6, 410.9, 855.5, 413.5, 865.5, 416.1, 876.5, 416.7, 887.5, 417.3, 894.0, 415.6, 900.5, 413.9, 904.7, 411.4, 909.0, 408.9, 918.5, 397.4, 928.1, 385.9, 921.7, 378.2, 915.3, 370.5, 913.7, 370.2, 912.1, 369.9, 905.3, 375.4, 898.6, 381.0, 894.5, 383.0, 890.5, 384.9, 881.6, 386.1, 872.7, 387.2, 868.2, 386.6, 863.7, 386.0, 858.5, 383.6, 853.4, 381.3, 846.1, 375.0, 838.8, 368.8, 826.7, 354.8, 814.5, 340.8, 810.9, 335.7, 807.2, 330.5, 804.9, 325.0, 802.6, 319.5, 800.0, 315.0, 797.4, 310.5, 795.2, 310.2, 793.0, 309.9, 791.2, 313.2};
        vector<float> m_leftSlide = {120.5, 46.1, 118.4, 47.1, 117.1, 49.2, 115.8, 51.3, 113.3, 57.9, 110.9, 64.5, 107.9, 72.5, 104.9, 80.5, 103.6, 84.0, 102.3, 87.5, 97.1, 101.5, 91.9, 115.5, 89.9, 121.0, 87.8, 126.5, 86.5, 130.0, 85.1, 133.5, 82.6, 140.0, 80.2, 146.5, 76.4, 156.5, 72.7, 166.5, 70.3, 173.0, 67.9, 179.5, 66.6, 183.0, 65.3, 186.5, 62.6, 193.8, 59.8, 201.2, 64.2, 200.8, 67.9, 199.7, 72.4, 201.0, 76.9, 202.2, 80.3, 205.7, 83.8, 209.1, 87.6, 208.8, 91.3, 208.5, 94.6, 200.5, 97.9, 192.5, 101.5, 183.0, 105.0, 173.5, 107.5, 167.0, 110.0, 160.5, 113.5, 151.0, 117.0, 141.5, 119.5, 135.0, 122.0, 128.5, 125.5, 119.3, 129.0, 110.0, 131.1, 103.3, 133.2, 96.5, 137.2, 84.5, 141.3, 72.5, 144.0, 66.4, 146.7, 60.3, 149.1, 58.1, 151.5, 55.8, 155.0, 54.1, 158.5, 52.5, 218.4, 52.0, 278.3, 51.5, 279.3, 49.8, 280.4, 48.2, 279.1, 46.6, 277.8, 45.0, 200.1, 45.1, 122.5, 45.1, 120.5, 46.1};
        vector<float> m_rightSlide = {80.2, 466.4, 77.0, 469.8, 72.4, 471.0, 67.9, 472.3, 64.2, 471.2, 60.6, 470.1, 62.4, 477.7, 64.9, 484.5, 67.5, 491.5, 70.1, 498.5, 71.4, 502.0, 72.7, 505.5, 76.4, 515.5, 80.1, 525.5, 81.5, 529.0, 82.9, 532.5, 85.5, 539.5, 88.2, 546.5, 90.0, 551.5, 91.9, 556.5, 97.1, 570.5, 102.3, 584.5, 103.6, 588.0, 104.9, 591.5, 107.9, 599.5, 110.9, 607.5, 113.3, 614.1, 115.8, 620.7, 117.1, 622.8, 118.4, 624.9, 120.7, 625.9, 123.1, 627.0, 200.4, 627.0, 277.8, 627.0, 279.1, 625.4, 280.4, 623.8, 279.3, 622.2, 278.3, 620.5, 218.4, 620.0, 158.5, 619.5, 155.0, 617.9, 151.5, 616.2, 149.1, 613.9, 146.7, 611.7, 144.0, 605.6, 141.3, 599.5, 137.2, 587.5, 133.2, 575.5, 131.1, 568.7, 129.0, 562.0, 125.5, 552.7, 122.0, 543.5, 119.5, 537.0, 117.0, 530.5, 113.5, 521.0, 110.0, 511.5, 107.5, 505.0, 105.0, 498.5, 101.5, 489.0, 97.9, 479.5, 94.6, 471.5, 91.3, 463.5, 87.4, 463.2, 83.5, 463.0, 80.2, 466.4};
        vector<float> m_leftSlideLine = {163.9, 81.6, 162.6, 83.2, 163.7, 84.8, 164.7, 86.5, 204.5, 86.5, 244.3, 86.5, 245.3, 84.8, 246.4, 83.2, 245.1, 81.6, 243.8, 80.0, 204.5, 80.0, 165.2, 80.0, 163.9, 81.6};
        vector<float> m_rightSlideLine = {163.9, 586.6, 162.6, 588.2, 163.7, 589.8, 164.7, 591.5, 204.5, 591.5, 244.3, 591.5, 245.3, 589.8, 246.4, 588.2, 245.1, 586.6, 243.8, 585.0, 204.5, 585.0, 165.2, 585.0, 163.9, 586.6};
        vector<float> m_leftBumper = {156.9, 116.0, 155.3, 117.0, 154.0, 120.2, 152.8, 123.5, 151.0, 127.5, 149.2, 131.5, 146.5, 138.0, 143.7, 144.5, 142.0, 148.5, 140.2, 152.5, 137.6, 159.0, 134.9, 165.5, 133.3, 168.4, 131.8, 171.2, 131.6, 176.6, 131.5, 181.9, 132.8, 183.2, 134.1, 184.5, 138.3, 184.5, 142.5, 184.5, 150.0, 180.0, 157.5, 175.5, 160.0, 174.1, 162.5, 172.7, 166.0, 170.8, 169.5, 168.9, 172.5, 167.1, 175.5, 165.3, 180.0, 162.6, 184.5, 159.9, 187.3, 158.9, 190.0, 157.8, 192.8, 155.1, 195.5, 154.1, 200.5, 151.0, 205.5, 147.9, 208.3, 146.9, 211.0, 145.8, 213.3, 143.5, 215.5, 142.8, 218.5, 140.5, 221.5, 138.3, 223.7, 137.6, 225.8, 136.9, 227.0, 135.5, 228.2, 134.0, 229.7, 134.0, 231.1, 134.0, 233.2, 132.0, 235.4, 130.0, 236.9, 130.0, 238.4, 130.0, 241.2, 127.3, 244.0, 124.6, 244.0, 122.0, 244.0, 119.3, 241.7, 117.2, 239.4, 115.0, 198.9, 115.0, 158.5, 115.1, 156.9, 116.0};
        vector<float> m_rightBumper = {134.4, 487.9, 132.3, 488.8, 131.6, 491.5, 130.9, 494.1, 131.6, 497.8, 132.3, 501.5, 133.6, 504.0, 134.9, 506.5, 137.6, 513.0, 140.2, 519.5, 142.0, 523.5, 143.7, 527.5, 146.5, 534.0, 149.2, 540.5, 151.0, 544.5, 152.8, 548.5, 154.0, 551.8, 155.3, 555.1, 157.1, 556.0, 158.9, 557.0, 199.3, 557.0, 239.7, 557.0, 241.8, 554.7, 244.0, 552.4, 244.0, 550.0, 244.0, 547.6, 241.3, 544.8, 238.6, 542.0, 237.0, 542.0, 235.4, 542.0, 233.2, 540.0, 231.1, 538.0, 229.7, 538.0, 228.2, 538.0, 227.0, 536.5, 225.8, 535.1, 223.7, 534.4, 221.5, 533.7, 218.5, 531.5, 215.5, 529.2, 213.3, 528.5, 211.0, 527.9, 208.3, 525.1, 205.5, 524.1, 200.5, 521.0, 195.5, 517.9, 192.8, 516.9, 190.0, 515.8, 187.3, 513.1, 184.5, 512.1, 180.0, 509.4, 175.5, 506.7, 172.5, 504.9, 169.5, 503.1, 166.0, 501.2, 162.5, 499.3, 160.0, 497.9, 157.5, 496.5, 150.4, 492.2, 143.2, 487.9, 139.9, 487.5, 136.5, 487.0, 134.4, 487.9};
        vector<vector<float>> m_layer1ShapeData = {
            m_tubeRight, m_tubeLeft, m_launchExitLock, m_upperWall, m_upperWall2, m_upperWall4, m_leftSlide, m_rightSlide, m_rightSlideLine, m_leftSlideLine, m_leftBumper, m_rightBumper
        };

        // Layer 2 shapes.
        vector<float> m_leftInnerRail = {271.4, 52.4, 270.9, 53.8, 271.2, 56.7, 271.5, 59.5, 419.0, 59.8, 566.5, 60.0, 644.8, 142.9, 723.0, 225.7, 734.8, 237.1, 746.5, 248.6, 756.6, 255.3, 766.6, 261.9, 776.0, 266.4, 785.5, 270.8, 793.4, 273.5, 801.3, 276.1, 809.9, 278.0, 818.5, 279.9, 830.5, 281.1, 842.5, 282.3, 908.5, 281.7, 974.5, 281.1, 983.5, 280.0, 992.5, 278.8, 1001.6, 276.5, 1010.6, 274.2, 1018.3, 271.0, 1025.9, 267.8, 1032.2, 263.8, 1038.5, 259.7, 1044.1, 253.9, 1049.8, 248.0, 1054.8, 237.8, 1059.9, 227.5, 1061.1, 223.0, 1062.3, 218.5, 1062.4, 205.0, 1062.5, 191.5, 1059.4, 182.8, 1056.3, 174.1, 1050.5, 163.8, 1044.7, 153.5, 1040.4, 147.4, 1036.2, 141.4, 1030.2, 135.9, 1024.3, 130.4, 1018.6, 126.6, 1012.9, 122.9, 1005.2, 119.0, 997.4, 115.1, 988.2, 112.1, 979.1, 109.1, 968.5, 107.0, 957.9, 105.0, 931.4, 105.0, 905.0, 105.0, 905.0, 108.9, 905.0, 112.9, 934.3, 113.2, 963.5, 113.6, 969.5, 115.3, 975.5, 117.0, 984.9, 120.7, 994.3, 124.3, 996.1, 126.1, 998.0, 128.0, 999.3, 128.0, 1000.7, 128.0, 1008.1, 133.1, 1015.5, 138.3, 1025.0, 147.9, 1034.5, 157.6, 1039.4, 164.9, 1044.3, 172.3, 1047.3, 179.9, 1050.3, 187.5, 1050.8, 196.0, 1051.2, 204.5, 1050.1, 210.3, 1048.9, 216.0, 1045.5, 222.8, 1042.1, 229.5, 1036.1, 236.6, 1030.1, 243.8, 1022.0, 249.9, 1013.9, 256.0, 1012.4, 256.0, 1011.0, 256.0, 1002.2, 261.8, 993.5, 266.0, 983.8, 268.5, 974.0, 270.9, 963.8, 271.9, 953.5, 272.8, 905.0, 273.1, 856.5, 273.5, 842.5, 273.4, 828.5, 273.3, 818.5, 271.6, 808.5, 269.8, 796.9, 266.0, 785.3, 262.2, 777.3, 258.2, 769.4, 254.2, 760.2, 248.0, 751.0, 241.9, 742.3, 233.7, 733.7, 225.5, 726.1, 216.0, 718.6, 206.5, 706.6, 192.0, 694.6, 177.5, 678.3, 158.3, 662.0, 139.1, 662.0, 137.8, 662.0, 136.4, 650.8, 125.3, 639.5, 114.2, 617.2, 92.8, 594.8, 71.5, 584.2, 61.5, 573.5, 51.4, 532.0, 52.3, 490.5, 53.1, 481.3, 52.1, 472.2, 51.0, 372.0, 51.0, 271.9, 51.0, 271.4, 52.4};
        vector<float> m_leftOuterRail = {831.0, 61.9, 831.0, 66.0, 847.3, 66.1, 863.5, 66.2, 914.5, 66.9, 965.5, 67.7, 976.3, 69.9, 987.1, 72.1, 996.2, 75.1, 1005.3, 78.0, 1013.8, 82.0, 1022.4, 86.1, 1032.4, 92.7, 1042.5, 99.4, 1053.0, 109.9, 1063.6, 120.5, 1069.2, 129.0, 1074.8, 137.5, 1079.4, 147.6, 1084.0, 157.7, 1086.1, 167.6, 1088.2, 177.5, 1089.0, 182.5, 1089.9, 187.5, 1089.9, 206.6, 1090.0, 225.6, 1088.9, 231.6, 1087.8, 237.5, 1087.1, 238.5, 1086.4, 239.5, 1085.0, 244.0, 1083.7, 248.5, 1080.9, 254.1, 1078.2, 259.7, 1070.0, 269.9, 1061.7, 280.1, 1051.6, 290.2, 1041.5, 300.4, 1027.0, 312.4, 1012.5, 324.5, 994.0, 339.0, 975.5, 353.4, 947.1, 374.8, 918.8, 396.2, 912.6, 399.1, 906.5, 401.9, 900.5, 403.5, 894.5, 405.0, 885.2, 406.1, 875.8, 407.1, 865.5, 406.1, 855.2, 405.1, 847.5, 403.5, 839.8, 401.9, 831.3, 399.4, 822.7, 396.9, 813.1, 393.4, 803.5, 389.8, 786.1, 381.4, 768.8, 373.0, 756.6, 365.9, 744.5, 358.7, 738.8, 354.8, 733.1, 351.0, 730.7, 350.1, 728.3, 349.2, 715.9, 340.5, 703.5, 331.8, 699.2, 328.3, 694.9, 324.8, 693.5, 325.4, 692.0, 325.9, 692.0, 327.9, 692.0, 329.9, 695.5, 332.8, 699.1, 335.7, 698.4, 337.3, 697.8, 339.0, 692.0, 342.9, 686.3, 346.8, 682.6, 342.2, 679.0, 337.5, 674.0, 331.5, 669.1, 325.5, 669.0, 324.4, 669.0, 323.2, 661.9, 315.6, 654.8, 308.0, 655.5, 303.8, 656.2, 299.5, 664.9, 291.2, 673.5, 282.9, 682.7, 278.4, 691.9, 274.0, 697.2, 271.9, 702.5, 269.9, 709.8, 265.9, 717.1, 262.0, 719.0, 263.0, 720.9, 264.0, 723.1, 267.2, 725.3, 270.5, 729.9, 275.0, 734.5, 279.6, 744.5, 285.1, 754.5, 290.6, 765.0, 295.7, 775.5, 300.9, 783.0, 304.0, 790.5, 307.2, 800.5, 311.2, 810.5, 315.2, 839.0, 316.0, 867.5, 316.8, 897.2, 316.9, 926.8, 317.0, 942.7, 319.5, 958.5, 322.0, 959.8, 322.0, 961.0, 322.0, 961.0, 323.2, 961.0, 324.5, 954.8, 329.5, 948.5, 334.5, 944.0, 338.8, 939.5, 343.2, 932.5, 348.6, 925.5, 354.0, 916.9, 358.5, 908.4, 362.9, 899.6, 365.4, 890.8, 368.0, 881.1, 368.9, 871.5, 369.8, 860.6, 368.8, 849.8, 367.9, 838.5, 365.0, 827.2, 362.1, 816.8, 358.0, 806.5, 353.9, 792.5, 346.6, 778.5, 339.3, 756.5, 323.1, 734.6, 306.9, 727.3, 302.3, 720.0, 297.8, 718.5, 298.4, 717.0, 298.9, 717.0, 300.5, 717.0, 302.0, 721.3, 306.3, 725.5, 310.6, 732.0, 314.5, 738.5, 318.4, 746.0, 324.0, 753.5, 329.7, 762.5, 335.7, 771.5, 341.7, 782.5, 348.0, 793.5, 354.4, 804.0, 359.1, 814.6, 363.8, 825.3, 367.4, 836.0, 371.0, 849.6, 373.5, 863.1, 376.0, 871.5, 376.0, 879.8, 376.0, 890.0, 374.0, 900.2, 371.9, 908.2, 369.0, 916.2, 366.1, 922.6, 362.5, 929.0, 358.9, 936.4, 353.0, 943.9, 347.1, 961.3, 334.2, 978.7, 321.2, 979.3, 319.5, 980.0, 317.8, 980.0, 316.7, 980.0, 315.5, 977.3, 314.3, 974.5, 313.1, 897.5, 312.0, 820.5, 310.9, 806.5, 306.5, 792.5, 302.1, 776.5, 293.9, 760.5, 285.8, 753.5, 282.2, 746.5, 278.7, 739.9, 273.8, 733.3, 269.0, 701.3, 235.2, 669.3, 201.5, 613.1, 142.5, 556.9, 83.5, 548.2, 82.9, 539.5, 82.2, 396.3, 82.1, 253.0, 82.0, 253.0, 87.5, 253.0, 93.0, 365.2, 92.8, 477.5, 92.5, 499.5, 90.6, 521.5, 88.7, 537.1, 89.4, 552.7, 90.2, 623.5, 164.1, 694.3, 238.0, 702.1, 245.0, 709.0, 252.9, 710.0, 253.5, 711.0, 254.1, 711.0, 256.5, 711.0, 258.8, 706.7, 261.4, 702.3, 263.9, 695.9, 266.3, 689.5, 268.7, 681.5, 272.8, 673.4, 276.8, 668.5, 280.8, 663.5, 284.8, 657.5, 290.6, 651.5, 296.5, 650.2, 301.8, 649.0, 307.2, 649.0, 309.0, 649.0, 310.9, 654.0, 315.1, 659.0, 319.3, 659.0, 320.7, 659.0, 322.1, 660.5, 322.6, 661.9, 323.2, 664.5, 327.6, 667.1, 332.0, 672.8, 338.4, 678.5, 344.9, 680.2, 348.2, 681.8, 351.5, 682.4, 353.2, 682.9, 355.0, 684.9, 355.0, 686.9, 355.0, 687.9, 353.1, 689.0, 351.2, 693.2, 348.7, 697.5, 346.2, 701.2, 342.6, 704.8, 339.1, 715.9, 346.8, 727.1, 354.5, 733.3, 358.4, 739.5, 362.4, 749.5, 368.5, 759.5, 374.7, 772.0, 381.3, 784.5, 387.9, 796.5, 393.1, 808.5, 398.2, 821.5, 402.5, 834.5, 406.8, 844.0, 408.9, 853.5, 410.9, 864.6, 412.0, 875.7, 413.1, 885.6, 412.1, 895.5, 411.0, 901.5, 409.5, 907.5, 408.0, 916.5, 403.5, 925.5, 399.0, 952.1, 378.7, 978.6, 358.5, 995.6, 345.3, 1012.5, 332.1, 1025.4, 321.6, 1038.3, 311.0, 1050.5, 300.3, 1062.7, 289.5, 1065.1, 287.4, 1067.5, 285.2, 1072.4, 280.0, 1077.2, 274.7, 1082.9, 265.8, 1088.5, 256.9, 1090.7, 252.7, 1092.9, 248.5, 1095.6, 240.1, 1098.3, 231.8, 1097.7, 201.1, 1097.0, 170.5, 1095.5, 164.7, 1093.9, 159.0, 1086.4, 143.7, 1079.0, 128.5, 1072.6, 120.0, 1066.2, 111.5, 1056.4, 102.0, 1046.5, 92.4, 1037.1, 86.2, 1027.7, 79.9, 1018.6, 75.5, 1009.5, 71.2, 1000.6, 68.1, 991.7, 65.0, 979.6, 62.5, 967.5, 60.1, 956.5, 59.6, 945.5, 59.0, 888.3, 58.4, 831.0, 57.9, 831.0, 61.9};
        vector<float> m_rightOuterRail = {1063.5, 595.1, 1057.7, 603.1, 1047.0, 613.4, 1036.3, 623.7, 1024.9, 631.3, 1013.5, 638.9, 1002.9, 643.9, 992.4, 649.0, 980.4, 652.9, 968.5, 656.8, 957.5, 658.9, 946.5, 661.0, 937.5, 662.0, 928.5, 663.0, 667.8, 663.0, 407.2, 663.0, 372.8, 639.2, 338.5, 615.5, 309.9, 615.2, 281.3, 614.9, 280.6, 617.2, 280.0, 619.5, 280.0, 621.2, 280.0, 623.0, 307.5, 623.0, 335.1, 623.0, 369.8, 647.0, 404.5, 671.0, 667.0, 671.0, 929.5, 671.0, 938.5, 670.0, 947.5, 669.0, 958.5, 666.9, 969.5, 664.8, 983.0, 660.4, 996.5, 656.0, 1007.5, 650.6, 1018.5, 645.2, 1027.5, 639.3, 1036.5, 633.3, 1043.0, 628.0, 1049.5, 622.6, 1056.9, 615.1, 1064.2, 607.5, 1070.1, 599.7, 1076.0, 591.9, 1072.7, 588.8, 1069.4, 587.2, 1063.5, 595.1};
        vector<float> m_rightInnerRail = {660.8, 433.7, 655.4, 437.5, 627.7, 457.4, 600.0, 477.3, 599.5, 479.1, 598.9, 480.9, 600.0, 482.9, 601.0, 484.9, 633.1, 529.2, 665.2, 573.5, 666.8, 574.7, 668.4, 576.0, 669.7, 576.0, 671.0, 576.0, 681.8, 568.6, 692.7, 561.2, 695.5, 559.7, 698.4, 558.2, 720.7, 579.9, 742.9, 601.5, 745.5, 602.4, 748.0, 603.4, 748.0, 608.4, 748.0, 613.5, 744.9, 618.8, 741.9, 624.1, 739.4, 625.0, 736.9, 626.0, 574.2, 626.0, 411.5, 626.0, 378.0, 602.8, 344.5, 579.6, 336.5, 578.9, 328.5, 578.2, 287.8, 578.1, 247.0, 578.0, 247.0, 581.9, 247.0, 585.8, 293.8, 586.2, 340.5, 586.5, 374.8, 610.3, 409.1, 634.0, 574.5, 634.0, 739.9, 634.0, 743.7, 631.9, 747.5, 629.8, 748.8, 628.7, 750.2, 627.6, 752.6, 622.8, 755.0, 618.1, 755.0, 611.9, 755.0, 605.7, 752.8, 599.8, 750.7, 593.9, 730.1, 574.1, 709.5, 554.3, 704.2, 549.6, 698.9, 545.0, 696.7, 545.0, 694.5, 545.0, 682.5, 554.9, 670.5, 564.8, 669.9, 564.1, 669.2, 563.5, 640.1, 523.2, 611.0, 483.0, 610.7, 482.1, 610.5, 481.2, 638.5, 461.0, 666.5, 440.8, 667.6, 440.4, 668.6, 439.9, 713.5, 462.0, 758.4, 484.1, 752.5, 498.0, 745.9, 511.1, 738.9, 504.8, 731.8, 498.5, 726.8, 494.2, 721.8, 490.0, 720.0, 490.0, 718.1, 490.0, 716.6, 491.6, 715.0, 493.1, 715.0, 494.9, 715.0, 496.7, 740.8, 519.5, 766.5, 542.4, 795.1, 570.4, 823.7, 598.5, 829.6, 603.1, 835.5, 607.7, 841.6, 611.8, 847.6, 615.9, 856.1, 620.4, 864.5, 624.9, 875.5, 628.7, 886.5, 632.5, 909.9, 632.8, 933.4, 633.1, 939.9, 632.0, 946.5, 630.9, 956.6, 627.5, 966.8, 624.1, 976.1, 619.4, 985.5, 614.7, 995.9, 607.7, 1006.3, 600.6, 1017.8, 589.6, 1029.3, 578.5, 1034.2, 572.6, 1039.1, 566.8, 1035.8, 564.5, 1032.5, 562.2, 1029.6, 565.9, 1026.7, 569.5, 1015.6, 580.6, 1004.5, 591.6, 997.0, 597.2, 989.4, 602.8, 983.0, 606.9, 976.5, 611.0, 972.5, 612.9, 968.5, 614.9, 958.5, 618.6, 948.5, 622.3, 942.3, 624.6, 936.1, 626.9, 935.5, 626.0, 934.9, 625.0, 913.1, 625.0, 891.2, 625.0, 882.4, 622.4, 873.5, 619.9, 864.1, 615.4, 854.7, 611.0, 846.4, 605.5, 838.2, 600.0, 827.3, 589.3, 816.4, 578.5, 813.0, 574.5, 809.5, 570.5, 803.8, 566.5, 798.2, 562.6, 797.7, 560.0, 797.1, 557.5, 775.1, 537.6, 753.0, 517.7, 761.5, 499.9, 770.1, 482.8, 769.5, 481.1, 769.0, 479.3, 718.7, 454.6, 668.5, 429.9, 667.4, 430.0, 666.3, 430.0, 660.8, 433.7};
        vector<vector<float>> m_layer2ShapeData = {
            m_leftInnerRail, m_leftOuterRail, m_rightOuterRail, m_rightInnerRail
        };

        // All the layers
        vector<vector<vector<float>>> m_layerData = {m_launchTubeLayer, m_layer1ShapeData, m_layer2ShapeData};
};
#endif