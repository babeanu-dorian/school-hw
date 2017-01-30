#ifndef INCLUDED_TEST_
#define INCLUDED_TEST_

#include <vector>
#include <algorithm>

template <typename T>
class Test
{
	template <typename U>
	friend class Test;

	std::vector<T> d_data;

	class Nested
	{
		T d_data;
		friend class Test<T>;

		Nested(T data)
		:
			d_data(data)
		{}

		T const &get() const;
	};
	public:
		void push(T data)
		{
			d_data.push_back(data);
		}

		T get(size_t idx) const
		{
			Nested nest(d_data[idx]);
			return nest.get();
		}

		template <typename U>
		T look(Test<U> const &other, size_t idx)
		{
			return static_cast<T>(other.d_data[idx]);
		}
};

template <typename T>
T const &Test<T>::Nested::get() const
{
	return d_data;
}

#endif