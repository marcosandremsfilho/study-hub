/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
	uint16_t Sensor1;
	GPIO_PinState Sensor2;
	GPIO_PinState Sensor3;
	int pwm;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3); // Configura o timer 3 com o canal 3
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4); // Configura o timer 3 com o canal 4
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  	//Aprendendo a ler o pino de entrada

	  	Sensor1 = HAL_GPIO_ReadPin(GPIO_Sens1_GPIO_Port, GPIO_Sens1_Pin); // Lê o valor que está na entrada do sensor 1 e armazena na variável "Sensor1"
	  	Sensor2 = HAL_GPIO_ReadPin(GPIO_Sens2_GPIO_Port, GPIO_Sens2_Pin); // Lê o valor que está na entrada do sensor 2 e armazena na variável "Sensor2"
	  	Sensor3 = HAL_GPIO_ReadPin(GPIO_Sens3_GPIO_Port, GPIO_Sens3_Pin); // Lê o valor que está na entrada do sensor 3 e armazena na variável "Sensor3"

	  	//Aprendendo a usar PWM

	  	htim3.Instance->CCR3 = pwm; //PWM enviado para o timer 3 canal 3
	  	htim3.Instance->CCR4 = 255 - pwm; //PWM enviado para o timer 3 canal 4

	  	HAL_Delay(500);

	  	if(pwm > 0 && pwm < 300) {
	  		pwm += 10;
	  	} else {
	  		pwm = 1;
	  	}

	  	HAL_GPIO_WritePin(GPIO_Led1_GPIO_Port, GPIO_Led1_Pin, 1); //Torna a saída do led 1 em nível lógico baixo
	  	HAL_GPIO_WritePin(GPIO_Led2_GPIO_Port, GPIO_Led2_Pin, 0); //Torna a saída do led 2 em nível lógico alto
	  	/*
	  	//Aprendendo a escrever no pino de saída

	  	if(Sensor1 == 1) {
		HAL_GPIO_WritePin(GPIO_Led1_GPIO_Port, GPIO_Led1_Pin, 0);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led1_GPIO_Port, GPIO_Led1_Pin, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led2_GPIO_Port, GPIO_Led2_Pin, 0);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led2_GPIO_Port, GPIO_Led2_Pin, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led3_GPIO_Port, GPIO_Led3_Pin, 0);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led3_GPIO_Port, GPIO_Led3_Pin, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led4_GPIO_Port, GPIO_Led4_Pin, 0);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led4_GPIO_Port, GPIO_Led4_Pin, 1);
		HAL_Delay(500);
	} else if (Sensor2 == 1) {
		HAL_GPIO_WritePin(GPIO_Led1_GPIO_Port, GPIO_Led1_Pin, 0);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led2_GPIO_Port, GPIO_Led2_Pin, 0);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led3_GPIO_Port, GPIO_Led3_Pin, 0);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led4_GPIO_Port, GPIO_Led4_Pin, 0);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led1_GPIO_Port, GPIO_Led1_Pin, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led2_GPIO_Port, GPIO_Led2_Pin, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led3_GPIO_Port, GPIO_Led3_Pin, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led4_GPIO_Port, GPIO_Led4_Pin, 1);
		HAL_Delay(500);
	} else if (Sensor3 == 1) {
		HAL_GPIO_WritePin(GPIO_Led1_GPIO_Port, GPIO_Led1_Pin, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led2_GPIO_Port, GPIO_Led2_Pin, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led3_GPIO_Port, GPIO_Led3_Pin, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led4_GPIO_Port, GPIO_Led4_Pin, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led1_GPIO_Port, GPIO_Led1_Pin, 0);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led2_GPIO_Port, GPIO_Led2_Pin, 0);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led3_GPIO_Port, GPIO_Led3_Pin, 0);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led4_GPIO_Port, GPIO_Led4_Pin, 0);
	} else if (Sensor1 == 0 & Sensor2 == 0 & Sensor3 == 0) {
		HAL_GPIO_WritePin(GPIO_Led1_GPIO_Port, GPIO_Led1_Pin, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led2_GPIO_Port, GPIO_Led2_Pin, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led3_GPIO_Port, GPIO_Led3_Pin, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIO_Led4_GPIO_Port, GPIO_Led4_Pin, 1);
		HAL_Delay(500);
	}

	*/
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
