/*
 * cTraffic;LightPedestrians.h
 *
 *  Created on: 25 םמÿב. 2017 ד.
 *      Author: ÃÏÂ
 */

#ifndef CTRAFFICLIGHTPEDESTRIANS_H_
#define CTRAFFICLIGHTPEDESTRIANS_H_

#include "cTrafficLight.h"
#include "cLamp.h"
#include "stdint.h"

class cTrafficLightPedestrian: public cTrafficLight {
public:
	cTrafficLightPedestrian(cLamp **ptrLedMass, uint8_t ledsAmount);

	void Run(void);

	void SetMode(TrafficLightModes_t newMode);

private:
	cLamp **allLamps;
    uint8_t lampsAmount;

	const LampModes_t modesTable[4][2] = {
			   	   	   	   	     //Green  	Red
		/* modeGreen */			{lampOn, 	lampOff},
		/* modeGreenBlink */	{lampBlink, lampOff},
		/* modeRed */			{lampOff,	lampOn},
		/* modeService */		{lampOff,	lampOff},
	};

};

#endif /* CTRAFFICLIGHTPEDESTRIANS_H_ */
