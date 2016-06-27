# Note 2016-06-25

The way for checking Palindrome is always the same;

```c++
template<typename InputIterator>
bool isPali(InputIterator first, InputIterator last){
    while(first < last){
        if( *first != last)
            return false;
        first++;
        last--;
    }    
    return true;
}
```

However, for the Palindrome Pairs question the key obstacle is to **optimize
the searching strategy for those Pairs**.

Another way is to enumerate all the potential substring of all the strings, and search for the palindrome patterns.
Optimistic method is the only to enumerate the exist length of string to generate the corresponding substring length.

P.S. Whenever comes the TLE or MLE problems figure the *algorithm complexity for the first place!*
