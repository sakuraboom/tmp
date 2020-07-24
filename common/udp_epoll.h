#ifndef _UDP_EPOLL_H
#define _UDP_EPOLL_H
void add_event_ptr(int epollfd, int fd, int events, struct User *user);
void del_event(int epollfd, int fd);
int udp_connect(struct sockaddr_in *client);
int check_online (struct LogRequest *request);
int udp_accept(int fd, struct User *user);
void add_to_sub_reactor(struct User *user);
#endif
