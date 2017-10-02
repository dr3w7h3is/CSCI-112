/*********************************/
/* Program: Largesmall Lab       */
/* Author: Drew Theis            */
/* Date: 10/01/2017              */
/*********************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* Defines file that will later be used for output */
FILE *fp;
/* Main function that runs compare set number of times default value is set to 4 */
int main(void) {
	int i;
	/* Opens csic.txt to allow printed statements to be applied to document */
	fp = fopen("csis.txt", "w");
	/* For loop that defines how many times the function calculateBMI will run */
	for (i = 1; i <= 4; ++i) {
		compare();
	}
	/* Closes txt document csic.txt after printed statemnets have been applied */
	fclose(fp);
	/* Requires user to exit the console to see last response before closing */
	system("pause");
	return 0;
}
/* Funtion takes user input of 4 numbers and sorts them to respond back the largest and smallest in console window and text document*/
int compare(int w, int x, int y, int z) {
	/* Defines initial value for when function is ran */
	int max = 0;
	int min = 0;
	/* Prompts user to input 4  numbers seperated by spaces*/
	printf("Please type in four numbers to be sorted serperated by a space: ");
	/* Reads user input and assigns them to the variables w,x,y,z respectedly */
	scanf("%d %d %d %d", &w, &x, &y, &z);
	/* Initial compare statement which either assigns w as max or eliminates it */
	if (w > x && w > y && w > z) {
		max = w;
	}
	/* Statement compare x,y,z since w was eliminated */
	else if (x > y && x > z) {
		max = x;
	}
	/* Statement compares y and z with else statement since only 2 variables are left */
	else if (y > z) {
		max = y;
	}
	else {
		max = z;
	}
	/* Initial compare statement which either assigns w as min or eliminates it */
	if (w < x && w < y && w < z) {
		min = w;
	}
	/* Statement compare x,y,z since w was eliminated */
	else if (x < y && x < z) {
		min = x;
	}
	/* Statement compares y and z with else statement since only 2 variables are left */
	else if (y < z) {
		min = y;
	}
	else {
		min = z;
	}
	/* Prints output to console window with the numbers that where enterd and the largest and smallest */
	printf("From the four numbers entered: %d %d %d %d. Max = %d Min = %d \n", w, x, y, z, max, min);
	/* Prints output to txt document csis.txt with the numbers that where enterd and the largest and smallest */
	fprintf(fp, "From the four numbers entered: %d %d %d %d. Max = %d Min = %d \n", w, x, y, z, max, min);
	return 0;
}