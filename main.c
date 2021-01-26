/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:38:16 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/26 11:11:52 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_printf(const char *format, ...);

int main (void)
{
	
	int mine;
	int org;
	
	// // 						STRING
	// char *sapo = "chimpacho";
	// mine = ft_printf("yo: %7.4s, capullo, %-12.12s, calamita\n", sapo, "acuña");
	// org = printf("og: %7.4s, capullo, %-12.12s, calamita\n", sapo, "acuña");
	// printf ("mine: %i,   org: %i\n", mine, org);

	// // 						CHAR
	char *sapo = "chimpacho";
	mine = ft_printf("yo: %7c, capullo, %-12c, calamita\n", sapo[0], '\0');
	org = printf("og: %7c, capullo, %-12c, calamita\n", sapo[0], '\0');
	printf ("mine: %i,   org: %i\n", mine, org);

							// INT
	// int var = 33;
	// mine = ft_printf("yo: %*i, %5.0d, 66\n", 6, var, 0);
	// 	org = printf("og: %*i, %5.0d, 66\n", 6, var, 0);
	// printf ("mine: %i,   org: %i\n", mine, org);

					// UNSIGNED INT
	// int var = 33;
	// mine = ft_printf("yo: %*u, %5.0u, 66\n", 6, var, -42);
	// 	org = printf("og: %*u, %5.0u, 66\n", 6, var, -42);
	// printf ("mine: %i,   org: %i\n", mine, org);

					//		HEX
	// int var = 457;
	// mine = ft_printf("yo: %.6x, %-15X\n",var, -322);
	// 	org = printf("og: %.6x, %-15X\n",var, -322);
	// printf ("mine: %i,   org: %i\n", mine, org);

						//	POINTER
	// int var = 457;
	// char c = 'f';
	// mine = ft_printf("yo: %20p, %-14p\n",&var, &c);
	// 	org = printf("og: %20p, %-14p\n",&var, &c);
	// printf ("mine: %i,   org: %i\n", mine, org);

		// // 						PERCENT
	// mine = ft_printf("yo: %7%, %012%, calamita\n");
	// org = printf("og: %7%, %012%, calamita\n");
	// printf ("mine: %i,   org: %i\n", mine, org);

							// INT	MAX
	// int var = -2147483648;
	// mine = ft_printf("yo: %030d, 66\n", var);
	// 	org = printf("og: %030d, 66\n", var);
	// printf ("mine: %i,   org: %i\n", mine, org);
}
