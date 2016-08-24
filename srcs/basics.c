/*
** basics.c for basics in /home/valeru_r/rendu/Prog_Elem/sudoki-bi
** 
** Made by valeru_r
** Login   <valeru_r@MrWest>
** 
** Started on  Sat Feb 27 17:46:08 2016 valeru_r
** Last update Sat Feb 27 17:46:43 2016 valeru_r
*/

#include "sudoki.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
