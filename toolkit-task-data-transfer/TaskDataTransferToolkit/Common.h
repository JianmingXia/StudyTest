#pragma once

#define COL_DATA_SEPARATOR		","

template <typename T>
inline bool IN_VECTOR(const vector<T> &vec, T key)
{
	return find(vec.begin(), vec.end(), key) != vec.end();
}