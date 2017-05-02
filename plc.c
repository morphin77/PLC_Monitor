/*PLC functions */

#define LINUX
#include <stdio.h>
#include <string.h>
#include "nodave.h"
#include "openSocket.h"

/*global vars*/
daveInterface * di;
daveConnection * dc;
_daveOSserialType fds;
daveResultSet rs;

void connect_plc (char address[15], int rack, int slot)
{
  int x;
  char command[45];
  strcpy(command, "ping -c 1 -w 2 ");
  strcat( command, address);
  strcat( command, ">/dev/null");
  x=system(command);
  if (x == 0){
    printf("Целевой узел %s доступен.\n", address);
    fds.rfd = openSocket(102, address); 
    fds.wfd=fds.rfd;
    if (fds.rfd>0)
    {
      printf("Сокет с целевым узлом %s открыт.\n", address);//вывод в лог
      di = daveNewInterface(fds,"IF1",0, daveProtoISOTCP, daveSpeed187k);
      dc = daveNewConnection(di,0,rack, slot);
      if (0==daveConnectPLC(dc)) 
      {
        printf("Успешно подключен к целевому узлу %s\n", address);  
      }
      else
      {
        printf("Нет возможности подключиться с целевому узлу %s.\n", address);
      } 
    } 
    else
    {
      printf("Нет возможности открыть сокет для целевого узла %s.\n", address);//вывод в лог
    }
  }        
  else{
    printf("Целевой узел %s не доступен.\n", address);
  }	
}