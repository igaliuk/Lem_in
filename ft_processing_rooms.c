/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_rooms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:35:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/02/20 12:55:18 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_processing_rooms(char *line, t_input_data *input_data,
									int start_end)
{
	t_list_rooms	*tmp_r;
	char			*str;
	int				k;

	(input_data->nor)++;
	tmp_r = ft_lstnew_r(input_data, start_end);
	k = 0;
	while (k < 3)
	{
		if (!(str = ft_findspace(line, k)))
			ft_error(input_data);
		if (!k)
			tmp_r->name = ft_strdup(str);
		else if (k == 1)
			tmp_r->x = ft_atoi_li(str, input_data);
		else
			tmp_r->y = ft_atoi_li(str, input_data);
		ft_strdel(&str);
		k++;
	}
	if (ft_valid_room(input_data->lstrooms))
		return (-1);
	return (0);
}

t_list_rooms	*ft_lstnew_r(t_input_data *input_data, size_t k)
{
	static int		id = 2;
	t_list_rooms	*tmp_r;

	if (!(tmp_r = (t_list_rooms *)malloc(sizeof(t_list_rooms))))
		ft_error(input_data);
	if (k)
		tmp_r->id = (int)k - 1;
	else
		tmp_r->id = id++;
	tmp_r->name = NULL;
	tmp_r->x = 0;
	tmp_r->y = 0;
	tmp_r->next = input_data->lstrooms;
	input_data->lstrooms = tmp_r;
	return (tmp_r);
}

char			*ft_findspace(char *src, int k)
{
	static int		start;
	int				i;
	char			*str;

	if (!k)
		start = 0;
	i = start;
	while (src[i])
	{
		if (k < 2 && src[i] == ' ')
			break ;
		i++;
	}
	str = ft_strsub(src, start, i - start);
	start = i + 1;
	return (str);
}

int				ft_valid_room(t_list_rooms *lstrooms)
{
	t_list_rooms	*tmp_r1;
	t_list_rooms	*tmp_r2;
	int				i;

	tmp_r1 = lstrooms;
	i = 0;
	while ((tmp_r1->name)[i])
		if ((tmp_r1->name)[i++] == '-' || (tmp_r1->name)[0] == 'L')
			return (-1);
	tmp_r2 = tmp_r1->next;
	while (tmp_r2)
	{
		if ((!ft_strcmp(tmp_r1->name, tmp_r2->name))
			|| (tmp_r1->x == tmp_r2->x && tmp_r1->y == tmp_r2->y))
			return (-1);
		tmp_r2 = tmp_r2->next;
	}
	return (0);
}
