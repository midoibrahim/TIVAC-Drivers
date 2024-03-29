/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Dio.h>
 *       Module:  -
 *
 *  Description:  <this file contains all defines for DIO Driver>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include <stdint.h> 
# include "Port.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

struct Dio_PinType
{
   Port_PortType port ;
	 uint8_t pin; 				//pin number 
};

typedef enum
{
	DIO_PIN_LOW,
	DIO_PIN_HIGH
}Dio_LevelType;

typedef uint32_t Dio_PortLevelType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
Dio_LevelType Dio_ReadChannel(struct Dio_PinType PinId);
void Dio_WriteChannel(struct Dio_PinType PinId,Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort(Port_PortType PortId);
void Dio_WritePort(Port_PortType PortId, Dio_LevelType Level);
Dio_LevelType Dio_FlipChannel(struct Dio_PinType PinId); 
 
#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
