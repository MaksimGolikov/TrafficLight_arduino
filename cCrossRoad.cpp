/*
 * cCrossRoad.cpp
 *
 *  Created on: 8 груд. 2017 р.
 *      Author: MaGol
 */

#include "cCrossRoad.h"
#include <Arduino.h>

cCrossRoad::cCrossRoad(cTrafficLight **ptrTrafficlights, uint8_t trafficLightsAmount, cShedule *ptrShedule){
	this->TrafficLights = ptrTrafficlights;
	this->trafficLightsAmount = trafficLightsAmount;
	this->shedule = ptrShedule;

	this->currentMode = 0;
	this->currentTime = millis();
	this->saveTime = millis();
}

void cCrossRoad::Run(){
	for(uint8_t i = 0; i< trafficLightsAmount; i++){
		TrafficLights[i]->Run();
	}


	if ((currentTime - saveTime) >= shedule->getTime()) {

		for (uint8_t i = 0; i < trafficLightsAmount; i++) {
			uint8_t newMode = shedule->getStep(i);

			TrafficLights[i]->SetMode(newMode);
		}
		shedule->IncrementStep();
		saveTime = millis();
	}


}

