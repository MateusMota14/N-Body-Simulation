# N-Body Simulation

A high-performance **N-Body Simulation** developed in C++. This project simulates gravitational interactions between multiple celestial bodies in a 2D environment, focusing on numerical stability and real-time visualization.

## 🚀 Features

* **Gravitational Physics:** Accurate simulation based on Newton's Law of Universal Gravitation.
* **Numerical Stability:** Implementation of the **Velocity Verlet** integrator for energy conservation.
* **Real-time Rendering:** Smooth visual output using the **SFML** library.
* **Cross-platform:** Build system managed by **CMake** for easy compilation on Windows, Linux, and macOS.

## 🔬 Physics & Integration

The simulation computes the force between bodies using:

$$F = G \frac{m_1 m_2}{r^2}$$

### Velocity Verlet Method
To ensure long-term orbital stability, this project utilizes the **Velocity Verlet** algorithm. Unlike standard Euler integration, this method is symplectic, meaning it better preserves the total energy of the system.

The state of each body is updated in three distinct steps:
1.  **Update Position:** $$x(t + \Delta t) = x(t) + v(t)\Delta t + \frac{1}{2}a(t)\Delta t^2$$
2.  **Half-step Velocity:** $$v(t + \frac{1}{2}\Delta t) = v(t) + \frac{1}{2}a(t)\Delta t$$
3.  **Full-step Velocity:** (After computing new acceleration $a(t + \Delta t)$):
    $$v(t + \Delta t) = v(t + \frac{1}{2}\Delta t) + \frac{1}{2}a(t + \Delta t)\Delta t$$

## 🛠️ Technologies

* **Language:** C++17 or higher
* **Graphics:** [SFML](https://www.sfml-dev.org/)
* **Build System:** [CMake](https://cmake.org/)

## 🔧 Prerequisites

You need the following installed:
* A C++ compiler (GCC, Clang, or MSVC)
* CMake (3.10+)
* SFML Development Libraries

## 🔨 Build and Installation

1.  **Clone the repository**
    ```bash
    git clone [https://github.com/your-username/n-body-simulation.git](https://github.com/your-username/n-body-simulation.git)
    cd n-body-simulation
    ```

2.  **Generate build files and compile**
    ```bash
    mkdir build && cd build
    cmake ..
    cmake --build .
    ```

3.  **Run the executable**
    ```bash
    ./n_body_simulation
    ```

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
