PROJECT
The Orbital Simulator project is an N-body simulation which renders simulated bodies on to the screen.

Libraries used: SFML for graphics, Google Test for unit testing

TODO
- Complete unit tests for Body
- Implement unit tests for BodySystem
- Implement unit tests for utility methods
- Refactor Body (and possibly BodySystem) to separate SFML classes from them

PLANNED FEATURES
- Time controls for speeding up or slowing down the simulation
- Camera controls for zooming and panning
- Classes to utilize the Barnes-Hut algorithm which will allow for larger simulations
- Methods for the simulation to generate larger sets of bodies of different types
- Richer graphics features for the bodies (possibly using a BodySprite class)
- Body orbit/path rendering
- Spacecraft maneuvers/plans, orbital transfers