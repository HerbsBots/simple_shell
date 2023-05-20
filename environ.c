#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: structure that contains potential arguments
 * used to maintain constant function prototype
 *
 * Return: Always 0
 *
 */

int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
 * _getenv - gets the value of an environ variable
 *
 * @info: structure that contain potential arguments used to maintain
 *
 * @name: env var name
 *
 * Return: the value
 */

char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;
while (node)
{
p = starts_with(node->str, name);
if (p && *p)
return (p);
node = node->next;
}
return (NULL);
}

/**
 * _mysetenv - initialize a new environment variable
 * or modify an existing one
 *
 * @info: structure that contains potential arguments
 * use to maintain constant function prototype
 *
 * Return: Always o
 */

int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguments\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}
