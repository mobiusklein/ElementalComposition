#include "Element.h"
#include "PeriodicTable.h"
#include <utility>
#include <vector>



namespace elemental_composition {
	Isotope::Isotope() : mass(0), abundance(0), neutrons(0), neutrons_offset(0) {}
	Isotope::~Isotope() {};

	Isotope::Isotope(double mass, double abundance, int neutrons, int neutrons_offset) : mass(mass), abundance(abundance),
		neutrons(neutrons), neutrons_offset(neutrons_offset) {
	}

	std::ostream& operator<< (std::ostream& stream, const Isotope& isotope) {
		stream << "Isotope(" << isotope.mass << ", " << isotope.abundance << ", "
			<< isotope.neutrons << ", " << isotope.neutrons_offset << ")";
		return stream;
	}

	IsotopeSet::IsotopeSet() {
		isotopes = _IsotopeMap();
	}

	IsotopeSet::IsotopeSet(_IsotopeMap isos) {
		isotopes = isos;
	}

	IsotopeSet::~IsotopeSet() {}

	size_t IsotopeSet::size() const {
		return isotopes.size();
	}

	void IsotopeSet::add(Isotope isotope) {
		isotopes.insert(std::pair<int, Isotope>(isotope.neutrons, isotope));
		if (isotope.neutrons_offset == 0) {
			monoisotopic = isotope;
		}
	}

	IsotopeIterator IsotopeSet::find(const int neutrons) const {
		return isotopes.find(neutrons);
	}

	Element::Element()
	{
		isotopes = IsotopeSet();
	}

	Element::Element(string symbol) {
		set_symbol(symbol);
		isotopes = IsotopeSet();
	}

	Element::Element(string sym, IsotopeSet isos)
	{
		set_symbol(sym);
		isotopes = isos;
	}

	void Element::add_isotope(Isotope isotope) {
		isotopes.add(isotope);
	}

	Element::~Element()
	{
	}

	bool Element::operator==(string other) const {
		return symbol == other;
	}

	bool Element::operator==(const Element& other) const {
		return symbol == other.symbol;
	}

	bool Element::operator!=(string other) const {
		return symbol != other;
	}

	bool Element::operator!=(const Element& other) const {
		return symbol != other.symbol;
	}

	std::ostream& operator<< (std::ostream& stream, const Element& element) {
		stream << "Element(" << element.get_symbol() << ", " << element.get_mass() << ")";
		return stream;
	}

	ElementSpecifier::ElementSpecifier() : element(""), isotope(0) {}
	ElementSpecifier::ElementSpecifier(const char element[] ) : ElementSpecifier(string(element)) {}

	ElementSpecifier::ElementSpecifier(const string element) {
		int status = parse_isotope_string(element, *this);
	}
	ElementSpecifier::ElementSpecifier(const string element, const int isotope) : element(element), isotope(isotope) {}

	bool ElementSpecifier::operator==(const ElementSpecifier element_spec) const
	{
		return element == element_spec.element && isotope == element_spec.isotope;
	}

	bool ElementSpecifier::operator!=(const ElementSpecifier element_spec) const
	{
		return element != element_spec.element || isotope != element_spec.isotope;
	}

	ElementSpecifier::operator string() const{
		string s;
		make_isotope_string(element, isotope, s);
		return s;
	}

	std::ostream& operator<< (std::ostream& stream, const ElementSpecifier& element_spec) {
		stream << "ElementSpecifier(" << element_spec.element << ", " << element_spec.isotope << ")";
		return stream;
	}

	ElementSpecifier::~ElementSpecifier() {}

	int parse_isotope_string(string isotope_string, ElementSpecifier& spec) {
		size_t n = isotope_string.size();
		string element = "";
		bool has_isotope = false;
		string isotope_part = "";
		for (auto c : isotope_string) {
			if (c == '[') {
				has_isotope = true;
				continue;
			}
			else if (c == ']') {
				break;
			}
			if (has_isotope) {
				isotope_part += c;
			}
			else {
				element += c;
			}
		}
		spec.element = element;
		spec.isotope = 0;
		if (has_isotope) {
			spec.isotope = stoi(isotope_part);
		}
		return 0;
	}
	
	int make_isotope_string(const string& element, const size_t isotopes, string& out) {
		char buffer[100];
		if (isotopes == 0) {
			out = element;
			return 0;
		}
		snprintf(buffer, 100, "%s[%u]", element.c_str(), isotopes);
		out = buffer;
		return 0;
	}
}
