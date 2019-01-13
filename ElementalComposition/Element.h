#pragma once
#include<string>
#include<memory>
#include<map>
#include<iostream>

using namespace std;

namespace elemental_composition {
	struct Isotope {
		Isotope();
		Isotope(double mass, double abundance, int neutrons, int neutrons_offset);
		~Isotope();

		int neutrons;
		int neutrons_offset;
		double mass;
		double abundance;

		friend std::ostream& operator<< (std::ostream& stream, const Isotope& isotope);
	};

	using _IsotopeMap = map<int, Isotope>;
	using IsotopeIterator = _IsotopeMap::const_iterator;


	struct ElementSpecifier {
		string element;
		int isotope;

		ElementSpecifier();
		~ElementSpecifier();
		
		ElementSpecifier(const string);
		ElementSpecifier(const char[]);
		ElementSpecifier(const string, const int);

		bool operator==(const ElementSpecifier) const;
		bool operator!=(const ElementSpecifier) const;

		operator string() const;

		friend std::ostream& operator<< (std::ostream& stream, const ElementSpecifier& element_spec);
	};

	struct IsotopeSet {
		IsotopeSet();
		IsotopeSet(_IsotopeMap isos);
		~IsotopeSet();

		//Attributes
		_IsotopeMap isotopes;
		Isotope monoisotopic;

		//Methods
		void add(Isotope);
		size_t size() const;

		IsotopeIterator find(int neutrons) const;

		_IsotopeMap::iterator begin() {
			return isotopes.begin();
		}

		_IsotopeMap::iterator end() {
			return isotopes.end();
		}

		IsotopeIterator begin() const {
			return isotopes.begin();
		}

		IsotopeIterator end() const {
			return isotopes.end();
		}

		IsotopeIterator cend() const {
			return isotopes.cend();
		}
	};

	class Element
	{
	public:
		Element();
		explicit Element(string symbol);
		Element(string symbol, IsotopeSet isotopes);
		~Element();

		bool operator==(string) const;
		bool operator==(const Element&) const;
		bool operator!=(string) const;
		bool operator!=(const Element&) const;

		double get_mass() const {
			return isotopes.monoisotopic.mass;
		}

		inline string get_symbol() const {
			return symbol;
		}

		inline void set_symbol(string sym) {
			symbol = sym;
		}

		IsotopeIterator get_isotope(int neutrons) const {
			return isotopes.find(neutrons);
		}

		const IsotopeSet& get_isotopes() const {
			return isotopes;
		}

		void add_isotope(Isotope);

		friend std::ostream& operator<< (std::ostream& stream, const Element& element);

	private:
		string symbol;
		IsotopeSet isotopes;
	};

	int parse_isotope_string(string isotope_string, ElementSpecifier& spec);
	int make_isotope_string(const string& element, const size_t isotopes, string& out);
}

namespace std {
	
	template<> struct hash<elemental_composition::ElementSpecifier>
	{
		typedef elemental_composition::ElementSpecifier argument_type;
		typedef size_t result_type;
		result_type operator()(argument_type const& s) const noexcept
		{
			result_type const h1(hash<string>{}(s.element));
			result_type const h2(hash<int>{}(s.isotope));
			return h1 ^ (h2 << 1);
		}
	};
}