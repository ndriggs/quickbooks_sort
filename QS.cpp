/*
* QSInterface.h
*
*  Created on: May 1, 2014
*  Last Updated on: March 30, 2015
*/


#include "QS.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
* WARNING: You may not modify any part of this document, including its name
*/



QS::QS(){
    index = 0;
    size = 0;
    array = NULL;
}
QS::~QS(){}

/*
* sortAll()
*
* Sorts elements of the array.  After this function is called, every
* element in the array is less than or equal its successor.
*
* Does nothing if the array is empty.
*/
void QS::sortAll(){
    if(index > 0){
        cout << "In the sortall function! Yay!" << endl;
        quicksort(0, index - 1);
    }
}

void QS::quicksort(int left, int right){
    //base case if size of array is 1
    if((right - left) < 1){ //can also do: if((right - left) < 1) {return;}
        cout << "Base case baby!" << endl;
        return;
    }
    //find a pivot and partion the array
    int pivot = medianOfThree(left, right);  ////NEEDS ACTUAL INDEX
    cout << "medianOfThree: " << getArray() << endl; 
    int newpivot = partition(left, right, pivot);
    cout << "Partition: " << getArray() << endl;
    
    //quicksort the left and right subarrays
    quicksort(left, newpivot);
    cout << "Just sorted left subarray: " << getArray() << endl;   
    quicksort(newpivot + 1, right);
    cout << "Just sorted right subarray: " << getArray() << endl;
}


/*
* medianOfThree()
*
* The median of three pivot selection has two parts:
*
* 1) Calculates the middle index by averaging the given left and right indices:
*
* middle = (left + right)/2
*
* 2) Then bubble-sorts the values at the left, middle, and right indices.
*
* After this method is called, data[left] <= data[middle] <= data[right].
* The middle index will be returned.
*
* Returns -1 if the array is empty, if either of the given integers
* is out of bounds, or if the left index is not less than the right
* index.
*
* @param left
* 		the left boundary for the subarray from which to find a pivot
* @param right
* 		the right boundary for the subarray from which to find a pivot
* @return
*		the index of the pivot (middle index); -1 if provided with invalid input
*/
int QS::medianOfThree(int left, int right) {
    if((index == 0) || (left < 0) || (right >= size) || (left >= right))
        return -1;
    int middle = (left + right) / 2;
    
    //sorts the left, middle, and right using bubble sort
    if(array[left] > array[middle]){
        int temp = array[left];
        array[left] = array[middle];
        array[middle] = temp;
    }
    if(array[right] < array[middle]){
        int temp = array[middle];
        array[middle] = array[right];
        array[right] = temp;
    }
    if(array[middle] < array[left]){
        int temp = array[left];
        array[left] = array[middle];
        array[middle] = temp;
    }
    return middle;
}

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
int QS::partition(int left, int right, int pivotIndex) {
    //check if valid
    if((array == NULL) || (left < 0) || (right >= index) || (left > right) || (pivotIndex > right) || (pivotIndex < left))
        return -1;
    
    //move the pivot to the first index of the subarray
    int temp = array[left];
    array[left] = array[pivotIndex];
    array[pivotIndex] = temp;
    
    //gearing up for something big
    int up = left + 1;
    int down = right;
    
    do {
        //up finds the first term greater than the pivot
        while((array[up] <= array[left]) && (up < down))
            up++;
        
        //down finds the first term less than the pivot
        while((array[down] > array[left]) && (down > up))
            down--;
            
        //switch up and down    
        if(up < down){
            int tmp = array[up];
            array[up] = array[down];
            array[down] = tmp;
        }
    } while(up < down);
    
    //switch down and first
    temp = array[left];
    array[left] = array[down - 1];
    array[down - 1] = temp;
    
    //return the index of the pivot
    return down - 1;
}

/*
* Produces a comma delimited string representation of the array. For example: if my array
* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
* with no trailing comma.  The number of cells included equals the number of values added.
* Do not include the entire array if the array has yet to be filled.
*
* Returns an empty string, if the array is NULL or empty.
*
* @return
*		the string representation of the current array
*/
string QS::getArray() const {
    stringstream to_string;
    if((array == NULL) || (index == 0))
        return "";
    for(int i = 0; i < index; i++){
        to_string << array[i];
        if(i != (index - 1))
            to_string << ", ";
    }
    return to_string.str();
}

/*
* Returns the number of elements which have been added to the array.
*/
int QS::getSize() const {
    return index;
}

/*
* Adds the given value to the end of the array starting at index 0.
* For example, the first time addToArray is called,
* the give value should be found at index 0.
* 2nd time, value should be found at index 1.
* 3rd, index 2, etc up to its max capacity.
*
* If the array is filled, do nothing.
* returns true if a value was added, false otherwise.
*/
bool QS::addToArray(int value){
    if(index > (size - 1))
        return false;
    array[index] = value;
    index += 1;
    return true;
}

/*
* Dynamically allocates an array with the given capacity.
* If a previous array had been allocated, delete the previous array.
* Returns false if the given capacity is non-positive, true otherwise.
*
* @param
*		size of array
* @return
*		true if the array was created, false otherwise
*/
bool QS::createArray(int capacity){
    if(capacity <= 0)
        return false;
    if(array != NULL){
        delete [] array;
        array = NULL;
    }
    array = new int[capacity];
    size = capacity;
    return true;
}

/*
* Resets the array to an empty or NULL state.
*/
void QS::clear() {
    index = 0;
}
