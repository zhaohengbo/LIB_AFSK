#include "fsk_corr_detector.h"

void FSK_Corr_Detector_Init( volatile FSK_Corr_Detector *obj)
{
	markSineSum = 0;
	markCosineSum = 0;
	spaceSineSum = 0;
	spaceCosineSum = 0;
	markPointer = 0;
	spacePointer = 0;
	markSumSquared = 0;
	spaceSumSquared = 0;
	fskScalar = 4.65661287e-10;
	markStep = (obj->mark_freq / obj->isr_freq) * 2.14748365e+09;
	spaceStep = (obj->space_freq / obj->isr_freq) * 2.14748365e+09;
}