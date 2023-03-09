/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Block.h"
#include "Player.h"
#include "Map.h"
#include"Bitmaps.h"
#include "Mob.h"
#include"stdio.h"
#include"string.h"
#include "Spike.h"
#include "Coin.h"
#include"Objects.h"
#include"tm_stm32f4_rng.h"
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


//--------GAME INTS------------//
//int for map
int is_map_changed=0;
int current_map=4;
int ground_level=62;
//ints for Jump
int Jump_height;

//ints for gravitation
int barrier;
//int for changing maps
int Mob_1_A=83;
int Mob_1_B=116;
int Block_1_A=81;
int Block_1_B=117;


//defines
#define true 1
#define false 0
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void Jump(Player &player,int &jump_height,int &barrier);
void Gravitation(Player &player,int ground_level,int &barrier);
void Check_buttons(Player &player,int barrier);
void Game(Player player,int &barrier,int &Jump_height);
void Display_Over_Screen();
void change_map(int &cur_map,int &is_map_changed,int &Block_1_A,int &Block_1_B,int &Mob_1_A,int &Mob_1_B,Coin coin);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/*-------------------------------change map function---------------------------------------*/
void change_map(int &cur_map,int &is_map_changed,int &Block_1_A,int &Block_1_B,int &Mob_1_A,int &Mob_1_B,Coin coin){//maps~
if(coin.is_coin_gathered==true){//if coin gathered boxi is go to the next map
// cur_map=TM_RNG_Get()%1+2;
	cur_map++; //random map will be in future work in progress
if(cur_map==2){//map 2
//-----POSITIONING OBJECTS-----//
//--------PLAYER------------//
boxi.Change_position(12, 0);
//--------BLOCKS------------//
B[0].Change_position(1,20);
B[1].Change_position(11,20);
B[2].Change_position(21,20);
B[3].Change_position(91,20);
B[4].Change_position(101,20);
B[5].Change_position(81,52);
B[6].Change_position(91,52);
B[8].Change_position(101,52);
B[9].Change_position(111,52);
B[7].Change_position(70,20);
Block_1_A=31;
Block_1_B=81;
//--------MOBS----------------//
m1.Change_position(91, 44);
m1.is_mob_alive=true;
Mob_1_A=90;
Mob_1_B=120;
//--------SPIKES--------------//
S[0].Change_position(2, 14);
S[1].Change_position(7, 14);
S[2].Change_position(81, 26);
S[3].Change_position(86, 26);
S[4].Change_position(122, 16);
S[5].Change_position(122, 48);
//--------COIN--------------/
c1.Change_position(82,44);
c1.is_coin_alive=true;
//cur_map++;
}
if(cur_map==3){// map 3
//-----POSITIONING OBJECTS-----//
//--------PLAYER------------//
boxi.Change_position(2, 0);
//--------BLOCKS------------//
B[0].Change_position(1,20);
B[1].Change_position(26,20);
B[2].Change_position(31,58);
B[3].Change_position(56,58);
B[4].Change_position(86,58);
B[5].Change_position(96,58);
B[6].Change_position(106,58);
B[8].Change_position(116,58);
B[9].Change_position(21,58);
B[7].Change_position(70,20);
Block_1_A=36;
Block_1_B=96;
//--------MOBS----------------//
m1.Change_position(91, 50);
m1.is_mob_alive=true;
Mob_1_A=86;
Mob_1_B=126;
//--------SPIKES--------------//
S[0].Change_position(18, 32);
S[1].Change_position(40, 32);
S[2].Change_position(47, 32);
S[3].Change_position(54, 32);
S[4].Change_position(61, 32);
S[5].Change_position(96, 32);
//--------COIN--------------/
c1.Change_position(32,45);
c1.is_coin_alive=true;
//cur_map++;
 }

if(cur_map==4){// map 4
//-----POSITIONING OBJECTS-----//
//--------PLAYER------------//
boxi.Change_position(5, 0);
//--------BLOCKS------------//
B[0].Change_position(1,46);
B[1].Change_position(31,56);
B[2].Change_position(41,56);
B[3].Change_position(51,56);
B[4].Change_position(61,56);
B[5].Change_position(71,56);
B[6].Change_position(96,52);
B[8].Change_position(106,42);
B[9].Change_position(31,30);
B[7].Change_position(70,36);
Block_1_A=41;
Block_1_B=106;
//--------MOBS----------------//
m1.Change_position(60, 48);
m1.is_mob_alive=true;
Mob_1_A=31;
Mob_1_B=81;
//--------SPIKES--------------//
S[0].Change_position(21, 60);
S[1].Change_position(26, 60);
S[2].Change_position(81, 60);
S[3].Change_position(86, 60);
S[4].Change_position(91, 60);
S[5].Change_position(120, 35);
//--------COIN--------------/
c1.Change_position(32,20);
c1.is_coin_alive=true;
//cur_map++;
 }
if(cur_map==5){// map 5
//-----POSITIONING OBJECTS-----//
//--------PLAYER------------//
boxi.Change_position(111, 0);
//--------BLOCKS------------//
B[0].Change_position(111,30);
B[1].Change_position(86,30);
B[2].Change_position(66,20);
B[3].Change_position(1,52);
B[4].Change_position(21,52);
B[5].Change_position(46,52);
B[6].Change_position(46,30);
B[8].Change_position(101,58);
B[9].Change_position(121,58);
B[7].Change_position(46,16);
Block_1_A=21;
Block_1_B=66;
//--------MOBS----------------//
m1.Change_position(21, 44);
m1.is_mob_alive=true;
Mob_1_A=1;
Mob_1_B=46;
//--------SPIKES--------------//
S[0].Change_position(11, 20);
S[1].Change_position(17, 20);
S[2].Change_position(26, 30);
S[3].Change_position(31, 30);
S[4].Change_position(46, 24);
S[5].Change_position(51,24);
//--------COIN--------------/
c1.Change_position(48,44);
c1.is_coin_alive=true;
//cur_map++;
 }
}
}
/*-------------------jump function------------------------------------------*/
	void Jump(Player &player,int &jump_height,int &barrier){

	 if((jump_height>0)&&(barrier==true))
	 {
		player.pos_y--;
	    jump_height--;   /////////////////////////////////////////////////////
		player.pos_y--; /* if gravitation is off we can jump on Jump_height */
		jump_height--; /*     in jump we are losing Jump_height             */
		barrier=true; /*    when we are jumping gravitation is off          */
                     /////////////////////////////////////////////////////////
		}
	 if(jump_height==0){
		 barrier=false;
	 }
	 }

