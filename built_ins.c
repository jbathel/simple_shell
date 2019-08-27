
	if (_strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		break;
	}
	if (_strcmp(argv[0], "env") == 0)
	{
		print_env();
		free(argv);
		break;
	}
