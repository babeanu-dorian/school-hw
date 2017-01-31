template <typename Fun, typename ...Params>
bool Semaphore::wait(Fun &&fun, Params &&...params)
{
	std::unique_lock<std::mutex> lk(d_mutex);
	while (d_nAvailable == 0)
		d_condition.wait(lk);
	--d_nAvailable;
	return fun(std::forward<Params>(params)...) && d_nAvailable;
}