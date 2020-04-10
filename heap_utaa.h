#include "time.h"

// File Name: heap_utaa.h
//
// Author: Nigar ERCAN
// Date: 01/04/2020
// Assignment Number: 2
// CENG 202 Spring 2020
// Instructor: Ender SEVINC
//
// A binary heap

using namespace std;

template<class ItemType>
class Heap_utaa {
public:
    
    //Constructor
    Heap_utaa();
    
    /****************************
     makeEmpty
     
     Function: Removes all the items from the heap.
     Postconditions: All the items have been removed/deallocated
     *****************************/
    void makeEmpty();
    
    /****************************
     insertItem
     
     Function: Adds newItem to the heap.
     Postconditions: newItem is in the proper position for a heap.
     *****************************/
    void insertItem(const ItemType &);
    
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
    
    ItemType getSize() { return size; }
    void setSize(ItemType sizee) { size = sizee; }

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
    
private:
    int size;
    unique_ptr<ItemType[]> heap;
    ItemType array[100];
    
    // Given a position in the array, percolate that element up into place
    void percolateUp(int);
    // Given a position in the array, percolate that element down into place
    void percolateDown(int);
    
};
/*******************************
 / Function implementations
*******************************/

template<class ItemType>
Heap_utaa<ItemType>::Heap_utaa()
{
   heap = make_unique<ItemType[]>(100);
}

template<class ItemType>
void Heap_utaa <ItemType>::makeEmpty()
{ 
    
}

template<class ItemType>
ItemType Heap_utaa <ItemType>::findMin()
{   
    return heap[1];
}

template<class ItemType>
void Heap_utaa <ItemType>::insertItem(const ItemType& newItem)
{
    // place newItem at end of tree, use percolate up to move to proper place

    if (size == 100) {
        cout << "There is no more location in the Heap to fill in!";
    }
    size++;
    int loc = size - 1;
    array[loc] = newItem;
    percolateUp(loc);
}

template<class ItemType>
void Heap_utaa <ItemType>::percolateUp(int loc) {

    // if array[loc] is greater than its parent: done
    // else swap array[loc] with parent, repeat on the parent
    // Make this recursive.

}


template<class ItemType>
void Heap_utaa <ItemType>::deleteMin()
{
    // move last item to top, use percolate down to move it to proper place

}

template<class ItemType>
void Heap_utaa <ItemType>::percolateDown(int loc) {

    int left = (loc * 2) + 1;  //calculate index of left child
    int right = (loc * 2) + 2;  //calculate index of right child

    if (left > size)   // no children


        if (left == size) { //one child
            // compare array[loc] to array[left], swap if needed
            //done
        }

    //two children:

    // if both children are greater than the parent: done
    // otherwise, swap the smaller of the two children with the
    // parent, repeat
}


// Provided:
template<class ItemType>
void Heap_utaa <ItemType>::display() {
    for (int i = 1; i <= size; i++) {
        if ((i & (i - 1)) == 0)  // i is a power of 2
            cout << endl;
        cout << array[i] << " ";
    }
    cout << endl;
}

