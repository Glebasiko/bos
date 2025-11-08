#include <stdio.h>
#include "liblogger.h"

void getLastLog() {
    printf("Hello, from lib!\n");
}

void addLog(char* input) {
    printf("%s %s\n", input, "accepted by lib!");
}