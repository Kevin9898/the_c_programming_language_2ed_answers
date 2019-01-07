all:
	gcc a.c -g -o a.o -std=c89
htoi: htoi.c htoi.h test_htoi.c
	gcc -g test_htoi.c htoi.c -o htoi.out -std=c89
clean:
	rm *.o *.out
