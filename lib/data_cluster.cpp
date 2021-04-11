#include "data_cluster.h"

//        constructor         //

data_cluster::data_cluster(std::vector<bool> vec , int len )
    :_vec(vec), _len(len)
{
    calc_distance_distribution();
}

data_cluster::~data_cluster() {}

//____________________________________________________________________


//          methods          //

void data_cluster::calc_distance_distribution()
{
    if(_vec.size() < N_step)
    {
        std::cerr << "ERROR: in function: \" " << __FUNCTION__ << " \" input array too small \n";
        ERROR = true;
        return;
    }

    if(_vec.size() < 10 * N_step)
    {
        std::cerr <<"Input vector is small. The result may be affected\n";
    }


    std::vector<bool>::const_iterator it , it_marker;
    it_marker = _vec.begin();
    
    for(it = _vec.begin(); it != _vec.end() ; ++it)
    {
        if(*it == false) ;
        else
        {
            _dist.push_back(std::distance(it_marker,it));
            it_marker = it;
        } 
    }
    _dist.erase(_dist.begin());
}


void data_cluster::create_histogram()
{
    if(_dist.size() == 0) // check if _dist vector is calculated
    {
        std::cerr << " ERROR: in function: \" " << __FUNCTION__ << " \" distance ditribution is empty.\n";
        return;
    }

    if (ERROR) return; // check if input vector is corrupted

    
    std::sort(_dist.begin(),_dist.end()); //sort vector

    int max = *_dist.end();

    data_cluster::_data_step = static_cast<float>(max)/static_cast<float>(N_step);

    int k = 0;
    _hist.resize(N_step);

    std::vector<int>::iterator it;
    for( it = _hist.begin(); it != _hist.end(); ++it )
    {
        *it = 0;
        int i = std::distance(_hist.begin(), it);
        for(k ; k < _dist.size(); k++)
        {
            if(_dist[k] <= (i + 1)* _data_step)
            {

                *it += 1;
            }
            else
            {
                k--;
                break;
            }
        }
    }

    for(int i = 0; i < N_step; i++)
    {
        std::cout << "from " << static_cast<float>(i * _data_step) << " to " 
                             << static_cast<float>((i+1)*_data_step) 
                             << ":" << _hist[i] << std::endl; 
    }
}


void data_cluster::print_distance_csv()
{
    std::ofstream of("./histogram.csv");
    of << "index,min,max,element\n";
    for( auto it = _hist.begin(); it != _hist.end(); ++it )
    {
        int i = std::distance(_hist.begin(),it);
        of << i                 << ","
           << (i * _data_step)  << ","
           << ((i+1)*_data_step)<< ","
           << *it               << "\n";
    }



}