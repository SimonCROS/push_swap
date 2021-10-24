#include <iostream>
#include <getopt.h>
#include <algorithm>
#include <vector>
#include <string>
#include <sys/stat.h>

using namespace std;

static struct option long_options[] =
{
    {"sorted", no_argument, NULL, 's'},
    {NULL, 0, NULL, 0}
};

int main(int argc, char **argv)
{
	bool sorted;
	int ch;

	while ((ch = getopt_long(argc, argv, "s", long_options, NULL)) != -1)
	{
		switch (ch)
		{
			case 's':
				sorted = true;
				break;
		}
	}
	argc -= optind;
	argv += optind;

	if (argc < 2 || argc > 4)
		return EXIT_FAILURE;

	size_t end;
	struct stat  st;

	try
	{
		string push_swap = "./push_swap";

		if (stat("./push_swap", &st) < 0)
			return EXIT_FAILURE;
		if ((st.st_mode & S_IEXEC) == 0 ||
			(st.st_mode & S_IFREG) == 0)
			return EXIT_FAILURE;

		int numbers = stoi(argv[0], &end);
		if (*(argv[0] + end) != 0 || numbers < 0)
			return EXIT_FAILURE;

		int iterations = stoi(argv[1], &end);
		if (*(argv[1] + end) != 0 || iterations < 1)
			return EXIT_FAILURE;

		int objective = -1;
		if (argc >= 3)
		{
			objective = stoi(argv[2], &end);
			if (*(argv[2] + end) != 0 || objective < 0)
				return EXIT_FAILURE;
		}

		string checker;
		if (argc >= 4)
		{
			checker = argv[3];

			if (stat(argv[3], &st) < 0)
				return EXIT_FAILURE;
			if ((st.st_mode & S_IEXEC) == 0 ||
				(st.st_mode & S_IFREG) == 0)
				return EXIT_FAILURE;
		}

		cout << numbers << " | " << iterations << " | " << objective << " | " << checker << endl;
	}
	catch (std::invalid_argument& e)
	{
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
