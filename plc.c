/*PLC functions */

#define LINUX
#include <stdio.h>
#include <string.h>
#include "nodave.h"
#include "openSocket.h"
#include "file.h"

/*global vars*/
daveInterface * di;
daveConnection * dc;
_daveOSserialType fds;
daveResultSet rs;

void connect_plc (char address[15], int rack, int slot)
{
  char message[255];
  int x;
  char command[45];
  strcpy(command, "ping -c 1 -w 2 ");
  strcat( command, address);
  strcat( command, ">/dev/null");
  x=system(command);
  if (x == 0){
    
    strcpy(message, "Целевой узел ");
    strcat(message, address);
    strcat(message, " доступен.\n");
    log_it(message);
    strcpy(message, "");

    fds.rfd = openSocket(102, address); 
    fds.wfd=fds.rfd;
    if (fds.rfd>0)
    {
      strcpy(message, "Сокет с целевым узлом ");
      strcat(message, address);
      strcat(message, " открыт.\n");
      log_it(message);
      strcpy(message, "");
      di = daveNewInterface(fds,"IF1",0, daveProtoISOTCP, daveSpeed187k);
      dc = daveNewConnection(di,0,rack, slot);
      if (0==daveConnectPLC(dc)) 
      {
        strcpy(message, "Успешно подключен к целевому узлу ");
        strcat(message, address);
        strcat(message, "\n");
        log_it(message);
        strcpy(message, "");
      }
      else
      {
        strcpy(message, "Нет возможности подключиться с целевому узлу ");
        strcat(message, address);
        strcat(message, "\n");
        log_it(message);
        strcpy(message, "");
      } 
    } 
    else
    {
      strcpy(message, "Нет возможности открыть сокет для целевого узла ");
      strcat(message, address);
      strcat(message, "\n");
      log_it(message);
      strcpy(message, "");
    }
  }        
  else{
    strcpy(message, "Целевой узел ");
    strcat(message, address);
    strcat(message, " не доступен.\n");
    log_it(message);
    strcpy(message, "");
  }	
}