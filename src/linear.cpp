#include "linear.h"

std::pair<int, int> linear(int num_floors, int breaking_point, int pineapples)
{
    int num_pineapples = pineapples;
    int cycles = 1; // it takes at least one cycle
    for(int i = 1; i < num_floors; i++) // start at 1, there's no basement (0th floor)
    {
        if(i == breaking_point)
        {
            num_pineapples--; // decrement, then assignment
            break;
        }
        cycles++;
    }
    return std::make_pair(num_pineapples, cycles);
}