# SoalShiftSISOP20_modul2_D03

Dibuat oleh:

Kelompok D03

Putu Putri Natih Devayanti (05111840000163)

Elvira Catrine Natalie (05111840000016)


## SOAL 1

**Program C menyerupai crontab**

> Penjelasan

- Program menerima 4 argumen berupa: i. Detik: 0-59 atau * (any value) ii. Menit: 0-59 atau * (any value) iii. Jam: 0-23 atau * (any value) iv. Path file .sh.

- Program akan mengeluarkan pesan error jika argumen yang diberikan tidak sesuai.

Penjelasan: 

Memeriksa argumen yang di diinput oleh user berjumlah lima argumen atau lebih

./program atau nama program termasuk dalam argumen yang akan dipassing ke dalam fungsi main(), maka total argumen yang masuk harus berjumlah lima. Kemudian terapkan error handling.

Gunakan perintah yang digunakan untuk membatasi argumen yang diinput oleh user hanya angka dan *.


- Program hanya menerima 1 config cron.

Penjelasan: 
Kami tidak membuat argumen fungsi main() lebih atau kurang dari lima argumen karena program yang diminta pada soal hanya menerima 1 config cron.


> Langkah 

- Lakukan checking terhadap argumen

Code: 
```
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


```

- Fungsi main untuk checking

```

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
 
 ```
 
 - Berikut adalah fungsi untuk membuat daemonnya
 
 ```
 
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

```
 
 - Proses looping 
 
 Program ini menggunakan struct time.h untuk melakukan segala proses yang berkaitan dengan waktu.
 
```
- while (1)
  {
    time_t waktu;
    struct tm * tm_now;
    time(&waktu);
//tm_hour menyesuaikan
    tm_now = localtime(&waktu);

    if ((tm_now->tm_sec == arg[1] || arg[1] == -1)){
	if (tm_now->tm_min == arg[2] || arg[2] == -1){
	if (tm_now -> tm_hour == arg[3] || arg[3] == -1)
    {
      pid_t child = fork();
      int stts;
      if (child == 0){
        char *argv2[] = {"bash", argv1[4], NULL};
        execv("/bin/bash", argv2);
      }
    }
}
 }
//melakukan delay 1 tm_sec
    sleep (1);
  }
}
else
{
  Error();
  exit (EXIT_FAILURE);
}
}

```



## SOAL 2 

### Membuat sebuah program C yang dapat download dan zip sekumpulan gambar

- Shisoppu mantappu! itulah yang selalu dikatakan Kiwa setiap hari karena sekarang dia merasa sudah jago materi sisop. Karena merasa jago, suatu hari Kiwa iseng membuat sebuah program. Kiwa lalu terbangun dan sedih karena menyadari programnya hanya sebuah mimpi. Buatlah program dalam mimpi Kiwa jadi nyata! 

Catatan:
Tidak boleh memakai system().

Program utama harus ter-detach dari terminal Hint:

Gunakan fitur picsum.photos untuk mendapatkan gambar dengan ukuran tertentu

Epoch Unix bisa didapatkan dari time()

a) Pertama-tama, Kiwa membuat sebuah folder khusus, di dalamnya dia membuat sebuah program C yang per 30 detik membuat sebuah folder dengan nama timestamp [YYYY-mm-dd_HH:ii:ss].

b) Tiap-tiap folder lalu diisi dengan 20 gambar yang di download dari https://picsum.photos/, dimana tiap gambar di download setiap 5 detik. Tiap gambar berbentuk persegi dengan ukuran (t%1000)+100 piksel dimana t adalah detik Epoch Unix. Gambar tersebut diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss].

c) Agar rapi, setelah sebuah folder telah terisi oleh 20 gambar, folder akan di zip dan folder akan di delete(sehingga hanya menyisakan .zip).

d) Karena takut program tersebut lepas kendali, Kiwa ingin program tersebut men-generate sebuah program "killer" yang siap di run(executable) untuk menterminasi semua operasi program tersebut. Setelah di run, program yang menterminasi ini lalu akan mendelete dirinya sendiri.

e) Kiwa menambahkan bahwa program utama bisa dirun dalam dua mode, yaitu MODE_A dan MODE_B. untuk mengaktifkan MODE_A, program harus dijalankan dengan argumen -a. Untuk MODE_B, program harus dijalankan dengan argumen-b. Ketika dijalankan dalam MODE_A, program utama akan langsung menghentikan semua operasinya ketika program killer dijalankan. Untuk MODE_B, ketika program killer dijalankan, program utama akan berhenti tapi membiarkan proses di setiap folder yang masih berjalan sampai selesai(semua folder terisi gambar, terzip lalu di delete).


> Langkah dan Penjelasan

- Menggunakan template daemon

```

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
  
 ```

- Program ini menggunakan struct time.h untuk melakukan segala proses yang berkaitan dengan waktu.


> Kendala

- Kurang memahami fungsi dan syntax yang bisa dipergunakan dalam soal

- Kami belum mengetahui cara solve problem di atas



## SOAL 3

### Ekstrak Folder dan File

### 3a

Program buatan jaya harus bisa membuat dua direktori di “/home/[USER]/modul2/”. Direktori yang pertama diberi nama “indomie”, lalu lima detik kemudian membuat direktori yang kedua bernama “sedaap”.


> Langkah dan Penjelasan

- Pertama-tama membuat folder modul2 dulu

Code 

```

mkdir modul2

```

- Program 

```

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

```

- Gunakan fungsi fork() terlebih dahulu untuk membuat direktori pertama (indomie). Membuat direktori menggunakan mkdir –p jika merupakan child process, lalu gunakan perintah execv() untuk menjalankan program.

