#include "parsing.hpp"

Parsing::Parsing(char *config_file)
{
	_nb_server = 0;
	start_parsing(config_file);
}

Parsing::~Parsing(void)
{
}

void	Parsing::start_parsing(char *config_file)
{
	std::ifstream		fd;
	std::string			line;
	
	fd.open(config_file);
	if (!fd.is_open())
		throw std::string("impossible to open config file");
	while (std::getline(fd, line))
	{
		if (check_line(line, "server{"))
		{
			_nb_server++;
			default_config();
			while (std::getline(fd, line) && line != "}")
				parse_config(line, _config.back());
		}
	}
	fd.close();
	if (_nb_server == 0)
		throw std::string("server block missing");
}

void	Parsing::default_config(void)
{
	t_config conf;

	conf.host = "127.0.0.1";
	conf.port = "80";
	conf.server_name = "Default";
	conf.root = "";
	conf.default_error_page = "";
	conf.body_size_limit = 1;
	_config.push_back(conf);
}

void	Parsing::parse_config(std::string line, t_config conf)
{
	if (check_line(line, "	listen"))
		std::cout << "listen" << std::endl;
}

bool	Parsing::check_line(std::string const &line, std::string const &comp)
{
	unsigned int	start = 0;
	unsigned int	end = comp.size();

	if (line.size() >= start && line.substr(start, end) == comp)
		return true;
	return false;
}