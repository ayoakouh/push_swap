#include "push_swap.h"

int    ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
        i++;
    }
    return (s1[i] - s2[i]);
}
int is_valide(char *str)
{
    int i;
    
    i = 0;
    if (str != NULL && (str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]) == 1)
        i++;
    while(str && str[i] != '\0')
    {
        if (ft_isdigit(str[i]) == 0)
            return (0);
              i++;
    }
    return(1);
}

int is_range_valide(char *str)
{
    long number = ft_atoi(str);
    if (number < INT_MIN || number > INT_MAX)
        return(0);
    return(1);
}
int duplicate(char **str) 
{
    int i = 0;
    int j;
    int count = 0;
    while(str[i])
    {
        j = i + 1;
        while(str[j])
        {
            if(ft_strcmp(str[i], str[j]) == 0)
                count++;
            j++;
        }
        i++;
    }
    if(count == 0)
        return(1);
    return(0); 
}

int check_empty(char **av, int ac)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < ac - 1)
    {
        if (av[i] == NULL)
            return (0);
        while (av[i][j] == 32)
            j++;
        if (av[i][j] == '\0')
            return (0);
        i++;
    }
    return (1);
}