#include <cstdio>
#include <string>

#include "SObserver.h"
#include "SSubject.h"
using namespace std;

class AA {
public:
	AA()
	{
		shot_subject = new SSubject<int>();
		td_subject = new SSubject<string, string>();
	}

	template<typename... Args>
	void add_obs(SObserver<Args...>* obs)
	{
		shot_subject->addObserver(obs);
	}

	void set_val(int val)
	{
		shot_val = val;
		shot_subject->notifyUpdate(shot_val);
	}

	void set_td_conn(string td_id, string rom_path)
	{

	}

private:
	int shot_val = 0;
	SSubject<int>* shot_subject = nullptr;
	SSubject<string, string>* td_subject = nullptr;
};

class BBHasAClass
{
public:
	BBHasAClass()
	{
		
	}

	static bool check_can_use()
	{
		return true;
	}

	static void sonication()
	{
		printf("BBHasAClass::sonication called...\n");
	}
};

class BB
{
public:
	BB()
	{
		shot_val_obs = new SObserver<int>(&shot_val_updated);
	}

	static void shot_val_updated(int shot_val)
	{
		printf("BB::shot_val_updated called ... shot_val : %d\n", shot_val);
		if (bb1.check_can_use())
		{
			bb1.sonication();
		}
	}

	SObserver<int>* shot_val_obs = nullptr;

private:
	static BBHasAClass bb1;
};

class CC
{
public:
	CC()
	{
		td_conn_obs = new SObserver<string, string>(&update_td_conn_rom);
		shot_val_obs = new SObserver<int>(&update_relate_with_shot_val);
	};

	static void update_relate_with_shot_val(int shot_val) {
		printf("CC::update_relate_with_shot_val called... shot_val = %d\n", shot_val);
	}

	static void update_td_conn_rom(string td_id, string rom_path) {
		printf("%s %s\n", td_id, rom_path);
	}

	SObserver<string, string>* td_conn_obs = nullptr;
	SObserver<int>* shot_val_obs = nullptr;

private:
};

int main() {
	AA aa;
	BB bb;
	CC cc;

	aa.add_obs(bb.shot_val_obs);
	aa.add_obs(cc.shot_val_obs);
	aa.set_val(1000);
}