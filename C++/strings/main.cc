#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

namespace dyk{

    // length is the
    char* c_replace_blank(char* str_ipt, int size)
    {
        // O(n)
        if(str_ipt == NULL || size <= 0)
            return NULL;

        int origin_len = 0;
        int blank_len = 0;

        for(int i = 0; str_ipt[i] != '\0'; i++)
        {
            origin_len++;

            if(str_ipt[i] == ' ')
                blank_len++;
        }

        int extra_len = origin_len + blank_len * 2;

        if(extra_len > size)
            return NULL;

        for(int i = origin_len, j = extra_len; i >= 0; i--)
        {
            if(str_ipt[i] == ' ')
            {
                str_ipt[j--] = '0';
                str_ipt[j--] = '2';
                str_ipt[j--] = '%';
            } else {
                str_ipt[j--] = str_ipt[i];
            }
        }

        return str_ipt;
    }

    string& replace_blank(string& str_ipt)
    {
        // O(n^2)
        string::size_type it;

        while((it = str_ipt.find(' ')) != string::npos)  // string::npos
        {
            str_ipt.replace(it, 1, "%20");
        }

        return str_ipt;
    }


    int strcmp(const char* lhs, const char* rhs)
    {
        assert((NULL != lhs) && (NULL != rhs));
        while(*lhs != '\0' && *rhs != '\0')
        {
            if(*lhs == *rhs)
            {
                lhs++;
                rhs++;
            } else return (*lhs) - (*rhs);
        }
        return (*lhs) - (*rhs);
    }

    char* strcat(char *des, const char* src)
    {
        assert((NULL != des) && (NULL != src));
        char *res = des;
        while(*des != '\0')
            des++;
        while(*src != '\0')
        {
            *des++ = *src++;
        }
        *des = '\0';
        return res;
    }

    char* strcpy(char *des, const char* src)
    {
        assert((NULL != des) && (NULL != src));
        char *res = des;
        while(*src != '\0')
        {
            *des++ = *src++;
        }
        *des = '\0';
        return res;
    }
}

int main(int argc, char* argv[])
{
    char des[7] = "Hello ";
    char src[20] = " World ! ";
    string str("hello World ! ");
    dyk::replace_blank(str);
    dyk::c_replace_blank(src, 20);
    cout<<src<<endl;
    return 0;
}
