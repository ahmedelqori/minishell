/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:30:40 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/02 15:05:14 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

pid_t PID;

void handle_sig_int(int sig)
{
	(void)sig;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sig_int);
}


int main(int ac, char **av, char **env)
{
	char 	*input;
	char	*prompt_msg;
	(void )ac;
	(void)av;
	PID = fork();
	if (PID == 0)
		exit(0);
	while (TRUE)
	{
		handle_signals();
		prompt_msg = prompt(env);
		input = readline(prompt_msg);
		if (input == NULL)
			exit(1);
		history(input);
	} 
	 rl_clear_history();
}
