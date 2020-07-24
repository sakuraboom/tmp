#ifndef _COMMON_H
#define _COMMON_H
char *get_conf_value(const char *path, const char *key);
void make_non_block(int fd);
void make_block(int fd);
int socket_create_udp(int port);
int socket_udp();
#endif