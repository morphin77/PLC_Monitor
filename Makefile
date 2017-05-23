# makefile
plcmd: main.o plc.o file.o libnodave.so 
	gcc -o plcmd main.o plc.o file.o libnodave.so `$ mysql_config --cflags --libs`

main.o: main.c 
	gcc -c main.c `$ mysql_config --cflags --libs`

file.o: file.c
	gcc -c file.c

plc.o: plc.c
	gcc -c plc.c

clean:
	rm -f *.o main

#install:
	#sudo apt-get install mysql-server mysql-client libmysqlclient-dev