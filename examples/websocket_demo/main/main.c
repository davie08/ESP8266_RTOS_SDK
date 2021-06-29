#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "driver/gpio.h"
#include "esp_transport.h"
#include "esp_transport_tcp.h"
#include "esp_transport_ssl.h"
#include "esp_transport_ws.h"
#include "esp_sleep.h"
#include "esp_wifi.h"

/* using uri parser */
#include "http_parser.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "esp_log.h"
#include "esp_timer.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "esp_log.h"
#include "esp_system.h"
#include "esp_err.h"

#include "esp8266/gpio_register.h"
#include "esp8266/pin_mux_register.h"

extern void wifi_main();
void websocket_reconnect_app(void);

void app_main()
{
		// wifi as AP and open websocket server first
    // when recevie hello from websocket, change to sta
    wifi_main();

    websocket_reconnect_app();

    while (1) {
        vTaskDelay(5000 / portTICK_RATE_MS);
    }
}

