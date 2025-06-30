/*****************************************************************************
 *  @file    EPD_352_Interface.h
 *  @brief   Header file for EPD_352_Interface.c
 *   This file contains the function prototypes and definitions for interfacing
 *           with the EPD 3.52" display using SPI communication.
 *   @author  Ilyes Gharmoul
 *   @date    2025-06-17
 *   @version 1.0
 *  *  @note    This code is designed for STM32F4 series microcontrollers and uses
 *            the HAL library for hardware abstraction.
 *  ******************************************************************************
*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_spi.h"

#include "../Pilote/PiloteSPI_EPAPER.h"
#include "../Pilote/PiloteSPI.h"
#include "interface_LED3_Orange.h"
#include "interface_LED5_Rouge.h"
#include "EPD_352_Interface.h"
#include "../Service/serviceBaseDeTemps.h"

/**
 * @brief Send Command to the EPD 3.52" display through SPI.
 *
 * @param Reg data to be sent as command.
 */
void EPD_352_SendCommand(uint8_t Reg)
{
    Pilote_DC_EPAPER_metAZero(); // Set DC low to indicate command
    Pilote_CS0_EPAPER_metAZero(); // Set CS low to select the device
    //HAL_SPI_Transmit(&hspi2, &Reg, 1, 1000);
    Pilote_SPI1_Transmit(&Reg, 1);
    Pilote_CS0_EPAPER_metAUn(); // Set CS high to deselect the device
}

/**
 * @brief Send Data to the EPD 3.52" display through SPI.
 *
 * @param Data data to be sent.
 */
void EPD_352_SendData(uint8_t Data)
{
    Pilote_DC_EPAPER_metAUn(); // Set DC high to indicate data
    Pilote_CS0_EPAPER_metAZero(); // Set CS low to select the device
    //HAL_SPI_Transmit(&hspi2, &Data, 1, 1000);
    Pilote_SPI1_Transmit(&Data, 1);
    Pilote_CS0_EPAPER_metAUn(); // Set CS high to deselect the device
}
/**
 * @brief
 *
 */
void EPD_352_refresh(void)
{
    uint8_t busy = 0;
    EPD_352_SendCommand(0x17);
    EPD_352_SendData(0xA5);
    while (!busy)
        busy = HAL_GPIO_ReadPin(BUSY_GPIO_Port, BUSY_Pin);
    HAL_Delay(200);
}
void EPD_3IN52_lut(void)
{
    uint8_t count;
    EPD_352_SendCommand(0x20); // Set vcom
    for (count = 0; count < 42; count++)
    {
        EPD_352_SendData(EPD_3IN52_lut_vcom[count]);
    }
    EPD_352_SendCommand(0x21); // Set ww
    for (count = 0; count < 42; count++)
    {
        EPD_352_SendData(EPD_3IN52_lut_ww[count]);
    }
    EPD_352_SendCommand(0x22); // Set bw r
    for (count = 0; count < 42; count++)
    {
        EPD_352_SendData(EPD_3IN52_lut_bw[count]);
    }
    EPD_352_SendCommand(0x23); // Set wb w
    for (count = 0; count < 42; count++)
    {
        EPD_352_SendData(EPD_3IN52_lut_wb[count]);
    }
    EPD_352_SendCommand(0x24); // Set bb b
    for (count = 0; count < 42; count++)
    {
        EPD_352_SendData(EPD_3IN52_lut_bb[count]);
    }
}
/**
 * @brief
 *
 */
