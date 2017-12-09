/*
 * cCrossRoad.h
 *
 *  Created on: 8 Dec. 2017 ð.
 *      Author: MaGol
 */

#ifndef CCROSSROAD_H_
#define CCROSSROAD_H_

#include "cTrafficLight.h"
#include "cShedule.h"
#include "stdint.h"

class cCrossRoad {
public:
	cCrossRoad(cTrafficLight **ptrTrafficlights, uint8_t trafficLightsAmount, cShedule *ptrShedule);

	void Run();

private:
	cTrafficLight **TrafficLights;
	uint8_t trafficLightsAmount;
	cShedule *shedule;
	uint8_t currentMode; // mast be static
	uint32_t saveTime;  // mast be static
	uint32_t currentTime;

};

#endif /* CCROSSROAD_H_ */
