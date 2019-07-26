#include "fsk_corr_detector.h"

uint16_t mark_counter, space_counter, zero_counter, bit_sample_counter;

void FSK_Corr_Detector_OverSample_Run(volatile FSK_Corr_Detector *obj)
{
	markSumSquared = ((markCosineSum * markCosineSum) + (markSineSum * markSineSum)) / ((obj->isr_freq / (obj->bit_freq * 2.0)) * (obj->isr_freq / (obj->bit_freq * 2.0)));
	spaceSumSquared = ((spaceCosineSum * spaceCosineSum) + (spaceSineSum * spaceSineSum)) / ((obj->isr_freq / (obj->bit_freq * 2.0)) * (obj->isr_freq / (obj->bit_freq * 2.0)));
	
	if((markSumSquared > obj->detection_threshold) || (markSumSquared > obj->detection_threshold))
	{
		if(markSumSquared > obj->detection_threshold)
		{
			mark_counter++;
		}
		if(markSumSquared > obj->detection_threshold)
		{
			space_counter++;
		}
		bit_sample_counter++;
		
	}
	else
	{
		zero_counter++;
		if(bit_sample_counter != 0)
		{
			bit_sample_counter++;
		}
	}
	
	if(bit_sample_counter > 2)
	{
		if((space_counter < mark_counter) && (mark_counter > 1))
		{
			obj->bit_detected = 1;
		}
		else if((space_counter > mark_counter) && (space_counter > 1))
		{
			obj->bit_detected = -1;
		}
		else
		{
			obj->bit_detected = 0;
		}
		
		bit_sample_counter = 0;
		mark_counter = 0;
		space_counter = 0;
		zero_counter = 0;
	}
	
	markSineSum = 0;
	markCosineSum = 0;
	spaceSineSum = 0;
	spaceCosineSum = 0;
}

void FSK_Corr_Detector_Bitrate_Run(volatile FSK_Corr_Detector *obj)
{
	markSumSquared = ((markCosineSum * markCosineSum) + (markSineSum * markSineSum)) / ((obj->isr_freq / (obj->bit_freq * 2.0)) * (obj->isr_freq / (obj->bit_freq * 2.0)));
	spaceSumSquared = ((spaceCosineSum * spaceCosineSum) + (spaceSineSum * spaceSineSum)) / ((obj->isr_freq / (obj->bit_freq * 2.0)) * (obj->isr_freq / (obj->bit_freq * 2.0)));
	
	if((markSumSquared > obj->detection_threshold) && (spaceSumSquared < obj->detection_threshold))
	{
		obj->bit_detected = 1;
	}
	else if((spaceSumSquared > obj->detection_threshold) && (markSumSquared < obj->detection_threshold))
	{
		obj->bit_detected = -1;
	}
	else
	{
		obj->bit_detected = 0;
	}
	
	markSineSum = 0;
	markCosineSum = 0;
	spaceSineSum = 0;
	spaceCosineSum = 0;
}