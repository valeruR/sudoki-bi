/*
** get_next_line.c for get_next_line in /home/valeru_r/rendu/Prog_Elem/GetNextLine/CPE_2015_getnextline
** 
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
** 
** Started on  Mon Jan 18 20:22:26 2016 Reever Valerus
** Last update Sun Feb 28 23:24:53 2016 valeru_r
*/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "sudoki.h"

char            *my_strcpy(char *buff, int s, t_read get, int i)
{
  get.u = 0;
  get.i = 0;
  get.t = 0;

  if ((get.str = malloc(sizeof(char) * (my_strlen(buff) + 1)))
      == NULL)
    return (NULL);
  if (s == 1)
    while (buff[get.i] != '\n' && buff[get.i] != '\0')
      get.str[get.u++] = buff[get.i++];
  else if (s == 2)
    {
      while (get.t < i && buff[get.i] != '\0')
        {
          if (buff[get.i] == '\n')
            get.t++;
          get.i++;
        }
      while (buff[get.i] != '\0' && buff[get.i] != '\n')
        get.str[get.u++] = buff[get.i++];
    }
  get.str[get.u] = '\0';
  return (get.str);
}

int             verif_line(char *str, int size, int i)
{
  int           z;
  int           y;

  z = 0;
  y = 0;
  while (z < size)
    {
      if (str[z] == '\n')
        {
          y++;
          if (y == i)
            return (z);
        }
      z++;
    }
  return (-1);
}

char            *my_realloc(char *buff, char *result, t_read get)
{
  char          *tmp;

  get.i = 0;
  get.u = 0;
  if ((tmp = malloc(sizeof(char) * (my_strlen(buff) +
                                    my_strlen(result) + 1))) == NULL)
    return (NULL);
  while (result[get.i] != '\0')
    {
      tmp[get.i] = result[get.i];
      get.i++;
    }
  while (buff[get.u] != '\n' && buff[get.u] != '\0')
    {
      tmp[get.i] = buff[get.u];
      get.i++;
      get.u++;
    }
  tmp[get.i] = '\0';
  free(result);
  return (tmp);
}

char            *return_line(char *buff, t_read get, int i, int *t)
{
  if ((get.u = verif_line(buff, (my_strlen(buff)), i)) >= 0)
    {
      get.str = my_strcpy(buff, 2, get, (i - 1));
      *t = 0;
    }
  else
    {
      get.str = my_strcpy(buff, 2, get, (i - 1));
      *t = -1;
    }
  return (get.str);
}

char            *get_next_line(const int fd)
{
  static char   buffer[READ_SIZE + 1] = "";
  static int    g = 1;
  static int    i = 1;
  t_read        get;

  get.t = -1;
  if (g > 1)
    get.str = return_line(buffer, get, i, &get.t);
  while (get.t == -1)
    {
      if (((get.r = read(fd, buffer, READ_SIZE)) <= 0) && g > 1)
	  return (NULL);
      else if ((get.r <= 0) && (g == 1))
	  return (get.str);
      buffer[get.r] = '\0';
      i = 1;
      get.t = verif_line(buffer, (my_strlen(buffer)), i);
      if (g == 1)
        get.str = my_strcpy(buffer, 1, get, 0);
      else
        get.str = my_realloc(buffer, get.str, get);
      g++;
    }
  i++;
  return (get.str);
}

/*int             main()
{
  int           fd;
  int           u;
  char          *s;

  fd = open("je_suis", O_RDONLY);
  u = 0;
  while ((s = get_next_line3(0)))
    {
      printf("%s\n", s);
      free(s);
      u++;
    }
  return (0);
}
*/
