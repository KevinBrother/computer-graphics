#include <iostream>

void print_pointer(char **p) {
  char *str = "Hello, world!";
  printf("The value of str in print_pointer() is %p\n", str);
  printf("The value of str in print_pointer() is %p\n", "Hello, world!");
  printf("The value of str in print_pointer() is %p\n", &str);
  // 把指针 str 指向的地址赋值给 p
  *p = str;
}

int main() {
  char *p;
  printf("The value of p after is %s\n", p);
  printf("The value of p before is %p\n", p);
  printf("The address of p before is %p\n", &p);

  print_pointer(&p);

  printf("The value of p after is %s\n", p);
  printf("The value of p after is %p\n", p);
  printf("The address of p after is %p\n", &p);
  return 0;
}
