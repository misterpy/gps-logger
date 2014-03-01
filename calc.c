// calc.c

#include "calc.h"

// this flags is needed for distance calculation
int flagSouth = FALSE;
int flagWest = FALSE;

double getRadians(double degree){
	return (degree * (M_PI/180));
}

void getCoordinate(char* pInput, char* pLatOut, char* pLongOut){

	int i=0;
	int j=0;
	int loop=7;

	// flag for controlling loop
	int hasBoth = FALSE;
	int hasLat = FALSE;

	do{
		if(!hasLat){
			if(pInput[loop] == 'S' || pInput[loop] == 'N'){
				if(pInput[loop] == 'S'){
					flagSouth = TRUE;
					hasLat = TRUE;
					loop += 2; // jump to next coordinate
				}
				else{
					hasLat = TRUE;
					loop += 2; // jump to next coordinate
				}
			}
			else{
				pLatOut[i++] = pInput[loop++];
			}
		}
		else{
			if(pInput[loop] == 'W' || pInput[loop] == 'E'){
				if(pInput[loop] == 'W'){
					flagWest = TRUE;
					hasBoth = TRUE;
				}
				else{
					hasBoth = TRUE;
				}
			}
			else{
				pLongOut[j++] = pInput[loop++];
			}
		}
	}while(!hasBoth);

	// Filling the rest of the array with end of line to avoid
	// having old value when storing new value
	for(--i;i<13;i++){
		pLatOut[i] = '\0';
	}
	
	for(--j;j<13;j++){
		pLongOut[j] = '\0';
	}
}

double coorTranslate(char* pInput, char CD){ // Cardinal Direction Longitude 'O' Latitude 'A'

	double x = atof(pInput);

	switch(CD){
		case 'O':
			if(flagWest){	// if flagWest is true, the negative value is returned
				return (x-(x*2));
			}
			else return x;

		case 'A':
			if(flagSouth){	// if flagWest is true, the negative value is returned
				return (x-(x*2));
			}
			else return x;

		default:
			return x;
	}
}

void getDistance(char* pNMEAIn, char* pSDBuffIn, char* pLatGPSOut, char* pLongGPSOut, char* pLatSDOut, char* pLongSDOut, char* pDistanceOut){

	double tempLongGPS, tempLatGPS, tempLongSD, tempLatSD, tempDist;

	getCoordinate(pNMEAIn, pLatGPSOut, pLongGPSOut);

	getCoordinate(pSDBuffIn, pLatSDOut, pLongSDOut);

	// Storing the coordinate as float in the temp variable for calculation
	// - Storing coordinate read from actuall NMEA message
	tempLatGPS = coorTranslate(pLatGPSOut, 'A');
	tempLongGPS = coorTranslate(pLongGPSOut, 'O');

	// - Stroring the coordinate read from SD card
	tempLatSD = coorTranslate(pLatSDOut, 'A');
	tempLongSD = coorTranslate(pLongSDOut, 'O');

	tempLongSD /= 100;
	tempLatSD /= 100;

	tempLatGPS /= 100;
	tempLongGPS /= 100;

	// Calculate the distance between two coordinate using the haversine formula
	/* Haversine Formula */

	double dLat, dLong;

	dLat = getRadians(tempLatSD - tempLatGPS);
	dLong = getRadians(tempLongSD - tempLongGPS);

	double latGPS = getRadians(tempLatGPS);
	double latSD = getRadians(tempLatSD);

	double a = (sin(dLat/2) * sin(dLat/2)) + (sin(dLong/2) * sin(dLong/2) * cos(latGPS) * cos(latSD));
	double c = 2 * atan2(sqrt(a), sqrt(1-a));

	tempDist = RADIUS * c;

	/* ***************** */

	// Put the distace calculated double back to char array
	dtostrf(tempDist,1,4,pDistanceOut);
}
