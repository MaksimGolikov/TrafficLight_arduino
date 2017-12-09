/*
 * cShedule.h
 *
 *  Created on: 8 груд. 2017 р.
 *      Author: MaGol
 */

#ifndef CSHEDULE_H_
#define CSHEDULE_H_

#include <stdint.h>

class cShedule {
public:
	cShedule(uint8_t *ptrSheduleTable, uint8_t modeAmount, uint8_t trafficLights_Amount);

    uint8_t getStep(uint8_t trafficLightNumber);

    uint32_t getTime();

    void IncrementStep();

    void print();

private:
	uint8_t *sheduleTable;
	uint8_t trafficLightsAmount;
	uint8_t modeAmount;
	uint8_t stepNumber; //mast be static
};

#endif /* CSHEDULE_H_ */
