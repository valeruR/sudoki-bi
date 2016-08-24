/*
** sudoki.h for sudoki in /home/valeru_r/rendu/Prog_Elem/sudoki-bi
** 
** Made by valeru_r
** Login   <valeru_r@MrWest>
** 
** Started on  Sat Feb 27 11:45:19 2016 valeru_r
** Last update Sun Feb 28 23:32:24 2016 valeru_r
*/

#ifndef SUDOKI_H_
# define SUDOKI_H_

#ifndef READ_SIZE
# define READ_SIZE 50
#endif /* READ_SIZE */

typedef struct		s_read
{
  char			*str;
  int			r;
  int			t;
  char			*str2;
  int			u;
  int			i;
}			t_read;

typedef struct		s_tab
{
  int			i;
  int			u;
  int			j;
  int			k;
  int			**tab;
}			t_tab;

typedef struct		s_main
{
  char			*str;
  int			**tab;
  char			*str2;
  int			i;
}			t_main;

char		*get_next_line(int fd);
int		verif_line(char *str, int size, int i);
void		my_putchar(char c);
void		my_putstr(char *str);
void		my_put_nbr(int nb);
int		my_strlen(char *str);
char		*my_strcat_map(char *str, char *str2);
char		*my_str_cpy(char *dest, char *src);
int		**put_int_tab(char *str);
int		check_map(char *line);
void		print_map(char *str);
void		print_map_error();
void		print_final(int **tab);
int		good_tab(int **tab, int position);


#endif /* !SUDOKI_H_ */
