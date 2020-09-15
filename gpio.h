#pragma once

#include <stdbool.h>

#include "stm32f401xe.h"

typedef enum {
	portA,
	portB,
	portC,
	portD,
} gpio_port_e;	

typedef struct {
	GPIO_TypeDef* pPort;
	uint8_t pin;
} gpio_s;

typedef enum {
	AF00 = 0,
	AF01 = 1,
	AF02 = 2,
	AF03 = 3,
	AF04 = 4,
	AF05 = 5,
	AF06 = 6,
	AF07 = 7,
	AF08 = 8,
	AF09 = 9,
	AF10 = 10,
	AF11 = 11,
	AF12 = 12,
	AF13 = 13,
	AF14 = 14,
	AF15 = 15,
} gpio_alt_func_e;

/* Public Functions */

gpio_s construct_as_output(gpio_port_e port, uint8_t pin);
gpio_s construct_as_inout(gpio_port_e port, uint8_t pin);
gpio_s construct_as_alternate_func(gpio_port_e port, uint8_t pin, gpio_alt_func_e AF);
void gpio_set(gpio_s* gpio);
void gpio_reset(gpio_s* gpio);
void gpio_toggle(gpio_s* gpio);
bool gpio_get_level(gpio_s* gpio);