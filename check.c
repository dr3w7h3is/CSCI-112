/*********************************/
/* Program: Checking Account Lab */
/* Author: Drew Theis            */
/* Date: 10/27/2017              */
/*********************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* Declares function outputHeader */
void outputHeaders(void);
/* Declares function initialBalance and passes variables amount, balance, service, and openBalance */
void initialBalance(double amount, double* balance, double* service, double* openBalance);
/* Declares function deposit and passes variables amount, balance, service, numDeposit, and amtDeposit */
void deposit(double amount, double* balance, double* service, int* numDeposit, double* amtDeposit);
/* Declares function check and passes variables amount, balance, service, numCheck, and amtCheck */
void check(double amount, double* balance, double* service, int* numCheck, double* amtCheck);
/* Declares outputSummary and passes variables numDeposit, amtDeposit, numCheck, amtCheck, openBalance, service, and classBalance */
void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance);
/* Defines files to be used as input and output */
FILE *fpIn;
FILE *fpOut;
/* Copy of the main function from text book to be used */
int main(void) {
	char code;
	double amount, service, balance;
	double amtCheck, amtDeposit, openBalance, closeBalance;
	int numCheck, numDeposit;

	if (!(fpIn = fopen("account.txt", "r"))) {
		printf("account.txt could not be opened for input.");
		exit(1);
	}
	if (!(fpOut = fopen("csis.txt", "w"))) {
		printf("csis.txt could not be opened for output");
		exit(1);
	}

	amount = 0.0;
	service = 0.0;
	balance = 0.0;
	amtCheck = 0.0;
	amtDeposit = 0.0;
	openBalance = 0.0;
	closeBalance = 0.0;
	numCheck = 0;
	numDeposit = 0;

	outputHeaders();

	while (!feof(fpIn)) {
		fscanf(fpIn, "%c %lf\n", &code, &amount);
		if (code == 'I') {
			initialBalance(amount, &balance, &service, &openBalance);
		}
		else if (code == 'D') {
			deposit(amount, &balance, &service, &numDeposit, &amtDeposit);
		}
		else {
			check(amount, &balance, &service, &numCheck, &amtCheck);
		}
	}


	closeBalance = balance - service;
	outputSummary(numDeposit, amtDeposit, numCheck, amtCheck, openBalance, service, closeBalance);
	fclose(fpIn);
	fclose(fpOut);
	system("pause");
	return 0;
}

void outputHeaders(void) {
	/* Prints format of the header with descriptions in console */
	printf("%s%16s%12s%14s\n", "Transaction", "Deposit", "Check", "Balance");
	printf("-----------         -------       -----       -------\n");
	/* Prints format of the header with descriptions in txt document csis.txt */
	fprintf(fpOut, "%s%16s%12s%14s\n", "Transaction", "Deposit", "Check", "Balance");
	fprintf(fpOut, "-----------         -------       -----       -------\n");
}
/* Function to print format and account for service fee */
void initialBalance(double amount, double* balance, double* service, double* openBalance) {
	/* Sets fee for each month of account */
	service += 3;
	/* Defines the inital balance to amount read from the account.txt file and set each month balance amount */
	*balance = amount;
	*openBalance = amount;
	/* Prints and formats initial balance to console window */
	printf("Initial Balance %37.2lf\n", *balance);
	/* Prints and formats initial balance to txt document csis.txt */
	fprintf(fpOut, "Initial Balance %37.2lf\n", *balance);
}
/* Function for printing and formatting deposits */
void deposit(double amount, double* balance, double* service, int* numDeposit, double* amtDeposit) {
	/* Sets service fee amount of 3 cents on deposits */
	*service += 0.03;
	/* Takes balance and adds the last amount to form new balance */
	*balance = *balance + amount;
	/* Keeps a total of numbner of deposits made */
	*amtDeposit += amount;
	/* Keeps an incrimental total of deposits */
	*numDeposit = *numDeposit + 1;
	/* Prints and formats deposits made to console window */
	printf("%s%20.2lf%26.2lf\n", "Deposit", amount, *balance);
	/* Prints and formants deposits made to txt document csis.txt */
	fprintf(fpOut, "%s%20.2lf%26.2lf\n", "Deposit", amount, *balance);
}
/* Function for printing and formatting checks */
void check(double amount, double* balance, double* service, int* numCheck, double* amtCheck) {
	/* Loop to check if amount is greater than 0 to not charge fee */
	if ((*balance - amount) > 0) {
		*balance = *balance - amount;
	}
	/* Loop to check if amount if less then 0 to charge a fee */
	else if ((*balance - amount) < 0) {
		*balance = *balance - amount;
		/* Defines service fee of 5 dollars for overdraft */
		*service += 5.00;
	}
	/* Sets service fee of 6 cents for checks */
	*service += 0.06;
	/* Keeps total amount of money paid in checks */
	*amtCheck += amount;
	/* Keeps a total of number of checks written */
	*numCheck = *numCheck + 1;
	/* Prings and formats checks written and balance to console window */
	printf("%s%34.2lf%14.2lf\n", "Check", amount, *balance);
	/* Prints and formats check written and balance to txt document csic.txt */
	fprintf(fpOut, "%s%34.2lf%14.2lf\n", "Check", amount, *balance);
}
/* Function for printing and formatting summary output */
void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance) {
	/* Adds 2 line space between transactions and summary in console window */
	printf("\n\n");
	/* Prints and formats total number of deposits in console window */
	printf("Total number of deposits: %d\n", numDeposit);
	/* Prints and formats total amount of deposits in console window*/
	printf("Total amount deposits: %.2lf\n\n", amtDeposit);
	/* Prints and formats amount of checks in console window */
	printf("Total number of checks: %d\n", numCheck);
	/* Prints and formats total amounts of checks in console window */
	printf("Total amount checks: %.2lf\n\n", amtCheck);
	/* Prints and formats total service charges in console window */
	printf("Total service charge: %.2lf\n\n", service);
	/* Prints and formats opening balance in console window */
	printf("Opening balance: %.2lf\n", openBalance);
	/* Prints and formats closing balance in console window */
	printf("Closing balance: %.2lf\n", closeBalance);
	/* Adds 2 line space between transactions and summary in txt document csis.txt */
	fprintf(fpOut, "\n\n");
	/* Prints and formats total number of deposits in txt document csis.txtw */
	fprintf(fpOut, "Total number of deposits: %d\n", numDeposit);
	/* Prints and formats total amount of deposits in txt document csis.txt */
	fprintf(fpOut, "Total amount deposits: %.2lf\n\n", amtDeposit);
	/* Prints and formats amount of checks in txt document csis.txt */
	fprintf(fpOut, "Total number of checks: %d\n", numCheck);
	/* Prints and formats total amounts of checks in txt document csis.txt */
	fprintf(fpOut, "Total amount checks: %.2lf\n\n", amtCheck);
	/* Prints and formats total service charges in txt document csis.txt */
	fprintf(fpOut, "Total service charge: %.2lf\n\n", service);
	/* Prints and formats opening balance in txt document csis.txt */
	fprintf(fpOut, "Opening balance: %.2lf\n", openBalance);
	/* Prints and formats closing balance in txt document csis.txt */
	fprintf(fpOut, "Closing balance: %.2lf\n", closeBalance);
}