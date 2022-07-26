#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Stack.h"

/* 判断表达式是否平衡*/
bool IsBalance(char* ch)
{
    Stack S;
    int i = 0;
    char m, n;
    char p;
    
    InitStack(&S);
    while (ch[i] != '\0')
    {
        if (isdigit(ch[i]))
        {
            Push(ch[i], &S);
            i++;
            continue;
        }
        else
        {
            m = ch[i];
            switch (m)
            {
            case '(':
                Push(m, &S);
                i++;
                break;
            case '+':
                Push(m, &S);
                i++;
                break;
            case '-':
                Push(m, &S);
                i++;
                break;
            case '*':
                Push(m, &S);
                i++;
                break;
            case '/':
                Push(m, &S);
                i++;
                break;
            case ')':
                if (StackIsEmpty(&S))
                    return false;
                Pop(&n, &S);
                while (n != '(' && !StackIsEmpty(&S))
                {
                    Pop(&n, &S);
                }
                if (n != '(')
                    return false;
                p = '0';
                Push(p, &S);
                i++;
                break;
            default:
                return false;
            }
                    
        }
    } 
    while (!StackIsEmpty(&S))
    {
        Pop(&n, &S);
        if (n != '+' && n != '-' && n != '*' && n != '/' && !isdigit(n))
            return false;
    }
    return true;
 
}

/* 中缀转后缀表达式*/
void InToPost(char* in, char* post)
{
	Stack S;

	int i = 0;
	int k = 0;
    char m;

    InitStack(&S);

	while (in[i] != '\0')
	{
		if (isdigit(in[i]))
		{
			post[k++] = in[i++];
			continue;
		}
		else
		{
			if (in[i] == '(')
			{
				Push(in[i], &S);
				i++;
			}
			else if (in[i] == ')')
			{
				Pop(&m, &S);
				while (m != '(')
				{
					post[k++] = m;
					Pop(&m, &S);
				} 
				i++;
			}
			else if (in[i] == '+' || in[i] == '-')
			{
                if (StackIsEmpty(&S))
                {
                    Push(in[i], &S);
                    i++;
                    break;
                }

				m = GetTop(&S);

                if (m == '(')
                {
                    Push(in[i], &S);
                    i++;
                }

				else
				{
					Pop(&m, &S);
					while (m != '(')
					{
						post[k++] = m;
						if (StackIsEmpty(&S))
							break;
						Pop(&m, &S);
					}
					if (m == '(')
						Push(m, &S);
					Push(in[i], &S);
					i++;
				}	
			}
			else
				Push(in[i++], &S);
		}
	}
    while (!StackIsEmpty(&S))
    {
        Pop(&m, &S);
        post[k++] = m;
    }
    post[k] = '\0';
}

/* 计算结果*/ //本函数有误，字符串数组无法表示大于10的数字
int Measure(char* post)
{
    Stack S;
    int i = 0;
    int op;
    char m,n;
    int b, a;
    int result;
    char p;

    InitStack(&S);

    while (post[i] != '\0')
    {
        if (isdigit(post[i]))
        {
            Push(post[i], &S);
            i++;
        }
        else
        {
            op = post[i++];
            switch (op)
            {
            case '+':
                Pop(&m, &S);
                a = (int)m;
                Pop(&n, &S);
                b = (int)n;
                result = b + a;
                p = (char)result;
                Push(p, &S);
                break;
            case '-':
                Pop(&m, &S);
                a = (int)m;
                Pop(&n, &S);
                b = (int)n;
                result = b - a;
                p = (char)result;
                Push(p, &S);
                break;
            case '*':
                    Pop(&m, &S);
                    a = (int)m;
                    Pop(&n, &S);
                    b = (int)n;
                    result = b * a;
                    p = (char)result;
                    Push(p, &S);
                    break;
            case '/':
                Pop(&m, &S);
                a = (int)m;
                Pop(&n, &S);
                b = (int)n;
                result = b / a;
                p = (char)result;
                Push(p, &S);
                break;

            default:
                break;
            }

        }
    }
    Pop(&p, &S);

    result = (int)p;

    return result;
}