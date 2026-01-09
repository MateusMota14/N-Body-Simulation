# N-Body Simulation

A high-performance **N-Body Simulation** developed in C++. This project simulates gravitational interactions between multiple celestial bodies in a 2D environment, focusing on numerical stability and real-time visualization.

## Note on usage: When setting the initial conditions it is helpful to set frequency of updates to 0 so that the planets don't move. 

## 🚀 Features

* **Gravitational Physics:** Accurate simulation based on Newton's Law of Universal Gravitation.
* **Numerical Stability:** Implementation of the **Velocity Verlet** integrator for energy conservation.
* **Real-time Rendering:** Smooth visual output using the **SFML** library.
* **Cross-platform:** Build system managed by **CMake** for easy compilation on Windows, Linux, and macOS.

## 🔬 Physics & Integration

The simulation computes the force between bodies using:

$$F = G \frac{m_1 m_2}{r^2}$$

### Velocity Verlet Method
To ensure long-term orbital stability, this project utilizes the **Velocity Verlet** algorithm. Unlike standard Euler integration, this method is symplectic, meaning it better preserves the total energy of the system. This simulation uses the **Stored-Acceleration** variant of the Velocity Verlet algorithm. This approach is mathematically equivalent to the standard form but optimized for systems where force calculation is computationally expensive:

The state of each body is updated in three distinct steps:
1.  **Position Update:** Uses current velocity and acceleration.
2.  **Velocity Update:** Uses the average of current and previous acceleration (Trapezoidal rule).
3.  **Acceleration Storage:** The current acceleration is stored as `lastAcceleration` for use in the next time step.

## 🛠️ Technologies

* **Language:** C++17 or higher
* **Graphics:** [SFML](https://www.sfml-dev.org/)
* **Build System:** [CMake](https://cmake.org/)

## 🔧 Prerequisites

You need the following installed:
* A C++ compiler (GCC, Clang, or MSVC)
* CMake
* SFML Development Libraries

