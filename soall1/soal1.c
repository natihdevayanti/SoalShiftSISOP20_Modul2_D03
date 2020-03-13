#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
 
int bintang (char star[]) {
	if (star[0]=='*') 
	return 1;
    return 0;
}

int number (char numbs[]){
  int i = 0;
//cek bilangan negatif
  for (; numbs[i] != '\0'; i++){
    if(!isdigit(numbs[i]))
      return 0;
  }
     return 1;
}

void Error(){
     printf("Tidak valid\n");
}

static void daemonsize()
//menggunakan template daemon
{
  pid_t pid, sid;
  pid = fork();
  if (pid < 0)
    exit(EXIT_FAILURE);

  if (pid > 0)
    exit(EXIT_SUCCESS);

  umask(0);

  sid = setsid();
  if (sid < 0)
  exit(EXIT_FAILURE);
  
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
}

 
int main(int arg1, char **argv1) {
if (arg1 != 5){
	Error();
	exit (EXIT_FAILURE);
}

if (arg1 == 5) {
//5 adalah program dan 4 argumen lain
  int arg[4];
  int i;
  for (i = 1; i < 4; i++)
  {
    if (number(argv1[i]))
    {
      arg[i] = atoi(argv1[i]);
      if(arg[i]<0)
        Error();
    }
    else if (bintang(argv1[i]))
      arg[i] = -1;
    else 
    {
      Error();
      exit (EXIT_FAILURE);
    }

//ubah
  int cek = atoi(argv1[i]);
  if ((i == 0 || i ==1) && (cek > 59 || cek < 0))
 {
Error();
return 0;
 }

if (i == 2 && (cek > 23 || cek < 0 )){
Error();
return 0;
  }
 }

//daemon
daemonsize();

	//lakukan looping untuk argumen 4
  while (1)
  {
    time_t waktu;
    struct tm * tm_now;
    time(&waktu);
//waktu menyesuaikan
    tm_now = localtime(&waktu);
	  
//lakukan pengecekan waktu
    if ((tm_now->tm_sec == arg[1] || arg[1] == -1)){
	if (tm_now->tm_min == arg[2] || arg[2] == -1){
	if (tm_now -> tm_hour == arg[3] || arg[3] == -1)
    {
      int stts;
      pid_t child = fork();
      //child menjalankan bash
      if (child == 0){
        char *argv2[] = {"bash", argv1[4], NULL};
        execv("/bin/bash", argv2);
      }
    }
}
 }
//melakukan delay 1 sec
    sleep (1);
  }
}
else
{
  Error();
  exit (EXIT_FAILURE);
}
}



