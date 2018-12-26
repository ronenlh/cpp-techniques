#include <iostream>
#include <thread>

using namespace std;

class Thread
{
private:
	thread *pThread;
	bool stopped;
	void run();

public:
	Thread();
	~Thread();

	void start();
	void stop();
	void join();
	void detach();
};



