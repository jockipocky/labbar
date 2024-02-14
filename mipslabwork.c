/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog 

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int mytime = 0x5957;

char textstring[] = "text, more text, and even more text!";

/* Tilldelas deras adresser då dom är deklarerade som "volatile".
     TRISE inehåller bitarna som bestämmer om portarna är INPUT/OUTPUT
     PORTE inehåller datan som bestämmer vilken INPUT/OUTPUT det är. */

volatile int *portE = (volatile int*) 0xbf886110; // address to port E register
volatile int *trisE = (volatile int*) 0xbf886100; // address to TRISE register

/* 
/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{

*trisE = *trisE & ~0xff; // set bits 7-0 to output (0)



TRISD = TRISD|0x0fe0; // Intitalize port D set bits 11 - 5 as inputs
   
return;

}

/* This function is called repetitively from the main program */
void labwork( void )
{
  
  int btns = getbtns();
  int sw = getsw();

  // Btn 2 pressed (001)
  if (btns & 1){ 
    mytime = mytime & 0xff0f;
    mytime = (sw << 4)| mytime;
  } 

  // Btn 3 pressed (010)
  if (btns & 2){ 
    mytime = mytime & 0xf0ff;
    mytime = (sw << 8)| mytime;
  } 

  // Btn 4 pressed (100)
  if (btns & 4){ 
    
    mytime = mytime & 0x0fff;
    mytime = (sw << 12)| mytime;
  } 
  
  static int count = 0; 

  delay( 1000 );
  time2string( textstring, mytime );
  display_string( 3, textstring );
  display_update();
  tick( &mytime );
  count++;
  *portE = count; // increment by one to display bin value on LEDs
  display_image(96, icon); 
  
    
 }
