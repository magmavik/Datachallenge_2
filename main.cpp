#include <iostream>
#include "./lib/dataset.h"
#include "./lib/data_cluster.h"

int main()
{
    Dataset data(10000,0,0.2,0);

    //data.print();

    data_cluster clust(data.get_items(),  data.get_length());

    clust.create_histogram();
    


    return 0;
}