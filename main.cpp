#include <iostream>
using namespace std;
#include "Navigasi.cpp"

int main () {
    siapkan_peta();
    data_lokasi();

    cout << "sitem navigasi unper \n \n";
    cout << "Daftar lokasi :\n";
    for (int i=1; i <= jumlah_lokasi; i++){
        cout << "[" << i << "]" << nama_lokasi[i] << "\n";

    }

    int lokasiawal,lokasitujuan;
    cout << "\nMasukan lokasi anda saat ini = ";
    cin >> lokasiawal;
    cout << "Masukan angka tujuan = ";
    cin >> lokasitujuan;

    bool inputvalid = (lokasiawal  >= 1 && lokasiawal  <= jumlah_lokasi) &&
                        (lokasitujuan >= 1 && lokasitujuan <= jumlah_lokasi);
    
    if (!inputvalid) {
        cout << "\n[!]Kode lokasi tidak dikenali program!\n";
        return 1;

    }

    cout << "\nMengkalkulasi rute terbaik untuk perjalanan anda...";
    cari_rute (lokasiawal,lokasitujuan);
    return 0;



}
