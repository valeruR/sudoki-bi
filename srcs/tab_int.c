/*
** tab_int.c for tab_int in /home/valeru_r/rendu/Prog_Elem/sudoki-bi
** 
** Made by valeru_r
** Login   <valeru_r@MrWest>
** 
** Started on  Sat Feb 27 15:35:15 2016 valeru_r
** Last update Sat Feb 27 18:47:38 2016 valeru_r
*/

#include <stdio.h>
#include <stdlib.h>
#include "sudoki.h"

int		**init_tab()
{
  int		**tab;
  int		i;

  i = 0;
  tab = malloc(sizeof(int *) * 9);
  while (i < 9)
    {
      tab[i] = malloc(sizeof(int) * 9);
      i++;
    }
  return (tab);
}

int		get_start(char *str)
{
  int		u;
  int		k;

  u = 0;
  k = 0;
  while (k < 3)
    {
      if (str[u] == '|')
	k++;
      u++;
    }
  u--;
  return (u);
}

void		init_var_tab(int *u, int *j)
{
  *u = 0;
  *j = 0;
}

int		**put_int_tab(char *str)
{
  t_tab		data;

  data.tab = init_tab();
  data.i = get_start(str);
  init_var_tab(&data.u, &data.j);
  while (str[data.i])
    {
      if (str[data.i] >= '0' && str[data.i] <= '9')
	{
	  data.tab[data.u][data.j] = str[data.i] - '0';
	  data.j++;
	}
      else if (str[data.i] == ' ')
	{
	  data.tab[data.u][data.j] = 0;
	  data.j++;
	}
      if (data.j == 9)
	{
	  data.j = 0;
	  data.u++;
	}
      data.i = data.i + 2;      
    }
  return (data.tab);
}

void		print_tab(int **tab)
{
  int		i;
  int		u;

  i = 0;
  while (i < 9)
    {
      u = 0;
      while (u < 9)
	{
	  printf("%d", tab[i][u]);
	  u++;
	}
      printf("\n");
      i++;
    }
}
