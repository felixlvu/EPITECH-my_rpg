/*
** EPITECH PROJECT, 2023
** B-MUL-200-TLS-2-1-myrpg-louis.huguet
** File description:
** get_file.c
*/

#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

int my_strlen(char* str)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        a++;
    }
    return a;
}

char *my_strcpy(char *dest, char const *src)
{
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

struct poubelle {
    char **return_str;
    int index_str;
    int i;
};

int compteur_separator(int compteur_sep, char *str, char separator)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator || str[i] == '\n')
            compteur_sep++;
    }
    return compteur_sep;
}

int malloc_return_str(struct poubelle *p, char *str, char separator, int i)
{
    int malloc_count = 0;

    for (malloc_count; str[p->index_str] != '\n' &&
    str[p->index_str] != separator; p->index_str++)
        malloc_count++;
    p->index_str++;
    p->return_str[i] = malloc(sizeof(char) * malloc_count + 1);
    return p->index_str;
}

char **str_to_word_array (char *str, char separator)
{
    struct poubelle *p;
    int compteur_sep = 0;

    p = malloc(sizeof(struct poubelle));
    compteur_sep = compteur_separator(compteur_sep, str, separator);
    p->index_str = 0;
    p->return_str = malloc(sizeof(char*) * (compteur_sep + 1));
    for (int i = 0; i != compteur_sep; i++) {
        int k = p->index_str;
        int j = 0;
        malloc_return_str(p, str, separator, i);
        for (j = 0; str[k] != '\n' && str[k] != separator; k++) {
            p->return_str[i][j] = str[k];
            j++;
        }
        p->return_str[i][j] = '\0';
    }
    p->return_str[compteur_sep] = NULL;
    return p->return_str;
}

char** get_map(char* link)
{
    int fd = 0;
    char* buff = NULL;
    char** buffer = NULL;
    struct stat map;
    if (stat(link, &map) == -1) {
        return  NULL;
    }
    fd = open(link, O_RDONLY);
    buff = malloc(sizeof(char) * map.st_size + 1);
    buff[map.st_size] = '\0';
    read(fd, buff, map.st_size);
    buffer = str_to_word_array(buff, '\n');
    free(buff);
    return buffer;
}
