/*********************************/
/* Program: Weight lab           */
/* Author: Drew Theis            */
/* Date: 9/9/2017                */
/*********************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)  {
	/* Defines the file that output will be printed to*/
	FILE *csis;
	/* Values of different weights on planets based on a 200 pound person*/
	float wgt_mer = 200 * 0.378;
	float wgt_ven = 200 * 0.907;
	float wgt_mar = 200 * 0.377;
	float wgt_jup = 200 * 2.36;
	float wgt_sat = 200 * 0.916;
	float wgt_ura = 200 * 0.889;
	float wgt_nep = 200 * 1.12;
	/* Print to console to right justify the planet name to 9 spaces 
	   and then prints the weight with5 characters only 1 decmal place */
	printf("%+9s", "Mercury: ");
	printf("%05.1f\n", wgt_mer);
	printf("%+9s", "Venus: ");
	printf("%05.1f\n", wgt_ven);
	printf("%+9s", "Mars: ");
	printf("%05.1f\n", wgt_mar);
	printf("%+9s", "Jupiter: ");
	printf("%05.1f\n", wgt_jup);
	printf("%+9s", "Saturn: ");
	printf("%05.1f\n", wgt_sat);
	printf("%+9s", "Uranus: ");
	printf("%05.1f\n", wgt_ura);
	printf("%+9s", "Neptune: ");
	printf("%05.1f\n", wgt_nep);
	/* Opens the text file that output will be printed too */
	csis = fopen("csis.txt", "w");
	/* Print to console to right justify the planet name to 9 spaces 
	   and then prints the weight with5 characters only 1 decmal place */
	fprintf(csis,"%+9s", "Mercury: ");
	fprintf(csis,"%05.1f\n", wgt_mer);
	fprintf(csis,"%+9s", "Venus: ");
	fprintf(csis,"%05.1f\n", wgt_ven);
	fprintf(csis,"%+9s", "Mars: ");
	fprintf(csis,"%05.1f\n", wgt_mar);
	fprintf(csis,"%+9s", "Jupiter: ");
	fprintf(csis,"%05.1f\n", wgt_jup);
	fprintf(csis,"%+9s", "Saturn: ");
	fprintf(csis,"%05.1f\n", wgt_sat);
	fprintf(csis,"%+9s", "Uranus: ");
	fprintf(csis,"%05.1f\n", wgt_ura);
	fprintf(csis,"%+9s", "Neptune: ");
	fprintf(csis,"%05.1f\n", wgt_nep);
	/* Closes the text after all output has been printed to it*/
	fclose(csis);
	/* Stops console from closing before  outpout can be seen */
	system("pause");
	return 0;
}
