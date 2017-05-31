/*main programm */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mysql/my_global.h>
#include <mysql/mysql.h>
#include "plc.h"
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
    struct db_params args = read_config();
  	if (mysql_real_connect(con, args.host, args.user, args.password, args.database, 0, NULL, 0) == NULL) 
  	{
      finish_with_error(con);
  	}
  	else
  	{
  		log_it("Аутентификация прошла успешно.\n");
  		
  		if (mysql_query(con, "select plc.ip, plc.daveProto, plc.daveSpeed, plc.daveTimeout, plc.MPI, plc.rack, plc.slot from plc where plc.active = 1")) 
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

  /*
  row[0] - IP
  row[1] - Proto
  row[2] - speed
  row[3] - timeout
  row[4] - MPI
  row[5] - rack
  row[6] - slot
  */
  
  while ((row = mysql_fetch_row(result))) 
  { 
    //connect_plc(row[0], atoi(row[1]), atoi(row[2])); 
    connect_plc (row[0], atoi(row[1]), atoi(row[2]), atoi(row[3]), atoi(row[4]), atoi(row[5]), atoi(row[6]));
  }
  
  mysql_free_result(result);
  mysql_close(con);
}      


    