/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:38:16 by mmonereo          #+#    #+#             */
/*   Updated: 2021/11/15 11:16:25 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_printf(const char *format, ...);

int main (void)
{
	
	int mine;
	int org;
	
	// // // 						STRING
	char *s = "mouli nette";
	mine = ft_printf("yo: %*.*s, %--7s, robot\n", 7, 3, s, "cereals");
	org = printf("og: %*.*s, %--7s, robot\n", 7, 3, s, "cereals");
	printf ("mine: %i,   org: %i\n", mine, org);

	// // // // 						CHAR
	// char *s = "acho";
	// mine = ft_printf("yo: %7c, %-12c, robot\n", s[0], '\0');
	// org = printf("og: %7c, %-12c, robot\n", s[0], '\0');
	// printf ("mine: %i,   org: %i\n", mine, org);

	// 						// INT
	// int var1 = 37;
	// mine = ft_printf("yo: %10.8i, %d, 66\n", var1, 0);
	// 	org = printf("og: %10.8i, %d, 66\n", var1, 0);
	// printf ("mine: %i,   org: %i\n", mine, org);

	// 				// UNSIGNED INT
	// int var2 = 33;
	// mine = ft_printf("yo: %*u, %5.0u, 66\n", 6, var2, -42);
	// 	org = printf("og: %*u, %5.0u, 66\n", 6, var2, -42);
	// printf ("mine: %i,   org: %i\n", mine, org);

	// 						// HEX
	// int var3 = 457;
	// mine = ft_printf("yo: %.6x, %-15X\n",var3, -322);
	// 	org = printf("og: %.6x, %-15X\n",var3, -322);
	// printf ("mine: %i,   org: %i\n", mine, org);

	// 					//	POINTER
	// int *var4 = 0;
	// // char c = 'f';
	// mine = ft_printf("yo: %p, %p\n",&var4, NULL);
	// 	org = printf("og: %p, %p\n",&var4, NULL);
	// printf ("mine: %i,   org: %i\n", mine, org);

	// 	// // 						PERCENT
	// mine = ft_printf("yo: %7%, %012%, calamita\n");
	// org = printf("og: %7%, %012%, calamita\n");
	// printf ("mine: %i,   org: %i\n", mine, org);

							// INT	MAX
	// int var5 = -2147483648;
	// mine = ft_printf("yo: %030d, 66\n", var5);
	// 	org = printf("og: %030d, 66\n", var5);
	// printf ("mine: %i,   org: %i\n", mine, org);

	// system("leaks a.out");
	// getchar();
}
