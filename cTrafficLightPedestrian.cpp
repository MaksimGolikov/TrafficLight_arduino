/*
 * cTrafficLightPedestrians.cpp
 *
 *  Created on: 25 íîÿá. 2017 ã.
 *      Author: ÃÏÂ
 */

#include "cTrafficLightPedestrian.h"

cTrafficLightPedestrian::cTrafficLightPedestrian(cLamp **ptrLedMass, uint8_t ledsAmount) {
	this->allLamps = ptrLedMass;
	this->lampsAmount = ledsAmount;

}

void cTrafficLightPedestrian::Run(void){
	for(uint8_t i = 0; i < lampsAmount; i++){
		allLamps[i]->Run();
	}
}

void cTrafficLightPedestrian::SetMode(TrafficLightModes_t newMode){
	for(uint8_t i = 0; i < lampsAmount; i++){
		allLamps[i]->SetMode((LampModes_t)modesTable[newMode][i]);
	}
}

