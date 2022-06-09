/*
** EPITECH PROJECT, 2022
** app.c
** File description:
** Source code of app
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <png.h>
#include <stdlib.h>
#include <string.h>

void write_data(int width, int height, png_bytepp rows)
{
    int i = 0;
    int j = 0;

    printf("%ix%i\n", width, height);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width * 4; j += 4) {
            printf("%i %i %i \n", rows[i][j], rows[i][j + 1], rows[i][j + 2]);
        }   
    }
}

int get_image_data(char *path)
{
    int width = 0;
    int height = 0;
    FILE *file = fopen(path, "r");
    png_bytepp rows = NULL;
    png_structp pngptr = NULL;
    png_infop pnginfo = NULL;

    if (file == NULL)
        return (-1);
    pngptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (pngptr == NULL)
        return (-1);
    pnginfo = png_create_info_struct(pngptr);
    png_set_palette_to_rgb(pngptr);
    png_init_io(pngptr, file);
    png_read_png(pngptr, pnginfo, PNG_TRANSFORM_IDENTITY, NULL);
    width = png_get_image_width(pngptr, pnginfo);
    height = png_get_image_height(pngptr, pnginfo);
    rows = png_get_rows(pngptr, pnginfo);
    write_data(width, height, rows);
    png_destroy_read_struct(&pngptr, &pnginfo, (png_infopp) NULL);
    fclose(file);
    return (0);
}

int is_png_file(char *path)
{
    int len = strlen(path);
    char *ext = NULL;

    if (path[len - 4] != '.')
        return (-1);
    ext = strdup(path + len - 4);
    if (strcmp(ext, ".png") != 0) {
        free(ext);
        return (-1);
    }
    free(ext);
    return (0);
}

int start_app(char **av)
{
    if (is_png_file(av[1]) == -1) {
        dprintf(2, "[ERROR] \'%s\' is not a png file\n", av[1]);
        return (-1);
    }
    
    if (get_image_data(av[1]) == -1) {
        dprintf(2, "[ERROR] \'%s\' was not found\n", av[1]);
        return (-1);
    }
    return (0);
}