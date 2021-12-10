//
// Created by njudd on 10/20/2021.
//

//
// Created by njudd on 10/17/2021.
//

#include "QS.h"


void QS::sortAll() {
    cout << "In sortAll" << endl;
    if(arrayToSort != nullptr){
        primarySort(0, getSize() - 1);
    }
}

/* [1, 4, 2, 9, 5] */
void QS::primarySort(int left, int right) {
    cout << "in primary sort" << endl;
    if (left < right) {
        int pivot = medianOfThree(left, right);
        pivot = partition(left, right, pivot);
        if (right > left + 5) {
            primarySort(left, pivot - 1);
            primarySort(pivot + 1, right);
        }
    }
}

/* [1, 4, 2, 9, 5] */
int QS::medianOfThree(int left, int right) {
    cout << "In median of three" << endl;

    if (getSize() == 0 || arrayToSort == nullptr || left + 1 == right || left == right || left < 0 || right > getSize() - 1 || left > right) {
        return -1;
    }

    int middle = (left + right)/2;

    int tempMiddle = arrayToSort[middle];
    int tempRight = arrayToSort[right];

    if (tempMiddle < arrayToSort[left]) {
        arrayToSort[middle] = arrayToSort[left];
        arrayToSort[left] = tempMiddle;
    }

    if (tempRight < arrayToSort[middle]) {
        arrayToSort[right] = arrayToSort[middle];
        arrayToSort[middle] = tempRight;
    }

    if (arrayToSort[middle] < arrayToSort[left]) {
        tempMiddle = arrayToSort[middle];
        arrayToSort[middle] = arrayToSort[left];
        arrayToSort[left] = tempMiddle;
    }

    return middle;
}

int QS::partition(int left, int right, int pivotIndex) {
    /*
* Partitions a subarray around a pivot value selected according to
* median-of-three pivot selection.  Because there are multiple ways to partition a list,
* we will follow the algorithm on page 611 of the course text when testing this function.
*
* The values which are smaller than the pivot should be placed to the left
* of the pivot; the values which are larger than the pivot should be placed
* to the right of the pivot.
*
* Returns -1 if the array is null, if either of the given integers is out of
* bounds, or if the first integer is not less than the second integer, or if the
* pivot is not within the sub-array designated by left and right.
*
* @param left
* 		the left boundary for the subarray to partition
* @param right
* 		the right boundary for the subarray to partition
* @param pivotIndex
* 		the index of the pivot in the subarray
* @return
*		the pivot's ending index after the partition completes; -1 if
* 		provided with bad input
 */
    cout << "In partition" << endl;
    if (pivotIndex < left || pivotIndex > right || left >= right || left < 0 || right >= getSize() || getSize() == 0 || arrayToSort == nullptr) {
        return -1;
    }

    // Start up and down at either end of the sequence.
    // The first table element is the pivot value.

    //Set the pivot to the first value for simplicity
    int pivot = arrayToSort[pivotIndex];
    int begin = arrayToSort[left];
    arrayToSort[left] = pivot;
    arrayToSort[pivotIndex] = begin;

    int vigilanteUp = left + 1;
    int vigilanteDown = right - 1;
    do {
        /* Invariant:
           All items in table[first] through table[up - 1] <= table[first]
           All items in table[down + 1] through table[last - 1] > table[first]
        */

        while ((vigilanteUp != right - 1) && arrayToSort[left] >= arrayToSort[vigilanteUp]) {
            vigilanteUp++;
        }
        // Assert: up equals last-1 or table[up] > table[first].
        while (arrayToSort[left] < arrayToSort[vigilanteDown]) {
            vigilanteDown--;
        }
        // Assert: down equals first or table[down] <= table[first].
        if (arrayToSort[vigilanteUp] < arrayToSort[vigilanteDown]) {   // if up is to the left of down,
            // Exchange table[up] and table[down].
            // std::iter_swap(vigilanteUp, vigilanteDown);
            int temp1 = arrayToSort[vigilanteUp];
            int temp2 = arrayToSort[vigilanteDown];

            arrayToSort[vigilanteDown] = temp1;
            arrayToSort[vigilanteUp] = temp2;
        }
    } while (vigilanteUp < vigilanteDown); // Repeat while up is left of down.

    // Exchange table[first] and table[down] thus putting the
    // pivot value where it belongs.
    // Return position of pivot.
    //std::iter_swap(left, vigilanteDown);
    int temp1 = arrayToSort[left];
    int temp2 = arrayToSort[vigilanteDown];

    arrayToSort[vigilanteDown] = temp1;
    arrayToSort[left] = temp2;
    return vigilanteDown;


}

string QS::getArray() const{
    string array;
    cout << "In getArray" << endl;
    if (arrayToSort != nullptr) {
        for (int i = 0; i < getSize(); i++)
            if (arrayToSort[i] != -2147483648) {
                if (i != getSize() - 1)
                    array += to_string(arrayToSort[i]) + ",";
                else array += to_string(arrayToSort[i]);
            }
    }
    return array;
}

int QS::getSize() const{
    cout << "In getSize" << endl;
//    if (arrayToSort != nullptr) {
//        int counter = 0;
//        for (int i = 0; i < getSize(); i++) {
//            if (arrayToSort[i] != NULL) {
//                counter++;
//            }
//        }
//        return counter;
//    }
//    return 0;
    return arrayLength;
}

bool QS::addToArray(int value){
    cout << "In addToArray" << endl;
    for(int i = 0; i < getSize(); i++) {
        if(arrayToSort[i] == -2147483648) {
            arrayToSort[i] = value;
            return true;
        }
    }
    return false;
}

bool QS::createArray(int capacity){
    cout << "In createArray" << endl;
    if(capacity > 0){

        clear();

        arrayToSort = new int[capacity];
        arrayLength = capacity;

        for(int i = 0; i < capacity; i++){
            arrayToSort[i] = -2147483648;
        }

        return true;

    } else return false;
}

void QS::clear(){
    cout << "In clear" << endl;
    int* temp = arrayToSort;

    delete[] temp;
}