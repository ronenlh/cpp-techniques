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

void threadProc() {
	for(auto i=0;i!=NUM_THREADS;++i) {
		cout << "Message " << i << " from " << this_thread::get_id() << endl;
	}
}

int main()
{
	int i;
	vector<thread> threads(NUM_THREADS);

	for(i=0;i!=NUM_THREADS;++i)
		threads[i]=thread(threadProc);		
	

	for(i=0;i!=NUM_THREADS;++i) 
		threads[i].join();

	return 0;
}
