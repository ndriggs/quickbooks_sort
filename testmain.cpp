#include "QS.h"
#include <iostream>

int main(){
    QS line;
    line.createArray(10);
    line.addToArray(2);
    line.addToArray(5);
    line.addToArray(47);
    line.addToArray(2);
    line.addToArray(27);
    line.addToArray(15);
    
    cout << "Your array sir:" << endl << line.getArray() << endl;
    cout << "Your size sir:" << endl << line.getSize() << endl;
    return 0;
}