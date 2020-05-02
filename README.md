# SoalShiftSISOP20_modul2_D03

Dibuat oleh:

Kelompok D03

Putu Putri Natih Devayanti (05111840000163)

Elvira Catrine Natalie (05111840000016)


## SOAL 1

### Enkripsi Versi 1

a. Jika sebuah direktori dibuat dengan awalan “encv1_”, maka direktori tersebut akan menjadi direktori terenkripsi menggunakan metode enkripsi v1.

b. Jika sebuah direktori di-rename dengan awalan “encv1_”, maka direktori tersebut akan menjadi direktori terenkripsi menggunakan metode enkripsi v1.

c. Apabila sebuah direktori terenkripsi di-rename menjadi tidak terenkripsi, maka isi adirektori tersebut akan terdekrip.

d. Setiap pembuatan direktori terenkripsi baru (mkdir ataupun rename) akan tercatat ke sebuah database/log berupa file.

e. Semua file yang berada dalam direktori ter enkripsi menggunakan caesar cipher dengan key. 9(ku@AW1[Lmvgax6q`5Y2Ry?+sF!^HKQiBXCUSe&0M.b%rI'7d)o4~VfZ*{#:}ETt$3J-zpc]lnh8,GwP_ND|jO

f. Metode enkripsi pada suatu direktori juga berlaku kedalam direktori lainnya yang ada didalamnya.

> Langkah 

- Digunakan character sebagai berikut untuk menyimpan character key yang digunakan, yaitu `*characterlist = {"9(ku@AW1[Lmvgax6q`5Y2Ry?+sF!^HKQiBXCUSe&0M.b%rI'7d)o4~VfZ*{#:}ETt$3J-zpc]lnh8,GwP_ND|jO"};`

- Character  memiliki panjang 87 karakter dan menggunakan 10 key, sehingga apabila dienkrip akan digeser ke kanan sebanyak 10 karakter dan jika didekrip akan digeser ke kiri sebanyak 10 karakter. 

- Pada fungsi enkrip dan dekrip akan melakukan looping untuk membaca dan mengubah nama folder atau file. Misalkan apabila mkdir rahasia/encv1_coba, maka yg di enkripsi hanya string encv1_coba saja, rahasia/ tidak akan di enkripsi.

- Untuk mengetahui batas looping tersebut, `fungsi miring` dan `check_ekstensi` yang akan mengembalikan indeks ekstensi dan index tanda miring sebagai penanda awal dan akhir enkripsi dan dekripsi.

Code cek tanda miring:

```
int miring(char* path, int num){
	int length_path = strlen(path);
	for(int i=0; i<length_path; i++){
		if(path[i] == '/'){
			return i + 1;
		}
	}
	return num;
}
```

Code cek ekstensi:

```
int check_ekstensi(char* path){
	int length_path = strlen(path);

	for(int i=length_path-1; i >=0; i--){
		if(path[i] == '.') return i;
	}
	return length_path;
}
```

Code Enkripsi Versi 1: 

```
void encrypt(char *save_path)
{
	int curr = 0, i, j;
	if (!strcmp(save_path, ".") || !strcmp(save_path, ".."))
		return;

	int akhir = check_ekstensi(save_path);
	int mulai = miring(save_path, 0);

	for (i = mulai; i < akhir; i++)
	{
		if(save_path[i] != '/'){
			for (j = 0; j < jum_kode; j++)
			{
				if (save_path[i] == characterlist[j])
				{
					curr = (j + key) % jum_kode;
					save_path[i] = characterlist[curr];
					break;
				}
			}
		}
	}
}
```

Code dekripsi: 

```

void decrypt(char *save_path)
{
	int curr = 0, i, j;
	if(!strcmp(save_path, ".") || !strcmp(save_path, ".."))
		return;

	int akhir = check_ekstensi(save_path);
	int mulai = miring(save_path, akhir);

	for (i = mulai; i < akhir; i++)
	{
		if(save_path[i] != '/'){
			for (j = 0; j < jum_kode; j++)
			{
				if (save_path[i] == characterlist[j])
				{
					curr = (j + (jum_kode - key)) % jum_kode;
					save_path[i] = characterlist[curr];
					break;
				}
			}
		}
	}
}

```

Keterangan : 

- Variable save_path merupakan string yang akan dienkripsi, jika save_path ke-i sama dengan key ke-j, maka variable save_path ke-i akan dibah menjadi key ke (j+17) % 87.

- `if(save_path[i] != '/')` digunakan fungsi sebagai berikut untuk mengabaikan jika bertemu tanda / sesuai keterangan pada soal

- Pemanggilan fungsi dekripsi ini dilakukan di utility functions getattr, mkdir, rename, rmdir, dan fungsi-fungsi lainnya. Akan terdapat pengecekaan string "encv1_" pada path di masing-masing utility function dengan menggunakan fungsi strstr(). Dengan adanya fungsi ini, maka fungsi enkripsi dan dekripsi akan dipanggil untuk string tersebut dengan "encv1_" sebagai batasan awal mulai stringnya. 


## SOAL 2

### Enkripsi Versi 2



```

**TERIMA KASIH**
