// UAP ASD KELOMPOK 2
// Header komentar untuk identifikasi kelompok dan anggota
// Nama Anggota:
// 1. Nama: Ibnu Jalalluddin Mukhlis (245150301111004)
// 2. Nama: Muhammad Naufal Mathara Rahman (245150307111006)
// 3. Nama: Raden Fatih Abdul Jabbar (245150307111017)
// 4. Nama: Jahzeel Erason Nicodemus (245150300111002)
// 5. Nama: POLARESKY MARSA AURIGA (245150307111002)
// 6. Nama: FAREL PARIS HUTAJULU (245150301111003)
// Deskripsi: Program ini mengelola daftar teman dengan berbagai perintah seperti menambah, menghapus, menghubungkan teman, merekomendasikan teman, dan mencetak daftar teman berdasarkan kriteria tertentu.

#include <iostream>     // Library untuk input/output stream (cin, cout)
#include <string>       // Library untuk tipe data string
#include <sstream>      // Library untuk string stream (parsing string)
#include <vector>       // Library untuk container vector (array dinamis)
#include <algorithm>    // Library untuk fungsi algoritma (sort)
using namespace std;    // Menggunakan namespace standard untuk mempersingkat penulisan

struct Teman;           // Forward declaration struct Teman (deklarasi awal)

struct NodeTeman        // Struct untuk node dalam linked list teman
{
    Teman *teman;       // Pointer ke data teman
    NodeTeman *next;    // Pointer ke node teman berikutnya
};

struct Teman            // Struct untuk menyimpan informasi teman
{
    string nama;        // Nama teman
    int umur;          // Umur teman
    string hobi1, hobi2, hobi3;  // Tiga hobi teman
    Teman *next;       // Pointer ke teman berikutnya dalam linked list utama
    NodeTeman *daftarTeman;  // Pointer ke linked list teman dari teman ini

    // Constructor untuk inisialisasi struct Teman
    Teman(string n, int u, string h1, string h2, string h3, Teman *nxt = nullptr)
        : nama(n), umur(u), hobi1(h1), hobi2(h2), hobi3(h3), next(nxt), daftarTeman(nullptr) {}
        // Inisialisasi semua member variable dengan parameter yang diberikan
};

struct NodePerintah     // Struct untuk node dalam linked list perintah
{
    string data;        // Data perintah dalam bentuk string
    NodePerintah *next; // Pointer ke node perintah berikutnya
    NodePerintah(string d) : data(d), next(nullptr) {}  // Constructor
};

class DaftarPerintah    // Class untuk mengelola daftar perintah
{
private:
    NodePerintah *head; // Pointer ke node pertama
    NodePerintah *tail; // Pointer ke node terakhir

public:
    DaftarPerintah() : head(nullptr), tail(nullptr) {}  // Constructor

    void Tambah(string data)  // Method untuk menambah perintah baru
    {
        NodePerintah *baru = new NodePerintah(data);  // Membuat node baru
        if (!head)          // Jika linked list kosong
            head = tail = baru;  // Set head dan tail ke node baru
        else                // Jika linked list tidak kosong
        {
            tail->next = baru;   // Hubungkan tail dengan node baru
            tail = baru;         // Update tail ke node baru
        }
    }

    NodePerintah *getHead() { return head; }  // Getter untuk mendapatkan head
};

class ListTeman         // Class untuk mengelola daftar teman
{
private:
    Teman *head;        // Pointer ke teman pertama dalam linked list

public:
    ListTeman() : head(nullptr) {}  // Constructor

    void Add(string nama, int umur, string hobi1, string hobi2, string hobi3)  // Method untuk menambah teman
    {
        Teman *baru = new Teman{nama, umur, hobi1, hobi2, hobi3, nullptr};  // Membuat teman baru
        if (head == nullptr)    // Jika linked list kosong
        {
            head = baru;        // Set head ke teman baru
        }
        else                    // Jika linked list tidak kosong
        {
            Teman *temp = head; // Pointer temporary untuk traversal
            while (temp->next != nullptr)  // Cari node terakhir
            {
                temp = temp->next;  // Pindah ke node berikutnya
            }
            temp->next = baru;  // Hubungkan node terakhir dengan teman baru
        }
        cout << nama << " BERHASIL DITAMBAH" << endl;  // Output konfirmasi
    }

    void Remove(string nama)  // Method untuk menghapus teman
    {
        Teman *temp = head;   // Pointer untuk traversal
        Teman *prev = nullptr;  // Pointer untuk node sebelumnya

        while (temp != nullptr && temp->nama != nama)  // Cari teman yang akan dihapus
        {
            prev = temp;      // Simpan node sebelumnya
            temp = temp->next;  // Pindah ke node berikutnya
        }

        if (temp == nullptr)  // Jika teman tidak ditemukan
        {
            cout << nama << " TIDAK DITEMUKAN" << endl;  // Output error
            return;           // Keluar dari function
        }

        if (prev == nullptr)  // Jika yang dihapus adalah head
        {
            head = head->next;  // Update head ke node berikutnya
        }
        else                  // Jika yang dihapus bukan head
        {
            prev->next = temp->next;  // Hubungkan node sebelum dan sesudah
        }

        delete temp;          // Hapus node dari memory
        cout << nama << " BERHASIL DIHAPUS" << endl;  // Output konfirmasi
    }