void EPD_352_lut_GC(void)
{
    uint8_t count;
    EPD_352_SendCommand(0x20); // Set vcom
    for (count = 0; count < 56; count++)
    {
        EPD_352_SendData(EPD_3IN52_lut_R20_GC[count]);
    }
    EPD_352_SendCommand(0x21); // red not use
    for (count = 0; count < 42; count++)
    {
        EPD_352_SendData(EPD_3IN52_lut_R21_GC[count]);
    }
    EPD_352_SendCommand(0x24); // Set bb b
    for (count = 0; count < 42; count++)
    {
        EPD_352_SendData(EPD_3IN52_lut_R24_GC[count]);
    }
    if (EPD_352_FLAG == 0)
    {
        EPD_352_SendCommand(0x22); // Set bw r
        for (count = 0; count < 56; count++)
        {
            EPD_352_SendData(EPD_3IN52_lut_R22_GC[count]);
        }
        EPD_352_SendCommand(0x23); // Set wb w
        for (count = 0; count < 42; count++)
        {
            EPD_352_SendData(EPD_3IN52_lut_R23_GC[count]);
        }
        EPD_352_FLAG = 1; // Set flag to indicate that GC LUT has been loaded
    }
    else
    {
        EPD_352_SendCommand(0x22); // Set bw r
        for (count = 0; count < 42; count++)
        {
            EPD_352_SendData(EPD_3IN52_lut_R23_GC[count]);
        }
        EPD_352_SendCommand(0x23); // Set wb w
        for (count = 0; count < 56; count++)
        {
            EPD_352_SendData(EPD_3IN52_lut_R22_GC[count]);
        }
    }
}
/**
 * @brief
 *
 */
void EPD_352_lut_DU(void)
{
    uint8_t count;
    EPD_352_SendCommand(0x20); // Set vcom
    for (count = 0; count < 56; count++)
    {
        EPD_352_SendData(EPD_3IN52_lut_R20_DU[count]);
    }
    EPD_352_SendCommand(0x21); // red not use
    for (count = 0; count < 42; count++)
    {
        EPD_352_SendData(EPD_3IN52_lut_R21_DU[count]);
    }
    EPD_352_SendCommand(0x24); // Set bb b
    for (count = 0; count < 42; count++)
    {
        EPD_352_SendData(EPD_3IN52_lut_R24_DU[count]);
    }
    if (EPD_352_FLAG == 0)
    {
        EPD_352_SendCommand(0x22); // Set bw r
        for (count = 0; count < 56; count++)
        {
            EPD_352_SendData(EPD_3IN52_lut_R22_DU[count]);
        }
        EPD_352_SendCommand(0x23); // Set wb w
        for (count = 0; count < 42; count++)
        {
            EPD_352_SendData(EPD_3IN52_lut_R23_DU[count]);
        }
        EPD_352_FLAG = 1; // Set flag to indicate that DU LUT has been loaded
    }
    else
    {
        EPD_352_SendCommand(0x22); // Set bw r
        for (count = 0; count < 56; count++)
        {
            EPD_352_SendData(EPD_3IN52_lut_R23_DU[count]);
        }
        EPD_352_SendCommand(0x23); // Set wb w
        for (count = 0; count < 42; count++)
        {
            EPD_352_SendData(EPD_3IN52_lut_R22_DU[count]);
        }
    }
}
/**
 * @brief
 *
 */
void EPD_352_Init(void)
{
    EPD_352_Reset(); // Reset the display

    //HAL_GPIO_WritePin(SPI1_SCK_GPIO_Port,SPI1_SCK_Pin,GPIO_PIN_RESET);
    EPD_352_SendCommand(0x00); // SPI INIT
    EPD_352_SendCommand(0x00); // Panel setting
    EPD_352_SendData(0xFF); // 0x0F: 1/7.5, 0x0B: 1/7, 0x0A: 1/6.5, 0x09: 1/6
    EPD_352_SendData(0x01); // 0x0F: 1/7.5, 0x0B: 1/7, 0x0A: 1/6.5, 0x09: 1/6

    EPD_352_SendCommand(0x01); // Power setting
    EPD_352_SendData(0x03); // 0x03: VDS_EN, VDG_EN, VCOM_EN
    EPD_352_SendData(0x10);            //  x x x VCOM_SLWE VGH[3:0]   VGH=20V, VGL=-20V	
    EPD_352_SendData(0x3F);            //  x x VSH[5:0]	VSH = 15V
    EPD_352_SendData(0x3F);            //  x x VSL[5:0]	VSL=-15V
    EPD_352_SendData(0x03);            //  OPTEN VDHR[6:0]  VHDR=6.4V
    // T_VDS_OFF[1:0] 00=1 frame; 01=2 frame; 10=3 frame; 11=4 frame
    EPD_352_SendCommand(0x06);         // booster soft start   BTST 
    EPD_352_SendData(0x37);            //  BT_PHA[7:0]  	
    EPD_352_SendData(0x3D);            //  BT_PHB[7:0]	
    EPD_352_SendData(0x3D);            //  x x BT_PHC[5:0]	

    EPD_352_SendCommand(0x60);         // TCON setting			TCON 
    EPD_352_SendData(0x22);            // S2G[3:0] G2S[3:0]   non-overlap = 12		

    EPD_352_SendCommand(0x82);         // VCOM_DC setting		VDCS 
    EPD_352_SendData(0x07);            // x  VDCS[6:0]	VCOM_DC value= -1.9v    00~3f,0x12=-1.9v

    EPD_352_SendCommand(0x30);
    EPD_352_SendData(0x09);

    EPD_352_SendCommand(0xe3);         // power saving			PWS 
    EPD_352_SendData(0x88);            // VCOM_W[3:0] SD_W[3:0]

    EPD_352_SendCommand(0x61);         // resoultion setting 
    EPD_352_SendData(0xf0);            //  HRES[7:3] 0 0 0	
    EPD_352_SendData(0x01);            //  x x x x x x x VRES[8]	
    EPD_352_SendData(0x68);            //  VRES[7:0]

    EPD_352_SendCommand(0x50);
    EPD_352_SendData(0xB7);
}
/**
 * @brief
 *
 * @param picData
 */
