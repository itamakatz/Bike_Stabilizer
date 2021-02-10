#ifndef __GENETAL_DEFS__
#define __GENETAL_DEFS__

// ============================== GPIO parameters ================================= //

#define LED_PIN 13
#define CHECK_SIGNAL_OUT 36

//  AnalogWrite
#define ANALOGWRITE_BIT_RESOLUTION 16
#define ANALOGWRITE_FREQUENCY 915.527 // for 180MHz CPU
#define MIN_ANALOGWRITE_VALUE 0
#define MAX_ANALOGWRITE_VALUE 65535 

// PWM
#define MIN_POSSIBLE_OUTPUT 0
#define MAX_POSSIBLE_OUTPUT 2048

// ============================ Cyclic Array Parameters =========================== //

#define CYC_ARRAY_SIZE 	50
#define sixDOF_ALPHA 	(float)0.01

// ============================== Delays and Metros =============================== //

#define INITIAL_DELAY_sixDOF 			60
#define INITIAL_DELAY_main_ino 			1000

#define CRITICAL_DELAY_LOOP_main_ino 	5 // 300 // 60

#define METRO_LED_HIGH_INTERVAL 		250 // blincking led 
#define METRO_GENERAL_INTERVAL 			500
#define METRO_LED_LOW_INTERVAL 			1000 // blincking led 
#define METRO_PRINT_INTERVAL 			1000 // print results
#define METRO_BIG_NUM 					50000 // dummy for initialization
#define METRO_CHECK_SERIAL_INTERVAL 	1500

// piezo
#define PIEZO_PIN 35
#define PIEZO_RESONANCE 250 // (from 2040?)
enum Piezo_modes { none, on, off, piezo_set_target_angles };
#define PIEZO_TONE map(PIEZO_RESONANCE, 0, 1024, MIN_ANALOGWRITE_VALUE, MAX_ANALOGWRITE_VALUE)

#define EULER_YAW_INDEX 0
#define EULER_PITCH_INDEX 1
#define EULER_ROLL_INDEX 2

#endif