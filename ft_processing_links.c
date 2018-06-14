/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proccessing_links.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:12:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/26 13:12:00 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_processing_links(char *line, t_input_data *input_data)
{
	int				i;
	int				j;

	if (!(input_data->arrlinks))
		ft_processing_links_malloc(input_data);
	if ((i = ft_finddash(line, input_data->lstrooms, 0)) == -1
		|| (j = ft_finddash(line, input_data->lstrooms, 1)) == -1
		|| i == j)
		return (-1);
	(input_data->arrlinks)[i][j] = 1;
	(input_data->arrlinks)[j][i] = 1;
	return (0);
}

void	ft_processing_links_malloc(t_input_data *input_data)
{
	int				i;
	int				j;

	if (!(input_data->arrlinks = (int **)malloc(sizeof(int *)
		* input_data->nor)))
		ft_error(input_data);
	i = 0;
	while (i < input_data->nor)
	{
		if (!((input_data->arrlinks)[i] = (int *)malloc(sizeof(int)
			* input_data->nor)))
			ft_error(input_data);
		j = 0;
		while (j < input_data->nor)
			(input_data->arrlinks)[i][j++] = 0;
		i++;
	}
}

int		ft_finddash(char *src, t_list_rooms *lstrooms, int k)
{
	static int		start;
	t_list_rooms	*tmp_r;

	if (!k)
		start = 0;
	tmp_r = lstrooms;
	while (tmp_r)
	{
		if (!ft_strncmp(src + start, tmp_r->name, ft_strlen(tmp_r->name)))
		{
			start += ft_strlen(tmp_r->name) + 1;
			if ((!k && src[start - 1] != '-') || (k && src[start - 1]))
				return (-1);
			return (tmp_r->id);
		}
		tmp_r = tmp_r->next;
	}
	return (-1);
}
