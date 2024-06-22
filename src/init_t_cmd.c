/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:08:32 by smoore            #+#    #+#             */
/*   Updated: 2024/06/21 18:19:44 by smoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*path_finder(char **envp)
{
	int	found_path;
	int	i;

	i = 0;
	found_path = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			found_path = 1;
		i++;
	}
	if (found_path == 0)
		return (NULL);
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	*load_cmd(char **list, char *cmd)
{
	char	*tmp;
	char	*dest;

	while (*list)
	{
		tmp = ft_strjoin(*list, "/");
		dest = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(dest, X_OK) == 0)
			return (dest);
		free(dest);
		list++;
	}
	return (NULL);
}

char	*init_t_cmd(t_cmd *c, char *av, char **envp)
{
	c->paths = path_finder(envp);
	if (!c->paths)
		return (NULL);
	c->list = ft_split(c->paths, ':');
	if (!c->list)
		return (NULL);
	c->args = ft_split(av, ' ');
	if (!c->args)
		return (NULL);
	c->cmd = load_cmd(c->list, c->args[0]);
	if (!c->cmd)
		return (NULL);
	return (c->cmd);
}
