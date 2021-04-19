#include "cluster_events.h"
#include "utility_lib.h"
#include <random>

/**
 * constructor. by default sigma of gaussian rumor is set as 
 * range/100 
 */ 
cluster_events::cluster_events(double range, int events, int cluster_number, float cluster_sigma)
    :events_list(range,events), _cluster_number(cluster_number), _cluster_sigma(cluster_sigma)
{

}

void cluster_events::generate_events()
{
    _list.clear();

    // random gauss generator.
    std::default_random_engine generator;
    
    int* _cluster_positions;
    std::normal_distribution<double>* _cluster_distributions;   // initialize several distributions, one for each cluster

    _cluster_positions = new int[_cluster_number];
    _cluster_distributions = new std::normal_distribution<double>[_cluster_number];
    for(int i=0; i<_cluster_number; i++)
    {
        _cluster_positions[i] = round(rand()/(RAND_MAX+1.0)*_list_range);
        _cluster_distributions[i] = std::normal_distribution<double>(_cluster_positions[i], _cluster_sigma);
        std::cout << _cluster_positions[i] << std::endl;
    }

    for(int i=0; i<_N_success; i++)
    {
        int appo = round(rand()/(RAND_MAX+1.0)*(_cluster_number-1));
        int insert = 0;
        do
        {
        insert = round(_cluster_distributions[appo](generator));
        }while(insert<0 or insert >= _list_range or std::find(_list.begin(), _list.end(), insert) != _list.end());
        _list.push_back(insert);
    }

    sort_list();

    delete[] _cluster_positions;
    delete[] _cluster_distributions;
}

