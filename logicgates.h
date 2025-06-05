#ifndef LOGICGATES_H
#define LOGICGATES_H

#define INPUT_SIZE 2
#define BATCH_SIZE 4

// Intput set for logic gates
#define GATE_INPUTS {{1.0, 1.0}, {1.0, 0.0}, {0.0, 1.0}, {0.0, 0.0}}

// Output sets for logic gates
#define AND_OUTPUT { 1, 0, 0, 0}
#define NAND_OUTPUT { 0, 1, 1, 1}
#define OR_OUTPUT { 1, 1, 1, 0}
#define NOR_OUTPUT { 0, 0, 0, 1}

#endif
