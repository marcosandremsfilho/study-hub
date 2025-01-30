/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void mainCpp();
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_1_Pin GPIO_PIN_4
#define LED_1_GPIO_Port GPIOC
#define LED_2_Pin GPIO_PIN_5
#define LED_2_GPIO_Port GPIOC
#define LED_3_Pin GPIO_PIN_0
#define LED_3_GPIO_Port GPIOB
#define LED_4_Pin GPIO_PIN_1
#define LED_4_GPIO_Port GPIOB
#define M2_Control2_Pin GPIO_PIN_8
#define M2_Control2_GPIO_Port GPIOC
#define M2_Control1_Pin GPIO_PIN_9
#define M2_Control1_GPIO_Port GPIOC
#define M2_PWM_Pin GPIO_PIN_8
#define M2_PWM_GPIO_Port GPIOA
#define M1_PWM_Pin GPIO_PIN_9
#define M1_PWM_GPIO_Port GPIOA
#define M1_Control2_Pin GPIO_PIN_10
#define M1_Control2_GPIO_Port GPIOA
#define M1_Control1_Pin GPIO_PIN_11
#define M1_Control1_GPIO_Port GPIOA
#define Sensor_3_Pin GPIO_PIN_2
#define Sensor_3_GPIO_Port GPIOD
#define Sensor_2_Pin GPIO_PIN_4
#define Sensor_2_GPIO_Port GPIOB
#define Sensor_1_Pin GPIO_PIN_6
#define Sensor_1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
