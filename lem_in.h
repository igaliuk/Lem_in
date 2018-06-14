/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:58:21 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/04 19:28:01 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct			s_list_rooms
{
	int					id;
	char				*name;
	int					x;
	int					y;
	struct s_list_rooms	*next;
}						t_list_rooms;

typedef struct			s_list_1way
{
	int					id;
	struct s_list_1way	*next;
}						t_list_1way;

typedef struct			s_list_ways
{
	t_list_1way			*lstoneway;
	int					lstoneway_size;
	struct s_list_ways	*next;
}						t_list_ways;

typedef struct			s_st_f
{
	int					start;
	int					fin;
}						t_st_f;

typedef struct			s_input_data
{
	t_list				*inst;
	int					noa;
	int					nor;
	t_st_f				count;
	t_list_rooms		*lstrooms;
	int					**arrlinks;
	t_list_ways			*lstways;
	int					**arrways;
}						t_input_data;

void					ft_zero(t_input_data *input_data);
void					ft_print_inst(t_list *inst);
void					ft_print_ways(t_input_data input_data);
void					ft_print_case(int noa, t_list_rooms *lstrooms);

int						ft_atoi_li(char *str, t_input_data *input_data);

void					ft_read_inst(t_input_data *input_data);
int						ft_analis_line(char *line, t_input_data *input_data,
										int start_end);
int						ft_mask_rooms_links(char *str, char c);

int						ft_processing_rooms(char *line,
											t_input_data *input_data,
											int start_end);
t_list_rooms			*ft_lstnew_r(t_input_data *input_data, size_t k);
char					*ft_findspace(char *src, int k);
int						ft_valid_room(t_list_rooms *lstrooms);

int						ft_processing_links(char *line,
											t_input_data *input_data);
void					ft_processing_links_malloc(t_input_data *input_data);
int						ft_finddash(char *src, t_list_rooms *lstrooms,
									int k);

void					ft_finding_way(t_input_data *input_data,
										t_list_1way **tmp, int i);
int						ft_norepeat(t_list_1way **tmp, int j);
void					ft_delforway(t_list_1way **tmp);
void					ft_new_way(t_input_data *input_data, t_list_1way **tmp);

void					ft_processing_ways(t_input_data *input_data);
void					ft_sort_ways(int **arrways);
void					ft_filter_ways(int **arrways, int start,
										t_input_data *input_data);
void					ft_stf1_2(int **arrways, t_st_f *stf1, t_st_f *stf2_1,
									t_st_f *stf2_2);
int						*ft_filter_doubles(int **arrways,
											t_st_f stf1, t_st_f stf2,
											t_input_data *input_data);

void					ft_delway(int **arrways, int i);
int						ft_doubles(int *arr1, int *arr2);
int						ft_parsing1(int **arrways, int **arrdoubles,
									t_st_f stf1);
int						ft_parsing2(int **arrdoubles, t_st_f stf1);
void					ft_parsing3(int **arrways, int **arrdoubles,
									t_st_f stf1);

size_t					ft_number_ways(t_list_ways *lstways);
void					ft_lst_to_arr_ways(t_input_data *input_data);

void					ft_starting_ants(t_input_data *input_data);
int						**ft_zero_ants_and_min_l(t_input_data *input_data,
													int *l_min, int *n_l_min);
int						ft_choice_way(int **ant, t_input_data input_data,
										int l_min, int n_l_min);
void					ft_print_steps(int **ants, int noa,
										t_list_rooms *lstrooms);

int						ft_check_finish(int **ants, int noa);
char					*ft_name_room(int id, t_list_rooms *lstrooms);

void					ft_error(t_input_data *input_data);
void					ft_free_input_data(t_input_data *input_data);
void					ft_free_lstways(t_input_data *input_data);
void					ft_free_arrs(t_input_data *input_data);

#endif
