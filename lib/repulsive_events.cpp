#include "repulsive_events.h"

/**
 * constructor. by default sigma of gaussian rumor is set as 
 * range/100 
 */ 
repulsive_events::repulsive_events(double range, int events)
    :events_list(range,events)
{
    _sigma = range/100;
}

repulsive_events::repulsive_events(double range, int events, double sigma)
    :events_list(range,events) , _sigma(sigma)
{

}

void repulsive_events::generate_events()
{
    double _data_min = 0;
    double _data_max = get_list_range();
    int    N_success = get_N_succes();

    if(_data_max - _data_min <= 0 or N_success < 0 or _sigma < 0)
    {
        std::cerr << "ERROR: in " << __FUNCTION__ << "\n"
                  << "       invalid input for range or number of success. \n"
                  << "       Please check\n";
        return;  

    }

    double _step = static_cast<double>(_data_max - _data_min)/N_success;

    for(int i = 0; i < N_success; i++)
    {}




}

