int isOpenClose(char a)
{
    if(a == '{' || a == '[' || a == '(')return 1;
    else return 0;
}
int valid(char s1, char s2)
{
    if((s1 == '[' && s2 == ']') || (s1 == '{' && s2 == '}') || (s1 == '(' && s2 == ')')) return 1;
    else return 0;
}
bool isValid(char* s) {
    int len = strlen(s);
    char stack[len + 1];
    int top = -1;
    for(int i = 0; i < len; i++)
    {
        if(isOpenClose(s[i]))stack[++top] = s[i];
        else
        {
            if(top == -1){
                return false;
            }
            else
            {
                if(valid(stack[top], s[i]))top--;
                else return false;
            }
        }
    }
    if(top > -1)return false;
    else return true;
    return 0;
}