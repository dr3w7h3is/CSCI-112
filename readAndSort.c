/*********************************/
/* Program: Read  and Sort Lab   */
/* Author: Drew Theis            */
/* Date: 10/05/2017              */
/*********************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/* Defines file to call and read */
FILE *fpIn;
/* Defines functions */
void swap(int *x, int *y);
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);
/* Main takes 50 randomized numbers from txt file and sort them in acending order */
int main(void) {
	/* Define interger to be used for counting repitition */
	int i;
	/* Defines the array that hold the numbers read from txt file */
	int arr[50];
	/* If statement to open txt doc and error check by making sure the file can be read */
	if ((fpIn = fopen("randomfifty.txt", "r")) == NULL) {
		printf("fiftyrandom.txt could not be opened!\n");
		exit(1);
	}
	/* For loop to repeat the reading portion of the numbner from the txt file */
	for (i = 0; i < 50; i++) {
		/* Used to read the number associated in the txt file realitive to the number of reps done */
		fscanf(fpIn, "%d,", &arr[i]);
	}
	/* Integer set to size of array */
	int n = 50;
	/* Calls the bubble function for sorting */
	bubbleSort(arr, n);
	/* Prints in console a header */
	printf("Drew - Bubble Sort \n");
	printf("------------------\n");
	/* Calls function for printing the ordered array */
	printArray(arr, n);
	/* Closes the text file */
	fclose(fpIn);
	/* Pauses the console window to read output */
	system("pause");
	return 0;
}
/* Swap function for changing variable and comparing */
void swap(int *x, int *y) {
	/* Swaps the value of the x to y for compaing */
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
/* Sorting function using bubble method */
void bubbleSort(int arr[], int n) {
	/* Defines i and j for values used in comparison */
	int i, j;
	/* Bubble method sorting to arragne numbers in array from random to acending order */
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
/* Functio to print array as list */
void printArray(int arr[], int size) {
	/* Defines i to be used in for loop for counting */
	int i;
	/* For loop to perfom print in console window each number in array */
	for (i = 0; i < size; i++)
		printf("%d\n", arr[i]);
	printf("\n");
}