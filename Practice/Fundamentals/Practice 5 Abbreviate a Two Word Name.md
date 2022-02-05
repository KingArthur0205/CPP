# Practice 5: Abbreviate a Two Word Name
Write a function to convert a name into initials. This kata strictly takes two words with one space in between them.

The output should be two capital letters with a dot separating them.

It should look like this:

```Sam Harris => S.H```

```patrick feeney => P.F```

# Solution:
1. Push the capitalized first letter into  our newly-constructed string
2. Push a '.' to our string
3. Find the white space that splits the first name and the last word. Get the letter after the white space, capitalize it, and push it into the string.

```cpp
#include <string>

std::string abbrevName(std::string name) {
  std::string ret;
  ret.push_back(toupper(name[0]));
  ret.push_back('.');
  
  //Find the index of the white space.
  std::string::size_type spaceIndex = name.find(" ");
  //The character after the white space is the one we wants.
  ret.push_back(toupper(name[spaceIndex + 1]));
  
  return ret;
}
```