#include <string>
using namespace std;

const int jumlah_lokasi = 25;
const int hubung = 1;

int jarak[jumlah_lokasi + 1][jumlah_lokasi + 1];
string nama_lokasi[jumlah_lokasi + 1];

void set_nama_lokasi(int id, string nama){
    nama_lokasi[id] = nama;
}

void tambah_jalur(int a, int b, int jarak_meter){
    jarak[a][b] = jarak_meter;
    jarak[b][a] = jarak_meter;
}

void siapkan_peta(){
    for(int i = 0; i <= jumlah_lokasi; i++){
        for(int j = 0; j <= jumlah_lokasi; j++){
            jarak[i][j] = hubung;
        }
        jarak[i][i] = 0;
    }
}

void data_lokasi(){
    set_nama_lokasi(1, "Praktek Faperta");
    set_nama_lokasi(2, "Gedung Mashudi");
    set_nama_lokasi(3, "Parkir Motor 1");
    set_nama_lokasi(4, "Gazebo");
    set_nama_lokasi(5, "Kantin");
    set_nama_lokasi(6, "UKM");
    set_nama_lokasi(7, "Saung Unper");
    set_nama_lokasi(8, "Mushola");
    set_nama_lokasi(9, "Hotel Unper");
    set_nama_lokasi(10, "Lab Farmasi");
    set_nama_lokasi(11, "Gedung PGSD, Farmasi, Faperta");
    set_nama_lokasi(12, "Kopma, Ormawa");
    set_nama_lokasi(13, "Parkir Motor 2");
    set_nama_lokasi(14, "Parkir Motor 1");
    set_nama_lokasi(15, "Bundaran");
    set_nama_lokasi(16, "Lab Komputer 1");
    set_nama_lokasi(17, "Lab Komputer 2");
    set_nama_lokasi(18, "Perpustakaan");
    set_nama_lokasi(19, "Lab Toufel & Budaya");
    set_nama_lokasi(20, "Parkir Mobil");
    set_nama_lokasi(21, "Gedung Sholihin");
    set_nama_lokasi(22, "Ruang Sajian Perhotelan");
    set_nama_lokasi(23, "Lapang Basket & Voli");
    set_nama_lokasi(24, "Lapang Unper");
    set_nama_lokasi(25, "Pos Satpam");

   // ------------------------------------------------------
    // ZONA A: Faperta & Mashudi (pojok kiri atas)
    // -------------------------------------------------------
    tambah_jalur(1, 2,  80);   // Praktek Faperta -> Gedung Mashudi (cukup jauh, beda sisi)
    tambah_jalur(2, 3,  70);   // Gedung Mashudi  -> Parkir Motor 1

    // -------------------------------------------------------
    // ZONA B: Area atas (Parkir Motor 1 -> Kantin -> UKM -> Lab Farmasi -> Gedung PGSD)
    // Ini jalur koridor atas yang lurus ke kanan
    // -------------------------------------------------------
    tambah_jalur(3, 4,  20);   // Parkir Motor 1 -> Gazebo (sangat dekat)
    tambah_jalur(4, 5,  25);   // Gazebo -> Kantin
    tambah_jalur(5, 6,  20);   // Kantin -> UKM (bersebelahan)
    tambah_jalur(6, 10, 35);   // UKM -> Lab Farmasi
    tambah_jalur(10, 11, 30);  // Lab Farmasi -> Gedung PGSD/Farmasi/Faperta

    // -------------------------------------------------------
    // ZONA C: Area tengah (Gazebo -> Saung -> Mushola -> Hotel -> Kopma)
    // Jalur menurun dari area atas ke bundaran
    // -------------------------------------------------------
    tambah_jalur(4, 7,  30);   // Gazebo -> Saung Unper
    tambah_jalur(7, 8,  20);   // Saung Unper -> Mushola (sangat dekat)
    tambah_jalur(8, 9,  25);   // Mushola -> Hotel Unper
    tambah_jalur(8, 12, 30);   // Mushola -> Kopma & Ruang Organisasi

    // -------------------------------------------------------
    // ZONA D: Kopma & Parkir Motor 2 -> Bundaran
    // -------------------------------------------------------
    tambah_jalur(12, 13, 25);  // Kopma -> Parkir Motor 2 (Atas)
    tambah_jalur(13, 14, 20);  // Parkir Motor 2 (Atas) -> Parkir Motor 2 (Bundaran)
    tambah_jalur(12, 15, 35);  // Kopma -> Bundaran (jalur langsung)
    tambah_jalur(14, 15, 20);  // Parkir Motor 2 (Bundaran) -> Bundaran

    // -------------------------------------------------------
    // Mashudi -> Bundaran (jalur utama kiri kampus)
    // -------------------------------------------------------
    tambah_jalur(2, 15, 90);   // Gedung Mashudi -> Bundaran (jalan utama panjang)

    // -------------------------------------------------------
    // ZONA E: Bundaran -> area kiri bawah (Lab Komputer, Perpus, Lab Toufel)
    // -------------------------------------------------------
    tambah_jalur(15, 16, 25);  // Bundaran -> Lab Komputer 1
    tambah_jalur(16, 17, 20);  // Lab Komputer 1 -> Lab Komputer 2 (bersebelahan)
    tambah_jalur(17, 18, 30);  // Lab Komputer 2 -> Perpustakaan
    tambah_jalur(17, 19, 25);  // Lab Komputer 2 -> Lab Toufel & Budaya
    tambah_jalur(18, 19, 20);  // Perpustakaan -> Lab Toufel & Budaya (dekat)
    tambah_jalur(19, 20, 30);  // Lab Toufel -> Parkir Mobil

    // -------------------------------------------------------
    // ZONA F: Bundaran -> area kanan bawah (Sholihin, Lapangan, Satpam)
    // -------------------------------------------------------
    tambah_jalur(14, 21, 40);  // Parkir Motor 2 (Bundaran) -> Gedung Sholihin
    tambah_jalur(15, 21, 50);  // Bundaran -> Gedung Sholihin
    tambah_jalur(21, 22, 25);  // Sholihin -> Ruang Sajian Perhotelan
    tambah_jalur(21, 23, 30);  // Sholihin -> Lapang Basket & Voli
    tambah_jalur(22, 23, 20);  // Ruang Sajian -> Lapang Basket (bersebelahan)
    tambah_jalur(21, 24, 40);  // Sholihin -> Lapang Unper (agak jauh ke bawah)
    tambah_jalur(23, 24, 30);  // Lapang Basket -> Lapang Unper

    // -------------------------------------------------------
    // ZONA G: Menuju Pos Satpam (gerbang/exit bawah)
    // -------------------------------------------------------
    tambah_jalur(20, 25, 40);  // Parkir Mobil -> Pos Satpam
    tambah_jalur(24, 25, 35);  // Lapang Unper -> Pos Satpam
    tambah_jalur(15, 25, 80);  // Bundaran -> Pos Satpam (jalur utama vertikal)
}
