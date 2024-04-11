/*
 * app.h
 *
 *  Created on: April 1, 2024
 *      Author: Hamada
 */

#ifndef ADISPLAY_INTERFACE_H_
#define ADISPLAY_INTERFACE_H_
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"
#include "MSTK_Interface.h"
#include "MGPIO_Interface.h"
#include "MSPI_Interface.h"
#include "HTFT_Interface.h"

#define APP_VALUE_0			0U
#define APP_VALUE_1			1U
#define APP_VALUE_3			3U


/*initialization function for the whole application*/
void ADisplay_Init(void);
/*the function to run the application*/
void ADisplay_DisplayRun(void);







#endif /* ADISPLAY_INTERFACE_H_ */
