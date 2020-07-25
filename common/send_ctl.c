/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   send_ctl.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 23:47:12 2020/07/24 五
*     > Comment     :
**********************************************************/

#include "head.h"
extern int sockfd;
extern struct FootBallMsg ctl_msg;
extern WINDOW *Message;

void send_ctl (int signal_num) {
    if (ctl_msg.ctl.dirx || ctl_msg.ctl.diry) {
        ctl_msg.ctl.action = ACTION_DFL;
        send (sockfd, (void *)&ctl_msg, sizeof (ctl_msg), 0);
        ctl_msg.ctl.dirx = ctl_msg.ctl.diry = 0;
        show_data_stream ('n');
    }
}
