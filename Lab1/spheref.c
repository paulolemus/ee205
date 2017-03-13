#include "spheref.h"

void calcAreaAndVolume(double rad, double *parea, double *pvolume){
    *parea = 4.0 * rad * rad * PI;
    *pvolume = 4.0 / 3.0 * rad * rad * rad * PI;
}
