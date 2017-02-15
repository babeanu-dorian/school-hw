template <typename Base, typename Derived>
void deleter(Base* ptr)
{
	delete static_cast<Derived*>(ptr);
}