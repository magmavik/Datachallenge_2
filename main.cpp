#include <iostream>
// #include "./lib/events_list.h"
#include "./lib/stocastic_events.h"

int main()
{
    stocastic_events stocazz(1000,10);
    stocazz.generate_events();
    stocazz.print_list();
    return 0;
}