/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

int main() {
    const uint GPIO16 = 16;
    gpio_init(GPIO16);
    gpio_set_dir(GPIO16, GPIO_OUT);
    while (true) {
        gpio_put(GPIO16, 1);
        sleep_ms(250);
        gpio_put(GPIO16, 0);
        sleep_ms(250);
    }
}
