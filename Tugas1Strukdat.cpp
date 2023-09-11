#include <iostream>
#include <string>

using namespace std;

struct mahasiswa {
    string nama;
    string nrp;
    int umur;
    bool jenis_kelamin;
};

int main() {
    struct mahasiswa mhs[10];
    int input_user;
    int n = 1;
    int jumlah = 0;
    
    while (n == 1) {
        cout << "Menu:\n";
        cout << "1. Menambah Data\n";
        cout << "2. Menghapus Data\n";
        cout << "3. Mengubah Data\n";
        cout << "4. Menampilkan data\n";
        cout << "5. Keluar\n";
        cout << "Pilih : ";
        cin >> input_user;
        cout << endl;

        switch(input_user) {
            case 1:
                cout << "Nama mahasiswa ke-" << jumlah + 1 << " : ";
                cin.ignore(); 
                getline(cin, mhs[jumlah].nama); 
                cout << "Nrp : ";
                cin >> mhs[jumlah].nrp;
                cout << "Umur : ";
                cin >> mhs[jumlah].umur;
                cout << "Jenis Kelamin (0 = Perempuan / 1 = Laki-laki) : ";
                cin >> mhs[jumlah].jenis_kelamin;
                cout << endl;
                jumlah++;
                break;
            case 2:
                int del;
                cout << "Masukkan index mahasiswa yang akan dihapus: ";
                cin >> del;
        
                if (del >= 1 && del <= jumlah) {
                    for (int i = del - 1; i < jumlah - 1; i++) {
                        mhs[i] = mhs[i + 1];
                    }
                    jumlah--;
                } else {
                    cout << "Indeks tidak valid.\n";
                }
                cout << endl;
                break;
            case 3:
                int update;
                cout << "Masukkan indeks mahasiswa yang yang akan diubah: ";
                cin >> update;
        
                if (update >= 1 && update <= jumlah) {
                    cout << "Nama mahasiswa ke-" << update << " : ";    
                    cin >> mhs[update - 1].nama;
                    cout << "Nrp : ";
                    cin >> mhs[update - 1].nrp;
                    cout << "Umur : ";
                    cin >> mhs[update - 1].umur;
                    cout << "Jenis Kelamin (0 = Perempuan / 1 = Laki-laki) : ";
                    cin >> mhs[update - 1].jenis_kelamin;
                } else {
                    cout << "Indeks tidak valid.\n";
                }
                cout << endl;
                break;
            case 4:
                for (int i = 0; i < jumlah; i++) {
                    cout << "Nama mahasiswa ke-" << i+1 << " : " << mhs[i].nama << endl;
                    cout << "Nrp : " << mhs[i].nrp << endl;
                    cout << "Umur : " << mhs[i].umur << endl;
                    cout << "Jenis Kelamin : ";
                    mhs[i].jenis_kelamin == 1 ? cout << "Laki-laki\n\n" : cout << "Perempuan\n\n";
                }
                break;
            case 5:
                n = 0;
                cout << endl;
                break;
            default:
                cout << "Input tidak valid. Silahkan coba lagi.\n";
        }
    }
    
    return 0;
}