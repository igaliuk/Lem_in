/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_ways_daughter.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 10:40:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/02/22 10:40:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_delway(int **arrways, int i)
{
	int		*tmp;

	while (arrways[i + 1])
	{
		tmp = arrways[i];
		arrways[i] = arrways[i + 1];
		arrways[i + 1] = tmp;
		i++;
	}
	free(arrways[i]);
	arrways[i] = NULL;
}

int		ft_doubles(int *arr1, int *arr2)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (arr1[i])
	{
		j = 0;
		while (arr2[j])
		{
			if (arr1[i] == arr2[j])
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

int		ft_parsing1(int **arrways, int **arrdoubles, t_st_f stf1)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (stf1.start < stf1.fin)
	{
		if ((*arrdoubles)[i++])
		{
			ft_delway(arrways, (stf1.start)--);
			(stf1.fin)--;
			k++;
		}
		(stf1.start)++;
	}
	free(*arrdoubles);
	*arrdoubles = NULL;
	if (k == i)
		return (2);
	if (k)
		return (1);
	return (0);
}

int		ft_parsing2(int **arrdoubles, t_st_f stf1)
{
	int		i;
	int		k;

	k = 0;
	i = stf1.start;
	while (i < stf1.fin)
	{
		if ((*arrdoubles)[i - stf1.start])
			k = 1;
		i++;
	}
	free(*arrdoubles);
	*arrdoubles = NULL;
	if (k)
		return (1);
	return (0);
}

void	ft_parsing3(int **arrways, int **arrdoubles, t_st_f stf1)
{
	int		i;
	int		count_max;
	int		max;

	max = 0;
	count_max = stf1.start;
	i = stf1.start;
	while (i < stf1.fin)
	{
		if ((*arrdoubles)[i - stf1.start] > max)
		{
			max = (*arrdoubles)[i - stf1.start];
			count_max = i;
		}
		i++;
	}
	free(*arrdoubles);
	*arrdoubles = NULL;
	if (max)
		ft_delway(arrways, count_max);
}
