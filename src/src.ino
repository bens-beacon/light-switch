/*
* Sourcecode for ATTiny45
*
* CODE BY BEN
*/

// Includes
#include <RCSwitch.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

// Vars
RCSwitch mySwitch = RCSwitch();
unsigned int ButtonPin = 4;
int Button = 0;
int ButtonState = 0;

// Setup
void setup() 
{
  cli();                                // deactivate Interrupts global
                                        // save energy
  ADCSRA &= ~(1<<ADEN);                 // deactivate ADC
  ACSR = (1<<ACD);                      // deactivate Analog Comparator
  sei();                                // activate Interrupts global
                                        // init Pin-Change-Interrupt
  GIMSK |= (1<<PCIE);
  PCMSK |= (1<<PCINT4);                 // enable INT0 External Interrupt
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  // Power-Down-Modus
  sei();                                // activate Interrupts global

  pinMode(ButtonPin, INPUT);  
  mySwitch.enableTransmit(0);
}

// Loop
void loop() 
{
  enterSleep();
  sendCommand();  
}

void sendCommand()
{

  if (Button == HIGH && ButtonState == 0)    // if State == OFF
  {
    ButtonState = 2;
    mySwitch.switchOn("10101", "01000");     // switch on
  } 
  if (Button == HIGH && ButtonState == 1)    // if State == ON
  {
    ButtonState = 3;
    mySwitch.switchOff("10101", "01000");    // switch off
  } 
  Button = digitalRead(ButtonPin); 
  if (Button == LOW && ButtonState == 2) ButtonState = 1; 
  if (Button == LOW && ButtonState == 3) ButtonState = 0;
  Button = LOW;
}

void enterSleep()
{
  sleep_mode();
  Button = HIGH;
}

// ISR for PCINT0
ISR(PCINT0_vect){}

