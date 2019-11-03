
#include "fdf.h"

void		ft_check_line(char *line)
{
	int		i;

	i = 0;
	if (line[i] == '\0')
		ft_error("FDF: line empty.");
	while (line[i] && line[i] != ',')
	{
		if (ft_isalpha(line[i]) && line[i] != ' ' &&
				!ft_isdigit(line[i]))
			ft_error("FDF: Invalid character.");
		i++;
	}
}

static void	ft_checkfile2(t_data *data, char **tab, int i)
{
	int j;

	j = -1;
	data->width = ft_count_tab(tab);
	data->p[i] = (t_point *)malloc(sizeof(t_point) * data->width);
	while (tab[++j])
	{
		data->p[i][j].value = ft_atoi(tab[j]);
		if (data->p[i][j].value == 0)
			data->p[i][j].color = 0xFF0000;
		else
			data->p[i][j].color = 0xFFFF00;
		data->p[i][j].x = j * data->zoom + H / 3;
		data->p[i][j].y = i * data->zoom + V / 3;
	}
	free_twod(tab);
}

static void	ft_check_file(int fd, t_data *data)
{
	char	*line;
	char	**tab;
	int		i;

	data->p = (t_point **)malloc(sizeof(t_point *) * data->hight);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_check_line(line);
		if (!(tab = ft_strsplit(line, ' ')))
			ft_error("FDF: problem in content.");
		ft_zoom(data, tab);
		ft_checkfile2(data, tab, i);
		ft_strdel(&line);
		i++;
	}
	if (!i)
		ft_error("FDF: file empty. or Permission denied or file Not found");
}

int			ft_count_lines(char *file)
{
	char	*line;
	char	**splt;
	int		counter;
	int		x;
	int		fd;

	counter = 0;
	x = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(splt = ft_strsplit(line, ' ')))
			ft_error("FDF: problem in content.");
		if (x == 0)
			x = ft_count_tab(splt);
		if (ft_count_tab(splt) < x)
			ft_error("incorrect file lines len!");
		ft_strdel(&line);
		free_twod(splt);
		counter++;
	}
	close(fd);
	return (counter);
}

void		ft_check(char *name, t_data *data)
{
	int		fd;

	if (!(fd = open(name, O_RDONLY)))
		ft_error("FDF: can't open file.");
	data->hight = ft_count_lines(name);
	data->v = name;
	ft_check_file(fd, data);
}
 