**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

New:  Process is about to be created, program will eventually be picked up by the OS to create the process

Ready:  Process is ready to run, and loaded into main memory.  Maintained in a ready queue.

Running:  Process is being executed by the CPU.

Waiting:  Process needs input from user or is waiting for a child process to finish or for access to some resource.

Terminated:  Process is destroyed.


**2. What is a zombie process?**

A zombie process is a child process that has finished executing, but its parent process is still executing or in a waiting state.


**3. How does a zombie process get created? How does one get destroyed?**

A zombie process is created when the child process of a parent (created from a fork()) finishes executing but the parent doesn't clean it up.  It gets destroyed when the parent process cleans it up such as by using the `waitpid(int pid)` command, which waits for the child to finish executing before executing any code from the parent process.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

A compiled language will generally be more performant then a non compiled language. That is, even though we have to take the time to compile our code, it will run much faster than code that is read by an interpreter used by a non-compiled language.

We also get more control over memory and CPU usage as we are allocating only the memory that we require for our programs.

