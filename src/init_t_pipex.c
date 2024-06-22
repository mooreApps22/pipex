/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_pipex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:08:32 by smoore            #+#    #+#             */
/*   Updated: 2024/06/22 15:38:31 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	validate_args(t_pipex *p, char **av)
{
	if (p->rd < 0)
	{
		if (p->rd < 0 && p->c2.cmd == NULL)
		{
			ft_printf("bash: %s: %s", av[1], E_IN);
			ft_printf("%s: %s", p->c2.args[0], E_CMD);
		}
		else
			ft_printf("bash: %s: %s", av[1], E_IN);
		return ;
	}
	if (p->c1.cmd == NULL)
		ft_printf("%s: %s", p->c1.args[0], E_CMD);
	if (p->c2.cmd == NULL)
		ft_printf("%s: %s", p->c2.args[0], E_CMD);
	return ;
}

void	init_t_pipex(t_pipex *p, int ac, char **av, char **envp)
{
	if (ac != 5)
	{
		wr_error(E_AC);
		exit(EXIT_FAILURE);
	}
	p->rd = open(av[1], O_RDONLY);
	p->c1.cmd = init_t_cmd(&p->c1, av[2], envp);
	p->c2.cmd = init_t_cmd(&p->c2, av[3], envp);
	p->wr = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	validate_args(p, av);
}
