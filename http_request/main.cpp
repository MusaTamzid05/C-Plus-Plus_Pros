#include "download.h"

int main(int argc , char** argv){

    download("http://ctabustracker.com/bustime/map/getBusesForRoute.jsp?route=22" , "data.xml");
    return 0;
}
