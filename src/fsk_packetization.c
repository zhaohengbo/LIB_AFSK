#include "fsk_corr_detector.h"
#include "fsk_packetization.h"

void Packetize(int16_t message[], int16_t packet[])
{
	uint16_t count = 0,new_count = 0;
	int16_t msg_sum = message[0];
	int16_t i;
	packet_sum = 0;
	packet[0] = packet[1] = packet[2] = 0;
	while(1)
	{
		count++;
		if(count >= RX_MESSAGE_SIZE)
		{
			break;
		}
		msg_sum += message[count];
		new_count = (((uint32_t)(count + 1) * 47663) >> 19);// 1/NUMBER_OF_BITS_PER_WORD
		if(((new_count * NUMBER_OF_BITS_PER_WORD) - count ) == (-1))
		{
			packet[new_count - 1] = msg_sum;
			packet_sum += msg_sum;
			msg_sum = 0;
			continue;
		}
	}
	for(i=0;i<RX_MESSAGE_SIZE;i++)
	{
		message[i] = 0;
	}
	bit_sample_counter = 0;
	mark_counter = 0;
	space_counter = 0;
	zero_counter = 0;
}