#include <iostream>
#include <climits>
#include "PetaWisata.cpp"

using namespace std;

void cari_rute(int titik_awal, int titik_tujuan)
{
    int jarakterpendek[jumlah_lokasi + 1];
    bool dikunjungi[jumlah_lokasi + 1];
    int lokasisebelumnya[jumlah_lokasi + 1];

    for (int i = 1; i <= jumlah_lokasi; i++)
    {
        jarakterpendek[i] = INT_MAX;
        dikunjungi[i] = false;
        lokasisebelumnya[i] = -1;
    }

    jarakterpendek[titik_awal] = 0;

    for (int hitung = 1; hitung <= jumlah_lokasi - 1; hitung++)
    {
        int lokasiterpilih = -1;
        int jarakmin = INT_MAX;

        for (int v = 1; v <= jumlah_lokasi; v++)
        {
            if (!dikunjungi[v] &&
                jarakterpendek[v] < jarakmin)
            {
                jarakmin = jarakterpendek[v];
                lokasiterpilih = v;
            }
        }

        if (lokasiterpilih == -1)
            break;

        dikunjungi[lokasiterpilih] = true;

        for (int v = 1; v <= jumlah_lokasi; v++)
        {
            int bobot = jarak[lokasiterpilih][v];

            bool adajalur = (bobot != hubung);
            bool belumfinal = !dikunjungi[v];
            bool lebihdekat = (jarakterpendek [lokasiterpilih] +bobot <jarakterpendek [v]);

            if (adajalur &&
                belumfinal &&
                jarakterpendek[lokasiterpilih] != INT_MAX &&
                jarakterpendek[lokasiterpilih] + bobot < jarakterpendek[v])
            {
                jarakterpendek[v] =
                    jarakterpendek[lokasiterpilih] + bobot;

                lokasisebelumnya[v] = lokasiterpilih;
            }
        }
    }

    if (jarakterpendek[titik_tujuan] == INT_MAX)
    {
        cout << "\nRute tidak dapat diakses!\n";
        return;
    }

    cout << "\nEstimasi jarak tempuh = "
         << jarakterpendek[titik_tujuan]
         << " meter\n";

    cout << "Panduan rute = ";

    int urutan[jumlah_lokasi + 1];
    int jumlah_langkah = 0;

    int posisi = titik_tujuan;

    while (posisi != -1)
    {
        urutan[jumlah_langkah] = posisi;
        jumlah_langkah++;

        posisi = lokasisebelumnya[posisi];
    }

    for (int i = jumlah_langkah - 1; i >= 0; i--)
    {
        cout << nama_lokasi[urutan[i]];

        if (i > 0)
            cout << " -> ";
    }

    cout << endl;
}
