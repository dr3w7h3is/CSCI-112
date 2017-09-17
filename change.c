/*********************************/
/* Program: Change lab           */
/* Author: Drew Theis            */
/* Date: 9/17/2017               */
/*********************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)  {
	/* Defines the file that output will be printed to*/
	FILE * csis;
	/* Defines inital parameters for amount given cost of item and */
	float tendered = 100;
	float cost = 21.17;
	/* Equation to take previous defined data to give amount of change */
	float change = tendered - cost;
	/* Equation to make number easy to work with when using remainder */
	int total = change * 100;
	/* Defines the diffrenet amounts of denomination values used */
	int twenty, ten, five, one, quarter, dime, nickel, penny;
	/* Seires of values set to define the amout of specific dednomination required and puts remainder into total to allow operation on next lower denomination */
	twenty = (int)total / 2000;
	total = (int)total % 2000;
	ten = (int)total / 1000;
	total = (int)total % 1000;
	five = (int)total / 500;
	total = (int)total % 500;
	one = (int)total / 100;
	total = (int)total % 100;
	quarter = (int)total / 25;
	total = (int)total % 25;
	dime = (int)total / 10;
	total = (int)total % 10;
	nickel = (int)total / 5;
	total = (int)total % 5;
	penny = (int)total;
	/* Statement printing the different amouts of tender needed into console window */
	printf("A purchase of a $%.2f item is paid for with $%.2f the change will be $%.2f. \nThe minimum bills and coins required to make this change is: \n%d twenties \n%d tens \n%d fives \n%d ones \n%d quarters \n%d dimes \n%d nickels \n%d pennies\n", cost, tendered, change, twenty, ten, five, one, quarter, dime, nickel, penny);
	/* Opens txt file that output will be printed too */
	csis = fopen("csis.txt", "w+");
	/* Statement printing the different amouts of tender needed into txt file*/
	fprintf(csis, "A purchase of a $%.2f item is paid for with $%.2f the change will be $%.2f. \nThe minimum bills and coins required to make this change is: \n%d twenties \n%d tens \n%d fives \n%d ones \n%d quarters \n%d dimes \n%d nickels \n%d pennies\n", cost, tendered, change, twenty, ten, five, one, quarter, dime, nickel, penny);
	/* Closes txt file after printing has completed */
	fclose(csis);
	/* Stops console from closing before outpout can be seen */
	system("pause");
	return 0;
}