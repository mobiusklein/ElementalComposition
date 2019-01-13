#include "ElementalComposition.h"
#include "PeriodicTable.h"
#include<iterator>
#include<memory>
#include<sstream>
#include<algorithm>
#include<vector>

namespace elemental_composition {
	ElementalComposition::ElementalComposition()
	{
		element_count = element_count_t();
	}

	ElementalComposition::ElementalComposition(const element_count_t counts) {
		element_count = element_count_t();
		for (auto iter : counts) {
			(*this)[iter.first] = iter.second;
		}
	}

	ElementalComposition::ElementalComposition(const ElementalComposition& composition) {
		element_count = element_count_t();
		for (auto iter : composition.get_element_counts()) {
			(*this)[iter.first] = iter.second;
		}
	}

	ElementalComposition::ElementalComposition(ElementalComposition&& composition) {
		element_count = std::move(composition.element_count);
	}

	ElementalComposition::ElementalComposition(const element_count_initializer_t initializer) {
		element_count = element_count_t();
		for (auto iter : initializer) {
			(*this)[iter.first] = iter.second;
		}
	}

	ElementalComposition::ElementalComposition(const ElementalCompositionPtr& ref) {
		element_count = element_count_t(ref->element_count);
	}

	ElementalComposition::ElementalComposition(const ElementalCompositionPtr&& ref) {
		element_count = ref->element_count;
	}

	const element_count_t& ElementalComposition::get_element_counts() const {
		return element_count;
	}

	ElementalComposition::~ElementalComposition() {}

	ElementalComposition& ElementalComposition::operator=(ElementalComposition& other) {
		element_count = other.element_count;
		return *this;
	}

	count_t& ElementalComposition::operator[](const element_t element) {
		return element_count[element];
	}

	count_t& ElementalComposition::operator[](const Element& element) {
		return (*this)[ElementSpecifier(element.get_symbol(), 0)];
	}

	count_t ElementalComposition::operator[](const element_t element) const{
		auto count = element_count.find(element);
		if (count == element_count.cend()) {
			return 0;
		}
		else {
			return count->second;
		}
	}

	count_t ElementalComposition::operator[](const Element& element) const{
		return (*this)[ElementSpecifier(element.get_symbol(), 0)];
	}

	element_count_t::iterator ElementalComposition::begin() {
		return element_count.begin();
	}

	element_count_t::iterator ElementalComposition::end() {
		return element_count.end();
	}

	element_count_t::const_iterator ElementalComposition::begin() const {
		return element_count.cbegin();
	}

	element_count_t::const_iterator ElementalComposition::end() const {
		return element_count.cend();
	}

	bool ElementalComposition::operator==(const ElementalComposition& other) const {
		return this->element_count == other.element_count;
	}

	bool ElementalComposition::operator!=(const ElementalComposition& other) const {
		return this->element_count != other.element_count;
	}

	ElementalComposition ElementalComposition::operator+(const ElementalComposition& other) const {
		ElementalComposition copy(this->get_element_counts());
		for (const auto &iter : other) {
			(copy)[iter.first] += iter.second;
		}
		return copy;
	}

	ElementalComposition ElementalComposition::operator-(const ElementalComposition& other) const {
		ElementalComposition copy(this->get_element_counts());
		for (const auto &iter : other) {
			(copy)[iter.first] -= iter.second;
		}
		return copy;
	}

	ElementalComposition ElementalComposition::operator*(const int i) const {
		ElementalComposition copy(this->get_element_counts());
		for (const auto &iter : (*this)) {
			(copy)[iter.first] = iter.second * i;
		}
		return copy;
	}

	ElementalComposition ElementalComposition::operator-() const {
		ElementalComposition copy;
		for (const auto& iter : *this) {
			copy[iter.first] = -iter.second;
		}
		return copy;
	}

	ElementalComposition& ElementalComposition::operator+=(const ElementalComposition& other) {
		ElementalComposition& ref = *this;
		for (const auto &iter : other) {
			ref[iter.first] += iter.second;
		}
		return ref;
	}

	ElementalComposition& ElementalComposition::operator-=(const ElementalComposition& other) {
		ElementalComposition& ref = *this;
		for (const auto &iter : other) {
			ref[iter.first] -= iter.second;
		}
		return ref;
	}

	ElementalComposition& ElementalComposition::operator*=(const int& i) {
		ElementalComposition& ref = *this;
		for (const auto &iter : ref) {
			ref[iter.first] *= i;
		}
		return ref;
	}

	size_t ElementalComposition::size() const {
		return element_count.size();
	}

	PeriodicTablePtr ElementalComposition::periodic_table = nullptr;