void EPD_352_display(uint8_t* picData)
{
    uint16_t i;
    EPD_352_SendCommand(0x13);		     //Transfer new data
    for (i = 0;i < (EPD_3IN52_WIDTH * EPD_3IN52_HEIGHT / 8);i++)
    {
        EPD_352_SendData(*picData);
        picData++;
    }
}
/**
 * @brief
 *
 * @param NUM
 */
void EPD_352_display_NUM(uint8_t NUM)
{
    uint16_t row, column;
    EPD_352_SendCommand(0x13);
    for (column = 0; column < EPD_3IN52_HEIGHT; column++)
    {
        for (row = 0; row < EPD_3IN52_WIDTH; row++)
        {
            switch (NUM)
            {
            case EPD_3IN52_WHITE:
                EPD_352_SendData(0xFF);
                break;

            case EPD_3IN52_BLACK:
                EPD_352_SendData(0x00);
                break;

            case EPD_3IN52_Source_Line:
                EPD_352_SendData(0xAA);
                break;

            case EPD_3IN52_Gate_Line:
                if (column % 2)
                    EPD_352_SendData(0xff); //An odd number of Gate line  
                else
                    EPD_352_SendData(0x00); //The even line Gate  
                break;

            case EPD_3IN52_Chessboard:
                if (row >= (EPD_3IN52_WIDTH / 8 / 2) && column >= (EPD_3IN52_HEIGHT / 2))
                    EPD_352_SendData(0xff);
                else if (row < (EPD_3IN52_WIDTH / 8 / 2) && column < (EPD_3IN52_HEIGHT / 2))
                    EPD_352_SendData(0xff);
                else
                    EPD_352_SendData(0x00);
                break;

            case EPD_3IN52_LEFT_BLACK_RIGHT_WHITE:
                if (row >= (EPD_3IN52_WIDTH / 8 / 2))
                    EPD_352_SendData(0xff);
                else
                    EPD_352_SendData(0x00);
                break;

            case EPD_3IN52_UP_BLACK_DOWN_WHITE:
                if (column >= (EPD_3IN52_HEIGHT / 2))
                    EPD_352_SendData(0xFF);
                else
                    EPD_352_SendData(0x00);
                break;

            case EPD_3IN52_Frame:
                if (column == 0 || column == (EPD_3IN52_HEIGHT - 1))
                    EPD_352_SendData(0x00);
                else if (row == 0)
                    EPD_352_SendData(0x7F);
                else if (row == (EPD_3IN52_WIDTH / 8 - 1))
                    EPD_352_SendData(0xFE);
                else
                    EPD_352_SendData(0xFF);
                break;

            case EPD_3IN52_Crosstalk:
                if ((row >= (EPD_3IN52_WIDTH / 8 / 3) && row <= (EPD_3IN52_WIDTH / 8 / 3 * 2) && column <= (EPD_3IN52_HEIGHT / 3)) || (row >= (EPD_3IN52_WIDTH / 8 / 3) && row <= (EPD_3IN52_WIDTH / 8 / 3 * 2) && column >= (EPD_3IN52_HEIGHT / 3 * 2)))
                    EPD_352_SendData(0x00);
                else
                    EPD_352_SendData(0xFF);
                break;

            case EPD_3IN52_Image:
                //EPD_3IN52_SendData(gImage_1[pcnt++]);
                break;

            default:
                break;
            }
        }
    }
}
/**
 * @brief
 *
 */
