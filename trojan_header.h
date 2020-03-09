#ifndef _TROJAN_HEADER_H_
#define _TROJAN_HEADER_H_

#include <stdlib.h>
#include <stdint.h>

#define TROJAN_HEADER_HEX_SIZE 56
#define TROJAN_HEADER_IP_SIZE 4

// TrojanHeader is ...
// Only support IPv4...
// +-----------------------+---------+----------------+---------+----------+
// | hex(SHA224(password)) |  CRLF   | Trojan Request |  CRLF   | Payload  |
// +-----------------------+---------+----------------+---------+----------+
// |          56           | X'0D0A' |    Variable    | X'0D0A' | Variable |
// +-----------------------+---------+----------------+---------+----------+
// where Trojan Request is a SOCKS5-like request:
// +-----+------+----------+----------+
// | CMD | ATYP | DST.ADDR | DST.PORT |
// +-----+------+----------+----------+
// |  1  |  1   | Variable |    2     |
// +-----+------+----------+----------+
// where:
// 	o  CMD
// 		o  CONNECT X'01'
// 		o  UDP ASSOCIATE X'03'
// 	o  ATYP address type of following address
// 		o  IP V4 address: X'01'
// 		o  DOMAINNAME: X'03'
// 		o  IP V6 address: X'04'
// 	o  DST.ADDR desired destination address
// 	o  DST.PORT desired destination port in network octet order
typedef struct TrojanHeader {
    uint8_t hex[TROJAN_HEADER_HEX_SIZE];
    uint8_t sepa0[2];
    uint8_t cmd;
    uint8_t type;
    uint8_t IP[TROJAN_HEADER_IP_SIZE];
    uint16_t port;
    uint8_t sepa1[2];
} TrojanHeader;

char * sha224_hex_new(const char *p);
uint8_t * host_ip_new(const char * hostname);

TrojanHeader * trojan_header_new(const char * password, const char *host_name, uint16_t port);
int serialize_trojan_header(char * buff, const TrojanHeader * header);

#endif
