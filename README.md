# Operating-Systems-Labs
## A brief explanation of repository contents

This repository is setup as a demonstration of my work completed during my degree in regards to Operating Systems.

- The aim of this work is to use Linux to explore the role of operating systems on computers to see how pipes and threads work and how memory managed.

- The tasks consited of using the Linux terminal commands, writing bash shell scripts and writing/compiling small C programs that explore Linux/POSIX features such as threads.

- Used Linux bash commands: strace, man, getpid, getppid.

- Wrote shell scripts and used strace to find pipe/forks/clone/child processes.

- Wrote small C programs that make forks and another using **POSIX threads**.

- Added **Mutual Exclusion** semaphore to POSIX threaded programs.

- **Inter process communication** using messages/signals.

- **Memory management** using chuncks and mmap.

- Some of the work is based on Beej's guide to Unix.

## Screenshots

Below are screenshots looking at the CPU usage (using command top in the terminal) when increasing the number of total processes in the forkE11.c program. The program was run on a single CPU with 2 physical cores with 2 threads.

### ForkE11.c where N=3

![Alt text](/ospracticals/forkN3.png?raw=true "ForkE11 using N=3")

### ForkE11.c where N=4

![Alt text](/ospracticals/forkN4.png?raw=true "ForkE11 using N=4")

### ForkE11.c where N=8

![Alt text](/ospracticals/forkN8.png?raw=true "ForkE11 using N=8")

### ForkE11.c where N=16

![Alt text](/ospracticals/forkN16.png?raw=true "ForkE11 using N=16")
