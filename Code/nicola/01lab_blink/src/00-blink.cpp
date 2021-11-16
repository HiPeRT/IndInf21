#include <unistd.h>

const int time_delay = 1000; //1 secondo - esprimere in microsecondi
 
int next_blink(int current_blink) {
    usleep(time_delay * 1000);
    return (!current_blink);
}