/*---------------------gravitation function-----------------------------------*/
	void Gravitation(Player &player,int ground_level,int &barrier){

	  player.generateHIT();//generating actual hit box of player

	 if(player.BHIT>=ground_level){
		barrier=true;// if player hit the ground
		player.Player_live--;
	 }

	if(barrier==false){ // if player is in free air we are falling fastest
		player.pos_y++;
		player.pos_y++;
	 }
	}

/*----------------------checking buttons---------------------------------------*/
	void Check_buttons(Player &player,int barrier){
		player.generateHIT();//generating actual hit box of player

		if((HAL_GPIO_ReadPin(UP_GPIO_Port, UP_Pin)==0)&&(barrier==true))//jumping
		{
          if((Jump_height==0)&&(barrier==true)){//checking if player has end his jump
        	  Jump_height=18;                   // and if he is on something that he jump of
          }
		}

		if(HAL_GPIO_ReadPin(A_GPIO_Port, A_Pin)==0){ //go into right side
			player.pos_x++;
		}
		if(HAL_GPIO_ReadPin(LEFT_GPIO_Port, LEFT_Pin)==0){//go into left side
			player.pos_x--;
		}
		}
/*-----------------------------GAME OVER SCREEN--------------------------------*/
	void Display_Over_Screen(){//displaying a 128x64 game over bitmap function
		ssd1306_Fill(Black);
		ssd1306_DrawBitmap(0, 0, Bitmap_game_over, 128, 64, White);
		ssd1306_UpdateScreen();
		HAL_Delay(2000);
	}

/*-----------------------------GAME LOOP----------------------------------------*/
	void Game(Player player,int &barrier,int &Jump_height){//main loop of boxi game
	if(player.Player_live>0){//if player is alive

		//---------DISPLAYING LAST FRAME-----------//
		//displaying all objects//
		  ssd1306_Fill(Black);
		  boxi.Display_Player_hearts();
		  map1.Display_map();
          c1.Display_Coin();

		  for(int i=0; i<=9; i++){//displaying blocks
			  B[i].Display_Block();
		  }

		  for(int i=0; i<=5; i++){//displaying spikes
		      S[i].Display_Spike();
		   }

		  m1.Display_mob();//displaying mob

		  boxi.Display_Player();//displaying boxi

		  //updating the screen//
		  ssd1306_UpdateScreen();

		  //----------MOVING BLOCKS------------------//
		  B[7].Move_Block(Block_1_A, Block_1_B, barrier,boxi);

		  //----------MOVING MOBS-------------------//
		  m1.Move_mob(Mob_1_A,Mob_1_B);

		  //--------CHECKING BARRIERS----------------//
		  c1.Check(boxi,current_map);
		  m1.check(boxi);
		  for(int i=0; i<=5; i++){//checking spikes
		  	 S[i].Check(barrier, boxi);
		  }


		  for(int i=0; i<=9; i++){ // checking if player(boxi) is on block
		  	B[i].Check(barrier, boxi);
		  }

		  //----------GRAVITATION FUNCTION----------//
		  Gravitation(boxi, ground_level,barrier);

		  //--------BUTTONS CHECKING ---------------//
	      Check_buttons(boxi,barrier);

	      //----------JUMPING FUNCTION--------------//
	      Jump(boxi,Jump_height,barrier);
	      //-----------CHANGE MAP FUNCTION----------//
	      change_map(current_map,is_map_changed,Block_1_A,Block_1_B,Mob_1_A,Mob_1_B,c1);

		  //-----------LED TEST--------------//
		  //HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin); //i am turning it on for tests but game will go faster without it
	}
	else {
		Display_Over_Screen();
	}
}
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
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  	  //Initialize  of libraries//
  	  ssd1306_Init();

  	  //fill black the display
  	  ssd1306_Fill(Black);
  	  ssd1306_UpdateScreen();
  	//-----POSITIONING OBJECTS-----//
     //--------BLOCKS------------//
  	  B[0].Change_position(1,52);
  	  B[1].Change_position(11,52);
  	  B[2].Change_position(21,52);
  	  B[3].Change_position(41,42);
  	  B[4].Change_position(41,52);
  	  B[5].Change_position(71,42);
  	  B[6].Change_position(71,52);
  	  B[7].Change_position(91,42);
  	  B[8].Change_position(117,42);
  	  B[9].Change_position(117,52);
  	 //--------SPIKES--------------//
  	  S[0].Change_position(51, 56);
  	  S[1].Change_position(56, 56);
  	  S[2].Change_position(61, 56);
  	  S[3].Change_position(66, 56);
  	  S[4].Change_position(31, 56);
  	  S[5].Change_position(36, 56);
  	  c1.Change_position(119, 36);
  	 /* Initialize random number generator */
  	    TM_RNG_Init();




  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    Game(boxi,barrier,Jump_height); //Game loop
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
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
  RCC_OscInitStruct.PLL.PLLN = 85;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
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
