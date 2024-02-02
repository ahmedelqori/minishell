/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:38:48 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/02 10:16:50 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

char    *get_home_path(char **env)
{
    int i;
    char    *home_path;

    i = 0;
    while (env[i])
    {
        if (ft_strnstr(env[i], "HOME=", 5) != NULL)
        {
           home_path = ft_strdup(env[i] + 5);
           break; 
        }
        i++;
    }
    return (home_path);
}

char    *prompt(char **env)
{
    char    path[1024];
    char    *home_path;
    char    *str;
    int     len;

    str = NULL;
    home_path = get_home_path(env);
    len = ft_strlen(home_path);
    getcwd(path, 1024);
    // path[ft_strlen(path)] = ' ';
    // path[ft_strlen(path) + 1] = '\0';
    if (ft_strnstr(path, home_path, len) != NULL)
        str = ft_strjoin(BOLDYELLOW"MiniShell $>"RESET" ~", path + len );
    else
        str = ft_strjoin(BOLDYELLOW"MiniShell $> " RESET, path);
    free(home_path);
    home_path = str;
    str = ft_strjoin(str, " ");
    free(home_path);
    return (str);
}