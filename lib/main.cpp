#include <iostream>
#include "./lib/dataset.h"
#include "./lib/data_cluster.h"

int main()
{
    Dataset::initialize_seed();
    Dataset data(100,0,0.2,0);


    data_cluster clust(data.get_items(),  data.get_length());

    clust.create_histogram();
    clust.print_distance_csv();
    


    return 0;
}