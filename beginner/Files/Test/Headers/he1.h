#ifndef HE1_H_INCLUDED
#define HE1_H_INCLUDED

int add(int a, int b)
{
    return a + b;
}


int add_array(int arr[])
{
    int answer = 0;

    for (int i = 0; i < (int) (sizeof(arr) / sizeof(int)); ++i) answer += i;

    return answer;
}

#endif // HE1_H_INCLUDED
