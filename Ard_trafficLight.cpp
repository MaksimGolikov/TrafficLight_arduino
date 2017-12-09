#include <Arduino.h>
#include <stdint.h>


#include "cLamp.h"
#include "cTrafficLightPedestrian.h"
#include "cTrafficLightCars.h"
#include "cCrossRoad.h"
#include "cShedule.h"

cLamp HeartbeatLed		(13, HIGH, LOW,  200);

cLamp lampGreenPin10	(10, HIGH, LOW,  500);
cLamp lampRedPin9		(9,  HIGH, LOW,	 500);

cLamp lampGreenPin5		(5,  LOW,  HIGH, 500);
cLamp lampRedPin4		(4,  LOW,  HIGH, 500);

cLamp lampRedPin6		(6,  HIGH, LOW,  500);
cLamp lampYellowPin7	(7,  HIGH, LOW,  500);
cLamp lampGreenPin8     (8,  HIGH, LOW,  500);

cLamp lampRedPin1		(1,  LOW,  HIGH, 500);
cLamp lampYellowPin2	(2,  LOW,  HIGH, 500);
cLamp lampGreenPin3		(3,  LOW,  HIGH, 500);

cLamp *lampsOftrafficLightsCar_first[]={
		&lampGreenPin8,
		&lampYellowPin7,
		&lampRedPin6
};

cLamp *lampsTrafficLightsCar_second[]={
		&lampGreenPin3,
		&lampYellowPin2,
		&lampRedPin1
};

cLamp *lampsOftrafficLightsPed_first[]={
		&lampGreenPin10,
		&lampRedPin9
};

cLamp *lampsOfTrafficLightsPed_second[]={
		&lampGreenPin5,
		&lampRedPin4
};


cTrafficLightCars trafficLightsCar_first (lampsOftrafficLightsCar_first, 3);
cTrafficLightCars trafficLightsCar_second (lampsTrafficLightsCar_second, 3);

cTrafficLightPedestrian trafficLightPed_first (lampsOftrafficLightsPed_first, 2);
cTrafficLightPedestrian trafficLightPed_second (lampsOfTrafficLightsPed_second, 2);


cTrafficLight *trafficLights[] ={
		&trafficLightsCar_first,
		&trafficLightPed_first,
		&trafficLightsCar_second,
		&trafficLightPed_second
};


static uint8_t trafficLightScheduler[][5] = {
			//Main Cars         Main Ped		Second Cars			Second Ped       Delay
			{modeGreen,		 	modeRed,		modeRed,			modeGreen,          5},
			{modeGreenBlink, 	modeRed,		modeRed,			modeGreenBlink,     5},
			{modeYellow,		modeRed,		modeRed,			modeRed,            5},
			{modeRed, 			modeGreen,		modeRedYellow,		modeRed,            5},
			{modeRed,			modeGreen, 		modeGreen,			modeRed,            5},
			{modeRed,			modeGreenBlink,	modeGreenBlink,		modeRed,            5},
			{modeRed,			modeRed,		modeRedYellow,		modeRed,            5},
			{modeRedYellow,		modeRed,		modeRed,			modeRed,            5}

};


cShedule shedule(*trafficLightScheduler, 8, 4);

cCrossRoad crossRoad_1(trafficLights, 2, &shedule);


void setup() {
Serial.begin(115200);

	HeartbeatLed.SetMode(lampBlink);

	trafficLightsCar_first.SetMode(modeService);
	trafficLightsCar_second.SetMode(modeService);

	trafficLightPed_first.SetMode(modeGreen);
	trafficLightPed_second.SetMode(modeGreen);
}

void loop() {

	HeartbeatLed.Run();

	crossRoad_1.Run();
}
