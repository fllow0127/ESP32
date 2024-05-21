/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

static void AppScr_CloImgBtn_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		// Write the load screen code.
		lv_obj_t *act_scr = lv_scr_act();
		lv_disp_t *d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			lv_obj_clean(act_scr);
			if (guider_ui.ClockScr_del == true)
			{
				setup_scr_ClockScr(&guider_ui);
			}
			CLockScrLiveFlag = 1;
			lv_scr_load_anim(guider_ui.ClockScr, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, true);
			guider_ui.AppScr_del = true;
		}
		break;
	}
	default:
		break;
	}
}
static void AppScr_SetImgBtn_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_clear_flag(guider_ui.AppScr_WaittingImg, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
void events_init_AppScr(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->AppScr_CloImgBtn, AppScr_CloImgBtn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->AppScr_SetImgBtn, AppScr_SetImgBtn_event_handler, LV_EVENT_ALL, NULL);
}
static void ClockScr_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code)
	{
	default:
		break;
	}
}
static void ClockScr_CloScrBtn_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		// Write the load screen code.
		lv_obj_t *act_scr = lv_scr_act();
		lv_disp_t *d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			lv_obj_clean(act_scr);
			if (guider_ui.AppScr_del == true)
			{
				setup_scr_AppScr(&guider_ui);
			}
			CLockScrLiveFlag = 0;
			lv_scr_load_anim(guider_ui.AppScr, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, true);
			guider_ui.ClockScr_del = true;
		}
		break;
	}
	default:
		break;
	}
}
void events_init_ClockScr(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ClockScr, ClockScr_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->ClockScr_CloScrBtn, ClockScr_CloScrBtn_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{
}
