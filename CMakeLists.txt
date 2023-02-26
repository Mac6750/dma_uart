cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
include(../pico-sdk/tools/CMakeLists.txt)
project(dma_uart C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${PROJECT_NAME}
	dma_uart.c
)

pico_generate_pio_header(${PROJECT_NAME}
	${CMAKE_CURRENT_LIST_DIR}/RX_pio.pio
)

pico_generate_pio_header(${PROJECT_NAME}
	${CMAKE_CURRENT_LIST_DIR}/TX_pio.pio
)

target_link_libraries(${PROJECT_NAME}
	hardware_pio 
	hardware_dma
	pico_stdlib
)
pico_add_extra_outputs(${PROJECT_NAME})
#example_auto_set_url(${PROJECT_NAME})

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)
