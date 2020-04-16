#include "binary.h"

std::pair<int, int> binary_combo_search(int num_floors, int num_pineapples, int breaking_point)
{
    int remaining_pineapples = num_pineapples;
    int cycles, lower_bound = 0;
    int upper_bound = num_floors;
    
    do
    {
        int middle = (upper_bound - lower_bound)/2;
        if(middle == 0)
        {
            // is this even possible?
        }
        if(middle >= breaking_point) // middle floor is greater than breaking_point, pineapple is broken
        {
            remaining_pineapples--;
        }
        else // middle floor is less than breaking point, pineapple is not broken
        {
            lower_bound = middle;
        }
        
        cycles++;
    } while (remaining_pineapples < num_pineapples);
    
    return std::make_pair(0, 0);
}
