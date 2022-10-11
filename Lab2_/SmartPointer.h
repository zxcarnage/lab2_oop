#pragma once
template<typename T>
class SmartPointer
{
	T* _pointer;
	//void CleanUp();

public:
	SmartPointer();
	SmartPointer(T object);
	SmartPointer(T* pointer);
	SmartPointer(SmartPointer& other);
	~SmartPointer(void);

	T& operator*();
	void operator=(SmartPointer&& other);
	T* operator->();
};

template<typename T>
SmartPointer<T>::SmartPointer()
{

}

template<typename T>
SmartPointer<T>::SmartPointer(T object)
{
	*_pointer = object;
}

template<typename T>
SmartPointer<T>::SmartPointer(T* pointer)
{
	pointer = _pointer;
}

template<typename T>
SmartPointer<T>::SmartPointer(SmartPointer& other)
{
	*other = *_pointer;
}

template<typename T>
SmartPointer<T>::~SmartPointer(void)
{
	CleanUp();
}

template<typename T>
T& SmartPointer<T>::operator*()
{
	return *_pointer;
}

template<typename T>
void SmartPointer<T>::operator=(SmartPointer&& other)
{
	CleanUp();
	_pointer = other._pointer;
	if (other._pointer)
		other._pointer = nullptr;
}

template<typename T>
T* SmartPointer<T>::operator->()
{
	return _pointer;
}

template<typename T>
void SmartPointer<T>::CleanUp()
{
	if (_pointer)
		delete _pointer;
}