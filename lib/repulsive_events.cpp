#include "repulsive_events.h"
#include "utility_lib.h"

/**
 * constructor. by default sigma of gaussian rumor is set as 
 * range/100 
 */ 
repulsive_events::repulsive_events(double range, int events, double sigma)
    :events_list(range,events), _sigma(sigma)
{
}

// repulsive_events::repulsive_events(double range, int events, double force, double sigma)
//     :events_list(range,events), _force(force), _sigma(sigma)
// {

// }

void repulsive_events::generate_events()
{
    double d_data_min = 0;
    double d_data_max = _list_range; 

    double d_step = static_cast<double>(_list_range/ _N_success);

    std::cout << d_step; 

    if(d_data_max - d_data_min <= 0 or _N_success < 0 or _sigma < 0)
    {
        std::cerr << "ERROR: in " << __FUNCTION__ << "\n"
                  << "       invalid input for range or number of success. \n"
                  << "       Please check\n";
        return;  

    }

    _list[0] = 0;
    for(int i = 1; i < _N_success; i ++)
    {
        _list[i] =  i * d_step +  add_gaussian_noise(_sigma);
    }

}


    // double _data_min = 0;
    // double _data_max = get_list_range();
    // int    N_success = get_N_succes();

    // if(_data_max - _data_min <= 0 or N_success < 0 or _sigma < 0)
    // {
    //     std::cerr << "ERROR: in " << __FUNCTION__ << "\n"
    //               << "       invalid input for range or number of success. \n"
    //               << "       Please check\n";
    //     return;  

    // }

    // double _median_step = static_cast<double>(_data_max - _data_min)/N_success;

    // double _steps[N_success];   // array with steps, without the step from last element to end of range

    // // filling randomly _list and creating steps array
    // for(int i = 0; i < N_success; i++)
    // {
    //     _list[i] = rand()/(RAND_MAX+1.0) * (_data_max - _data_min);
    // }

    // sort_list();

    // _steps[0] = _list[0];
    // for(int i=1; i < N_success; i++)
    // {
    //     _steps[i] = _list[i] - _list[i-1];
    // }
    
    // // making the steps in steps array evolve
    // int t_max = 100;
    // for(int t=0; t<=t_max; t++)
    // {
    //     for(int i=0; i<N_success; i++)
    //     {
    //         double force_norm = static_cast<double>(1./(_list_range* 10));
    //         _steps[i] += 0.001*_force*sgn(_median_step - _steps[i]);
    //     }

    // }

    // // creating final list from evolved steps
    // double appo=0;
    // for(int i=0; i<N_success; i++)
    // {
    //     appo += _steps[i];
    //     _list[i] = appo;
    // }