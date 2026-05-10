/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef BSP__H_
#define BSP__H_

#include <stdint.h>

#include <FM24CL04B/FM24CL04B.h>
#include <P4309N_DCT/P4309N_DCT.h>

void initializeBoard(void);

extern FM24CL04B fram;

extern P4309N_DCT lcd;

extern FrameBufferRgb565LE fb;

#endif

