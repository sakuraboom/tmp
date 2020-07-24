# *****************************************************
#     > Do Androids Dream of Electric Sheep? 
#     > File Name   :  Makefile
#     > Author      :  spike
#     > Email       :  Gehirn@yeah.net
#     > Create time :  CST 13:43:18 2020/07/23 四
#     > Comment     :
# *****************************************************


make : client.c show_strength.o show_data_stream.o common.o game_ui.o client_recv.o send_ctl.o send_chat.o 
	gcc client.c show_strength.o show_data_stream.o client_recv.o send_chat.o send_ctl.o game_ui.o common.o -I ../common/ -o client -lncursesw -lpthread

common.o :
	gcc ../common/common.c -c 

game_ui.o :
	gcc ../common/game_ui.c -c 

send_chat.o :
	gcc ../common/send_chat.c -c

client_recv.o :
	gcc ../common/client_recv.c -c

send_ctl.o :
	gcc ../common/send_ctl.c -c

show_data_stream.o :
	gcc ../common/show_data_stream.c -c

show_strength.o :
	gcc ../common/show_strength.c -c

open :
	vim ./client.c

run :
	./client

clean :
	rm *.o
