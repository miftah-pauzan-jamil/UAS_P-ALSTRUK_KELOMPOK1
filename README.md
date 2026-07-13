# Navigasi UNPER 🗺️

Program navigasi kampus berbasis **C++** yang membantu pengguna (mahasiswa, dosen, maupun tamu kampus) menemukan **rute terpendek** antar lokasi di lingkungan kampus **Universitas Perjuangan Tasikmalaya (UNPER)**.

Tugas Ujian Akhir Semester (UAS) — Mata Kuliah **Algoritma & Struktur Data**
Program Studi Teknik Informatika, Fakultas Teknik, Universitas Perjuangan Tasikmalaya
Dosen Pengampu: **Aso Sudiarjo, S.Kom., M.Kom.**

## Deskripsi Proyek

Kampus UNPER direpresentasikan sebagai **graf berbobot** yang terdiri dari **25 titik lokasi** (gedung, area parkir, fasilitas umum, hingga pos satpam), yang dihubungkan oleh jalur-jalur dengan bobot berupa jarak tempuh dalam satuan meter.

Permasalahan pencarian rute terpendek pada graf ini diselesaikan menggunakan **algoritma Dijkstra**, sehingga relevan dengan materi struktur data graf serta algoritma *greedy*/*shortest path* pada mata kuliah Algoritma dan Struktur Data.

## Fitur

- Menampilkan daftar seluruh lokasi (1–25) beserta nomor kodenya.
- Menerima input titik lokasi awal dan tujuan dari pengguna melalui terminal (`cin`).
- Validasi input agar berada pada rentang kode lokasi yang valid (1–25).
- Menghitung estimasi jarak tempuh terpendek antara dua lokasi menggunakan algoritma Dijkstra.
- Menampilkan panduan rute secara berurutan (contoh: `Lokasi A -> Lokasi B -> Lokasi C`) beserta total estimasi jarak dalam meter.
- Memberikan pesan peringatan apabila rute antara dua lokasi tidak dapat ditemukan.

## Struktur Program

Program terdiri dari tiga berkas C++ yang saling terhubung:

| File | Modul | Deskripsi |
|---|---|---|
| `PetaWisata.cpp` | Modul Peta | Menyiapkan matriks jarak (adjacency matrix), menyimpan nama lokasi (`set_nama_lokasi()`), dan menambahkan jalur/relasi antar lokasi beserta bobotnya (`tambah_jalur()`) melalui `siapkan_peta()` dan `data_lokasi()`. |
| `Navigasi.cpp` | Modul Navigasi | Menjalankan algoritma Dijkstra melalui `cari_rute()` untuk menghitung estimasi jarak terpendek dan menyusun panduan rute. |
| `main.cpp` | Modul Utama | Mengintegrasikan modul peta dan navigasi: menampilkan daftar lokasi, menerima input pengguna, memvalidasi input, dan memanggil `cari_rute()` untuk menampilkan hasil akhir. |

### Alur Program

1. Program menginisialisasi peta melalui `siapkan_peta()` dan `data_lokasi()`.
2. Program menampilkan daftar 25 lokasi beserta nomor kodenya.
3. Pengguna memasukkan nomor kode lokasi awal dan lokasi tujuan.
4. Program memvalidasi kedua kode berada pada rentang 1–25; jika tidak valid, program menampilkan pesan kesalahan dan berhenti.
5. Jika input valid, program memanggil `cari_rute()` yang menjalankan algoritma Dijkstra dan menampilkan estimasi jarak beserta panduan rute.

## Struktur Data yang Digunakan

Peta kampus direpresentasikan sebagai **graf tidak berarah dan berbobot** (*weighted undirected graph*) dengan 25 simpul, menggunakan **adjacency matrix**. Pencarian rute terpendek diselesaikan dengan **algoritma Dijkstra berbasis array**, tanpa struktur data tambahan seperti *priority queue*.

| Struktur Data | Digunakan di | Fungsi / Kegunaan |
|---|---|---|
| `jarak[26][26]` (adjacency matrix) | `PetaWisata.cpp` | Menyimpan bobot (jarak dalam meter) tiap pasangan lokasi. Nilai sentinel `-1` (variabel `hubung`) menandai bahwa dua lokasi tidak memiliki jalur langsung. |
| `nama_lokasi[26]` (array of string) | `PetaWisata.cpp` | Menyimpan nama setiap titik lokasi (1–25) untuk ditampilkan sebagai menu dan pada hasil rute. |
| `jarakterpendek[]` | `Navigasi.cpp` | Menyimpan estimasi jarak terpendek sementara dari titik awal ke setiap lokasi selama proses Dijkstra berjalan. |
| `dikunjungi[]` (array boolean) | `Navigasi.cpp` | Menandai lokasi yang sudah final/selesai diproses agar tidak diproses ulang. |
| `lokasisebelumnya[]` (predecessor array) | `Navigasi.cpp` | Menyimpan lokasi sebelumnya pada rute optimal, digunakan untuk merekonstruksi jalur akhir (backtracking). |
| `urutan[]` | `Navigasi.cpp` | Menyimpan hasil backtracking dari titik tujuan ke titik awal sebelum dibalik dan ditampilkan sebagai panduan rute. |

### Alasan Pemilihan Struktur Data

- **Adjacency matrix** dipilih karena jumlah lokasi relatif kecil dan tetap (25 titik), sehingga matriks 26×26 masih efisien dari segi memori dan mudah diimplementasikan.
- Dengan adjacency matrix, pengecekan jalur langsung antar dua lokasi (`jarak[u][v]`) dilakukan dalam waktu **O(1)**, memudahkan proses relaksasi bobot pada algoritma Dijkstra.
- **Array** (bukan struktur data dinamis seperti *linked list* atau *struct graph* berbasis *pointer*) dipilih agar kompatibel dengan compiler Dev-C++/TDM-GCC yang digunakan pada mata kuliah ini, sehingga implementasi tetap sederhana, stabil, dan mudah ditelusuri.
- Kekurangan utama pendekatan ini adalah kompleksitas ruang **O(V²)**, yang kurang efisien untuk graf besar dan jarang terhubung (*sparse graph*). Namun untuk studi kasus 25 lokasi, hal ini tidak berdampak signifikan.

## Cara Menjalankan

Program membutuhkan compiler C++ (misalnya g++/TDM-GCC atau Dev-C++).

```bash
g++ main.cpp PetaWisata.cpp Navigasi.cpp -o navigasi_unper
./navigasi_unper
```

Kemudian ikuti instruksi pada terminal: pilih kode lokasi awal dan tujuan sesuai daftar yang ditampilkan.

## Anggota Kelompok

| No | Nama | NIM | Tugas / Peran |
|---|---|---|---|
| 1 | Miftah Pauzan Jamil | 2503010060 | Ketua Kelompok — bertanggung jawab atas keseluruhan proyek: mengatur, merancang, dan mengarahkan jalannya pengerjaan. |
| 2 | Muhammad Fasya Sya'bana | 2503010062 | Modul Peta — menyiapkan data lokasi dan mengatur jarak antar lokasi (`PetaWisata.cpp`). |
| 3 | Arfyn Diazs Aryada | 2503010138 | Modul Navigasi — mengambil data peta dan membuat perhitungan rute terpendek/tercepat (`Navigasi.cpp`). |
| 4 | Ifan Julian Pratama | 2503010070 | Modul Main — mengintegrasikan data peta dan navigasi lalu memanggilnya pada program utama (`main.cpp`). |

## Kesimpulan

- Sistem "Navigasi UNPER" berhasil dirancang untuk membantu pengguna menemukan rute terpendek antar 25 titik lokasi di lingkungan kampus UNPER menggunakan algoritma Dijkstra.
- Adjacency matrix dipilih karena kesederhanaan implementasi, kemudahan akses data (O(1) per pasangan lokasi), dan kesesuaian dengan skala studi kasus (25 lokasi).
- Pembagian tugas berbasis modul (peta, navigasi, dan main) memudahkan kelompok bekerja secara paralel.

## Pengembangan Selanjutnya

- Menambahkan antarmuka grafis (GUI).
- Integrasi peta visual interaktif.
- Migrasi struktur data menjadi *adjacency list* agar lebih efisien apabila jumlah lokasi kampus terus bertambah.

---

Proyek ini dikembangkan sebagai bagian dari tugas mata kuliah Algoritma & Struktur Data, Kelompok 1, TI25C — Universitas Perjuangan Tasikmalaya.