    Teman *search(string nama)  // Method untuk mencari teman berdasarkan nama
    {
        Teman *temp = head;     // Pointer untuk traversal
        while (temp != nullptr) // Loop sampai akhir linked list
        {
            if (temp->nama == nama)  // Jika nama cocok
                return temp;         // Return pointer ke teman
            temp = temp->next;       // Pindah ke node berikutnya
        }
        return nullptr;         // Return null jika tidak ditemukan
    }

    bool SudahConnect(Teman *a, Teman *b)  // Method untuk cek apakah dua teman sudah terhubung
    {
        NodeTeman *t = a->daftarTeman;  // Pointer ke daftar teman dari teman a
        while (t != nullptr)            // Loop melalui daftar teman
        {
            if (t->teman == b)          // Jika teman b ditemukan dalam daftar
                return true;            // Return true
            t = t->next;                // Pindah ke node berikutnya
        }
        return false;                   // Return false jika tidak ditemukan
    }

    void TambahTeman(Teman *a, Teman *b)  // Method untuk menambah teman ke daftar teman
    {
        NodeTeman *baru = new NodeTeman{b, a->daftarTeman};  // Buat node baru
        a->daftarTeman = baru;  // Set node baru sebagai head daftar teman
    }

    void Connect(string nama1, string nama2)  // Method untuk menghubungkan dua teman
    {
        Teman *t1 = search(nama1);  // Cari teman pertama
        Teman *t2 = search(nama2);  // Cari teman kedua

        if (t1 != nullptr && t2 != nullptr && t1 != t2 && !SudahConnect(t1, t2))  // Validasi
        {
            TambahTeman(t1, t2);  // Tambah t2 ke daftar teman t1
            TambahTeman(t2, t1);  // Tambah t1 ke daftar teman t2 (hubungan dua arah)
        }
    }

    void Recommend(string nama)  // Method untuk merekomendasikan teman
    {
        Teman *user = search(nama);  // Cari user yang meminta rekomendasi
        if (user == nullptr)         // Jika user tidak ditemukan
        {
            cout << "PENGGUNA TIDAK DITEMUKAN" << endl;  // Output error
            return;                  // Keluar dari function
        }

        NodeTeman *temanUser = user->daftarTeman;  // Pointer ke daftar teman user
        Teman *hasil[100];           // Array untuk menyimpan hasil rekomendasi
        int jumlah = 0;              // Counter jumlah rekomendasi

        while (temanUser != nullptr) // Loop melalui teman-teman user
        {
            NodeTeman *temanDariTeman = temanUser->teman->daftarTeman;  // Teman dari teman
            while (temanDariTeman != nullptr)  // Loop melalui teman dari teman
            {
                Teman *calon = temanDariTeman->teman;  // Calon teman yang direkomendasikan
                if (calon != user && !SudahConnect(user, calon))  // Validasi calon
                {
                    bool sudahAda = false;  // Flag untuk cek duplikasi
                    for (int i = 0; i < jumlah; i++)  // Loop cek duplikasi
                    {
                        if (hasil[i] == calon)  // Jika sudah ada dalam hasil
                        {
                            sudahAda = true;    // Set flag
                            break;              // Keluar dari loop
                        }
                    }
                    if (!sudahAda)              // Jika belum ada dalam hasil
                    {
                        hasil[jumlah++] = calon;  // Tambah ke hasil dan increment counter
                    }
                }
                temanDariTeman = temanDariTeman->next;  // Pindah ke teman berikutnya
            }
            temanUser = temanUser->next;  // Pindah ke teman user berikutnya
        }

        if (jumlah == 0)  // Jika tidak ada rekomendasi
        {
            cout << "TIDAK ADA REKOMENDASI" << endl;  // Output pesan
        }
        else              // Jika ada rekomendasi
        {
            for (int i = 0; i < jumlah; i++)  // Loop output semua rekomendasi
            {
                cout << hasil[i]->nama << " ";  // Output nama teman yang direkomendasikan
            }
            cout << endl;  // Newline di akhir
        }
    }

    void PrintAll()  // Method untuk mencetak semua teman
    {
        vector<Teman *> semuaTeman;  // Vector untuk menyimpan pointer teman

        Teman *temp = head;     // Pointer untuk traversal
        while (temp != nullptr) // Loop melalui semua teman
        {
            semuaTeman.push_back(temp);  // Tambah teman ke vector
            temp = temp->next;           // Pindah ke teman berikutnya
        }

        sort(semuaTeman.begin(), semuaTeman.end(), [](Teman *a, Teman *b)  // Sort berdasarkan nama
             { return a->nama < b->nama; });  // Lambda function untuk comparator

        for (Teman *t : semuaTeman)  // Loop melalui vector yang sudah di-sort
        {
            // Output informasi lengkap teman
            cout << t->nama << " " << t->umur << " " << t->hobi1 << " " << t->hobi2 << " " << t->hobi3 << endl;
        }
    }

