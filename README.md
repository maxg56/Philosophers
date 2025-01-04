# Philosophers Project

This README provides an overview of the "Philosophers" project, part of the 42 school curriculum. The project explores the concepts of multithreading and synchronization, using the classic "Dining Philosophers" problem as its basis.

---

## Table of Contents

1. [Introduction](#introduction)
2. [How to Use](#how-to-use)
3. [Program Logic](#program-logic)
4. [Compiling and Running](#compiling-and-running)
5. [Key Constraints](#key-constraints)
6. [Error Handling](#error-handling)
7. [Learning Objectives](#learning-objectives)
8. [Author](#author)

---

## Introduction

The "Dining Philosophers" problem is a synchronization problem involving a group of philosophers sitting around a table, alternating between thinking and eating. Each philosopher requires two forks to eat, but adjacent philosophers share a fork, leading to potential conflicts and deadlocks.

This project implements a solution to the problem using multithreading and mutexes in C, ensuring the following:
- Avoidance of deadlocks.
- Accurate simulation of the philosophers' behavior.
- Efficient resource usage.

---

## How to Use

The program simulates the philosophers' behavior given a set of parameters:

```bash
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

### Parameters
1. **number_of_philosophers**: Number of philosophers and forks.
2. **time_to_die** (in milliseconds): Maximum time a philosopher can go without eating.
3. **time_to_eat** (in milliseconds): Time a philosopher spends eating.
4. **time_to_sleep** (in milliseconds): Time a philosopher spends sleeping.
5. **number_of_times_each_philosopher_must_eat** (optional): The simulation stops once all philosophers eat this many times. If omitted, the simulation runs indefinitely.

### Example
```bash
./philosophers 5 800 200 200 7
```
This simulates 5 philosophers with the following rules:
- A philosopher dies if they don't eat within 800 ms.
- Each philosopher spends 200 ms eating and 200 ms sleeping.
- The simulation stops after each philosopher eats 7 times.

---

## Program Logic

1. Each philosopher is represented by a thread.
2. Forks are represented by mutexes to ensure exclusive access.
3. The program handles the following scenarios:
   - Prevents deadlocks by ensuring no circular waiting occurs.
   - Tracks the state of each philosopher (thinking, eating, sleeping).
   - Stops the simulation if any philosopher dies or when the optional eating condition is met.
4. Time calculations are handled precisely using `gettimeofday` or a similar function.

---

## Compiling and Running

1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd philosophers
   ```
2. Compile the project:
   ```bash
   make
   ```
   This generates the `philosophers` executable.
3. Run the program with the desired arguments (see [How to Use](#how-to-use)).

---

## Key Constraints

- Each philosopher must take exactly two forks to eat.
- Philosophers cannot pick up forks simultaneously.
- The program must use pthreads and mutexes for synchronization.
- Avoid busy waiting. Proper use of sleeping mechanisms is mandatory to reduce CPU usage.

---

## Error Handling

The program ensures robust error handling:
- **Invalid Input**: Displays an error message and exits if parameters are missing, invalid, or out of range.
- **Runtime Errors**: Handles thread creation, mutex initialization, and synchronization issues gracefully.

---

## Learning Objectives

Through this project, you will:
- Understand and implement multithreading concepts.
- Learn to use mutexes for resource synchronization.
- Explore deadlock prevention strategies.
- Develop precise timing mechanisms for real-time systems.

---

## Author

This project was implemented as part of the 42 school curriculum by Maxence Gendrot. For any questions or feedback, feel free to reach out!

