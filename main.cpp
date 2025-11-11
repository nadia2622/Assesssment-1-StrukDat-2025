#include <iostream>
#include "SLL.h"

using namespace std;
int main() {
    List timeline;
    createNewLList(timeline);

    Post p1 = {1, "Haaaaiiii MyTelu!", 100, "t.nadia"}; // ini masukin datanya ke obj
    Post p2 = {2, "P info mendoan terdekat.", 20, "n.tambun"};
    Post p3 = {3, "UTS Praktikum ni bro", 4, "bunbunan"};

    insertLast(timeline, allocate(p1));
    insertLast(timeline, allocate(p2));
    insertLast(timeline, allocate(p3)); // Nah kan di soal mintanya postingan itu muncul dalam keadaan ascending berdasarkan idPost
    // Jadi saya pake insertLast aja hehehe.... (ga bikin insert baru yg isinya sorting membesar gitu. tapi saya urutin dari inputnya hehe)
    // maklum waktunya dikit, mls mikir hehe

    cout << "Selamat datang di timeline~\n";
    printList(timeline); // ini tampilkan semua postingan yang udah kita buat tadi

    cout << "\nSukai post ID 2...\n";
    likePost(timeline, 2); // ngelike postingan dengan id 2 (postingannya si n.tambun)
    printList(timeline);

    cout << "\nUnlike post ID 1...\n";
    unlikePost(timeline, 1); // ngurangin jml like yang ada di postingan id 1
    printList(timeline);

    cout << "\nCari postingan dengan idPost 3\n";
    address cari = findElement(timeline, 3);
    if (cari != Nil) {
        printPost(info(cari));
    } else {
        cout << "Post yang anda cari tidak ditemukan\n";
    }

    cout << "\nCari postingan dengan idPost 5\n";
    address found = findElement(timeline, 5); // outputnya tidak akan ditemukan
    if (found != Nil) {
        printPost(info(found));
    } else {
        cout << "Post yang anda cari tidak ditemukan\n";
    }

    cout << "\nCari postingan n.tambun\n";
    address cariUsr = findElementUsr(timeline, "n.tambun"); // ini nyari berdasarkan usrname
    if (cariUsr != Nil) {
        printPost(info(cariUsr));
    } else {
        cout << "Post yang anda cari tidak ditemukan\n";
    }

    return 0;
}
