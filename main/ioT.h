#ifndef __IOT_H__

/******************************************************
@example:
    void app_main(void)
    {
        myWiFi_Init();
        while (1)
        {
            // 每隔5S发布一次测试消息
            // if(my_mqtt_connect_flag) esp_mqtt_client_publish(emcht,"/ih3mZslK014/ESP32/user/Phone2ESP","test",strlen("test"),1,0);
            vTaskDelay(3000 / portTICK_PERIOD_MS);
        }
    }

******************************************************/
/********* WIFI *********/
#define MY_WIFI_NAME "Lv"
#define MY_WIFI_PASSWARD "ab123456"

/********* MQTT *********/
#define MY_CLIENT_ID "ih3mZslK014.ESP32|securemode=2,signmethod=hmacsha256,timestamp=1716192893835|"
#define MY_MQTT_URL "mqtt://iot-06z00hyelt721zg.mqtt.iothub.aliyuncs.com"
#define MY_MQTT_PORT 1883
#define MY_MQTT_USERNAME "ESP32&ih3mZslK014"
#define MY_MQTT_PASSWARD "dec3314db60b8f89a613f0700f297fb25b6a8f28b80c2ad3b14a342bbf3bffe9"
#define MY_MQTT_SUB_TOPIC "/ih3mZslK014/ESP32/user/Phone2ESP"
#define MY_MQTT_PUB_TOPIC

void myWiFi_Init(void);
void myMqtt_Init(void);

#endif