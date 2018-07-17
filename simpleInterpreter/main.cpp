#include <iostream>
#include <string>

#include "simpleInterpreter.h"

int main()
{
    Interpreter ip;
    while (1) {
        ip.read();
        ip.eval();
        ip.print();
    }

    return 0;
}