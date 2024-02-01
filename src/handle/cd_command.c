/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:56:24 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/01 16:22:29 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void    handle_change_dir(char *s)
{
    char    **str;
    char    path[1024];

    getcwd(path, 1024);
    str = ft_split(s, ' ');
    // printf("%s",str[0]);
    if (ft_strlen(str[0]) == 2 && ft_strncmp(str[0], "cd", 3) == 0)
    {
        if (str[1] == NULL)
            chdir("/home/meedivo");
        else
            chdir(str[1]);
        
    }   
}