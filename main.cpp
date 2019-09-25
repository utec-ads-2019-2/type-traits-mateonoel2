#include <iostream>

#include "test/tester.h"

using namespace std;

int main(int argc, char const *argv[]) {
    //Tester::execute();

    SelfList<int> list(SelfList<int>::Transpose);
    for (int i = 0; i < 100; i++)
        list.insert(i);

    list.find(50);
    list.find(49);
    list.find(50);

    list.print();

    return EXIT_SUCCESS;
}
