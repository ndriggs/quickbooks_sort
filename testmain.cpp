#include "QS.h"
#include <iostream>

int main(){
    QS line;
    line.createArray(10);
    line.addToArray(50);
    line.addToArray(5);
    line.addToArray(47);
    line.addToArray(1);
    line.addToArray(27);
    line.addToArray(15);
    line.addToArray(30);
    
    cout << "Your array sir:" << endl << line.getArray() << endl;
    cout << "Your size sir:" << endl << line.getSize() << endl;
    
    int median = line.medianOfThree(0, 6);
    cout << "Your new array sir:" << endl << line.getArray() << endl;
    cout << "With the pivot at index " << median << endl;
    
    return 0;
}