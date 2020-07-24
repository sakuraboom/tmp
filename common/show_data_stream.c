/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   show_data_stream.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 00:27:25 2020/07/25 六
*     > Comment     :
**********************************************************/

#include "head.h"
extern char data_stream[20];
extern WINDOW *Help;
extern struct Map court;

void show_data_stream (int type) {
    for (int i = 17; i >= 1; i--){
        data_stream[i + 1] = data_stream[i];
    }
    data_stream[1] = type;
    for (int i = 1; i <= 18; i++) {
        if (data_stream[i] == 'l') {
            wattron (Help, COLOR_PAIR (10));
        } else if (data_stream[i] == 'c') {
            wattron (Help, COLOR_PAIR (9));
        } else if (data_stream[i] == 'k') {
            wattron (Help, COLOR_PAIR (12));
        } else if (data_stream[i] == 's') {
            wattron (Help, COLOR_PAIR (11));
        } else if (data_stream[i] == 'n') {
            wattron (Help, COLOR_PAIR (8));
        } else if (data_stream[i] == 'e') {
            wattron (Help, COLOR_PAIR (10));
        }
        w_gotoxy_putc (Help, i, court.height, ' ');
    }
}
