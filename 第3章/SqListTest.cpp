#include"SqList.h"

int main() {
    SeqList L;  //创建实例模板,称为L
    InitList(L);  //初始化L
    //插入操作
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);
    //ListDelete(L, 1, e)
    //遍历输出线性表
    cout << "原始顺序表:";
    for (int k=0; k<L.length ; k++) {
        cout << L.data[k] << ",";
    }
    cout << endl <<  "顺序表已存储数据长度:" << L.length << endl;
    cout << "顺序表最大储存长度:" << L.MaxSize << endl;

    //删除操作
    int e = 1;
    cout << "执行删除操作中..." << endl;
    if (ListDelete( L, 3, e)) {
        cout << "已删除第3个元素,删除的值是:" << e << endl;
    }
    else {
        cout << "位序i不合法" << endl;
    };
    //遍历输出线性表
    cout << "当前顺序表:";
    for (int k=0; k<L.length ; k++) {
        cout << L.data[k] << ",";
    }
    cout << endl;

    //顺序表扩容
    cout << "顺序表扩容中..." << endl;
    IncreaseSize(L,3);
    cout << "扩容后最大储存长度:" << L.MaxSize << endl;

    //按位查找
    cout << GetElem(L, 3) << endl;
    
    //按值查找
    cout << locateElem(L,5) << endl;
    
    return 0;
}
