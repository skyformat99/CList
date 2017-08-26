//
// Created by luna on 2017/8/23.
//

#ifndef CLIST_ARRAYLIST_H
#define CLIST_ARRAYLIST_H
#pragma once
/**
 * 功能类似于 Java 中的 ArrayList 类，支持泛型类。内部实现使用的是数组.
 *
 * 由于在 C++ 中数组记录的指针是数组中第一个元素的位置(超棒的特性)，所以在实例域
 * 中保存了头元素的指针位置。计算当前空闲位置的方式是通过实例域中的 _size + list
 * 指针计算当前空元素位置.
 *
 * 数组增量默认情况为0.6，即在执行add操作时如果当前数组长度不够申请新数组的长度为
 * 原长度*1.6，当这个值小于 7 时则增加7个单位的长度。这样设计也是为了兼顾性能的同
 * 时节省下一部分内存。你可以通过构造函数手动指定这个值.
 *
 * @tparam T
 */
template<class T> class ArrayList
{
private:
    int _length; // 当前数组的长度
    int _size = 0; // 当前列表中不为NULL元素的个数
    T *list; // 数组
    int amount; // 每次增加所需要增加的数组大小
    float mod; // 增量
public:
    ArrayList();
    ArrayList(int amount);
    ArrayList(int amount, float mod);

    /**
     * 在当前对象的末尾添加一个元素(指针)，如果当前对象已满则会更换更大的数组.
     */
    ArrayList<T> add(T *t);

    /**
     * 在当前对象的末尾添加一个元素(引用)，如果当前对象已满则会更换更大的数组.
     */
    ArrayList<T> add(T t);

    /**
     * 在指定位置插入一个 T 类型指针.
     * 此操作将造成该位置往后的所有元素向后移动一个位置.
     */
    ArrayList<T> add(int loc, T *t);

    /**
     * 移除列表的最后一个元素，执行本操作的时候如果 size 小于 length 的一半，则将数组长度减小一半以节省内存.
     */
    ArrayList<T> remove();

    /**
     * 移除列表中指定位置的元素，执行本操作的时候如果 size 小于 length 的一半，则将数组长度减小一半以节省内存.
     * 因为是数组实现，删除中间的位置会造成后面所有的元素往前挪一个位置，造成巨大开销.
     */
    T remove(int loc);

    /**
     * 获取指定位置的元素.
     */
    T get(int loc);

    /**
     * 返回当前列表中元素的数量.
     */
    int size();

    /**
     * 返回当前列表的长度.
     */
    int length();

    /**
     * 在数组长度再变化时，用这个方法裁剪列表，释放多余内存.
     */
    int trimSize();

    /**
     * 将指定位置的指针设置为作为参数的指针
     */
    int setContent(int loc, T *t);
};


//////////////////////////////////////////////////////////////////////////
//                                                                      //
//									实现                                 //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

template<class T>
ArrayList<T>::ArrayList()
{
    this->_length = 6;
    this->list  = new T[6];
}

template<class T>
ArrayList<T>::ArrayList(int amount)
{
    this->_length = amount;
    this->list = new T[amount];
}

template<class T>
ArrayList<T> ArrayList<T>::add(T *t)
{
    // 如果长度已经达到上限的话那就换一个新的数组
    if (_size >= _length)
    {
        T *nl = new T[_length = _length + amount]; // 更新数组当前长度
        T *bnl = nl, *bl = this->list;
        for(int i = 0; i < this->_length; i++) *bnl++ = *bl++; // 将老数组中的元素复制进新数组
    }
    *(this->list + this->_size++) = *t; // 更新当前size长度


    return *this;
}

template<class T>
ArrayList<T> ArrayList<T>::add(T t)
{
    return this->add(&t);
}
#endif //CLIST_ARRAYLIST_H
