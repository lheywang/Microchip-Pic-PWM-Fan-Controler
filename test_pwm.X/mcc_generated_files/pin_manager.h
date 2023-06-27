/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F46K22
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)

// get/set LED_LSB aliases
#define LED_LSB_TRIS                 TRISAbits.TRISA7
#define LED_LSB_LAT                  LATAbits.LATA7
#define LED_LSB_PORT                 PORTAbits.RA7
#define LED_LSB_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define LED_LSB_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define LED_LSB_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define LED_LSB_GetValue()           PORTAbits.RA7
#define LED_LSB_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define LED_LSB_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set PB aliases
#define PB_TRIS                 TRISBbits.TRISB5
#define PB_LAT                  LATBbits.LATB5
#define PB_PORT                 PORTBbits.RB5
#define PB_WPU                  WPUBbits.WPUB5
#define PB_ANS                  ANSELBbits.ANSB5
#define PB_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define PB_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define PB_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define PB_GetValue()           PORTBbits.RB5
#define PB_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define PB_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define PB_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define PB_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define PB_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define PB_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set LED_RPM aliases
#define LED_RPM_TRIS                 TRISCbits.TRISC5
#define LED_RPM_LAT                  LATCbits.LATC5
#define LED_RPM_PORT                 PORTCbits.RC5
#define LED_RPM_ANS                  ANSELCbits.ANSC5
#define LED_RPM_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED_RPM_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED_RPM_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED_RPM_GetValue()           PORTCbits.RC5
#define LED_RPM_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED_RPM_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED_RPM_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define LED_RPM_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RD1 procedures
#define RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()              PORTDbits.RD1
#define RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetAnalogMode()         do { ANSELDbits.ANSD1 = 1; } while(0)
#define RD1_SetDigitalMode()        do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set LED_MSB aliases
#define LED_MSB_TRIS                 TRISDbits.TRISD5
#define LED_MSB_LAT                  LATDbits.LATD5
#define LED_MSB_PORT                 PORTDbits.RD5
#define LED_MSB_ANS                  ANSELDbits.ANSD5
#define LED_MSB_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define LED_MSB_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define LED_MSB_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define LED_MSB_GetValue()           PORTDbits.RD5
#define LED_MSB_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define LED_MSB_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define LED_MSB_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define LED_MSB_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCB5 pin functionality
 * @Example
    IOCB5_ISR();
 */
void IOCB5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCB5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCB5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCB5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCB5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCB5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCB5_SetInterruptHandler() method.
    This handler is called every time the IOCB5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCB5_SetInterruptHandler(IOCB5_InterruptHandler);

*/
extern void (*IOCB5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCB5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCB5_SetInterruptHandler() method.
    This handler is called every time the IOCB5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCB5_SetInterruptHandler(IOCB5_DefaultInterruptHandler);

*/
void IOCB5_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/