#include <iostream>
#include "qpdf/string.h"

int
main(int argc, char *argv[])
{
    std::cout << "qpdf example" << std::endl;

    qpdf::string test("test pdf string");
    std::cout << test.value() << std::endl;
    return 0;
}
