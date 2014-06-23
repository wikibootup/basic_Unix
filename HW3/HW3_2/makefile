#Makefile

IPC_Socket_server	: IPC_Socket_server.o
					gcc -o	IPC_Socket_server	IPC_Socket_server.c
					gcc -o	IPC_Socket_client	IPC_Socket_client.c
					gcc -o	IPC_Socket_client2	IPC_Socket_client2.c


IPC_Socket_client	: IPC_Socket_client.o
					gcc -o	IPC_Socket_server		IPC_Socket_server.c
					gcc -o	IPC_Socket_client		IPC_Socket_client.c
					gcc -o	IPC_Socket_client2		IPC_Socket_client2.c

IPC_Socket_server.o :	IPC_Socket_server.c
					gcc -c IPC_Socket_server.c
					gcc -c IPC_Socket_client.c
					gcc -c IPC_Socket_client2.c

IPC_Socket_client.o :	IPC_Socket_client.c
					gcc -c IPC_Socket_server.c
					gcc -c count_process_client.c
					gcc -c count_process_client2.c

IPC_Socket_client2.o :	IPC_Socket_client2.c
					gcc -c IPC_Socket_server.c
					gcc -c count_process_client.c
					gcc -c count_process_client2.c



clean :
					rm IPC_Socket_server.o
					rm IPC_Socket_server	
					rm IPC_Socket_client.o
					rm IPC_Socket_client
					rm IPC_Socket_client2.o
					rm IPC_Socket_client2


#


  

