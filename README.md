# SoalShiftSISOP20_modul2_D03

Dibuat oleh:

Kelompok D03

Putu Putri Natih Devayanti (05111840000163)

Elvira Catrine Natalie (05111840000016)


## SOAL 1

**Program C menyerupai crontab**


**a. Program menerima 4 argumen berupa: i. Detik: 0-59 atau * (any value) ii. Menit: 0-59 atau * (any value) iii. Jam: 0-23 atau * (any value) iv. Path file .sh.**

**b. Program akan mengeluarkan pesan error jika argumen yang diberikan tidak sesuai.**

> Langkah 

- Melakukan checking apakah ada * pada argument yang dimasukkan, jika ada maka return 1 (benar).

Code: 
```
int bintang (char star[]) {
	if (star[0]=='*') 
	return 1;
    return 0;
}

```

- Untuk melakukan checking apakah input yang dimasukkan merupakan integer. Jika bukan makai a akan return 0 (salah), jika benar akan return 1 (benar).

```

int number (char numbs[]){
  int i = 0;
//cek bilangan negatif
  for (; numbs[i] != '\0'; i++){
    if(!isdigit(numbs[i]))
      return 0;
  }
     return 1;
}


```

- Untuk melakukan checking apakah total argument yang masuk adalah benar terdapat 5 argumen, yang termasuk run program. 


```

if (arg1 != 5){
	Error();
	exit (EXIT_FAILURE);
}

```
- Jika tidak maka akan masuk ke if (arg1 !=5) yang dimana akan mengeluarkan error dengan syntax :

```
void Error(){ printf("Tidak valid\n");
}

```

Yang dimana jika error (input tidak sesuai dengan perintah), maka akan mengeluarkan pernyataan “tidak valid”


- Lakukan deteksi error

```

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
 
- Perintah diatas digunakan untuk mendeteksi apakah terjadi error atau tidak. Apabila input berupa integer, maka akan dipindah ke array arg[i] yang berisi integer. Jika berupa * akan ditandai di array arg[i] dengan -1, selain itu tidak valid.

- Fungsi `atoi()` digunakan untuk mengubah string angka menjadi bilangan integer.

- Kemudian lakukan checking apakah inputan kita merupakan masih dalam range satuan jam dan juga menit. Jika tidak, maka akan mengeluarkan perintah error/tidak valid.


**c. Program hanya menerima 1 config cron**

Penjelasan:
Kami tidak membuat argumen fungsi main() lebih atau kurang dari lima argumen karena program yang diminta pada soal hanya menerima 1 config cron.


**d. Program berjalan di background (daemon)**
 
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

- Program ini menggunakan struct time.h untuk melakukan segala proses yang berkaitan dengan waktu.

- Menggunakan while karena program yang dibuat ini seperti crontab sehingga akan dilakukan secara terus menerus.

- Variabel `time_t waktu, struct tm* tm_now` berada pada library time.h yang nantinya akan digunakan untuk mendapatkan waktu yang tertera pada komputer.

- Kemudian `tm_now=localtime(&waktu);` digunakan untuk memasukkan nilai waktu ke format `struct * tm_now`.

- Lalu lakukan pengecekan apakah argumen ketiga (hour) yang dimasukkan merupakan * atau sama dengan jam waktu yang tertera. Lalu dilakukan lagi pengecekan apakah argumen kedua (minutes) yang dimasukkan merupakan * atau sama dengan menit waktu yang tertera. Setelah itu dilakukan pengecekan lagi apakah argumen pertama (second) yang dimasukkan sama dengan * atau sama dengan menit waktu yang tertera.

- Jika memenuhi kondisi-kondisi diatas maka akan dipanggil fungsi execv untuk mengeksekusi bash pada argv1[4] yang terletak pada argumen terakhir inputan.
 
- `sleep(1);` merupakan penanda bahwa fungsi tersebut setiap berjalan akan melakukan delay 1 detik. Maka tiap 1 detik fungsi ini akan melakukan penyocokan antara waktu di argumen dengan waktu yang tertera di saat itu.



## SOAL 2 

### Membuat sebuah program C yang dapat download dan zip sekumpulan gambar

- Shisoppu mantappu! itulah yang selalu dikatakan Kiwa setiap hari karena sekarang dia merasa sudah jago materi sisop. Karena merasa jago, suatu hari Kiwa iseng membuat sebuah program. Kiwa lalu terbangun dan sedih karena menyadari programnya hanya sebuah mimpi. Buatlah program dalam mimpi Kiwa jadi nyata! 

Catatan:
Tidak boleh memakai system().

Program utama harus ter-detach dari terminal Hint:

Gunakan fitur picsum.photos untuk mendapatkan gambar dengan ukuran tertentu

Epoch Unix bisa didapatkan dari time()

**a) Pertama-tama, Kiwa membuat sebuah folder khusus, di dalamnya dia membuat sebuah program C yang per 30 detik membuat sebuah folder dengan nama timestamp [YYYY-mm-dd_HH:ii:ss].**

```

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
     }
