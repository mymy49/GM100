/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

// Nuvoton M25x 시리즈에서 유효한 설정이 담긴 참고용 파일입니다.

#ifndef YSS_CONFIG__H_
#define YSS_CONFIG__H_

// ####################### 외부 크리스탈 클럭 주파수 설정 #######################
// 아래 HSE_CLOCK_FREQ가 정의 되어 있으면 HSE 클럭을 소스로 PLL 설정이 이뤄집니다.
// 정의되어 있지 않으면 HSI 클럭을 소스로 PLL 설정이 이뤄집니다.
//#define HSE_CLOCK_FREQ 32000000

// ####################### 스케줄러 설정 #######################
// runtime 함수를 지원할 PWM 장치 설정 (RUNTIME_TIMER0, 1, 2, 3, 4)
#define YSS_TIMER			RUNTIME_TIMER0

// 쓰레드당 할당 받는 Systick Clock의 수
#define THREAD_GIVEN_CLOCK	20000

// 최대 등록 가능한 쓰레드의 수
#define MAX_THREAD			12

// 쓰레드의 스택을 0xAA 패턴으로 채우기 (true, false)
#define FILL_THREAD_STACK	false

// ###################### 주변 장치 활성화 ######################
// 활성화 시킬 장치에 대해 false -> true로 변경하여 활성화 합니다.
//
// 주의 

// BPWM 활성화
#define BPWM0_ENABLE		true
#define BPWM1_ENABLE		false

// CAN FD 활성화
#define CANFD0_ENABLE		true
#define CANFD1_ENABLE		true
#define CANFD2_ENABLE		true
#define CANFD3_ENABLE		true

// EPWM 활성화
#define EPWM0_ENABLE		false
#define EPWM1_ENABLE		false

// HBI 활성화
#define HBI_ENABLE			true

// I2C 활성화
#define I2C0_ENABLE			true
#define I2C1_ENABLE			true

// I2S 활성화
#define I2S0_ENABLE			false
#define I2S1_ENABLE			false

// PWM 활성화
#define PWM0_ENABLE			false
#define PWM1_ENABLE			false
#define PWM2_ENABLE			false
#define PWM3_ENABLE			false

// QSPI 활성화
#define QSPI0_ENABLE		true
#define QSPI1_ENABLE		true

// SDH 활성화
#define SDH0_ENABLE			true
#define SDH1_ENABLE			true

// SPI 활성화
#define SPI0_ENABLE			false
#define SPI1_ENABLE			true

// TIMER 활성화
#define TIMER0_ENABLE		false
#define TIMER1_ENABLE		true
#define TIMER2_ENABLE		false
#define TIMER3_ENABLE		false

// UART 활성화
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

// USBD 활성화
#define USBD_ENABLE			false

#endif

