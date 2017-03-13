/* THis  runs on Visual Studio
 so make sure to use scanf instead of  scanf_s,
and comment out  getch() if you are on Unix. 

* Paulo Lemus
*
* I replaces scanf_s and removed the getch. I also fixed the linking error with pow by using -lm while compiling.
*/

#include "spheref.h"


int main() {
	double r;
	double s = 0;
	double v = 0;
	
	printf("Enter radius in inches\n");
	scanf("%lf", &r);

	printf("\n\nSphere parameters: \n radius= %.2f inches \n\n", r);

	calcAreaAndVolume(r, &s, &v);
	printf("area= %.2lf square inches\n volume= %.2lf cubic inches\n\n", s, v);

	return 0;
}
