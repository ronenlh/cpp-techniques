#include <thread>
#include <vector>
#include <iostream>

#define NUM_THREADS 5
using namespace std;

/*
 * thread instance(thread_procedure)
 *
 * this_thread::get_id()
 *
 * thread::join()
 *
 */

function<void()> threadProcess = []() {
	for(auto i=0;i!=NUM_THREADS;++i) {
		cout << "Message " << i << " from " << this_thread::get_id() << endl;
	}
};

int main()
{
	vector<thread> threads;

	for(auto i=0;i!=NUM_THREADS;++i)
		threads.push_back(thread(threadProcess));		
	

	for(thread &th : threads){
		if(th.joinable())
			th.join();
	}
	return 0;
}
