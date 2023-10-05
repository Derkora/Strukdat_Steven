#include <iostream>
#include <map>

using namespace std;

map<string, map<string, string>> dataAkun;

//pr untuk hashing di sini modifikasi 
int hashfunction(string password){
    int a, b, c, d, e;
    int hasil;
    a = tolower(password[0]);
    b = tolower(password[1]);
    c = tolower(password[2]);
    e = 39;
    if(a%2 == 0){
        if(b%2 == 0){
            d = ((a + b + c) % (a + c));
        }else{
            d = ((a + b + 2*c) % (a + c));
        }
    }else{
        if(b%2 == 0){
            d = ((a + b + c) % (b + c));
        }else{
            d = ((2*a + b + c) % (a + c));
        }
    }
    hasil = d % e;
    return hasil;
}

void registrasi(){
    string username, password, fullname;
    cout<<"Masukkan username:\n";
    cin>>username;
    cout<<"Masukkan password:\n";
    cin>>password;
    cout<<"Masukkan nama lengkap:\n";
    cin>>fullname;

    string hash_key = to_string(hashfunction(password));
    map<string, string> dataDetail;
    dataDetail["username"] = username;
    dataDetail["password"] = password;
    dataDetail["fullname"] = fullname;

    printf("Registrasi berhasil\n");
    dataAkun[hash_key] = dataDetail;
}

bool login(){
    string username, password;
    cout<<"Masukkan username:\n";
    cin>>username;
    cout<<"Masukkan password:\n";
    cin>>password;

    string hash_key = to_string(hashfunction(password));

    if(dataAkun.find(hash_key) != dataAkun.end() && dataAkun[hash_key]["username"] == username && dataAkun[hash_key]["password"] == password){
        cout<<"Login berhasil! Selamat datang, "<<dataAkun[hash_key]["fullname"]<<"\n";
        return true;
    }else{
        cout<<"Login gagal. Username atau password salah."<<"\n";
        return false;
    }
}

void printAkun(){
    cout<<"\n";
    for(auto i = dataAkun.begin(); i != dataAkun.end(); i++){
        cout<<"Key: "<<i->first<<"\t"<<", Username: "<< i->second["username"]<<", Fullname: "<< i->second["fullname"]<<"\n";
    }
}

void menu(){
    while(true){
        int input_user;
        cout<<"=== MENU ===\n";
        cout<<"1. Registrasi\n";
        cout<<"2. Login\n";
        cout<<"3. Print Data Akun\n";
        cout<<"4. Exit\n";
        cin>>input_user;

        if(input_user == 1){
            registrasi();
        }else if(input_user == 2){
            if (login()){
            }
        }else if(input_user == 3){
            printAkun();
        }else if(input_user == 4){
            break;
        }else{
            cout<<"Input tidak valid. Silakan coba lagi.\n";
        }
    }
}

int main(){
    menu();
    return 0;
}
