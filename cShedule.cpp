/*
 * cShedule.cpp
 *
 *  Created on: 8 груд. 2017 р.
 *      Author: MaGol
 */
#include "stdint.h"
#include "cShedule.h"
#include <Arduino.h>


cShedule::cShedule(uint8_t *ptrSheduleTable, uint8_t modeAmount, uint8_t trafficLights_Amount) {
	this->sheduleTable = ptrSheduleTable;
	this->trafficLightsAmount = trafficLights_Amount;
	this->modeAmount = modeAmount;
	this->stepNumber = 0;
}


uint8_t cShedule::getStep(uint8_t trafficLightNumber){
	uint8_t result = *(this->sheduleTable + (this->stepNumber*this->trafficLightsAmount));

	if(trafficLightNumber <= trafficLightsAmount){
		result = *(this->sheduleTable + (this->stepNumber*this->trafficLightsAmount) + trafficLightNumber);
		//esult = this->sheduleTable[stepNumber][trafficLightNumber];
	}

	return result;
}


uint32_t cShedule::getTime(){
	return *(this->sheduleTable + (this->stepNumber*this->trafficLightsAmount) + this->trafficLightsAmount) *1000;
	//return (this->sheduleTable[stepNumber][trafficLightsAmount] * 1000);
}


void cShedule::IncrementStep(){
	stepNumber += 1;
	if (stepNumber >= modeAmount) {
		stepNumber = 0;
	}
}

void cShedule::print(){

	for (uint8_t i = 0; i < modeAmount; i++) {
		for (uint8_t j = 0; j < trafficLightsAmount; j++) {
			Serial.print(*(this->sheduleTable + (i *  this->trafficLightsAmount) + j));
		}
	}
}
