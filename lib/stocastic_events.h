#include <random>

#include "events_list.h"
#include "iostream"

class stocastic_events : public events_list
{
    public:
        stocastic_events(int range,int events);
        stocastic_events(int range, int N_events, int N_generations);

        void generate_events();
        

    private:

};
