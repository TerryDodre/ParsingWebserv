#ifndef PARSING_HPP
# define PARSING_HPP

# define BLACK   "\033[1m\033[30m"	/* Bold Black */
# define RED     "\033[1m\033[31m"	/* Bold Red */
# define GREEN   "\033[1m\033[32m"	/* Bold Green */
# define YELLOW  "\033[1m\033[33m"	/* Bold Yellow */
# define BLUE    "\033[1m\033[34m"	/* Bold Blue */
# define MAGENTA "\033[1m\033[35m"	/* Bold Magenta */
# define CYAN    "\033[1m\033[36m"	/* Bold Cyan */
# define WHITE   "\033[1m\033[37m"	/* Bold White */
# define RESET   "\033[0m"

#include <iostream>
#include <list>
#include <fstream>

typedef struct				s_config
{
	std::string				host;
	std::string				port;
	std::string				server_name;
	std::string				root;
	std::string				default_error_page;
	size_t					body_size_limit;
	std::list<std::string>	index;
	// std::list<t_location>	locations;
}							t_config;

class Parsing
{
private:
	int						_nb_server;
	std::list<t_config>		_config;
	Parsing(void);
public:
	Parsing(char *argv);
	~Parsing(void);
	void	start_parsing(char *argv);
	void	default_config(void);
	void	parse_config(std::string line, t_config conf);
	// UTILS
	bool	check_line(std::string const &line, std::string const &comp);
	// GETTERS
};

#endif