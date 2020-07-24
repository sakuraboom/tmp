#include "head.h"


char conf_ans[512] = {0};


char *get_conf_value(const char *path, const char *key) {
    FILE *fp = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int key_flag = 0;

    if ((fp = fopen(path, "r")) == NULL) {
        return NULL;
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        char *tmp;
        int idx;
        if ((tmp = strstr(line, key)) != NULL) {
            idx = strlen(key);
            if (tmp[idx] == '=') {
                key_flag = 1;
                idx++;
                strncpy(conf_ans, &tmp[idx], strlen(tmp) - idx);
                break;
            }
        }
    }
    if (!key_flag) {
        return NULL;
    }
    return conf_ans;
}

void make_non_block(int fd) {
    unsigned long ul = 1;
    ioctl(fd, FIONBIO, &ul);
}


void make_block(int fd) {
    unsigned long ul = 0;
    ioctl(fd, FIONBIO, &ul);
}

int socket_create_udp(int port){
    int listener;
    if((listener = socket_udp()) < 0){
        perror("socket_udp()");
        exit(1);
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(port);
    unsigned long opt = 1;
    setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    make_non_block(listener);
    if(bind(listener, (struct sockaddr *)&server, sizeof(server)) < 0){
        return -1;
    }
    return listener;
}

int socket_udp(){
    return socket(AF_INET, SOCK_DGRAM, 0);
}
