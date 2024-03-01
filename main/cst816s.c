/*
1.需要添加的组件
my_project
    build
    main
        CMakeLists.txt
        idf_component.yml   <--
        main.c
    CMakeLists.txt

idf_component.yml里面的内容如下
dependencies:
  idf: ">=5.1"
  lvgl/lvgl: ">=8.*"
  esp_lvgl_port: "^1"
  espressif/esp_lcd_touch_cst816s: "^1.0.3"

*/

#include <stdio.h>

#include "driver/i2c.h"
#include "esp_lvgl_port.h"
#include "esp_lcd_touch_cst816s.h"

#define TOUCH_I2C_PORT I2C_NUM_0 // 使用的i2c

#define TOUCH_SCL 22                 // 触摸的scl引脚
#define TOUCH_SDA 21                 // 触摸的sda引脚
#define TOUCH_CLK_SPEED (400 * 1000) // 触摸的i2c频率，默认400*1000就好了

#define TOUCH_RST 23 // 触摸的rst引脚，触摸芯片复位
#define TOUCH_INT 19 // 触摸的int引脚，触摸芯片中断

#define LCD_H_RES 240 // 触摸屏幕的宽
#define LCD_V_RES 240 // 触摸屏幕的高

#define TOUCH_SWAP_XY false
#define TOUCH_MIRROR_X false
#define TOUCH_MIRROR_Y false

void cst816s_init(void)
{
    // 创建触摸的句柄和总线的句柄
    esp_lcd_touch_handle_t tp = NULL;
    esp_lcd_panel_io_handle_t tp_io_handle = NULL;

    // 初始化一组i2c，如果使用已经注册的则可以不要这个步骤
    const i2c_config_t i2c_config = {
        .mode = I2C_MODE_MASTER,
        .scl_io_num = TOUCH_SCL,
        .sda_io_num = TOUCH_SDA,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = TOUCH_CLK_SPEED,
    };
    i2c_param_config(TOUCH_I2C_PORT, &i2c_config);
    i2c_driver_install(TOUCH_I2C_PORT, I2C_MODE_MASTER, 0, 0, 0);

    // 初始化触摸的io面板
    const esp_lcd_panel_io_i2c_config_t tp_io_config = ESP_LCD_TOUCH_IO_I2C_CST816S_CONFIG();
    esp_lcd_new_panel_io_i2c((esp_lcd_i2c_bus_handle_t)TOUCH_I2C_PORT, &tp_io_config, &tp_io_handle);

    // 初始化cst816t
    const esp_lcd_touch_config_t tp_cfg = {
        .x_max = LCD_H_RES,
        .y_max = LCD_V_RES,
        .levels = {
            .reset = TOUCH_RST,
            .interrupt = TOUCH_INT,
        },
        .flags = {
            .swap_xy = TOUCH_SWAP_XY,
            .mirror_x = TOUCH_MIRROR_X,
            .mirror_y = TOUCH_MIRROR_Y,
        },
    };
    esp_lcd_touch_new_i2c_cst816s(tp_io_handle, &tp_cfg, &tp);

    // 将触摸注册到lvgl
    lv_disp_t *disp = lv_disp_get_default();
    lvgl_port_touch_cfg_t touch_cfg = {
        .disp = disp,
        .handle = tp,
    };
    lvgl_port_add_touch(&touch_cfg);
}