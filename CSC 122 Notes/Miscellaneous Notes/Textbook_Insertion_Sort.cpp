#include <array>
#include <iomanip>
#include <iostream>

using namespace std;

//sorting an array into ascending order
template <typename T, size_t size>
void insertionSort(array<T, size>& items) {
    //loop over the elements of the array
    for (size_t next{1}; next < items.size(); ++next ) {
        T insert{items[next]}; // save value of next item to insert
        size_t moveIndex{next}; // initialize location to place element
        
        //search for the location in which to put the current element
        while ( (moveIndex > 0) && (items[moveIndex - 1] > insert) ) {
            //shift element one slot to the right
            items[moveIndex] = items[moveIndex - 1];
            --moveIndex;
        }
        
        items[moveIndex] = insert; //place insert item back into array
    }
}

int main() {
    const size_t arraySize{10}; //size of array
    array<int, arraySize> data{34, 56, 4, 10, 77, 51, 93, 30, 5, 32};
    
    cout << "Unsorted array:\n";
    
    //output original array
    for (size_t i{0}; i < arraySize; ++i) {
        cout << setw(4) << data[i];    
    }
    
    insertionSort(data); // sort the array
    
    cout << "\nSorted array:\n";
    
    //output sorted array
    for (size_t i{0}; i < arraySize; ++i) {
        cout << setw(4) << data[i];    
    }
    
    cout << endl;
}
