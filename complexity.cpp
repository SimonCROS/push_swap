#include <iostream>
#include <getopt.h>
#include <algorithm>
#include <vector>
#include <array>
#include <random>
#include <string>
#include <iterator>
#include <numeric>
#include <sys/stat.h>
#include <signal.h>
#include <optional>

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

	help += "\033[91mUsage :\n";
	help += "\033[90m./complexity [-h|--help]\033[0m\n";
	help += "\033[90m./complexity [-s|--sorted] <nb_item> <nb_iter> [goal] [checker]\033[0m";
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

	program_opts opts = {false};

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

static std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

static void print(program_params params, int done, int total, int best, int worst, int successful, int ok)
{
	cout << "Pire = \033[31m" << (worst) << "\033[0m instructions" << endl;
	cout << "Moyenne = \033[33m" << (total / done) << "\033[0m instructions" << endl;
	cout << "Meilleur = \033[36m" << (best) << "\033[0m instructions" << endl;
	if (params.objective.has_value())
		cout << "Objectif = \033[94m" << (successful * 100 / done) << "\033[0m % sous \033[94m" << (params.objective.value()) << "\033[0m (\033[91m" << (done - successful) << "\033[0m au dessus)   " << endl;
	else
		cout << "Objectif = entrez un nombre en troisième argument" << endl;
	if (params.checker.has_value())
		cout << "Précision = \033[97m" << (ok * 100 / done) << "\033[0m % OK (\033[91m" << (done - ok) << "\033[0m KO)   " << endl;
	else
		cout << "Précision = entrez un testeur en quatrième argument" << endl;
	cout << "\033[32m" << (done * 100 / params.iterations) << "\033[0m % effectué" << endl;
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

	atexit([]() {
		showCursor();
		cout << "\033[6B\033[0m";
	});
	signal(SIGINT, [](int s) {
		exit(EXIT_SUCCESS);
	});
	
	auto rd = std::random_device {}; 
	auto rng = std::default_random_engine { rd() };

	int done = 0;
	int worst = 0;
	int best = -1;
	int	total = 0;
	int successful = 0;
	int ok = 0;

	hideCursor();
	cout << "\033[97mDémarrage du test : \033[95m" << params.numbers << "\033[97m éléments, \033[95m" << params.iterations << "\033[97m itérations" << endl;
	while (done < params.iterations)
	{
		vector<int> nums(params.numbers);
		vector<string> args;

		iota(begin(nums), end(nums), 0);
		if (!opts.sorted)
			std::shuffle(nums.begin(), nums.end(), rng);
		std::transform(nums.begin(), nums.end(), std::back_inserter(args), [](int d) {
				return std::to_string(d);
			}
		);
		std::string command = params.program;
		for (const string &piece : args)
			command += " " + piece;

        string result = exec(command.c_str());
		int lines = std::count(result.begin(), result.end(), '\n');

		done++;
		total += lines;

		if (lines <= params.objective.value_or(-1))
			successful++;
		if (lines < best || best == -1)
			best = lines;
		if (lines > worst)
			worst = lines;

		print(params, done, total, best, worst, successful, 0);
		cout << "\033[6A";
	}
	return EXIT_SUCCESS;
}
