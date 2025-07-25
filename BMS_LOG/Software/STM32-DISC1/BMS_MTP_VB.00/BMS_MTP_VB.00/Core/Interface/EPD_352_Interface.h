/*
 * EPD_352_Interface.h
 *
 *  Created on: Jun 17, 2025
 *      Author: Ilyes Gharmoul
 */

#ifndef INC_EPD_352_INTERFACE_H_
#define INC_EPD_352_INTERFACE_H_

#include <stdint.h>

#define EPD_3IN52_WHITE                         0xFF
#define EPD_3IN52_BLACK                         0x00
#define EPD_3IN52_Source_Line                   0xAA
#define EPD_3IN52_Gate_Line                     0x55
#define EPD_3IN52_UP_BLACK_DOWN_WHITE           0xF0
#define EPD_3IN52_LEFT_BLACK_RIGHT_WHITE        0x0F
#define EPD_3IN52_Frame                         0x01
#define EPD_3IN52_Crosstalk                     0x02
#define EPD_3IN52_Chessboard                    0x03
#define EPD_3IN52_Image                         0x04

void EPD_352_SendCommand(uint8_t Reg);
void EPD_352_SendData(uint8_t Data);
void EPD_352_refresh(void);
void EPD_3IN52_lut(void);
void EPD_352_lut_GC(void);
void EPD_352_lut_DU(void);
void EPD_352_Init(void);
void EPD_352_display(uint8_t* picData);
void EPD_352_display_NUM(uint8_t NUM);
void EPD_352_Clear(void);
void EPD_352_sleep(void);
void EPD_352_Reset(void);

// New interface functions
void interfaceEPD_initialise(void);
void interfaceEPD_gere(void);
void interfaceEPD_rst(void);
void interfaceEPD_refresh(void);
void interfaceEPD_refresh_2(void);

void interfaceEPD_Delay200_MS(void);
void interfaceEPD_Delay2_MS(void);
void interface_delay_safetycooldown(void);


#define INTERFACEEPD_INCONNU 0
#define INTERFACEEPD_IS_BUSY  2
#define INTERFACEEPD_NOT_BUSY  1
#define INTERFACEEPD_NOT_RST 1
#define INTERFACEEPD_IS_RST 2
#define INTERFACEEPD_DELAI_ATTEIND 0
#define INTERFACEEPD_DELAI_ENCOURS 1
#define INTERFACEEPD_REQUEST_NONE 0
#define INTERFACEEPD_REQUEST_RESET 1
#define INTERFACEEPD_REQUEST_REFRESH 2
#define INTERFACEEPD_REQUEST_INITIALISE 3


typedef struct
{
  unsigned int compteur;
  unsigned int etatDuDelai;
  unsigned int etatDuBusy;
  unsigned int etatDuRst;
  unsigned int request;
} INTERFACEEPD;

extern unsigned char EPD_352_FLAG;
extern INTERFACEEPD interfaceEPD;

static const uint8_t EPD_3IN52_lut_R20_GC[] =
{
  0x01,0x0f,0x0f,0x0f,0x01,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};							  
static const uint8_t EPD_3IN52_lut_R21_GC[] =
{
  0x01,0x4f,0x8f,0x0f,0x01,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};						 
static const uint8_t EPD_3IN52_lut_R22_GC[] =
{
  0x01,0x0f,0x8f,0x0f,0x01,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
static const uint8_t EPD_3IN52_lut_R23_GC[] =
{
  0x01,0x4f,0x8f,0x4f,0x01,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
static const uint8_t EPD_3IN52_lut_R24_GC[] =
{
  0x01,0x0f,0x8f,0x4f,0x01,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};


// DU 0.3s
static const uint8_t EPD_3IN52_lut_R20_DU[] =
{
  0x01,0x0f,0x01,0x00,0x00,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};							  
static const uint8_t EPD_3IN52_lut_R21_DU[] =
{
  0x01,0x0f,0x01,0x00,0x00,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};						 
static const uint8_t EPD_3IN52_lut_R22_DU[] =
{
  0x01,0x8f,0x01,0x00,0x00,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
static const uint8_t EPD_3IN52_lut_R23_DU[] =
{
  0x01,0x4f,0x01,0x00,0x00,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
static const uint8_t EPD_3IN52_lut_R24_DU[] =
{
  0x01,0x0f,0x01,0x00,0x00,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

// 
static const uint8_t EPD_3IN52_lut_vcom[] =
{
  0x01,0x19,0x19,0x19,0x19,0x01,0x01,
  0x01,0x19,0x19,0x19,0x01,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

static const uint8_t EPD_3IN52_lut_ww[] =
{
  0x01,0x59,0x99,0x59,0x99,0x01,0x01,
  0x01,0x59,0x99,0x19,0x01,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00

};

static const uint8_t EPD_3IN52_lut_bw[] =
{
  0x01,0x59,0x99,0x59,0x99,0x01,0x01,
  0x01,0x59,0x99,0x19,0x01,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

static const uint8_t EPD_3IN52_lut_wb[] =
{	
  0x01,0x19,0x99,0x59,0x99,0x01,0x01,
  0x01,0x59,0x99,0x59,0x01,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

static const uint8_t EPD_3IN52_lut_bb[] =
{
  0x01,0x19,0x99,0x59,0x99,0x01,0x01,
  0x01,0x59,0x99,0x59,0x01,0x01,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
#endif /* INC_EPD_352_INTERFACE_H_ */
