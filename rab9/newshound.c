#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char *feeds[] = {
        "http://cnn.com",
        "http://rollingstone.com",
        "http://eonline.com"
    };
    int times = 3;
    char *phrase = argv[1];
    int i;

    for (i = 0; i < times; i++) {
        char var[255];
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        char *vars[] = {var, NULL};

        if (execle("/usr/bin/python3", "/usr/bin/python3", "./rssgossip.py", phrase, NULL, vars) == -1) {

            
            fprintf(stderr, "Не могу запустить скрипт: %s\n", strerror(errno));
            return 1;
        }
    }
    return 0;
}
