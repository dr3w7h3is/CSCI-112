/*********************************/
/* Program: String Lab           */
/* Author: Drew Theis            */
/* Date: 11/03/2017              */
/*********************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/* Declares function and vaiable used for appending string*/
void append(char usrStr[], char insertStr[], int pos);
/* Main function to inster word community into user inputed sentance Palomar College*/
int main() {
	/* Declares variable used usrString to apply user input and copyString for what coping sting*/
	char usrString[100], copyString[100], insertStr[100] = "Community ";
	/* Prompts the user to enter phrase */
	printf(" Enter this phrase - Palomar College.\n");
	/* Get user input and assings it to usrString */
	gets(usrString);
	/* Copies userString to copyString per assignment */
	strcpy(copyString, usrString);
	/* Prints the newly copied string */
	printf("%s\n", copyString);
	/* Calls function responible for inserting word into string passes usrString, word Community and position to be inserted */
	append(usrString, insertStr, 8);
	/* print usrString after it has been appended */
	printf("%s\n", usrString);
	/* Pauses console screen to validate functionality */
	system("pause");
	return 0;
}
/* apoend function edit string value and inserts a new string into that value */
void append(char usrStr[], char insertStr[], int pos)  {
	/* Declares a string that will be used for editing usrString */
	char placeHolder[100] = { 0 };
	/* Copies value of usrString to placeHolder to be altered */
	strncpy(placeHolder, usrStr, pos);
	/* Defines an interage with is the the length of the place holding string */
	int len = strlen(placeHolder);
	/* Copies insertString of community to place placeHolder account for the length placeHolder with pos */
	strcpy(placeHolder + len, insertStr);
	/* Adds new value to length adding value of insertString community */
	len += strlen(insertStr);
	/* Copies usrStr and position to placeHolder accounting for length */
	strcpy(placeHolder + len, usrStr + pos);
	/* Copies final place holder string value to usrStr */
	strcpy(usrStr, placeHolder);
}
