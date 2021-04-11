#include <iostream>     // std::cout;
#include <vector>       // std::vector
#include <algorithm>    // std::sort
#include <fstream>


class data_cluster
{
    public:
        const static int N_step = 7;
        // constructor
        data_cluster(std::vector<bool> data, int data_length );
        ~data_cluster();

        /**
         * create a vector of distane between point in input vector 
         */
        void calc_distance_distribution();  // calulate distance bertween elements

        /**
         * format data as histogram column  
         */
        void create_histogram();

        /**
         * Create or update a csv file with data organized as histogram 
         */
        void print_distance_csv();   



    private:
        std::vector<int>   _dist;
        std::vector<bool>  _vec;
        std::vector<int>   _hist;
        
        int _len;
        float _data_step;

        bool ERROR = false;

};