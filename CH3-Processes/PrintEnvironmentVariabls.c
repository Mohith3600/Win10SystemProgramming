#include <stdio.h>
#include <Windows.h>

int main(int argc, const char* argv[], char* env[])
{
	for (int i=0; ; i++)
	{
		if (env[i] == nullptr)
			break;
		auto equals = strchr(env[i], '=');
		//change the equals to NULl
		*equals = '\0';
		printf("%s: %s\n", env[i], equals + 1);

		//for consistency revert the equal sign
		*equals = '=';
	}
	return 0;
}
