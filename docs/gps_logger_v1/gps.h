//gps.h

#ifndef GPS_H
#define GPS_H

#define GPS_ACK 0x83
#define GPS_NACK 0x84

// Some commands that may be used
#define GPS_GET_UPDATE_RATE 0x10
#define GPS_GET_DATE 0x2D
#define GPS_GET_1PPS 0x3F

#define GPS_SET_BAUDRATE 0x05
#define GPS_SET_NMEA 0x08
#define GPS_SET_POWER 0x0C
#define GPS_SET_UPDATE_RATE 0x0E
#define GPS_SET_1PPS 0x3E

// Indicators if NMEA Message is valid or invalid (validity differs for each Message type)
#define GPS_NMEA_VALID 0x01
#define GPS_NMEA_INVALID 0x00

// Possible NMEA-Messages that may be returned
#define GPS_NMEA_GGA 0x02 // 0b00000010 // Note: bit 0 can't be used, is an indicator
#define GPS_NMEA_GSA 0x04 // 0b00000100 // for validity of the message
#define GPS_NMEA_GSV 0x08 // 0b00001000
#define GPS_NMEA_GLL 0x10 // 0b00010000
#define GPS_NMEA_RMC 0x20 // 0b00100000
#define GPS_NMEA_VTG 0x40 // 0b01000000
#define GPS_NMEA_ZDA 0x80 // 0b10000000

// The value which is returned when no known NMEA-command has been recognized
#define GPS_NMEA_UNKNOWN 0

// A bitmask to extract the message type from a getNMEA return value
#define GPS_NMEA_TYPEMASK 0xFE

// BAUD-Rate of the serial interface
#define GPS_BAUDRATE 9600UL

/*
Initializes the GPS-module. Locks the processor in case of error

The parameters can be used to configure the output produced by the GPS.
Please note that certain limitations exist for the parameters values.

Parameter pFrequency is the frequency (in Hertz) in which NMEA-sentences should be returned.
The module supports only a value of the set {1,2,4,5,8,10}.
Only the value {1} are supported by the gLogger-Firmware right now!
Higher frequencies may or may not work.

Parameter pMessages is a bitset containing the messages which should be returned in each message block. Multiple messages can be selected by using the OR-operator on the constant values. Possible constant values are {GPS_NMEA_GGA, GPS_NMEA_RMC, GPS_NMEA_GSA, GPS_NMEA_GSV, GPS_NMEA_GLL, GPS_NMEA_VTG, GPS_NMEA_ZDA}.
*/
    void gps_init(uint8_t pFrequency, uint8_t pMessages);

/*
Sets a parameter of the GPS-module to a given value

Parameter pCommand is the parameter which should be set (see constants).
Parameter pData is the data which should be written for this parameter.
Return value GPS_ACK on success, otherwise GPS_NACK.
*/
    unsigned char gps_setParam(unsigned char pCommand, unsigned char* pData, uint16_t pLength);
  
/*
Checks if the given sentence meets the criteria for a valid message

This method checks several properties, some of them will only indicate if the message can be considered as "valid" or not, others will say more generally if the given message is in a correct format.

In detail, the method sweeps through the sentence once, while:
- Performing a prefix check (return instantly if invalid)
- Searching for pValidityToken and comparing it with pValidityCheck
- Calculating the checksum and comparing it to given one (if given)

Parameter pSentence is the sentence which shall be checked.
Parameter pMessageType is the message type which is expected.
Parameter pPrefix is the prefix (== message type) that the sentence is supposed to have.
Parameter pValidityToken is the index of a token (a token is delimited by commas) in which a validity information can be found. Set to 0 if no validity check should be performed. Token 1 begins after the first comma (i.e. the first data after the "$GP..." type string).
Parameter pValidityCheck is a string to which the validityToken should be compared.
Parameter pCheckEquality is if TRUE, the sentence is considered valid if the validityToken equals the validityCheck string, otherwise if they are unequal.
Return value GPS_NMEA_UNKNOWN if the message has a corrupt format (i.e. prefix or checksum mismatch), otherwise a composition of GPS_NMEA_<TYPE> | {GPS_NMEA_VALID or GPS_NMEA_INVALID}. If pValidityToken is zero, GPS_NMEA_VALID will be returned in combination with the type as we assume that this specific message type is always valid.
*/
    uint8_t gps_checkNMEA(const char* pSentence, uint8_t pMessageType,
        char* pPrefix, uint8_t pValidityToken, char* pValidityCheck,
        uint8_t pCheckEquality);

/*
Writes a NMEA-String into the given output buffer and returns its type.

Parameter pOutput is the buffer in which the NMEA string shall be written.
Parameter pMaxLength The buffer's maximal length.
Return value is a byte composed of the message type (bits 1-7) and a bit indicating if the message is valid or not (bit 0).
*/
    uint8_t gps_getNMEA(char* pOutput, uint8_t pMaxLength);
#endif
