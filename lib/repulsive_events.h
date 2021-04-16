#include <iostream> 

#include "events_list.h"
#include "math.h"
#include "utility_lib.h"

/**
 * The class generate a series of events wich interact repulsively
*/
class repulsive_events : public events_list
{
    public:

        repulsive_events(double range, int events, double sigma);
        //repulsive_events(double range, int events, double force, double sigma);
        //repulsive_events(double range, int events, double bake_time); //To be implemented... maybe
        
    // methods 
        void generate_events();

    private:
        double _sigma;
        double _force;

};