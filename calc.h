#ifndef CALC_H
#define CALC_H

#include <math.h>
#include <stdlib.h>

// definition of 'true' when using 8-bit integer as boolean replacement
#define TRUE 1
// definition of 'false'
#define FALSE 0

// Coordinate buffer size
#define COORDINATE_BUFFER_SIZE 11

#define RADIUS 6371

/* 
	This function will separate the given sentence into respective
	coordinates which are longitude and latitude.

	Parameter pInput is the sentence that contain the NMEA Message format.
	
	Parameter pLatOut will be the array that will contain the Latitude.

	Parameter pLongOut will be the array that will contain the Longitude.
*/
	void getCoordinate(char* pInput, char* pLatOut, char* pLongOut);

/*
	This function will determind the sign for each coordinate prior
	to the distance calculation.

	Minus "-" value will be initialised for coordinate with
	Cardinal Direction of South "S" and West "W".

	Parameter pInput is the array which contains the NMEA message.
*/
	double coorTranslate(char* pInput, char CD);

/*
	Parameter pLatGPSOut and pLongGPSOut is the latitude and the longitude
	taken from the actuall NMEA message from the GPS module.

	Parameter pLatSDOut and pLongSDOut will be the coordinate read from the SD card.

	!!! Note: Both NMEA message receive from GPS module and read from SD Card
	need to be in the same format.

	Parameter pNEMAIn is the array of NMEA message receive from GPS module.

	Parameter pSDBuffIn is the array of NMEA message read from SD card.

	Parameter pDistanceOut is the array that will contain the distance
	calculated and will be used to display on the LCD.
*/
	void getDistance(char* pNMEAIn, char* pSDBuffIn, char* pLatGPSOut, char* pLongGPSOut, char* pLatSDOut, char* pLongSDOut, char* pDistanceOut);

/*
	This functions input the coordinate in degree and return the value in radians
*/
	double getRadians(double degree);

#endif
