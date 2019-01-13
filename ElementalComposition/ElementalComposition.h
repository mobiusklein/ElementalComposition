#pragma once
#include<unordered_map>
#include<iostream>
#include<memory>
#include<string>
#include "Element.h"
#include "PeriodicTable.h"

using namespace std;

namespace elemental_composition {
	class ElementalComposition;

	using count_t = int;
	using element_t = ElementSpecifier;
	using element_count_t = unordered_map<element_t, count_t>;
	using element_count_initializer_t = initializer_list< pair<element_t, int> >;
	using ElementalCompositionPtr = shared_ptr<ElementalComposition>;

	class ElementalComposition
	{
	public:
		ElementalComposition();
		ElementalComposition(const element_count_initializer_t);
		ElementalComposition(const element_count_t);
		ElementalComposition(const ElementalComposition&);
		ElementalComposition(ElementalComposition&& composition);
		ElementalComposition(const ElementalCompositionPtr&);
		ElementalComposition(const ElementalCompositionPtr&& ref);
		~ElementalComposition();

		count_t& operator[](const element_t element);
		count_t& operator[](const Element&);

		count_t operator[](const element_t element) const;
		count_t operator[](const Element&) const;

		element_count_t::iterator begin();
		element_count_t::iterator end();
		element_count_t::const_iterator begin() const;
		element_count_t::const_iterator end() const;

		double mass() const;
		double mass(PeriodicTable& periodic_table) const;

		bool operator==(const ElementalComposition&) const;
		bool operator!=(const ElementalComposition&) const;
		
		ElementalComposition operator+(const ElementalComposition&) const;
		ElementalComposition operator-(const ElementalComposition&) const;
		ElementalComposition operator*(const int) const;
		ElementalComposition operator-() const;

		ElementalComposition& operator=(ElementalComposition&);
		ElementalComposition& operator+=(const ElementalComposition&);
		ElementalComposition& operator-=(const ElementalComposition&);
		ElementalComposition& operator*=(const int&);

		const element_count_t& get_element_counts() const;

		size_t size() const;

		friend std::ostream& operator<< (std::ostream& stream, const ElementalComposition& composition);

		std::string formula() const;

		static void initialize_periodic_table() {
			ElementalComposition::periodic_table = PeriodicTable::make_table_static();
		}

		static PeriodicTablePtr get_periodic_table() {
			return periodic_table;
		}

	private:
		static PeriodicTablePtr ElementalComposition::periodic_table;
		element_count_t element_count;
	};

	ElementalComposition parse_formula(const string& formula);
}
