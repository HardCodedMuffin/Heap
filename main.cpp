#include <iostream>
#include "heap_utaa.h"

using namespace std;

int main()
{
    unsigned int size;

    cout << ">> Select size of the heap: ";
    cin >> size;

    Heap_utaa<char>* pointerr = new Heap_utaa<char>();

    for (int i = 0; i < size; i++)
    {
        char character; cin >> character;
        pointerr->insertItem(character);
    }

    cout << "\n>> The minimum element of the heap is: " << pointerr->findMin() << endl;
    pointerr->deleteMin();
    pointerr->display();
    cout << "\n>> The minimum element of the heap is: " << pointerr->findMin() << endl;
    pointerr->makeEmpty();
    pointerr->display();



    /*
       Sample Arrays
       hgfedcbaonmlkji
       onmlkjihgfedcba
       edcbaon
       gfedcba
    */
}

