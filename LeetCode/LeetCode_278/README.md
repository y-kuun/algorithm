# Note 2016-06-27

Binary search must have code sections like below:

```c++
auto mid = (left + right) / 2;
```

However, if the range is really big the formulation above would overflow!

A more better way is like this:

```c++
auto mid = left + (right - right) / 2;
aka:
auto mid = left - left/2 + right / 2;
         = left/2 + right/2;
         = (left + right)/2;
```

Easy but necessary :)

