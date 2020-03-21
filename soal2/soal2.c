#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <wait.h> 
#include <syslog.h> 
#include <string.h> 
#include <time.h>
#include <dirent.h> 
#include <fcntl.h> 
#include <errno.h> 
#include <unistd.h>

void killer(char *zip_dir) {
FILE *n_file;
n_file = fopen("killer.sh", "w");
if (strcmp(zip_dir, "-a") == 0){
fprintf(n_file, "#!/bin/bash\nkill -9 -%d\nrm killer", getpid());
}
if (strcmp(zip_dir, "-b") == 0) {
fprintf(n_file, "#!/bin/bash\nkill %d\nrm killer", getpid());
  }
else {
   printf("Argumen yang dimasukkan salah");
   exit(1);
  }

int stts; if(fork()==0){
if (fork()==0) {
char *arg2[] = {"chmod", "u+x", "killer.sh", NULL}; execv ("/bin/chmod", arg2);
}
else if(fork() !=0){
while ((wait (&stts)) > 0);
char *arg2[] = {"mv", "killer.sh", "killer", NULL}; execv ("/bin/mv", arg2);
}
}
fclose(n_file);
}


static void daemonsize() {
//template daemon 
pid_t pid, sid;
//variabel untuk menyimpan 
PID pid = fork();
//menyimpan pid dari child process
//akan keluar saat fork gagal 
if (pid < 0)
{
exit(EXIT_FAILURE);
}
//nilai pid adalah pid dari child process

    if (pid > 0)
    {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main(int arg1, char** arg2){
daemonsize();
killer(arg2[1]);
   struct tm *timer; 
   time_t now;
  

while(1){
    pid_t child_id;
    child_id = fork();
    int stts;
    time(&now);
    now = time(NULL);
    timer = localtime(&now);
    char dir_name[200];
    strftime(dir_name, 200, "%d-%m-%G_%H:%M:%S/", timer);
if (child_id < 0)
{
exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
}

if (child_id == 0)
{
// this is child
child_id = fork();
if (child_id == 0)
{
    char *arg2[] = {"mkdir", "-p", dir_name, NULL};
    execv("/bin/mkdir", arg2);
      }
      else {
        while ((wait(&stts)) > 0);
        int i;
        for (i = 0; i < 20; i++)
        {
          child_id = fork();
          if (child_id == 0) {
            time_t now1;
            struct tm* info = localtime(&now1);
            now1 = time(NULL);
            char url[200];
            char sftime[200];
            chdir(dir_name);
            int t = (int)time(NULL);
            t = ((t%1000)+100);
            sprintf(url, "https://picsum.photos/%d", t);
            strftime(sftime, 200, "%Y-%m-%d_%H:%M:%S", info);
            char *arg2[] = {"wget", url, "-qO", sftime, NULL};
            execv("/usr/bin/wget", arg2);
          }
          sleep(5);
        }
        char zip_dir[200];
        sprintf(zip_dir, "%s.zip", dir_name);
        //remove folder yang tadinya dizip.
        char *arg2[] = {"zip", "-qrm", zip_dir, dir_name, NULL};
        execv("/usr/bin/zip", arg2);
      }
    }
    else sleep(30);
  }
}

    