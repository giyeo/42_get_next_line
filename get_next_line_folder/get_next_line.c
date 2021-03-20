#include "get_next_line.h"

static char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s) + 1;
	dup = malloc(len * sizeof(char));
	if (dup)
		ft_memcpy(dup, s, len);
	return (dup);
}

static void			ft_strdel(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
}

static size_t			get_next_end(char *statico)
{
	size_t i;

	i = 0;
	while (statico[i] != '\n' && statico[i] != '\0')
		i++;
	if (statico[i] == 0)
		return i;
	return i - 1;
}

static int			get_next_return(int n, char **statico, char **line)
{
	char *temp;

	temp = NULL;
	*line = ft_substr(*statico, 0, get_next_end(*statico));
	if (line == 0 || n < 0)
		return ERROR;
	if (ft_strchr(*statico, '\n') != 0)
	{
		temp = ft_strdup(ft_strchr(*statico, '\n') + 1);
		ft_strdel(statico);
		*statico = temp;
		return EOL;
	}
	ft_strdel(statico);
	return FT_EOF;
}

int			get_next_line(int fd, char **line)
{
	static char		*statico;
	char			*buffer;
	int				nbytes;

	if (statico == 0)
		statico = ft_strdup("");
	if (BUFFER_SIZE <= 0)
		return ERROR;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == 0 || fd < 0 || line == 0)
		return ERROR;
	while ((nbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nbytes] = '\0';
		statico = ft_strjoin(statico, buffer);
		if (ft_strchr(statico, '\n') != 0)
			break;
	}
	ft_strdel(&buffer);
	return (get_next_return(nbytes, &statico, line));
}
/*
int    main(void)
{
    int fd;
    char *linha;
    int i;
    int retorno;

    i = 0;
    // fd = 123;
    fd = open("2.txt", O_RDONLY);
    retorno = 1;
    while (retorno == 1)
    {
        retorno = get_next_line(fd, &linha);
        if (retorno != 1)
            break;
        printf("1: linha[%d] = '%s'(%ld); retorno = %i\n", i, linha, ft_strlen(linha), retorno);
        free(linha);
        i++;
        // break;
    }
    if (retorno != -1)
    {
        printf("2: linha[%d] = '%s'(%ld); retorno = %i\n", i, linha, ft_strlen(linha), retorno);
        free(linha);
    }
    else
        printf("get_next_line retornou -1\n");
    return (0);
}*/
