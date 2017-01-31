#include "semaphore.ih"

void Semaphore::notify()
{
	std::lock_guard<std::mutex> lk(d_mutex);
	if (d_nAvailable++ == 0)
		d_condition.notify_one();
}
