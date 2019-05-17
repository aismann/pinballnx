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
        vector<float> m_underOuter = {637.6, 10.6, 633.8, 12.0, 630.1, 14.2, 626.5, 16.3, 619.8, 21.6, 613.2, 26.9, 606.7, 35.6, 600.1, 44.3, 595.6, 53.4, 591.1, 62.5, 587.6, 73.0, 584.1, 83.5, 581.6, 94.5, 579.2, 105.5, 576.7, 112.1, 574.2, 118.7, 571.5, 123.1, 568.8, 127.5, 565.6, 130.8, 562.5, 134.2, 559.5, 135.8, 556.5, 137.5, 498.0, 138.0, 439.5, 138.5, 427.4, 154.0, 415.3, 169.5, 394.2, 169.8, 373.0, 170.0, 361.8, 155.0, 350.5, 140.0, 307.7, 140.0, 264.8, 140.0, 197.4, 180.0, 130.1, 220.0, 117.0, 220.0, 104.0, 220.0, 104.0, 241.0, 104.0, 262.0, 116.4, 262.0, 128.9, 262.0, 133.2, 266.4, 137.5, 270.8, 240.0, 367.0, 342.5, 463.2, 356.0, 476.0, 369.5, 488.7, 377.2, 495.8, 385.0, 503.0, 473.8, 503.0, 562.7, 503.0, 579.6, 483.0, 596.5, 463.0, 624.6, 463.0, 652.8, 463.0, 658.9, 456.1, 665.0, 449.2, 683.0, 424.8, 701.1, 401.5, 700.8, 340.5, 700.5, 279.5, 697.2, 264.5, 693.9, 249.5, 689.8, 237.5, 685.8, 225.5, 681.2, 216.5, 676.6, 207.5, 668.1, 199.0, 659.7, 190.5, 656.3, 186.1, 652.8, 181.6, 649.4, 174.7, 645.9, 167.8, 642.5, 157.7, 639.1, 147.5, 636.6, 135.0, 634.1, 122.5, 633.1, 111.5, 632.0, 100.5, 633.0, 91.0, 634.0, 81.5, 635.1, 76.0, 636.1, 70.5, 638.7, 62.7, 641.2, 55.0, 644.5, 51.5, 647.7, 48.0, 672.9, 48.0, 698.0, 48.0, 698.0, 46.5, 698.0, 45.0, 671.9, 45.0, 645.9, 45.0, 643.9, 46.0, 642.0, 47.1, 639.5, 51.0, 637.0, 55.0, 634.5, 62.3, 632.1, 69.7, 630.4, 79.6, 628.8, 89.5, 628.8, 101.0, 628.8, 112.5, 630.5, 123.4, 632.1, 134.3, 635.7, 147.9, 639.2, 161.5, 639.7, 164.0, 640.3, 166.5, 640.9, 167.0, 641.5, 167.5, 646.5, 177.5, 651.4, 187.5, 662.0, 198.1, 672.5, 208.6, 677.2, 217.6, 681.8, 226.5, 684.9, 235.4, 688.0, 244.2, 690.5, 253.9, 692.9, 263.5, 694.9, 274.9, 697.0, 286.3, 697.0, 343.4, 696.9, 400.5, 677.9, 425.0, 658.9, 449.5, 654.2, 454.2, 649.6, 459.0, 621.9, 459.0, 594.2, 459.0, 581.4, 474.2, 568.5, 489.5, 564.1, 494.3, 559.7, 499.0, 473.6, 499.0, 387.5, 499.0, 260.0, 379.0, 132.5, 259.0, 119.8, 259.0, 107.0, 259.0, 107.0, 241.0, 107.0, 223.0, 119.9, 223.0, 132.8, 223.0, 193.5, 187.0, 254.1, 151.0, 260.1, 147.5, 265.5, 144.0, 307.0, 144.0, 348.5, 144.0, 359.8, 159.0, 371.0, 174.0, 394.0, 174.0, 416.9, 174.0, 427.1, 160.7, 437.4, 147.5, 439.9, 144.7, 442.4, 142.0, 498.9, 142.0, 555.5, 142.0, 560.0, 139.9, 564.5, 137.9, 569.0, 133.1, 573.5, 128.3, 577.2, 120.9, 580.8, 113.5, 582.9, 106.0, 584.9, 98.5, 587.6, 87.5, 590.2, 76.5, 594.1, 66.6, 598.1, 56.6, 601.2, 51.1, 604.3, 45.5, 609.1, 38.9, 614.0, 32.3, 618.9, 27.7, 623.9, 23.0, 630.1, 19.0, 636.3, 15.0, 638.1, 15.0, 639.9, 15.0, 640.5, 14.0, 641.1, 13.0, 669.6, 13.0, 698.0, 13.0, 698.0, 11.0, 698.0, 9.0, 669.8, 9.1, 641.5, 9.1, 637.6, 10.6};
        vector<float> m_under1 = {361.7, 215.8, 347.0, 230.5, 347.0, 231.5, 347.0, 232.5, 361.8, 247.3, 376.5, 262.0, 395.5, 262.0, 414.5, 262.0, 429.2, 247.3, 444.0, 232.5, 444.0, 231.5, 444.0, 230.5, 429.2, 215.7, 414.5, 201.0, 395.5, 201.0, 376.5, 201.0, 361.7, 215.8};
        vector<float> m_under2 = {361.7, 303.8, 347.0, 318.5, 347.0, 319.5, 347.0, 320.5, 361.8, 335.3, 376.5, 350.0, 395.5, 350.0, 414.5, 350.0, 429.2, 335.3, 444.0, 320.5, 444.0, 319.5, 444.0, 318.5, 429.2, 303.7, 414.5, 289.0, 395.5, 289.0, 376.5, 289.0, 361.7, 303.8};
        vector<float> m_under3 = {361.7, 391.8, 347.0, 406.5, 347.0, 407.5, 347.0, 408.5, 361.8, 423.3, 376.5, 438.0, 395.5, 438.0, 414.5, 438.0, 429.2, 423.3, 444.0, 408.5, 444.0, 407.5, 444.0, 406.5, 429.2, 391.7, 414.5, 377.0, 395.5, 377.0, 376.5, 377.0, 361.7, 391.8};
        vector<vector<float>> m_underLayer = {
            m_underOuter, m_under1, m_under2, m_under3
        };

        // Launch tube layer
        vector<float> m_tubeLeft = {0.0, 534.8, 0.0, 675.0, 210.3, 675.0, 420.6, 675.0, 423.8, 671.7, 427.1, 668.3, 423.2, 661.4, 419.4, 654.5, 415.4, 646.6, 411.5, 638.7, 407.1, 633.8, 402.7, 628.9, 398.1, 625.8, 393.5, 622.6, 389.5, 619.2, 385.5, 615.8, 380.5, 616.4, 375.6, 617.0, 357.0, 635.5, 338.5, 654.0, 174.2, 654.0, 10.0, 654.0, 10.0, 640.5, 10.0, 627.0, 42.9, 627.0, 75.8, 627.0, 78.9, 623.5, 82.0, 619.9, 82.0, 618.8, 82.0, 617.7, 77.1, 604.6, 72.1, 591.5, 36.4, 493.5, 0.8, 395.5, 3.2640556924e-14, 534.8};
        vector<float> m_tubeLeftUpper = {991.0, 538.5, 985.8, 545.0, 947.3, 579.3, 908.8, 613.5, 905.7, 615.8, 902.5, 618.1, 890.8, 625.1, 879.1, 632.1, 864.8, 638.9, 850.5, 645.8, 840.5, 649.5, 830.5, 653.3, 819.0, 656.9, 807.5, 660.5, 706.2, 660.8, 604.9, 661.0, 589.0, 658.6, 573.0, 656.1, 561.3, 653.4, 549.5, 650.8, 538.0, 647.3, 526.5, 643.9, 519.0, 640.5, 511.5, 637.2, 496.0, 630.2, 480.5, 623.2, 470.5, 619.9, 460.5, 616.5, 447.0, 616.5, 433.5, 616.5, 433.2, 618.3, 432.8, 620.2, 435.2, 624.8, 437.5, 629.5, 444.1, 641.5, 450.6, 653.5, 454.1, 660.4, 457.5, 667.2, 460.8, 671.1, 464.2, 675.0, 656.4, 675.0, 848.7, 675.0, 872.1, 674.0, 895.5, 672.9, 916.3, 671.4, 937.1, 669.9, 949.1, 667.9, 961.2, 665.8, 973.4, 662.5, 985.6, 659.2, 995.0, 655.4, 1004.5, 651.7, 1013.1, 647.4, 1021.7, 643.1, 1032.1, 636.2, 1042.5, 629.2, 1051.3, 621.0, 1060.1, 612.7, 1066.3, 604.6, 1072.6, 596.5, 1075.3, 592.3, 1078.0, 588.0, 1074.6, 584.6, 1071.2, 583.0, 1070.2, 583.0, 1069.2, 583.0, 1066.9, 586.7, 1064.6, 590.5, 1058.4, 598.6, 1052.1, 606.8, 1044.3, 614.0, 1036.5, 621.2, 1026.1, 628.1, 1015.8, 635.1, 1005.4, 640.0, 995.1, 645.0, 981.8, 649.4, 968.5, 653.8, 955.9, 656.4, 943.3, 659.0, 940.6, 659.0, 938.0, 659.0, 938.0, 660.0, 938.0, 661.0, 926.5, 661.0, 915.0, 661.0, 915.0, 645.5, 915.0, 630.0, 920.3, 630.0, 925.6, 630.0, 935.1, 628.4, 944.5, 626.8, 954.0, 623.8, 963.5, 620.8, 973.7, 616.0, 983.9, 611.2, 992.7, 605.4, 1001.5, 599.7, 1007.5, 595.2, 1013.5, 590.6, 1025.3, 579.1, 1037.0, 567.7, 1037.0, 566.5, 1037.0, 565.4, 1019.6, 548.7, 1002.2, 532.0, 999.2, 532.0, 996.2, 532.0, 991.0, 538.5};
        vector<float> m_tubeRight = {0.1, 140.2, 0.1, 280.5, 1.5, 277.0, 2.9, 273.5, 42.1, 164.5, 81.2, 55.5, 81.7, 53.4, 82.2, 51.3, 79.0, 47.6, 75.8, 44.0, 42.9, 44.0, 10.0, 44.0, 10.0, 31.0, 10.0, 18.0, 173.5, 18.0, 337.0, 18.0, 364.0, 45.0, 391.0, 72.0, 397.9, 72.0, 404.9, 72.0, 411.2, 68.6, 417.5, 65.2, 429.5, 58.6, 441.5, 52.0, 456.5, 45.6, 471.5, 39.2, 485.0, 34.7, 498.5, 30.2, 513.0, 26.6, 527.5, 23.0, 540.6, 21.0, 553.6, 19.0, 567.6, 18.0, 581.5, 17.0, 603.3, 16.3, 625.0, 15.7, 625.0, 32.7, 625.0, 49.8, 620.5, 50.9, 615.9, 52.0, 610.2, 54.8, 604.5, 57.6, 594.8, 63.3, 585.0, 69.1, 591.8, 81.5, 598.5, 92.9, 600.3, 93.0, 602.2, 93.0, 605.0, 91.0, 607.8, 89.0, 616.7, 84.9, 625.5, 80.8, 642.5, 73.5, 659.5, 66.2, 674.0, 60.7, 688.5, 55.1, 701.0, 50.0, 713.5, 44.9, 714.4, 43.9, 715.4, 43.0, 683.2, 43.0, 651.0, 43.0, 651.0, 28.5, 651.0, 14.0, 807.8, 14.3, 964.5, 14.6, 974.5, 16.3, 984.5, 18.1, 996.0, 20.6, 1007.5, 23.1, 1022.5, 28.1, 1037.4, 33.1, 1049.5, 38.9, 1061.5, 44.8, 1070.5, 50.8, 1079.5, 56.8, 1087.6, 63.8, 1095.7, 70.8, 1102.2, 78.7, 1108.7, 86.5, 1113.5, 93.8, 1118.2, 101.2, 1121.5, 108.3, 1124.8, 115.5, 1127.3, 124.5, 1129.9, 133.5, 1132.7, 146.0, 1135.5, 158.5, 1135.8, 339.0, 1136.1, 519.5, 1135.0, 530.5, 1133.9, 541.5, 1131.5, 552.5, 1129.2, 563.5, 1126.0, 573.0, 1122.9, 582.5, 1117.0, 594.8, 1111.1, 607.1, 1105.4, 615.8, 1099.8, 624.5, 1094.2, 631.5, 1088.6, 638.5, 1082.5, 644.9, 1076.5, 651.3, 1067.5, 658.8, 1058.5, 666.4, 1048.9, 672.7, 1039.2, 679.0, 1026.9, 684.9, 1014.5, 690.9, 1005.0, 694.0, 995.5, 697.2, 984.5, 699.8, 973.5, 702.4, 486.8, 702.7, -5.68434188608e-13, 703.0, -5.68434188608e-13, 711.5, -5.68434188608e-13, 720.0, 576.0, 720.0, 1152.0, 720.0, 1152.0, 360.0, 1152.0, -1.13686837722e-13, 576.0, -1.13686837722e-13, -4.54747350886e-13, -1.13686837722e-13, 0.0999999999995, 140.2};
        vector<vector<float>> m_launchTubeLayer = {
            m_tubeLeft, m_tubeRight, m_tubeLeftUpper
        };

        // Main table layer
        vector<float> m_upperWall = {786.0, 60.6, 777.5, 62.1, 765.8, 66.0, 754.2, 69.9, 744.5, 74.6, 734.9, 79.2, 723.2, 87.1, 711.5, 95.0, 708.1, 98.0, 704.6, 101.0, 707.4, 103.9, 710.3, 106.9, 714.7, 103.1, 719.0, 99.2, 727.8, 93.4, 736.5, 87.6, 746.8, 82.4, 757.1, 77.2, 767.8, 73.7, 778.5, 70.1, 788.0, 68.5, 797.5, 66.9, 881.5, 67.3, 965.5, 67.6, 977.6, 70.3, 989.7, 73.0, 998.6, 76.1, 1007.5, 79.2, 1015.7, 83.1, 1023.8, 87.0, 1032.7, 92.9, 1041.6, 98.9, 1048.7, 105.4, 1055.7, 111.9, 1061.3, 118.8, 1067.0, 125.7, 1068.8, 129.0, 1070.5, 130.9, 1072.4, 134.5, 1074.4, 138.1, 1073.4, 138.8, 1072.4, 139.5, 1064.4, 145.6, 1056.5, 151.7, 1050.7, 155.5, 1045.0, 159.3, 1039.7, 152.0, 1035.1, 145.5, 1031.3, 141.5, 1027.4, 137.5, 1021.3, 132.0, 1015.2, 126.5, 1007.3, 121.8, 999.4, 117.1, 991.6, 114.0, 983.9, 110.9, 976.4, 109.0, 968.9, 107.1, 958.9, 106.0, 948.8, 105.0, 920.1, 105.0, 891.4, 105.0, 883.2, 106.0, 875.0, 107.1, 866.3, 109.6, 857.5, 112.1, 849.2, 116.0, 840.8, 120.0, 833.7, 124.7, 826.6, 129.5, 817.8, 137.9, 809.0, 146.3, 804.0, 152.5, 799.1, 158.7, 794.5, 166.0, 790.0, 173.4, 790.0, 175.2, 790.0, 177.0, 792.6, 178.2, 795.3, 179.4, 796.6, 177.5, 798.0, 175.5, 803.9, 166.5, 809.8, 157.5, 817.5, 149.3, 825.1, 141.1, 833.1, 135.1, 841.1, 129.1, 851.3, 124.0, 861.5, 119.0, 871.5, 116.3, 881.5, 113.7, 914.0, 113.2, 946.5, 112.8, 957.1, 113.9, 967.8, 115.0, 975.6, 117.1, 983.5, 119.1, 990.5, 122.1, 997.5, 125.1, 1005.0, 129.7, 1012.5, 134.4, 1022.5, 144.5, 1032.5, 154.6, 1036.5, 161.2, 1040.5, 167.8, 1060.8, 173.4, 1081.1, 179.1, 1083.3, 178.8, 1085.4, 178.5, 1086.6, 174.5, 1087.8, 170.5, 1087.9, 164.3, 1088.0, 158.1, 1085.9, 148.3, 1083.8, 138.5, 1080.3, 132.2, 1076.9, 126.0, 1071.1, 118.2, 1065.2, 110.5, 1055.9, 101.5, 1046.5, 92.4, 1037.5, 86.4, 1028.5, 80.4, 1020.0, 76.3, 1011.5, 72.2, 1001.1, 68.6, 990.6, 64.9, 978.6, 62.3, 966.5, 59.6, 880.5, 59.4, 794.5, 59.1, 786.0, 60.6};
        vector<float> m_upperWall2 = {721.8, 489.6, 716.0, 494.2, 716.0, 495.5, 716.0, 496.8, 746.8, 525.7, 777.5, 554.7, 784.5, 560.9, 791.4, 567.0, 792.5, 567.0, 793.6, 567.0, 802.3, 575.4, 811.0, 583.9, 811.0, 588.8, 811.0, 593.8, 807.8, 596.5, 804.5, 599.1, 798.7, 603.4, 793.0, 607.7, 781.8, 611.0, 770.7, 614.3, 764.6, 613.7, 758.5, 613.1, 756.7, 612.5, 755.0, 611.8, 755.0, 608.7, 755.0, 605.7, 752.9, 599.9, 750.8, 594.2, 744.2, 588.3, 737.5, 582.5, 718.4, 563.7, 699.2, 545.0, 696.8, 545.0, 694.5, 545.0, 690.7, 548.1, 687.0, 551.1, 687.0, 554.4, 687.0, 557.6, 694.4, 589.5, 701.9, 621.5, 704.2, 623.3, 706.5, 625.2, 744.0, 624.7, 781.5, 624.2, 793.0, 622.1, 804.5, 620.0, 816.0, 616.4, 827.5, 612.9, 841.5, 606.1, 855.5, 599.2, 863.5, 593.3, 871.5, 587.3, 917.0, 545.6, 962.5, 503.8, 966.4, 500.0, 970.3, 496.2, 968.1, 492.6, 965.8, 489.0, 964.6, 489.0, 963.4, 489.0, 959.9, 492.6, 956.5, 496.2, 916.5, 531.4, 876.5, 566.5, 873.2, 569.3, 869.8, 572.0, 867.5, 572.0, 865.2, 572.0, 862.4, 569.7, 859.7, 567.5, 857.1, 564.5, 854.5, 561.6, 850.3, 557.6, 846.0, 553.6, 846.0, 551.5, 846.0, 549.3, 876.5, 520.6, 907.0, 491.8, 907.0, 489.6, 907.0, 487.4, 905.8, 486.2, 904.6, 485.0, 816.1, 485.0, 727.5, 485.0, 721.8, 489.6};
        vector<float> m_upperWall3 = {927.2, 392.8, 908.2, 407.7, 903.7, 410.3, 899.1, 413.0, 841.6, 413.0, 784.1, 413.0, 781.8, 414.1, 779.5, 415.2, 776.0, 419.5, 772.5, 423.8, 767.0, 431.0, 761.5, 438.1, 755.8, 445.2, 750.0, 452.2, 750.0, 453.6, 750.0, 454.9, 751.6, 456.4, 753.1, 458.0, 841.5, 458.0, 929.8, 458.0, 931.9, 453.5, 934.0, 449.0, 934.0, 448.0, 934.0, 446.9, 943.5, 415.3, 953.0, 383.7, 953.0, 382.4, 953.0, 381.1, 951.4, 379.6, 949.9, 378.0, 948.1, 378.0, 946.2, 378.0, 927.2, 392.8};
        vector<float> m_upperWall4 = {852.4, 333.7, 850.7, 336.5, 844.1, 343.4, 837.5, 350.2, 829.5, 356.5, 821.5, 362.7, 813.5, 368.0, 805.6, 373.4, 801.0, 375.1, 796.5, 376.8, 796.5, 380.1, 796.5, 383.5, 845.5, 383.8, 894.5, 384.1, 897.5, 383.5, 900.6, 383.0, 908.5, 376.4, 916.5, 369.8, 916.5, 368.1, 916.5, 366.5, 904.0, 366.0, 891.5, 365.5, 887.0, 363.2, 882.5, 360.8, 879.6, 358.2, 876.8, 355.5, 868.7, 345.5, 860.7, 335.5, 859.2, 333.2, 857.8, 331.0, 856.0, 331.0, 854.2, 331.0, 852.4, 333.7};
        vector<float> m_upperWall5 = {928.9, 391.6, 911.5, 405.3, 906.0, 408.9, 900.5, 412.5, 848.5, 413.0, 796.5, 413.5, 796.5, 417.5, 796.5, 421.5, 849.8, 421.8, 903.2, 422.0, 927.2, 403.3, 951.3, 384.5, 951.8, 383.1, 952.3, 381.7, 951.3, 380.1, 950.3, 378.5, 948.3, 378.2, 946.3, 377.9, 928.9, 391.6};
        vector<float> m_leftSlide = {120.9, 45.8, 118.2, 47.4, 117.0, 49.4, 115.8, 51.3, 113.3, 57.9, 110.9, 64.5, 107.9, 72.5, 104.9, 80.5, 103.6, 84.0, 102.3, 87.5, 97.1, 101.5, 91.9, 115.5, 89.9, 121.0, 87.8, 126.5, 86.5, 130.0, 85.1, 133.5, 82.6, 140.0, 80.2, 146.5, 76.4, 156.5, 72.7, 166.5, 70.3, 173.0, 67.9, 179.5, 66.6, 183.0, 65.3, 186.5, 62.6, 193.8, 59.8, 201.2, 64.2, 200.8, 67.9, 199.7, 72.4, 201.0, 76.9, 202.2, 82.4, 207.7, 87.8, 213.3, 88.8, 212.6, 89.8, 212.0, 93.8, 202.3, 97.9, 192.5, 101.5, 183.0, 105.0, 173.5, 107.5, 167.0, 110.0, 160.5, 113.5, 151.0, 117.0, 141.5, 119.5, 135.0, 122.0, 128.5, 125.5, 119.3, 129.0, 110.0, 131.1, 103.3, 133.2, 96.5, 137.2, 84.5, 141.3, 72.5, 144.0, 66.4, 146.7, 60.3, 149.1, 58.1, 151.5, 55.8, 155.0, 54.1, 158.5, 52.5, 218.4, 52.0, 278.3, 51.5, 279.3, 49.8, 280.4, 48.1, 278.6, 46.1, 276.7, 44.0, 200.1, 44.1, 123.5, 44.2, 120.9, 45.8};
        vector<float> m_rightSlide = {82.2, 464.4, 77.0, 469.7, 72.4, 471.0, 67.9, 472.3, 64.2, 471.2, 60.6, 470.1, 62.4, 477.7, 64.9, 484.5, 67.5, 491.5, 70.1, 498.5, 71.4, 502.0, 72.7, 505.5, 76.4, 515.5, 80.2, 525.5, 82.6, 532.0, 85.1, 538.5, 86.5, 542.0, 87.8, 545.5, 89.9, 551.0, 91.9, 556.5, 97.1, 570.5, 102.3, 584.5, 103.6, 588.0, 104.9, 591.5, 107.9, 599.5, 110.9, 607.5, 113.3, 614.1, 115.8, 620.7, 117.0, 622.6, 118.2, 624.6, 121.2, 626.3, 124.2, 628.0, 200.4, 628.0, 276.7, 628.0, 278.6, 625.9, 280.4, 623.9, 279.3, 622.2, 278.3, 620.5, 218.4, 620.0, 158.5, 619.5, 155.0, 617.9, 151.5, 616.2, 149.1, 613.9, 146.7, 611.7, 144.0, 605.6, 141.2, 599.5, 136.6, 585.5, 132.0, 571.5, 129.0, 563.0, 126.1, 554.5, 122.5, 545.0, 118.9, 535.5, 116.5, 529.0, 114.1, 522.5, 110.5, 513.0, 106.9, 503.5, 104.5, 497.0, 102.1, 490.5, 99.7, 484.0, 97.2, 477.5, 93.3, 468.6, 89.5, 459.7, 88.5, 459.3, 87.5, 459.0, 82.2, 464.4};
        vector<float> m_leftSlideLine = {165.2, 79.2, 164.0, 80.4, 164.0, 82.1, 164.0, 83.8, 165.4, 84.9, 166.7, 86.0, 219.0, 85.8, 271.3, 85.5, 272.4, 83.7, 273.5, 82.0, 272.4, 80.2, 271.3, 78.5, 218.8, 78.2, 166.4, 78.0, 165.2, 79.2};
        vector<float> m_rightSlideLine = {165.2, 587.2, 164.0, 588.4, 164.0, 590.1, 164.0, 591.8, 165.4, 592.9, 166.7, 594.0, 219.0, 593.8, 271.3, 593.5, 272.4, 591.7, 273.5, 590.0, 272.4, 588.2, 271.3, 586.5, 218.8, 586.2, 166.4, 586.0, 165.2, 587.2};
        vector<float> m_leftBumper = {160.4, 113.9, 157.4, 115.7, 143.7, 147.1, 130.0, 178.5, 130.0, 181.6, 130.0, 184.7, 132.3, 186.8, 134.6, 189.0, 137.6, 189.0, 140.7, 189.0, 142.9, 186.6, 145.2, 184.2, 144.8, 180.5, 144.5, 176.7, 160.0, 168.8, 175.5, 160.9, 183.1, 156.5, 190.8, 152.1, 196.4, 149.6, 202.1, 147.1, 224.3, 135.0, 246.6, 123.0, 251.6, 125.5, 254.9, 128.0, 257.8, 128.0, 260.7, 128.0, 262.8, 125.7, 265.0, 123.4, 265.0, 120.3, 265.0, 117.2, 261.9, 114.6, 258.8, 112.0, 211.2, 112.0, 163.5, 112.0, 160.4, 113.9};
        vector<float> m_rightBumper = {132.2, 485.3, 130.0, 487.6, 130.0, 490.6, 130.0, 493.5, 143.7, 524.9, 157.4, 556.3, 160.4, 558.1, 163.5, 560.0, 211.2, 560.0, 258.8, 560.0, 261.9, 557.4, 265.0, 554.8, 265.0, 551.6, 265.0, 548.3, 262.7, 546.2, 260.4, 544.0, 257.6, 544.0, 254.9, 544.0, 251.6, 546.5, 248.3, 549.0, 224.3, 537.0, 202.1, 524.9, 196.4, 522.4, 190.8, 519.9, 183.1, 515.5, 175.5, 511.1, 160.0, 503.2, 144.5, 495.3, 144.8, 491.5, 145.2, 487.8, 142.9, 485.4, 140.7, 483.0, 137.5, 483.0, 134.3, 483.0, 132.2, 485.3};
        vector<float> m_backdoor = {422.0, 670.2, 422.0, 672.5, 427.5, 681.5, 433.0, 690.5, 433.0, 692.5, 433.0, 694.5, 435.0, 695.8, 437.0, 697.0, 437.0, 699.3, 437.0, 701.7, 439.4, 702.9, 441.8, 704.2, 442.8, 706.4, 443.8, 708.6, 448.6, 709.7, 453.5, 710.8, 462.8, 710.9, 472.0, 711.1, 472.0, 710.0, 472.0, 709.0, 474.5, 709.0, 477.0, 709.0, 477.0, 706.7, 477.0, 704.3, 467.7, 703.7, 458.3, 703.1, 453.9, 701.1, 449.5, 699.2, 445.5, 695.7, 441.4, 692.2, 434.1, 680.1, 426.8, 668.0, 424.4, 668.0, 422.0, 668.0, 422.0, 670.2};
        vector<vector<float>> m_layer1ShapeData = {
            m_tubeRight, m_tubeLeft, m_tubeLeftUpper, m_upperWall, m_upperWall2, m_upperWall3, m_upperWall4, /*m_upperWall5,*/ m_leftSlide, m_rightSlide, m_rightSlideLine, m_leftSlideLine, m_leftBumper, m_rightBumper, m_backdoor
        };

        // Layer 3 shapes.
        vector<float> m_leftInnerRail = {271.1, 46.8, 270.2, 48.6, 271.1, 50.3, 272.1, 52.0, 417.3, 52.0, 562.4, 52.0, 568.0, 57.8, 573.5, 63.5, 660.6, 156.5, 747.8, 249.5, 757.3, 255.7, 766.7, 262.0, 776.1, 266.4, 785.5, 270.8, 794.5, 273.8, 803.5, 276.8, 811.5, 278.4, 819.5, 280.0, 829.0, 281.0, 838.5, 282.0, 914.7, 282.0, 990.9, 282.0, 998.6, 280.9, 1006.3, 279.8, 1011.9, 277.8, 1017.5, 275.8, 1025.5, 271.1, 1033.5, 266.5, 1041.3, 258.7, 1049.1, 251.0, 1053.6, 241.2, 1058.2, 231.5, 1059.0, 229.5, 1059.9, 227.5, 1061.1, 223.0, 1062.3, 218.5, 1062.4, 205.0, 1062.5, 191.5, 1059.4, 182.8, 1056.3, 174.1, 1050.5, 163.8, 1044.7, 153.5, 1040.4, 147.4, 1036.2, 141.4, 1030.2, 135.9, 1024.3, 130.4, 1018.6, 126.6, 1012.9, 122.9, 1005.2, 119.0, 997.4, 115.1, 988.2, 112.1, 979.1, 109.1, 968.5, 107.0, 957.9, 105.0, 931.4, 105.0, 905.0, 105.0, 905.0, 108.9, 905.0, 112.9, 934.3, 113.2, 963.5, 113.6, 969.5, 115.3, 975.5, 117.0, 984.9, 120.7, 994.3, 124.3, 996.1, 126.1, 998.0, 128.0, 999.3, 128.0, 1000.7, 128.0, 1008.1, 133.1, 1015.5, 138.3, 1025.0, 147.9, 1034.5, 157.6, 1042.2, 169.0, 1049.9, 180.5, 1051.6, 185.0, 1053.2, 189.5, 1053.7, 202.0, 1054.2, 214.5, 1053.2, 219.5, 1052.2, 224.5, 1049.5, 232.3, 1046.7, 240.1, 1039.2, 248.2, 1031.6, 256.2, 1022.8, 262.2, 1013.9, 268.1, 1008.7, 270.0, 1003.5, 271.8, 996.5, 273.4, 989.5, 275.0, 918.0, 275.0, 846.5, 275.0, 833.5, 273.5, 820.5, 272.0, 812.5, 270.4, 804.6, 268.8, 794.6, 265.3, 784.7, 261.9, 777.0, 258.0, 769.4, 254.2, 760.2, 248.0, 751.0, 241.9, 742.3, 233.7, 733.7, 225.5, 707.7, 196.5, 681.7, 167.5, 623.6, 106.2, 565.5, 45.0, 418.8, 45.0, 272.1, 45.0, 271.1, 46.8};
        vector<float> m_leftOuterRail = {831.0, 61.9, 831.0, 66.0, 847.3, 66.1, 863.5, 66.2, 914.5, 66.9, 965.5, 67.7, 976.3, 69.9, 987.1, 72.1, 996.2, 75.1, 1005.3, 78.0, 1013.8, 82.0, 1022.4, 86.1, 1032.4, 92.7, 1042.5, 99.4, 1053.0, 109.9, 1063.6, 120.5, 1069.2, 129.0, 1074.8, 137.5, 1079.4, 147.6, 1084.0, 157.7, 1086.1, 167.6, 1088.2, 177.5, 1089.0, 182.5, 1089.9, 187.5, 1089.9, 206.6, 1090.0, 225.6, 1088.9, 231.6, 1087.8, 237.5, 1087.1, 238.5, 1086.4, 239.5, 1085.0, 244.0, 1083.7, 248.5, 1080.9, 254.1, 1078.2, 259.7, 1070.2, 269.6, 1062.2, 279.5, 1053.7, 288.1, 1045.2, 296.8, 1024.7, 313.9, 1004.1, 331.0, 985.8, 345.3, 967.5, 359.5, 948.3, 373.9, 929.0, 388.2, 929.0, 390.8, 929.0, 393.3, 907.8, 392.6, 886.6, 391.9, 885.5, 354.2, 884.7, 317.0, 924.7, 317.0, 964.6, 317.0, 965.8, 318.2, 967.0, 319.4, 967.0, 320.7, 967.0, 321.9, 961.8, 325.8, 956.5, 329.7, 944.5, 338.5, 932.5, 347.3, 926.5, 351.8, 920.5, 356.4, 912.0, 363.5, 903.5, 370.6, 897.8, 374.9, 892.0, 379.2, 892.0, 381.6, 892.0, 384.0, 894.1, 384.0, 896.2, 384.0, 939.1, 349.8, 982.0, 315.7, 982.0, 314.0, 982.0, 312.3, 980.2, 310.7, 978.3, 309.0, 896.2, 309.0, 814.0, 309.0, 803.2, 305.5, 792.5, 302.0, 776.5, 293.9, 760.5, 285.8, 753.5, 282.2, 746.5, 278.7, 739.9, 273.8, 733.4, 269.0, 691.8, 225.2, 650.3, 181.5, 603.2, 132.0, 556.1, 82.5, 552.3, 80.3, 548.5, 78.0, 394.7, 78.0, 241.0, 78.0, 239.9, 80.4, 238.8, 82.7, 239.9, 84.9, 241.1, 87.0, 395.3, 87.0, 549.6, 87.0, 623.6, 164.1, 697.5, 241.2, 715.5, 260.1, 733.5, 279.1, 743.2, 284.4, 753.0, 289.8, 764.2, 295.3, 775.5, 300.9, 783.0, 304.0, 790.5, 307.2, 800.5, 311.2, 810.5, 315.2, 839.0, 316.0, 867.5, 316.8, 871.6, 316.9, 875.7, 317.0, 876.5, 358.0, 877.2, 398.9, 878.4, 399.9, 879.6, 400.9, 919.8, 402.0, 960.1, 403.2, 961.5, 402.0, 963.0, 400.8, 963.0, 388.0, 963.0, 375.3, 1005.0, 340.5, 1047.0, 305.8, 1047.0, 304.5, 1047.0, 303.2, 1054.8, 296.3, 1062.7, 289.5, 1065.1, 287.4, 1067.5, 285.2, 1072.4, 280.0, 1077.2, 274.7, 1082.9, 265.8, 1088.5, 256.9, 1090.7, 252.7, 1092.9, 248.5, 1095.6, 240.1, 1098.3, 231.8, 1097.7, 201.1, 1097.0, 170.5, 1095.5, 164.7, 1093.9, 159.0, 1086.4, 143.7, 1079.0, 128.5, 1072.6, 120.0, 1066.2, 111.5, 1056.4, 102.0, 1046.5, 92.4, 1037.1, 86.2, 1027.7, 79.9, 1018.6, 75.5, 1009.5, 71.2, 1000.6, 68.1, 991.7, 65.0, 979.6, 62.5, 967.5, 60.1, 956.5, 59.6, 945.5, 59.0, 888.3, 58.4, 831.0, 57.9, 831.0, 61.9};
        vector<float> m_rightOuterRail = {1063.5, 595.1, 1057.7, 603.1, 1047.0, 613.4, 1036.3, 623.7, 1024.9, 631.3, 1013.5, 638.9, 1002.9, 643.9, 992.4, 649.0, 980.4, 652.9, 968.5, 656.8, 957.5, 658.9, 946.5, 661.0, 937.5, 662.0, 928.5, 663.0, 667.8, 663.0, 407.2, 663.0, 375.9, 641.5, 344.7, 620.0, 290.6, 620.2, 236.5, 620.5, 236.5, 623.5, 236.5, 626.5, 288.7, 626.8, 340.9, 627.0, 372.7, 649.0, 404.5, 671.0, 667.0, 671.0, 929.5, 671.0, 938.5, 670.0, 947.5, 669.0, 958.5, 666.9, 969.5, 664.8, 983.0, 660.4, 996.5, 656.0, 1007.5, 650.6, 1018.5, 645.2, 1027.5, 639.3, 1036.5, 633.3, 1043.0, 628.0, 1049.5, 622.6, 1056.9, 615.1, 1064.2, 607.5, 1070.1, 599.7, 1076.0, 591.9, 1072.7, 588.8, 1069.4, 587.2, 1063.5, 595.1};
        vector<float> m_rightInnerRail = {660.8, 433.7, 655.4, 437.5, 627.7, 457.4, 600.0, 477.3, 599.5, 479.1, 598.9, 480.9, 600.0, 482.9, 601.0, 484.9, 633.1, 529.2, 665.2, 573.5, 666.8, 574.7, 668.4, 576.0, 669.7, 576.0, 671.0, 576.0, 681.8, 568.6, 692.7, 561.2, 695.5, 559.7, 698.4, 558.2, 720.7, 579.9, 742.9, 601.5, 745.5, 602.4, 748.0, 603.4, 748.0, 608.4, 748.0, 613.5, 744.9, 618.8, 741.9, 624.1, 739.4, 625.0, 736.9, 626.0, 574.2, 626.0, 411.5, 626.0, 381.8, 605.5, 352.1, 585.0, 296.3, 585.2, 240.5, 585.5, 240.5, 588.5, 240.5, 591.5, 294.4, 591.8, 348.2, 592.0, 378.7, 613.0, 409.2, 634.0, 574.6, 634.0, 739.9, 634.0, 743.7, 631.9, 747.5, 629.8, 748.8, 628.7, 750.2, 627.6, 752.6, 622.8, 755.0, 618.1, 755.0, 611.9, 755.0, 605.7, 752.8, 599.8, 750.7, 593.9, 730.1, 574.1, 709.5, 554.3, 704.2, 549.6, 698.9, 545.0, 696.7, 545.0, 694.5, 545.0, 682.5, 554.9, 670.5, 564.8, 669.9, 564.1, 669.2, 563.5, 640.1, 523.2, 611.0, 483.0, 610.7, 482.1, 610.5, 481.2, 638.5, 461.0, 666.5, 440.8, 667.6, 440.4, 668.6, 439.9, 713.5, 462.0, 758.4, 484.1, 752.5, 498.0, 745.9, 511.1, 738.9, 504.8, 731.8, 498.5, 726.8, 494.2, 721.8, 490.0, 720.0, 490.0, 718.1, 490.0, 716.6, 491.6, 715.0, 493.1, 715.0, 494.9, 715.0, 496.7, 740.8, 519.5, 766.5, 542.4, 795.1, 570.4, 823.7, 598.5, 829.6, 603.1, 835.5, 607.7, 841.6, 611.8, 847.6, 615.9, 856.1, 620.4, 864.5, 624.9, 875.5, 628.7, 886.5, 632.5, 909.9, 632.8, 933.4, 633.1, 939.9, 632.0, 946.5, 630.9, 956.6, 627.5, 966.8, 624.1, 976.1, 619.4, 985.5, 614.7, 995.9, 607.7, 1006.3, 600.6, 1017.8, 589.6, 1029.3, 578.5, 1034.2, 572.6, 1039.1, 566.8, 1035.8, 564.5, 1032.5, 562.2, 1029.6, 565.9, 1026.7, 569.5, 1015.6, 580.6, 1004.5, 591.6, 997.0, 597.2, 989.4, 602.8, 983.0, 606.9, 976.5, 611.0, 972.5, 612.9, 968.5, 614.9, 958.5, 618.6, 948.5, 622.3, 942.3, 624.6, 936.1, 626.9, 935.5, 626.0, 934.9, 625.0, 913.1, 625.0, 891.2, 625.0, 882.4, 622.4, 873.5, 619.9, 864.1, 615.4, 854.7, 611.0, 846.4, 605.5, 838.2, 600.0, 827.3, 589.3, 816.4, 578.5, 813.0, 574.5, 809.5, 570.5, 803.8, 566.5, 798.2, 562.6, 797.7, 560.0, 797.1, 557.5, 775.1, 537.6, 753.0, 517.7, 761.5, 499.9, 770.1, 482.8, 769.5, 481.1, 769.0, 479.3, 718.7, 454.6, 668.5, 429.9, 667.4, 430.0, 666.3, 430.0, 660.8, 433.7};
        vector<vector<float>> m_layer2ShapeData = {
            m_leftInnerRail, m_leftOuterRail, m_rightOuterRail, m_rightInnerRail
        };

        // All the layers
        vector<vector<vector<float>>> m_layerData = {m_underLayer, m_launchTubeLayer, m_layer1ShapeData, m_layer2ShapeData};
};
#endif