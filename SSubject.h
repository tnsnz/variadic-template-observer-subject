#include "SObserver.h"

#include <vector>

class SSubject
{
public:
	void addObserver(SObserverBase* observer)
	{
		observers.push_back(observer);
	}

	void notifyUpdate()
	{
		for (const auto& observer : observers)
		{
			observer->update();
		}
	}

private:
	std::vector<SObserverBase*> observers;
};
