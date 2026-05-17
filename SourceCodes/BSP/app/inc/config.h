/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CONFIG__H_
#define YSS_CONFIG__H_

// ####################### External crystal clock frequency setting #######################
// If HSE_CLOCK_FREQ is defined below, PLL configuration is performed using the HSE clock as the source.
// If not defined, the PLL is configured using the HSI clock as the source.
#define HSE_CLOCK_FREQ			12000000

// ####################### Scheduler settings #######################
// Select a timer device to support runtime functions (RUNTIME_TIMER0, 1, 2, 3, 4)
#define YSS_TIMER				RUNTIME_TIMER0

// Number of Systick Clocks allocated per thread
#define THREAD_GIVEN_CLOCK		12000

// Maximum number of threads that can be registered
#define MAX_THREAD				32

// Fill the thread's stack with the 0xAA pattern (true, false)
#define FILL_THREAD_STACK		false

// ####################### lmalloc settings #######################
// Whether to use dynamically allocated memory using SDRAM (true, false)
#define YSS_L_HEAP_USE			true

// Setting the starting address of SDRAM
#define YSS_SDRAM_ADDR			0x80000000

// Setting the total memory capacity of SDRAM
#define YSS_L_HEAP_SIZE			(8 * 1024 * 1024)

// lmalloc minimum allocation unit capacity
#define YSS_L_HEAP_CLUSTER_SIZE	(256)

// Maximum allocation count of lmalloc
#define YSS_L_MAX_NUM_OF_MALLOC	1024


// ###################### Activate peripheral devices ######################
// Activate the device by changing false to true.

// Enable BPWM
#define BPWM0_ENABLE		true
#define BPWM1_ENABLE		false

// Enable CAN FD
#define CANFD0_ENABLE		true
#define CANFD1_ENABLE		true
#define CANFD2_ENABLE		true
#define CANFD3_ENABLE		true

// Enable EPWM
#define EPWM0_ENABLE		false
#define EPWM1_ENABLE		false

// Enable HBI
#define HBI_ENABLE			true

// Enable I2C
#define I2C0_ENABLE			true
#define I2C1_ENABLE			true

// Enable I2S
#define I2S0_ENABLE			false
#define I2S1_ENABLE			false

// Enable PWM
#define PWM0_ENABLE			false
#define PWM1_ENABLE			false
#define PWM2_ENABLE			false
#define PWM3_ENABLE			false

// Enable QSPI
#define QSPI0_ENABLE		true
#define QSPI1_ENABLE		true

// Enable SDH
#define SDH0_ENABLE			true
#define SDH1_ENABLE			true

// Enable SPI
#define SPI0_ENABLE			false
#define SPI1_ENABLE			true

// Enable TIMER
#define TIMER0_ENABLE		false
#define TIMER1_ENABLE		true
#define TIMER2_ENABLE		false
#define TIMER3_ENABLE		false

// Enable UART
#define UART0_ENABLE		true
#define UART1_ENABLE		false
#define UART2_ENABLE		false
#define UART3_ENABLE		false
#define UART4_ENABLE		false
#define UART5_ENABLE		false
#define UART6_ENABLE		false
#define UART7_ENABLE		false
#define UART8_ENABLE		false
#define UART9_ENABLE		false

// Enable USBD
#define USBD_ENABLE			false

#endif

