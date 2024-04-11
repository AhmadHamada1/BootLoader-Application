/*
 * MFDI_Interface.h
 *
 *  Created on: April 1, 2024
 *      Author: Hamada
 */

#ifndef MFDI_INTERFACE_H_
#define MFDI_INTERFACE_H_

#define START_OF_SECTOR_1	0x08004000
#define RESET_HANDLER_ISR	0x08004004

void MFDI_voidEraseAppArea(void) ;
void MFDI_voidFlashWrite(u32 Copy_u32Address ,u16* Copy_PtrData, u8 Copy_u8DataLength) ;
void MFDI_voidSectorErase(u8 Copy_u8SectorNumber) ;



#endif /* MFDI_INTERFACE_H_ */
