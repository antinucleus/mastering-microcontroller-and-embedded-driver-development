#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"

void delay(void) {
	for (uint32_t i = 0; i < 500000; i++)
		;
}

int main(void) {

	GPIO_Handle_t Gpio_led;

	Gpio_led.pGPIOx = GPIOD;
	Gpio_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	Gpio_led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Gpio_led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Gpio_led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Gpio_led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&Gpio_led);

	while (1) {
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		delay();
	}

	return 0;
}
