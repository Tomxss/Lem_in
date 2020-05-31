/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 09:47:42 by tcoetzee          #+#    #+#             */
/*   Updated: 2020/05/31 05:54:38 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int	main(int argc, char **argv)
{
	t_lemin	l;

	init_ants(&l);						
	handle_flags(argc, argv, &l);	
	read_map(&l);						
	remove_useless_paths(&l);			
	if (l.debug == 1)			
		print_debug(&l);		
	else						
		resolve(&l);			
	ft_putendl(l.string_file);
	create_ant_result(&l);		
	get_ants(&l);
	free_at_end(&l);
	free_result(&l);
	return (0);
}
