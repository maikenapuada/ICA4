#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>//Support for POSIX error messages. Defines 'errno'
#include <math.h>
#include <ctype.h>

int main(int argc, char** argv)
{
	int arg1 = 0; //First integer


	int runs = 0;
	float avgruns = 0;
	char* end = NULL; //String pointer for detecting errors in strtol
	arg1 = strtol(argv[1], &end, 10);

	if ((argc == 4))
	{

		if (end == argv[1]) //Couldn't parse
		{
			fprintf(stderr, "Enter an integer for first argument.\n");
			exit(1); //Exit and throw and error.
		}
		if (argv[1] < 0)
		{
			fprintf(stderr, "Enter a positive integer.\n");
			exit(1); //Exit and throw and erro
		}

		else
		{
			switch (argv[2][0])
			{
			case'e':
			case'E':
			{
				if (arg1 < 0)
				{
					fprintf(stderr, "Enter a positive integer.\n");
					exit(1); //Exit and throw and erro
				}
				for (int i = 0; i < strlen(argv[3]); i++)
				{

					int key = arg1;
					int string = argv[3][i];
					if (((argv[3][i]) >= 65) && ((argv[3][i]) <= 90))
					{
						key = arg1 % 26;
						string = argv[3][i] + key;
						if (string > 90)
							string = string - 26;
						if (string < 65)
							string = string + 26;

					}

					if (((argv[3][i]) >= 97) && ((argv[3][i]) <= 122))
					{
						key = arg1 % 26;
						string = argv[3][i] + key;
						if (string > 122)
							string = string - 26;
						if (string < 97)
							string = string + 26;

					}

					if (((argv[3][i]) >= 48) && ((argv[3][i]) <= 57))
					{
						key = arg1 % 10;
						string = argv[3][i] + key;
						if (string > 57)
							string = string - 10;
						if (string < 48)
							string = string + 10;
					}

					printf("%c", string);
				}
				break;
			}
			case'd':
			case'D':
			{
				if (arg1 < 0)
				{
					fprintf(stderr, "Enter a positive integer.\n");
					exit(1); //Exit and throw and erro
				}
				for (int i = 0; i < strlen(argv[3]); i++)
				{
					int key = arg1;
					int string = argv[3][i];
					if (((argv[3][i]) >= 65) && ((argv[3][i]) <= 90))
					{
						key = arg1 % 26;
						string = argv[3][i] - key;
						if (string > 90)
							string = string - 26;
						if (string < 65)
							string = string + 26;

					}
					if (((argv[3][i]) >= 97) && ((argv[3][i]) <= 122))
					{
						key = arg1 % 26;;
						string = argv[3][i] - key;
						if (string > 122)
							string = string - 26;
						if (string < 97)
							string = string + 26;
					}

					if (((argv[3][i]) >= 48) && ((argv[3][i]) <= 57))
					{
						key = arg1 % 10;
						string = argv[3][i] - key;
						if (string > 57)
							string = string - 10;
						if (string < 48)
							string = string + 10;
					}
					printf("%c", string);

				}
				break;
			}

			default:
			{
				fprintf(stderr, "Invalid arguments. \n");
				exit(1);
				break;
			}
			}

		}

	}
	else
	{
		fprintf(stderr, "Invalid number of arguments.\n");
		exit(1); //Exit and throw and error.
	}

	fflush(stdin);
	printf("\nPress any key to continue.");
	fflush(stdout);
	fgetc(stdin);
	return 0;


}