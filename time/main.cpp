#include "time.h"
#include <stdlib.h>

#include <iostream>


int main(int argc , char** argv){

    int delay;

    if(argc == 1){
        std::cerr << "Usage:delay time.\n";
        exit(1);
    }

    delay = atoi(argv[1]);
    Helper::Time time;


    int start_time = time.now();

    std::cout << "Will turn of " <<  delay << " seconds leter.\n";

    int last_checked_time = 0;

    while(time.now() - start_time < delay ){

        if(last_checked_time != time.now() - start_time  ){
            
            last_checked_time = time.now() - start_time ;
            std::cout << last_checked_time << " seconds pass.\n";
        }
    }

    std::cout << "shutting down.\n";
    return 0;

}
