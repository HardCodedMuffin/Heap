#include "time.h"

// File Name: heap_utaa.h
//
// Author: Nigar ERCAN
// Date: 01/04/2020
// Assignment Number: 2
// CENG 202 Spring 2020
// Instructor: Ender SEVINC
//
// A binary heap.

using namespace std;

template<class ItemType>
class Heap_utaa {
public:

    //Constructor
    Heap_utaa();

    /****************************
     makeEmpty

     Function: Removes all the items from the heap.
     Postconditions: All the items have been removed/deallocated,
     *****************************/
    void makeEmpty();

    /****************************
     insertItem

     Function: Adds newItem to the heap.
     Postconditions: newItem is in the proper position for a heap.
     *****************************/
    void insertItem(const ItemType&);

    /****************************
     findMin

     Function: Finds minimum element in heap.
     Preconditions: heap has at least one node.
     Postconditions: Returns the smallest element in the heap.
     *****************************/
    ItemType findMin();

    /****************************
     deleteMin

     Function: Removes minimum element from heap.
     Preconditions: heap has at least one node.
     Postconditions: Smallest element has been removed from heap, and it's
                     still a heap.
     *****************************/
    void deleteMin();

    /****************************
     display

     Function: for diagnostic purposes, displays the tree like this
     (positions in array are shown):
     1
     2 3
     4 5 6 7
     8 9 10 11 12 13 14 15
     etc.
     *****************************/

    void display();

    void heapify();

    void heapSort();

private:
    int size;
    unique_ptr<ItemType[]> heap;
    ItemType array[100];
    bool isEmpty = false;
    bool isProper = false;
    bool isLeaf = false;
    // Given a position in the array, percolate that element up into place
    void percolateUp(int);
    // Given a position in the array, percolate that element down into place
    void percolateDown(int);
};

/*******************************
 / Function implementation
*******************************/

template<class ItemType>
Heap_utaa<ItemType>::Heap_utaa()
{
    heap = make_unique<ItemType[]>(100);
}

template<class ItemType>
void Heap_utaa <ItemType>::makeEmpty()
{
    heap.reset();
    isEmpty = true;
}

template<class ItemType>
ItemType Heap_utaa <ItemType>::findMin()
{
    return heap[1];
}

template<class ItemType>
void Heap_utaa <ItemType>::insertItem(const ItemType& newItem)
{
    // Place newItem at end of tree, use percolate up to move to proper place.  

    int loc = size + 1;

    if (size == 100)
        cout << "There is no more location in the Heap to fill in!";
    else
    {
        size++;
        heap[loc] = newItem;
        percolateUp(loc);
    }
}

template<class ItemType>
void Heap_utaa <ItemType>::percolateUp(int loc) {

    // If array[loc] is greater than its parent: done.
    // Else swap array[loc] with parent, repeat on the parent.
    // Make this recursive.

    int parent = loc / 2;
    if (loc == 0 || heap[loc] >= heap[parent])
        isProper = true;
    else {
        swap(heap[loc], heap[parent]);
        loc = parent;
        percolateUp(loc);
    }
}

template<class ItemType>
void Heap_utaa <ItemType>::deleteMin()
{
    // Move last item to top, use percolate down to move it to proper place.
    heap[1] = heap[size];
    size -= 1;
    percolateDown(1);
}

template<class ItemType>
void Heap_utaa <ItemType>::percolateDown(int loc)
{
    int parent = loc;
    int left = (2 * loc);   //Calculate index of left child.
    int right = (2 * loc) + 1; //Calculate index of right child.

    //Checks if left element is smaller then parent
    if (left < size && heap[left] < heap[parent])
        parent = left;

    //Checks if the right element is smaller then parent
    if (right < size && heap[right] < heap[parent])
        parent = right;

    // If statement that checks is the parent become root if it's not performs swap.
    // (Attention loc = 1 cause the heap starts from 1)
    if (parent != loc) {
        swap(heap[loc], heap[parent]);
        percolateDown(parent);
    }
}

// Funcion for change the order of min heap to max heap.
template<class ItemType>
void Heap_utaa <ItemType>::heapify()
{

}

template<class ItemType>
void Heap_utaa <ItemType>::heapSort()
{

}
// Provided... but updated. There is simple flow control with "if" that checks the heap is empty or not.
template<class ItemType>
void Heap_utaa <ItemType>::display() {
    if (!isEmpty) {
        for (int i = 1; i <= size; i++) {
            if ((i & (i - 1)) == 0)  // i is a power of 2
                cout << endl;
            cout << heap[i] << " ";
        }
    }
    else
        cout << "\n>> Sorry, the heap is empty!\n";
    cout << endl;
}
