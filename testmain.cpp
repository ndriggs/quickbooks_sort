#include "QS.h"
#include <iostream>

int main(){
    QS line;
    line.createArray(11);
    line.addToArray(50);
    line.addToArray(5);
    line.addToArray(47);
    line.addToArray(1);
    line.addToArray(27);
    line.addToArray(15);
    line.addToArray(30);
    line.addToArray(1);
    line.addToArray(27);
    line.addToArray(15);
    line.addToArray(99);
    
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
    
    
    line.sortAll();
    cout << endl << line.getArray() << endl;
    
    return 0;
}