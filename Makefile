# makefile
main: main.o plc.o mysql.o libnodave.so
	gcc -o main main.o plc.o mysql.o libnodave.so `$ mysql_config --cflags --libs`

main.o: main.c 
	gcc -c main.c 

plc.o: plc.c
	gcc -c plc.c

mysql.o: mysql.c
	gcc -c mysql.c `$ mysql_config --cflags --libs`

clean:
	rm -f *.o main