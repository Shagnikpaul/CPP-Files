#include "stdio.h"
#include "string.h"
#include "winsock2.h"
#include "unistd.h"


int main() {
    int serv = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in adr = {0};
    adr.sin_family = AF_INET;
    adr.sin_addr.S_un = IN_ADDR
}

