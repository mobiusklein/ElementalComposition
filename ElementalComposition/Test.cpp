#include "ElementalComposition.h"
#include "Element.h"
#include "PeriodicTable.h"
#include<iostream>
#include<string>


using namespace std;
using namespace elemental_composition;

int main() {
	ElementalComposition::initialize_periodic_table();
	ElementalComposition composition = ElementalComposition();
	ElementalComposition test_obj, test_obj2;
	Element elem_obj;
	string element = "O";
	int done;

	composition[element] = 2;
	composition["H"] = 5;
	cout << composition["H"] << " " << composition[element] << " Done" << endl;
	cout << composition["S"] << endl;
	cout << composition << endl;
	ElementalComposition dup = (composition + composition) * 3;
	cout << dup << endl;
	composition += dup;
	cout << composition << endl;
	cout << composition << endl;
	cout << composition.mass() << endl;
	composition = ElementalComposition({ { "O", 6 },{ "H", 12 },{ "C", 6 } });
	cout << composition << endl;
	cout << composition["O"] << endl;
	initializer_list< pair<element_t, int> > type_thing = { { "O", 6 },{ "H", 12 },{ "C", 6 } };
	ElementalComposition added = composition + type_thing;
	cout << (composition + type_thing) - ElementalComposition({ { "O", 6 }, { "H", 12 }, { "C", 6 } }) << endl;
	cout << composition << endl << composition.mass() << endl;
	test_obj = ElementalComposition(composition);
	test_obj = composition + composition;
	test_obj2 = composition * 2;
	cout << "Comparison " << (test_obj == test_obj2) << endl;

	test_obj = ElementalComposition(composition);
	test_obj += test_obj;
	cout << test_obj << endl;
	cout << "Comparison " << (test_obj == test_obj2) << endl;

	ElementSpecifier spec = ElementSpecifier();
	parse_isotope_string("C[13]", spec);
	cout << spec.element << " " << spec.isotope << endl;
	cout << spec << endl;
	cout << (std::string)spec << endl;

	test_obj = parse_formula("C6H12O6");
	cout << "Parsed " << test_obj << endl;
	cout << parse_formula("C4C[13]2(H2O)2") << endl;
	cin >> done;
}