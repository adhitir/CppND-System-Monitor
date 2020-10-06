#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 

    int hours = (int)(seconds/3600);
    int minutes = (int) ((seconds - (float)hours*3600)/60);
    int secs = (int) (seconds - (float)hours*3600 - (float)minutes*60);

    return std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(secs); 
    
}