/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:25:33 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/01 16:30:07 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
    pid_t pid = fork();

    if (pid == 0) {
        char *clearArgs[] = {"clear", NULL};
        execvp("clear", clearArgs);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
    } else {
        waitpid(pid, NULL, 0);
    }
}


int main(void)
{
    char *input;
    char *current_path;
    char path[1024];

    rl_on_new_line();
    
    while (1)
    {
        current_path = ft_get_current_path();
        input = readline(current_path);
        add_history(input);
        getcwd(path, 1024);

        if (strcmp(input, "pwd") == 0)
            printf("%s\n", path);
        else if (strcmp(input, "clear") == 0)
            clearScreen();
        else
            handle_change_dir(input);
    }

    return 0;
}
