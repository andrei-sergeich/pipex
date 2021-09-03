#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

int	main(int argc, char *argv[])
{
	// 5 => 5 * 4 = 20 => 20
	int	p1[2]; // C => P
	int	p2[2]; // P => C
	int	pid;

	if (pipe(p1) == -1)
		ft_error("Error pipe 1");
	if (pipe(p2) == -1)
		ft_error("Error pipe 2");
	pid = fork();
	if (pid == -1)
		ft_error("Error fork");
	if (pid == 0)
	{
		//Child process
		close(p1[0]);
		close(p2[1]);
		int	x;
		if (read(p2[0], &x, sizeof(x)) == -1)
			ft_error("Error read");
		printf("Received %d\n", x);
		x *= 4;
		if (write(p1[1], &x, sizeof(x)) == -1)
			ft_error("Error write");
		printf("Wrote %d\n", x);
		close(p1[1]);
		close(p2[0]);
	}
	else
	{
		//Parent process
		close(p1[1]);
		close(p2[0]);
		srand(time(NULL));
		int	y = rand() % 10;
		if (write(p2[1], &y, sizeof(y)) == -1)
			ft_error("Error write");
		printf("Wrote %d\n", y);
		if (read(p1[0], &y, sizeof(y)) == -1)
			ft_error("Error read");
		printf("Result %d\n", y);
		close(p1[0]);
		close(p2[1]);
	}
	return (0);
}

//int	main(int argc, char *argv[])
//{
//	int	arr[] = {1, 2, 3, 4, 1, 2, 7, 7};
//	int	arrSize = sizeof(arr) / sizeof(int);
//	int	fd[2];
//	int	id;
//	int	start;
//	int	end;
//
//	if (pipe(fd) == -1)
//		ft_perror("Error pipe");
//	id = fork();
//	if (id == -1)
//		ft_perror("Error fork");
//	if (id == 0)
//	{
//		start = 0;
//		end = arrSize / 2;
//	}
//	else
//	{
//		start = arrSize / 2;
//		end = arrSize;
//	}
//	int	sum = 0;
//	int	i = start;
//	while (i < end)
//	{
//		sum += arr[i];
//		i++;
//	}
//	printf("Calculated partial sum is: %d\n", sum);
//	if (id == 0)
//	{
//		close(fd[0]);
//		if (write(fd[1], &sum, sizeof(sum)) == -1)
//			ft_perror("Error write");
//		close(fd[1]);
//	}
//	else
//	{
//		int	sumFromChild;
//		close(fd[1]);
//		if (read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1)
//			ft_perror("Error write");
//		close(fd[0]);
//		int	totalsum = sum + sumFromChild;
//		printf("Total sum is: %d\n", totalsum);
//		wait(NULL);
//	}
//	return (0);
//}

//int	main()
//{
//	int id;
//	int x;
//	int y;
//	int fd[2];
////	fd[0] - read
////	fd[1] - write
//
//	if (pipe(fd) == -1)
//	{
//		printf("Error of pipe");
//		return (1);
//	}
//	id = fork();
//	if (id == -1)
//		ft_perror("Error of fork");
//	if (id == 0)
//	{
//		close(fd[0]);
//		printf("Input a number: ");
//		scanf("%d", &x);
//		if (write(fd[1], &x, sizeof(int)) == -1)
//			ft_perror("Error of write");
//		close(fd[1]);
//	}
//	else
//	{
//		close(fd[1]);
//		if (read(fd[0], &y, sizeof(int)) == -1)
//			ft_perror("Error of read");
//		y = y * 3;
//		close(fd[0]);
//		printf("Got from child process %d\n", y);
//	}
//	return (0);
//}

//int	main(int argc, char *argv[])
//{
//	int	id1;
//	int	id2;
//
//	id1 = fork();
//	id2 = fork();
//	if (id1 == 0)
//	{
//		if (id2 == 0)
//			printf("We are process Y\n");
//		else
//			printf("We are process X\n");
//	}
//	else
//	{
//		if (id2 == 0)
//			printf("We are process Z\n");
//		else
//			printf("We are the Parent process\n");
//	}
//	while (wait(NULL) != -1 || errno != ECHILD);
////		printf("Waited for a child to finish\n");
//	return (0);
//}

//int	main(void)
//{
//	int	id;
//	int	res;
//
//	id = fork();
//	if (id == 0)
//		sleep(1);
//	printf("Current ID: %d, Parent ID: %d\n", getpid(), getppid());
//	res = wait(NULL);
//	if (res == -1)
//		printf("No children to wait for\n");
//	else
//		printf("%d finished execution\n", res);
//	return (0);
//}

//int main()
//{
//	int	id;
//	int	n;
//	int	i;
//
//	id = fork();
//	if (id == 0)
//		n = 1;
//	else
//		n = 6;
//	if (id != 0)
//		wait(NULL);
//	i = n;
//	while (i < n + 5)
//	{
//		printf("%d ", i);
//		fflush(stdout);
//		i++;
//	}
//	if (id != 0)
//		printf("\n");
//	return (0);
//}

//int main()
//{
//	int	id;
//
//	id = fork();
//	if (id == 0)
//		printf("hello from child\n");
//	else
//	{
//		fork();
//		printf("hello from main\n");
//	}
////	printf("%s\n", envp[0]);
//	return (0);
//}

//int	main(int argc, char *argv[], char *envp[])
//{
//	int	j;
//
//	if (argc < 2)
//		ft_perror("Error");
//	else
//	{
//		for (j = 0; j < argc; j++)
//			printf("argv[%d]: %s\n", j, argv[j]);
//		for (j = 0; envp[j]; j++)
//			if (!ft_strncmp(envp[j], "PATH=", 5))
//				printf("%s\n", envp[j]);
//	}
//	exit(EXIT_SUCCESS);
//}
