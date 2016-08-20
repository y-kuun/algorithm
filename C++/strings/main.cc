#include <cstdio>
#include <cassert>
#include <cstdlib>

namespace dyk{
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
    char src[20] = "World!";
    printf("%d\n", dyk::strcmp(des, src));
    printf("%s - %s \n", des, src);
    dyk::strcat(des, src);
    printf("%s - %s \n", des, src);
    des[10] = 'S';
    printf("%s - %s \n", des, src);
    dyk::strcpy(des, src);
    printf("%s - %s \n", des, src);
    return 0;
}
