/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Port.h>
 *       Module:  -
 *
 *  Description:  <contains all the references for port driver>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include <stdint.h> 

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

//**************GPIO REGISTERS OFFSET ****************************************** 
#define PORT_GPIO_DATA             0x000003FC
#define PORT_GPIO_DIR              0x00000400
#define PORT_GPIO_DEN              0x0000051C
#define PORT_GPIO_PUR              0x00000510
#define PORT_GPIO_LOCK             0x00000520
#define PORT_GPIO_CR               0x00000524
#define PORT_GPIO_AFSEL            0x00000420 
#define PORT_GPIO_AMSEL            0x00000528 

//***************GPIO CLOCK ENABLE VALUE ***************************************
#define CLOCK(PORTA)              0x1
#define CLOCK(PORTB)              0X2
#define CLOCK(PORTC)              0x4
#define CLOCK(PORTD)              0x8
#define CLOCK(PORTE)              0x10
#define CLOCK(PORTF)              0x20

#define LOCK 				0x4C4F434B

#define Port_PinMode_DIO             0
#define Port_PinMode_PA0_U0RX        1
#define Port_PinMode_PA1_U0TX        1
#define Port_PinMode_PA2_SSI0Clk     2

//*********TIVA LEDS DIRECTION AS OUTPUT VALUE***********************************
#define LED_OUTPUT 0x0e

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8_t Port_PinModeType;

typedef enum
{
// ***************GPIO PORTS BASE ADDRESSES***********************	
	PORTA = 0x40004000,
	PORTB = 0x40005000,
  PORTC = 0x40006000,
	PORTD = 0x40007000,
	PORTE = 0x40024000,
	PORTF = 0x40025000
}Port_PortType;

typedef enum
{
	PORT_PIN_0 = 0x00000001,  // GPIO pin 0
	PORT_PIN_1 = 0x00000002,  // GPIO pin 1
	PORT_PIN_2 = 0x00000004,  // GPIO pin 2
	PORT_PIN_3 = 0x00000008,  // GPIO pin 3
	PORT_PIN_4 = 0x00000010,  // GPIO pin 4
	PORT_PIN_5 = 0x00000020,  // GPIO pin 5
	PORT_PIN_6 = 0x00000040,  // GPIO pin 6
	PORT_PIN_7 = 0x00000080   // GPIO pin 7
}Port_PinType;

typedef enum
{
	PORT_PIN_DIR_IN,	// Pin is a GPIO input
	PORT_PIN_DIR_OUT,	// Pin is a GPIO output
	PORT_PIN_DIR_HW		// Pin is a peripheral function
	
}Port_PinDirectionType;

typedef enum
{
	
PORT_PIN_ATTACH_STD       =  0x00000008,  // Push-pull
PORT_PIN_ATTACH_STD_WPU   =  0x0000000A,  // Push-pull with weak pull-up
PORT_PIN_ATTACH_STD_WPD   =  0x0000000C,  // Push-pull with weak pull-down
PORT_PIN_ATTACH_OD        =  0x00000009,  // Open-drain
PORT_PIN_ATTACH_ANALOG    =  0x00000000,  // Analog comparator
PORT_PIN_ATTACH_WAKE_HIGH =  0x00000208,  // Hibernate wake, high
PORT_PIN_ATTACH_WAKE_LOW  =  0x00000108,  // Hibernate wake, low
	
}Port_PinInternalAttachType;

typedef enum 
{
	PORT_PIN_CURRENT_2MA   =    0x00000001,  // 2mA drive CURRENT
	PORT_PIN_CURRENT_4MA     =  0x00000002,  // 4mA drive CURRENT
	PORT_PIN_CURRENT_6MA     =  0x00000065,  // 6mA drive CURRENT
	PORT_PIN_CURRENT_8MA     =  0x00000066,  // 8mA drive CURRENT
	PORT_PIN_CURRENT_8MA_SC  =  0x0000006E,  // 8mA drive with slew rate control
	PORT_PIN_CURRENT_10MA    =  0x00000075,  // 10mA drive strength
	PORT_PIN_CURRENT_12MA    =  0x00000077,  // 12mA drive strength

}Port_PinOutputCurrentType;

typedef struct
{
	Port_PortType								portId;
  Port_PinType                pinId;
	Port_PinDirectionType       pinDir;
	Port_PinModeType            pinMode;
	Port_PinOutputCurrentType   currentStrength;
	Port_PinInternalAttachType  internalAttach;
}Port_ConfigType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Port_Init ( const Port_ConfigType* ConfigPtr ); 
 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/
