#include <iostream>
#include <stdlib.h>
#include "./lib/stocastic_events.h"
#include "./lib/repulsive_events.h"
#include "./lib/cluster_events.h"

//this program generate an array of events between 0 and range. 



int main(int argc, char **argv)
{
    int range           = 100000;
    int max_success     = 5000; 
    int min_success     = 4990;
    int N_generations   = 5;
    int N_cluster       = 5;
    float cluster_sigma = static_cast<double>(range/ max_success   * 2);
    double sigma        = static_cast<double>(range/ (max_success  * 2) );

    std::string PATH  = "./data/"; 

    if( argc < 1)
    {
        std::cerr << " ERROR: please specify the type of events series \n";
        return -1;
    }
    
    if( !strcmp(argv[1], "-r") )
    std::cout << "repuslive series selected \n";
    {
        if(argc < 5)
        {
            std::cout << "ISSUE: less input values then expected. Digit -h for input help.\n";   
        }
        else
        {
            range = atoi(argv[2]);  max_success = atoi(argv[3]);sigma = atof(argv[4]);  N_generations = atoi(argv[5]);
            if(N_generations > 100 or max_success > range)
            {
                std::cerr << "ERROR: wrong input plese retry\n";
                return -1; 
            }

        }
        repulsive_events events(range,max_success,sigma,N_generations);

        min_success = max_success; // può essere utile averlo. nel casocommenta
        for(int i = min_success; i <= max_success ; ++i)//il min success è opzionale e modificabile solo nel codice
        {
            std::string nameFile = PATH + "data_" 
                                   + std::to_string(i) + ".csv";
            events.set_N_succes(i);
            events.generate_events();
            events.sort_list();
            events.print_distance_csv(nameFile);
        }        
    }


    if ( !strcmp(argv[1], "-s") )
    {   
        std::cout << "stocastic series selected \n";
        if(argc < 3)
        {
            std::cout << "ISSUE: less input values then expected. Digit -h for input help.\n";
        }
        else
        {
            range = atoi(argv[2]);  max_success = atoi(argv[3]);  N_generations = atoi(argv[4]);
            if(N_generations > 100 or max_success > range)
            {
                std::cerr << "ERROR: wrong input plese retry\n";
                return -1; 
            }
        }
        stocastic_events events(range,max_success,N_generations);
        min_success = max_success; // può essere utile averlo. nel casocommenta
        for(int i = min_success; i <= max_success ; ++i)//il min success è opzionale e modificabile solo nel codice
        {
            std::string nameFile = PATH + "data_" 
                                   + std::to_string(i) + ".csv";
            events.set_N_succes(i);
            events.generate_events();
            events.sort_list();
            events.print_distance_csv(nameFile);
        
        }
    }

    if ( !strcmp(argv[1], "-c"))
    {
        std::cout << " clusterized series selected\n";
        if(argc < 6)
        {
            std::cout << "ISSUE: less input value than axpected. Digit -h for input help.\n";
        }
        else
        {
            range = atoi(argv[2]);  max_success = atoi(argv[3]); N_cluster = atoi(argv[4]);
            cluster_sigma = atof(argv[5]); N_generations = atoi(argv[6]);
            if(N_generations > 100 or max_success > range)
            {
                std::cerr << "ERROR: wrong input plese retry\n";
                return -1; 
            }
        }

        cluster_events events(range,max_success,N_cluster, cluster_sigma, N_generations);
        min_success = max_success; // può essere utile averlo. nel casocommenta
        for(int i = min_success; i <= max_success ; ++i)//il min success è opzionale e modificabile solo nel codice
        {
            std::string nameFile = PATH + "data_" 
                                    + std::to_string(i) + ".csv";
            events.set_N_succes(i);
            events.generate_events();
            events.sort_list();
            events.print_distance_csv(nameFile);
        
        }    
    }

    if( !strcmp(argv[1], "-h") or !strcmp(argv[1], "-help"))
    {
        std::cout << "USAGE:\n" 
                  << "       * stocastic:\n"
                  << "         ./main.x -s int(range) int(success) int(N_generations) \n\n"
                  << "       * repulsive:\n"
                  << "         ./main.x -s int(range) int(success) double(sigma) int(N_generations)\n\n"
                  << "       * clusterized:"
                  << "         ./main.x int(range) int(events) int(cluster_number) float(cluster_sigma) int(generation)\n";
    }
    return 0;
}











