#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

    char *my_env[] = {"JUICE=персик и яблоко", NULL};

    execle("diner_info", "diner_info", "4", NULL, my_env);

    perror("Ошибка при запуске diner_info");
    return 1;
}