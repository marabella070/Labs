# Laboratory work: A class for working with time

## Task

This laboratory work implements a class for working with time. The class includes:

- Overloaded constructors:

  - The default constructor.

  - Constructor with parameters.

  - Copy constructor.
  
- Dynamic memory allocation for storing reminders.

- A destructor to free up memory.

- A set of methods for working with class data:

  - Changing values (hours, minutes, seconds).

  - Output of values.

  - Addition of two objects of the class.

## Project structure

The project consists of the following files:

- `time.h` is the header file with the definition of the `Time` class.

- `time.cpp` is the implementation of methods of the `Time` class.

- `main.cpp` is a demo program showing the use of the `Time` class.

## Installation

1. Clone the repository to your computer:

   ```bash
   git clone https://github.com/marabella070/Labs/tree/main/ThirdSemestr/First
   ```

2. Go to the build directory and create a folder to generate the solution:

    ```bash
    cd build
    mkdir Solution
    ```

3. Run CMake to generate a Makefile:

    ```bash
    cmake ../../
    ```

4. Build a project using Make:

    ```bash
    cmake --build .
    ```

5. Run the compiled program:

    ```bash
    solution
    ```

## Usage

When you start the program, you will be able to enter hours, minutes, seconds and reminders. The program will also demonstrate the operation of an overloaded addition operator for objects of the Timer class.