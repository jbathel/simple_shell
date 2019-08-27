/**
  * word_counter - Calls Function
  * @str: ...
  * Description: ...
  * Return: ...
  */
int word_counter(char *str)
{
	int i, count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}
	return (count);
}
