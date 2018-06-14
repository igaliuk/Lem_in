/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_li.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:58:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/27 17:58:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_atoi_li(char *str, t_input_data *input_data)
{
	int			i;
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i])
	{
		if ((i == 0) && (str[i] == '-'))
		{
			sign = -1;
			i++;
		}
		if (str[i] >= '0' && str[i] <= '9')
			res = 10 * res + str[i] - '0';
		if ((res * sign < -2147483648) || (res * sign > 2147483647)
			|| str[i] < '0' || str[i] > '9')
			ft_error(input_data);
		i++;
	}
	return (res * sign);
}
