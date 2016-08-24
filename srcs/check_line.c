/*
** check_line.c for check_line in /home/cosson_v/rendu/C_Prog_Elem/sudoki-bi
** 
** Made by Vincent Cosson
** Login   <cosson_v@cosson-v-pc>
** 
** Started on  Sat Feb 27 15:12:06 2016 Vincent Cosson
** Last update Sun Feb 28 22:01:02 2016 valeru_r
*/

#include <stdio.h>
#include "sudoki.h"

int		check_map(char *line)
{
  int		i;

  i = 0;
  while (line[i] != '\0')
    {
      if (my_strlen(line) != 20)
	{
	  printf("MAP ERROR ollle\n\n");
	  return (-1);
	}
      if ((line[i] != '|') && (line[i] != '-') && (line[i] != '\n') &&
	  (line[i] != '\n') && (line[i] < '1' && line[i] > '9'))
	{
	  printf("MAP ERROR\n\n");
	  return (-1);
	}
      i = i + 1;
    }
  return (0);
}

int		check_line(int **tab, int k, int i)
{
  int		j;

  j = 0;
  while (j < 9)
    {
      if (tab[i][j] == k)
	return (-1);
      j++;
    }
  return (0);
}

int		check_column(int **tab, int k, int j)
{
  int		i;

  i = 0;
  while (i < 9)
    {
      if (tab[i][j] == k)
	return (-1);
      i++;
    }
  return (0);
}

int		check_bloc(int **tab, int k, int i, int j)
{
  int		u;
  int		e;

  u = i - (i % 3);
  e = j - (j % 3);
  i = u;
  while (i < u + 3)
    {
      j = e;
      while (j < e + 3)
	{
	  if (tab[i][j] == k)
	    return (-1);
	  j++;
	}
      i++;
    }
  return (0);
}

int		good_tab(int **tab, int position)
{
  int		i;
  int		k;
  int		j;

  i = position / 9;
  j = position % 9;
  k = 1;
  if (position == 81)
    return (0);
  if (tab[i][j] != 0)
    return good_tab(tab, (position + 1));
  while (k <= 9)
    {
      if ((!(check_line(tab, k, i)))
	&& (!(check_column(tab, k, j)))
	  && (!(check_bloc(tab, k, i, j))))
	{
	  tab[i][j] = k;
	  if (!(good_tab(tab, position + 1)))
	    return (0);
	}
      k++;
    }
  tab[i][j] = 0;
  return (-1);
}
