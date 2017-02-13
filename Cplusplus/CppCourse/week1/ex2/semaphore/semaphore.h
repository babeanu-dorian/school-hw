#ifndef INCLUDED_SEMAPHORE_
#define INCLUDED_SEMAPHORE_

#include <mutex>
#include <condition_variable>

class Semaphore
{
	mutable std::mutex d_mutex;
	std::condition_variable d_condition;
	size_t d_nAvailable;

	public:
		Semaphore(size_t nAvailable);

		void notify();
		void notify_all();
		inline size_t size() const;

		template <typename Fun, typename ...Params>
		bool wait(Fun &&fun, Params &&...params);
};

#include "size.f"
#include "wait.f"
#endif
