/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:38:16 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/13 20:44:18 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_printf(const char *format, ...);

int main (void)
{
	char *sapo = "chimpacho";
	int mine;
	int org;
	
	mine = ft_printf("yo: %33s, capullo, %4s, calamita\n", sapo, "acuña");
	org = printf("og: %33s, capullo, %4s, calamita\n", sapo, "acuña");
	printf ("mine: %i,   org: %i\n", mine, org);
}