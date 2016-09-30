# Note 2016-06-29

As I remembered about this question, it can be done by recursion.
After I tried a correct recursion solution and check the solutions in the Internet,
I found a mere recursion solution will occur a heavy overhead while the LeetCode OJ will return Time Limit Exceeded error.

Actually the recursion solution has computed a lot of the repeated sub-problems.
To **reduce** the overhead brought by those sub-problems, **Dynamic Programming** is all we need.


## A Iterator Solution

http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html


**Analysis:**

For each element in s
If \*s==\*p or \*p == ? which means this is a match, then goes to next element s++ p++.
If p=='\*', this is also a match, but one or many chars may be available, so let us save this \*'s position and the matched s position.
If not match, then we check if there is a \* previously showed up,
       if there is no \*,  return false;
       if there is an \*,  we set current p to the next element of \*, and set current s to the next saved s position.

```
e.g.

abed
?b*d**

a=?, go on, b=b, go on,
e=*, save * position star=3, save s position ss = 3, p++
e!=d,  check if there was a *, yes, ss++, s=ss; p=star+1
d=d, go on, meet the end.
check the rest element in p, if all are *, true, else false;
```