	double ElementalComposition::mass() const{
		if (ElementalComposition::periodic_table == nullptr) {
			ElementalComposition::initialize_periodic_table();
		}
		return mass(*ElementalComposition::periodic_table);
	}

	double ElementalComposition::mass(PeriodicTable& table) const{
		Element element;
		int status;
		double mass = 0.0;
		for (auto iter : (*this)) {
			const ElementSpecifier& spec = iter.first;
			status = table.get_element(spec.element, element);
			if (status == 0) {
				if (spec.isotope == 0) {
					mass += element.get_mass() * iter.second;
				}
				else {
					const IsotopeIterator isotope_iterator = element.get_isotope(spec.isotope);
					if (isotope_iterator != element.get_isotopes().cend()) {
						mass += isotope_iterator->second.mass * iter.second;
					}
					else {
						throw runtime_error("Invalid isotope for " + (string)spec);
					}
				}
			}
			else {
				throw runtime_error("Invalid element for " + (string)spec);
			}
		}
		return mass;
	}

	std::ostream& operator<< (std::ostream& stream, const ElementalComposition& composition) {
		stream << "ElementalComposition({" << endl;
		size_t i = 0;
		size_t n = composition.size();
		for (auto iter : composition) {
			stream << "  \"" << (string)iter.first << "\": " << iter.second;
			if (i < n) {
				stream << "," << endl;
			}
			i++;
		}
		stream << "})" << endl;
		return stream;
	}

	ElementalComposition parse_formula(const string& formula) {
		size_t prev_chem_symbol_start = formula.size();
		int i = prev_chem_symbol_start - 1;
		size_t seek_mode = 0;
		size_t paren_level = 0;
		size_t group_coef = 1;
		size_t brace_pos = 0;
		int isotope_num;
		int num_atoms = 0;
		char ch;
		string element_stack = "";
		string parse_stack = "";
		string isotope_string = "";

		ElementalComposition result = ElementalComposition();

		while (i >= 0) {
			if (seek_mode < 1) {
				if (formula[i] == ')') {
					seek_mode += 1;
					if (i + 1 == prev_chem_symbol_start) {
						group_coef = 1;
					}
					else if (isdigit(formula[i + 1])) {
						group_coef = stoi(formula.substr(i + 1, prev_chem_symbol_start));
					}
					i -= 1;
					continue;
				}
				if (isdigit(formula[i]) || formula[i] == '-') {
					i -= 1;
					continue;
				}
				else {
					//If the number of atoms is omitted then it is 1.
					if (i + 1 == prev_chem_symbol_start) {
						num_atoms = 1;
					}
					else {
						num_atoms = stoi(formula.substr(i + 1, prev_chem_symbol_start));
					}
					if (formula[i] == ']') {
						brace_pos = formula.rfind("[", prev_chem_symbol_start - 1);
						if (brace_pos == string::npos) {
							throw runtime_error("Bad Isotope String");
						}
						i = brace_pos - 1;
						isotope_num = stoi(formula.substr(brace_pos + 1, i));
					}
					else {
						isotope_num = 0;
					}
				}
				element_stack = "";
				while (i >= 0) {
					if (islower(formula[i])) {
						element_stack = formula[i] + element_stack;
					}
					else if (isupper(formula[i])) {
						element_stack = formula[i] + element_stack;
						break;
					}
					i--;
				}
				i--;
				prev_chem_symbol_start = i + 1;
				make_isotope_string(element_stack, isotope_num, isotope_string);
				if (isotope_string == "") {
					continue;
				}
				(result)[isotope_string] = num_atoms;
			}
			else {
				ch = formula[i];
				parse_stack = ch + parse_stack;
				i -= 1;
				if (ch == '(') {
					seek_mode -= 1;
					if (seek_mode == 0) {
						result += (parse_formula(parse_stack) * group_coef);
						prev_chem_symbol_start = i + 1;
						parse_stack = "";
					}
				}
				else if (ch == ')') {
					seek_mode += 1;
				}
				else {
					//continue accumulating
				}
			}
		}
		return result;
	}

	std::string ElementalComposition::formula() const {
		std::stringstream ss;
		std::vector<element_t> ordered;
		ordered.reserve(size());
		for (auto& pair_iter : *this) {
			ordered.emplace_back(pair_iter.first);
		}
		std::sort(ordered.begin(), ordered.end(), [](const auto& a, const auto& b) {
			return (a.element < b.element) && (a.isotope <= b.isotope);
		});
		for (const auto& iter : ordered) {
			ss << (std::string)iter << (*this)[iter];
		}
		return ss.str();
	}
}
