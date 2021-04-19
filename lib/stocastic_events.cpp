#include "stocastic_events.h"

stocastic_events::stocastic_events(int range, int events)
    :events_list(range, events)
{
}
stocastic_events::stocastic_events(int range, int events, int N_generations)
    :events_list(range, events, N_generations)
{
}

void stocastic_events::generate_events()
{
    int lower_bound = 0;
    int upper_bound = get_range();

    if(upper_bound - lower_bound <= 0 or _N_success < 0 )
    {
        std::cerr << "ERROR: in " << __FUNCTION__ << "\n"
                  << "       invalid input for range or number of success. \n"
                  << "       Please check\n";
        return;  
    }
    
    std::uniform_real_distribution<float> unif(lower_bound,upper_bound);
    std::default_random_engine re;
    for(int j = 0; j < _N_generation; ++j)
    {
        for(int i = 0; i < _N_success ;++i)
        {
            _mat[j][i] = static_cast<int>( unif(re) );
        }

    }
}