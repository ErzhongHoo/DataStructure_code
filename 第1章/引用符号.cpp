#include<stdio.h>
/*本篇主要写&引用的作用*/

//不使用引用
void normalX(int x){
    //内存中复制了一个新的x(开辟新内存地址),1024赋给的是新的,不是main的那个x
    x=1024;
    printf("normalX函数内部 x=%d\n",x);
}

//使用引用&
void referenceY(int &y){
    //修改的是main函数里面y的那个内存中的数据
    y=1024;
    printf("referenceY函数内部 y=%d\n",y);
}

int main(){
    int x=1;
    printf("x调用normalX前 x=%d\n",x);
    normalX(x);
    printf("x调用normalX后 x=%d\n",x);

    printf("\n");

    int y=1;
    printf("y调用referenceY前 y=%d\n",y);
    referenceY(y);
    printf("y调用referenceY后 y=%d\n",y);

    return 0;
}
