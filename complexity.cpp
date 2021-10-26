#include <iostream>
#include <getopt.h>
#include <algorithm>
#include <vector>
#include <random>
#include <string>
#include <iterator>
#include <numeric>
#include <sys/stat.h>
#include <signal.h>
#include <optional>
#include <boost

using namespace std;

struct program_opts
{
	bool	help;
	bool	sorted;
};

struct program_params
{
	string				program;
	int					numbers;
	int					iterations;
	optional<int>		objective;
	optional<string>	checker;
};

static const string getHelp()
{
	string help;

	help += "\033[1;31mUsage :\n";
	help += "\033[1;30m./complexity [-h|--help]\033[0m\n";
	help += "\033[1;30m./complexity [-s|--sorted] <nb_item> <nb_iter> [goal] [checker]\033[0m";
	return help;
}

static const string& assertExecutable(const string& path)
{
	struct stat  st;

	if (stat(path.c_str(), &st) < 0 ||
		(st.st_mode & S_IEXEC) == 0 ||
		(st.st_mode & S_IFREG) == 0)
		throw invalid_argument(path + " is not a valid file");
	return path;
}

static int parseNumber(string str, int min)
{
	size_t end;
	int number;

	try
	{
		number = stoi(str.c_str(), &end);
		if (str.length() > end != 0)
			throw invalid_argument(str + " is not a valid number");
	}
	catch(const exception& e)
	{
		throw invalid_argument(str + " is not a valid number");
	}
	if (number < min)
		throw invalid_argument(str + " must be greater than " + to_string(min));
	return number;
}

static struct program_opts getOptions(int& argc, char **&argv)
{
	static struct option long_options[] =
	{
		{"help", no_argument, NULL, 'h'},
		{"sorted", no_argument, NULL, 's'},
		{NULL, 0, NULL, 0}
	};

	program_opts opts;

	int ch;
	while ((ch = getopt_long(argc, argv, "hs", long_options, NULL)) != -1)
	{
		switch (ch)
		{
			case 'h':
				opts.help = true;
				break;
			case 's':
				opts.sorted = true;
				break;
		}
	}
	argc -= optind;
	argv += optind;

	return opts;
}

static struct program_params getParameters(int argc, char **argv)
{
	program_params params;

	if (argc < 2 || argc > 4)
		throw invalid_argument(getHelp());
	params.program = assertExecutable("./push_swap");
	params.numbers = parseNumber(argv[0], 0);
	params.iterations = parseNumber(argv[1], 1);
	if (argc >= 3)
		params.objective = parseNumber(argv[2], 0);
	if (argc >= 4)
		params.checker = assertExecutable(argv[3]);
	return params;
}

static void hideCursor()
{
	cout << "\e[?25l";
}

static void showCursor()
{
	cout << "\e[?25h";
}

int main(int argc, char **argv)
{
	program_opts opts;
	program_params params;

	opts = getOptions(argc, argv);
	if (opts.help)
	{
		cout << getHelp() << endl;
		return (EXIT_SUCCESS);
	}

	try
	{
		params = getParameters(argc, argv);
	}
	catch (const invalid_argument& e)
	{
		cerr << e.what() << endl;
		return EXIT_FAILURE;
	}

	signal(SIGINT, (void (*)(int))showCursor);
	
	auto rd = std::random_device {}; 
	auto rng = std::default_random_engine { rd() };

	for (int i = 0; i < params.iterations; i++)
	{
		vector<int> nums(params.numbers);
		vector<string> args;
		vector<char*> cargs;

		iota(begin(nums), end(nums), 0);
		std::shuffle(nums.begin(), nums.end(), rng);
		std::transform(nums.begin(), nums.end(), std::back_inserter(args), [](int d) {
				return std::to_string(d);
			}
		);

        for(string& arg : args)
            cargs.push_back(&arg.front());

		


		// copy(args.begin(), args.end(), ostream_iterator<string>(cout, "\n"));
	}

	// hideCursor();
	// sleep(2);
	// showCursor();

	return EXIT_SUCCESS;
}
