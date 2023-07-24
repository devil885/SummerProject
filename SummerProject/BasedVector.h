#pragma once
template <typename T>
class BasedVector
{
public:
	BasedVector() 
	{
		this->arr = new T[5];
		this->capacity = 5;
		this->size = 0;
	}

	BasedVector(const BasedVector& other)
	{
		this->arr = new T[other.capacity];
			for (int i = 0; i < other.size; i++)
			{
				this->arr[i] = other[i];
			}
			size = other.size;
			capacity = other.capacity;
	}

	~BasedVector() { clear(); }

	BasedVector& operator=(const BasedVector& other) 
	{
		if (this != &other)
		{
			T* betterArr = new T[other.size];
			clear();
			for (int i = 0; i < other.size; i++)
			{
				betterArr[i] = other[i];
			}
			arr = betterArr;
			size = other.size;
			capacity = other.capacity;
		}
		return *this;
	}

	const T& operator[](const int index)const
	{
		if (index > size - 1)
		{
			throw std::out_of_range("Index out of range");
		}
		return arr[index];
	}

	T& operator[](const int index) 
	{
		if (index>size-1)
		{
			throw std::out_of_range("Index out of range");
		}
		return arr[index];
	}
	
	
	void push(const T& elem) 
	{
		if (size>=capacity)
		{
			resize();
		}
		arr[size] = elem;
		size++;
	}

private:
	T* arr;
	int capacity;
	int size;

	void resize() 
	{
		T* betterArr = new T[capacity*2];
		for (int i = 0; i < size; i++)
		{
			betterArr[i] = arr[i];
		}
		delete[] arr;
		arr = betterArr;
	}

	void clear() { delete[] arr; }
	
};