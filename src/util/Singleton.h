#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#ifdef __LP64__
	typedef long long Singleton_OFFSET;
#else
	typedef int Singleton_OFFSET;
#endif


template<typename Type>
class Singleton
{
public:
	Singleton()
	{
		Singleton_OFFSET offset = (Singleton_OFFSET)((Type*)0 + 1) - (Singleton_OFFSET)(Singleton <Type>*)((Type*)0+1);
		m_Type = (Type*)((Singleton_OFFSET)this + offset);
	}
	~Singleton()
	{
		m_Type = 0;
	}

	static Type & Instance()
	{
		return ( *m_Type);
	}
	static Type * InstancePtr()
	{
		return (m_Type);
	}

private:
	static Type * m_Type;
};

template<typename Type> Type* Singleton<Type>::m_Type = 0;

#endif // __SINGLETON_H__
