#include <stdio.h>
#include <stdlib.h>

#include "trojan_header.h"

int main(int argc, char *argv[]) {
    char * hex = sha224_hex_new("umorepassword1");

    printf("hex : %s\n", hex);

    free(hex);

    uint8_t * ip = host_ip_new("red.ubiznet.com");

    for(int i = 0; i < 4; ++i) {
        if(i != 0) printf(".");
        printf("%d", ip[i]);
    }

    printf("\n");

    free(ip);

    TrojanHeader * header = trojan_header_new("umorepassword1", "red.ubiznet.com", 54321);

    char buff[1024];

    int n = serialize_trojan_header(buff, header);

    printf("n : %d, buff : %s\n", n, buff);

    free(header);

    return 0;
}