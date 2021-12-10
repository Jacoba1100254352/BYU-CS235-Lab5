//
// Created by njudd on 10/20/2021.
//

#include <iostream>
#include "QS.h"

using namespace std;

int main(){
    QS * testQuickSort = new QS;

    testQuickSort->createArray(5);
    testQuickSort->addToArray(1);
    testQuickSort->addToArray(77);
    testQuickSort->addToArray(33);
    testQuickSort->addToArray(41);
    testQuickSort->addToArray(2);

    cout << testQuickSort->getArray() << endl;
    testQuickSort->sortAll();

    cout << testQuickSort->getArray() << endl;

    delete testQuickSort;

    return 0;
}
