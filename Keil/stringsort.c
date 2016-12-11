/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include "TI_Lib.h"
#include "tft.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stringsort.h"

/* Print string array to TI Board */
void printStringliste(char *string[]) {
	int i = 0;
	/* for looping through all string elements, you need to work on the matrix or
	else you just loop through every char of one string elem */
	while(string[i][0] > 0) {

		printf("%s \n", string[i]);

		TFT_puts(string[i]);
		TFT_carriage_return();
		TFT_newline();
		i++;
	}
}

/* Identify number in string and return it */
/* func expects string elements to be passed in separately (line by line) */
int getNum(char stringRow[]) {
	int i = 0;
	int result = 0;
	int currentChar;

	while ((currentChar = stringRow[i]) > 0) {
		// ASCII range numbers: 48 - 57
		if (currentChar > 47 && currentChar < 58) {
			// multiply with 10 for getting the right value regarding the digit
			result = result * 10;
			// we cant get the correct ASCII value hence we have to subtract 48 from the current ASCII char
			result = result + currentChar - 48;
		}

		i++;
	}

	return result;
};

/* sorts a string array by the number in each string (ascending) */
void sortiereStrings(char *string[]) {
	int size = 0;
	// determine size of array (while not being allowed to use sizeof() ...)
	while(string[size][0] != 0) {
		size++;
	}

	for(int j = size; j > 1; j--) {
		int lastIndex = j - 1;

		for(int i = 0 ; i < lastIndex ; i++ ) {
			int first = getNum(string[i]);
			int second = getNum(string[i+1]);

			if(second < first) {
				char *temp = string[i];
				string[i] = string[i+1];
				string[i+1] = temp;
			}
		}
	}
}

/* sort with getNum_asm */
void sortiereStringsASM(char *string[]) {
	int size = 0;
	// determine size of array (while not being allowed to use sizeof() ...)
	while(string[size][0] != 0) {
		size++;
	}

	for(int j = size; j > 1; j--) {
		int lastIndex = j - 1;

		for(int i = 0 ; i < lastIndex ; i++ ) {
			int first = getNum_asm(string[i]);
			int second = getNum_asm(string[i+1]);

			if(second < first) {
				char *temp = string[i];
				string[i] = string[i+1];
				string[i+1] = temp;
			}
		}
	}
}
