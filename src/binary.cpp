#include "binary.h"

std::pair<int, int> binary(int num_floors, int breaking_point, int num_pineapples)
{
    int cycles = 0;
    int remaining_pineapples = num_pineapples;
    int broken = 0;
    do
    {
        int middle = num_floors/2;
        if(middle >= breaking_point) // middle floor is greater than breaking_point, pineapple is broken
        {
            num_pineapples--;
            broken = 1;
        }
        else // middle floor is less than breaking point, pineapple is not broken
        {
            
        }
        
        cycles++;
    } while (broken < num_pineapples);
    
    return std::make_pair(0, 0);
}