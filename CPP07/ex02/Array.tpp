template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n)
{
	if (n > 0)
		_array = new T[n]();
}

template <typename T>
Array<T>::Array(Array<T> const &src) : _array(NULL),
	_size(src._size)
{
	if (_size > 0)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
		{
			_array[i] = src._array[i];
		}
	}
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this == &rhs)
		return (*this);
	if (_array != NULL)
		delete[] _array;
	_size = rhs._size;
	if (_size > 0)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
		{
			_array[i] = rhs._array[i];
		}
	}
	else
	{
		_array = NULL;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (_array != NULL)
		delete[] _array;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template <typename T>

T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return _array[index];
}