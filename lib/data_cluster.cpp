#include "data_cluster.h"

data_cluster::data_cluster(std::vector<bool> vec , int len )
    :_vec(vec), _len(len)
{
    calc_distance_distribution();
}

data_cluster::~data_cluster() {}


void data_cluster::calc_distance_distribution()
{
    if(_vec.size() < N_step)
    {
        std::cerr << "ERROR: in __FUNCTION__ input array too small \n";
        ERROR = true;
        return;
    }

    if(_vec.size() < 10 * N_step)
    {
        std::cerr <<"Input vector is small. The result may be affected\n";
    }

    std::cout <<" provettina\n";


    for(int  i = 0; i < _len ; i++)
    {
        if(_vec[i] == false) break;
        else 
        {
            for (int j = i ; j < _len ; j++  )
            {
                if(_vec[j] == false) break;
                else 
                {
                    _dist.push_back(j - i);    
                }
            }
        }
    }
}


void data_cluster::print_distance_histogram()
{
    if(_dist.size() == 0) // check if _dist vector is calculated
    {
        std::cerr << " ERROR: in " <<__FUNCTION__ <<"   distance ditribution is empty.\n";
        return;
    }

    if (ERROR) return; // check if input vector is corripted

    std::sort(_dist.begin(),_dist.end()); //sort vector
    int max = *_dist.end();

    float step = max/N_step;

    int hist[N_step];
    int k = 0;
    for( int i = 0; i < N_step; i++ )
    {
        hist[i] = 0;
        for(k ; k < _dist.size(); k++)
        {
            if(_dist[k] <= i * step)
            {
                hist[i] += 1;
                if( _dist[k + 1] != _dist.size() && _dist[k + 1] > i * step )
                {
                    break;
                }
            }
        }
    }

    for(int i = 0; i < N_step; i++)
    {
        std::cout << "from " << i * step << "to " << (i+1)*step 
                  << ":" << hist[i] << std::endl; 
    }
}


