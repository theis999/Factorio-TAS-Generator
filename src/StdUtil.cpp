#include "StdUtil.h"

const map<string, int> convert_vector_to_map(const vector<string> v)
{
	const size_t s = v.size();
	map<string, int> m{};
	for (int i = 0; i < s; i++)
	{
		m.insert({v[i], i});
	}
	return m;
}
