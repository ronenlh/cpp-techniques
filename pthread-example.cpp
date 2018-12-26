#include <pthread.h>
#include <assert.h>
#include <vector>
#include <iostream>

#define NUM_THREADS 5
using namespace std;
/*
int pthread_create( // create a new thread
		pthread_t *thread, // thread handle pointer
		const pthread_attr_t *attr, // thread attribute
		void *(*start_routine)(void*), // thread function pointer
		void *arg // thread argument
		)

int pthread_join(pthread_t *thread, void **retval) // blocks the caller thread until exit

int pthread_exit(void *retval) // output parameter of the exit code of the thread

pthread_t pthread_self(void) // returns the thread id
*/

void* threadProc(void *param)
	// runs within the thread context
{
	for(auto i=0;i!=4;++i)
		cout << "Message " << i << " from " << pthread_self() << endl;
	pthread_exit(0); // terminates the calling thread (with exit code)
}

int main() {
	cout << "pthread example" << endl;
	int i;
	vector<pthread_t> threads(NUM_THREADS); // declare thread instances
	
	for(i=0;i!=NUM_THREADS;++i) {
		int code = pthread_create(&threads[i], nullptr, threadProc, nullptr); // creates new thread
		assert(!code);
	}

	
	for(i=0;i!=NUM_THREADS;++i) {
		int code = pthread_join(threads[i], nullptr); // block out main thread, until thread passes 
		assert(!code);
	}
	return 0;
}
