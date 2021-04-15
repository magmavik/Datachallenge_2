#include <random>

#include "events_list.h"
#include "iostream"

class stocastic_events : public events_list
{
    public:
        stocastic_events(double range,int events);

        void generate_events();
        

    private:

};
