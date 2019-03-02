make an if(!fork()) within the one currently in beejs and execute the commands cat, cut and sort in that order

fd[2]
fd2[2]

pipe(fd)
if (!fork()){
	pipe(fd2)
	if (!fork()){//chld2
		close(fd2[1]);
		dup2(fd2[0],0)
		close(fd2[0]);
		close(fd[1]);
		close(fd[0]);
		execlp("wc", "wc", "-l", NULL);
	} else {//chld1
		close(fd[1]);
		dup2(fd[0],0);
		close(fd[0]);
		close(fd2[0]);
		dup2(fd2[1],1);
		close(fd2[1]);
		execlp("grep", "grep", "/bin/bash$", NULL);
	} 
} else {//prnt
	close(fd[0]);
	dup2(fd[1],1);
	close(fd[1]);
	execlp("cat", "cat", "/etc/passwd", NULL);
}




I MAY HAVE CLOSED SOMETHING TOO EARLY ___CHECK
