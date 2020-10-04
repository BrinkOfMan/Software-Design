#include"../react.h"



int func(int arg)
{
  arg = arg + 2;
  return arg;
}

int funcp(int *argp)
{
  *argp = (*argp) + 2;
  return *argp;
}

int main ()
{

    int i = 17;
    double f = -4.2;
    int *ip = &i;
    double *fp = &f;
    print("Initial values: i is {i}, *ip is {ip}, f is {f}, *fp is {fp}\n", {{"i",i},{"ip",*ip},{"f",f},{"fp",*fp}});

    i *= 3;
    *fp *= 1.5;
    print("After multiplying: i is {i}, *ip is {ip}, f is {f}, *fp is {fp}\n", {{"i",i},{"ip",*ip},{"f",f},{"fp",*fp}});

    double f2 = 2.5;
    fp = &f2;
    i *= *ip;
    print("i is {i}, *ip is {ip}, f is {f}, *fp is {fp}, f2 is {f2}\n", {{"i",i},{"ip",*ip},{"f",f},{"fp",*fp},{"f2",f2}});

    print("func(i) returns {fi}", {{"fi", func(i)}});
    print(", i is {i}, *ip is {ip}\n", {{"i", i}, {"ip", *ip}});

    print("func(*ip) returns {fip}", {{"fip", func(*ip)}});
    print(", i is {i}, *ip is {ip}\n", {{"i", i}, {"ip", *ip}});

    print("funcp(ip) returns {fip}", {{"fip", funcp(ip)}});
    print(", i is {i}, *ip is {ip}\n", {{"i", i}, {"ip", *ip}});

    print("funcp(&i) returns {fi}", {{"fi", funcp(&i)}});
    print(", i is {i}, *ip is {ip}\n", {{"i", i}, {"ip", *ip}});

}
