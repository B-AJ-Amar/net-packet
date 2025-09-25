#ifndef packet_H
#define packet_H

#define VERSION_MASK 0xF0
#define IHL_MASK     0x0F
#define FLAGS_MASK  0xE000
#define FRAG_OFF_MASK 0x1FFF


#define VERSION_SHIFT 4
#define FLAGS_SHIFT  13


#include <stdio.h>

typedef struct packet_option
{
    __uint8_t  option_type;
    __uint8_t  option_length;
    char *option_data;
}packet_option;


typedef struct packet{
    __uint8_t  version_ihl;
    __uint8_t  type_of_service;
    __uint16_t total_length;
    __uint16_t identification;
    __uint16_t flags_fragment_offset;
    __uint8_t  ttl;
    __uint8_t  protocol;
    __uint16_t header_checksum;
    __uint32_t src_addr;
    __uint32_t dest_addr;
    packet_option* options;
    
    char *data;

};

packet* recv_packet(int sock);
packet* parse_packet_header(char* buffer, int length);

int send_packet(int sock, packet* pkt, int length);
#endif // packet_H