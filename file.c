#include <stdio.h>
#include <time.h>
#include <string.h>

void log_it(char *message){
	FILE *log = fopen("log.txt", "a");
	time_t t = time(NULL);
	struct tm* aTm = localtime(&t);
	//char text[255];
	//strcpy(text, message);
	//strcpy(text, "\n");

	fprintf(log, "%04d/%02d/%02d %02d:%02d:%02d: %s", aTm->tm_year+1900, aTm->tm_mon+1, aTm->tm_mday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec, message);
	fflush(log);
}