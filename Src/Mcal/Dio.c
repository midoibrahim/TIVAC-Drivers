/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"
#include "Port.h"
#include "Std_Types.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel (struct Dio_PinType PinId)        
* \Description     : used to read value on a pin                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PinId   struct containing port address and pin number                     
* \Parameters (out): None                                                      
* \Return value:   : Pin Value
*                                                                      
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(struct Dio_PinType PinId){

	return(STD_PIN_READ(STD_DEREF(PinId.port + PORT_GPIO_DATA),PinId.pin));
}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel (struct Dio_PinType PinId,Dio_LevelType Level)        
* \Description     : used to write value on a pin                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PinId   struct containing port address and pin number
										 Level   Value to write on pin
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                      
*******************************************************************************/
void Dio_WriteChannel(struct Dio_PinType PinId,Dio_LevelType Level){
	if (Level == STD_HIGH)
		{
	STD_DEREF(PinId.port + STD_PIN_Offset(PinId.pin))= Level;
	}
	else if( Level == STD_LOW)
		{
	STD_PIN_CLR(STD_DEREF(PinId.port + STD_PIN_Offset(PinId.pin)),PinId.pin);
	}
}

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)        
* \Description     : used to read value of a port                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PinId   struct containing port address and pin number                     
* \Parameters (out): None                                                      
* \Return value:   : Port Level
*                                                                      
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Port_PortType PortId)
{
	return(STD_DEREF((PortId + PORT_GPIO_DATA)));
}

/******************************************************************************
* \Syntax          : void Dio_WritePort (Dio_PortType PortId, Dio_LevelType Level)        
* \Description     : used to write value on a port                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PinId   struct containing port address and pin number
										 Level   Value to write on port                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                      
*******************************************************************************/
void Dio_WritePort(Port_PortType PortId, Dio_LevelType Level){

	STD_SET(STD_DEREF(PortId + PORT_GPIO_DATA),Level);

}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel (struct Dio_PinType PinId)       
* \Description     : used to flip value of a pin                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PinId   struct containing port address and pin number                     
* \Parameters (out): None                                                      
* \Return value:   : Pin Value
*                                                                      
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(struct Dio_PinType PinId){

STD_PIN_FLIP(STD_DEREF(PinId.port + STD_PIN_Offset(PinId.pin)),PinId.pin);
	
return(STD_PIN_READ(STD_DEREF(PinId.port + PORT_GPIO_DATA),PinId.pin));
} 

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
