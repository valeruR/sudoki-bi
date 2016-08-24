/*
** sudoki.c for sudoki in /home/cosson_v/rendu/C_Prog_Elem/sudoki-bi
** 
** Made by Vincent Cosson
** Login   <cosson_v@cosson-v-pc>
** 
** Started on  Sat Feb 27 10:36:52 2016 Vincent Cosson
** Last update Sun Feb 28 23:30:12 2016 valeru_r
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "sudoki.h"

int		main()
{
  t_main	data;

  data.i = 0;
  while (data.i < 11)
    {
      if ((data.str = get_next_line(0)) == NULL)
	return (-1);
      if ((check_map(data.str)) == -1)
	return (-1);
      if (data.i == 0)
	data.str2 = my_str_cpy(data.str2, data.str);
      else
	data.str2 = my_strcat_map(data.str2, data.str);
      data.i++;
    }
  data.tab = put_int_tab(data.str2);
  free(data.str2);
  if ((good_tab(data.tab, 0)) == -1)
    {
      print_map_error();
      return (-1);
    }
  print_final(data.tab);
  return (0);
}
