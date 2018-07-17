#include <iostream>
#include <string>

#include "simpleInterpreter.h"

int main()
{
    Interpreter ip;
    while (1) {
        std::string cmd;
        std::cout << "Enter command: ";
        std::getline(std::cin, cmd);

        ip.read(cmd);
        auto res = ip.eval("1+2-3");
        std::cout << "res: " << res << '\n';
        ip.printBuffer();
    }

    return 0;
}