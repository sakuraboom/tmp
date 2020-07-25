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
extern WINDOW *Message;
extern int message_num;
extern struct Map court;

void *client_recv (void *arg) {
    while (1) {
        struct FootBallMsg msg;
        struct User user;
        bzero (&msg, sizeof (msg));
        recv (sockfd, (void *)&msg, sizeof (msg), 0);
        strcpy (user.name, msg.name);
        user.team = msg.team;
        if (msg.type & FT_HEART) {
            /* wclear (Message); */
            /* w_gotoxy_puts (Message, (++message_num) % 5, 1, "HeartBeat from Server\n"); */
            /* printf ("HeartBeat from Server\n"); */
            msg.type = FT_ACK;
            send (sockfd, (void *)&msg, sizeof (msg), 0);
        } else if (msg.type & FT_MSG) {
            char info[512] = {0};
            wclear (Message);
            sprintf (info, "Recv from Server : %s\n", msg.msg);
            w_gotoxy_puts (Message, (++message_num) % 5, 1, info);
            /* printf ("Recv from Server : %s\n", msg.msg); */
        } else if (msg.type & FT_WALL) {
            /* printf ("Recv from Server : %s\n", msg.msg); */
        } else if (msg.type & FT_FIN) {
            printf ("Server is going to stop. \n");
            close (sockfd);
            endwin ();
            exit (0);
        } else if (msg.type & FT_MAP) {
            printf ("Foot Game refresh. \n");
            /* parse_spirit (msg.msg, msg.size); */
        } else {
            printf ("Message unsupport.\n");
        }
    }
}
