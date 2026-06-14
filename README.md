# University-Course-Registration-System (Turing Machine)

 Overview

This project demonstrates the application of Turing Machine (TM) theory to a real-world problem: university course registration. It models the entire registration workflow using a formal computational approach and implements it in C.

The system simulates validation steps such as prerequisite checking, credit limits, and course selection using TM state transitions.

 Features
Formal Turing Machine model for course registration
State-based validation (each state = workflow step)
Credit hour verification
Prerequisite checking
Retry mechanism for invalid selections
Fully implemented in C

Concept

Traditional automata like Finite Automata and Pushdown Automata are insufficient for this problem due to:

Arbitrary credit calculations
Complex prerequisite chains
Conditional logic and retries

A Turing Machine is used because of its:

Unlimited memory (tape)
Read/write capability
Ability to simulate complex computations

Implementation

The system is implemented in C, where:

Each TM state corresponds to a logical validation step
Transitions represent decision-making processes
Tape simulates input and intermediate computation

Example Workflow
User selects courses
System checks prerequisites
Validates total credit hours
Accepts or rejects registration
Allows retry if constraints fail
                                                                                                                                                        
Learning Outcomes
Practical application of Theory of Computation
Understanding of Turing Machine design
Mapping theoretical models to real-world systems
