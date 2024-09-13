/*
Example: execl
 */

#include <iostream>
#include <stdexcept>
#include <unistd.h>
using namespace std;

int main()
{
    const char *file = "/home/davidkebo/math-scripts/factorial.sh";
    const char *arg1 = "-lai";
    execl(file, file, arg1, NULL); // Binary + Path to the Binary + Rest of the options ... + NULL
    cout << "======AFTER========" << endl;
    return 0;
}
