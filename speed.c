/*********************************/
/* Program: Speed lab            */
/* Author: Drew Theis            */
/* Date: 9/2/2017                */
/*********************************/

#include <stdio.h>
/* Was added after a long search to solve issue with fopen in program fix was gathered from Microsoft.com */
#pragma warning(disable:4996)

FILE *csis;

int main(void)  {
	float distance = 425.5,
		  time = 7.5,
		  seconds = time * 3600,
		  meters = distance * 1600;

	csis = fopen("csis.txt", "w");

	printf("Speed (mph): %.2f\n", distance / time);
	fprintf(csis, "Speed (mph): %.2f\n", distance / time);
	printf("Speed (meters/second): %.2f\n", meters / seconds);
	fprintf(csis, "Speed (meters/second): %.2f\n", meters / seconds);

	fclose(csis);

	system("pause");

	return 0;
}