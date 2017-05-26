/*main programm */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mysql/my_global.h>
#include <mysql/mysql.h>
#include "plc.h"

struct db_params{
  char host[50];
  char user[50];
  char password[50];
  char database[50];
};  

#include "file.h"

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}



int main (void){
  
  MYSQL *con = mysql_init(NULL);
  
  if (con == NULL)
  {
    fprintf(stderr, "mysql_init() failed\n");
    exit(1);
  }
  else
  { 	
  	log_it("MySQL клиент готов к подключению.\n");
    struct db_params param;
	  read_config(param);
    printf("%s\n", param.host);
    printf("%s\n", param.user);
    printf("%s\n", param.password);
    printf("%s\n", param.database);
  	if (mysql_real_connect(con, "localhost", "root", "sad56das", "testdb", 0, NULL, 0) == NULL) 
  	{
      finish_with_error(con);
  	}
  	else
  	{
  		log_it("Аутентификация прошла успешно.\n");
  		
  		if (mysql_query(con, "SELECT ip_address, rack, slot FROM PLC")) 
  		{
      	finish_with_error(con);
  		}
  	}    
  }   
  
  MYSQL_RES *result = mysql_store_result(con);
  
  if (result == NULL) 
  {
    finish_with_error(con);
  }
  else
  {
  	log_it("Данные о ПЛК успешно получены из базы данных.\n");
	}

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;
  
  while ((row = mysql_fetch_row(result))) 
  { 
    connect_plc(row[0], atoi(row[1]), atoi(row[2])); 
  }
  
  mysql_free_result(result);
  mysql_close(con);
}      


    