#include "SLL.h"
#include <iostream>

using namespace std;

address newElement(infotype data) {
    address p = new elmList; // bikin obj baru buat dijadiin pointer
    info(p) = data; // ini dua2nya inisialisasi
    next(p) = Nil;
    return p;
} // ini function untuk membuat elemen baru (di dalamnya ada pointer)

address allocate(infotype data) {
    return newElement(data);
} // nah kalau ini function untuk mengalokasikan si elemen barunya tadi

void createNewLList(List &a) {
    first(a) = Nil; // bikin list baru, dmn elemennya masih ksoongan
} // ini function buat bikin list baru (seperti yang tlah kita pelajari, sebuah list itu terdiri dari elemen2. dan untuk SLL, ini, tiap elm memiliki info dan pointer next)

bool isEmpty(List a) {
    return first(a) == Nil; // jika elemennya == Null, brarti kosong
} // ini function utk cek apakah isi listnya kosong

void insertFirst(List &a, address p) {
    next(p) = first(a); // pointer next(p) jadi first(a)
    first(a) = p; // trs first(a) nya jadi first -> yg artinya, elemen yang dimasukin ini jadi elemen pertama di list
} // ini prosedur untuk masukin elm ke list dari depan

//Silahkan uncomment untuk meja NIM genap
//void insertLast(List &a, address p){
//    ...
//}

void insertAfter(List &a, int id, address p) {
    address q = findElement(a, id); // q iki pointer buat nyari si elm nya
    if (q != Nil) {
        next(p) = next(q); // yaa intinya ini buat naro di tengah2 list (maaf ga jelasin secara detail. dikejar wkt soale)
        next(q) = p;
    }
} // ini prosedur untuk masukin elm ke list di tengah2

void insertLast(List &a, address p) {
    if (isEmpty(a)) { // jika list kosong, maka masukin elm ke list menggunakan insertFirst() (brarti masukinnya dari depan)
        insertFirst(a, p); 
    } else { // ini kalau list nya udah ada isinya
        address q = first(a); // pointer q dijadiin first a
        while (next(q) != Nil) { // trs suruh mundur 1 1 si q nya, sampai next(q) ny null (di akhir)
            q = next(q);
        }
        next(q) = p;
    }
} // ini prosedur untuk masukin elm ke list dari blkg

void deleteFirst(List &a, address &p) {
    if (!isEmpty(a)) { //
        p = first(a);
        first(a) = next(p);
        next(p) = Nil;
    }
} // ini prosedur utk ngapus elm di list di depan

void deleteLast(List &a, address &p) {
    if (!isEmpty(a)) { // enih kalau list tidak kosong
        if (next(first(a)) == Nil) {
            p = first(a);
            first(a) = Nil;
        } else {
            address q = first(a);
            while (next(next(q)) != Nil) {
                q = next(q);
            }
            p = next(q);
            next(q) = Nil;
        }
    }
}

int length(List a) {
    int count = 0;
    address p = first(a);
    while (p != Nil) {
        count++;
        p = next(p);
    }
    return count;
}

address findElement(List a, int idPost) {
    address p = first(a); // inisialisasi pointernya
    while (p != Nil) { // selama p tdk null, lakukan:
        if (info(p).idPost == idPost) { // cari obj info(p).idPost
            return p; // kembalikan si elm post berdasarkan id yang dicari
        }
        p = next(p);
    }
    return Nil; // ini klau list nya kosong
}

address findElementUsr(List a, string username) {
    address p = first(a);
    while (p != Nil) {
        if (info(p).username == username) {
            return p;
        }
        p = next(p);
    }
    return Nil;
}

void printPost(const infotype &p) {
    cout << "ID: " << p.idPost << " | "
         << "User: " << p.username << " | "
         << "Likes: " << p.jumlahLike << "\n"
         << "Content: " << p.kontenPost << "\n"; // ini buat post di timelinenya
}

void printList(List a) {
    address p = first(a);
    while (p != Nil) {
        printPost(info(p)); // tampilkan isi list (atau postingannya)
        cout << "-------------------------\n";
        p = next(p);
    }
}

void likePost(List &a, int id) {
    address p = findElement(a, id); 
    if (p != Nil) {
        info(p).jumlahLike++; // postingan, likenya nambah 1
    }
}

void unlikePost(List &a, int id) {
    address p = findElement(a, id);
    if (p != Nil && info(p).jumlahLike > 0) {
        info(p).jumlahLike--; // postingan, likenya ngurang 1
    }
}