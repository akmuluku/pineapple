#include <stdio.h>
#include <iostream>

#include "linear_search.h"

int main(int argc, char **argv) // argc = # of arguments, argv = pointer to arguments as char**
{
    int num_floors, breaking_point, pineapples = 0;

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

    // linear search
    linear_search(num_floors, breaking_point, pineapples);

    return 0;
}
