#include "gpio.h"

/* Private Functions */
static gpio_s construct_gpio(gpio_port_e port, uint8_t pin) {
	gpio_s gpio;
	gpio.pin = pin;
	switch(port) {
		case (portA):
			gpio.pPort = GPIOA;
			break;
		case (portB):
			gpio.pPort = GPIOB;
			break;
		case (portC):
			gpio.pPort = GPIOC;
			break;
		case (portD):
			gpio.pPort = GPIOD;
			break;
	}
	return gpio;
}

gpio_s construct_as_output(gpio_port_e port, uint8_t pin) {
	/* REGISTERS NEEDED */
	/* OTYPER, OSPEEDR, MODER, PUPDR */
	/* Default to low speed, push-pull, no bias */
	gpio_s gpio = construct_gpio(port, pin);
	
	gpio.pPort -> MODER 	&= ~(3 << (2 * pin));
	gpio.pPort -> MODER 	|= (1 << (2 * pin));
	gpio.pPort -> OTYPER 	&= ~(1 << (pin));
	gpio.pPort -> PUPDR 	&= ~(3 << (2 * pin));
	gpio.pPort -> OSPEEDR &= ~(3 << (2 * pin));
	
	return gpio;
}
gpio_s construct_as_inout(gpio_port_e port, uint8_t pin) {
	/* REGISTERS NEEDED */
	/* OTYPER, OSPEEDR, MODER, PUPDR */
	/* Default to low speed, push-pull, no bias */
	gpio_s gpio = construct_gpio(port, pin);
	
	gpio.pPort -> MODER 	&= ~(3 << (2 * pin));
	gpio.pPort -> MODER 	|= (0 << (2 * pin));
	gpio.pPort -> OTYPER 	&= ~(1 << (pin));
	gpio.pPort -> PUPDR 	&= ~(3 << (2 * pin));
	gpio.pPort -> OSPEEDR &= ~(3 << (2 * pin));
	
	return gpio;
}
gpio_s construct_as_alternate_func(gpio_port_e port, uint8_t pin, gpio_alt_func_e AF);
void gpio_set(gpio_s* gpio);
void gpio_reset(gpio_s* gpio);
void gpio_toggle(gpio_s* gpio);
bool gpio_get_level(gpio_s* gpio);

