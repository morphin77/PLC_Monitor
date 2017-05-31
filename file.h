/* Programm Interface for configs and logs */

struct db_params{
  char host[20];
  char user[20];
  char password[255];
  char database[255];
}; 

void log_it(char *message);
struct db_params read_config();