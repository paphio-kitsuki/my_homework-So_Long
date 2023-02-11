#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_window
{
	void	*mlx;
	void	*win;
}			t_window;


int	exit_func(int button, t_window *param)
{
	printf("%d\n", button);
	mlx_destroy_display(param->mlx);
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
}

int	main()
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, 500, 500, "mlx 42");
	//mlx_mouse_hook(window->win, exit_func, window);
	mlx_hook(window->win, 17, 0, exit_func, window);
	mlx_loop(window->mlx);
	free(window);
}
