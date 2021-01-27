/* In this header are macros tho facilitate debugging */
#ifndef DEBUG_H
# define DEFBUG_H

# include <stdio.h>
# include <ctype.h>

# define BOLD				"\033[1m"
# define BLACK				"\033[30m"
# define RED				"\033[31m"
# define GREEN				"\033[32m"
# define YELLOW				"\033[33m"
# define BLUE				"\033[34m"
# define MAGENTA			"\033[35m"
# define CYAN				"\033[36m"
# define WHITE				"\033[37m"
# define ORANGE				"\033[38;5;202m"

# define ANSI_RESET			"\033[0m"

# define DEBUG(msg,...) fprintf(stderr, BOLD GREEN"[LOG](%s:%d)" RED msg ANSI_RESET"\n" , __FILE__, __LINE__, ##__VA_ARGS__)

void _intp		(int *ptr,	size_t len)	{size_t i; i = 0;while (i < len) {printf("%d\n", ptr[i]); i++;};}
void _boolp	(bool *ptr, size_t len)	{size_t i; i = 0;while (i < len) {ptr[i] == true ? printf("True\n") : printf("False\n"); i++;}}
void _defp		(void *ptr, size_t len)	{DEBUG("PRINTING WITH UNDEFINED TYPE (likely char *, use printf instead)");}


# define _PRINT_1D(array, size) _Generic((array),\
	int		*: _intp_  ((int  *) array, size),\
	bool	*: _boolp_ ((bool *) array, size),\
	default	 : _defp_  (array, size))

#endif