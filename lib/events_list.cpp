#include "events_list.h"
#include <random>

// ======== constructor =========//
events_list::events_list()
{

}

// events_list::events_list(int_vec events_list)
//     :_mat[0](events_list), _N_success(events_list.size()),
//     _list_range( *std::max_element(events_list.begin(), events_list.end()))
// {
//     _N_generation = 1;
// }

events_list::events_list(int list_range, int N_success )
    : _list_range(list_range),_N_success(N_success)
{
    _mat[0].resize(_N_success);
    _N_generation = 1;
}

events_list::events_list(int list_range, int N_success, int N_generation)
    : _list_range(list_range), _N_success(N_success), _N_generation(N_generation)
{
    int_point_it it;
    _mat.resize( _N_generation);
    for(it = _mat.begin(); it != _mat.end(); ++it )
    {
        it -> resize(_N_success);
    }
}

// events_list::~events_list(){

// }

//======================================//
//========= setter & getter ============//

void events_list::set_list_range(const int list_range)
{
    _list_range = list_range;
}
        
void events_list::set_N_succes(const int N_success)
{
    _N_success = N_success;
}

// void events_list::set_event_list(int_vec events_list)
// {
//     _list = events_list;
// }

void events_list::set_list_element(int pos , int value)
{
    _mat[0][pos] = value;
}

void events_list::set_mat_element(int pos, int generation, int value)
{
    _mat[generation][pos] = value;
}

int events_list::get_list_range() const
{
    return _list_range;
}
int events_list::get_N_succes() const
{
    return _N_success;
}

std::vector<int> events_list::get_event_list(int generation) const
{
    return _mat[generation];
}

int events_list::get_element(const int i, const int generation) const
{
    return _mat[generation][i];
}

int events_list::get_element(const int i) const
{
    return _mat[0][i];
}

//======================================//
//=============  methods  ==============//
int events_list::size() const
{
    return _N_success;
}

void events_list::print_list() const
{
    int_cit it;
    std::cout << std::endl << "list: \n";
    for( it = _mat[0].begin() ; it != _mat[0].end(); ++it)
    {
        std::cout << " " << *it << " ";
    }
    std::cout << std::endl;
}

void events_list::print_list( int generation) const
{
    int_cit it;
    std::cout << std::endl << "list: \n";
    for( it = _mat[generation].begin() ; it != _mat[generation].end();
         ++it)
    {
        std::cout << " " << *it << " ";
    }
    std::cout << std::endl;
}

void events_list::sort_list()
{
    int_point_it it;
    for(it = _mat.begin() ; it != _mat.end() ; ++it)
    {
        std::sort( it->begin() , it -> begin() + _N_success);
    }
}

// void events_list::print_distance_csv() 
// {
//     std::ofstream of("./../distance_data.csv");
//     if(!of.good())
//     {
//         std::cerr << "ERROR: unable to create csv. Something went wrong.\n";
//         return; 
//     }
//     of << "index,distance\n";

//     std::sort(_list.begin(), _list.end());
//     int_it it;

//     for(it = _list.begin() ; it != (_list.end() - 1) ; ++ it)
//     {
//         of << std::distance(_list.begin(),it) << "," <<  (*(it + 1) - *it) << "\n";
//     }

// }

void events_list::print_distance_csv(const std::string name_file) 
{
    std::string PATH = "./";
    std::ofstream of(PATH + name_file);
    if(!of.good())
    {
        std::cerr << "ERROR: unable to create csv. Something went wrong.\n";
        return; 
    }
    for( int i = 0; i < _N_generation; i++ )
    {
        of << "d_generation_" << i << ",";
    }
    of << "\n";

    sort_list();

    for( int i = 0; i < _N_success - 1; ++i )
    {
        for(int j = 0; j < _N_generation; ++j)
        {
            int dist = static_cast<int>
                          (_mat[j][i + 1] - _mat[j][i] );
            of << dist << ",";
        }
        of << "\n";
    }

}

void events_list::print_csv(const std::string name_file) 
{
    std::string PATH = "./";
    std::ofstream of( name_file );
    if(!of.good())
    {
        std::cerr << "ERROR: unable to create csv. Something went wrong.\n";
        return; 
    }
    for( int i = 0; i < _N_generation; i++ )
    {
        of << "generation_" << i << ",";
    }
    of << "\n";

    int_it it;

    for( int j = 0; j < _N_success; j++)
    {
        for(int i = 0; i < _N_generation; i++)
        {
            of << _mat[i][j] << ","; 
        }
        of << "\n";
    }

}

// void events_list::add_gaussian_noise(float sigma)
// {
//     std::default_random_engine generator;
//     std::normal_distribution<int> dist(0.0, sigma);

//     for(int i=0; i<_list.size(); i++)
//     {
//         _list[i] += dist(generator);
//     }
// }




/// non funzia don't know why"
// std::vector<int>& events_list::operator[](int i)
// {
//     if(i > _list.size())
//     {
//         std::cerr << "ERROR: in" <<__FUNCTION__ << std::endl
//                   << "       list overflow";
//     }
//     else return _list.at(i);
// }


// // std::vector<int> events_list::operator[](int i) const
// // {
// //     if(i > _events_list.size())
// //     {
// //         std::cerr << "ERROR: in" <<__FUNCTION__ << std::endl
// //                   << "       list overflow";
// //     }
// //     else return _events_list[i];
// // }