- Direktori kedua yaitu “sedaap” dibuat lima detik kemudian setelah direktori “indomie” dibuat. Maka kita menggunakan perintah sleep(5)



### 3b

Kemudian program tersebut harus meng-ekstrak file jpg.zip di direktori “/home/[USER]/modul2/”. Setelah tugas sebelumnya selesai, ternyata tidak hanya itu tugasnya.

> Langkah dan Penjelasan

Code

```

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
        char *arg[] = {"unzip", "-oq", "/home/elvira/modul2/jpg.zip", NULL};

        execv("/usr/bin/unzip", arg);
    }

```

- Gunakan fungsi fork() untuk unzip file. Gunakan perintah unzip() jika merupakan child process, lalu jalankan program menggunakan perintah execv()



### 3c

Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (di dalam direktori “home/[USER]/modul2/jpg/”) harus dipindahkan sesuai dengan pengelompokan, semua file harus dipindahkan ke “/home/[USER]/modul2/sedaap/” dan semua direktori harus dipindahkan ke “/home/[USER]/modul2/indomie/”.

> Langkah dan Penjelasan

Code

```

 else
    {
       while ((wait(&stts)) > 0);

       struct dirent *dr;
	struct stat st;
	stat(dr->d_name, &st);
	DIR *d = opendir ("/home/elvira/modul2/jpg/");
        char filename [2000];
	char destination_file[2000];
       //chdir ("/home/elvira/modul2/jpg/");
       d = opendir("."); 
       if(d)
       {
           while ((dr = readdir(d)) != NULL)
           {
               pid_t child_id3;
               child_id3 = fork();

                if (child_id3 == 0)
                {
       
                    sprintf (filename, "home/elvira/modul2/jpg/%s", dr->d_name);

                    if(S_ISDIR(st.st_mode))
                    {
                        if(strcmp(dr->d_name, ".")==0 || strcmp(dr->d_name, "..")== 0)
			continue;
                        else
                        {
                            pid_t child_id4;
                            child_id4 = fork();
 
                            if (child_id4 == 0){
                            char* arg[] = {"mv", filename, "/home/elvira/modul2/indomie/", NULL};
                            execv("/bin/mv", arg);
                        }

```

- Struct dirent *dr adalah struct yang berfungsi untuk membaca file yang terdapat pada direktori

- Jika directory tidak kosong, perintah akan dijalankan, sehingga menggunakan perintah readdir(d)

- Direktori tidak termasuk (proses berkelanjutan) jika direktori berupa . dan .., maka harus menggunakan strcmp() untuk membandingkan dengan dr.

- Jika tipe dr merupakan direktori, gunakan fungsi snprintf() untuk memformat dan menyimpan nama hasil ekstrak bertipe direktori yang akan disimpan pada direktori indomie dalam buffer array.

- Gunakan fungsi fork() terlebih dahulu lalu gunakan mv untuk memindahkan nama hasil ekstrak bertipe direktori ke direktori indomie.

- Jika tipe dr merupakan file, gunakan fungsi snprintf() untuk memformat dan menyimpan nama hasil ekstrak ber tipe file yang akan disimpan pada direktori sedaap dalam buffer array (coding ada di 3c).

- Gunakan fungsi fork() terlebih dahulu lalu gunakan mv untuk memindahkan nama hasil esktrak yang bertipe file ke direktori sedaap.

### 3d

Untuk setiap direktori yang dipindahkan ke “/home/[USER]/modul2/indomie/” harus membuat dua file kosong. File yang pertama diberi nama “coba1.txt”, lalu 3 detik kemudian membuat file bernama “coba2.txt”. (contoh : “/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt”).

```

                        else {
                            
                            while ((dr = readdir(d)) != NULL){
                                pid_t child_id5;
                                child_id5 = fork();
                                if (child_id5 == 0){
                                    FILE *target;
                                    sprintf(destination_file, "/home/elvira/modul2/indomie/%s/coba1.txt", dr->d_name);
                                    target = fopen (destination_file, "w");
                                    fclose (target);
                                }
                                else{
                                    while ((wait(&stts)) > 0);
                                    sleep (3);
					FILE *target;
                                    sprintf(destination_file, "/home/elvira/modul2/indomie/%s/coba2.txt", dr->d_name);
                                    target = fopen(destination_file, "w");
                                    fclose (target);
                                    exit(0);
                                }
                            }
                        }
                    }
                }
                    else {
                        char* arg[] = {"mv", filename, "/home/elvira/modul2/sedaap/", NULL};
                        execv("/bin/mv", arg);
                    }
                }
           }
               closedir(d);

           }
       }
    }  
return 0;
}

```

- Terdapat dua file kosong yang akan dibuat yaitu file coba1.txt dan coba2.txt jika dr bertipe direktori

- Gunakan fungsi snprintf() untuk memformat dan menyimpan coba1.txt yang akan disimpan pada direktori dalam buffer array.

- Membuat file coba1.txt lalu gunakan perintah execv() untuk eksekusi 

- File coba2.txt dibuat tiga detik kemudian setelah file coba1.txt dibuat, maka gunakan perintah sleep(3)

- Gunakan fungsi snprintf() untuk memformat dan menyimpan file coba2.txt yang akan disimpan pada direktori dalam buffer array.

- Membuat file coba2.txt lalu gunakan perintah execv() untuk eksekusi 

Karena Jaya terlalu banyak tugas dia jadi stress, jadi bantulah Jaya agar bisa membuat
program tersebut.

Catatan :
- Tidak boleh memakai system().
- Tidak boleh memakai function C mkdir() ataupun rename().
- Gunakan exec dan fork
- Direktori “.” dan “..” tidak termasuk


**TERIMA KASIH**
