/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F46K22
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pwm4.h"

void SetPWMPercentage(uint8_t value);

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
  
    PB_SetDigitalInput();
    PWM4_Initialize();
    //PWM4_LoadDutyValue(639);
    //__delay_ms(5000);
    //PWM4_LoadDutyValue(0);
    
    uint8_t state = 0;
    uint8_t rpm_state = 0;
   
    while (1)
    {
        if(PB_GetValue()==0)
        {
            if (state == 0)
            {
                state = 1;
                rpm_state = !rpm_state;
                
            }
        }
        else if (PB_GetValue() == 1)
            state = 0;
        __delay_ms(20);
        
        if (rpm_state == 1)
        {
           SetPWMPercentage(100);
           LED_RPM_SetHigh();
        }
        else
        {
            SetPWMPercentage(0);
            LED_RPM_SetLow();
        }
            
    }
    // OK !
    // Now handle button to swap from one speed to another
/**
 End of File
*/
}

void SetPWMPercentage(uint8_t value)
{    
    uint16_t PWM_duty;
    
    if (value < 25)
    {
        LED_LSB_SetLow();
        LED_MSB_SetLow();
    }
    else if (value > 24 && value < 50)
    {
        LED_LSB_SetHigh();
        LED_MSB_SetLow();
    }
    else if (value > 49 && value < 75)
    {
        LED_LSB_SetLow();
        LED_MSB_SetHigh();
    }
    else if (value > 74)
    {
        LED_LSB_SetHigh();
        LED_MSB_SetHigh();
    }
    
    PWM_duty = (uint16_t) value * 62.7; 
    PWM_duty += 12;
    PWM4_LoadDutyValue(PWM_duty);
    // 0% = 12
    // 100% = 639
}