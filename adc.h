/* 
 * File:   adc.h
 * Author: Vishnu Prasanna V, Pushpa Raman V, Karmukilan K.T, Sanjay S, Ahamed Atheeq M.A,
 * Description: Contains functions related to ADC
 * Created on 4 December, 2021, 4:08 PM
 */

#ifndef ADC_H
#define	ADC_H
#include<xc.h>
#define _XTAL_FREQ 20000000
#include <stdint.h>

void adc_init() {
     ADCON0 = 0x41;  // Turn ADC ON, Select AN0 Channel, ADC Clock = Fosc/8 01000001
     ADCON1 = 0x80;  // All 8 Channels Are Analog, Result is "Right-Justified" 10000000
                    // ADC Clock = Fosc/8
}


uint16_t ADC_Read(uint8_t ANC)
{
  if(ANC<0 || ANC>7) // Check Channel Number Validity
  { return 0;}
  //Clearing the channel and setting the channel is otional 
  ADCON0 &= 0x11000101; // Clear The Channel Selection Bits
  ADCON0 |= ANC<<3; // Select The Required Channel (ANC) //shifting the anc bit to the correct location for adding
  // Wait The Aquisition Time
  __delay_us(30); // The Minimum Tacq = 20us, So That should be enough
  GO_DONE = 1; // Start A/D Conversion
  while(ADCON0bits.GO_DONE); // Polling GO_DONE Bit
  // Provides Delay Until Conversion Is Complete
  return ((ADRESH << 8) + ADRESL); // Return The Right-Justified 10-Bit Result
}

#endif	/* ADC_H */

