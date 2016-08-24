/*
** retrieve_map.c for retrieve_map in /home/valeru_r/rendu/Prog_Elem/sudoki-bi
** 
** Made by valeru_r
** Login   <valeru_r@MrWest>
** 
** Started on  Sat Feb 27 11:48:17 2016 valeru_r
<<<<<<< HEAD
** Last update Sun Feb 28 19:14:00 2016 valeru_r
=======
** Last update Sun Feb 28 18:51:55 2016 Vincent Cosson
>>>>>>> 9e4432e8eddcc63249aeeb324f533080c53f45d5
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "sudoki.h"

char		*my_strcat_map(char *str, char *str2)
{
  int		i;
  int		u;
  char		*str3;

  i = 0;
  u = 0;
  str3 = malloc(sizeof(char) *((my_strlen(str))
			       + (my_strlen(str2)) + 1));
  while (str[i])
    {
      str3[i] = str[i];
      i++;
    }
  while (str2[u])
    {
      str3[i] = str2[u];
      i++;
      u++;
    }
  str3[i] = '\0';
  free(str);
  return (str3);
}

char		*my_str_cpy(char *dest, char *src)
{
  int		i;

  i = 0;
  dest = malloc(sizeof(char) * my_strlen(src) + 1);
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

void		print_map(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (i != 0 && i % 20 == 0)
	printf("\n");
      printf("%c", str[i]);
      i++;
    }
}

void		print_map_error()
{
  printf("|------------------|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n");
  printf("|------------------|\n");
}

void		print_final(int **tab)
{
  int		i;
  int		u;

  i = 0;
  printf("|------------------|\n");
  while (i < 9)
    {
      u = 0;
      printf("|");
      while (u < 9)
	{
	  printf(" %d", tab[i][u]);
	  u++;
	}
      printf("|\n");
      i++;
    }
  printf("|------------------|\n");
}
