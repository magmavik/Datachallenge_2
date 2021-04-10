#include <iostream>     // std::cout;
#include <vector>       // std::vector
#include <algorithm>    // std::sort


class data_cluster
{
    public:
        const int N_step = 20;
        // constructor
        data_cluster(std::vector<bool>, int );
        ~data_cluster();

        // methods
        void calc_distance_distribution();  // calulate distance bertween elements
        void print_distance_histogram();    // format and print dist as histogram


    private:
        std::vector<int>   _dist;
        std::vector<bool>  _vec;
        std::vector<int>   _hist;
        int _len;

        bool ERROR = false;

};