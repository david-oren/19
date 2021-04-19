#include "test.h"

static void	ft_init_ftab(int (**f)(int *, int *))
{
	f[0] = &basics_launcher;
	f[1] = &conv_d_i_launcher;
	f[2] = &conv_u_launcher;
	f[3] = &conv_x_bigx_launcher;
	f[4] = &conv_c_launcher;
	f[5] = &conv_s_launcher;
	f[6] = &conv_p_launcher;
	f[7] = &percent_launcher;
	f[8] = &mixed_launcher;
	f[9] = NULL;
}

static void	ft_init_test_name(char **tab)
{
	tab[0] = strdup("Basic tests");
	tab[1] = strdup("Conv d-i");
	tab[2] = strdup("Conv u");
	tab[3] = strdup("Conv x-X");
	tab[4] = strdup("Conv c");
	tab[5] = strdup("Conv s");
	tab[6] = strdup("Conv p");
	tab[7] = strdup("Percent");
	tab[8] = strdup("Mixed tests");
	tab[9] = NULL;
}

static void	ft_run_tests(t_score **score, int (**f)(int *, int *), char **name)
{
	int		i;
	int		success;
	int		total;

	i = 0;
	while (f[i])
	{
		success = 0;
		total = 0;
		(f[i])(&success, &total);
		ft_save_score(score, name[i], success, total);
		i++;
		ft_putstr("\n\n");
	}
}

int			main(void)
{
	int		(*f[NB_TEST_TYPE + 1])(int *, int *);
	char	*test_name[NB_TEST_TYPE + 1];
	t_score	*score;

	score = NULL;
	ft_init_ftab(f);
	ft_init_test_name(test_name);
	ft_write_title();
	ft_putstr("\n");
	ft_putstr_col("*****************************************\n", B_GREEN, DEF);
	ft_putstr_col("********* PRINTF - PANDACOUSTIC *********\n", B_GREEN, DEF);
	ft_putstr_col("*****************************************\n", B_GREEN, DEF);
	ft_putstr("\n");
	ft_run_tests(&score, f, test_name);
	ft_putstr("");
	ft_putstr_col("*****************************************\n", B_GREEN, DEF);
	ft_putstr_col("**************** RESULT *****************\n", B_GREEN, DEF);
	ft_putstr_col("*****************************************\n", B_GREEN, DEF);
	ft_putstr("\n");
	return (ft_get_final_score(&score));
}
