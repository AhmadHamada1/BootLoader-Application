

             
#ifndef MRCC_CONFIG_H_
#define MRCC_CONFIG_H_

/*#####################################################################*/
/*
   - Select The Clock Source from The Following Options : 
         1) HSI
		 2) HSE
		 3) PLL
*/

#define   MRCC_CLKSRC       HSI

/*#####################################################################*/


/*#####################################################################*/

/*
   - Select The  Source of HSE from The Following Options : 
         1) HSE_CRYSTAL
		 2) HSE_RC
*/

#define   MRCC_HSE_SRC       HSE_CRYSTAL

/*#####################################################################*/

/*#####################################################################*/

/*
   - Select The  Source of PLL from The Following Options : 
         1) HSE_PLL
		 2) HSI_PLL
*/

#define   MRCC_PLL_SRC       HSE_PLL

/*#####################################################################*/

/*#####################################################################*/
/*
   - Enter The External Clock Frequancy between 4 - 26 MHZ 
*/

#define    MRCC_HSE_FREQANCY       25 

/*#####################################################################*/


/*#####################################################################*/
/*                  THE END OF CONFIGURATION FILE                      */
/*#####################################################################*/

#endif /*MRCC_CONFIG_H_*/
