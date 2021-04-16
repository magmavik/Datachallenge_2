#include <iostream>
#include <stdlib.h>
#include "./lib/stocastic_events.h"
#include "./lib/repulsive_events.h"

int main(int argc, char **argv)
{
    double range = 1000;
    int N_success = 10000; 


    if( !strcmp(argv[1], "-r") )
    {
        std::cout << "hello world";
        double sigma = atof(argv[2]);
        repulsive_events events(range,N_success,sigma);
        events.generate_events();
        events.sort_list();
        events.print_list();
        events.print_distance_csv("prova_1");
    }
    if ( !strcmp(argv[1], "-s") )
    {
        std::cout << "stocastic series selected \n";
        stocastic_events events(range,N_success);
        events.generate_events();
        events.sort_list();
        events.print_list();
        events.print_distance_csv("prova_1");
    }
    return 0;
}