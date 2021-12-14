// Hello! I am egoriwe999
// This programm can show you characterization of your processor(MMX,SSE,AVX)
// My telegram account - https://t.me/egoriwe999
// My telegram channel - https://t.me/whitehacker999

#include <iostream>
#include <limits.h>
#include <intrin.h>

int main()
{
    char processorName[13];
    processorName[12] = 0;
    int regs[4];
    __cpuid(regs, 0);
    memcpy(processorName, &regs[1], 4);
    memcpy(processorName + 4, &regs[3], 4);
    memcpy(processorName + 8, &regs[2], 4);
    __cpuid(regs, 1);
    if (regs[3] & (1 << 23))
    {
        std::cout << "MMX" << std::endl;
    }
    if (regs[3] & (1 << 25))
    {
        std::cout << "SSE" << std::endl;
    }
    if (regs[3] & (1 << 28))
    {
        std::cout << "AVX" << std::endl;
    }

}