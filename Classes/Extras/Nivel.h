#ifndef __PUNTO_H__
#define __PUNTO_H__

#include <string>
#include <sstream>

using namespace std;

class Nivel{
    
public:
    double speed;
    int pipes;
    Nivel(double speed = 0.0, int pipes = 0)
    :speed(speed), pipes(pipes)
    {}
    
    std::string toString() {
        std::ostringstream  ss;
        ss << "p(";
        ss << speed;
        ss << ", ";
        ss << pipes;
        ss << ")";
        return(ss.str());
    }
};
#endif