void EPD_352_Clear(void)
{
    uint32_t i;
    EPD_352_SendCommand(0x13); // Transfer new data
    for (i = 0; i < (EPD_3IN52_WIDTH * EPD_3IN52_HEIGHT / 8); i++)
    {
        EPD_352_SendData(0xFF);
    }
    EPD_352_lut_GC();
    EPD_352_refresh();
}
/**
 * @brief
 *
 */
void EPD_352_sleep(void)
{
    EPD_352_SendCommand(0x07);   // deep sleep
    EPD_352_SendData(0xA5);
}
/**
 * @brief Reset the EPD 3.52" display.
 *
 */
void EPD_352_Reset(void)
{
    Pilote_RST_EPAPER_metAUn(); // Set RST high to reset the display
    HAL_Delay(200);
    Pilote_RST_EPAPER_metAZero();
    HAL_Delay(1);
    Pilote_RST_EPAPER_metAUn();
    HAL_Delay(200);
}
INTERFACEEPD interfaceEPD;
void interfaceEPD_initialise(void)
{

    interfaceEPD.compteur = 0;
    interfaceEPD.etatDuBusy = INTERFACEEPD_NOT_BUSY;
    interfaceEPD.etatDuRst = INTERFACEEPD_NOT_RST;
    interfaceEPD.etatDuDelai = INTERFACEEPD_DELAI_ATTEIND;
    interfaceEPD.request = INTERFACEEPD_REQUEST_NONE;
    serviceBaseDeTemps_execute[INTERFACEEPD_PHASE] = interfaceEPD_first_rst;

}

void interfaceEPD_first_rst(void)
{
	if (interfaceEPD.request != INTERFACEEPD_REQUEST_INITIALISE)
	{
		interface_LED5_Rouge_eteint();
		return;
	}
    // Set RST high to reset the display
	interface_LED5_Rouge_allume();
	Pilote_RST_EPAPER_metAUn();
    serviceBaseDeTemps_execute[INTERFACEEPD_PHASE] = interfaceEPD_Delay200_MS;
    return;
}


void interfaceEPD_Delay200_MS(void)
{
	interfaceEPD.compteur++;
	if(interfaceEPD.compteur < INTERFACEEPD_TEMPS_RST_MS)
		return;
	interfaceEPD.compteur = 0;
	Pilote_RST_EPAPER_metAZero();
	serviceBaseDeTemps_execute[INTERFACEEPD_PHASE] = interfaceEPD_Delay2_MS;
	return;
}

void interfaceEPD_Delay2_MS(void)
{
	interfaceEPD.compteur++;
	if (interfaceEPD.compteur < INTERFACEEPD_COMPTE_1_MS)
	{
		return;
	}
	interfaceEPD.compteur =0;
	Pilote_RST_EPAPER_metAUn();
	interface_LED5_Rouge_eteint();
	serviceBaseDeTemps_execute[INTERFACEEPD_PHASE] = interface_delay_safetycooldown;
	interfaceEPD.request = INTERFACEEPD_REQUEST_NONE;
	return;
}
void interface_delay_safetycooldown(void)
{
	interfaceEPD.compteur++;
	if(interfaceEPD.compteur < INTERFACEEPD_TEMPS_RST_MS)
		return;
	interfaceEPD.compteur = 0;
	serviceBaseDeTemps_execute[INTERFACEEPD_PHASE] = interfaceEPD_gere;
	interface_LED5_Rouge_allume();
}
void interfaceEPD_gere(void)
{

}
