/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   sever_exit.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 23:51:09 2020/07/23 四
*     > Comment     :
**********************************************************/

extern struct User *rteam, *bteam;
void server_exit(int signum) {
    struct FootBallMsg msg;
    msg.type = FT_FIN;
    for (int i = 0; i < MAX; i++ ) {
        if (rteam[i].online) send(rteam[i].fd, (void *)&msg, sizeof()msg, 0);
        if (bteam[i].online) send(bteam[i].fd, (void *)&msg, sizeof()msg, 0);
    }
    endwin();
    exit(0);
}
