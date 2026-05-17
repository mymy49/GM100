/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss.h>
#include <bsp.h>
#include <yss/debug.h>
#include <util/runtime.h>
#include <yss/Trigger.h>


int main(void)
{
	// Operating system initialization
	initializeYss();

	// Board initialization
	initializeBoard();

	while(1)
	{
		debug_printf("%d\r", (uint32_t)runtime::getMsec());
		thread::yield();
	}
}