sleep(30);
}

```

- `pid_t child_id; child_id = fork();` untuk membuat fork agar bisa menjalankan banyak proses dalam sekali menjalankan.

- `now = time(NULL);` digunakan untuk mengkalkulasi waktu kalender sekarang dan memasukkannya ke format now.

- Kemudian `timer = localtime(&now);` digunakan untuk memasukkan nilai now ke format struct * timer.

- Membuat child process yang di dalamnya ada eksekusi dari membuat folder yang dilakukan setiap 30 detik.

- `strftime(dir_name, 200, "%d-%m-%G_%H:%M:%S/", timer);` adalah untuk memasukkan tahun-bulan-hari dan juga jam-menit-detik ke dir_name yang nanti akan digunakan untuk membuat direktori

- `char *arg2[]  =  {"mkdir",  "-p",  dir_name,  NULL};`  untuk  membuat  direktori, "-  p" digunakan untuk membuat parent direktori nya

- Program ini menjalankan looping setiap 30 detik. Child process pertama akan membuat suatu folder/direktori baru yang sesuai timestamp. Parent akan menunggu sampai child process mkdir selesai. Kemudian membuat child process lagi yang akan mengendalikan proses setiap folder.


**b) Tiap-tiap folder lalu diisi dengan 20 gambar yang di download dari https://picsum.photos/, dimana tiap gambar di download setiap 5 detik. Tiap gambar berbentuk persegi dengan ukuran (t%1000)+100 piksel dimana t adalah detik Epoch Unix. Gambar tersebut diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss].**

```
while ((wait(&stts)) > 0); int i;
for (i = 0; i < 20; i++)
{
child_id = fork(); if (child_id == 0) { 
time_t now1;
struct tm* info = localtime(&now1); 
now1 = time(NULL);
char url[200]; char sftime[200]; 
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

```
- `while ((wait(&status)) > 0);` untuk delay suatu proses

- Lakukan looping sebanyak 20x untuk memproses folder

- Lakukan download pada setiap folder. Oleh karena itu membutuhkan fork lagi untuk membuat child process.

- `chdir(dir_name);` Dilakukan chdir agar hasil download masuk ke direktori.

- `sprintf(url, "https://picsum.photos/%d", t);` digunakan untuk menyimpan link pada string url dan menyimpan ukuran dari foto tersebut.

- Ukuran dari foto tersebut adalah `(t%1000)+100` piksel.

- `struct tm* info = localtime(&now1);` digunakan untuk memasukkan nilai now1 ke format struct * info.
 
- `strftime(sftime, 200, "%Y-%m-%d_%H:%M:%S", info);` adalah untuk memasukkan tahun-bulan-hari dan juga jam-menit-detik ke sftime.

- Melakukan eksekusi dari wget menggunakan execv.

- `Sleep (5);` tiap gambar didownload setiap 5 detik.


**c) Agar rapi, setelah sebuah folder telah terisi oleh 20 gambar, folder akan di zip dan folder akan di delete(sehingga hanya menyisakan .zip).**

```
char zip_dir[200];
sprintf(zip_dir, "%s.zip", dir_name);
//remove folder yang tadinya dizip.
char *arg2[] = { "zip", "-qrm", zip_dir, dir_name, NULL }; execv("/usr/bin/zip", arg2);
```

- kemudian menjalankan child process untuk melakukan perintah zip

- `sprintf(zip_dir, "%s.zip", dir_name);` yaitu nama zip sesuai dengan nama folder awal sehingga disimpan dalam dir_name.

- Proses folder selesai dengan melakukan perintah zip-rm untuk menghapus foldernya yang tadinya akan di-zip.


**d) Karena takut program tersebut lepas kendali, Kiwa ingin program tersebut men-generate sebuah program "killer" yang siap di run(executable) untuk menterminasi semua operasi program tersebut. Setelah di run, program yang menterminasi ini lalu akan mendelete dirinya sendiri.**

(bersama program dibawah)


**e) Kiwa menambahkan bahwa program utama bisa dirun dalam dua mode, yaitu MODE_A dan MODE_B. untuk mengaktifkan MODE_A, program harus dijalankan dengan argumen -a. Untuk MODE_B, program harus dijalankan dengan argumen-b. Ketika dijalankan dalam MODE_A, program utama akan langsung menghentikan semua operasinya ketika program killer dijalankan. Untuk MODE_B, ketika program killer dijalankan, program utama akan berhenti tapi membiarkan proses di setiap folder yang masih berjalan sampai selesai(semua folder terisi gambar, terzip lalu di delete).**


> Langkah dan Penjelasan

```

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
  
 ```

- Program mengendalikan dua mode berbeda, yaitu mode A (argument -a) dan B (argumen -b).

- Fungsi strcmp digunakan untuk mendeteksi apakah inputan adalah -a atau -b.

- `if (strcmp(zip_dir, "-a") == 0) fprintf(n_file "#!/bin/bash\nkill -9 -%d\nrm killer", getpid());` melakukan kill langsung tanpa menunggu program selesai berjalan. Untuk mode A killer ini akan membunuh semua proses (termasuk child) dengan minus pid.

- `if (strcmp(zip_dir, "-b") == 0) fprintf(n_file, "#!/bin/bash\nkill %d\nrm killer", getpid());` maka dikill namun berjalan pelan-pelan. Untuk mode B, killer hanya akan membunuh parent agar tidak membuat child baru.

- Selain perintah input -a dan -b , maka program akan memberi pemberitahuan bahwa argument salah.

- Killer ini menggunakan bash yang bisa dieksekusi dengan `chmod u+x killer.sh.` Lalu bash ini diubah namanya menjadi killer.



## SOAL 3

### Ekstrak Folder dan File

### 3a

Program buatan jaya harus bisa membuat dua direktori di “/home/[USER]/modul2/”. Direktori yang pertama diberi nama “indomie”, lalu lima detik kemudian membuat direktori yang kedua bernama “sedaap”.


> Langkah dan Penjelasan

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

- `pid_t child_id; dan child_id = fork();` merupakan bagian untuk membuat fork agar bisa menjalankan banyak proses dalam sekali jalan

- `if  (child_id  <  0)  exit(EXIT_FAILURE);`	menunjukkan bahwa jika gagal dalam membuat proses baru, program akan berhenti

- Gunakan fungsi fork() terlebih dahulu untuk membuat direktori pertama (indomie). Membuat direktori menggunakan mkdir –p jika merupakan child process, lalu gunakan perintah execv() untuk menjalankan program.

- `char *arg[] = {"mkdir", "-p", "/home/elvira/modul2/indomie", NULL};` adalah bagian untuk membuat direktori, "-p" adalah untuk membuat parent direktori nya

- `while ((wait(&stts)) > 0);` bagian ini untuk delay suatu proses.

- Direktori kedua yaitu “sedaap” dibuat lima detik kemudian setelah direktori “indomie” dibuat. Maka kita menggunakan perintah `sleep(5)`;


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

- `pid_t child_id2 = fork();` adalah bagian untuk membuat fork agar bisa menjalankan banyak proses dalam sekali jalan

- `if  (child_id  <  0)  exit(EXIT_FAILURE);` menunjukkan bahwa jika gagal dalam membuat proses baru, program akan berhenti

- `while ((wait(&stts)) > 0);` bagian ini untuk delay suatu proses.


### 3c

Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (di dalam direktori “home/[USER]/modul2/jpg/”) harus dipindahkan sesuai dengan pengelompokan, semua file harus dipindahkan ke “/home/[USER]/modul2/sedaap/” dan semua direktori harus dipindahkan ke “/home/[USER]/modul2/indomie/”.

> Langkah dan Penjelasan

Code

```

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

```

- Struct dirent *dr adalah struct yang berfungsi untuk membaca file yang terdapat pada direktori

- `DIR *d;` adalag pointer untuk menunjuk ke direktori

- `d = opendir("jpg");` adalah bagian untuk membuka direktori jpg

- `struct stat st;` adalah pointer status dalam proses mengecek sebuah direktori

- `if(d)` adalah bagian untuk mengecek pointer yang ditunjuk adalah benar sebuah direktori.

- `while((dr = readdir(d)) != NULL)` bagian ini loop ketika sebuah direktori masih ada file/folder didalamnya

- `char file_name[20000];` untuk menyimpan hasil pencarian
 
- `sprintf(file_name, "/home/elvira/modul2/jpg/%s", dr->d_name);` untuk mencari file/folder yang ada dalam direktori

- Direktori tidak termasuk (proses berkelanjutan) jika direktori berupa . dan .., maka harus menggunakan strcmp() untuk membandingkan dengan dr.

- Jika tipe dr merupakan direktori, gunakan fungsi snprintf() untuk memformat dan menyimpan nama hasil ekstrak bertipe direktori yang akan disimpan pada direktori indomie dalam buffer array.

- Gunakan fungsi fork() terlebih dahulu lalu gunakan mv untuk memindahkan nama hasil ekstrak bertipe direktori ke direktori indomie.

- Jika tipe dr merupakan file, gunakan fungsi snprintf() untuk memformat dan menyimpan nama hasil ekstrak ber tipe file yang akan disimpan pada direktori sedaap dalam buffer array (code ada di 3c).

- Gunakan fungsi fork() terlebih dahulu lalu gunakan mv untuk memindahkan nama hasil esktrak yang bertipe file ke direktori sedaap.


### 3d

Untuk setiap direktori yang dipindahkan ke “/home/[USER]/modul2/indomie/” harus membuat dua file kosong. File yang pertama diberi nama “coba1.txt”, lalu 3 detik kemudian membuat file bernama “coba2.txt”. (contoh : “/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt”).

```
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

```

- Terdapat dua file kosong yang akan dibuat yaitu file coba1.txt dan coba2.txt jika dr bertipe direktori

- `FILE *target;` adalah pointer untuk menunjuk sebuah file/folder

- `target = fopen(destination_file,"w");` adalah untuk membuka file/folder kemudian memberikan perintah untuk membuat file "coba1.txt" atau "coba2.txt"pada direktori

- Gunakan fungsi snprintf() untuk memformat dan menyimpan coba1.txt yang akan disimpan pada direktori dalam buffer array.

- Membuat file coba1.txt lalu gunakan perintah execv() untuk eksekusi

- File coba2.txt dibuat tiga detik kemudian setelah file coba1.txt dibuat, maka gunakan perintah sleep(3)

- Gunakan fungsi snprintf() untuk memformat dan menyimpan file coba2.txt yang akan disimpan pada direktori dalam buffer array.

- Membuat file coba2.txt lalu gunakan perintah execv() untuk eksekusi

- `fclose(target); exit(0);` adalah untuk mengakhiri proses dalam membuat file dalam direktori


**TERIMA KASIH**
