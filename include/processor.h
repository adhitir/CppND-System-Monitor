#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
    float PrevIdle{0.0}, PrevNonIdle{0.0}, PrevTotal{0.0};

};

#endif