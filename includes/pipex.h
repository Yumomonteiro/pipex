/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:15:38 by yude-oli          #+#    #+#             */
/*   Updated: 2024/02/02 16:29:43 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/libft/libft.h"
//funcs
void	error(void);
void	execute_cmd(char **argv, char **env);
char	*find_path(char *cmd, char **env);
#endif