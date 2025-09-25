#ifndef UDP_H
#define UDP_H

#define SRC_PORT_MASK  0xFFFF000000000000
#define DEST_PORT_MASK 0x0000FFFF00000000
#define LENGTH_MASK    0x00000000FFFF0000
#define CHECKSUM_MASK  0x000000000000FFFF

#include <stdio.h>

typedef struct udp_message
{
    __uint16_t src_port;
    __uint16_t dest_port;
    __uint16_t length;
    __uint16_t checksum;
    char *data;
} udp_message;


void parse_udp(char *buffer, int size, udp_message *udp);
int recv_udp(int sockfd, char *buffer, int buffer_size);
int send_udp(int sockfd, const char *buffer, int buffer_size, const char *dest_ip, int dest_port);

#endif // UDP_H