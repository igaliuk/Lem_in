/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_ways.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:59:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/02/21 17:21:49 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_processing_ways(t_input_data *input_data)
{
	int		i;
	size_t	len;

	ft_lst_to_arr_ways(input_data);
	ft_sort_ways(input_data->arrways);
	i = 0;
	while ((input_data->arrways)[i])
	{
		len = ft_intlen((input_data->arrways)[i]);
		ft_filter_ways(input_data->arrways, i, input_data);
		while ((input_data->arrways)[i])
		{
			if (ft_intlen((input_data->arrways)[i]) != len)
				break ;
			i++;
		}
	}
}

void	ft_sort_ways(int **arrways)
{
	int		i;
	int		k;
	int		*tmp;

	k = 1;
	while (k == 1)
	{
		k = 0;
		i = 1;
		while (arrways[i])
		{
			if (ft_intlen(arrways[i - 1]) > ft_intlen(arrways[i]))
			{
				tmp = arrways[i - 1];
				arrways[i - 1] = arrways[i];
				arrways[i] = tmp;
				k = 1;
			}
			i++;
		}
	}
}

void	ft_filter_ways(int **arrways, int start, t_input_data *input_data)
{
	int		*arrdoubles;
	int		k;
	t_st_f	stf1;
	t_st_f	stf2_1;
	t_st_f	stf2_2;

	stf1.start = start;
	ft_stf1_2(arrways, &stf1, &stf2_1, &stf2_2);
	arrdoubles = ft_filter_doubles(arrways, stf1, stf2_1, input_data);
	if ((k = ft_parsing1(arrways, &arrdoubles, stf1)) == 2)
		return ;
	if (k == 1)
	{
		ft_filter_ways(arrways, start, input_data);
		return ;
	}
	arrdoubles = ft_filter_doubles(arrways, stf1, stf1, input_data);
	if (ft_parsing2(&arrdoubles, stf1))
	{
		arrdoubles = ft_filter_doubles(arrways, stf1, stf2_2, input_data);
		ft_parsing3(arrways, &arrdoubles, stf1);
		ft_filter_ways(arrways, start, input_data);
	}
}

void	ft_stf1_2(int **arrways, t_st_f *stf1, t_st_f *stf2_1, t_st_f *stf2_2)
{
	int		i;
	size_t	len;

	i = stf1->start;
	len = ft_intlen(arrways[i]);
	while (arrways[i])
	{
		if (ft_intlen(arrways[i]) != len)
			break ;
		i++;
	}
	stf1->fin = i;
	stf2_1->start = 0;
	stf2_1->fin = stf1->start;
	if (!(stf1->start))
		stf2_1->fin = 0;
	stf2_2->start = stf1->start;
	while (arrways[i])
		i++;
	stf2_2->fin = i;
}

int		*ft_filter_doubles(int **arrways, t_st_f stf1, t_st_f stf2,
							t_input_data *input_data)
{
	int		i;
	int		j;
	int		*arrdoubles;

	if (!(arrdoubles = (int *)malloc(sizeof(int) * (stf1.fin - stf1.start))))
		ft_error(input_data);
	i = stf1.start;
	while (i < stf1.fin)
	{
		arrdoubles[i - stf1.start] = 0;
		j = stf2.start;
		while (j < stf2.fin)
		{
			if (j != i)
				arrdoubles[i - stf1.start] += ft_doubles(arrways[i],
															arrways[j]);
			j++;
		}
		i++;
	}
	return (arrdoubles);
}
