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

    pointerr->display();
 
}

