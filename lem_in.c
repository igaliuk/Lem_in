/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:24:00 by igaliuk           #+#    #+#             */
/*   Updated: 2018/02/20 12:53:40 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_zero(t_input_data *input_data)
{
	input_data->inst = NULL;
	input_data->nor = 0;
	input_data->count.start = 0;
	input_data->count.fin = 0;
	input_data->lstrooms = NULL;
	input_data->arrlinks = NULL;
	input_data->lstways = NULL;
	input_data->arrways = NULL;
}

void	ft_print_inst(t_list *inst)
{
	t_list	*tmp;

	write(1, "\e[1;35mINSTRUCTIONS\n\e[0m", 24);
	tmp = inst;
	while (tmp)
	{
		ft_printf("%s\n", (char *)(tmp->content));
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

void	ft_print_ways(t_input_data input_data)
{
	int		i;
	int		j;

	write(1, "\e[1;33mBEST WAYS\n\e[0m", 21);
	i = 0;
	while ((input_data.arrways)[i])
	{
		j = 0;
		while ((input_data.arrways)[i][j])
			ft_printf("%s-", ft_name_room((input_data.arrways)[i][j++],
											input_data.lstrooms));
		ft_printf("%s\n", ft_name_room(0, input_data.lstrooms));
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_case(int noa, t_list_rooms *lstrooms)
{
	int		i;

	i = 0;
	while (i < noa)
	{
		if (i)
			write(1, " ", 1);
		ft_printf("L%d-%s", i + 1, ft_name_room(0, lstrooms));
		i++;
	}
	write(1, "\n", 1);
}

int		main(void)
{
	t_input_data	input_data;
	t_list_1way		*tmp;

	ft_zero(&input_data);
	ft_read_inst(&input_data);
	if (!(input_data.lstrooms) || !(input_data.arrlinks))
		ft_error(&input_data);
	tmp = NULL;
	ft_finding_way(&input_data, &tmp, 1);
	if (!(input_data.lstways)
		|| !(input_data.arrways = (int **)malloc(sizeof(int *)
			* (ft_number_ways(input_data.lstways) + 1))))
		ft_error(&input_data);
	ft_processing_ways(&input_data);
	ft_print_inst(input_data.inst);
	ft_print_ways(input_data);
	write(1, "\e[1;32mRESAULTS\n\e[0m", 20);
	if (!(input_data.arrways[0][0]))
		ft_print_case(input_data.noa, input_data.lstrooms);
	else
		ft_starting_ants(&input_data);
	ft_free_input_data(&input_data);
	return (0);
}
