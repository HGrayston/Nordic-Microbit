#include "ppi.h"

PPI->PPI_CH[0].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);

PPI->PPI_CH[0].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[1]);