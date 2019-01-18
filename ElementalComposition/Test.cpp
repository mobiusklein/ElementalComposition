#include "ElementalComposition.h"
#include "Element.h"
#include "PeriodicTable.h"
#include<iostream>
#include<cassert>
#include<chrono>
#include<string>


using namespace std;
using namespace elemental_composition;

int initialization_test() {
	ElementalComposition composition = ElementalComposition();
	ElementalComposition test_obj, test_obj2;
	Element elem_obj;
	string element = "O";

	composition[element] = 2;
	composition[{"H", 0}] = 5;
	assert(composition["H"] == 5);
	assert(composition["S"] == 0);
	ElementalComposition dup = (composition + composition) * 3;
	composition += dup;
	assert(abs(composition.mass() - 259.203) < 1e-3);
	composition = ElementalComposition({ { "O", 6 },{ "H", 12 },{ "C", 6 } });
	assert(composition["O"] == 6);
	assert(abs(composition.mass() - 180.063) < 1e-3);
	initializer_list< pair<element_t, int> > type_thing = { { "O", 6 },{ "H", 12 },{ "C", 6 } };
	// alternative initialization
	assert(composition == type_thing);
	// arithmetic operations
	ElementalComposition added = composition + type_thing;
	assert(added == composition * 2);
	assert(
		(composition + type_thing) - ElementalComposition(
			{ { "O", 6 },{ "H", 12 },{ "C", 6 } }) == composition);
	test_obj = ElementalComposition(composition);
	test_obj = composition + composition;
	test_obj2 = composition * 2;
	assert(test_obj == test_obj2);

	return 0;
}

int negation_test() {
	ElementalComposition composition = parse_formula("C6H12O6");
	composition = -composition;
	assert(composition["O"] == -6);
	return 0;
}

int formula_parse_test() {
	ElementalComposition test_obj;
	ElementalComposition ref({ {"C", 6}, {"H", 12}, {"O", 6} });
	test_obj = parse_formula("C6H12O6");
	assert(test_obj == ref);
	assert(test_obj.formula() == "C6H12O6");
	test_obj = parse_formula("C4C[13]2(H2O)2");
	ref = ElementalComposition({ {"C", 4}, {{"C", 13}, 2}, {"H", 4}, {"O", 2} });
	assert(test_obj == ref);
	return 0;
}

int element_specifier_test() {
	ElementSpecifier spec = ElementSpecifier();
	parse_isotope_string("C[13]", spec);
	assert(spec.element == "C");
	assert(spec.isotope == 13);
	assert((std::string)spec == "C[13]");
	parse_isotope_string("O", spec);
	assert(spec.element == "O");
	assert(spec.isotope == 0);
	assert((std::string)spec == "O");
	return 0;
}

int perf_test() {
	ElementalComposition::initialize_periodic_table();
	ElementalComposition composition = ElementalComposition();
	Element elem_obj;
	string element = "O";

	composition[element] = 2;
	composition[{"H", 0}] = 5;
	cout << "Element Resolution" << endl;
	auto upper_limit = std::pow(2, 20) - 1;
	auto clock = std::chrono::steady_clock();
	auto start = clock.now();
	for (std::size_t i = 0; i < upper_limit; i++) {
		bool t = composition[{"H", 0}] == 5;
		assert(t);
	}
	auto end = clock.now();
	auto diff = std::chrono::duration<double>(end - start);
	cout << "Fully Specified " << diff.count() << " s (" <<  (
		diff.count() / upper_limit) << " s per)" << endl;

	start = clock.now();
	for (std::size_t i = 0; i < upper_limit; i++) {
		bool t = composition["H"] == 5;
		assert(t);
	}
	end = clock.now();
	diff = std::chrono::duration<double>(end - start);
	cout << "Element Parsing " << diff.count() << " s (" << (
		diff.count() / upper_limit) << " s per)" << endl;

	cout << "Element Lookup" << endl;
	PeriodicTable& table = *composition.get_periodic_table();
	start = clock.now();
	for (std::size_t i = 0; i < (upper_limit); i++) {
		elem_obj = table["O"];
	}
	end = clock.now();
	diff = std::chrono::duration<double>(end - start);
	cout << "Raw lookup " << diff.count() << " s (" << (
		diff.count() / upper_limit) << " s per)" << endl;

	start = clock.now();
	for (std::size_t i = 0; i < (upper_limit); i++) {
		table.get_element("O", elem_obj);
	}
	end = clock.now();
	diff = std::chrono::duration<double>(end - start);
	cout << "Status code " << diff.count() << " s (" << (
		diff.count() / upper_limit) << " s per)" << endl;

	double time_to_look_up = diff.count() / upper_limit;

	upper_limit /= 10;

	cout << "Formula Parsing" << endl;
	start = clock.now();
	for (std::size_t i = 0; i < upper_limit; i++) {
		composition = parse_formula("C6H12O6");
	}	
	end = clock.now();
	diff = std::chrono::duration<double>(end - start);
	cout << "Parsing " << diff.count() << " s (" << (
		diff.count() / upper_limit) << " s per)" << endl;

	cout << "Mass Calculation" << endl;
	composition = parse_formula("C6H12O6");
	start = clock.now();
	for (std::size_t i = 0; i < (upper_limit); i++) {
		composition.mass();
	}
	end = clock.now();
	diff = std::chrono::duration<double>(end - start);
	cout << "Massing " << diff.count() << " s (" << (
		diff.count() / upper_limit) << " s per)" << endl;
	cout << "Lookup Cost " << time_to_look_up * composition.size() << endl;
	cout << "Mass Arithmetic " << (diff.count() / upper_limit) - \
		(time_to_look_up * composition.size()) << endl;
	return 0;
}

int main() {
	int done;
	cout << "Running Elemental Composition Tests" << endl;
	ElementalComposition::initialize_periodic_table();
	initialization_test();
	negation_test();
	perf_test();
	element_specifier_test();
	formula_parse_test();
	cout << "Testing Finished" << endl;
	cin >> done;
	return 0;
}