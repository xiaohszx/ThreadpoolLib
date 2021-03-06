/** 
* @file MyList.h
* @brief 线程列表
*/

#pragma once
#include <list>
#include "MyThread.h"

// 线程列表
typedef std::list<CMyThread*> ThreadList;

/**
* @class CMyList 
* @brief 线程列表封装了对ThreadList的操作方法
*/
class CMyList
{
public:
	/// 默认构造函数
	CMyList() { }

	/// 默认析构函数
	~CMyList() { }

public:

	// 向线程列表添加一个线程
	inline void addThread(CMyThread *t) { assert(t); m_list.push_back(t); }

	// 向线程列表移除一个线程(只移除，不delete指针)
	inline void removeThread(CMyThread *t) { assert(t); m_list.remove(t); }

	// 获取线程列表的大小
	inline int getSize() const { return m_list.size(); }

	// 判断线程列表是否为空
	inline bool isEmpty() const { return m_list.empty(); }
	
	// 删除线程列表中的线程(移除，并delete指针)
	inline void CMyList::clear()
	{
		for(ThreadList::const_iterator iter = m_list.begin(); iter != m_list.end(); ++iter)
			(*iter)->Exit();
		m_list.clear();
	}

private:
	/// 线程列表
	ThreadList m_list;
};
