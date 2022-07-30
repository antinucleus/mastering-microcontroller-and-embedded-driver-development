/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Jul 17, 2022
 *      Author: antinucleus
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"

/*
 * This is a configuration structure for GPIO pin
 */

typedef struct {
	uint8_t GPIO_PinNumber; /*!< possible values from @GPIO_PİN_NUMBERS >*/
	uint8_t GPIO_PinMode; /*!< possible values from @GPIO_PIN_MODES >*/
	uint8_t GPIO_PinSpeed; /*!< possible values from @GPIO_PIN_SPEEDS >*/
	uint8_t GPIO_PinPuPdControl; /*!< possible values from @GPIO_PIN_PUPD >*/
	uint8_t GPIO_PinOPType; /*!< possible values from @GPIO_PIN_OP_TYPES >*/
	uint8_t GPIO_PinAltFunMode; /*!< possible values from @NULL >*/
} GPIO_PinConfig_t;

/*
 * This is handle structure for GPTIO pin
 */

typedef struct {
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
} GPIO_Handle_t;

/*
 * @GPIO_PİN_NUMBERS
 * GPIO pin numbers
 */

#define GPIO_PIN_NO_0 0
#define GPIO_PIN_NO_1 1
#define GPIO_PIN_NO_2 2
#define GPIO_PIN_NO_3 3
#define GPIO_PIN_NO_4 4
#define GPIO_PIN_NO_5 5
#define GPIO_PIN_NO_6 6
#define GPIO_PIN_NO_7 7
#define GPIO_PIN_NO_8 8
#define GPIO_PIN_NO_9 9
#define GPIO_PIN_NO_10 10
#define GPIO_PIN_NO_11 11
#define GPIO_PIN_NO_12 12
#define GPIO_PIN_NO_13 13
#define GPIO_PIN_NO_14 14
#define GPIO_PIN_NO_15 15

/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */

#define GPIO_MODE_IN 0	   // Input mode
#define GPIO_MODE_OUT 1	   // Output mode
#define GPIO_MODE_ALTFN 2  // Alternate function
#define GPIO_MODE_ANALOG 3 // Analog mode
#define GPIO_MODE__FT 4	   // Falling edge
#define GPIO_MODE__RT 5	   // Rising edge
#define GPIO_MODE__RFT 6   // Rising edge falling edge trigger

/*
 * @GPIO_PIN_OP_TYPES
 * GPIO pin output types
 */

#define GPIO_OP_TYPE_PP 0 // Push pull
#define GPIO_OP_TYPE_OD 1 // Open drain

/*
 * @GPIO_PIN_SPEEDS
 * GPIO pin possible output speeds
 */

#define GPIO_SPEED_LOW 0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_FAST 2
#define GPIO_SPEED_HIGH 3

/*
 * @GPIO_PIN_PUPD
 * GPIO pin pull-up pull-down configuration macros
 */

#define GPIO_NO_PUPD 0
#define GPIO_PU 1
#define GPIO_PD 2

/*
 * Peripheral clock setup
 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Peripheral Init and De-Init
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Peripheral data read and write
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteFromOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber,
		uint8_t Value);
void GPIO_WriteFromOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * Peripheral IRQ configuration and ISR handling
 */

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPRIORITY);
void GPIO_IRQHandling(uint8_t pinNumber);

#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
