#ifndef _CHECK_H_
#define _CHECK_H_

/**
 * @note 检查指针是否为空，默认直接返回
 * @param X 标准C/C++数据
 * @return 无
 */
#define CHECK_STD(X) do{ \
    if ((X) == NULL) \
    { \
        printf("[ERROR] " #X " is NULL. %s %dL.\n", __FILE__, __LINE__); \
        return; \
    } \
}while(0)

/**
 * @note 检查指针是否为空，用于有返回值的函数中
 * @param X 标准C/C++数据
 * @param Y 任意类型的数据
 * @return Y
 */
#define CHECK_STD_RETURN(X, Y) do{ \
    if ((X) == NULL) \
    { \
        printf("[ERROR] " #X " is NULL. %s %dL.\n", __FILE__, __LINE__); \
        return (Y); \
    } \
}while(0)

#endif // _CHECK_H_

