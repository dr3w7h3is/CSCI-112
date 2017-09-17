/*********************************/
/* Program: Heart lab            */
/* Author: Drew Theis            */
/* Date: 9/2/2017                */
/*********************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	/* Defines files to be used*/
	FILE *csis;
	/* Important interger us to solve problem*/
	int years = 50,
		days = 365,
		hours = 24,
		minutes = 60,
		seconds = 60;
	/* Opens previously defined file to allow solution to writen in txt*/
	csis = fopen("csis.txt", "w");
	/* Prints both on console window and txt doc */
	printf("Total heart beats in %d years: %d \n", years, years * days * hours * minutes * seconds);
	fprintf(csis, "Total heart beats in %d years: %d \n", years, years * days * hours * minutes * seconds);
	/* Closes defined file*/
	fclose(csis);
	system("pause");
	return 0;
}