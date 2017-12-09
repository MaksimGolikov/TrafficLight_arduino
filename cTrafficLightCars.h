/*
 * cTrafficLightCars.h
 *
 *  Created on: Dec 1, 2017
 *      Author: SAK
 */

#ifndef CTRAFFICLIGHTCARS_H_
#define CTRAFFICLIGHTCARS_H_

#include "cTrafficLight.h"
#include "cLamp.h"

class cTrafficLightCars: public cTrafficLight {
public:
	cTrafficLightCars(cLamp **ptrMasLed,  uint8_t trafficLedAmount);

	void Run(void);

	void SetMode(TrafficLightModes_t newMode);

private:
	cLamp **allLamps;
    uint8_t ledsAmount;

	const LampModes_t modesTable[6][3] = {
								//Green		Yellow		Red
		/* modeGreen */			{lampOn, 	lampOff,	lampOff	},
		/* modeGreenBlink */	{lampBlink,	lampOff,	lampOff	},
		/* modeRed */			{lampOff,	lampOff,    lampOn	},
		/* modeService */		{lampOff,	lampBlink,	lampOff },
		/* modeYellow */		{lampOff,	lampOn,		lampOff	},
		/* modeRedYellow */		{lampOff,	lampOn,		lampOn	}
	};

};

#endif /* CTRAFFICLIGHTCARS_H_ */
