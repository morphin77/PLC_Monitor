/*mysql function*/
#include <stdlib.h>
#include <stdio.h>
#include <mysql/my_global.h>
#include <mysql/mysql.h>
#include "plc.h"


void finish_with_error(MYSQL *con)
{
  printf("Ошибка при обращении к базе данных.\n");
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

void Disconnect_DB(MYSQL *con){
	printf("База данных успешно отключена\n");
	mysql_close(con);
}

int MySQL_Connect(MYSQL *con){
  
	if (con == NULL)
  {
    printf("Клиент не готов для подключения к базе данных\n");
    exit(1);
  } 
  else 
  {
  	printf("Клиент готов для подключения к базе данных. Попытка аутентификации...\n");
  	if (mysql_real_connect(con, "localhost", "root", "sad56das", "testdb", 0, NULL, 0) == NULL) 
  	{
   		finish_with_error(con);
  	}
  	else
  	{
  		printf("Аутентификация завершилась успешно. Готов к работе.\n");
  		return 1;
  	}
  }
} 

void get_result_array_size(MYSQL_RES *result, MYSQL *con){
	
	int num_fields = mysql_num_fields(result);
 	char plc[8][3];
 	MYSQL_ROW row;
 	int num_row =0;
 	int i;

	if (result == NULL) 
  {
   	finish_with_error(con);
  }
  else
  {
  	while (row = mysql_fetch_row(result))
  	{ 
  		for (i=0; i<num_fields; i++){
  			num_row=num_row++;
  			plc[num_row][i] = row[i];
  		}
    	//connect_plc(row[1], atoi(row[2]), atoi(row[3]));
    }
  }
}

void Select_Targets_Data_From_DB(MYSQL *con) {
	if (MySQL_Connect(con) == 1)
	{
		if (mysql_query(con, "SELECT ip_address, rack, slot FROM PLC")) 
		{
   		finish_with_error(con);
  	}
  	else
  	{
  		MYSQL_RES *result = mysql_store_result(con);
  		get_result_array_size(result, con);
  		mysql_free_result(result);
  		Disconnect_DB(con);
  	}
 	}
}