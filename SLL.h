#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

#define first(L) (L).first
#define next(P) (P)->next
#define info(P) (P)->info
#define Nil NULL

struct Post {
	int idPost;
	string kontenPost;
	int jumlahLike;
	string username;
};

typedef Post infotype;
typedef struct elmList *address;

struct elmList {
	infotype info;
	address next;
};

struct List {
	address first;
};

address newElement(infotype data);
address allocate(infotype data);
void createNewLList(List &a);

bool isEmpty(List a);
void insertFirst(List &a, address p);
void insertAfter(List &a, int idPost, address p);
void insertLast(List &a, address p);
void deleteFirst(List &a, address &p);
void deleteLast(List &a, address &p);
int length(List a);
address findElement(List a, int idPost);
void printList(List a);
void likePost(List &a, int idPost);
void printPost(const infotype &p);

#endif // SLL_H_INCLUDED

/* Penjelasan singkat:
Jadi, di file SLL.h (atau yang kita pelajari sebagai header)
isinya seperti cetakan, kita mau buat func apa aja di SLL.cpp nanti
yaaaaa intine gitu. itu yang aku pahami

- Nadia Tambunan 103122400005
*/