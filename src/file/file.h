#ifndef		FILE_H
# define	FILE_H

typedef struct	s_resolution {
    unsigned short  width;
    unsigned short  height;
}				t_resolution;

typedef struct	s_texture {
    unsigned int*			data;
    t_resolution	resolution;
}				t_texture;

typedef struct	s_file
{
	t_resolution	resolution;
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
	t_texture		sprite;
	t_texture		floor;
	t_texture		ceil;
	unsigned char	**map;
}				t_file;

int		init_file(char *path, t_file *file);
#endif