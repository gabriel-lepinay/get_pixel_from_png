/*
** EPITECH PROJECT, 2022
** main
** File description:
** Source code of the main
*/
#include "main.h"
#include <stdio.h>
#include "app.h"

int error_handling(int ac) 
{
    if (ac != 2)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    int status = 0;
    if (error_handling(ac) == 1) {
        dprintf(2, "[Error] Invalid format.\n"
        "Usage:\n\t ./open_img <imagepath.png>\n"
        "Tips:\n\t use ./open_img <imagepath.png> > outputfile\n");
        return (84);
    }
    status = start_app(av);
    return (status);
}