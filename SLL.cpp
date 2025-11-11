#include "SLL.h"
#include <iostream>

using namespace std;

address newElement(infotype data) {
    address p = new elmList; //
    info(p) = data;
    next(p) = Nil;
    return p;
} // ini function untuk membuat elemen baru (di dalamnya ada pointer)

address allocate(infotype data) {
    return newElement(data);
} // nah kalau ini function untuk mengalokasikan si elemen barunya tadi

void createNewLList(List &a) {
    first(a) = Nil;
} // ini function buat bikin list baru (seperti yang tlah kita pelajari, sebuah list itu terdiri dari elemen2. dan untuk SLL, ini, tiap elm memiliki info dan pointer next)

bool isEmpty(List a) {
    return first(a) == Nil;
} // ini function utk cek apakah isi listnya kosong

void insertFirst(List &a, address p) {
    next(p) = first(a);
    first(a) = p;
} // ini prosedur untuk masukin elm ke list dari depan

//Silahkan uncomment untuk meja NIM genap
//void insertLast(List &a, address p){
//    ...
//}

void insertAfter(List &a, int id, address p) {
    address q = findElement(a, id);
    if (q != Nil) {
        next(p) = next(q);
        next(q) = p;
    }
} // ini prosedur untuk masukin elm ke list di tengah2

void insertLast(List &a, address p) {
    if (isEmpty(a)) {
        insertFirst(a, p);
    } else {
        address q = first(a);
        while (next(q) != Nil) {
            q = next(q);
        }
        next(q) = p;
    }
} // ini prosedur untuk masukin elm ke list dari blkg

void deleteFirst(List &a, address &p) {
    if (!isEmpty(a)) {
        p = first(a);
        first(a) = next(p);
        next(p) = Nil;
    }
} // ini prosedur utk ngapus elm di list di depan

void deleteLast(List &a, address &p) {
    if (!isEmpty(a)) {
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

address findElement(List a, int id) {
    address p = first(a);
    while (p != Nil) {
        if (info(p).id == id) {
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
         << "Content: " << p.kontenPost << "\n";
}

void printList(List a) {
    address p = first(a);
    while (p != Nil) {
        printPost(info(p));
        cout << "-------------------------\n";
        p = next(p);
    }
}

void likePost(List &a, int id) {
    address p = findElement(a, id);
    if (p != Nil) {
        info(p).likes++;
    }
}