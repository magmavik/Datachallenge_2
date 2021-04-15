#include "events_list.h"

// ======== constructor =========//
events_list::events_list()
{

}

events_list::events_list(double_vec events_list)
    :_list(events_list), _N_success(events_list.size()),
    _list_range( *std::max_element(events_list.begin(), events_list.end()))
{
    
}

events_list::events_list(double list_range, int N_success )
    : _list_range(list_range),_N_success(N_success)
{
    _list.resize(_N_success);
}

// events_list::~events_list(){

// }

//======================================//
//========= setter & getter ============//

void events_list::set_list_range(const double list_range)
{
    _list_range = list_range;
}
        
void events_list::set_N_succes(const int N_success)
{
    _N_success = N_success;
}

void events_list::set_event_list(double_vec events_list)
{
    _list = events_list;
}

void events_list::set_list_element(int pos , double value)
{
    _list[pos] = value;
}

double events_list::get_list_range() const
{
    return _list_range;
}
int events_list::get_N_succes() const
{
    return _N_success;
}

std::vector<double> events_list::get_event_list() const
{
    return _list;
}

double events_list::get_list_element(const int i) const
{
    return _list[i];
}

//======================================//
//=============  methods  ==============//
int events_list::size() const
{
    return _N_success;
}

void events_list::print_list() const
{
    double_cit it;
    std::cout << "list: \n";
    for( it = _list.begin() ; it != _list.end(); ++it)
    {
        std::cout << " " << *it << " ";
    }
}


void events_list::print_distance_csv() 
{
    std::ofstream of("./../distance_data.csv");
    if(!of.good())
    {
        std::cerr << "ERROR: unable to create csv. Something went wrong.\n";
        return; 
    }
    of << "index,distance\n";

     std::sort(_list.begin(), _list.end());
    double_it it;

    for(it = _list.begin() ; it != (_list.end() - 1) ; ++ it)
    {
        of << std::distance(_list.begin(),it) << "," <<  (*(it + 1) - *it) << "\n";
    }

}


/// non funzia don't know why"
// std::vector<double>& events_list::operator[](int i)
// {
//     if(i > _list.size())
//     {
//         std::cerr << "ERROR: in" <<__FUNCTION__ << std::endl
//                   << "       list overflow";
//     }
//     else return _list.at(i);
// }


// // std::vector<double> events_list::operator[](int i) const
// // {
// //     if(i > _events_list.size())
// //     {
// //         std::cerr << "ERROR: in" <<__FUNCTION__ << std::endl
// //                   << "       list overflow";
// //     }
// //     else return _events_list[i];
// // }











