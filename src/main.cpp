#include <stdio.h>
#include <iostream>

#include "main.h"
#include "linear.h"
#include "binary.h"

int main(int argc, char **argv) // argc = # of arguments, argv = pointer to arguments as char**
{
    int num_floors = 100;
    int num_pineapples = 2;
    int breaking_point = 0;

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
    search(linear_search, num_floors, num_pineapples, breaking_point);

    // binary search
    printf("binary combo search\t");
    search(binary_combo_search, num_floors, num_pineapples, breaking_point);

    return 0;
}

// function signatures for linear_search(), binary_combo_search(), etc. are the same, can be passed as pointers
void search(std::pair<int, int>(*search_type)(int, int, int), int num_floors, int num_pineapples, int breaking_point)
{
    std::pair<int, int> p = std::make_pair(0,0);
    int aggregate_cycles = 0;
    
    for(int i = 1; i < num_floors; i++) // identify how many cycles to find breaking point, starting at 1st floor
    {
        p = (*search_type)(num_floors, num_pineapples, i);
        aggregate_cycles += p.first; // aggregate all cycle counts for averaging
    }
    printf("average_cycles: %d\tremaining_pineapples: %d\n", aggregate_cycles/num_floors, p.second);
}
