#include "fsk_corr_detector.h"
#include <math.h>

void FSK_Corr_Detector_Run(volatile float adc_value)
{
	markPointer = (markPointer + markStep) & 0x7FFFFFFF;
	spacePointer = (spacePointer + spaceStep) & 0x7FFFFFFF;
	markSineSum = markSineSum + sin((markPointer * fskScalar)*2*M_PI) * adc_value;
	markCosineSum = markCosineSum + cos((markPointer * fskScalar)*2*M_PI) * adc_value;
	spaceSineSum = spaceSineSum + sin((spacePointer * fskScalar)*2*M_PI) * adc_value;
	spaceCosineSum = spaceCosineSum + cos((spacePointer * fskScalar)*2*M_PI) * adc_value;
}