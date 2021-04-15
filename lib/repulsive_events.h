#include <iostream> 

#include "events_list.h"
#include "math.h"

/**
 * The class generate a series of events wich interact repulsively
*/
class repulsive_events : public events_list
{
    public:

        repulsive_events(double range,int events);
        repulsive_events(double range, int events, double bake_time);
        
    // methods 
        void generate_events();

    private:
        double _sigma;

};