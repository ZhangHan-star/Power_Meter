# components/porting/CMakeLists.txt
idf_component_register(
    SRCS
        "lv_port_indev.c"
    INCLUDE_DIRS
        # "${CMAKE_CURRENT_SOURCE_DIR}/../lvgl/include"  # 添加 lvgl include 目录到包含路径
        "${CMAKE_CURRENT_SOURCE_DIR}/../../main/Key"  # 添加 Key 目录到包含路径

    REQUIRES
        lvgl
        driver  # 添加对 driver 的依赖
)
