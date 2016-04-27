/************************************************************************/
/*																		*/
/*	Board_Data.c --	DP32 Customization Data Declarations		        */
/*																		*/
/************************************************************************/
/*	Author: Gene Apperson												*/
/*	Copyright 2011, Digilent. All rights reserved						*/
/************************************************************************/
/*  File Description:													*/
/*																		*/
/* This file contains the board specific declartions and data structure	*/
/* to customize the chipKIT MPIDE for use with a CmodCK1 board using a	*/
/* PIC32 part in a 44-pin package.										*/
/*																		*/
/* This code is based on earlier work:									*/
/*		Copyright (c) 2010, 2011 by Mark Sproul							*/
/*		Copyright (c) 2005, 2006 by David A. Mellis						*/
/*																		*/
/************************************************************************/
/*  Revision History:													*/
/*																		*/
/*	11/28/2011(GeneA): Created by splitting data out of Board_Defs.h	*/
/*  03/26/2013(KeithV): Modified for DP32 board                          */
/*																		*/
/************************************************************************/
//*	This library is free software; you can redistribute it and/or
//*	modify it under the terms of the GNU Lesser General Public
//*	License as published by the Free Software Foundation; either
//*	version 2.1 of the License, or (at your option) any later version.
//*	
//*	This library is distributed in the hope that it will be useful,
//*	but WITHOUT ANY WARRANTY; without even the implied warranty of
//*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*	Lesser General Public License for more details.
//*	
//*	You should have received a copy of the GNU Lesser General
//*	Public License along with this library; if not, write to the
//*	Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*	Boston, MA  02111-1307  USA
/************************************************************************/

#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*					Data Tables									*/
/* ------------------------------------------------------------ */
/* The following declarations define data used in pin mapping.	*/
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_DATA)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t	port_to_tris_PGM[] = {
	NOT_A_PORT,				//index value 0 is not used

#if defined(_PORTA)
	(uint32_t)&TRISA,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTB)
	(uint32_t)&TRISB,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTC)
	(uint32_t)&TRISC,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTD)
	(uint32_t)&TRISD,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTE)
	(uint32_t)&TRISE,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTF)
	(uint32_t)&TRISF,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTG)
	(uint32_t)&TRISG,
#else
	NOT_A_PORT,
#endif

	NOT_A_PORT,
};

