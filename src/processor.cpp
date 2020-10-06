#include "processor.h"
#include "linux_parser.h"
#include <vector>
#include <string>
using std::stof;
using std::string;
using std::vector;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
    vector<string> cpu_usage = LinuxParser::CpuUtilization();
    float Idle, NonIdle, Total, totald, idled;
    //float usertime = stof(cpu_usage(LinuxParser::kUser_)) - stof(cpu_usage(LinuxParser::kGuest_));
    //float nicetime = stof(cpu_usage(LinuxParser::kNice_)) - stof(cpu_usage(LinuxParser::kGuestNice));
    Idle = stof(cpu_usage[LinuxParser::kIdle_]) + stof(cpu_usage[LinuxParser::kIOwait_]);
    NonIdle = stof(cpu_usage[LinuxParser::kUser_]) + stof(cpu_usage[LinuxParser::kNice_]) + 
            stof(cpu_usage[LinuxParser::kSystem_]) + stof(cpu_usage[LinuxParser::kIRQ_]) + 
            stof(cpu_usage[LinuxParser::kSoftIRQ_]) + stof(cpu_usage[LinuxParser::kSteal_]); 
    Total = Idle + NonIdle;

    totald = Total - PrevTotal;
    idled = Idle - PrevIdle;

    PrevNonIdle = NonIdle;
    PrevIdle = Idle;
    PrevTotal = PrevIdle + PrevNonIdle;

    return (totald - idled)/totald; 
}