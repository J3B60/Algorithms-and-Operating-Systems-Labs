#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	/* cat /etc/passwd | cut -f1 -d: | sort */

	int pfds[2]; /* pipe takes pair of file desciptors (start and end to read) */
	int ppfds[2]; /*therefore need two since two pipes*/

	pipe(pfds);//Two pipes
	
	if (!fork()) {//3 forks
		pipe(ppfds);
		if (!fork()){
			close(1);	/* close normal stdout */
			dup(pfds[1]);	/* make stdout same as pfds[1]  */
			close(pfds[0]);	/* we don't need this */
			close(ppfds[1]);
			close(ppfds[0]);
			execlp("/bin/cat", "/bin/cat", "/etc/passwd", NULL);
		} else {
			close(0);	/* close normal stdin */
			dup(pfds[0]);	/* make stdin same as pfds[0]  */
			close(pfds[1]);	/* we don't need this */
			close(1);
			dup(ppfds[1]);
			close(ppfds[0]);
			execlp("/usr/bin/cut", "/usr/bin/cut", "-f1", "-d:", NULL);
		}
	} else {//parent
		close(0);	/* close normal stdin */
		close(pfds[1]);
		close(pfds[0]);
		dup(ppfds[0]);	/* make stdin same as pfds[0] */
		close(ppfds[1]);	/* we don't need this */
		execlp("/usr/bin/sort", "/usr/bin/sort",  NULL);
	}
	
	return 0;
}