/* ------------------------------------------------------------ */
/* This table is used to map the digital pin number to the port
** containing that pin. The default mapping is to assign pin numbers
** for every possible port bit in order from PORTA to PORTG.
*/
const uint8_t	digital_pin_to_port_PGM[] = {

    // Click connector
    _IOPORT_PG,         //  0: AN / RG9
    _IOPORT_PD,         //  1: RST / RD6
    _IOPORT_PE,         //  2: CS / RE5
    _IOPORT_PD,         //  3: SCK / RD2
    _IOPORT_PD,         //  4: MISO / RD3
    _IOPORT_PD,         //  5: MOSI / RD4
    _IOPORT_PD,         //  6: SDA / RD9
    _IOPORT_PD,         //  7: SCL / RD10
    _IOPORT_PF,         //  8: TX / RF4
    _IOPORT_PF,         //  9: RX / RD5
    _IOPORT_PD,         // 10: INT / RD0
    _IOPORT_PF,         // 11: PWM / RF3

    // LEDs and Buttons
    _IOPORT_PB,         // 11: LD0 / RB1
    _IOPORT_PB,         // 12: LD1 / RB2
    _IOPORT_PE,         // 14: T1 / RE7
    _IOPORT_PB,         // 15: T2 / RB0

    // Battery voltage sensor
    _IOPORT_PB,         // 16: BAT_SENSE_EN / RB8
    _IOPORT_PB,         // 17: BAT_SENSE / RB11

    // RF Module
    _IOPORT_PB,         // 18: RF_GPIO0 / RB3
    _IOPORT_PB,         // 19: RF_GPIO1 / RB4
    _IOPORT_PE,         // 20: RF_GPIO2 / RE6
    _IOPORT_PD,         // 21: RF_GPIO3 / RD5
    _IOPORT_PE,         // 22: RF_GPIO4 / RE1
    _IOPORT_PE,         // 23: RF_GPIO5 / RE4
    _IOPORT_PE,         // 24: RF_CS / RE3
    _IOPORT_PE,         // 25: RF_RST / RE2
    _IOPORT_PE,         // 26: RF_VREG_EN / RE0
    _IOPORT_PG,         // 27: RF_SCK / RG6
    _IOPORT_PG,         // 28: RF_MISO / RG7
    _IOPORT_PG,         // 29: RF_MOSI / RG8
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t	digital_pin_to_bit_mask_PGM[] = {
    // Click connector
    _BV( 9 ),           //  0: AN / RG9
    _BV( 6 ),           //  1: RST / RD6
    _BV( 5 ),           //  2: CS / RE5
    _BV( 2 ),           //  3: SCK / RD2
    _BV( 3 ),           //  4: MISO / RD3
    _BV( 4 ),           //  5: MOSI / RD4
    _BV( 9 ),           //  6: SDA / RD9
    _BV(10 ),           //  7: SCL / RD10
    _BV( 4 ),           //  8: TX / RF4
    _BV( 5 ),           //  9: RX / RD5
    _BV( 0 ),           // 10: INT / RD0
    _BV( 3 ),           // 11: PWM / RF3

    // LEDs and Buttons
    _BV( 1 ),           // 11: LD0 / RB1
    _BV( 2 ),           // 12: LD1 / RB2
    _BV( 7 ),           // 14: T1 / RE7
    _BV( 0 ),           // 15: T2 / RB0

    // Battery voltage sensor
    _BV( 8 ),           // 16: BAT_SENSE_EN / RB8
    _BV(11 ),           // 17: BAT_SENSE / RB11

    // RF Module
    _BV( 3 ),           // 18: RF_GPIO0 / RB3
    _BV( 4 ),           // 19: RF_GPIO1 / RB4
    _BV( 6 ),           // 20: RF_GPIO2 / RE6
    _BV( 5 ),           // 21: RF_GPIO3 / RD5
    _BV( 1 ),           // 22: RF_GPIO4 / RE1
    _BV( 4 ),           // 23: RF_GPIO5 / RE4
    _BV( 3 ),           // 24: RF_CS / RE3
    _BV( 2 ),           // 25: RF_RST / RE2
    _BV( 0 ),           // 26: RF_VREG_EN / RE0
    _BV( 6 ),           // 27: RF_SCK / RG6
    _BV( 7 ),           // 28: RF_MISO / RG7
    _BV( 8 ),           // 29: RF_MOSI / RG8

};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t	digital_pin_to_timer_PGM[] = {
    // Click connector
    NOT_ON_TIMER,       //  0: AN / RG9
    NOT_ON_TIMER,       //  1: RST / RD6
    NOT_ON_TIMER,       //  2: CS / RE5
    NOT_ON_TIMER,       //  3: SCK / RD2
    NOT_ON_TIMER,       //  4: MISO / RD3
    NOT_ON_TIMER,       //  5: MOSI / RD4
    NOT_ON_TIMER,       //  6: SDA / RD9
    NOT_ON_TIMER,       //  7: SCL / RD10
    NOT_ON_TIMER,       //  8: TX / RF4
    NOT_ON_TIMER,       //  9: RX / RD5
    NOT_ON_TIMER,       // 10: INT / RD0
    _TIMER_OC1,         // 11: PWM / RF3

    // LEDs and Buttons
    NOT_ON_TIMER,       // 12: LD0 / RB1
    NOT_ON_TIMER,       // 13: LD1 / RB2
    NOT_ON_TIMER,       // 14: T1 / RE7
    NOT_ON_TIMER,       // 15: T2 / RB0

    // Battery voltage sensor
    NOT_ON_TIMER,       // 16: BAT_SENSE_EN / RB8
    NOT_ON_TIMER,       // 17: BAT_SENSE / RB11

    // RF Module
    NOT_ON_TIMER,       // 18: RF_GPIO0 / RB3
    NOT_ON_TIMER,       // 19: RF_GPIO1 / RB4
    NOT_ON_TIMER,       // 20: RF_GPIO2 / RE6
    NOT_ON_TIMER,       // 21: RF_GPIO3 / RD5
    NOT_ON_TIMER,       // 22: RF_GPIO4 / RE1
    NOT_ON_TIMER,       // 23: RF_GPIO5 / RE4
    NOT_ON_TIMER,       // 24: RF_CS / RE3
    NOT_ON_TIMER,       // 25: RF_RST / RE2
    NOT_ON_TIMER,       // 26: RF_VREG_EN / RE0
    NOT_ON_TIMER,       // 27: RF_SCK / RG6
    NOT_ON_TIMER,       // 28: RF_MISO / RG7
    NOT_ON_TIMER,       // 29: RF_MOSI / RG8
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** PPS register. This register is used to select the peripheral output
** connected to the pin. The register is set to 0 to disconnedt the
** pin from any peripheral so it can be used as GPIO.
** For PIC32MX1xx/2xx series devices, the PPS output select registers
** are arranged as a contiguous series of 32 bit registers. This table
** treats these registers as an array of DWORDs an stores the index
** to the register.
*/
const uint8_t digital_pin_to_pps_out_PGM[] = {

    // Click connector
    _PPS_OUT(_PPS_RPG9R),   //  0: AN / RG9
    NOT_PPS_PIN,            //  1: RST / RD6
    _PPS_OUT(_PPS_RPE5R),   //  2: CS / RE5
    _PPS_OUT(_PPS_RPD2R),   //  3: SCK / RD2
    _PPS_OUT(_PPS_RPD3R),   //  4: MISO / RD3
    _PPS_OUT(_PPS_RPD4R),   //  5: MOSI / RD4
    _PPS_OUT(_PPS_RPD9R),   //  6: SDA / RD9
    _PPS_OUT(_PPS_RPD10R),  //  7: SCL / RD10
    _PPS_OUT(_PPS_RPF4R),   //  8: TX / RF4
    _PPS_OUT(_PPS_RPD5R),   //  9: RX / RD5
    _PPS_OUT(_PPS_RPD0R),   // 10: INT / RD0
    _PPS_OUT(_PPS_RPF3R),   // 11: PWM / RF3

    // LEDs and Buttons
    _PPS_OUT(_PPS_RPB1R),   // 11: LD0 / RB1
    _PPS_OUT(_PPS_RPB2R),   // 12: LD1 / RB2
    NOT_PPS_PIN,            // 14: T1 / RE7
    _PPS_OUT(_PPS_RPB0R),   // 15: T2 / RB0

    // Battery voltage sensor
    _PPS_OUT(_PPS_RPB8R),   // 16: BAT_SENSE_EN / RB8
    NOT_PPS_PIN,            // 17: BAT_SENSE / RB11

    // RF Module
    _PPS_OUT(_PPS_RPB3R),   // 18: RF_GPIO0 / RB3
    NOT_PPS_PIN,            // 19: RF_GPIO1 / RB4
    NOT_PPS_PIN,            // 20: RF_GPIO2 / RE6
    _PPS_OUT(_PPS_RPD5R),   // 21: RF_GPIO3 / RD5
    NOT_PPS_PIN,            // 22: RF_GPIO4 / RE1
    NOT_PPS_PIN,            // 23: RF_GPIO5 / RE4
    _PPS_OUT(_PPS_RPE3R),   // 24: RF_CS / RE3
    NOT_PPS_PIN,            // 25: RF_RST / RE2
    NOT_PPS_PIN,            // 26: RF_VREG_EN / RE0
    _PPS_OUT(_PPS_RPG6R),   // 27: RF_SCK / RG6
    _PPS_OUT(_PPS_RPG7R),   // 28: RF_MISO / RG7
    _PPS_OUT(_PPS_RPG8R),   // 29: RF_MOSI / RG8
};

/* ------------------------------------------------------------ */
/* This table maps from the digital pin number to the value to be
** loaded into a PPS input select register to select that pin.
** It also maps from digital pin number to input/output pin set to 
** which the pin belongs. The set mask is in the high four bits,
** the select value is in the low four bits.
** Note: if the PIC32 device has more than four pin sets, or more than
** 16 pin mapping choices per input function, then this table will have
** to be redefined as a table of uint16_t values and the macros used to
** access the table redefined as well.
*/
const uint8_t digital_pin_to_pps_in_PGM[] = {
    // Click connector
    _PPS_IN(_PPS_RPG9),   //  0: AN / RG9
    NOT_PPS_PIN,            //  1: RST / RD6
    _PPS_IN(_PPS_RPE5),   //  2: CS / RE5
    _PPS_IN(_PPS_RPD2),   //  3: SCK / RD2
    _PPS_IN(_PPS_RPD3),   //  4: MISO / RD3
    _PPS_IN(_PPS_RPD4),   //  5: MOSI / RD4
    _PPS_IN(_PPS_RPD9),   //  6: SDA / RD9
    _PPS_IN(_PPS_RPD10),  //  7: SCL / RD10
    _PPS_IN(_PPS_RPF4),   //  8: TX / RF4
    _PPS_IN(_PPS_RPD5),   //  9: RX / RD5
    _PPS_IN(_PPS_RPD0),   // 10: INT / RD0
    _PPS_IN(_PPS_RPF3),     // 11: PWM / RF3

    // LEDs and Buttons
    _PPS_IN(_PPS_RPB1),   // 11: LD0 / RB1
    _PPS_IN(_PPS_RPB2),   // 12: LD1 / RB2
    NOT_PPS_PIN,            // 14: T1 / RE7
    _PPS_IN(_PPS_RPB0),   // 15: T2 / RB0

    // Battery voltage sensor
    _PPS_IN(_PPS_RPB8),   // 16: BAT_SENSE_EN / RB8
    NOT_PPS_PIN,            // 17: BAT_SENSE / RB11

    // RF Module
    _PPS_IN(_PPS_RPB3),   // 18: RF_GPIO0 / RB3
    NOT_PPS_PIN,            // 19: RF_GPIO1 / RB4
    NOT_PPS_PIN,            // 20: RF_GPIO2 / RE6
    _PPS_IN(_PPS_RPD5),   // 21: RF_GPIO3 / RD5
    NOT_PPS_PIN,            // 22: RF_GPIO4 / RE1
    NOT_PPS_PIN,            // 23: RF_GPIO5 / RE4
    _PPS_IN(_PPS_RPE3),   // 24: RF_CS / RE3
    NOT_PPS_PIN,            // 25: RF_RST / RE2
    NOT_PPS_PIN,            // 26: RF_VREG_EN / RE0
    _PPS_IN(_PPS_RPG6),   // 27: RF_SCK / RG6
    _PPS_IN(_PPS_RPG7),   // 28: RF_MISO / RG7
    _PPS_IN(_PPS_RPG8),   // 29: RF_MOSI / RG8
};

/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
** In the default case, where there is a one-to-one mapping, this
** table isn't needed as the analogInPinToChannel() macro is defined
** to provide the mapping.
*/
//#if defined(_NOT_USED_)
const uint8_t analog_pin_to_channel_PGM[] = {
	19,
	11,
};
//#endif

const uint8_t digital_pin_to_analog_PGM[] = {
    // Click connector
    _BOARD_AN0,          //  0: AN / RG9
    NOT_ANALOG_PIN,         //  1: RST / RD6
    NOT_ANALOG_PIN,       //  2: CS / RE5
    NOT_ANALOG_PIN,       //  3: SCK / RD2
    NOT_ANALOG_PIN,       //  4: MISO / RD3
    NOT_ANALOG_PIN,       //  5: MOSI / RD4
    NOT_ANALOG_PIN,       //  6: SDA / RD9
    NOT_ANALOG_PIN,       //  7: SCL / RD10
    NOT_ANALOG_PIN,       //  8: TX / RF4
    NOT_ANALOG_PIN,       //  9: RX / RD5
    NOT_ANALOG_PIN,       // 10: INT / RD0
    NOT_ANALOG_PIN,         // 11: PWM / RF3

    // LEDs and Buttons
    NOT_ANALOG_PIN,       // 11: LD0 / RB1
    NOT_ANALOG_PIN,       // 12: LD1 / RB2
    NOT_ANALOG_PIN,         // 14: T1 / RE7
    NOT_ANALOG_PIN,       // 15: T2 / RB0

    // Battery voltage sensor
    NOT_ANALOG_PIN,       // 16: BAT_SENSE_EN / RB8
    _BOARD_AN1,            // 17: BAT_SENSE / RB11

    // RF Module
    NOT_ANALOG_PIN,       // 18: RF_GPIO0 / RB3
    NOT_ANALOG_PIN,         // 19: RF_GPIO1 / RB4
    NOT_ANALOG_PIN,         // 20: RF_GPIO2 / RE6
    NOT_ANALOG_PIN,       // 21: RF_GPIO3 / RD5
    NOT_ANALOG_PIN,         // 22: RF_GPIO4 / RE1
    NOT_ANALOG_PIN,         // 23: RF_GPIO5 / RE4
    NOT_ANALOG_PIN,       // 24: RF_CS / RE3
    NOT_ANALOG_PIN,         // 25: RF_RST / RE2
    NOT_ANALOG_PIN,         // 26: RF_VREG_EN / RE0
    NOT_ANALOG_PIN,       // 27: RF_SCK / RG6
    NOT_ANALOG_PIN,       // 28: RF_MISO / RG7
    NOT_ANALOG_PIN,       // 29: RF_MOSI / RG8
};

/* ------------------------------------------------------------ */
/* This table maps from an output compare number as stored in the
** digital_pin_to_timer_PGM table to the digital pin number of the
** pin that OC is connected to. This table is only required for
** devices that support peripheral pin select (PPS), i.e. PIC32MX1xx/2xx
** devices.
*/

const uint8_t output_compare_to_digital_pin_PGM[] = {
    0,
    PIN_OC1,     
	NOT_PPS_PIN,
	NOT_PPS_PIN,
	NOT_PPS_PIN,
	NOT_PPS_PIN
};

/* ------------------------------------------------------------ */
/* This table maps from an external interrupt number to the digital
** pin for that interrupt.
*/

const uint8_t external_int_to_digital_pin_PGM[] = {
	NOT_PPS_PIN,		// INT0 is not mappable;    RB7
//	PIN_INT1,			// A3, B14, B0, B10, B9;    B9  INT1R = RPB9 = 4
//	PIN_INT2,			// A2, B6, A4, B13, B2;     B2  INT2R = RPB2 = 4
//	PIN_INT3,			// A1, B5, B1, B11, B8;     B8  INT3R = RPB8 = 4
//	PIN_INT4			// A0, B3, B4, B15, B7;     B4  INT4R = RPB4 = 2
};

/* ------------------------------------------------------------ */
/*				Board Customization Functions					*/
/* ------------------------------------------------------------ */
/*																*/
/* The following can be used to customize the behavior of some	*/
/* of the core API functions. These provide hooks that can be	*/
/* used to extend or replace the default behavior of the core	*/
/* functions. To use one of these functions, add the desired	*/
/* code to the function skeleton below and then set the value	*/
/* of the appropriate compile switch above to 1. This will		*/
/* cause the hook function to be compiled into the build and	*/
/* to cause the code to call the hook function to be compiled	*/
/* into the appropriate core function.							*/
/*																*/
/* ------------------------------------------------------------ */
/***	_board_init
**
**	Parameters:
**		none
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		This function is called from the core init() function.
**		This can be used to perform any board specific init
**		that needs to be done when the processor comes out of
**		reset and before the user sketch is run.
*/
#if	(OPT_BOARD_INIT != 0)

void _board_init(void) {

	//	Turn Secondary oscillator off as GPIO is needed
	OSCCONCLR	=	_OSCCON_SOSCEN_MASK;
	
}

#endif

/* ------------------------------------------------------------ */
/***	_board_pinMode
**
**	Parameters:
**		pin		- digital pin number to configure
**		mode	- mode to which the pin should be configured
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the pinMode
**		function. It can perform any special processing needed
**		when setting the pin mode. If this function returns zero,
**		control will pass through the normal pinMode code. If
**		it returns a non-zero value the normal pinMode code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_pinMode(uint8_t pin, uint8_t mode) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_getPinMode
**
**	Parameters:
**		pin		- digital pin number
**		mode	- pointer to variable to receive mode value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the getPinMode
**		function. It can perform any special processing needed
**		when getting the pin mode. If this function returns zero,
**		control will pass through the normal getPinMode code. If
**		it returns a non-zero value the normal getPinMode code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_getPinMode(uint8_t pin, uint8_t * mode) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_digitalWrite
**
**	Parameters:
**		pin		- digital pin number
**		val		- value to write to the pin
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the digitalWrite
**		function. It can perform any special processing needed
**		in writing to the pin. If this function returns zero,
**		control will pass through the normal digitalWrite code. If
**		it returns a non-zero value the normal digitalWrite code isn't
**		executed.
*/#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_digitalWrite(uint8_t pin, uint8_t val) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_digitalRead
**
**	Parameters:
**		pin		- digital pin number
**		val		- pointer to variable to receive pin value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the digitalRead
**		function. It can perform any special processing needed
**		in reading from the pin. If this function returns zero,
**		control will pass through the normal digitalRead code. If
**		it returns a non-zero value the normal digitalRead code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_digitalRead(uint8_t pin, uint8_t * val) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogRead
**
**	Parameters:
**		pin		- analog channel number
**		val		- pointer to variable to receive analog value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogRead
**		function. It can perform any special processing needed
**		in reading from the pin. If this function returns zero,
**		control will pass through the normal analogRead code. If
**		it returns a non-zero value the normal analogRead code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int	_board_analogRead(uint8_t pin, int * val) {

	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogReference
**
**	Parameters:
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogReference
**		function. It can perform any special processing needed
**		to set the reference voltage. If this function returns zero,
**		control will pass through the normal analogReference code. If
**		it returns a non-zero value the normal analogReference code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int	_board_analogReference(uint8_t mode) {

	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogWrite
**
**	Parameters:
**		pin		- pin number
**		val		- analog value to write
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogWrite
**		function. It can perform any special processing needed
**		in writing to the pin. If this function returns zero,
**		control will pass through the normal analogWrite code. If
**		it returns a non-zero value the normal analogWrite code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_WRITE != 0)

int	_board_analogWrite(uint8_t pin, int val) {

	return 0;

}

#endif

#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif	// BOARD_DATA_C

/************************************************************************/
