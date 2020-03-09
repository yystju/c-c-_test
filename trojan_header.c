#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <openssl/sha.h>
#include <openssl/crypto.h>

#include "trojan_header.h"

void print_hex(unsigned char *md, int len, char * output);

TrojanHeader * trojan_header_new(const char * password, const char *host_name, uint16_t port) {
    TrojanHeader * p = malloc(sizeof(TrojanHeader));

    char * hex = sha224_hex_new(password);

    memset(p->hex, '\0', TROJAN_HEADER_HEX_SIZE);
    strncpy((char *)p->hex, hex, strlen(hex));

    free(hex);

    uint8_t * ip = host_ip_new(host_name);

    memcpy(p->IP, ip, sizeof(uint8_t) * 4);

    free(ip);

    p->cmd = 0x01;
    p->type = 0x01;
    p->port = htons(port);

    p->sepa0[0] = 0x0D;
    p->sepa0[1] = 0x0A;

    p->sepa1[0] = 0x0D;
    p->sepa1[1] = 0x0A;

    return p;
}

int serialize_trojan_header(char * buff, const TrojanHeader* header) {
    int n = 0;

    uint8_t * p = (uint8_t *)header;

    for(int i = 0; i < sizeof(TrojanHeader); ++i) {
        uint8_t b = p[i];

        n += sprintf(buff + (i * 2), "%02x", b);
    }

    return n;
}

// IPv4 only...
uint8_t * host_ip_new(const char * hostname) {
    struct hostent *host_entry;
    struct in_addr ip_addr;

    uint8_t * ret = malloc(sizeof(uint8_t) * 4);

    host_entry = gethostbyname(hostname);

    ip_addr = *(struct in_addr *)(host_entry->h_addr);

    unsigned long addr = ip_addr.s_addr;

    for(int i = 0; i < 4; ++i) {
        unsigned char p = (unsigned char)(addr & 0xFF);

        addr = addr >> 8;

        ret[i] = p;
    }

    return ret;
}

char * sha224_hex_new(const char *p) {
    SHA256_CTX c;

    char * ret = (char *) malloc(sizeof(char) * (SHA224_DIGEST_LENGTH * 2 + 1));
	unsigned char md[SHA224_DIGEST_LENGTH];

	SHA224_Init(&c);
	SHA224_Update(&c, p, strlen(p));
	SHA224_Final(md, &c);
	OPENSSL_cleanse(&c, sizeof(c));

	print_hex(md, SHA224_DIGEST_LENGTH, ret);

    return ret;
}

void print_hex(unsigned char *md, int len, char * output) {
	int i = 0;

	for (i = 0; i < len; i++) {
        sprintf(output + (i * 2), "%02x", md[i]);
	}

    output[2*len + 1] = 0;
}
