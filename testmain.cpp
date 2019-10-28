#include "QS.h"
#include <iostream>

int main(){
    QS line;
    line.createArray(11);
    line.addToArray(2);
    line.addToArray(10);
    line.addToArray(9);
    line.addToArray(3);
    line.addToArray(2);
    line.addToArray(7);
    line.addToArray(5);
    line.addToArray(4);
    line.addToArray(8);
    line.addToArray(6);
    line.addToArray(1);
    
    cout << "Your array sir:" << endl << line.getArray() << endl;
    cout << "Your size sir:" << endl << line.getSize() << endl;
    //line.sortAll();
    //cout << "Tada: " << endl;
    //cout << line.getArray() << endl;
    
    
    int piv = line.medianOfThree(0, line.getSize() - 1); //////
    cout << "pivot at index " << piv << endl;
    cout << line.getArray() << endl << endl;
    int newpiv = line.partition(0, line.getSize() - 1, piv); //////
    cout << "new piv at index " << newpiv << endl;
    cout << line.getArray() << endl << endl;
    
    piv = line.medianOfThree(newpiv + 1, line.getSize() - 1);
    newpiv = line.partition(newpiv + 1, line.getSize() - 1, piv); ///////
    cout << "New array with right part partitioned, with piv at index " << newpiv << endl;
    cout << line.getArray() << endl;
    
    line.sortAll();
    cout << endl << line.getArray() << endl;
    
    
    //line.sortAll();
    //cout << endl << line.getArray() << endl;
    
    return 0;
}