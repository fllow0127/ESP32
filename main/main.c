#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "cst816s.h" //触摸屏
#include "gc9a01.h"  //显示屏
#include "led_brightness.h"

// #include "lv_demos.h"
#include "generated/gui_guider.h"
#include "custom/custom.h"

lv_ui guider_ui;

void app_main(void)
{
    gc9a01_init();
    cst816s_init();
    display_brightness_init();

    setup_ui(&guider_ui);
    custom_init(&guider_ui);

    display_brightness_set(50);

    while (1)
    {
        vTaskDelay(10000 / portTICK_PERIOD_MS);
    }
}
