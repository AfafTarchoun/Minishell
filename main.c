/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:49:22 by atarchou          #+#    #+#             */
/*   Updated: 2022/08/22 09:59:37 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	main(int argc, char **argv)
{
	char	*line;
	t_lexer	*lexer;
	t_cmd	*cmd;
	t_cmd	*head;

	if (argc == 2)
	{
		line = ft_strdup(argv[1]);
		lexer = init_lx(line);
		cmd = create_lst_cmd(lexer);
		head = cmd;
		fix_quotes(&cmd);
		cmd = head;
		printf("final : |");
		while (cmd)
		{
			printf("%s", cmd->tok->value);
			// printf("TOKEN (%d, %s, %c)\n", cmd->tok->type, cmd->tok->value, cmd->tok->quote);
			cmd = cmd->next;
		}
		printf("|\n");
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
// 		if (line == NULL)
// 			exit(0);
// 		add_history(line);
// 		lexer = init_lx(line);
// 		cmd = create_lst_cmd(lexer);
// 		head = cmd;
// 		fix_quotes(&cmd);
// 		cmd = head;
// 		printf("final : |");
// 		while (cmd)
// 		{
// 			printf("%s", cmd->tok->value);
// 			// printf("TOKEN (%d, %s, %c)\n", cmd->tok->type, cmd->tok->value, cmd->tok->quote);
// 			cmd = cmd->next;
// 		}
// 		printf("|\n");
// 		free(line);
// 	}
// }
