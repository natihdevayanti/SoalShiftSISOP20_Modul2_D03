#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

//3a
int main()
{
int stts;
pid_t child_id;
child_id = fork();
if (child_id < 0)
{
exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
}

if (child_id == 0)
{
// this is child
    pid_t child_id1;
	child_id1 = fork();
    if(child_id1 < 0)
    {
        exit(EXIT_FAILURE);
    }
    if (child_id1 == 0)
    {
        char *arg[] = {"mkdir", "-p", "/home/elvira/modul2/indomie", NULL};
        execv("/bin/mkdir", arg);
    }
    else
    {
        while ((wait(&stts)) > 0);    
        sleep (5);  
        char *arg[] = {"mkdir", "-p", "/home/elvira/modul2/sedaap", NULL};
        execv("/bin/mkdir", arg);
    }
}
//no 3b
else
{
    while ((wait(&stts)) > 0);

    pid_t child_id2;
	child_id2 = fork();

    if (child_id2 < 0)
    {
        exit(EXIT_FAILURE);
    }
    if (child_id2 == 0)
    {
        char *argz[] = {"unzip", "-oq", "/home/elvira/modul2/jpg.zip", NULL}; 
//unzip folder
        execv("/usr/bin/unzip", argz);
    }
//no 3c
   else 
      {
        while ((wait(&stts)) > 0);
        DIR *d;
        struct dirent *dr; 
        d = opendir("jpg");
	struct stat st;
        if (d)
        {
          while ((dr = readdir(d)) != NULL)
          {
            pid_t child_id3;
	    child_id3 = fork ();
            if (child_id3 < 0) 
            {
              exit(EXIT_FAILURE); 
            }
            if (child_id3 == 0)
            {
              char file_name[20000];
              sprintf(file_name, "/home/elvira/modul2/jpg/%s", dr->d_name);

              if (stat(file_name, &st)) 
              {
                exit (EXIT_FAILURE);
              }
              if (strcmp(dr->d_name, "..")== 0 || strcmp(dr->d_name, ".")== 0);

              else if(dr->d_type == DT_REG)
              {
                char* arggg[] = {"mv", file_name, "/home/elvira/modul2/sedaap/", NULL};
                execv("/bin/mv", arggg);
              }
              else 
              {
                pid_t child_id4;
		child_id4 = fork ();
                if (child_id4 < 0) 
                {
                  exit(EXIT_FAILURE); 
                }
                if(child_id4 == 0)
                {
                  char* arggg[] = {"mv", file_name, "/home/elvira/modul2/indomie/", NULL};
                  execv("/bin/mv", arggg);
                }
                else 
                {
                  while ((wait(&stts)) > 0);
                  pid_t child_id5;
		  child_id5 = fork ();
                  if (child_id5 < 0) 
                  {
                    exit(EXIT_FAILURE); 
                  }
                  if(child_id5 == 0)
                  {
                    char destination_file[20000];
                     FILE *target;
	              sprintf(destination_file, "/home/elvira/modul2/indomie/%s/coba1.txt", dr->d_name);
                      target = fopen(destination_file,"w");
                      fclose(target);
                    
                  }
                  else 
                  {
                    while ((wait(&stts)) > 0);
                    sleep(3);
                    char destination_file[20000];
  		      FILE *target;
	              sprintf(destination_file, "/home/elvira/modul2/indomie/%s/coba2.txt", dr->d_name);
	              target = fopen(destination_file,"w");
	              fclose(target);
		      exit(0);

                  }
                }
              }
            }
          }
          closedir(d);

        }
      }
    }
  }
