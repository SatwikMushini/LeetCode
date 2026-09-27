/*int check_bracket(char s)
{
    if(s == '(')return 1;
    else if(s == ')')return 2; 
    else return 0;
}*/
char* reverseParentheses(char* s) {
    char *stack = (char *)malloc(2001 * sizeof(char));
    int top = -1;
    int len = strlen(s);

    char sub[2001];
    for(int i = 0; i < len; i++)
    {
        if(s[i] != ')')stack[++top] = s[i];
        else
        {
            int j = 0;
            while(top != -1 && stack[top] != '(')
            {
                sub[j++] = stack[top--];
                //top--;
            }
            top--;
            sub[j] = '\0';
            int len_sub = strlen(sub);
            for(int k = 0; k <len_sub; k++)
            {
                stack[++top] = sub[k];
            }
            sub[0] = '\0';
        }
    }
    stack[++top] = '\0';
    return stack;
}