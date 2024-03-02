/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *AppScr;
	bool AppScr_del;
	lv_obj_t *AppScr_AppCarousel;
	lv_obj_t *AppScr_AppCarousel_Clock;
	lv_obj_t *AppScr_AppCarousel_Message;
	lv_obj_t *AppScr_AppCarousel_Setting;
	lv_obj_t *AppScr_CloImgBtn;
	lv_obj_t *AppScr_CloImgBtn_label;
	lv_obj_t *AppScr_MsgImgBtn;
	lv_obj_t *AppScr_MsgImgBtn_label;
	lv_obj_t *AppScr_SetImgBtn;
	lv_obj_t *AppScr_SetImgBtn_label;
	lv_obj_t *ClockScr;
	bool ClockScr_del;
	lv_obj_t *ClockScr_BgImg;
	lv_obj_t *ClockScr_DigitalClo;
	lv_obj_t *ClockScr_CloScrBtn;
	lv_obj_t *ClockScr_CloScrBtn_label;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_AppScr(lv_ui *ui);
void setup_scr_ClockScr(lv_ui *ui);
LV_IMG_DECLARE(_Clock_alpha_160x160);
LV_IMG_DECLARE(_NoMsg_alpha_160x160);
LV_IMG_DECLARE(_Setting_alpha_160x160);
LV_IMG_DECLARE(_CSbg_alpha_240x240);

LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_Acme_Regular_50)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_Antonio_Regular_16)


#ifdef __cplusplus
}
#endif
#endif
