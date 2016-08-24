/*
** print_final.c for print_final in /home/valeru_r/sudoki-bi
** 
** Made by valeru_r
** Login   <valeru_r@MrWest>
** 
** Started on  Sun Feb 28 18:32:44 2016 valeru_r
** Last update Sun Feb 28 19:07:22 2016 valeru_r
*/

#include <stdio.h>
#include "sudoki.h"

void		print_final(int **tab)
{
  int		u;
  int		i;

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
