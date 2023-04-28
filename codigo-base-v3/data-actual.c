#include <time.h>
#include <stdio.h>

int main (void) {

    char buff[100];
    time_t now = time(0);
    struct tm now_t = *localtime(&now);
    strftime (buff, 100, "%d/%m/%Y %H:%M:%S", &now_t);
    
    puts(buff);

    return 0;
}
