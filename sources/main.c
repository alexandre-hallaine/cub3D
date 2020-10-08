/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 20:05:46 by ahallain          #+#    #+#             */
/*   Updated: 2020/10/07 23:37:29 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "file/file.h"
#include "player/player.h"
#include "mlx/mlx1.h"

int     main(int argc, char** argv)
{
	int			ret;
	t_file		file;
	t_player	player;
	t_mlx		mlx;

	ret = 0;
	if (argc == 1)
		ret = 1;
    if (!ret)
		ret = init_file(argv[1], &file) ? 2 : 0;
	if (!ret)
		ret = init_player(file.map, &player);
	if (!ret)
	{
		init_mlx(&file, &mlx, &player);
		loop(*argv + 2, (t_runtime) {file, player, mlx, 0, 0, 0});
	}
	return (error(ret));
}