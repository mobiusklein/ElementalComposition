#pragma once
#include<unordered_map>
#include<memory>
#include "Element.h"

using namespace std;


namespace elemental_composition {
	class PeriodicTable;

	using _ElementMap = unordered_map<string, Element>;
	using iterator = _ElementMap::iterator;
	using const_iterator = _ElementMap::const_iterator;
	using ConstElementIterator = _ElementMap::const_iterator;
	using PeriodicTablePtr = shared_ptr<PeriodicTable>;

	class PeriodicTable
	{
	public:
		PeriodicTable();
		~PeriodicTable();

		size_t size();
		int get_element(string symbol, Element& outref);
		Element& operator[](string);
		void add_element(Element& element);


		iterator begin() {
			return elements.begin();
		}

		iterator end() {
			return elements.end();
		}

		const_iterator begin() const {
			return elements.cbegin();
		}

		const_iterator end() const {
			return elements.cend();
		}

		static PeriodicTablePtr make_table_static();

	private:
		_ElementMap elements;

	};


}