/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:29:00 by ghtouman          #+#    #+#             */
/*   Updated: 2019/08/10 13:44:23 by tigre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# define BUF_SIZE 1000

typedef enum			e_bool
{
	false,
	true
}						t_bool;

typedef struct			s_room
{
	char				*name;
	struct s_room		*next;
	struct s_room		*last;
	int					len_name;
	int					id;
}						t_room;

typedef struct			s_buf
{
	char				buf[BUF_SIZE];
	int					len;
	struct s_buf		*last;
	struct s_buf		*sep;
	struct s_buf		*next;
}						t_buf;

typedef struct			s_way
{
	int					id;
	int					current;
	char				*name;
	struct s_way		*next;
	struct s_way		*last;
}						t_way;

typedef struct			s_tree
{
	int					id;
	int					step;
	int					current;
	struct s_tree		*father;
}						t_tree;

typedef	struct			s_file
{
	int					id;
	int					true_father;
	t_tree				*father;
	struct s_file		*next;
}						t_file;

typedef struct			s_sol
{
	int					nb_ants;
	int					len_way;
	char				*name;
	struct s_sol		*next;
}						t_sol;

typedef struct			s_bfs
{
	t_bool				overlap;
	t_bool				stop;
	t_file				*f;
	t_bool				*visited;
	t_bool				*p_old_visited;
}						t_bfs;

typedef struct			s_rabbit
{
	int					id;
	int					i;
	t_way				*tmp;
	t_way				*mem;
}						t_rabbit;

typedef struct			s_data
{
	int					nb_ant;
	int					end_id;
	int					nb_room;
	int					size;
	int					score;
	int					i_bucheron;
	int					start_end;
	int					off_s_e;
	int					check;
	int					first;
	char				*start;
	char				*end;
	char				*require_line;
	char				ways[100000];
	t_buf				*pad;
	t_file				*file;
	t_tree				**bucheron;
}						t_data;

/*
**						PARSE :
*/
void					get_ant(char **line, t_data *d);
t_room					**get_room(char **line, t_room **room, t_data *d);
void					end_get_room(t_room **room, char **line, t_data *d);
t_bool					no_double_room(t_room **room, char *line);
char					*strdup_lim(char *str, t_data *d,
						t_room **elem, t_room **room);
t_bool					find_dash(char *str);
t_way					**get_way(char **line, t_data *d,
						t_way **tab_way, t_room **room);
t_way					**init_get_way(t_way **tab_way, t_data *d);
t_bool					no_start_end(char *line);
/*
**						BFS ALGO :
*/
t_bool					bfs(t_way **tab_way, t_tree **t, t_data *d,
						t_bool *old_visited);
t_bool					go_back(t_bfs *bfs, t_way **tab_way);
void					put_zero(t_bool *tab, int size);
/*
**						SOLUTIONS MANAGER:
*/
void					get_flux(t_room **room, t_way **tab_way, t_data *d);
t_sol					**follow_the_rabbit(t_way **tab_way, t_sol **sol,
						t_data *d);
void					potentiel_result(t_way **tab_way, t_data *d);
void					print_sol(t_sol **sol, t_data *d);
/*
**						ERRORS MANAGER :
*/
void					ft_exit(t_room **room, t_way **tab_way, t_data d);
int						check_ascii(char *line);
/*
**						FILL BUFFER
*/
t_buf					*lst_buf(char *line, t_buf *pad);
void					str_to_buf(t_data *d, int *len, char *str);
void					put_ways_to_buf(t_sol **sol, t_data *d);
void					fill_buf(t_sol **ant, int n, t_data *d, t_buf *pad);
void					add_buf(t_buf **pad);
/*
**						OPTIONS :
*/
void					get_line_require(char *line, t_data *d);
void					print_options(t_data d, int ac, char **av);
void					print_score(int *indicator, size_t *j, t_data d);
void					usage(int *indicator, size_t *j);
void					print_ways(int *indicator, size_t *j, t_data d);
/*
**						FREE :
*/
void					clean_t_tree(t_data *d);
void					clean_sol(t_sol **sol, int size);
void					clean_file(t_file *f);
void					clean(t_room **room, t_way **tab_way, t_data d);
void					lstbufdel(t_buf **pad);
void					free_room(t_room **room, t_data d);

#endif
