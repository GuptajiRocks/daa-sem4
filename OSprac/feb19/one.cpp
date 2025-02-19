#include <iostream>
#include<unistd.h>
#include<sys/types.h>

using namespace std;

int main() {
    //pid_t p = fork();
    cout << getpid() << endl;

    return 0;
}