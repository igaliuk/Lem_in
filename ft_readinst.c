/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readinst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 08:27:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/25 08:27:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_read_inst(t_input_data *input_data)
{
	t_list	*tmp;
	char	*line;
	int		start_end;

	start_end = 0;
	while (get_next_line(0, &line) > 0)
	{
		if ((start_end = ft_analis_line(line, input_data, start_end)) == -1)
		{
			ft_strdel(&line);
			break ;
		}
		if ((tmp = ft_lstnew(NULL, 0)) == NULL)
			ft_error(input_data);
		tmp->content = ft_strdup(line);
		ft_lstaddback((&(input_data->inst)), tmp);
		ft_strdel(&line);
	}
}

int		ft_analis_line(char *line, t_input_data *input_data, int start_end)
{
	static int		k = 0;

	if (k == 0 && (input_data->noa = ft_atoi_li(line, input_data)) > 0)
	{
		k = 1;
		return (0);
	}
	if (k == 1 && !start_end && !ft_strcmp(line, "##start")
		&& (input_data->count.start)++ < 1)
		return (2);
	if (k == 1 && !start_end && !ft_strcmp(line, "##end")
		&& (input_data->count.fin)++ < 1)
		return (1);
	if (k == 1 && !ft_mask_rooms_links(line, 'r')
		&& !ft_processing_rooms(line, input_data, start_end))
		return (0);
	if (k <= 2 && input_data->count.start == 1 && input_data->count.fin == 1
		&& !ft_mask_rooms_links(line, 'l') && (k = 2)
		&& !ft_processing_links(line, input_data))
		return (0);
	if (line[0] == '#' && ft_strcmp(line, "##start")
		&& ft_strcmp(line, "##end"))
		return (start_end);
	return (-1);
}

int		ft_mask_rooms_links(char *str, char c)
{
	int		i;

	i = 0;
	if (c == 'r')
	{
		while (str[i] && str[i] != ' ')
			i++;
		if (i < 1 || str[i] != ' ')
			return (-1);
		i++;
		while (str[i] && str[i] != ' ')
			i++;
		if (str[i] != ' ')
			return (-1);
	}
	if (c == 'l')
	{
		while (str[i] && str[i] != '-')
			i++;
		if (i < 1 || str[i] != '-')
			return (-1);
	}
	return (0);
}
