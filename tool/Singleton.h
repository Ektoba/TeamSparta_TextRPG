#pragma once

template <typename T>
class Singleton
{
	typedef void(*DESTORY)(void);
private:
	static T* m_Inst;
public:
	static T* GetInst()
	{
		if (m_Inst == nullptr)
		{
			m_Inst = new T;
		}

		return m_Inst;
	}
	static void Destroy()
	{
		if (m_Inst != nullptr)
		{
			delete m_Inst;
			m_Inst = nullptr;
		}
	}
public:
	Singleton()
	{
		atexit((DESTORY)Singleton<T>::Destroy);
	}

	virtual ~Singleton()
	{
	}
};
template<typename T>
T* Singleton<T>::m_Inst = nullptr;