#include "UniquePtr.h"

UniquePtr::UniquePtr()
{
	_ptr = nullptr;
}

UniquePtr::UniquePtr(ValueType* ptr)
{
	_ptr = ptr;
}

UniquePtr::UniquePtr(UniquePtr&& o) noexcept
{
	this->_ptr = o._ptr;
	o._ptr = nullptr;
}

UniquePtr& UniquePtr::operator=(UniquePtr&& o) noexcept
{
	if (&o != this) {
		reset();
		this->_ptr = o._ptr;
		o._ptr = nullptr;
	}
	return *this;
}

UniquePtr& UniquePtr::operator=(ValueType* ptr)
{
	reset();
	_ptr = ptr;
	return *this;
}

void UniquePtr::reset()
{
	delete[] _ptr;
	_ptr = nullptr;
}

void UniquePtr::reset(ValueType* ptr)
{
	reset();
	_ptr = ptr;
}

void UniquePtr::release()
{
	_ptr = nullptr;
}

UniquePtr::operator bool() const
{
	return(_ptr != nullptr);
}

ValueType& UniquePtr::operator*() const
{
	return *_ptr;
}

ValueType* UniquePtr::operator->() const
{
	return _ptr;
}

ValueType* UniquePtr::get() const
{
	return _ptr;
}

UniquePtr::~UniquePtr()
{
	reset();
}

	