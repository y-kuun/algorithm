# Note

The way for checking Palindrome is alway the same;

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

P.S. Whenever comes the TLE or MLE problems figure the *algorithm complexity for the first place!*
