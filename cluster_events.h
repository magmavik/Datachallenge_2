#include <iostream> 

#include "events_list.h"
#include "math.h"

/**
 * The class generate a series of events wich interact repulsively
*/
class cluster_events : public events_list
{
    public:

        cluster_events(int range, int events, int cluster_number, float cluster_sigma, int generation);
        
    // methods 
        void generate_events();

    private:
        double _sigma;
        double _cluster_sigma;
        int _cluster_number;
        int _force;

};