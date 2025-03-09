#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Film
{
    string judul;
    string kode;
    double harga;
};

Film daftarFilm[] = {
    {"Avengers", "F001", 8.50},
    {"Titanic", "F002", 9.00},
    {"Inception", "F003", 8.80},
    {"Interstellar", "F004", 9.20},
    {"Joker", "F005", 8.70}};
int jumlahFilm = sizeof(daftarFilm) / sizeof(daftarFilm[0]);

void tampilkanFilm()
{
    cout << "\nDaftar Film:\n";
    cout << endl;
    cout << "==================================\n";
    cout << left << setw(15) << "Judul" << setw(10) << "Kode" << "Harga" << endl;
    cout << "----------------------------------\n";
    for (int i = 0; i < jumlahFilm; i++)
    {
        cout << left << setw(15) << daftarFilm[i].judul
             << setw(10) << daftarFilm[i].kode
             << fixed << setprecision(2) << daftarFilm[i].harga << endl;
    }
    cout << "==================================\n";
}

void cariBerdasarkanKode()
{
    string kode;
    cout << "\nMasukkan Kode: ";
    cin >> kode;
    bool ditemukan = false;
    for (int i = 0; i < jumlahFilm; i++)
    {
        if (daftarFilm[i].kode == kode)
        {
            cout << "Film ditemukan: " << daftarFilm[i].judul << " - " << daftarFilm[i].harga << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "Film dengan Kode " << kode << " tidak ditemukan.\n";
    }
}

void cariBerdasarkanJudul()
{
    string judul;
    cout << "\nMasukkan Judul: ";
    cin.ignore();
    getline(cin, judul);
    bool ditemukan = false;
    for (int i = 0; i < jumlahFilm; i++)
    {
        if (daftarFilm[i].judul == judul)
        {
            cout << "Film ditemukan: " << daftarFilm[i].kode << " - " << daftarFilm[i].harga << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "Film dengan Judul " << judul << " tidak ditemukan.\n";
    }
}

int partition(Film arr[], int low, int high)
{
    double pivot = arr[high].harga;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].harga <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(Film arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSortDesc(Film arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].harga < arr[j + 1].harga)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void tampilkanMenu()
{
    cout << "\n======== Bioskop Double A ========\n";
    cout << "1. Tampilkan Film\n";
    cout << "2. Cari berdasarkan kode\n";
    cout << "3. Cari berdasarkan judul\n";
    cout << "4. Sort Harga Film (asc)\n";
    cout << "5. Sort Harga Film (desc)\n";
    cout << "6. Exit\n";
    cout << "Pilih menu: ";
}

int main()
{
    int pilihan;
    do
    {
        tampilkanMenu();
        cin >> pilihan;
        system("cls");
        switch (pilihan)
        {
        case 1:
            tampilkanFilm();
            break;
        case 2:
            cariBerdasarkanKode();
            break;
        case 3:
            cariBerdasarkanJudul();
            break;
        case 4:
            quickSort(daftarFilm, 0, jumlahFilm - 1);
            tampilkanFilm();
            cout << "Film telah diurutkan berdasarkan harga (ascending).\n";
            break;
        case 5:
            bubbleSortDesc(daftarFilm, jumlahFilm);
            tampilkanFilm();
            cout << "Film telah diurutkan berdasarkan harga (descending).\n";
            break;
        case 6:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);
    return 0;
}
