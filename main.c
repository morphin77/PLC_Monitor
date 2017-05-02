/*main programm */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include "mysql_func.h"
#include "plc.h"



int main (void){
	MYSQL *con = mysql_init(NULL);
	Select_Targets_Data_From_DB(con);
	//for (int i=0; i<)
}      


    