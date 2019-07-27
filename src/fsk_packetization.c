#include "fsk_corr_detector.h"
#include "fsk_packetization.h"

void Packetize(int16_t message[], int16_t packet[])
{
	uint16_t read_count = 0,write_count = 0;
	int16_t msg_sum = message[0];
	int16_t i;
	packet_sum = 0;
	packet[0] = packet[1] = packet[2] = 0;
	while(1)
	{
		read_count++;
		if(read_count >= RX_MESSAGE_SIZE)
		{
			break;
		}
		msg_sum += message[read_count];
		write_count = (((uint32_t)(read_count + 1) * 47663) >> 19);// 1/NUMBER_OF_BITS_PER_WORD
		/*
		 *  This is just a simple way to make ((read_count % NUMBER_OF_BITS_PER_WORD) == 0)
		 *  , where mod cost a long time and can be optimized.
		 *  w  r
		 *  0  10
		 *  1  21
		 *  2  32
		 */
		if((read_count - (write_count * NUMBER_OF_BITS_PER_WORD)) == (-1))
		{
			packet[write_count - 1] = msg_sum;
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