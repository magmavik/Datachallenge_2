#include "cluster_events.h"
#include "utility_lib.h"
#include <random>

/**
 * constructor. by default sigma of gaussian rumor is set as 
 * range/100 
 */ 
cluster_events::cluster_events(int range, int events, int cluster_number, float cluster_sigma, int generation)
    :events_list(range,events,generation), _cluster_number(cluster_number), _cluster_sigma(cluster_sigma) 
{

}

void cluster_events::generate_events()
{
    _mat.clear();

    // random gauss generator.
    std::default_random_engine generator;
    
    int* cluster_positions;
    std::normal_distribution<double>* cluster_distributions;   // initialize several distributions, one for each cluster

    cluster_positions = new int[_cluster_number];
    cluster_distributions = new std::normal_distribution<double>[_cluster_number];
    for(int gen = 0; gen < _N_generation; gen++)
    {
        _mat[gen].clear();
        for(int i=0; i<_cluster_number; i++)
        {
            cluster_positions[i] = round(rand()/(RAND_MAX+1.0)*_range);
            std::cout << "Cluster position: " << cluster_positions[i] << std::endl;
            cluster_distributions[i] = std::normal_distribution<double>(cluster_positions[i], _cluster_sigma);
        }

        for(int i=0; i<_N_success; i++)
        {
            int appo = round(rand()/(RAND_MAX+1.0)*(_cluster_number-1));
            int insert = 0;
            do
            {
                insert = round(cluster_distributions[appo](generator));
            }while(insert<0 or insert >= _range);
            _mat[gen].push_back(insert);
        }
        std::sort(_mat[gen].begin(), _mat[gen].end());
        for(int i=0; i<_N_success; i++)
        {
            std::cout << _mat[gen][i] << std::endl;
        }
    }
    // delete[] cluster_positions;
    // delete[] cluster_distributions;
}
