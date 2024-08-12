#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; argv[i]; i++)
		{
			for (size_t j = 0; argv[i][j]; j++)
			{
				argv[i][j] = std::toupper(argv[i][j]);
				std::cout << argv[i][j];
			}
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
