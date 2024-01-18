#pragma once

template <typename... Args>
class SObserver {
public:
	typedef void Function(Args...);

	SObserver(Function* func)
	{
		this->func = func;
		auto kk = func;
	}

	void addFunc(Function* func)
	{
		this->func = func;
	}

	void update(Args... args)
	{
		func(args...);
	}

private:
	Function* func;
};