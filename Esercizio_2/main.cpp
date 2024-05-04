#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include "SortingAlgorithm.hpp"


using namespace std;
using namespace SortLibrary;


int main(int argc, char *argv[])
{
    double mean_Merge = 0;
    double mean_Bubble = 0;

    for(unsigned int i=1; i<argc; i++)
    {
        int n = stoi(argv[i]);
        vector<double> vMerge(n);
        vector<double> vBubble(n);

        srand(time(NULL));

        for(unsigned int i = 0; i<n; i++)
        {
            vMerge[i] = rand()%1000;
            vBubble[i] = rand()%1000;
        }


        std::chrono::steady_clock::time_point t_begin_Merge = std::chrono::steady_clock::now();
        MergeSort(vMerge);
        std::chrono::steady_clock::time_point t_end_Merge = std::chrono::steady_clock::now();

        double duration_Merge = std::chrono::duration_cast<std::chrono::microseconds>(t_end_Merge - t_begin_Merge).count();

        mean_Merge += duration_Merge;

        std::chrono::steady_clock::time_point t_begin_Bubble = std::chrono::steady_clock::now();
        BubbleSort(vBubble);
        std::chrono::steady_clock::time_point t_end_Bubble = std::chrono::steady_clock::now();

        double duration_Bubble = std::chrono::duration_cast<std::chrono::microseconds>(t_end_Bubble - t_begin_Bubble).count();

        mean_Bubble += duration_Bubble;


        cout << "Size of vector " << i << ": " << n << endl;
        cout << "Merge sort finished in " << duration_Merge << " microseconds" << endl;
        cout << "Bubble sort finished in " << duration_Bubble << " microseconds" << endl;
        cout << endl;
    }

    mean_Merge = mean_Merge/(argc-1);
    mean_Bubble = mean_Bubble/(argc-1);

    cout << "Average time of MergeSort: " << mean_Merge << endl;
    cout << "Average time of BubbleSort: " << mean_Bubble << endl;


    return 0;
}

