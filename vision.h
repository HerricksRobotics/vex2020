/*vex-vision-config:begin*/
#include "vex.h"
vex::vision::signature ORANGECUBE = vex::vision::signature (1, 10777, 13667, 12222, -4231, -3295, -3763, 3, 0);
vex::vision::signature PURPLECUBE = vex::vision::signature (2, 4293, 6985, 5639, -2341, 485, -928, 2, 0);
vex::vision::signature SIG_3 = vex::vision::signature (3, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision Vision1 = vex::vision (vex::PORT7, 54, ORANGECUBE, PURPLECUBE, SIG_3, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/
