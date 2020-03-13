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
• Memeriksa argumen yang di diinput oleh user berjumlah lima argumen atau lebih

• ./program atau nama program termasuk dalam argumen yang akan dipassing ke dalam fungsi main(), maka total argumen yang masuk harus berjumlah lima. Kemudian terapkan error handling.

• Gunakan perintah yang digunakan untuk membatasi argumen yang diinput oleh user hanya angka dan *.


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
## Membuat sebuah program C yang dapat download dan zip sekumpulan gambar

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



## SOAL 3

### 3a

Mendownload 28 gambar dari link yang sudah tersedia dengan fungsi wget dan mengubah nama filenya dengan fungsi -0

> Langkah dan Penjelasan

Code 

```

#!/bin/bash
for i in {1..28}
do
wget -O pdkt_kusuma_$i https://loremflickr.com/320/240/cat -a wget.log
done

```

- Kita gunakan -a untuk menambahkan lalu -0 untuk mengubah nama file menjadi “pdkt_kusuma_$i” dimana maksud dari $i adalah penomoran (iterasi) -> `sebanyak 28 gambar` saat mendownload gambar. 

- Menggunakan fungsi wget untuk langsung mendownload file yang ada di website dan wget.log untuk menyimpan file yang sudah didownload

### 3b

Script download hanya berjalan setiap 8 jam dimulai dari pukul 6.05 setiap hari kecuali hari Sabtu, maka dibuat cron job sebagai berikut

> Langkah dan Penjelasan

Code

```

crontab -e

5 6-23/8 * * 0-5 /home/elvira/soal3.sh

```

`5 6-23/8 * * 0-5`
- 5 adalah menit ke-5
- 6-23/8 adalah setiap 8 jam dari pukul 06.00-23.00
- 0-5 adalah hari minggu - jumat (setiap hari kecuali hari sabtu)

### 3c

Membuat sebuah script untuk mengidentifikasi gambar yang identik dari keseluruhan gambar yang terdownload tadi. Bila terindikasi sebagai gambar yang identik, maka sisakan 1 gambar dan pindahkan sisa file identik tersebut ke dalam folder ./duplicate dengan format filename "duplicate_nomor" (contoh : duplicate_200, duplicate_201). Setelah itu lakukan pemindahan semua gambar yang tersisa kedalam folder ./kenangan dengan format filename "kenangan_nomor" (contoh: kenangan_252, kenangan_253). Setelah tidak ada gambar di ​current directory​, maka lakukan backup seluruh log menjadi ekstensi ".log.bak"

> Langkah dan Penjelasan

Code

```

#!/bin/bash

grep "Location" wget.log > location.log
readarray line < location.log
for ((i=0; i<28; i++))
do
for ((j=0; j<=i; j++))
do
if [ $i == $j ]
then
continue
elif [ "${line[$i]}" == "${line[$j]}" ]
then
mv pdkt_kusuma_"$(($i+1))".jpg ./duplicate/duplicate_"$i".jpg
fi
done
done

for ((i=1; i<=28; i++))
do
mv pdkt_kusuma_"$i".jpg ./kenangan/kenangan_"$i".jpg
done
cp wget.log wget.log.bak

```

> Langkah dan Penjelasan

- Logfile wget.log yang terdapat karakter "Location" disimpan pada file "location.log"

- `mkdir kenangan` dan `mkdir duplicate` untuk membuat folder kenangan dan duplicate

- Untuk pengecekan gambar, maka dilakukan dengan for nested (iterasi 1-28)

- Jika locationnya sama, maka gambar tsb identik dan nantinya dipindahkan ke folder `duplicate`

- Jika gambar tidak berduplikat, maka dipindahkan ke folder `kenangan` dan namanya diganti menjadi kenangan + penomorannya. 
 
- Lalu akan dilakukan backup menuju file wget.log.bak

![Screenshot from 2020-02-21 16-36-57](https://user-images.githubusercontent.com/56763600/75027937-f5629c80-54d1-11ea-8865-f312c87ac69f.png)

**TERIMA KASIH**
