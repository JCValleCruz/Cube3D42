void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_findplayer(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_finalgg_ok(game);
	else if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
		move_player(game, game->playerx, game->playery - 1);
	else if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS))
		move_player(game, game->playerx, game->playery + 1);
	else if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
		move_player(game, game->playerx - 1, game->playery);
	else if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		move_player(game, game->playerx + 1, game->playery);
}