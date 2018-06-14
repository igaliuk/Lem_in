/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starting_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:10:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/02/26 16:10:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_starting_ants(t_input_data *input_data)
{
	int **ants;
	int i;
	int l_min;
	int n_l_min;

	ants = ft_zero_ants_and_min_l(input_data, &l_min, &n_l_min);
	while (ft_check_finish(ants, input_data->noa))
	{
		i = 0;
		while (i < input_data->noa)
		{
			if (!ants[i][0])
			{
				if (ants[i][2] == -1
					&& !ft_choice_way(&(ants[i]), *input_data, l_min, n_l_min))
					break ;
				ants[i][1] = input_data->arrways[ants[i][2]][ants[i][3]];
				(ants[i][3])++;
			}
			i++;
		}
		ft_print_steps(ants, i, input_data->lstrooms);
	}
	ft_arrdel(ants, (size_t)(input_data->noa));
}

int		**ft_zero_ants_and_min_l(t_input_data *input_data, int *l_min,
									int *n_l_min)
{
	int		**ants;
	int		i;

	if (!(ants = (int **)malloc(sizeof(int *) * input_data->noa)))
		ft_error(input_data);
	i = 0;
	while (i < input_data->noa)
	{
		if (!(ants[i] = (int *)malloc(sizeof(int) * 4)))
		{
			ft_arrdel(ants, (size_t)i);
			ft_error(input_data);
		}
		ants[i][0] = 0;
		ants[i][1] = 1;
		ants[i][2] = -1;
		ants[i][3] = 0;
		i++;
	}
	*l_min = (int)ft_intlen((input_data->arrways)[0]);
	*n_l_min = 1;
	while ((input_data->arrways)[*n_l_min]
		&& (int)ft_intlen((input_data->arrways)[*n_l_min]) == *l_min)
		(*n_l_min)++;
	return (ants);
}

int		ft_choice_way(int **ant, t_input_data input_data,
						int l_min, int n_l_min)
{
	static int w = 0;
	static int right_ants = 0;

	if (!(input_data.arrways[w]))
	{
		w = 0;
		return (0);
	}
	while (((int)ft_intlen(input_data.arrways[w]) - l_min)
			* n_l_min >= input_data.noa - right_ants)
	{
		w++;
		if (!(input_data.arrways[w]))
		{
			w = 0;
			return (0);
		}
	}
	(*ant)[2] = w++;
	right_ants++;
	return (1);
}

void	ft_print_steps(int **ants, int noa, t_list_rooms *lstrooms)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (i < noa)
	{
		if (k)
			write(1, " ", 1);
		if (!(ants[i][0]) && ants[i][2] != -1)
		{
			ft_printf("L%d-%s", i + 1, ft_name_room(ants[i][1], lstrooms));
			k = 1;
		}
		if (!ants[i][1])
			ants[i][0] = 1;
		i++;
	}
	write(1, "\n", 1);
}
