Tentu! Berikut adalah penjelasan lengkap **program C++** tersebut, agar kamu bisa memahaminya dengan baik untuk persiapan ujian:

---

### 📌 **Deskripsi Umum**

Program ini adalah **simulasi sistem pertemanan**, di mana kamu bisa:

* Menambahkan dan menghapus orang dari daftar teman.
* Menghubungkan dua teman agar menjadi teman satu sama lain.
* Memberikan **rekomendasi teman baru** berdasarkan teman dari teman.
* Mencetak semua teman, daftar teman dari seseorang, atau mencetak daftar orang yang memiliki hobi tertentu.

---

### 🧱 **Struktur Data**

#### 1. **Struct `Teman`**

Mewakili satu orang teman:

```cpp
struct Teman {
    string nama;
    int umur;
    string hobi1, hobi2, hobi3;
    Teman *next;                // untuk linked list semua teman
    NodeTeman *daftarTeman;     // linked list teman dari orang ini
};
```

#### 2. **Struct `NodeTeman`**

Digunakan untuk menyimpan **teman dari seseorang** (sebagai linked list):

```cpp
struct NodeTeman {
    Teman *teman;
    NodeTeman *next;
};
```

#### 3. **Struct `NodePerintah`**

Digunakan untuk menyimpan semua perintah yang diinputkan user dalam bentuk linked list:

```cpp
struct NodePerintah {
    string data;
    NodePerintah *next;
};
```

---

### 🧰 **Kelas `DaftarPerintah`**

Digunakan untuk menyimpan dan membaca semua perintah yang diinput oleh user:

* `Tambah(data)`: Menambahkan perintah baru ke akhir list.
* `getHead()`: Mengambil node pertama dari perintah.

---

### 📋 **Kelas `ListTeman`**

Berfungsi untuk menyimpan dan memanipulasi data teman. Fungsi-fungsinya:

#### `Add(nama, umur, hobi1, hobi2, hobi3)`

* Menambahkan teman baru ke linked list teman.
* Contoh: `ADD Andi 20 bola coding musik`.

#### `Remove(nama)`

* Menghapus teman berdasarkan nama.
* Jika tidak ada, muncul pesan `"TIDAK DITEMUKAN"`.

#### `search(nama)`

* Mencari teman berdasarkan nama dan mengembalikan pointer ke struct `Teman`.

#### `Connect(nama1, nama2)`

* Menghubungkan dua orang teman.
* Relasi ini dua arah.
* Dicek dulu apakah mereka sudah berteman (`SudahConnect`) agar tidak double.

#### `Recommend(nama)`

* Mencari **teman dari teman** (mutual friend) yang belum terhubung langsung dengan user.
* Hasilnya ditampilkan sebagai **rekomendasi**.

#### `PrintAll()`

* Mencetak semua teman yang ada di sistem, **diurutkan berdasarkan nama secara alfabetis**.

#### `PrintByTeman(nama)`

* Menampilkan semua teman dari seseorang, **diurutkan berdasarkan nama**.

#### `PrintHobi(hobi)`

* Menampilkan semua orang yang memiliki **salah satu dari tiga hobinya** cocok dengan input.
* **Diurutkan berdasarkan umur dari yang tertua ke termuda.**

---

### ⚙️ **Fungsi `main()`**

1. Menyimpan semua perintah yang diketik ke dalam `DaftarPerintah`.
2. Setelah input selesai (enter kosong), akan diproses satu per satu:

   * `ADD nama umur hobi1 hobi2 hobi3` → menambahkan teman.
   * `REMOVE nama` → menghapus teman.
   * `CONNECT nama1 nama2` → menghubungkan dua teman.
   * `RECOMMEND nama` → rekomendasi teman berdasarkan mutual friend.
   * `PRINT ALL` → cetak semua teman.
   * `PRINT namaTeman` → cetak teman-teman dari `namaTeman`.
   * `PRINT hobi` → cetak semua teman yang punya hobi itu.

---

### 🔍 **Contoh Input dan Output**

#### Input:

```
ADD Andi 20 bola coding musik
ADD Budi 22 musik coding bola
ADD Citra 21 melukis musik coding
CONNECT Andi Budi
CONNECT Budi Citra
RECOMMEND Andi
PRINT ALL
PRINT Andi
PRINT musik
```

#### Output:

```
Andi BERHASIL DITAMBAH
Budi BERHASIL DITAMBAH
Citra BERHASIL DITAMBAH
Citra
Andi 20 bola coding musik
Budi 22 musik coding bola
Citra 21 melukis musik coding
Budi
Budi
Citra
```

---

### 💡 **Poin Kunci untuk Ujian**

* **Sistem berbasis linked list**, baik untuk data teman maupun daftar perintah.
* **Relasi dua arah antar teman**.
* **Fitur rekomendasi menggunakan graph traversal sederhana** (teman dari teman).
* **Sorting dilakukan saat cetak**, menggunakan `std::sort()`.

---

Kalau kamu mau, aku juga bisa bantu buatin **mindmap atau diagram alur data** untuk kamu cetak atau pelajari secara visual. Mau?
