#include "time.h"


namespace Helper{

    Time::Time(){

    }

    int Time::now(){
        return std::time(nullptr);
    }



};
