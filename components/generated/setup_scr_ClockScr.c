/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "../custom/custom.h"



int ClockScr_DigitalClo_min_value = 25;
int ClockScr_DigitalClo_hour_value = 11;
int ClockScr_DigitalClo_sec_value = 50;void setup_scr_ClockScr(lv_ui *ui)
{
	//Write codes ClockScr
	ui->ClockScr = lv_obj_create(NULL);
	lv_obj_set_size(ui->ClockScr, 240, 240);

	//Write style for ClockScr, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ClockScr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ClockScr_BgImg
	ui->ClockScr_BgImg = lv_img_create(ui->ClockScr);
	lv_obj_add_flag(ui->ClockScr_BgImg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->ClockScr_BgImg, &_CSbg_alpha_240x240);
	lv_img_set_pivot(ui->ClockScr_BgImg, 50,50);
	lv_img_set_angle(ui->ClockScr_BgImg, 0);
	lv_obj_set_pos(ui->ClockScr_BgImg, 0, 0);
	lv_obj_set_size(ui->ClockScr_BgImg, 240, 240);

	//Write style for ClockScr_BgImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->ClockScr_BgImg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ClockScr_DigitalClo
	static bool ClockScr_DigitalClo_timer_enabled = false;
	ui->ClockScr_DigitalClo = lv_dclock_create(ui->ClockScr, "11:25");
	if (!ClockScr_DigitalClo_timer_enabled) {
		lv_timer_create(ClockScr_DigitalClo_timer, 1000, NULL);
		ClockScr_DigitalClo_timer_enabled = true;
	}
	lv_obj_set_pos(ui->ClockScr_DigitalClo, 45, 62);
	lv_obj_set_size(ui->ClockScr_DigitalClo, 150, 60);

	//Write style for ClockScr_DigitalClo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->ClockScr_DigitalClo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ClockScr_DigitalClo, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ClockScr_DigitalClo, &lv_font_Acme_Regular_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ClockScr_DigitalClo, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ClockScr_DigitalClo, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ClockScr_DigitalClo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ClockScr_DigitalClo, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ClockScr_DigitalClo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ClockScr_DigitalClo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ClockScr_DigitalClo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ClockScr_DigitalClo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ClockScr_CloScrBtn
	ui->ClockScr_CloScrBtn = lv_btn_create(ui->ClockScr);
	ui->ClockScr_CloScrBtn_label = lv_label_create(ui->ClockScr_CloScrBtn);
	lv_label_set_text(ui->ClockScr_CloScrBtn_label, "");
	lv_label_set_long_mode(ui->ClockScr_CloScrBtn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ClockScr_CloScrBtn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ClockScr_CloScrBtn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->ClockScr_CloScrBtn, 0, 0);
	lv_obj_set_size(ui->ClockScr_CloScrBtn, 240, 240);

	//Write style for ClockScr_CloScrBtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ClockScr_CloScrBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ClockScr_CloScrBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ClockScr_CloScrBtn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ClockScr_CloScrBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ClockScr_CloScrBtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ClockScr_CloScrBtn, &lv_font_Antonio_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ClockScr_CloScrBtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->ClockScr);

	
	//Init events for screen.
	events_init_ClockScr(ui);
}
