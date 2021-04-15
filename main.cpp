#include <iostream>
// #include "./lib/events_list.h"
#include "./lib/repulsive_events.h"

int main()
{
    srand(time(NULL));
    repulsive_events stocazz(1000,100,5,10);
    stocazz.generate_events();
    stocazz.add_gaussian_noise(5);
    stocazz.print_list();
    return 0;
}