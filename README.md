# Very-large-Prime-Number-Calculation

Project Overview

This project generates a random 1024-bit number, stores it in a linked list, and performs a simplified Miller-Rabin primality test to determine whether the number is prime.

Approach

1. Generate a random 1024-bit number and store it in a linked list.
2. Convert the linked list to a string for display.
3. Find the first 10 smaller prime numbers up to half of the last 64 bits.
4. Perform a simplified Miller-Rabin primality test using the last 64 bits.

Assumptions

- The random number generator produces uniformly distributed numbers.
- The Miller-Rabin primality test is sufficient for this application.
- Memory constraints are not a concern.

Challenges Faced

- Handling very large numbers (1024 bits) without using specialized libraries.
- Implementing the Miller-Rabin primality test efficiently.
- Balancing code simplicity with performance considerations.
