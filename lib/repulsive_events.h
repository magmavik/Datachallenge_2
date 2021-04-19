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

        repulsive_events(int range, int success, double sigma);
        repulsive_events(int range, int success, double sigma, int generations);
        //repulsive_events(intrange, int events, intforce, intsigma);
        //repulsive_events(intrange, int events, intbake_time); //To be implemented... maybe
        
    // methods 
        void generate_events();

    private:
        double _sigma;

};