/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_frees.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:13:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/24 15:13:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(t_input_data *input_data)
{
	ft_free_input_data(input_data);
	write(1, "\e[1;31mERROR\n\e[0m", 17);
	exit(0);
}

void	ft_free_input_data(t_input_data *input_data)
{
	t_list_rooms	*tmp_r;

	if (input_data->inst)
		ft_lstdel(&(input_data->inst), &ft_del);
	while (input_data->lstrooms)
	{
		tmp_r = input_data->lstrooms;
		input_data->lstrooms = input_data->lstrooms->next;
		ft_strdel(&(tmp_r->name));
		free(tmp_r);
		tmp_r = NULL;
	}
	ft_free_lstways(input_data);
	ft_free_arrs(input_data);
}

void	ft_free_lstways(t_input_data *input_data)
{
	t_list_ways		*tmp_w;
	t_list_1way		*tmp_o;

	while (input_data->lstways)
	{
		tmp_w = input_data->lstways;
		input_data->lstways = input_data->lstways->next;
		while (tmp_w->lstoneway)
		{
			tmp_o = tmp_w->lstoneway;
			tmp_w->lstoneway = tmp_w->lstoneway->next;
			free(tmp_o);
			tmp_o = NULL;
		}
		free(tmp_w);
		tmp_w = NULL;
	}
}

void	ft_free_arrs(t_input_data *input_data)
{
	int i;

	if (input_data->arrlinks)
	{
		i = 0;
		while (i < input_data->nor)
		{
			free((input_data->arrlinks)[i]);
			(input_data->arrlinks)[i++] = NULL;
		}
		free(input_data->arrlinks);
		input_data->arrlinks = NULL;
	}
	if (input_data->arrways)
	{
		i = 0;
		while ((input_data->arrways)[i])
		{
			free((input_data->arrways)[i]);
			(input_data->arrways)[i++] = NULL;
		}
		free(input_data->arrways);
		input_data->arrways = NULL;
	}
}
