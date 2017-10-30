
#include <iostream>

int		main(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac > 1)
		{
			while (av[++i])
			{
				j = -1;
				while (av[i][++j])
					if (av[i][j] >= 'a' && av[i][j] <= 'z')
						std::cout << (char)(av[i][j] - 32);
					else
						std::cout << (char)(av[i][j]);
				if (av[i + 1])
					std::cout << " ";
			}
		}
	return 0;
}
