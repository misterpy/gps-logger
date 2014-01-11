#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define bool int
#define TRUE 1
#define FALSE 0
#define RADIUS	6371

	void getCoordinate(char* pInput, char* pLatOut, char* pLongOut);

	double coorTranslate(char* pInput, char CD);

/*
	Parameter pLatGPSOut and pLongGPSOut is the latitude and the longitude
	taken from the actuall NMEA message from the GPS module.

	Parameter pLatSDOut and pLongSDOut will be the coordinate read from the SD card.
*/
	void getDistance(char* pNMEAIn, char* pSDBuffIn, char* pLatGPSOut, char* pLongGPSOut, char* pLatSDOut, char* pLongSDOut, char* pDistanceOut);

/*
	This functions input the coordinate in degree and return the value in radians
*/
	double getRadians(double degree);

char nmeabuff[] = {'$','G','P','G','L','L',',','4','2','5','0','.','5','5','8',',','S',',','1','4','7','1','8','.','5','0','8','4',',','E',',','0','9','2','2','0','4','.','9','9','9',',','A',',','A','*','2','D','<','C','R','>','<','L','F','>','\0'};
char sdbuff[] = {'$','G','P','G','L','L',',','4','1','3','0','.','5','0','0',',','N',',','1','3','4','2','3','.','7','0','3','4',',','E',',','0','9','2','2','0','4','.','9','9','9',',','A',',','A','*','2','D','<','C','R','>','<','L','F','>','\0'};

// Value of Latitude, Longitude and distance will be stored here
// for further used such as displaying on the LCD and storing
// into the SD Card
char pLatGPS[11];
char pLongGPS[11];

char pLatSD[11];
char pLongSD[11];

char pDistance[20];

// this flags is needed for distance calculation
bool flagSouth = FALSE;
bool flagWest = FALSE;

void getCoordinate(char* pInput, char* pLatOut, char* pLongOut){

	int i=0;
	int j=0;
	int loop=7;

	// flag for controlling loop
	bool hasBoth = FALSE;
	bool hasLat = FALSE;

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
	sprintf(pDistanceOut, "%.4f", tempDist);
}

double getRadians(double degree){
	return (degree * (M_PI/180));
}

int main(){

	getDistance(nmeabuff, sdbuff, pLatGPS, pLongGPS, pLatSD, pLongSD, pDistance);

	printf("The pLatGPS is %s \n", pLatGPS);

	printf("The pLongGPS is %s \n", pLongGPS);

	printf("The pLatSD is %s \n", pLatSD);

	printf("The pLongSD is %s \n", pLongSD);

	printf("The distance is %s \n", pDistance);

};