#include <iostream>
#include <chrono>
#include <ctime>
#include "sortingcompetition.h"

using namespace std;

int main()
{

    string fName = "test2.txt";
    SortingCompetition sc(fName);
    sc.readData();
    std::chrono::duration<double> esectot;
    for(int i=0;i<3;++i)
    {
        sc.prepareData();
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        //sort function goes in here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        sc.sortData();
        //sort function goes in here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        end = std::chrono::system_clock::now();

        //subtract end from beginning to get number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time =
        std::chrono::system_clock::to_time_t(end);
        esectot+=elapsed_seconds;
        //output the duration.
        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds.count() << "s\n";
    }
    esectot/=3;
    cout << esectot.count() << endl;
    sc.outputData("sorted.txt");

    sc.setFileName("test.txt");
    sc.readData();
    std::chrono::duration<double> esectot2;
    for(int i=0;i<3;++i)
    {
        sc.prepareData();
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        //sort function goes in here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        sc.sortData();
        //sort function goes in here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        end = std::chrono::system_clock::now();

        //subtract end from beginning to get number of seconds elapsed
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time =
        std::chrono::system_clock::to_time_t(end);
        esectot2+=elapsed_seconds;
        //output the duration.
        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds.count() << "s\n";
    }
    esectot2/=3;
    cout << esectot2.count() << endl;
    sc.outputData("output2.txt");
}

