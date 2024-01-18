#pragma once
#include "SObserver.h"
#include <vector>

template<typename... Args>
class SSubject {
public:
	SSubject()
	{
	}

	void addObserver(SObserver<Args...> *observer)
	{
		observers.push_back(observer);
	}

	void notifyUpdate(Args... arg)
	{
		for (auto observer : observers)
		{
			observer->update(arg...);
		}
	}

private:
	std::vector<SObserver<Args...>*> observers;

};