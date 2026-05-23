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
	bool firstDownFlag = true;
	Position p1, p2, base;
	PointerDevice::event_t event;

	// Operating system initialization
	initializeYss();

	// Board initialization
	initializeBoard();

	fb.setBackgroundColor({0xFF, 0xFF, 0xFF});
	fb.clear();
	
	brush.drawBitmap({0, 0}, fb.getBitmap());

	touch.clearEvent();

	while(1)
	{
		event = touch.getCurrentEvent();

		switch(event.event)
		{
		case PointerDevice::EVENT_NOTTING :
		default :
			break;

		case PointerDevice::EVENT_TOUCH_DOWN :
			brush.drawBitmap({0, 0}, fb.getBitmap());

			if(firstDownFlag)
				p1.setPosition(event.x, event.y);
			else
				p2.setPosition(event.x, event.y);


			if(firstDownFlag)
			{
				fb.drawBitmap({0, 0}, brush.getBitmap());

				brush.setBrushColor({0xFF, 0x00, 0x00});
				brush.fillCircle(p1, 5);
			}
			else 
			{
				brush.setBrushColor({0xFF, 0x00, 0x00});
				brush.fillCircle(p1, 5);

				brush.setBrushColor({0x00, 0x00, 0x00});
				brush.drawLine(p1, p2);
				brush.setBrushColor({0xFF, 0x00, 0x00});
				brush.drawCircle(p2, 50);
			}

			lcd.drawBitmap(base, brush.getBitmap());

			firstDownFlag = false;
			break;

		case PointerDevice::EVENT_TOUCH_DRAG :
			brush.drawBitmap({0, 0}, fb.getBitmap());

			p2.setPosition(event.x, event.y);

			brush.setBrushColor({0x00, 0x00, 0x00});
			brush.drawLine(p1, p2);

			brush.setBrushColor({0xFF, 0x00, 0x00});
			brush.fillCircle(p1, 5);

			brush.setBrushColor({0xFF, 0x00, 0x00});
			brush.drawCircle(p2, 50);

			lcd.drawBitmap(base, brush.getBitmap());
			break;

		case PointerDevice::EVENT_TOUCH_UP :
			p2.setPosition(event.x, event.y);

			brush.drawBitmap({0, 0}, fb.getBitmap());
			brush.setBrushColor({0x00, 0x00, 0x00});
			brush.drawLine(p1, p2);

			fb.drawBitmap({0, 0}, brush.getBitmap());

			brush.setBrushColor({0xFF, 0x00, 0x00});
			brush.fillCircle(p2, 5);

			lcd.drawBitmap(base, brush.getBitmap());

			p1 = p2;
			break;
		}

		thread::yield();
	}
}


