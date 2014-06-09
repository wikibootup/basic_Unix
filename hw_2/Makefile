#Makefile

recoder : recoder.o
						gcc -o recoder recoder.o
						gcc -o gambler gambler.o
#gambler : gambler.o
#						gcc -o gambler gambler.o
recoder.o : recoder.c
						gcc -c recoder.c
						gcc -c gambler.c
gambler.o : gambler.c
						gcc -c gambler.c

clean :
				rm gambler.o gambler recoder.o recoder
