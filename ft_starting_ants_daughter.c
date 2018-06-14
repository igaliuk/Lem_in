/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starting_ants_daughter.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:36:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/03/04 10:36:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_finish(int **ants, int noa)
{
	int i;

	i = 0;
	while (i < noa)
		if (!(ants[i++][0]))
			return (1);
	return (0);
}

char	*ft_name_room(int id, t_list_rooms *lstrooms)
{
	t_list_rooms *tmp;

	tmp = lstrooms;
	while (tmp)
	{
		if (tmp->id == id)
			return (tmp->name);
		tmp = tmp->next;
	}
	return (NULL);
}
