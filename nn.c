#include<stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
        i++;
    }
    return (s1[i] - s2[i]);
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