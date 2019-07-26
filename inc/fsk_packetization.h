#ifndef FSK_PACKETIZATION_H_
#define FSK_PACKETIZATION_H_

#include <stdint.h>

#define NUMBER_OF_WORDS 3
#define NUMBER_OF_BITS_PER_WORD 11

extern int16_t packet_sum;

// enum for deciphering received packet
enum word{
    word_0 = -1,
    word_1 = 1,
    word_z = 0,
    packet_0 = -3,
    packet_1 = 3,
    packet_z = 0
};

void Packetize(int16_t message[], int16_t packet[]);

#endif // FSK_PACKETIZATION_H_
