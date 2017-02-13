#include "semaphore.ih"

void Semaphore::notify_all()
{
	std::lock_guard<std::mutex> lk(d_mutex);
	if (d_nAvailable++ == 0)
		d_condition.notify_all();
}