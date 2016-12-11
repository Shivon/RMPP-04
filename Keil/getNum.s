;**************************************************************
;
; HAW Hamburg, Department Informatik
; Praktikum Rechnerstrukturen und Maschinennahe Programmierung
;
; Zweck:		Asm-Programm zu A4: 'Stringsortierung'
; Dateiname:	getNum.s
; History:
;
; 5'2014  Cnz	Aufbereitung für Aufgabenstellung
; 7'2013  Beh	Erstversion für Arm-Cortex M4
; 7'2005  Msl   Urfassung für Pentium (GEME-System)
;
;**************************************************************


		IMPORT	TFT_puts
		IMPORT  TFT_cls
		IMPORT  TFT_gotoxy
		IMPORT  Delay

;********************************************
; Data section, aligned on 4-byte boundary
;********************************************
; ######################
	AREA MyData, DATA, align = 2

; start and end of ASCII numbers as decimal
NUMBER_START	equ		 48
NUMBER_END		equ		 57


;********************************************
; Code section, aligned on 4-byte boundary
;********************************************

	AREA MyCode, CODE, readonly, align = 3

;--------------------------------------------
; main subroutine
;--------------------------------------------
			GLOBAL getNum_asm

;-------------------------------------------------------------------------------------------------
getNum_asm		PROC
			push{r1 - r3, lr}

			MOV r2, r0
			MOV r0, #0
			MOV r3, #10

WHILE_STRING
			LDRB r1, [r2], #1
			CMP r1, #0
			BLS WHILE_STRING_END
			
IF_NUMBER
			CMP r1, #NUMBER_START
			BLO IF_NUMBER_END

			CMP r1, #NUMBER_END
			BHI IF_NUMBER_END

			MUL r0, r0, r3
			SUB r1, r1, #NUMBER_START
			ADD r0, r1
IF_NUMBER_END

			B WHILE_STRING

WHILE_STRING_END

			pop{r1 - r3, lr}
			bx lr

forever		b		forever			; nowhere to retun if main ends

			ENDP

			ALIGN 4
			END
