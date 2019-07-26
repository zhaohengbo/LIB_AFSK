#ifndef FSK_CORR_DETECT_INCLUDE_H
#define FSK_CORR_DETECT_INCLUDE_H

#include <stdint.h>

#define RX_MESSAGE_SIZE 33  // Number of bits to receive

typedef struct{
	float mark_freq;
	float space_freq;
	float isr_freq;
	float bit_freq;
	float detection_threshold;
	int16_t bit_detected; // +1 mark, -1 space, 0 zero energy or unspecified frequency
}FSK_Corr_Detector;

extern uint16_t mark_counter, space_counter, zero_counter, bit_sample_counter;
//extern uint16_t mark_detect[RX_MESSAGE_SIZE], space_detect[RX_MESSAGE_SIZE], n; // Used for debug

void FSK_Corr_Detector_Init( volatile FSK_Corr_Detector *obj);
void FSK_Corr_Detector_Bitrate_Run(volatile FSK_Corr_Detector *obj);
void FSK_Corr_Detector_Run(volatile float adc_value);
void FSK_Corr_Detector_OverSample_Run(volatile FSK_Corr_Detector *obj);

#endif
