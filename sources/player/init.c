/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:18:33 by ahallain          #+#    #+#             */
/*   Updated: 2020/10/21 18:52:42 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

float			degree(char c)
{
	if (c == 'E')
		return (90);
	if (c == 'S')
		return (180);
	if (c == 'W')
		return (270);
	return (0);
}

unsigned char	init_player(char **map, t_player *player)
{
	unsigned short x;
	unsigned short y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N'
				|| map[y][x] == 'S'
				|| map[y][x] == 'W'
				|| map[y][x] == 'E')
			{
				if (player->updated)
					return (4);
				*player = (t_player) {degree(map[y][x]),
					{x + 0.5, y + 0.5, 0}, 0, 0, true};
			}
			x++;
		}
		y++;
	}
	return (player->updated ? 0 : 4);
}
