#include "simulation.h"

int main(int argc, char* argv[]) {
  Simulation simulation;

  // Simulation is a singleton.
  simulation.initialize(argc, argv);
  // The Game Loop.
  while (not simulation.is_over()) {
    simulation.process_events();
    simulation.update();
    simulation.render();
  }
  return 0;
}