#include <stdio.h>
#include <iostream>

#include "linear.h"
#include "binary.h"

int main(int argc, char **argv) // argc = # of arguments, argv = pointer to arguments as char**
{
    int num_floors = 100;
    int breaking_point = 0;
    int pineapples = 2;
    int cycles = 0;

    /*
    printf("how many floors?\n");
    std::cin >> num_floors;

    printf("lowest floor that will cause pineapple to break?\n");
    std::cin >> breaking_point;
    if(breaking_point > num_floors)
    {
        printf("breaking floor is greater than total number of floors, invalid parameters.\n");
        return -1;
    }

    printf("how many total pineapples?\n");
    std::cin >> pineapples;

    printf("parameters: num_floors = %d, breaking_point = %d, pineapples = %d\n", num_floors, breaking_point, pineapples);
    */

    // linear search
    std::pair<int, int> p;
    cycles = 0;
    printf("linear\t");
    for(int i = 1; i < num_floors; i++) // identify how many cycles to find breaking point, starting at 1st floor
    {
        p = linear(num_floors, i, pineapples);
        cycles += p.second;
    }
    printf("remaining_pineapples: %d\taverage_cycles: %d\n", p.first, cycles/num_floors);

    // binary search
    cycles = 0;
    printf("binary\t");
    for(int i = 1; i < num_floors; i++) // identify how many cycles to find breaking point, starting at 1st floor
    {
        cycles += binary(num_floors, i, pineapples);
    }
    printf("average_cycles: %d\n", cycles/num_floors);

    return 0;
}
