#ifndef __events_list_h__
#define __events_list_h__


#include <iostream>   //std::cout
#include <vector>     //std::vector
#include <algorithm>  //std::max_element std::sort
#include <fstream>    //std::ofstream
#include <string.h>   //string

class events_list{
    public:
        typedef std::vector<int>                 int_vec;
        typedef std::vector<int>::const_iterator int_cit;
        typedef std::vector<int>::iterator       int_it;
        typedef std::vector<std::vector<int>>    int_mat;    
        typedef std::vector<std::vector<int>>::iterator int_point_it; 
    
    // constructor & destructor
        events_list();
        events_list(int_vec);
        events_list(int list_range, int N_success );
        events_list(int list_range, int N_success, int N_generation);

        ~events_list(){};

    // setter and getter

        void set_range(int);
        void set_N_succes(const int);
        void set_event_list(int_vec);
        void set_list_element(int pos , int value);
        void set_mat_element(int pos, int generation, int value);

        int     get_range() const;
        int        get_N_succes()   const;
        int_vec get_event_list(int generation) const;
        int     get_element(const int) const;
        int     get_element(const int, const int generation) const;

    //methods and other
        int     size()       const;
        void    print_list() const;
        void    print_list(int generation) const;
        void    sort_list();
        void    print_distance_csv() ;
        void    print_distance_csv(const std::string name_file) ;
        void    print_csv(const std::string name_file); 
        //void    add_gaussian_noise(float sigma);

        // da implementare appena si scopre l'errore
        // int_vec  operator[](int i) const;
        //int_vec& operator[](int i);

    
    
    protected:
        int         _range = 0;   // range between events
        int         _N_success  = 0;     // number of success
        int         _N_generation = 0;
        //int_vec  _list;  // list of success between 0-_range
        int_mat _mat;
};



#endif