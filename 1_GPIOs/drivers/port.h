#ifndef PORT_H_
#define PORT_H_

#include "R7FA6E10F.h"

#define PORT0           ((R_PORT0_Type *) R_PORT0_BASE)
#define PORT1           ((R_PORT0_Type *) R_PORT1_BASE)
#define PORT2           ((R_PORT0_Type *) R_PORT2_BASE)
#define PORT3           ((R_PORT0_Type *) R_PORT3_BASE)
#define PORT4           ((R_PORT0_Type *) R_PORT4_BASE)
#define PORT5           ((R_PORT0_Type *) R_PORT5_BASE)
#define PORT6           ((R_PORT0_Type *) R_PORT6_BASE)
#define PORT7           ((R_PORT0_Type *) R_PORT7_BASE)
// #define PORT8           ((R_PORT0_Type *) R_PORT8_BASE)
// #define PORT9           ((R_PORT0_Type *) R_PORT9_BASE)
// #define PORT10          ((R_PORT0_Type *) R_PORT10_BASE)
// #define PORT11          ((R_PORT0_Type *) R_PORT11_BASE)
// #define PORT12          ((R_PORT0_Type *) R_PORT12_BASE)
// #define PORT13          ((R_PORT0_Type *) R_PORT13_BASE)
// #define PORT14          ((R_PORT0_Type *) R_PORT14_BASE)

#define HIGH 1
#define LOW  0

enum PORT_MODE{INPUT=0,OUTPUT};

/*  Initialize the port & pin
    param1: PORT   -> port to be used (PORT 0-7)
    param2: pin    -> pin to be used 
                    (P000-008, P014-015)
                    (P100-115)
                    (P200-201, P205-214)
                    (P300-307)
                    (P400-415)
                    (P500-P505)
                    (P600-P602, P608-P610)
                    (P708)
    param3: mode   -> Mode (INPUT(0) or OUTPUT(1))

    retval: void
*/
void PORT_Pin_Init(R_PORT0_Type *PORT, uint8_t pin,  uint8_t mode);
/*  state of the pin
    param1: PORT   -> port to be used (PORT 0-7)
    param2: pin    -> pin to be used 
                    (P000-008, P014-015)
                    (P100-115)
                    (P200-201, P205-214)
                    (P300-307)
                    (P400-415)
                    (P500-P505)
                    (P600-P602, P608-P610)
                    (P708)
    param3: level   -> level (HIGH(1) or LOW(0))

    retval: void
*/
void PORT_Pin_Write(R_PORT0_Type *PORT, uint8_t pin, uint8_t level);
/*  Toggle the state of the particular pin
    param1: PORT   -> port to be used (PORT 0-7)
    param2: pin    -> pin to be used 
                    (P000-008, P014-015)
                    (P100-115)
                    (P200-201, P205-214)
                    (P300-307)
                    (P400-415)
                    (P500-P505)
                    (P600-P602, P608-P610)
                    (P708)

    retval: void
*/
void PORT_Pin_Toggle(R_PORT0_Type *PORT, uint8_t pin);
/*  Read the level of the particular pin
    param1: PORT   -> port to be used (PORT 0-7)
    param2: pin    -> pin to be used 
                    (P000-008, P014-015)
                    (P100-115)
                    (P200-201, P205-214)
                    (P300-307)
                    (P400-415)
                    (P500-P505)
                    (P600-P602, P608-P610)
                    (P708)

    retval: uint16_t Low or High Level
*/
uint16_t PORT_Pin_Read(R_PORT0_Type *PORT,uint16_t pin);

#endif