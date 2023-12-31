/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F46K22
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB             :  MPLAB X 5.20

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "pin_manager.h"




void (*IOCB5_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x20;
    LATA = 0x80;
    LATB = 0x20;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x07;
    TRISA = 0x7F;
    TRISB = 0xFF;
    TRISC = 0xDF;
    TRISD = 0xDD;

    /**
    ANSELx registers
    */
    ANSELD = 0xDF;
    ANSELC = 0xD8;
    ANSELB = 0x1F;
    ANSELE = 0x07;
    ANSELA = 0x2F;

    /**
    WPUx registers
    */
    WPUB = 0x20;
    INTCON2bits.nRBPU = 0;



    /**
    IOCx registers 
    */
    //interrupt on change for group IOCB - flag
    IOCBbits.IOCB5 = 0;



    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCB5_SetInterruptHandler(IOCB5_DefaultInterruptHandler);
   
    
}
  
void PIN_MANAGER_IOC(void)
{   
	// interrupt on change for pin IOCB5
    if(IOCBbits.IOCB5 == 1)
    {
        IOCB5_ISR();  
    }	
	// Clear global Interrupt-On-Change flag
    INTCONbits.RBIF = 0;
}

/**
   IOCB5 Interrupt Service Routine
*/
void IOCB5_ISR(void) {

    // Add custom IOCB5 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCB5_InterruptHandler)
    {
        IOCB5_InterruptHandler();
    }
}

/**
  Allows selecting an interrupt handler for IOCB5 at application runtime
*/
void IOCB5_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCB5_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCB5
*/
void IOCB5_DefaultInterruptHandler(void){
    // add your IOCB5 interrupt custom code
    // or set custom function using IOCB5_SetInterruptHandler()
}

/**
 End of File
*/