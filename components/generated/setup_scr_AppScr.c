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

void setup_scr_AppScr(lv_ui *ui)
{
	// Write codes AppScr
	ui->AppScr = lv_obj_create(NULL);
	lv_obj_set_size(ui->AppScr, 240, 240);

	// Write style for AppScr, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->AppScr, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write codes AppScr_AppCarousel
	ui->AppScr_AppCarousel = lv_carousel_create(ui->AppScr);
	lv_carousel_set_element_width(ui->AppScr_AppCarousel, 160);
	lv_obj_set_size(ui->AppScr_AppCarousel, 240, 240);
	ui->AppScr_AppCarousel_Clock = lv_carousel_add_element(ui->AppScr_AppCarousel, 0);
	ui->AppScr_AppCarousel_Message = lv_carousel_add_element(ui->AppScr_AppCarousel, 1);
	ui->AppScr_AppCarousel_Setting = lv_carousel_add_element(ui->AppScr_AppCarousel, 2);
	lv_obj_set_pos(ui->AppScr_AppCarousel, 0, 0);
	lv_obj_set_size(ui->AppScr_AppCarousel, 240, 240);
	lv_obj_set_scrollbar_mode(ui->AppScr_AppCarousel, LV_SCROLLBAR_MODE_OFF);

	// Write style for AppScr_AppCarousel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->AppScr_AppCarousel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->AppScr_AppCarousel, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->AppScr_AppCarousel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->AppScr_AppCarousel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style for AppScr_AppCarousel, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->AppScr_AppCarousel, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->AppScr_AppCarousel, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_DEFAULT for &style_AppScr_AppCarousel_extra_element_items_default
	static lv_style_t style_AppScr_AppCarousel_extra_element_items_default;
	ui_init_style(&style_AppScr_AppCarousel_extra_element_items_default);

	lv_style_set_bg_opa(&style_AppScr_AppCarousel_extra_element_items_default, 0);
	lv_style_set_outline_width(&style_AppScr_AppCarousel_extra_element_items_default, 0);
	lv_style_set_border_width(&style_AppScr_AppCarousel_extra_element_items_default, 0);
	lv_style_set_radius(&style_AppScr_AppCarousel_extra_element_items_default, 5);
	lv_style_set_shadow_width(&style_AppScr_AppCarousel_extra_element_items_default, 0);
	lv_obj_add_style(ui->AppScr_AppCarousel_Setting, &style_AppScr_AppCarousel_extra_element_items_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->AppScr_AppCarousel_Message, &style_AppScr_AppCarousel_extra_element_items_default, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_style(ui->AppScr_AppCarousel_Clock, &style_AppScr_AppCarousel_extra_element_items_default, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style state: LV_STATE_FOCUSED for &style_AppScr_AppCarousel_extra_element_items_focused
	static lv_style_t style_AppScr_AppCarousel_extra_element_items_focused;
	ui_init_style(&style_AppScr_AppCarousel_extra_element_items_focused);

	lv_style_set_bg_opa(&style_AppScr_AppCarousel_extra_element_items_focused, 0);
	lv_style_set_outline_width(&style_AppScr_AppCarousel_extra_element_items_focused, 0);
	lv_style_set_border_width(&style_AppScr_AppCarousel_extra_element_items_focused, 0);
	lv_style_set_radius(&style_AppScr_AppCarousel_extra_element_items_focused, 5);
	lv_style_set_shadow_width(&style_AppScr_AppCarousel_extra_element_items_focused, 0);
	lv_obj_add_style(ui->AppScr_AppCarousel_Setting, &style_AppScr_AppCarousel_extra_element_items_focused, LV_PART_MAIN | LV_STATE_FOCUSED);
	lv_obj_add_style(ui->AppScr_AppCarousel_Message, &style_AppScr_AppCarousel_extra_element_items_focused, LV_PART_MAIN | LV_STATE_FOCUSED);
	lv_obj_add_style(ui->AppScr_AppCarousel_Clock, &style_AppScr_AppCarousel_extra_element_items_focused, LV_PART_MAIN | LV_STATE_FOCUSED);

	// Write codes AppScr_CloImgBtn
	ui->AppScr_CloImgBtn = lv_imgbtn_create(ui->AppScr_AppCarousel_Clock);
	lv_obj_add_flag(ui->AppScr_CloImgBtn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->AppScr_CloImgBtn, LV_IMGBTN_STATE_RELEASED, NULL, &_Clock_alpha_160x160, NULL);
	ui->AppScr_CloImgBtn_label = lv_label_create(ui->AppScr_CloImgBtn);
	lv_label_set_text(ui->AppScr_CloImgBtn_label, "");
	lv_label_set_long_mode(ui->AppScr_CloImgBtn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->AppScr_CloImgBtn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->AppScr_CloImgBtn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->AppScr_CloImgBtn, 0, 40);
	lv_obj_set_size(ui->AppScr_CloImgBtn, 160, 160);

	// Write style for AppScr_CloImgBtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->AppScr_CloImgBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->AppScr_CloImgBtn, &lv_font_montserratMedium_12, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->AppScr_CloImgBtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->AppScr_CloImgBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style for AppScr_CloImgBtn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->AppScr_CloImgBtn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->AppScr_CloImgBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->AppScr_CloImgBtn, &lv_font_montserratMedium_12, LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->AppScr_CloImgBtn, 0, LV_PART_MAIN | LV_STATE_PRESSED);

	// Write style for AppScr_CloImgBtn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->AppScr_CloImgBtn, 255, LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->AppScr_CloImgBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->AppScr_CloImgBtn, &lv_font_montserratMedium_12, LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->AppScr_CloImgBtn, 0, LV_PART_MAIN | LV_STATE_CHECKED);

	// Write style for AppScr_CloImgBtn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->AppScr_CloImgBtn, 255, LV_PART_MAIN | LV_IMGBTN_STATE_RELEASED);

	// Write codes AppScr_MsgImgBtn
	ui->AppScr_MsgImgBtn = lv_imgbtn_create(ui->AppScr_AppCarousel_Message);
	lv_obj_add_flag(ui->AppScr_MsgImgBtn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->AppScr_MsgImgBtn, LV_IMGBTN_STATE_RELEASED, NULL, &_NoMsg_alpha_160x160, NULL);
	ui->AppScr_MsgImgBtn_label = lv_label_create(ui->AppScr_MsgImgBtn);
	lv_label_set_text(ui->AppScr_MsgImgBtn_label, "");
	lv_label_set_long_mode(ui->AppScr_MsgImgBtn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->AppScr_MsgImgBtn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->AppScr_MsgImgBtn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->AppScr_MsgImgBtn, 0, 40);
	lv_obj_set_size(ui->AppScr_MsgImgBtn, 160, 160);

	// Write style for AppScr_MsgImgBtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->AppScr_MsgImgBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->AppScr_MsgImgBtn, &lv_font_montserratMedium_12, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->AppScr_MsgImgBtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->AppScr_MsgImgBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style for AppScr_MsgImgBtn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->AppScr_MsgImgBtn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->AppScr_MsgImgBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->AppScr_MsgImgBtn, &lv_font_montserratMedium_12, LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->AppScr_MsgImgBtn, 0, LV_PART_MAIN | LV_STATE_PRESSED);

	// Write style for AppScr_MsgImgBtn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->AppScr_MsgImgBtn, 255, LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->AppScr_MsgImgBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->AppScr_MsgImgBtn, &lv_font_montserratMedium_12, LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->AppScr_MsgImgBtn, 0, LV_PART_MAIN | LV_STATE_CHECKED);

	// Write style for AppScr_MsgImgBtn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->AppScr_MsgImgBtn, 255, LV_PART_MAIN | LV_IMGBTN_STATE_RELEASED);

	// Write codes AppScr_SetImgBtn
	ui->AppScr_SetImgBtn = lv_imgbtn_create(ui->AppScr_AppCarousel_Setting);
	lv_obj_add_flag(ui->AppScr_SetImgBtn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->AppScr_SetImgBtn, LV_IMGBTN_STATE_RELEASED, NULL, &_Setting_alpha_160x160, NULL);
	ui->AppScr_SetImgBtn_label = lv_label_create(ui->AppScr_SetImgBtn);
	lv_label_set_text(ui->AppScr_SetImgBtn_label, "");
	lv_label_set_long_mode(ui->AppScr_SetImgBtn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->AppScr_SetImgBtn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->AppScr_SetImgBtn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->AppScr_SetImgBtn, 0, 39);
	lv_obj_set_size(ui->AppScr_SetImgBtn, 160, 160);

	// Write style for AppScr_SetImgBtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->AppScr_SetImgBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->AppScr_SetImgBtn, &lv_font_montserratMedium_12, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->AppScr_SetImgBtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->AppScr_SetImgBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Write style for AppScr_SetImgBtn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->AppScr_SetImgBtn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->AppScr_SetImgBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->AppScr_SetImgBtn, &lv_font_montserratMedium_12, LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->AppScr_SetImgBtn, 0, LV_PART_MAIN | LV_STATE_PRESSED);

	// Write style for AppScr_SetImgBtn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->AppScr_SetImgBtn, 255, LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->AppScr_SetImgBtn, lv_color_hex(0xFF33FF), LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->AppScr_SetImgBtn, &lv_font_montserratMedium_12, LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->AppScr_SetImgBtn, 0, LV_PART_MAIN | LV_STATE_CHECKED);

	// Write style for AppScr_SetImgBtn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->AppScr_SetImgBtn, 255, LV_PART_MAIN | LV_IMGBTN_STATE_RELEASED);

	// Write codes AppScr_WaittingImg
	ui->AppScr_WaittingImg = lv_img_create(ui->AppScr_AppCarousel_Setting);
	lv_obj_add_flag(ui->AppScr_WaittingImg, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->AppScr_WaittingImg, &_Waiting_alpha_150x150);
	lv_img_set_pivot(ui->AppScr_WaittingImg, 50, 50);
	lv_img_set_angle(ui->AppScr_WaittingImg, 0);
	lv_obj_set_pos(ui->AppScr_WaittingImg, 7, 46);
	lv_obj_set_size(ui->AppScr_WaittingImg, 150, 150);
	lv_obj_add_flag(ui->AppScr_WaittingImg, LV_OBJ_FLAG_HIDDEN);

	// Write style for AppScr_WaittingImg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->AppScr_WaittingImg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	// Update current screen layout.
	lv_obj_update_layout(ui->AppScr);

	// Init events for screen.
	events_init_AppScr(ui);
}
