def palindrome(s,a,b) -> bool:
  if b <= a:
    return True
  return (s[a] == s[b]) and palindrome(s,a+1,b-1)


def sumx(n):
  if n == 0:
    return 0
  return n%10 + sumx(int(n/10))

print(sumx(3198))

print ( palindrome("abcba",0,4))
