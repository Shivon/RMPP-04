/**
  ******************************************************************************
  * @file    	main.c
  * @author  	Alfred Lohmann
  *        	  HAW-Hamburg
  *          	Labor f�r technische Informatik
  *          	Berliner Tor  7
  *          	D-20099 Hamburg
  * @version V1.0
  * @date    23.05.2013
  * @brief   Main program body
  *******************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>
#include <string.h>
#include "TI_Lib.h"
#include "tft.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stringsort.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
char *pMeineStrings[] = {
	"Haller 25 EUR",
	"Kandinsky 13 EUR",
	"Brombach 5 EUR",
	"Zaluskowski 12 EUR",
	"Osman 17 EUR",
	""
	};

char *pMeineStringsASM[] = {
	"Haller 25 EUR",
	"Kandinsky 13 EUR",
	"Brombach 5 EUR",
	"Zaluskowski 12 EUR",
	"Osman 17 EUR",
	""
	};

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/**
  * @brief  Main program
  * @param  None
  * @retval None
  */

int machStriche(void)
{
	printf("-----------");
	TFT_puts("-----------");
	TFT_carriage_return();
	TFT_newline();

	return 1;
}


int main(void)
{
	Init_TI_Board();

	printf("Sort with C");
	TFT_puts("Sort with C");
	TFT_carriage_return();
	TFT_newline();

	sortiereStrings(pMeineStrings);
	printStringliste(pMeineStrings);

	machStriche();

	printf("Sort with ASM");
	TFT_puts("Sort with ASM");
	TFT_carriage_return();
	TFT_newline();

	sortiereStringsASM(pMeineStringsASM);
	printStringliste(pMeineStringsASM);

	return 0;
}
