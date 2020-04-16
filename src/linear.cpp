#include "linear.h"

std::pair<int, int> linear_search(int num_floors, int num_pineapples, int breaking_point)
{
    int remaining_pineapples = num_pineapples;
    int cycles = 1; // takes at least one cycle
    for(int i = 1; i < num_floors; i++) // start at 1, there's no basement (0th floor)
    {
        if(i == breaking_point)
        {
            remaining_pineapples--; // decrement, then assignment
            break;
        }
        cycles++;
    }
    return std::make_pair(remaining_pineapples, cycles);
}