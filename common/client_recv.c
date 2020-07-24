/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   client_recv.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 20:57:41 2020/07/24 五
*     > Comment     :
**********************************************************/

#include "head.h"
extern int sockfd;

void *client_recv (void *arg) {
    while (1) {
        struct FootBallMsg msg;
        struct User user;
        bzero (&msg, sizeof (msg));
        recv (sockfd, (void *)&msg, sizeof (msg), 0);
        strcpy (user.name, msg.name);
        user.team = msg.team;
        if (msg.type & FT_HEART) {
            msg.type = FT_ACK;
            send (sockfd, (void *)&msg, sizeof (msg), 0);
        } else if (msg.type & FT_MSG) {

        } else if (msg.type & FT_WALL) {

        } else if (msg.type & FT_FIN) {
            endwin ();
            exit (0);
        } else if (msg.type & FT_MAP) {
            /* parse_spirit (msg.msg, msg.size); */
        } else {

        }
    }
}
