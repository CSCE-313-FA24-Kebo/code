/*
Example: Use sigaction() to establish a handler for the SIGINT signal.
*/

//  |sigaction| vs signal <<<<

// sigaction handles sets of signals 
// create mask of blocked signals
// functions to add signals to the mask
// functions to empty the mask
// Flags


#include "apue.h"
#include <signal.h>

static void handler(int signum)
{
    printf("Another action.\n");
}

int main()
{
    struct sigaction sa; // Struct with attributes: handler (pointer to a fct), sigaction (pointer to a fct), mask , flags.

    // Define the action the signal will take
    sa.sa_handler = handler;

    // Empty the mask set for this sigaction -> this means that we can capture ALL signals
    sigemptyset(&sa.sa_mask);  // New

    // System calls interrupted by this signal are automatically restarted.
    sa.sa_flags = SA_RESTART | SA_SIGINFO; // 

    // Change the action of SIGINT
    if (sigaction(SIGINT, &sa, NULL) == -1)
        printf("sigaction failed!");

    for (;;)
        pause(); // The pause function suspends the calling process until a signal is received.
}
