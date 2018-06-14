/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finding_way.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:02:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/29 12:02:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_finding_way(t_input_data *input_data, t_list_1way **tmp, int i)
{
	t_list_1way		*tmp2;
	int				j;

	if ((input_data->arrlinks)[i][0])
	{
		ft_new_way(input_data, tmp);
		return ;
	}
	j = 2;
	while (j < input_data->nor)
	{
		if ((input_data->arrlinks)[i][j] && ft_norepeat(tmp, j))
		{
			if (!(tmp2 = (t_list_1way *)malloc(sizeof(t_list_1way))))
				ft_error(input_data);
			tmp2->id = j;
			tmp2->next = *tmp;
			*tmp = tmp2;
			ft_finding_way(input_data, tmp, j);
			ft_delforway(tmp);
		}
		j++;
	}
}

int		ft_norepeat(t_list_1way **tmp, int j)
{
	t_list_1way	*tmp2;

	tmp2 = *tmp;
	while (tmp2)
	{
		if (tmp2->id == j)
			return (0);
		tmp2 = tmp2->next;
	}
	return (1);
}

void	ft_delforway(t_list_1way **tmp)
{
	t_list_1way	*tmp2;

	if (!tmp || !(*tmp))
		return ;
	tmp2 = *tmp;
	*tmp = (*tmp)->next;
	free(tmp2);
	tmp2 = NULL;
}

void	ft_new_way(t_input_data *input_data, t_list_1way **tmp)
{
	t_list_1way		*tmptmp;
	t_list_1way		*tmptmp2;
	t_list_ways		*tmpways;

	if (!(tmpways = (t_list_ways *)malloc(sizeof(t_list_ways))))
		ft_error(input_data);
	tmpways->lstoneway = NULL;
	tmpways->lstoneway_size = 0;
	tmpways->next = input_data->lstways;
	input_data->lstways = tmpways;
	tmptmp = *tmp;
	while (tmptmp)
	{
		if (!(tmptmp2 = (t_list_1way *)malloc(sizeof(t_list_1way))))
			ft_error(input_data);
		tmptmp2->id = tmptmp->id;
		tmptmp2->next = input_data->lstways->lstoneway;
		input_data->lstways->lstoneway = tmptmp2;
		(tmpways->lstoneway_size)++;
		tmptmp = tmptmp->next;
	}
}
