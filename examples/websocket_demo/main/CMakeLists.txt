set(COMPONENT_SRCS "main.c"
                    "wifi.c"
                    "esp_websocket_client.c"
                    "esp_websocket_server.c"
                    REQUIRES lwip esp-tls tcp_transport nghttp
                    PRIV_REQUIRES esp_timer)

register_component()
