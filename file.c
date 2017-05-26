#include <stdio.h>
#include <time.h>
#include <string.h>

void log_it(char *message){
	FILE *log = fopen("log.txt", "a");
	time_t t = time(NULL);
	struct tm* aTm = localtime(&t);
	fprintf(log, "%04d/%02d/%02d %02d:%02d:%02d: %s", aTm->tm_year+1900, aTm->tm_mon+1, aTm->tm_mday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec, message);
	fflush(log);
	fclose(log);
}

void read_config(struct db_params params){
	FILE *config = fopen("conf", "r");
	char str[50];
	char *estr;

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
    //Если файл не закончился, и не было ошибки чтения 
    //выводим считанную строку  на экран
    
    if (strncmp(str, "host=", 5)==0){
    	strcpy(params.host, str);
    }
    if (strncmp(str, "user=", 5)==0){
    	strcpy(params.user, str);
    }
    if (strncmp(str, "password=", 9)==0){
    	strcpy(params.password, str);
    }
    if (strncmp(str, "database=", 9)==0){
    	strcpy(params.database, str);
    }
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
}