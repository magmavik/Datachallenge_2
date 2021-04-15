#ifndef __events_list_h__
#define __events_list_h__


#include <iostream>   //std::cout
#include <vector>     //std::vector
#include <algorithm>  //std::max_element std::sort
#include <fstream>    //std::ofstream


class events_list{
    public:
        typedef std::vector<double>           double_vec;
        typedef std::vector<double>::const_iterator double_cit;
        typedef std::vector<double>::iterator double_it;
    
    // constructor & destructor
        events_list();
        events_list(double_vec);
        events_list(double list_range, int N_success );

        ~events_list(){};

    // setter and getter

        void set_list_range(double);
        void set_N_succes(const int);
        void set_event_list(double_vec);
        void set_list_element(int pos , double value);

        double     get_list_range() const;
        int        get_N_succes()   const;
        double_vec get_event_list() const;
        double     get_list_element(const int) const;

    //methods and other
        int     size()       const;
        void    print_list() const;
        void    sort_list();
        void    print_distance_csv();
        void    add_gaussian_noise(float sigma);

        // da implementare appena si scopre l'errore
        // double_vec  operator[](int i) const;
        //double_vec& operator[](int i);

    
    
    protected:
        double      _list_range = 0;   // range between events
        int         _N_success  = 0;     // number of success
        double_vec  _list;  // list of success between 0-_list_range
};



#endif