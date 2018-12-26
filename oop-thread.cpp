#include "oop-thread.h"

Thread::Thread()
{
	pThread = nullptr;
	stopped = false;
}

Thread::~Thread()
{
	delete pThread;
	pThread = nullptr;
}

void Thread::run()
{
	while(!stopped) {
		cout << this_thread::get_id() << endl;
		this_thread::sleep_for(1s);
	}
	cout << "\nThread " << this_thread::get_id() << " stopped as requested." << endl;
	return;
}

void Thread::stop()
{
	stopped = true;
}

void Thread::start()
{
	pThread = new thread(&Thread::run,this);
}

void Thread::join()
{
	pThread->join();
}

void Thread::detach()
{
	pThread->detach();
}
