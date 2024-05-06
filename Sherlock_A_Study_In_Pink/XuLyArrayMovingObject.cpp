#include "arrayMovingObject.h"

ArrayMovingObject::ArrayMovingObject(int capacity) : capacity(capacity), count(0)
{
	arr_mv_objs = new MovingObject * [capacity];
}
ArrayMovingObject::~ArrayMovingObject()
{
	for (int i = 0; i < count; ++i)
		delete arr_mv_objs[i];
	delete[] arr_mv_objs;
	count = 0;
	arr_mv_objs = NULL;
}
bool ArrayMovingObject::isFull() const
{
	return capacity == count;
}
bool ArrayMovingObject::add(MovingObject* mv_obj)
{
	if (isFull())
		return false;
	arr_mv_objs[count++] = mv_obj;
	return true;
}
string ArrayMovingObject::str() const
{
	string result = "ArrayMovingObject[count=" + to_string(count) + ";capacity=" + to_string(capacity) + ";";
	for (int i = 0; i < count; ++i)
	{
		result += arr_mv_objs[i]->str();
		if (i < count - 1)
			result += ";";
	}
	result += "]";
	return result;
}