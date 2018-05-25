#ifndef __ST7735_H__
#define __ST7735_H__

#include <string.h>
#include "font5x7.h"
#include "font7x11.h"
#include "color565.h"
#include "stm32f0xx_hal.h"

// Screen resolution in normal orientation
#define scr_w         128
#define scr_h         160

// ST7735 A0 (Data/Command select) pin

#define ST7735_DC_PORT       GPIOC
#define ST7735_DC_PIN        GPIO_PIN_3

// ST7735 RST (Reset) pin

#define ST7735_RST_PORT      GPIOF
#define ST7735_RST_PIN       GPIO_PIN_5

// ST7735 CS (Chip Select) pin

#define ST7735_CS_PORT       GPIOB
#define ST7735_CS_PIN        GPIO_PIN_0

// CS pin macros

#define CS_L() HAL_GPIO_WritePin(ST7735_CS_PORT,ST7735_CS_PIN,0)
#define CS_H() HAL_GPIO_WritePin(ST7735_CS_PORT,ST7735_CS_PIN,1)
//#define CS_L() GPIO_ResetBits(ST7735_CS_PORT,ST7735_CS_PIN)
//#define CS_H() GPIO_SetBits(ST7735_CS_PORT,ST7735_CS_PIN)

// A0 pin macros
#define DC_L() HAL_GPIO_WritePin(ST7735_DC_PORT,ST7735_DC_PIN,0)
#define DC_H() HAL_GPIO_WritePin(ST7735_DC_PORT,ST7735_DC_PIN,1)
//#define A0_L() GPIO_ResetBits(ST7735_A0_PORT,ST7735_A0_PIN)
//#define A0_H() GPIO_SetBits(ST7735_A0_PORT,ST7735_A0_PIN)

// RESET pin macros
#define RST_L() HAL_GPIO_WritePin(ST7735_RST_PORT,ST7735_RST_PIN,0)
#define RST_H() HAL_GPIO_WritePin(ST7735_RST_PORT,ST7735_RST_PIN,1)
//#define RST_L() GPIO_ResetBits(ST7735_RST_PORT,ST7735_RST_PIN)
//#define RST_H() GPIO_SetBits(ST7735_RST_PORT,ST7735_RST_PIN)

// Colors for spaces between symbols for debug view
//#define V_SEP COLOR565_YELLOW
//#define H_SEP COLOR565_SIENNA
//#define V_SEP COLOR565_WHITE
//#define H_SEP COLOR565_WHITE

typedef enum
{
  scr_normal = 0,
  scr_CW     = 1,
  scr_CCW    = 2,
  scr_180    = 3
} ScrOrientation_TypeDef;

extern uint16_t scr_width;
extern uint16_t scr_height;

uint16_t RGB565(uint8_t R,uint8_t G,uint8_t B);
void ST7735_write(uint8_t data);
void ST7735_Init(void);
void ST7735_AddrSet(uint16_t XS, uint16_t YS, uint16_t XE, uint16_t YE);
void ST7735_Orientation(uint8_t orientation);
void ST7735_Clear(uint16_t color);
void ST7735_Pixel(uint16_t X, uint16_t Y, uint16_t color);
void ST7735_HLine(uint16_t X1, uint16_t X2, uint16_t Y, uint16_t color);
void ST7735_VLine(uint16_t X, uint16_t Y1, uint16_t Y2, uint16_t color);
void ST7735_Line(int16_t X1, int16_t Y1, int16_t X2, int16_t Y2, uint16_t color);
void ST7735_Rect(uint16_t X1, uint16_t Y1, uint16_t X2, uint16_t Y2, uint16_t color);
void ST7735_FillRect(uint16_t X1, uint16_t Y1, uint16_t X2, uint16_t Y2, uint16_t color);
void ST7735_PutChar5x7(uint8_t scale, uint16_t X, uint16_t Y, uint8_t chr, uint16_t color, uint16_t bgcolor);
void ST7735_PutStr5x7(uint8_t scale, uint8_t X, uint8_t Y, char *str, uint16_t color, uint16_t bgcolor);
void ST7735_PutChar7x11(uint16_t X, uint16_t Y, uint8_t chr, uint16_t color, uint16_t bgcolor);
void ST7735_PutStr7x11(uint8_t X, uint8_t Y, char *str, uint16_t color, uint16_t bgcolor);
void ST7735_Wake(void);
void ST7735_Sleep(void);

#endif