    void PrintByTeman(string nama)  // Method untuk mencetak daftar teman dari seseorang
    {
        Teman *t = search(nama);    // Cari teman berdasarkan nama
        if (t == nullptr)           // Jika tidak ditemukan
        {
            cout << nama << " TIDAK DITEMUKAN" << endl;  // Output error
            return;                 // Keluar dari function
        }

        vector<string> daftarNamaTeman;  // Vector untuk menyimpan nama teman
        NodeTeman *temp = t->daftarTeman;  // Pointer ke daftar teman
        while (temp != nullptr)     // Loop melalui daftar teman
        {
            daftarNamaTeman.push_back(temp->teman->nama);  // Tambah nama ke vector
            temp = temp->next;      // Pindah ke teman berikutnya
        }

        sort(daftarNamaTeman.begin(), daftarNamaTeman.end());  // Sort nama secara alfabetis
        for (const string &n : daftarNamaTeman)  // Loop output nama yang sudah di-sort
        {
            cout << n << endl;      // Output nama teman
        }
    }

    void PrintHobi(string hobi)  // Method untuk mencetak teman berdasarkan hobi
    {
        vector<Teman *> cocok;   // Vector untuk teman yang cocok
        Teman *temp = head;      // Pointer untuk traversal
        while (temp != nullptr)  // Loop melalui semua teman
        {
            // Cek apakah hobi cocok dengan salah satu dari tiga hobi teman
            if (temp->hobi1 == hobi || temp->hobi2 == hobi || temp->hobi3 == hobi)
            {
                cocok.push_back(temp);  // Tambah ke vector jika cocok
            }
            temp = temp->next;       // Pindah ke teman berikutnya
        }

        // Sort berdasarkan umur (dari yang tertua ke termuda)
        sort(cocok.begin(), cocok.end(), [](Teman *a, Teman *b)
             { return a->umur > b->umur; });

        for (Teman *t : cocok)  // Loop output teman yang cocok
        {
            cout << t->nama << endl;  // Output nama teman
        }
    }
};

int main()  // Function utama program
{
    DaftarPerintah daftarPerintah;  // Object untuk menyimpan daftar perintah
    string input;                   // Variable untuk menyimpan input

    while (getline(cin, input))     // Loop membaca input line by line
    {
        if (input.empty())          // Jika input kosong
            break;                  // Keluar dari loop
        daftarPerintah.Tambah(input);  // Tambah input ke daftar perintah
    }

    ListTeman daftar;               // Object untuk mengelola daftar teman
    NodePerintah *node = daftarPerintah.getHead();  // Get node pertama dari daftar perintah
    while (node != nullptr)         // Loop melalui semua perintah
    {
        stringstream ss(node->data);  // Buat stringstream dari data perintah
        string command, nama, hobi1, hobi2, hobi3;  // Variable untuk parsing
        int umur;                   // Variable untuk umur

        ss >> command;              // Extract command dari stringstream

        if (command == "ADD")       // Jika perintah adalah ADD
        {
            if (ss >> nama >> umur >> hobi1 >> hobi2 >> hobi3)  // Extract semua parameter
            {
                daftar.Add(nama, umur, hobi1, hobi2, hobi3);  // Panggil method Add
            }
            else                    // Jika parameter tidak lengkap
            {
                cout << "INPUT INVALID" << endl;  // Output error
            }
        }
        else if (command == "REMOVE")  // Jika perintah adalah REMOVE
        {
            if (ss >> nama)         // Extract nama
            {
                daftar.Remove(nama);  // Panggil method Remove
            }
            else                    // Jika nama tidak ada
            {
                cout << "INPUT INVALID" << endl;  // Output error
            }
        }
        else if (command == "CONNECT")  // Jika perintah adalah CONNECT
        {
            string nama1, nama2;    // Variable untuk dua nama
            if (ss >> nama1 >> nama2)  // Extract kedua nama
            {
                daftar.Connect(nama1, nama2);  // Panggil method Connect
            }
        }
        else if (command == "RECOMMEND")  // Jika perintah adalah RECOMMEND
        {
            if (ss >> nama)         // Extract nama
            {
                daftar.Recommend(nama);  // Panggil method Recommend
            }
        }
        else if (command == "PRINT")    // Jika perintah adalah PRINT
        {
            string param;           // Variable untuk parameter print
            if (ss >> param)        // Extract parameter
            {
                if (param == "ALL") // Jika parameter adalah ALL
                {
                    daftar.PrintAll();  // Panggil method PrintAll
                }
                else if (daftar.search(param))  // Jika parameter adalah nama teman yang ada
                {
                    daftar.PrintByTeman(param);  // Panggil method PrintByTeman
                }
                else                // Jika parameter adalah hobi
                {
                    daftar.PrintHobi(param);  // Panggil method PrintHobi
                }
            }
        }
        else                        // Jika perintah tidak dikenali
        {
            cout << "PERINTAH INVALID" << endl;  // Output error
        }
        node = node->next;          // Pindah ke perintah berikutnya
    }
    return 0;                       // Return 0 menandakan program berhasil
}
