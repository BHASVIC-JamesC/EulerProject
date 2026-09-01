# Project Euler

Solutions to Project Euler problems, written primarily in C, organised by the
technique required rather than by problem number.

**Ongoing since October 2024.** 75 problems solved to date.

---

## Why this repository is organised this way

Project Euler problems are numbered by the order they were published, not by
what they require. A repository laid out as `Q1.c`, `Q2.c`, `Q3.c` is a record
of which problems I happened to attempt, and nothing more.

Grouping by technique shows the breadth instead — the range of methods these
solutions actually span, from sieves and modular arithmetic through dynamic
programming, graph algorithms, and discrete probability. Choosing the right
approach is the hard part of these problems; brute force is almost always
available and almost always too slow. The directory names make the spread of
approaches visible at a glance.

## Why C

C is the language I first learned to program in — taught deliberately as a
first language, on the basis that working closer to the machine makes the
underlying computer system harder to ignore and gives the theory something
concrete to attach to.

I kept using it here partly out of familiarity, but mostly because it keeps
that pressure on. Without arbitrary-precision integers, dynamic containers, or
a standard library of mathematical helpers, the method has to be explicit:
big-integer arithmetic, memory layout, and sieve construction all get built
rather than imported. It also makes inefficiency obvious rather than
survivable, which is exactly the constraint these problems reward. Where a
problem is genuinely about the mathematics rather than the implementation,
Python is used instead.

## Index

| Directory | Focus |
|---|---|
| `01-primes-factorisation` | Sieves, primality testing, prime factorisation |
| `02-digit-manipulation` | Digit extraction, digit-based search, digit DP |
| `03-divisors-totients` | Divisor functions, Euler's totient, multiplicative functions |
| `04-combinatorics-permutations` | Counting arguments, permutation generation, binomials |
| `05-dynamic-programming-partitions` | Memoisation, integer partitions, recurrence design |
| `06-big-integer-arithmetic` | Arbitrary-precision arithmetic implemented from scratch |
| `07-figurate-numbers-sequences` | Polygonal numbers, sequence generation and search |
| `08-geometry-diophantine` | Lattice geometry, Pythagorean triples, Diophantine equations |
| `09-probability-markov` | Discrete probability, expectation, Markov chains |
| `10-strings-parsing-simulation` | Input parsing, state simulation, string algorithms |
| `11-graphs-grids` | Shortest paths, spanning trees, grid traversal |
| `12-search-backtracking` | Constraint search, pruning, backtracking |
| `13-fractions-rational` | Continued fractions, rational approximation, Farey sequences |
| `14-elementary-arithmetic` | Direct arithmetic and early problems |



Problem statements and answers are not reproduced here, in line with Project
Euler's guidance on publishing solutions.
