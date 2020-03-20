#ifndef LAYER_H_
#define LAYER_H_

#include <list>
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

        // Underlayer
        vector<float> m_underOuter = {693.0, 6.9, 691.5, 7.8, 682.4, 11.0, 673.2, 14.2, 665.9, 17.9, 658.5, 21.7, 649.9, 26.2, 641.2, 30.7, 636.4, 34.1, 631.5, 37.4, 626.0, 42.0, 620.5, 46.6, 615.8, 49.6, 611.1, 52.5, 607.6, 60.0, 604.1, 67.5, 603.4, 72.0, 602.8, 76.5, 590.8, 110.5, 578.8, 144.5, 577.4, 146.7, 576.0, 148.9, 576.0, 150.4, 576.0, 151.8, 574.5, 154.6, 573.0, 157.5, 442.8, 158.0, 312.5, 158.5, 312.5, 178.5, 312.5, 198.5, 350.1, 199.0, 387.8, 199.5, 374.4, 221.0, 361.1, 242.5, 280.8, 243.0, 200.5, 243.5, 200.5, 263.5, 200.5, 283.5, 221.1, 283.8, 241.7, 284.0, 243.9, 289.9, 246.0, 295.7, 246.0, 296.8, 246.0, 297.8, 259.1, 329.1, 272.2, 360.4, 274.2, 366.9, 276.2, 373.5, 285.7, 395.0, 295.1, 416.5, 296.6, 418.7, 298.0, 421.0, 334.9, 421.0, 371.8, 421.0, 379.4, 433.2, 387.0, 445.5, 388.6, 447.7, 390.3, 450.0, 421.1, 450.0, 452.0, 450.0, 452.0, 464.5, 452.0, 479.0, 418.8, 479.2, 385.5, 479.5, 385.5, 499.0, 385.5, 518.5, 460.1, 518.8, 534.7, 519.0, 537.2, 517.0, 539.7, 515.1, 549.4, 499.6, 559.1, 484.1, 597.4, 483.8, 635.8, 483.5, 637.9, 481.0, 640.0, 478.5, 656.7, 452.0, 673.4, 425.5, 678.5, 418.0, 683.7, 410.5, 690.8, 398.9, 698.0, 387.4, 698.0, 318.9, 698.0, 250.5, 668.6, 203.8, 639.3, 157.1, 639.8, 151.8, 640.2, 146.5, 642.1, 138.2, 644.0, 129.9, 644.0, 127.2, 644.0, 124.4, 645.6, 118.5, 647.2, 112.5, 648.1, 105.5, 649.0, 98.5, 652.1, 87.7, 655.3, 76.9, 661.3, 72.4, 667.3, 67.8, 678.9, 61.7, 690.5, 55.7, 696.5, 54.3, 702.5, 53.0, 707.5, 51.8, 712.5, 50.6, 931.4, 50.1, 1150.3, 49.5, 1151.3, 47.8, 1152.4, 46.2, 1151.1, 44.6, 1149.8, 43.0, 923.1, 43.0, 696.3, 43.0, 676.3, 52.9, 656.3, 62.8, 652.5, 67.4, 648.7, 72.1, 645.8, 80.8, 643.0, 89.5, 641.0, 99.5, 639.0, 109.5, 634.4, 133.3, 629.8, 157.0, 637.1, 168.8, 644.4, 180.5, 667.7, 217.5, 691.0, 254.5, 691.0, 319.0, 691.0, 383.5, 683.6, 395.0, 676.2, 406.5, 654.6, 440.5, 633.1, 474.6, 630.7, 476.8, 628.4, 479.0, 590.4, 479.0, 552.3, 479.0, 546.2, 489.3, 540.1, 499.5, 535.8, 506.0, 531.5, 512.5, 460.8, 512.8, 390.0, 513.0, 390.0, 498.5, 390.0, 484.0, 448.3, 483.8, 506.5, 483.5, 506.5, 481.0, 506.5, 478.5, 481.8, 478.2, 457.0, 478.0, 457.0, 464.0, 457.0, 450.0, 532.6, 449.8, 608.3, 449.5, 609.3, 447.8, 610.4, 446.2, 609.1, 444.6, 607.8, 443.0, 520.8, 443.0, 433.8, 443.0, 419.1, 441.9, 404.5, 440.8, 398.9, 437.8, 393.3, 434.9, 387.8, 429.2, 382.3, 423.5, 376.7, 414.3, 371.1, 405.2, 369.6, 401.5, 368.0, 397.8, 366.3, 398.2, 364.5, 398.5, 364.0, 406.0, 363.5, 413.5, 333.4, 413.8, 303.4, 414.0, 280.3, 358.8, 257.2, 303.5, 253.5, 293.0, 249.7, 282.5, 248.3, 279.7, 246.9, 277.0, 227.0, 277.0, 207.0, 277.0, 207.0, 263.5, 207.0, 250.0, 286.4, 250.0, 365.9, 250.0, 382.5, 223.3, 399.1, 196.6, 398.8, 194.6, 398.5, 192.5, 358.8, 192.2, 319.0, 192.0, 319.0, 178.5, 319.0, 165.0, 404.8, 165.0, 490.6, 165.0, 523.5, 189.5, 556.4, 214.0, 558.8, 214.0, 561.1, 214.0, 562.4, 210.7, 563.8, 207.5, 572.5, 183.0, 581.2, 158.5, 584.0, 152.0, 586.8, 145.5, 597.4, 115.8, 608.0, 86.1, 611.5, 76.8, 615.1, 67.5, 617.2, 63.5, 619.3, 59.5, 623.9, 54.7, 628.5, 50.0, 659.0, 34.1, 689.5, 18.2, 694.0, 15.9, 698.5, 13.5, 923.4, 13.0, 1148.3, 12.5, 1149.3, 10.8, 1150.4, 9.2, 1149.1, 7.6, 1147.8, 6.0, 921.1, 6.0, 694.5, 6.1, 693.0, 6.9};
        vector<float> m_under1 = {440.0, 378.2, 439.0, 380.5, 434.4, 396.2, 429.9, 411.9, 430.2, 414.2, 430.5, 416.5, 491.5, 416.5, 552.5, 416.5, 552.8, 413.8, 553.1, 411.1, 551.3, 410.2, 549.5, 409.3, 497.9, 392.6, 446.4, 376.0, 443.7, 376.0, 441.0, 376.0, 440.0, 378.2};
        vector<float> m_under2 = {632.1, 155.4, 630.9, 156.9, 621.8, 219.7, 612.8, 282.5, 613.8, 284.0, 614.7, 285.5, 616.3, 285.8, 617.8, 286.1, 647.7, 249.3, 677.6, 212.5, 679.9, 209.2, 682.2, 206.0, 681.8, 205.0, 681.5, 203.9, 658.6, 179.0, 635.8, 154.0, 634.5, 154.0, 633.2, 154.0, 632.1, 155.4};
        vector<vector<float>> m_underLayer = {
            m_underOuter, m_under1/*, m_under2*/
        };

        // Launch tube layer
        vector<float> m_tubeLeft = {0.0, 540.8, 0.0, 675.0, 210.3, 675.0, 420.7, 675.0, 423.0, 672.5, 425.3, 670.0, 418.5, 655.4, 411.6, 640.8, 397.1, 630.4, 382.5, 620.1, 377.5, 620.0, 372.5, 620.0, 355.5, 637.0, 338.5, 654.0, 174.3, 654.0, 10.0, 654.0, 10.0, 641.0, 10.0, 628.0, 42.3, 628.0, 74.7, 628.0, 76.5, 626.0, 78.3, 624.1, 39.5, 515.8, 0.8, 407.5, 3.97459842816e-14, 540.8};
        vector<float> m_tubeLeftUpper = {988.0, 542.3, 977.5, 552.6, 942.0, 584.0, 906.5, 615.4, 897.0, 621.4, 887.5, 627.4, 873.5, 634.6, 859.5, 641.8, 850.5, 645.6, 841.5, 649.3, 830.0, 653.2, 818.5, 657.1, 803.5, 659.1, 788.5, 661.0, 696.5, 661.0, 604.5, 661.0, 588.7, 658.5, 573.0, 656.1, 561.2, 653.4, 549.5, 650.8, 538.2, 647.4, 526.9, 643.9, 519.0, 640.0, 511.1, 636.0, 498.8, 628.0, 486.5, 620.0, 461.3, 620.0, 436.1, 620.0, 435.5, 621.9, 434.9, 623.8, 436.2, 626.6, 437.4, 629.5, 444.0, 641.5, 450.6, 653.5, 454.1, 660.4, 457.5, 667.2, 460.8, 671.1, 464.2, 675.0, 705.3, 674.7, 946.5, 674.5, 958.6, 671.8, 970.6, 669.1, 980.6, 665.6, 990.5, 662.1, 997.5, 659.0, 1004.5, 655.9, 1013.3, 650.8, 1022.1, 645.8, 1030.3, 639.7, 1038.5, 633.6, 1048.9, 623.6, 1059.2, 613.5, 1065.2, 606.2, 1071.2, 598.9, 1067.9, 595.4, 1064.6, 592.0, 1058.3, 598.7, 1053.2, 605.5, 1038.8, 619.5, 1024.5, 633.5, 1013.2, 639.9, 1001.8, 646.3, 992.5, 650.1, 983.1, 653.9, 972.3, 656.9, 961.5, 659.9, 951.2, 660.9, 940.9, 662.0, 928.0, 662.0, 915.0, 662.0, 915.0, 646.0, 915.0, 630.0, 920.3, 630.0, 925.6, 630.0, 935.1, 628.4, 944.5, 626.8, 954.0, 623.8, 963.5, 620.8, 973.7, 616.0, 983.9, 611.2, 992.7, 605.4, 1001.5, 599.7, 1007.5, 595.2, 1013.5, 590.6, 1025.3, 579.1, 1037.0, 567.7, 1037.0, 566.5, 1037.0, 565.4, 1019.6, 548.7, 1002.2, 532.0, 1000.3, 532.0, 998.5, 532.0, 988.0, 542.3};
        vector<float> m_tubeRight = {0, 132.7, 0, 265.3, 39.5, 156.2, 78.3, 47.9, 76.5, 46.0, 74.7, 44.0, 42.3, 44.0, 10.0, 44.0, 10.0, 31.0, 10.0, 18.0, 173.5, 18.0, 337.0, 18.0, 366.0, 47.0, 395.0, 76.0, 401.0, 76.0, 407.0, 76.0, 414.7, 70.4, 422.5, 64.8, 430.6, 59.9, 438.7, 55.0, 453.1, 48.1, 467.5, 41.1, 479.5, 36.7, 491.5, 32.3, 505.0, 28.7, 518.5, 25.1, 528.5, 23.1, 538.5, 21.1, 551.5, 19.6, 564.5, 18.0, 584.2, 17.0, 603.8, 16.0, 614.4, 16.0, 625.0, 16.0, 625.0, 31.3, 625.0, 46.6, 617.3, 48.4, 609.5, 50.2, 603.8, 52.5, 598.2, 54.8, 593.5, 58.0, 588.9, 61.2, 589.2, 62.8, 589.5, 64.3, 592.5, 65.3, 595.5, 66.2, 598.6, 69.2, 601.7, 72.1, 602.8, 75.8, 603.8, 79.5, 604.5, 84.7, 605.2, 90.0, 606.8, 90.0, 608.3, 90.0, 614.9, 87.1, 621.5, 84.1, 632.0, 79.7, 642.5, 75.2, 669.5, 63.5, 696.5, 51.8, 703.0, 49.0, 709.5, 46.2, 709.5, 44.8, 709.5, 43.5, 680.3, 43.2, 651.0, 43.0, 651.0, 28.5, 651.0, 14.0, 872.3, 14.0, 1093.6, 14.0, 1094.8, 15.2, 1096.0, 16.4, 1096.0, 28.0, 1096.0, 39.6, 1094.8, 40.8, 1093.6, 42.0, 1077.4, 42.0, 1061.1, 42.0, 1060.4, 43.2, 1059.6, 44.4, 1060.7, 44.7, 1061.8, 45.1, 1070.7, 50.9, 1079.5, 56.8, 1087.6, 63.8, 1095.7, 70.8, 1102.2, 78.7, 1108.7, 86.5, 1113.5, 93.8, 1118.2, 101.2, 1121.5, 108.3, 1124.8, 115.5, 1127.3, 124.5, 1129.9, 133.5, 1132.7, 146.0, 1135.5, 158.5, 1135.8, 339.0, 1136.1, 519.5, 1135.0, 530.5, 1133.9, 541.5, 1131.5, 552.5, 1129.2, 563.5, 1126.0, 573.0, 1122.9, 582.5, 1117.0, 594.8, 1111.1, 607.1, 1105.4, 615.8, 1099.8, 624.5, 1094.2, 631.5, 1088.6, 638.5, 1082.5, 644.9, 1076.5, 651.3, 1067.5, 658.8, 1058.5, 666.4, 1048.9, 672.7, 1039.2, 679.0, 1026.9, 684.9, 1014.5, 690.9, 1005.0, 694.0, 995.5, 697.2, 984.5, 699.8, 973.5, 702.4, 486.8, 702.7, 0, 703.0, 0, 711.5, 0, 720.0, 576.0, 720.0, 1152.0, 720.0, 1152.0, 360.0, 1152.0, 0, 576.0, 0, 0, 0, 0, 132.7};
        vector<float> m_tubeRightLaunch = {1136.0, 402.7, 1136.0, 522.5, 1135.0, 531.5, 1134.0, 540.5, 1131.9, 550.9, 1129.8, 561.3, 1126.3, 571.9, 1122.9, 582.5, 1116.9, 594.9, 1111.0, 607.2, 1104.7, 616.9, 1098.4, 626.5, 1090.8, 635.5, 1083.3, 644.5, 1076.9, 650.5, 1070.5, 656.6, 1063.5, 662.2, 1056.5, 667.8, 1047.8, 673.4, 1039.1, 679.1, 1026.8, 685.0, 1014.5, 690.9, 1005.0, 694.0, 995.5, 697.2, 984.5, 699.8, 973.5, 702.4, 486.7, 702.7, 0.0, 703.0, 0.0, 711.5, 0.0, 720.0, 576.0, 720.0, 1152.0, 720.0, 1152.0, 501.5, 1152.0, 283.0, 1144.0, 283.0, 1136.0, 283.0, 1136.0, 402.7};
        vector<vector<float>> m_launchTubeLayer = {
            m_tubeLeft, m_tubeRightLaunch, m_tubeLeftUpper
        };

        // Main table layer
        vector<float> m_upperWall = {859.0, 44.1, 854.5, 45.0, 849.1, 46.1, 843.8, 47.2, 822.1, 58.0, 800.5, 68.8, 766.0, 87.8, 731.5, 106.8, 731.2, 108.5, 730.8, 110.1, 732.0, 111.5, 733.2, 113.0, 734.8, 113.0, 736.4, 113.0, 789.3, 84.9, 842.1, 56.7, 848.8, 54.3, 855.4, 51.9, 910.0, 52.3, 964.5, 52.7, 971.4, 54.4, 978.4, 56.0, 992.9, 60.6, 1007.5, 65.2, 1017.5, 70.3, 1027.5, 75.3, 1034.8, 80.3, 1042.0, 85.4, 1034.4, 95.9, 1026.9, 104.9, 968.7, 105.2, 910.5, 105.5, 906.5, 107.7, 902.5, 109.8, 837.0, 150.0, 771.5, 190.1, 768.3, 193.3, 765.0, 196.4, 765.0, 200.0, 765.0, 203.7, 767.1, 205.6, 769.2, 207.5, 782.8, 207.5, 796.3, 207.5, 808.6, 188.6, 820.9, 169.7, 822.7, 167.9, 824.5, 166.1, 845.4, 153.0, 866.4, 140.0, 867.4, 140.0, 868.5, 140.0, 894.0, 154.0, 919.5, 168.0, 921.8, 168.6, 924.0, 169.2, 926.1, 167.9, 928.1, 166.5, 944.9, 139.5, 961.6, 112.5, 995.8, 112.2, 1029.9, 112.0, 1036.8, 103.7, 1043.6, 95.5, 1046.9, 91.3, 1050.3, 87.1, 1049.0, 84.0, 1047.7, 80.9, 1040.6, 74.4, 1033.5, 67.8, 1021.5, 62.0, 1009.5, 56.1, 999.1, 52.5, 988.6, 48.9, 976.6, 46.3, 964.5, 43.7, 914.0, 43.4, 863.5, 43.1, 859.0, 44.1};
        vector<float> m_upperWall2 = {712.3, 463.6, 699.5, 477.2, 699.2, 478.7, 698.8, 480.3, 707.2, 488.4, 715.5, 496.5, 739.4, 519.0, 763.4, 541.5, 773.9, 551.3, 784.5, 561.2, 790.5, 565.8, 796.5, 570.4, 803.7, 577.0, 811.0, 583.5, 811.0, 588.7, 811.0, 593.8, 807.8, 596.5, 804.5, 599.1, 799.0, 603.3, 793.5, 607.4, 782.7, 610.7, 771.9, 614.0, 767.7, 614.0, 763.4, 614.0, 758.3, 612.7, 753.2, 611.4, 724.2, 594.1, 695.1, 576.8, 692.8, 577.2, 690.5, 577.5, 690.2, 579.3, 689.8, 581.1, 694.7, 597.8, 699.5, 614.5, 704.0, 619.0, 708.5, 623.6, 716.7, 626.8, 724.9, 630.1, 732.2, 631.8, 739.5, 633.5, 759.5, 633.5, 779.5, 633.5, 787.0, 632.1, 794.5, 630.7, 803.5, 628.8, 812.5, 626.9, 824.1, 623.0, 835.7, 619.2, 846.6, 613.7, 857.6, 608.2, 866.5, 602.1, 875.5, 596.1, 882.2, 590.3, 888.9, 584.5, 912.2, 562.3, 935.5, 540.2, 972.4, 503.2, 1009.3, 466.2, 1008.7, 464.6, 1008.1, 463.0, 993.8, 463.0, 979.5, 463.0, 924.5, 518.0, 869.5, 573.0, 864.7, 574.6, 860.0, 576.2, 839.2, 575.8, 818.5, 575.5, 814.5, 573.3, 810.5, 571.2, 773.5, 537.5, 736.5, 503.8, 735.3, 502.7, 734.1, 501.5, 742.8, 492.2, 751.5, 483.0, 776.5, 506.6, 801.5, 530.2, 812.2, 540.1, 822.9, 550.0, 832.7, 550.0, 842.5, 550.0, 868.9, 523.6, 895.4, 497.1, 894.1, 495.6, 892.8, 494.0, 857.5, 494.0, 822.2, 494.0, 811.9, 505.5, 801.6, 517.0, 800.6, 517.0, 789.1, 506.6, 778.5, 496.2, 753.5, 473.1, 728.6, 450.0, 726.9, 450.0, 725.2, 450.0, 712.3, 463.6};
        vector<float> m_upperWall3 = {1038.0, 237.2, 1034.5, 238.2, 1033.3, 239.2, 1032.0, 240.2, 1032.0, 241.9, 1032.1, 243.5, 1047.8, 275.0, 1063.5, 306.5, 1065.0, 306.8, 1066.6, 307.1, 1078.5, 298.6, 1090.5, 290.1, 1093.8, 287.8, 1097.1, 285.5, 1098.6, 284.1, 1100.1, 282.8, 1099.8, 281.2, 1099.5, 279.6, 1072.0, 257.8, 1044.5, 236.0, 1043.0, 236.1, 1041.5, 236.2, 1038.0, 237.2};
        vector<float> m_upperWall4 = {723.0, 235.5, 721.8, 237.0, 722.5, 239.7, 723.2, 242.5, 735.1, 285.0, 747.1, 327.5, 748.1, 330.2, 749.2, 332.9, 763.2, 346.1, 777.1, 359.3, 778.5, 362.1, 780.0, 364.9, 780.0, 368.7, 780.0, 372.5, 778.1, 375.6, 776.2, 378.7, 773.0, 380.0, 769.7, 381.4, 735.4, 377.6, 701.0, 373.8, 699.4, 374.4, 697.9, 375.0, 698.2, 376.5, 698.5, 378.1, 745.5, 423.0, 792.5, 468.0, 860.0, 468.0, 927.5, 468.0, 983.5, 412.0, 1039.5, 356.0, 1038.4, 354.3, 1037.3, 352.5, 1021.9, 352.2, 1006.5, 352.0, 991.5, 367.0, 976.5, 382.0, 921.5, 382.0, 866.5, 382.0, 851.5, 397.0, 836.5, 412.1, 814.3, 411.8, 792.0, 411.5, 788.8, 408.2, 785.5, 405.0, 785.5, 399.0, 785.5, 393.0, 788.8, 389.8, 792.0, 386.5, 806.7, 386.0, 821.4, 385.5, 824.1, 381.5, 826.8, 377.5, 855.1, 336.0, 883.4, 294.5, 883.4, 292.6, 883.5, 290.8, 881.9, 289.8, 880.4, 288.7, 846.9, 299.0, 813.5, 309.3, 789.5, 304.5, 765.5, 299.7, 759.0, 297.4, 752.5, 295.1, 749.9, 292.2, 747.2, 289.2, 739.0, 264.4, 730.7, 239.5, 729.3, 236.7, 727.9, 234.0, 726.1, 234.0, 724.2, 234.0, 723.0, 235.5};
        vector<float> m_upperWall5 = {772.9, 268.6, 771.6, 270.2, 772.7, 271.8, 773.7, 273.5, 783.0, 273.5, 792.3, 273.5, 793.3, 271.8, 794.4, 270.2, 793.1, 268.6, 791.8, 267.0, 783.0, 267.0, 774.2, 267.0, 772.9, 268.6};
        vector<float> m_upperWall6 = {770.9, 235.6, 769.6, 237.2, 770.7, 238.8, 771.7, 240.5, 780.5, 240.5, 789.3, 240.5, 790.3, 238.8, 791.4, 237.2, 790.1, 235.6, 788.8, 234.0, 780.5, 234.0, 772.2, 234.0, 770.9, 235.6};
        vector<float> m_upperWall7 = {564.1, 560.8, 517.6, 579.5, 516.6, 581.2, 515.6, 582.8, 516.9, 584.4, 518.2, 586.0, 572.9, 586.0, 627.6, 586.0, 628.8, 584.8, 630.0, 583.6, 630.0, 582.0, 630.0, 580.4, 623.4, 563.5, 616.9, 546.5, 615.4, 544.2, 614.0, 542.0, 612.2, 542.1, 610.5, 542.2, 564.1, 560.8};
        vector<float> m_leftSlide = {109.5, 47.4, 106.3, 50.9, 102.7, 60.2, 99.1, 69.5, 74.1, 134.9, 49.1, 200.3, 49.6, 201.2, 50.1, 202.0, 55.4, 202.0, 60.7, 202.0, 63.9, 200.9, 67.1, 199.8, 71.8, 201.0, 76.5, 202.1, 82.2, 207.7, 87.8, 213.2, 88.8, 212.6, 89.8, 212.0, 93.8, 202.3, 97.9, 192.5, 101.5, 183.0, 105.0, 173.5, 107.5, 167.0, 110.0, 160.5, 113.5, 151.0, 117.0, 141.5, 119.5, 135.0, 122.0, 128.5, 125.5, 119.3, 129.0, 110.0, 131.1, 103.3, 133.2, 96.5, 137.2, 84.5, 141.3, 72.5, 144.0, 66.4, 146.7, 60.3, 149.1, 58.1, 151.5, 55.8, 155.0, 54.1, 158.5, 52.5, 218.4, 52.0, 278.3, 51.5, 279.3, 49.8, 280.4, 48.1, 278.6, 46.1, 276.7, 44.0, 194.7, 44.0, 112.7, 44.0, 109.5, 47.4};
        vector<float> m_rightSlide = {82.1, 464.4, 76.7, 469.9, 72.0, 471.0, 67.2, 472.1, 63.4, 471.0, 59.5, 469.8, 56.0, 470.2, 52.5, 470.5, 52.2, 474.8, 51.9, 479.0, 78.5, 548.8, 105.2, 618.5, 107.2, 621.8, 109.2, 625.0, 111.3, 626.5, 113.4, 628.0, 195.1, 628.0, 276.7, 628.0, 278.6, 625.9, 280.4, 623.9, 279.3, 622.2, 278.3, 620.5, 218.4, 620.0, 158.5, 619.5, 155.0, 617.9, 151.5, 616.2, 149.1, 613.9, 146.7, 611.7, 144.0, 605.6, 141.2, 599.5, 136.6, 585.5, 132.0, 571.5, 129.0, 563.0, 126.1, 554.5, 122.5, 545.0, 118.9, 535.5, 116.5, 529.0, 114.1, 522.5, 110.5, 513.0, 106.9, 503.5, 104.5, 497.0, 102.1, 490.5, 99.7, 484.0, 97.2, 477.5, 93.3, 468.6, 89.5, 459.7, 88.5, 459.3, 87.4, 459.0, 82.1, 464.4};
        vector<float> m_leftSlideLine = {166.2, 79.2, 165.0, 80.4, 165.0, 82.1, 165.0, 83.8, 166.4, 84.9, 167.7, 86.0, 219.5, 85.8, 271.3, 85.5, 272.4, 83.7, 273.5, 82.0, 272.4, 80.2, 271.3, 78.5, 219.3, 78.2, 167.4, 78.0, 166.2, 79.2};
        vector<float> m_rightSlideLine = {166.2, 587.2, 165.0, 588.4, 165.0, 590.1, 165.0, 591.8, 166.4, 592.9, 167.7, 594.0, 219.5, 593.8, 271.3, 593.5, 272.4, 591.7, 273.5, 590.0, 272.4, 588.2, 271.3, 586.5, 219.3, 586.2, 167.4, 586.0, 166.2, 587.2};
        vector<float> m_leftBumper = {160.4, 113.9, 157.4, 115.7, 143.7, 147.1, 130.0, 178.5, 130.0, 181.6, 130.0, 184.7, 132.3, 186.8, 134.6, 189.0, 137.6, 189.0, 140.7, 189.0, 142.9, 186.6, 145.2, 184.2, 144.8, 180.5, 144.5, 176.7, 160.0, 168.8, 175.5, 160.9, 183.1, 156.5, 190.8, 152.1, 196.4, 149.6, 202.1, 147.1, 224.3, 135.0, 246.6, 123.0, 251.6, 125.5, 254.9, 128.0, 257.8, 128.0, 260.7, 128.0, 262.8, 125.7, 265.0, 123.4, 265.0, 120.3, 265.0, 117.2, 261.9, 114.6, 258.8, 112.0, 211.2, 112.0, 163.5, 112.0, 160.4, 113.9};
        vector<float> m_rightBumper = {132.2, 485.3, 130.0, 487.6, 130.0, 490.6, 130.0, 493.5, 143.7, 524.9, 157.4, 556.3, 160.4, 558.1, 163.5, 560.0, 211.2, 560.0, 258.8, 560.0, 261.9, 557.4, 265.0, 554.8, 265.0, 551.6, 265.0, 548.3, 262.7, 546.2, 260.4, 544.0, 257.6, 544.0, 254.9, 544.0, 251.6, 546.5, 248.3, 549.0, 224.3, 537.0, 202.1, 524.9, 196.4, 522.4, 190.8, 519.9, 183.1, 515.5, 175.5, 511.1, 160.0, 503.2, 144.5, 495.3, 144.8, 491.5, 145.2, 487.8, 142.9, 485.4, 140.7, 483.0, 137.5, 483.0, 134.3, 483.0, 132.2, 485.3};
        vector<float> m_backdoor = {415.7, 665.7, 415.0, 666.3, 415.0, 668.5, 415.0, 670.6, 418.1, 676.6, 421.3, 682.5, 426.8, 692.0, 432.4, 701.5, 435.4, 704.8, 438.4, 708.0, 464.0, 707.8, 489.5, 707.5, 489.5, 705.5, 489.5, 703.5, 478.5, 702.8, 467.5, 702.2, 461.5, 700.6, 455.5, 699.0, 448.4, 695.5, 441.4, 692.1, 436.9, 688.2, 432.5, 684.3, 428.5, 676.4, 424.6, 668.5, 422.5, 666.8, 420.5, 665.0, 418.4, 665.0, 416.3, 665.0, 415.7, 665.7};
        vector<vector<float>> m_layer1ShapeData = {
            m_tubeRight, m_tubeLeft, m_tubeLeftUpper, m_upperWall, m_upperWall2/*, m_upperWall3*/, m_upperWall4, m_upperWall5, m_upperWall6, m_upperWall7, m_leftSlide, m_rightSlide, m_rightSlideLine, m_leftSlideLine, m_leftBumper, m_rightBumper, m_backdoor
        };

        // Layer 3 shapes.
        vector<float> m_leftInnerRail = {271.1, 46.8, 270.2, 48.6, 271.1, 50.3, 272.1, 52.0, 448.3, 52.0, 624.5, 52.0, 741.2, 148.7, 857.8, 245.5, 872.6, 257.0, 887.3, 268.5, 898.4, 277.3, 909.5, 286.1, 951.5, 285.8, 993.5, 285.5, 998.8, 282.6, 1004.0, 279.7, 1016.3, 264.6, 1028.5, 249.6, 1035.8, 239.5, 1043.1, 229.5, 1049.5, 216.7, 1055.9, 203.9, 1058.1, 194.7, 1060.3, 185.5, 1060.4, 176.0, 1060.4, 166.5, 1059.1, 161.0, 1057.8, 155.5, 1053.4, 146.5, 1049.1, 137.5, 1042.6, 129.9, 1036.1, 122.3, 1030.3, 118.8, 1024.5, 115.2, 1017.5, 111.7, 1010.5, 108.2, 1003.5, 106.6, 996.5, 104.9, 953.5, 105.2, 910.5, 105.5, 906.5, 107.7, 902.5, 109.8, 852.5, 140.5, 802.5, 171.1, 800.5, 173.1, 798.5, 175.0, 799.6, 176.8, 800.7, 178.5, 803.6, 178.5, 806.5, 178.4, 856.3, 147.2, 906.1, 115.9, 912.3, 113.8, 918.5, 111.6, 949.0, 111.2, 979.5, 110.8, 988.9, 112.0, 998.2, 113.2, 1003.4, 114.7, 1008.5, 116.2, 1017.0, 120.4, 1025.5, 124.6, 1032.2, 129.4, 1038.9, 134.3, 1043.0, 140.1, 1047.1, 145.9, 1049.4, 151.2, 1051.7, 156.5, 1053.1, 162.0, 1054.4, 167.5, 1054.4, 176.5, 1054.3, 185.5, 1052.1, 194.0, 1049.9, 202.5, 1045.5, 211.7, 1041.2, 220.9, 1036.0, 228.7, 1030.7, 236.5, 1025.6, 243.0, 1020.5, 249.4, 1008.2, 262.5, 995.9, 275.5, 992.2, 277.7, 988.5, 280.0, 951.0, 280.0, 913.5, 280.0, 910.8, 278.2, 908.1, 276.5, 886.8, 259.8, 865.5, 243.0, 860.0, 238.5, 854.5, 234.0, 740.5, 139.5, 626.5, 45.0, 449.3, 45.0, 272.1, 45.0, 271.1, 46.8};
        vector<float> m_leftOuterRail = {859.0, 44.1, 854.5, 45.0, 849.1, 46.1, 843.8, 47.2, 822.1, 58.0, 800.5, 68.8, 766.0, 87.8, 731.5, 106.8, 731.2, 108.5, 730.8, 110.1, 732.0, 111.5, 733.2, 113.0, 734.8, 113.0, 736.4, 113.0, 789.3, 84.9, 842.1, 56.7, 848.8, 54.3, 855.4, 51.9, 910.0, 52.3, 964.5, 52.7, 971.4, 54.4, 978.4, 56.0, 992.9, 60.6, 1007.5, 65.2, 1017.3, 70.1, 1027.0, 75.0, 1037.7, 82.3, 1048.4, 89.5, 1054.2, 95.3, 1060.0, 101.0, 1066.2, 109.3, 1072.3, 117.5, 1077.1, 127.5, 1081.9, 137.5, 1084.6, 146.5, 1087.3, 155.5, 1087.7, 170.5, 1088.2, 185.5, 1086.5, 194.5, 1084.9, 203.5, 1081.5, 213.6, 1078.1, 223.8, 1072.6, 234.9, 1067.0, 246.0, 1059.5, 257.0, 1052.0, 268.1, 1045.9, 275.8, 1039.7, 283.5, 956.1, 367.2, 872.5, 451.0, 847.7, 451.0, 822.9, 451.0, 820.0, 449.5, 817.2, 448.0, 815.1, 445.4, 813.0, 442.7, 813.0, 438.6, 813.0, 434.5, 815.0, 431.3, 816.9, 428.1, 819.9, 426.5, 822.9, 425.0, 842.3, 425.0, 861.6, 425.0, 915.4, 370.9, 969.1, 316.8, 968.8, 314.6, 968.5, 312.5, 933.1, 312.2, 897.7, 312.0, 892.6, 308.2, 887.5, 304.5, 878.5, 297.1, 869.5, 289.7, 863.5, 284.0, 857.5, 278.2, 738.0, 178.1, 618.5, 78.0, 429.7, 78.0, 241.0, 78.0, 239.9, 80.4, 238.8, 82.7, 239.9, 84.9, 241.1, 87.0, 429.0, 87.0, 616.9, 87.0, 737.0, 188.0, 857.1, 289.0, 859.1, 290.0, 861.1, 291.1, 873.3, 301.3, 885.5, 311.5, 890.6, 315.3, 895.8, 319.0, 926.1, 319.0, 956.5, 319.0, 907.1, 368.4, 857.7, 417.8, 837.0, 418.2, 816.3, 418.5, 812.7, 421.3, 809.0, 424.1, 806.5, 429.0, 804.0, 433.9, 804.0, 439.2, 804.0, 444.5, 806.6, 448.3, 809.1, 452.1, 813.2, 455.0, 817.3, 458.0, 847.2, 458.0, 877.0, 458.0, 904.2, 430.2, 931.4, 402.5, 982.5, 351.0, 1033.6, 299.5, 1043.4, 288.0, 1053.2, 276.5, 1060.3, 266.6, 1067.4, 256.8, 1073.5, 246.0, 1079.6, 235.3, 1083.9, 224.6, 1088.2, 213.8, 1090.7, 204.2, 1093.2, 194.5, 1093.7, 179.7, 1094.3, 165.0, 1093.0, 157.2, 1091.8, 149.5, 1089.3, 141.5, 1086.8, 133.5, 1083.0, 125.5, 1079.1, 117.5, 1074.2, 110.2, 1069.3, 102.8, 1058.4, 90.8, 1047.6, 78.8, 1042.5, 75.0, 1037.4, 71.2, 1032.3, 68.6, 1027.1, 66.0, 1026.4, 64.9, 1025.7, 63.7, 1017.4, 59.9, 1009.1, 56.1, 998.9, 52.5, 988.6, 48.9, 976.6, 46.3, 964.5, 43.7, 914.0, 43.4, 863.5, 43.1, 859.0, 44.1};
        vector<float> m_rightOuterRail = {1063.5, 595.1, 1058.5, 602.1, 1047.4, 612.9, 1036.4, 623.7, 1024.9, 631.3, 1013.5, 638.9, 1003.0, 643.9, 992.5, 648.9, 981.7, 652.5, 970.9, 656.1, 959.2, 658.5, 947.5, 661.0, 675.9, 661.0, 404.3, 661.0, 375.2, 641.0, 346.2, 621.0, 291.3, 621.2, 236.5, 621.5, 236.5, 624.0, 236.5, 626.5, 288.7, 626.8, 340.9, 627.0, 370.6, 647.5, 400.3, 668.0, 677.2, 668.0, 954.0, 668.0, 963.3, 666.0, 972.5, 663.9, 984.5, 659.9, 996.5, 655.9, 1007.5, 650.6, 1018.5, 645.2, 1027.5, 639.3, 1036.5, 633.3, 1043.0, 628.0, 1049.5, 622.6, 1056.9, 615.1, 1064.2, 607.5, 1070.1, 599.7, 1076.0, 591.9, 1073.5, 589.2, 1070.9, 588.0, 1069.7, 588.1, 1068.5, 588.1, 1063.5, 595.1};
        vector<float> m_rightInnerRail = {660.8, 433.7, 655.4, 437.5, 627.7, 457.4, 600.0, 477.3, 599.5, 479.1, 598.9, 480.9, 600.0, 482.9, 601.1, 485.0, 620.8, 512.2, 640.6, 539.5, 641.4, 540.8, 642.1, 542.1, 647.8, 561.8, 653.5, 581.5, 654.3, 582.7, 655.1, 584.0, 674.0, 584.0, 692.8, 584.0, 695.7, 586.3, 698.5, 588.7, 721.5, 601.9, 744.5, 615.1, 745.4, 616.0, 746.3, 616.9, 744.0, 620.5, 741.7, 624.1, 739.3, 625.1, 736.9, 626.0, 574.2, 626.0, 411.5, 626.0, 381.8, 605.5, 352.1, 585.0, 296.3, 585.2, 240.5, 585.5, 240.5, 589.5, 240.5, 593.5, 295.8, 593.8, 351.2, 594.0, 380.2, 614.0, 409.1, 634.0, 574.5, 634.0, 739.9, 634.0, 743.7, 631.9, 747.5, 629.8, 748.8, 628.7, 750.2, 627.6, 752.6, 622.7, 755.1, 617.8, 754.8, 614.7, 754.5, 611.6, 742.5, 604.7, 730.5, 597.8, 712.9, 587.4, 695.4, 577.0, 677.9, 577.0, 660.4, 577.0, 657.0, 565.2, 653.6, 553.5, 652.5, 546.0, 651.4, 538.5, 631.2, 510.8, 611.0, 483.0, 610.8, 482.1, 610.5, 481.2, 638.5, 461.0, 666.5, 440.8, 667.6, 440.4, 668.6, 439.9, 713.5, 462.0, 758.4, 484.1, 752.5, 498.0, 745.9, 511.1, 738.9, 504.8, 731.8, 498.5, 726.8, 494.2, 721.8, 490.0, 720.0, 490.0, 718.1, 490.0, 716.6, 491.6, 715.0, 493.1, 715.0, 494.9, 715.0, 496.7, 740.8, 519.5, 766.5, 542.4, 795.1, 570.4, 823.7, 598.5, 829.6, 603.1, 835.5, 607.7, 841.6, 611.8, 847.6, 615.9, 856.1, 620.4, 864.5, 624.9, 875.5, 628.7, 886.5, 632.5, 909.9, 632.8, 933.4, 633.1, 939.9, 632.0, 946.5, 630.9, 956.6, 627.5, 966.8, 624.1, 976.1, 619.4, 985.5, 614.7, 996.0, 607.7, 1006.5, 600.6, 1022.3, 584.8, 1038.2, 569.1, 1037.8, 567.3, 1037.5, 565.6, 1034.8, 564.1, 1032.2, 562.6, 1029.4, 566.1, 1026.7, 569.5, 1015.6, 580.6, 1004.5, 591.6, 997.0, 597.2, 989.4, 602.8, 983.0, 606.9, 976.5, 611.0, 972.5, 612.9, 968.5, 614.9, 958.5, 618.6, 948.5, 622.3, 942.3, 624.6, 936.1, 626.9, 935.5, 626.0, 934.9, 625.0, 913.1, 625.0, 891.2, 625.0, 882.4, 622.4, 873.5, 619.9, 864.1, 615.4, 854.7, 611.0, 846.4, 605.5, 838.2, 600.0, 827.3, 589.3, 816.4, 578.5, 813.0, 574.5, 809.5, 570.5, 803.8, 566.5, 798.2, 562.6, 797.7, 560.0, 797.1, 557.5, 775.1, 537.6, 753.0, 517.7, 761.5, 499.9, 770.1, 482.8, 769.5, 481.1, 769.0, 479.3, 718.7, 454.6, 668.5, 429.9, 667.4, 430.0, 666.3, 430.0, 660.8, 433.7};
        vector<vector<float>> m_layer2ShapeData = {
            m_leftInnerRail, m_leftOuterRail, m_rightOuterRail, m_rightInnerRail
        };

        // All the layers
        vector<vector<vector<float>>> m_layerData = {m_underLayer, m_launchTubeLayer, m_layer1ShapeData, m_layer2ShapeData};
};
#endif