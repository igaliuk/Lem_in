/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrways.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:09:12 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/07 11:19:37 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	ft_number_ways(t_list_ways *lstways)
{
	t_list_ways		*tmp;
	size_t			i;

	tmp = lstways;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_lst_to_arr_ways(t_input_data *input_data)
{
	t_list_ways		*tmp;
	t_list_1way		*tmp_ow;
	int				i;
	int				j;

	tmp = input_data->lstways;
	i = 0;
	while (tmp)
	{
		if (!((input_data->arrways)[i] = (int *)malloc(sizeof(int)
			* (tmp->lstoneway_size + 1))))
			ft_error(input_data);
		tmp_ow = tmp->lstoneway;
		j = 0;
		while (j < tmp->lstoneway_size)
		{
			(input_data->arrways)[i][j++] = tmp_ow->id;
			tmp_ow = tmp_ow->next;
		}
		(input_data->arrways)[i++][j] = 0;
		tmp = tmp->next;
	}
	(input_data->arrways)[i] = NULL;
}
