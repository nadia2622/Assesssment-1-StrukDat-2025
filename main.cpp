#include <iostream>
#include "SLL.h"

using namespace std;
int main() {
    List timeline;
    createNewLList(timeline);

    Post p1 = {1, "Haaaaiiii MyTelu!", 100, "Nadia"};
    Post p2 = {2, "P info mendoan terdekat.", 20, "Tambun"};
    Post p3 = {3, "UTS Praktikum ni bro", 4, "Bunan"};

    insertLast(timeline, allocate(p1));
    insertLast(timeline, allocate(p2));
    insertLast(timeline, allocate(p3));

    cout << "Initial timeline:\n";
    printList(timeline);

    cout << "\nLiking post ID 2...\n";
    likePost(timeline, 2);
    printList(timeline);

    cout << "\nFind post ID 3 and print:\n";
    address found = findElement(timeline, 3);
    if (found != Nil) {
        printPost(info(found));
    } else {
        cout << "Post not found\n";
    }

    cout << "\nDeleting first post...\n";
    address del;
    deleteFirst(timeline, del);
    cout << "After deletion:\n";
    printList(timeline);

    return 0;
}
