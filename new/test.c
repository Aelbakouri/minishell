#include <stdio.h>
#include <unistd.h>

int main() {
    char *cwd; // Array to hold the current working directory
    cwd = getcwd(NULL, 0);
    if (1) {
        printf("Current workinnng directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }

    return 0;
}