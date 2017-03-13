/* THis  runs on Visual Studio
 so make sure to use scanf instead of  scanf_s,
and comment out  getch() if you are on Unix. 
*/

#include <stdio.h>
#include <math.h>

#define PI  3.14

double convert(double f) ;  //converts F to C

int main() {
	double tempf, tempc;
	
	printf("Enter temperature in Fahrnheit\n");
	scanf("%lf", &tempf);

	printf("\nEntered temperature: %.1f F \n\n", tempf);

	tempc = convert(tempf); 
	printf("%.1f F   =   %.1f C \n", tempf, tempc);

	if ( tempc > 20)  printf("balmy\n");
	else if (tempc > 10) printf("slight chiils no mo Hawaii!\n");
	else if (tempc > 5) printf("yo freeze...\n");
	else if (tempc > 0) printf("officially freezing point \n");
	else printf("Antarctica \n");


	return 0;

}

double convert(double f) {
    double fract = 5.0/9.0;
	return (f - 32) * fract; 
}

