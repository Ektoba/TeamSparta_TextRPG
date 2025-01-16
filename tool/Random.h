#pragma once
#include "Singleton.h"
#include <random>
class RandomMaanger : public Singleton<RandomMaanger>
{
public:
	RandomMaanger() 
	{ 
		mt = std::mt19937_64(rd()); 
		IntDist = std::uniform_int_distribution<>(0, 100);
		FloatDist = std::uniform_real_distribution<>(0.f, 100.f);
	}
	virtual ~RandomMaanger(){}
private:
	std::random_device rd;
	/*
	std::mt19937 �� C++ <random> ���̺귯������ �����ϴ� ���� ���� ���� �� �ϳ���, �޸��� Ʈ������ ��� �˰������ ����մϴ�.
	�� �˰������ ������ rand �� ����Ͽ��� ���� �յ� ��� ���� �� �� ������ �������� �����Ѵٰ� �˷����ֽ��ϴ�.
	�������ٵ� �����Ǵ� ������ ���� ������谡 �ſ� �۱� ������ ���� �ùķ��̼ǿ��� ����� �� �ֽ��ϴ�.

	���������� <random> ���̺귯������ �� �޸��� Ʈ������ ��� ���� ����� ������ rand �� ���� ���� �յ� �˰������ ����� minstd_rand �� ��������
	�������� ���ǵǾ� �ֽ��ϴ�. ���� mt19937 �� �Ǹ��� ������ �����ϱ⿡�� ���������� �������� ��ü ũ�Ⱑ Ŀ�� (2KB �̻�) �޸𸮰� ������ �ý��ۿ�����
	������ minstd_rand �� ������ �� �ֽ��ϴ�.

	mt19937 �� ������ ���Ŀ� ������ �����ϴ� �۾��� �ſ� �����ϴ�.
	��ó�� ���� ���� ������ ��������� ���� �ٷ� ������ ������ �� �ִ� ���� �ƴմϴ�.
	C++ �� ��� ��𿡼� ������ �̾Ƴ��� �˷��ִ� ����(distribution) �� �����ؾ� �մϴ�.

	�ռ� �츮�� ��� 0 ���� 99 ���� �յ��� Ȯ���� ������ �̾Ƴ��� �ʹٰ� �Ͽ����ϴ�.
	���� �̸� ���ؼ� �Ʒ��� ���� �յ� ���� (Uniform distribution) ��ü�� �����ؾ� �մϴ�.
	*/
	//mt19937_64 gen(1234); // �׳� �õ尪�� �־ �ȴ�.
	std::mt19937_64 mt;

	/*
	* 0 ~ 99 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����
	* <random> ���̺귯�������� �յ� ���� ����� �������� �������� �����ϰ� �ֽ��ϴ�. ���⼭�� �� ������ �Ұ��ϱ� ������� �� �� ���� ���� ���̴�
	* ���� ���� (Normal distribution) �� ������ ���캸�ڽ��ϴ�. (��ü ����� ���⼭ ������.)
	*/
	std::uniform_int_distribution<> IntDist;
	std::uniform_real_distribution<> FloatDist;
public:
	void setRange(const int& start, const int& end)
	{
		IntDist.reset();
		IntDist = std::uniform_int_distribution<int>(start, end);
	}
	void setRange(const float& start, const float& end)
	{
		FloatDist.reset();
		FloatDist = std::uniform_real_distribution<>(start, end);
	}
	template <typename T>
	T getRandom()
	{
		T val = NULL;
		if constexpr (std::is_same_v<T, int>)
		{
			val = IntDist(mt);
		}
		else 
		{
			val = FloatDist(mt);
		}

		return val;
	}
};

