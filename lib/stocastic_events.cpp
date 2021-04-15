#include "stocastic_events.h"

stocastic_events::stocastic_events(double range, int events)
    :events_list(range, events)
{
}

void stocastic_events::generate_events()
{
    double lower_bound = 0;
    double upper_bound = get_list_range();
    int N_success      = get_N_succes();

    if(upper_bound - lower_bound <= 0 or N_success < 0 )
    {
        std::cerr << "ERROR: in " << __FUNCTION__ << "\n"
                  << "       invalid input for range or number of success. \n"
                  << "       Please check\n";
        return;  
    }
    
    std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
    std::default_random_engine re;
    
    for(int i = 0; i < N_success ;++i)
    {
        double rand_val = unif(re);
        set_list_element(i,rand_val);
    }
}