#include <iostream>

using namespace std;

struct linked{
    int data;
    linked* next;
};

// Fungsi untuk memisahkan elemen genap dan ganjil
// Memodifikasi linked list dan mengembalikan dua linked list terpisah
pair<linked*, linked*> pisahkanGenapGanjil(linked* head){
    linked* genapHead = nullptr;
    linked* ganjilHead = nullptr;
    linked* current = head;

    while(current != nullptr){
        if(current->data % 2 == 0){ 
            // Jika elemen genap
            linked* genapNode = new linked;
            genapNode->data = current->data;
            genapNode->next = genapHead;
            genapHead = genapNode;
        }else{ 
            // Jika elemen ganjil
            linked* ganjilNode = new linked;
            ganjilNode->data = current->data;
            ganjilNode->next = ganjilHead;
            ganjilHead = ganjilNode;
        }
        current = current->next;
    }

    return make_pair(genapHead, ganjilHead);
}

int main(){
    linked* head = nullptr;
    int angka;

    // Buat dapatin angka dan memastikan angka tidak sama dengan 0
    while(cin >> angka && angka != 0){
        linked* link = new linked;
        link->data = angka;
        link->next = head;
        head = link;
    }

    int count = 0;
    linked* current = head;

    // Menghitung berapa banyak yang udah diinput sebelum 0
    while(current != nullptr){
        count++;
        current = current->next;
    }

    cout << "Jumlah link sebelum pemisahan: " << count << endl;

    // Memisahkan elemen genap dan ganjil
    pair<linked*, linked*> hasilPemisahan = pisahkanGenapGanjil(head);

    // Menghitung ulang jumlah link setelah pemisahan
    int countGenap = 0;
    int countGanjil = 0;

    current = hasilPemisahan.first; 
    // Menghitung jumlah link pada elemen genap
    while(current != nullptr){
        countGenap++;
        current = current->next;
    }

    current = hasilPemisahan.second; 
    // Menghitung jumlah link pada elemen ganjil
    while(current != nullptr){
        countGanjil++;
        current = current->next;
    }

    cout<<"Jumlah link elemen genap: "<<countGenap<<"\n";
    cout<<"Jumlah link elemen ganjil: "<<countGanjil<<"\n";

    return 0;
}
