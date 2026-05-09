/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <bsp.h>
#include <yss/instance.h>

FM24CL04B fram;

void initializeBoard(void)
{
	// Initializing I2C0
	I2c::mainConfig_t i2c0Config =
	{
		I2c::SPEED_STANDARD //speed_t speed;
	};
	
	gpioB.setAsAltFunc(4, Gpio::PB4_I2C0_SDA, Gpio::AF_OPEN_DRAIN);
	gpioB.setAsAltFunc(5, Gpio::PB5_I2C0_SCL, Gpio::AF_OPEN_DRAIN);
	
	i2c0.enableClock();
	i2c0.initialize(i2c0Config);
	i2c0.enableInterrupt();

	// Initializing I2C1
	I2c::mainConfig_t i2c1Config =
	{
		I2c::SPEED_STANDARD //speed_t speed;
	};
	
	gpioG.setAsAltFunc(2, Gpio::PG2_I2C1_SCL, Gpio::AF_OPEN_DRAIN);
	gpioG.setAsAltFunc(3, Gpio::PG3_I2C1_SDA, Gpio::AF_OPEN_DRAIN);
	
	i2c1.enableClock();
	i2c1.initialize(i2c1Config);
	i2c1.enableInterrupt();

	// Initializing UART0
	Uart::config_t uart0Config = 
	{
		Uart::MODE_NORMAL,	//mode_t mode;
		115200,				//uint32_t baudrate;
		Uart::STOP_1BIT,	//stopbit_t stopbit;
		Uart::PARITY_NONE,	//parityBit_t parity;
		nullptr,			//void *rcvBuf;
		128					//uint32_t rcvBufSize;
	};

	gpioA.setAsAltFunc(6, Gpio::PA6_UART0_RXD);
	gpioA.setAsAltFunc(7, Gpio::PA7_UART0_TXD);

	uart0.enableClock();
	uart0.initialize(uart0Config);
	uart0.enableInterrupt();

	// Initializing BPWM0 (TFT-LCD Back Light)
	//gpioA.setAsAltFunc(11, Gpio::PA11_BPWM0_CH0);	// Set PA11 to BPWM0 CH0

	//bpwm0.enableClock();			// Enable BPWM0 clock
	//bpwm0.initialize(1000);		// Initialize the output period of BPWM0 to 1kHz.
	//bpwm0.setAsPwmOutput(0);		// Set CH0 of BPWM0 as PWM inverted output
	//bpwm0.start();				// Start timer counter

	//bpwm0.setDutyRatio(0, 1.0);	// Set the output duty cycle of BPWM0 CH0 to 10%.

	// Temporarily disable the PWM function due to a problem where the PWM output stopped during debugging, causing the LCD screen to be invisible.
	gpioA.setAsOutput(11);
	gpioA.setOutput(11, true);

	// Initializing SDH0
	gpioE.setAsAltFunc(2, Gpio::PE2_SD0_DAT0);
	gpioE.setAsAltFunc(3, Gpio::PE3_SD0_DAT1);
	gpioE.setAsAltFunc(4, Gpio::PE4_SD0_DAT2);
	gpioE.setAsAltFunc(5, Gpio::PE5_SD0_DAT3);
	gpioE.setAsAltFunc(6, Gpio::PE6_SD0_CLK);
	gpioE.setAsAltFunc(7, Gpio::PE7_SD0_CMD);
	gpioD.setAsAltFunc(13, Gpio::PD13_SD0_nCD);

	sdh0.enableClock();
	sdh0.initialize();
	sdh0.enableInterrupt();
	sdh0.setDetectPin({&gpioD, 13});

	// Initializing QSPI0
	gpioE.setAsAltFunc(0, Gpio::PE0_QSPI0_MOSI0, Gpio::AF_PUSH_PULL, Gpio::SLEWRATE_HIGH);
	gpioE.setAsAltFunc(1, Gpio::PE1_QSPI0_MISO0, Gpio::AF_PUSH_PULL, Gpio::SLEWRATE_HIGH);
	gpioB.setAsAltFunc(0, Gpio::PB0_QSPI0_MOSI1, Gpio::AF_PUSH_PULL, Gpio::SLEWRATE_HIGH); 
	gpioB.setAsAltFunc(1, Gpio::PB1_QSPI0_MISO1, Gpio::AF_PUSH_PULL, Gpio::SLEWRATE_HIGH);
	gpioH.setAsAltFunc(8, Gpio::PH8_QSPI0_CLK, Gpio::AF_PUSH_PULL, Gpio::SLEWRATE_HIGH);

	Quadspi::config_t qspi0Config = 
	{
		Quadspi::MODE_MAIN	//mode_t mode;
	};

	qspi0.enableClock();
	qspi0.initialize(qspi0Config);
	qspi0.enableInterrupt();

	// Initializing CANFD0
	gpioD.setAsAltFunc(10, Gpio::PD10_CAN0_RXD);
	gpioD.setAsAltFunc(11, Gpio::PD11_CAN0_TXD);

	NuvotonCanFd::config_t canfd0Config = 
	{
		9,				//uint8_t dbrp;				// 0 ~ 31
		14,				//uint8_t dtseg1;			// 0 ~ 31
		1,				//uint8_t dtseg2;			// 0 ~ 15
		1,				//uint8_t dsjw;				// 0 ~ 15
		44,				//uint16_t nbrp;			// 0 ~ 511
		12,				//uint8_t ntseg1;			// 1 ~ 255
		1,				//uint8_t ntseg2;			// 1 ~ 127
		1,				//uint8_t nsjw;				// 0 ~ 127
		true,			//bool fdOperaiton;			// CAN FD 모드 활성화
		false,			//bool enableSilent;		// Silent 모드 활성화
		true			//bool enableLoopback;		// Loopback 모드 활성화
	};

	canfd0.enableClock();
	canfd0.initialize(canfd0Config);
	canfd0.enableInterrupt();

	// Initializing FRAM
	FM24CL04B::config_t framConfig = 
	{
		i2c0,			//I2c &peri;
		{&gpioB, 3},	//pin_t writeProtectPin;
		0				//uint8_t addr;
	};

	gpioB.setAsOutput(3);

	fram.initialize(framConfig);

}

