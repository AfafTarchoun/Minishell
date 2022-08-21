/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:49:22 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/21 21:52:52 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int main(int argc, char **argv)
{
  char *line;
  t_lexer *lexer;
  t_cmd *cmd;
  t_cmd *head;


	if (argc == 2)
	{
		line = strdup(argv[1]);
		printf("\nline is : |%s|\n\n", line);
		lexer = init_lx(line);
		cmd = create_lst_cmd(lexer);
		while (cmd)
		{
			printf("TOKEN (%d, %s, %c)\n", cmd->tok->type, cmd->tok->value, cmd->tok->quote);
			cmd = cmd->next;
		}
	}
  return (0);
}

// int	main(int argc, char **argv)
// {
// 	char *line;
// 	t_lexer *lexer;
// 	t_cmd *cmd;
// 	t_cmd *head;

// 	(void)argc;
// 	(void)argv;
// 	while (1)
// 	{
// 		ft_signals();
// 		line = readline("BomusShell$> ");
//		if (line = NULL)
//			exit(0);
// 		add_history(line);
// 		printf("\nline is : |%s|\n\n", line);
// 		lexer = init_lx(line);
// 		cmd = create_lst_cmd(lexer);
// 		while (cmd)
// 		{
// 			printf("TOKEN (%d, %s, %c)\n", cmd->tok->type, cmd->tok->value, cmd->tok->quote);
// 			cmd = cmd->next;
// 		}
// 		free(line);
// 	}
// }
