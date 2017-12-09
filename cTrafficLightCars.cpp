/*
 * cTrafficLightCars.cpp
 *
 *  Created on: Dec 1, 2017
 *      Author: SAK
 */

#include "cTrafficLightCars.h"

cTrafficLightCars::cTrafficLightCars(cLamp **ptrMasLed,  uint8_t trafficLedAmount) {
	this->allLamps = ptrMasLed;
	this->ledsAmount = trafficLedAmount;
}

void cTrafficLightCars::Run(void){
	for(uint8_t i = 0; i < ledsAmount; i++){
		allLamps[i]->Run();
	}
}

void cTrafficLightCars::SetMode(TrafficLightModes_t newMode){
	for(uint8_t i = 0; i < ledsAmount; i++){
			allLamps[i]->SetMode((LampModes_t)modesTable[newMode][i]);
		}
}

