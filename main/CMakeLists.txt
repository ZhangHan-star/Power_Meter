set(UI_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/ui)
file(GLOB_RECURSE SOURCES ${UI_SOURCE_DIR}/*.c
                          ${UI_SOURCE_DIR}/custom/*.c
                          ${UI_SOURCE_DIR}/generated/*.c
                          ${UI_SOURCE_DIR}/generated/images/*.c
                          ${UI_SOURCE_DIR}/generated/guider_fonts/*.c
                          ${UI_SOURCE_DIR}/generated/guider_customer_fonts/*.c)

set(include_dirs
    ${UI_SOURCE_DIR}
    ${UI_SOURCE_DIR}/custom
    ${UI_SOURCE_DIR}/generated
    ${UI_SOURCE_DIR}/generated/guider_customer_fonts
    ${UI_SOURCE_DIR}/generated/guider_fonts
    )

# idf_component_register(SRCS "hello_world_main.c"
#                     INCLUDE_DIRS ${include_dirs}
#                     REQUIRES lvgl)

idf_component_register( SRCS "main.c"
                            ${SOURCES}
                            "./Key/Key.c"
                            "./I2c/IIC.c"
                            "./Ina226/ina226.c"
                            "./Beep/Beep.c"
                            "./WIFI/TCP.c"
                            "./WIFI/VOFA.c"
                            "./WS2812b/WS2812b.c"
                        INCLUDE_DIRS "" ${include_dirs}
                            "./Key"
                            "./I2c"
                            "./Ina226"
                            "./Beep"
                            "./WIFI"
                            "./WS2812b"
                            "${IDF_PATH}/components/espcoredump/include"  # 添加 espcoredump include 目录
                            "${IDF_PATH}/components/esp_wifi/include"
                            "${IDF_PATH}/components/esp_event/include"
                            "${IDF_PATH}/components/esp_netif/include"
                            "${IDF_PATH}/components/lwip/include"
                            "${IDF_PATH}/components/nvs_flash/include"
                            "${IDF_PATH}/components/esp_partition/include"

                        REQUIRES lvgl
                        REQUIRES lvgl_esp32_drivers
                        REQUIRES porting
                        REQUIRES led_strip
                            )
