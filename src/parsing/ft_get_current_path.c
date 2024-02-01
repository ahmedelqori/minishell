/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_current_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:28:38 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/01 15:49:19 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *ft_get_current_path(void)
{
    char    path[1024];
    char    *current_path;
    int     size;
    int     length;
    int     check;

    length = 0;
    check = 0;
    getcwd(path, 1024);
    if (ft_strnstr(path ,HOME_PATH, 14 ) != NULL)
    {
        check = 1;
        length += 2; 
    }
    size = ft_strlen(path);
    path[size] = '\t';
    path[size + 1]  = '\0';
    if (check)
        current_path = ft_strjoin(BOLDGREEN"Minishell$> "RESET"~/", (path + 14));
    else
        current_path = ft_strjoin(BOLDGREEN"Minishell$> "RESET, path);
    return current_path;
}