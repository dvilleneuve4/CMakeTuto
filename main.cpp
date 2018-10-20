#include <iostream>
#include <cmath>
#include "CMakeTutoConfig.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout<< argv[0] << " Version " << CMakeTuto_VERSION_MAJOR << "." << CMakeTuto_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    double inputVal = strtod(argv[1], nullptr);
#ifdef USE_MYMATH
    double outputVal = mysqrt(inputVal);
#else
    double outputVal = sqrt(inputVal);
#endif

    std::cout<< "The square root of [" << inputVal << "] is [" << outputVal << "]" << std::endl;

    return 0;
}