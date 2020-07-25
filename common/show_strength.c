/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   show_strength.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 00:39:52 2020/07/25 六
*     > Comment     :
**********************************************************/

#include "head.h"
extern WINDOW *Write;
extern int sockfd;

void show_strength () {
    int maxx, maxy, strength;
    getmaxyx (Write, maxy, maxx);
    struct FootBallMsg msg;
    bzero (&msg, sizeof (msg));
    for (int i = 2; i < maxx - 2; i++) {
        if (i < maxx / 5 || i > (maxx - maxx / 5)) {
            wattron (Write, COLOR_PAIR (8));
        } else if (i < 2 * maxx / 5 || i > 3 * maxx / 5) {
            wattron (Write, COLOR_PAIR (9));
        } else {
            wattron (Write, COLOR_PAIR (10));
        }
        mvwaddch (Write, 2, i, ' ');
    }
    wattron (Write, COLOR_PAIR (3));
    int tmp[5] = {1, 2, 3, 2, 1};
    int offset = 1;
    int tmp_x = 2;
    make_non_block (0);
    while (1) {
        int c = getchar ();
        if (c != -1) {
            if (c == ' ' || c == 'k') {
                mvwaddch (Write, 1, tmp_x, ' ');
                mvwaddch (Write, 3, tmp_x, ' ');
                make_block (0);
                break;
            }
        }
        usleep (5000);
        mvwaddch (Write, 1, tmp_x, ' ');
        mvwaddch (Write, 3, tmp_x, ' ');
        tmp_x += offset;
        mvwaddch (Write, 1, tmp_x, '|');
        mvwaddch (Write, 3, tmp_x, '|');
        mvwaddch (Write, 4, maxx, ' ');
        if (tmp_x >= maxx - 2) offset = -1;
        if (tmp_x <= 2) offset = 1;
        wrefresh (Write);
    }
    char info[512] = {0};
    sprintf (info, "strength = %d", tmp[tmp_x / (maxx / 5)]);
    printf  ("%s\n", info);
    msg.type = FT_CTL;
    msg.ctl.action = ACTION_KICK;
    msg.ctl.strength = tmp [tmp_x / (maxx / 5)];
    send (sockfd, (void *)&msg, sizeof (msg), 0);
}
