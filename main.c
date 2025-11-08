#include <stdio.h>
#include <dlfcn.h>
#include "liblogger.h"

int main() {
    // Открыть библиотеку
    void *handle = dlopen("liblogger.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    // Очистить ошибки
    dlerror();

    // Получить указатель на функцию getLastLog
    void (*getLastLog)() = dlsym(handle, "getLastLog");
    char *error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        dlclose(handle);
        return 1;
    }

    getLastLog();

    // Получить указатель на функцию addLog (ИСПРАВЛЕНО: void вместо int)
    void (*addLog)(char*) = dlsym(handle, "addLog");
    error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        dlclose(handle);
        return 1;
    }

    addLog("logstring");

    // Закрыть библиотеку
    dlclose(handle);
    return 0;
}