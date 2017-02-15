#ifndef INCLUDED_PTR_
#define INCLUDED_PTR_

template <typename Type>
class Ptr
{
	Type *d_data;              // stored pointer
	void (*d_deleter)(Type*);  // function for freeing the pointer

	public:
		// template for selecting
		// the appropriate deleter function
		template <typename IsType>
		explicit Ptr(IsType *data);

		~Ptr();                // free the pointer

		// template for selecting
		// the appropriate deleter function
		template <typename IsType>
		void reset(IsType *data);
};

#include "deleter.f"
#include "destructor.f"
#include "ptr.f"
#include "reset.f"

#endif