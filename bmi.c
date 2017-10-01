/*********************************/
/* Program: Body Mass Index Lab  */
/* Author: Drew Theis            */
/* Date: 10/01/2017              */
/*********************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE * fp;
/* Function that calculates BMI from user input and assigns it to a category */
void calculateBMI() {
	/* Initial Values for weight and height */
	double weight = 0.0;
	double height = 0.0;
	/* Ask for user input of weight in pouunds */
	printf("What is your weight in pounds?: ");
	/* Reads value user gave from previous input int pounds as a double */
	scanf("%lf", &weight);
	/* Ask for user input of height in inches */
	printf("What is your height in inches?: ");
	/* Reads value user gave from previous input in inches as a double */
	scanf("%lf", &height);
	/* Equation to solve for that vlaue of inputed BMI */
	double bmi = (weight * 703.0) / (height * height);
	/* Created IF statements to assign 1 of 4 areas to put inputed values based on level of BMI*/
	if (bmi < 18.5) {
		/* Prints response to console window */
		printf("Your BMI is: %.2f  you are categorised as underwieght \n", bmi);
		/* Prints response to txt document */
		fprintf(fp, "Your BMI is: %.2f  you are categorised as underwieght \n", bmi);
	}
	else if (bmi > 18.5 && bmi < 25.0) {
		/* Prints response to console window */
		printf("Your BMI is: %.2f  you are categorised as normal \n", bmi);
		/* Prints response to txt document */
		fprintf(fp, "Your BMI is: %.2f  you are categorised as normal \n", bmi);
	}
	else if (bmi > 25.0 && bmi < 30.0) {
		/* Prints response to console window */
		printf("Your BMI is: %.2f  you are categorised as overweight \n", bmi);
		/* Prints response to txt document */
		fprintf(fp, "Your BMI is: %.2f  you are categorised as overweight \n", bmi);
	}
	else  if (bmi > 30.0) {
		/* Prints response to console window */
		printf("Your BMI is: %.2f  you are categorised as obese \n", bmi);
		/* Prints response to txt document */
		fprintf(fp, "Your BMI is: %.2f  you are categorised as obese \n", bmi);
	}
}
/* Main function that runs calcuateBMI set number of times default value is set to 4 */
int main(void) {
	int i;
	/* Opens csic.txt to allow printed statements to be applied to document */
	fp = fopen("csis.txt", "w");
	/* For loop that defines how many times the function calculateBMI will run */
	for (int i = 1; i <= 4; ++i) {
		calculateBMI();
	}
	/* Closes txt document csic.txt after printed statemnets have been applied */
	fclose(fp);
	/* Requires user to exit the console to see last response before closing */
	system("pause");
	return 0;
}