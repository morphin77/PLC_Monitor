#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "file.h"

void log_it(char *message){
	FILE *log = fopen("log.txt", "a");
	time_t t = time(NULL);
	struct tm* aTm = localtime(&t);
	fprintf(log, "%04d/%02d/%02d %02d:%02d:%02d: %s", aTm->tm_year+1900, aTm->tm_mon+1, aTm->tm_mday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec, message);
	fflush(log);
	fclose(log);
}

char* get_config_parametr(char str[255], char parametr[20], char varvalue[32]){
	char * pos;
  int delimiter = '=';
  int posend;
  
	if (strncmp (str,parametr,4) == 0){
  	pos = strchr(str, delimiter);
   	if (pos) {  
   		posend = abs (str - pos);
     	strncpy(varvalue,str + posend + 1,strlen(str) - posend);
     	varvalue[strlen(varvalue)-1]=0;
  	}	
  }	
}

struct db_params read_config(){
	FILE *config = fopen("conf", "r+b");
	char str[255];
	char *estr;
	struct db_params params;
	
  if (config == NULL) {
  	log_it("Ошибка открытия файла конфигурации.\n");
  }
  else{
  	log_it("Файл конфигурации найден.\n");
  }
  //Чтение (построчно) данных из файла в бесконечном цикле
  while (1)
  {
    // Чтение одной строки  из файла
    estr = fgets (str,sizeof(str),config);

    //Проверка на конец файла или ошибку чтения
    if (estr == NULL)
    {
      // Проверяем, что именно произошло: кончился файл
      // или это ошибка чтения
      if ( feof (config) != 0)
      {  
        break;
      }
      else
      {
        log_it("Ошибка чтения файла конфигурации.\n");
        break;
      }
    }
    else
    {
    	get_config_parametr(str,"host", params.host);
    	get_config_parametr(str,"user", params.user);
    	get_config_parametr(str,"password", params.password);
    	get_config_parametr(str,"database", params.database);
    }
    //Если файл не закончился, и не было ошибки чтения 
    //выводим считанную строку  на экран
  }

  // Закрываем файл
  if ( fclose (config) == EOF)
  {
  	log_it("Ошибка при закрытии файла конфигурации.\n");
  } 
  else
  {
  	log_it("Данные успешно прочитаны.\n");
  }
  return params;
}