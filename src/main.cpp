#include <stdio.h>
#include <iostream>

#include "main.h"
#include "linear.h"
#include "binary.h"

int main(int argc, char **argv) // argc = # of arguments, argv = pointer to arguments as char**
{
    int num_floors = 100;
    int breaking_point = 0;
    int num_pineapples = 2;

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
    printf("linear search\t");
    search(linear, num_floors, breaking_point, num_pineapples);

    // binary search
    printf("binary search\t");
    search(binary, num_floors, breaking_point, num_pineapples);

    return 0;
}

void search (std::pair<int, int>(*search_type)(int, int, int), int num_floors, int breaking_point, int num_pineapples)
{
    std::pair<int, int> p = std::make_pair(0,0);
    int num_cycles = 0;
    
    for(int i = 1; i < num_floors; i++) // identify how many cycles to find breaking point, starting at 1st floor
    {
        p = (*search_type)(num_floors, i, num_pineapples);
        num_cycles += p.second;
    }
    printf("remaining_pineapples: %d\taverage_cycles: %d\n", p.first, num_cycles/num_floors);
}