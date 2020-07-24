/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   send_chat.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 23:55:05 2020/07/24 五
*     > Comment     :
**********************************************************/

#include "head.h"
extern int sockfd;
extern WINDOW *Write;
extern struct FootBallMsg chat_msg;

void send_chat () {
    echo ();
    nocbreak ();
    bzero (chat_msg.msg, sizeof (chat_msg.msg));
    chat_msg.type = FT_WALL;
    w_gotoxy_puts (Write, 1, 1, "Input Message : ");
    mvwscanw (Write, 2, 1, "%[^\n]s", chat_msg.msg);
    if (strlen (chat_msg.msg)) send (sockfd, (void *)&chat_msg, sizeof (chat_msg), 0);
    wclear (Write);
    box (Write, 0, 0);
    wrefresh (Write);
    noecho ();
    cbreak ();
}
