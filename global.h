#ifndef GLOBAL_H
#define GLOBAL_H

    #ifndef F_CPU
        /// CPU frequency = 7,3728MHz (baud-rate crystal)
        #define F_CPU 7372800UL
    #endif

    /// definition of 'true' when using 8-bit integer as boolean replacement
    #define TRUE 1
    /// definition of 'false'
    #define FALSE 0
    ///ASCII character no. 03 - End of Text
    #define ETX 0x03
    ///ASCII character no. 10 - Linefeed
    #define LF 0x0A    
    ///ASCII character no. 13 - Carriage Return
    #define CR 0x0D

// The values is commented out because it is already
// available in the math.h header
/*
	///PI value to be use for calculation coordinates
    #define M_E 2.71828182845904523536
    #define M_LOG2E 1.44269504088896340736
    #define M_LOG10E 0.434294481903251827651
    #define M_LN2 0.693147180559945309417
    #define M_LN10 2.30258509299404568402
    #define M_PI 3.14159265358979323846
    #define M_PI_2 1.57079632679489661923
    #define M_PI_4 0.785398163397448309616
    #define M_1_PI 0.318309886183790671538
    #define M_2_PI 0.636619772367581343076
    #define M_1_SQRTPI 0.564189583547756286948
    #define M_2_SQRTPI 1.12837916709551257390
    #define M_SQRT2 1.41421356237309504880
    #define M_SQRT_2 0.707106781186547524401
*/

    #define RADIUS 6371

    #include <stdint.h>
    #include <stdlib.h>
    #include <avr/io.h>
    #include <avr/interrupt.h>
    #include <util/delay.h>

    #include <stdio.h>
    #include <string.h>
    #include <math.h>

    /** 
     * \brief Perform a break for a specified time of seconds
     *
     * Although the integrated _delay_ms would allow values large enough to 
     * establish seconds of delaying, the compiled code would be highly 
     * inefficient (i.e. it would take a lot of space). Therefore, several 
     * _delay_ms(250) calls in a row is a better approach for that
     *
     * \param pSeconds An integer containing the seconds that should be spend with
     * doing nothing
     */
    void _delay_s(uint8_t pSeconds);
    
    /**
     * \brief Indicates an error using the LED. !LOOPS FOREVER!
     *
     * Once the error method is called, there is no way back. The code 
     * influences the flashing sequence of the LED. In general, the LED 
     * flashes pCode times with a break of 100ms between each flash, then 
     * the LED is 500ms off and then the whole sequence repeats itself.
     *
     * \param code The error code which shall be displayed. Note: a parameter
     * value of 1 should not be used in order to prevent confusion with the
     * regular flashing pattern
     */
    void error(uint8_t pCode);
    
    /**
     * \brief Checks if the given string starts with the given pattern
     *
     * Both Strings have to be NULL-Terminated! pString will not be modified

     * in any way (in fact, it can't because of the const declaration).
     *
     * \param pString The string which should be checked
     * \param pPattern The pattern for which will be checked in pString
     * \return TRUE if the string starts with the pattern, FALSE otherwise

     */
    uint8_t strStartsWith(const char *pString, char *pPattern);
    
    /**
     * \brief Takes a character and returns its equivalent integer
     * 

     * \param pChar a char from the set {0,1,...,9,A,B,...,F,a,b,...,f}
     * \return An integer containing the value of the given hexadecimal character
     * or 0 if the character hasn't been recognized
     */
    uint8_t hexCharToInt(char pChar);    
#endif
