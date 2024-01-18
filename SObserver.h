#include <tuple>

class SObserverBase
{
public:
    virtual ~SObserverBase() {}
    virtual void update() = 0;
};

template <typename... Args>
class SObserver : public SObserverBase
{
public:
    using FunctionType = void (*)(Args...);
    SObserver(FunctionType func, Args... args) : func(func), storedArgs(args...) {}

    void update() override
    {
        callFunc(std::index_sequence_for<Args...>());
    }

private:
    template <std::size_t... Is>
    void callFunc(std::index_sequence<Is...>)
    {
        func(std::get<Is>(storedArgs)...);
    }

    FunctionType func;
    std::tuple<Args...> storedArgs;
};