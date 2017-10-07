/*********************************/
/* Program: Fish Fry Project     */
/* Author: Drew Theis            */
/* Date: 10/07/2017              */
/*********************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* Program to calculate rate of water leaking from tank and time when fish in tank will die */
int main(woid) {
	/* Define variables for initial start*/
	double tankVol = 500.0;
	int x = 1;
	double addPerHour;
	/* Prompts the user to input number of gallons they will continue to add per hour */
	printf("Please enter additional water added per hour in gallons. If no addtional water will be added enter 0: ");
	/* Read the respones given by the user and assigns it to named variable */
	scanf("%lf", &addPerHour);
	/* While loop based off variable x to be larger than 0 to contiue operation */
	while (x > 0) {
		/* Define the variable for the rate of loss that the tank has current value at 10% loss per hour */
		double tankLoss = 0.1;
		/* If statement based on the parameter that as long as the volume of tank is great then 100 gallons to contine */
		if (tankVol > 100) {
			/* Equation to calculate new value for loss based on changing vol of tank */
			tankLoss = tankVol * tankLoss;
			/* Equation to solve for the new volume of water in tank minus the loss from the leak */
			tankVol = tankVol - tankLoss;
			/* Print statement to inform the user of hours pass and gallons remaining */
			printf("After %d hours there is %.2f gallons remaining.	", x, tankVol);
			/* If statement to only add water to the tank equation if the volume of the tank is great then 100 gallons */
			if (tankVol > 100) {
				/* Equation to update volume of tank after set gallons have been added */
				tankVol = tankVol + addPerHour;
				/* Print statement informs the user of the new volume size of tank affter add set amount per hour */
				printf("%.2f gallons added	New Volume in tank: %.2f \n", addPerHour, tankVol);
				/* Add incriments of 1 to value x to keep track of hours (operations) passed */
				x = x + 1;
			}
			/* Else statement to leave loop when parameter of tank volume less then 100 gallons */
			else {
			}
		}
		/* Else statement to leave loop when parameter of tank volume less then 100 gallons */
		else {
			/* Print statement that informs user that fish are dead and how many hours passed */
			printf("\nAt %d hours the tank is empty and all the fish are dead. \n", x);
			/* Setting x to 0 end while loops allowing application to close*/
			x = 0;
		}
	}
	/* Requires user to exit the console to see last response before closing */
	system("pause");
	return 0;
}