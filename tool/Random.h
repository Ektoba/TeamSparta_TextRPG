#pragma once
#include "Singleton.h"
#include <random>
class Random : public Singleton<Random>
{
public:
	Random() 
	{ 
		mt = std::mt19937_64(rd()); 
		IntDist = std::uniform_int_distribution<>(0, 100);
		FloatDist = std::uniform_real_distribution<>(0.f, 100.f);
	}
	virtual ~Random(){}
private:
	std::random_device rd;
	/*
	std::mt19937 는 C++ <random> 라이브러리에서 제공하는 난수 생성 엔진 중 하나로, 메르센 트위스터 라는 알고리즘을 사용합니다.
	이 알고리즘은 기존에 rand 가 사용하였던 선형 합동 방식 보다 좀 더 양질의 난수열을 생성한다고 알려져있습니다.
	무엇보다도 생성되는 난수들 간의 상관관계가 매우 작기 때문에 여러 시뮬레이션에서 사용할 수 있습니다.

	참고적으로 <random> 라이브러리에는 위 메르센 트위스터 기반 엔진 말고도 기존의 rand 와 같이 선형 합동 알고리즘을 사용한 minstd_rand 외 여러가지
	엔진들이 정의되어 있습니다. 물론 mt19937 이 훌륭한 난수를 생성하기에는 적합하지만 생각보다 객체 크기가 커서 (2KB 이상) 메모리가 부족한 시스템에서는
	오히려 minstd_rand 가 적합할 수 있습니다.

	mt19937 를 생성한 이후에 난수를 생성하는 작업은 매우 빠릅니다.
	이처럼 난수 생성 엔진을 만들었지만 아직 바로 난수를 생성할 수 있는 것은 아닙니다.
	C++ 의 경우 어디에서 수들을 뽑아낼지 알려주는 분포(distribution) 을 정의해야 합니다.

	앞서 우리의 경우 0 부터 99 까지 균등한 확률로 정수를 뽑아내고 싶다고 하였습니다.
	따라서 이를 위해선 아래와 같이 균등 분포 (Uniform distribution) 객체를 정의해야 합니다.
	*/
	//mt19937_64 gen(1234); // 그냥 시드값을 넣어도 된다.
	std::mt19937_64 mt;

	/*
	* 0 ~ 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의
	* <random> 라이브러리에서는 균등 분포 말고도 여러가지 분포들을 제공하고 있습니다. 여기서는 다 일일히 소개하기 어렵지만 그 중 가장 많이 쓰이는
	* 정규 분포 (Normal distribution) 만 간단히 살펴보겠습니다. (전체 목록은 여기서 보세요.)
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

