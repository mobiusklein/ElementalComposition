#include "PeriodicTable.h"

namespace elemental_composition {
	PeriodicTable::PeriodicTable()
	{
		elements = _ElementMap();
	}

	size_t PeriodicTable::size() {
		return elements.size();
	}

	void PeriodicTable::add_element(Element& element) {
		elements[element.get_symbol()] = element;
	}

	int PeriodicTable::get_element(string symbol, Element& outref) {
		iterator found = elements.find(symbol);
		if (found == elements.end()) {
			return 1;
		}
		else {
			outref = (found->second);
			return 0;
		}
	}

	Element& PeriodicTable::operator[](string symbol) {
		return elements[symbol];
	}

	PeriodicTablePtr PeriodicTable::make_table_static() {
		PeriodicTablePtr table = make_shared<PeriodicTable>();
		Element element;

		element = Element("H+");
		element.add_isotope({ 1.007276, 1.000000, 1, 0 });
		table->add_element(element);

		element = Element("H");
		element.add_isotope({ 1.007825, 0.999885, 1, 0 });
		element.add_isotope({ 2.014102, 0.000115, 2, 1 });
		table->add_element(element);

		element = Element("He");
		element.add_isotope({ 3.016029, 0.000001, 3, -1 });
		element.add_isotope({ 4.002603, 0.999999, 4, 0 });
		table->add_element(element);

		element = Element("Li");
		element.add_isotope({ 6.015123, 0.075900, 6, -1 });
		element.add_isotope({ 7.016005, 0.924100, 7, 0 });
		table->add_element(element);

		element = Element("Be");
		element.add_isotope({ 9.012182, 1.000000, 9, 0 });
		table->add_element(element);

		element = Element("B");
		element.add_isotope({ 10.012937, 0.199000, 10, -1 });
		element.add_isotope({ 11.009305, 0.801000, 11, 0 });
		table->add_element(element);

		element = Element("C");
		element.add_isotope({ 12.000000, 0.989300, 12, 0 });
		element.add_isotope({ 13.003355, 0.010700, 13, 1 });
		table->add_element(element);

		element = Element("N");
		element.add_isotope({ 14.003074, 0.996360, 14, 0 });
		element.add_isotope({ 15.000109, 0.003640, 15, 1 });
		table->add_element(element);

		element = Element("O");
		element.add_isotope({ 15.994915, 0.997570, 16, 0 });
		element.add_isotope({ 16.999132, 0.000380, 17, 1 });
		element.add_isotope({ 17.999161, 0.002050, 18, 2 });
		table->add_element(element);

		element = Element("F");
		element.add_isotope({ 18.998403, 1.000000, 19, 0 });
		table->add_element(element);

		element = Element("Ne");
		element.add_isotope({ 19.992440, 0.904800, 20, 0 });
		element.add_isotope({ 20.993847, 0.002700, 21, 1 });
		element.add_isotope({ 21.991385, 0.092500, 22, 2 });
		table->add_element(element);

		element = Element("Na");
		element.add_isotope({ 22.989769, 1.000000, 23, 0 });
		table->add_element(element);

		element = Element("Mg");
		element.add_isotope({ 23.985042, 0.789900, 24, 0 });
		element.add_isotope({ 24.985837, 0.100000, 25, 1 });
		element.add_isotope({ 25.982593, 0.110100, 26, 2 });
		table->add_element(element);

		element = Element("Al");
		element.add_isotope({ 26.981539, 1.000000, 27, 0 });
		table->add_element(element);

		element = Element("Si");
		element.add_isotope({ 27.976927, 0.922230, 28, 0 });
		element.add_isotope({ 28.976495, 0.046850, 29, 1 });
		element.add_isotope({ 29.973770, 0.030920, 30, 2 });
		table->add_element(element);

		element = Element("P");
		element.add_isotope({ 30.973762, 1.000000, 31, 0 });
		table->add_element(element);

		element = Element("S");
		element.add_isotope({ 31.972071, 0.949900, 32, 0 });
		element.add_isotope({ 32.971459, 0.007500, 33, 1 });
		element.add_isotope({ 33.967867, 0.042500, 34, 2 });
		element.add_isotope({ 35.967081, 0.000100, 36, 4 });
		table->add_element(element);

		element = Element("Cl");
		element.add_isotope({ 34.968853, 0.757600, 35, 0 });
		element.add_isotope({ 36.965903, 0.242400, 37, 2 });
		table->add_element(element);

		element = Element("K");
		element.add_isotope({ 38.963707, 0.932581, 39, 0 });
		element.add_isotope({ 39.963998, 0.000117, 40, 1 });
		element.add_isotope({ 40.961826, 0.067302, 41, 2 });
		table->add_element(element);

		element = Element("Ar");
		element.add_isotope({ 35.967545, 0.003365, 36, -4 });
		element.add_isotope({ 37.962732, 0.000632, 38, -2 });
		element.add_isotope({ 39.962383, 0.996003, 40, 0 });
		table->add_element(element);

		element = Element("Ca");
		element.add_isotope({ 39.962591, 0.969410, 40, 0 });
		element.add_isotope({ 41.958618, 0.006470, 42, 2 });
		element.add_isotope({ 42.958767, 0.001350, 43, 3 });
		element.add_isotope({ 43.955482, 0.020860, 44, 4 });
		element.add_isotope({ 45.953693, 0.000040, 46, 6 });
		element.add_isotope({ 47.952534, 0.001870, 48, 8 });
		table->add_element(element);

		element = Element("Sc");
		element.add_isotope({ 44.955912, 1.000000, 45, 0 });
		table->add_element(element);

		element = Element("Ti");
		element.add_isotope({ 45.952632, 0.082500, 46, -2 });
		element.add_isotope({ 46.951763, 0.074400, 47, -1 });
		element.add_isotope({ 47.947946, 0.737200, 48, 0 });
		element.add_isotope({ 48.947870, 0.054100, 49, 1 });
		element.add_isotope({ 49.944791, 0.051800, 50, 2 });
		table->add_element(element);

		element = Element("V");
		element.add_isotope({ 49.947159, 0.002500, 50, -1 });
		element.add_isotope({ 50.943959, 0.997500, 51, 0 });
		table->add_element(element);

		element = Element("Cr");
		element.add_isotope({ 49.946044, 0.043450, 50, -2 });
		element.add_isotope({ 51.940508, 0.837890, 52, 0 });
		element.add_isotope({ 52.940649, 0.095010, 53, 1 });
		element.add_isotope({ 53.938880, 0.023650, 54, 2 });
		table->add_element(element);

		element = Element("Fe");
		element.add_isotope({ 55.934937, 0.917540, 56, 0 });
		element.add_isotope({ 56.935394, 0.021190, 57, 1 });
		element.add_isotope({ 57.933276, 0.002820, 58, 2 });
		table->add_element(element);

		element = Element("Mn");
		element.add_isotope({ 54.938045, 1.000000, 55, 0 });
		table->add_element(element);

		element = Element("Ni");
		element.add_isotope({ 57.935343, 0.680769, 58, 0 });
		element.add_isotope({ 59.930786, 0.262231, 60, 2 });
		element.add_isotope({ 60.931056, 0.011399, 61, 3 });
		element.add_isotope({ 61.928345, 0.036345, 62, 4 });
		element.add_isotope({ 63.927966, 0.009256, 64, 6 });
		table->add_element(element);

		element = Element("Co");
		element.add_isotope({ 58.933195, 1.000000, 59, 0 });
		table->add_element(element);

		element = Element("Cu");
		element.add_isotope({ 62.929597, 0.691500, 63, 0 });
		element.add_isotope({ 64.927790, 0.308500, 65, 2 });
		table->add_element(element);

		element = Element("Zn");
		element.add_isotope({ 63.929142, 0.482680, 64, 0 });
		element.add_isotope({ 65.926033, 0.279750, 66, 2 });
		element.add_isotope({ 66.927127, 0.041020, 67, 3 });
		element.add_isotope({ 67.924844, 0.190240, 68, 4 });
		element.add_isotope({ 69.925319, 0.006310, 70, 6 });
		table->add_element(element);

		element = Element("Ga");
		element.add_isotope({ 68.925574, 0.601080, 69, 0 });
		element.add_isotope({ 70.924701, 0.398920, 71, 2 });
		table->add_element(element);

		element = Element("Ge");
		element.add_isotope({ 69.924247, 0.203800, 70, -4 });
		element.add_isotope({ 71.922076, 0.273100, 72, -2 });
		element.add_isotope({ 72.923459, 0.077600, 73, -1 });
		element.add_isotope({ 73.921178, 0.367200, 74, 0 });
		element.add_isotope({ 75.921403, 0.078300, 76, 2 });
		table->add_element(element);

		element = Element("As");
		element.add_isotope({ 74.921597, 1.000000, 75, 0 });
		table->add_element(element);

		element = Element("Se");
		element.add_isotope({ 73.922476, 0.008900, 74, -6 });
		element.add_isotope({ 75.919214, 0.093700, 76, -4 });
		element.add_isotope({ 76.919914, 0.076300, 77, -3 });
		element.add_isotope({ 77.917309, 0.237700, 78, -2 });
		element.add_isotope({ 79.916521, 0.496100, 80, 0 });
		element.add_isotope({ 81.916699, 0.087300, 82, 2 });
		table->add_element(element);

		element = Element("Br");
		element.add_isotope({ 78.918337, 0.506900, 79, 0 });
		element.add_isotope({ 80.916291, 0.493100, 81, 2 });
		table->add_element(element);

		element = Element("Kr");
		element.add_isotope({ 77.920365, 0.003550, 78, -6 });
		element.add_isotope({ 79.916379, 0.022860, 80, -4 });
		element.add_isotope({ 81.913484, 0.115930, 82, -2 });
		element.add_isotope({ 82.914136, 0.115000, 83, -1 });
		element.add_isotope({ 83.911507, 0.569870, 84, 0 });
		element.add_isotope({ 85.910611, 0.172790, 86, 2 });
		table->add_element(element);

		element = Element("Rb");
		element.add_isotope({ 84.911790, 0.721700, 85, 0 });
		element.add_isotope({ 86.909181, 0.278300, 87, 2 });
		table->add_element(element);

		element = Element("Sr");
		element.add_isotope({ 83.913425, 0.005600, 84, -4 });
		element.add_isotope({ 85.909260, 0.098600, 86, -2 });
		element.add_isotope({ 86.908877, 0.070000, 87, -1 });
		element.add_isotope({ 87.905612, 0.825800, 88, 0 });
		table->add_element(element);

		element = Element("Y");
		element.add_isotope({ 88.905848, 1.000000, 89, 0 });
		table->add_element(element);

		element = Element("Zr");
		element.add_isotope({ 89.904704, 0.514500, 90, 0 });
		element.add_isotope({ 90.905646, 0.112200, 91, 1 });
		element.add_isotope({ 91.905041, 0.171500, 92, 2 });
		element.add_isotope({ 93.906315, 0.173800, 94, 4 });
		element.add_isotope({ 95.908273, 0.028000, 96, 6 });
		table->add_element(element);

		element = Element("Nb");
		element.add_isotope({ 92.906378, 1.000000, 93, 0 });
		table->add_element(element);

		element = Element("Mo");
		element.add_isotope({ 91.906811, 0.147700, 92, -6 });
		element.add_isotope({ 93.905088, 0.092300, 94, -4 });
		element.add_isotope({ 94.905842, 0.159000, 95, -3 });
		element.add_isotope({ 95.904680, 0.166800, 96, -2 });
		element.add_isotope({ 96.906021, 0.095600, 97, -1 });
		element.add_isotope({ 97.905408, 0.241900, 98, 0 });
		element.add_isotope({ 99.907477, 0.096700, 100, 2 });
		table->add_element(element);

		element = Element("Ru");
		element.add_isotope({ 95.907598, 0.055400, 96, -6 });
		element.add_isotope({ 97.905287, 0.018700, 98, -4 });
		element.add_isotope({ 98.905939, 0.127600, 99, -3 });
		element.add_isotope({ 99.904219, 0.126000, 100, -2 });
		element.add_isotope({ 100.905582, 0.170600, 101, -1 });
		element.add_isotope({ 101.904349, 0.315500, 102, 0 });
		element.add_isotope({ 103.905433, 0.186200, 104, 2 });
		table->add_element(element);

		element = Element("Rh");
		element.add_isotope({ 102.905504, 1.000000, 103, 0 });
		table->add_element(element);

		element = Element("Pd");
		element.add_isotope({ 101.905609, 0.010200, 102, -4 });
		element.add_isotope({ 103.904036, 0.111400, 104, -2 });
		element.add_isotope({ 104.905085, 0.223300, 105, -1 });
		element.add_isotope({ 105.903486, 0.273300, 106, 0 });
		element.add_isotope({ 107.903892, 0.264600, 108, 2 });
		element.add_isotope({ 109.905153, 0.117200, 110, 4 });
		table->add_element(element);

		element = Element("Ag");
		element.add_isotope({ 106.905097, 0.518390, 107, 0 });
		element.add_isotope({ 108.904752, 0.481610, 109, 2 });
		table->add_element(element);

		element = Element("Cd");
		element.add_isotope({ 105.906459, 0.012500, 106, -8 });
		element.add_isotope({ 107.904184, 0.008900, 108, -6 });
		element.add_isotope({ 109.903002, 0.124900, 110, -4 });
		element.add_isotope({ 110.904178, 0.128000, 111, -3 });
		element.add_isotope({ 111.902758, 0.241300, 112, -2 });
		element.add_isotope({ 112.904402, 0.122200, 113, -1 });
		element.add_isotope({ 113.903358, 0.287300, 114, 0 });
		element.add_isotope({ 115.904756, 0.074900, 116, 2 });
		table->add_element(element);

		element = Element("In");
		element.add_isotope({ 112.904058, 0.042900, 113, -2 });
		element.add_isotope({ 114.903878, 0.957100, 115, 0 });
		table->add_element(element);

		element = Element("Sn");
		element.add_isotope({ 111.904818, 0.009700, 112, -8 });
		element.add_isotope({ 113.902779, 0.006600, 114, -6 });
		element.add_isotope({ 114.903342, 0.003400, 115, -5 });
		element.add_isotope({ 115.901741, 0.145400, 116, -4 });
		element.add_isotope({ 116.902952, 0.076800, 117, -3 });
		element.add_isotope({ 117.901603, 0.242200, 118, -2 });
		element.add_isotope({ 118.903308, 0.085900, 119, -1 });
		element.add_isotope({ 119.902195, 0.325800, 120, 0 });
		element.add_isotope({ 121.903439, 0.046300, 122, 2 });
		element.add_isotope({ 123.905274, 0.057900, 124, 4 });
		table->add_element(element);

		element = Element("Sb");
		element.add_isotope({ 120.903816, 0.572100, 121, 0 });
		element.add_isotope({ 122.904214, 0.427900, 123, 2 });
		table->add_element(element);

		element = Element("I");
		element.add_isotope({ 126.904473, 1.000000, 127, 0 });
		table->add_element(element);

		element = Element("Te");
		element.add_isotope({ 119.904020, 0.000900, 120, -10 });
		element.add_isotope({ 121.903044, 0.025500, 122, -8 });
		element.add_isotope({ 122.904270, 0.008900, 123, -7 });
		element.add_isotope({ 123.902818, 0.047400, 124, -6 });
		element.add_isotope({ 124.904431, 0.070700, 125, -5 });
		element.add_isotope({ 125.903312, 0.188400, 126, -4 });
		element.add_isotope({ 127.904463, 0.317400, 128, -2 });
		element.add_isotope({ 129.906224, 0.340800, 130, 0 });
		table->add_element(element);

		element = Element("Xe");
		element.add_isotope({ 123.905893, 0.000952, 124, -8 });
		element.add_isotope({ 125.904274, 0.000890, 126, -6 });
		element.add_isotope({ 127.903531, 0.019102, 128, -4 });
		element.add_isotope({ 128.904779, 0.264006, 129, -3 });
		element.add_isotope({ 129.903508, 0.040710, 130, -2 });
		element.add_isotope({ 130.905082, 0.212324, 131, -1 });
		element.add_isotope({ 131.904154, 0.269086, 132, 0 });
		element.add_isotope({ 133.905394, 0.104357, 134, 2 });
		element.add_isotope({ 135.907219, 0.088573, 136, 4 });
		table->add_element(element);

		element = Element("Cs");
		element.add_isotope({ 132.905452, 1.000000, 133, 0 });
		table->add_element(element);

		element = Element("Ba");
		element.add_isotope({ 129.906321, 0.001060, 130, -8 });
		element.add_isotope({ 131.905061, 0.001010, 132, -6 });
		element.add_isotope({ 133.904508, 0.024170, 134, -4 });
		element.add_isotope({ 134.905689, 0.065920, 135, -3 });
		element.add_isotope({ 135.904576, 0.078540, 136, -2 });
		element.add_isotope({ 136.905827, 0.112320, 137, -1 });
		element.add_isotope({ 137.905247, 0.716980, 138, 0 });
		table->add_element(element);

		element = Element("La");
		element.add_isotope({ 137.907112, 0.000900, 138, -1 });
		element.add_isotope({ 138.906353, 0.999100, 139, 0 });
		table->add_element(element);

		element = Element("Ce");
		element.add_isotope({ 135.907172, 0.001850, 136, -4 });
		element.add_isotope({ 137.905991, 0.002510, 138, -2 });
		element.add_isotope({ 139.905439, 0.884500, 140, 0 });
		element.add_isotope({ 141.909244, 0.111140, 142, 2 });
		table->add_element(element);

		element = Element("Pr");
		element.add_isotope({ 140.907653, 1.000000, 141, 0 });
		table->add_element(element);

		element = Element("Nd");
		element.add_isotope({ 141.907723, 0.272000, 142, 0 });
		element.add_isotope({ 142.909814, 0.122000, 143, 1 });
		element.add_isotope({ 143.910087, 0.238000, 144, 2 });
		element.add_isotope({ 144.912574, 0.083000, 145, 3 });
		element.add_isotope({ 145.913117, 0.172000, 146, 4 });
		element.add_isotope({ 147.916893, 0.057000, 148, 6 });
		element.add_isotope({ 149.920891, 0.056000, 150, 8 });
		table->add_element(element);

		element = Element("Sm");
		element.add_isotope({ 143.911999, 0.030700, 144, -8 });
		element.add_isotope({ 146.914898, 0.149900, 147, -5 });
		element.add_isotope({ 147.914823, 0.112400, 148, -4 });
		element.add_isotope({ 148.917185, 0.138200, 149, -3 });
		element.add_isotope({ 149.917275, 0.073800, 150, -2 });
		element.add_isotope({ 151.919732, 0.267500, 152, 0 });
		element.add_isotope({ 153.922209, 0.227500, 154, 2 });
		table->add_element(element);

		element = Element("Eu");
		element.add_isotope({ 150.919850, 0.478100, 151, -2 });
		element.add_isotope({ 152.921230, 0.521900, 153, 0 });
		table->add_element(element);

		element = Element("Gd");
		element.add_isotope({ 151.919791, 0.002000, 152, -6 });
		element.add_isotope({ 153.920866, 0.021800, 154, -4 });
		element.add_isotope({ 154.922622, 0.148000, 155, -3 });
		element.add_isotope({ 155.922123, 0.204700, 156, -2 });
		element.add_isotope({ 156.923960, 0.156500, 157, -1 });
		element.add_isotope({ 157.924104, 0.248400, 158, 0 });
		element.add_isotope({ 159.927054, 0.218600, 160, 2 });
		table->add_element(element);

		element = Element("Tb");
		element.add_isotope({ 158.925347, 1.000000, 159, 0 });
		table->add_element(element);

		element = Element("Dy");
		element.add_isotope({ 155.924283, 0.000560, 156, -8 });
		element.add_isotope({ 157.924409, 0.000950, 158, -6 });
		element.add_isotope({ 159.925197, 0.023290, 160, -4 });
		element.add_isotope({ 160.926933, 0.188890, 161, -3 });
		element.add_isotope({ 161.926798, 0.254750, 162, -2 });
		element.add_isotope({ 162.928731, 0.248960, 163, -1 });
		element.add_isotope({ 163.929175, 0.282600, 164, 0 });
		table->add_element(element);

		element = Element("Ho");
		element.add_isotope({ 164.930322, 1.000000, 165, 0 });
		table->add_element(element);

		element = Element("Er");
		element.add_isotope({ 161.928778, 0.001390, 162, -4 });
		element.add_isotope({ 163.929200, 0.016010, 164, -2 });
		element.add_isotope({ 165.930293, 0.335030, 166, 0 });
		element.add_isotope({ 166.932048, 0.228690, 167, 1 });
		element.add_isotope({ 167.932370, 0.269780, 168, 2 });
		element.add_isotope({ 169.935464, 0.149100, 170, 4 });
		table->add_element(element);

		element = Element("Tm");
		element.add_isotope({ 168.934213, 1.000000, 169, 0 });
		table->add_element(element);

		element = Element("Yb");
		element.add_isotope({ 167.933897, 0.001300, 168, -6 });
		element.add_isotope({ 169.934762, 0.030400, 170, -4 });
		element.add_isotope({ 170.936326, 0.142800, 171, -3 });
		element.add_isotope({ 171.936382, 0.218300, 172, -2 });
		element.add_isotope({ 172.938211, 0.161300, 173, -1 });
		element.add_isotope({ 173.938862, 0.318300, 174, 0 });
		element.add_isotope({ 175.942572, 0.127600, 176, 2 });
		table->add_element(element);

		element = Element("Lu");
		element.add_isotope({ 174.940772, 0.974100, 175, 0 });
		element.add_isotope({ 175.942686, 0.025900, 176, 1 });
		table->add_element(element);

		element = Element("Hf");
		element.add_isotope({ 173.940046, 0.001600, 174, -6 });
		element.add_isotope({ 175.941409, 0.052600, 176, -4 });
		element.add_isotope({ 176.943221, 0.186000, 177, -3 });
		element.add_isotope({ 177.943699, 0.272800, 178, -2 });
		element.add_isotope({ 178.945816, 0.136200, 179, -1 });
		element.add_isotope({ 179.946550, 0.350800, 180, 0 });
		table->add_element(element);

		element = Element("Ta");
		element.add_isotope({ 179.947465, 0.000120, 180, -1 });
		element.add_isotope({ 180.947996, 0.999880, 181, 0 });
		table->add_element(element);

		element = Element("W");
		element.add_isotope({ 179.946704, 0.001200, 180, -4 });
		element.add_isotope({ 181.948204, 0.265000, 182, -2 });
		element.add_isotope({ 182.950223, 0.143100, 183, -1 });
		element.add_isotope({ 183.950931, 0.306400, 184, 0 });
		element.add_isotope({ 185.954364, 0.284300, 186, 2 });
		table->add_element(element);

		element = Element("Re");
		element.add_isotope({ 184.952955, 0.374000, 185, -2 });
		element.add_isotope({ 186.955753, 0.626000, 187, 0 });
		table->add_element(element);

		element = Element("Os");
		element.add_isotope({ 183.952489, 0.000200, 184, -8 });
		element.add_isotope({ 185.953838, 0.015900, 186, -6 });
		element.add_isotope({ 186.955750, 0.019600, 187, -5 });
		element.add_isotope({ 187.955838, 0.132400, 188, -4 });
		element.add_isotope({ 188.958147, 0.161500, 189, -3 });
		element.add_isotope({ 189.958447, 0.262600, 190, -2 });
		element.add_isotope({ 191.961481, 0.407800, 192, 0 });
		table->add_element(element);

		element = Element("Ir");
		element.add_isotope({ 190.960594, 0.373000, 191, -2 });
		element.add_isotope({ 192.962926, 0.627000, 193, 0 });
		table->add_element(element);

		element = Element("Pt");
		element.add_isotope({ 189.959932, 0.000140, 190, -5 });
		element.add_isotope({ 191.961038, 0.007820, 192, -3 });
		element.add_isotope({ 193.962680, 0.329670, 194, -1 });
		element.add_isotope({ 194.964791, 0.338320, 195, 0 });
		element.add_isotope({ 195.964952, 0.252420, 196, 1 });
		element.add_isotope({ 197.967893, 0.071630, 198, 3 });
		table->add_element(element);

		element = Element("Au");
		element.add_isotope({ 196.966569, 1.000000, 197, 0 });
		table->add_element(element);

		element = Element("Hg");
		element.add_isotope({ 195.965833, 0.001500, 196, -6 });
		element.add_isotope({ 197.966769, 0.099700, 198, -4 });
		element.add_isotope({ 198.968280, 0.168700, 199, -3 });
		element.add_isotope({ 199.968326, 0.231000, 200, -2 });
		element.add_isotope({ 200.970302, 0.131800, 201, -1 });
		element.add_isotope({ 201.970643, 0.298600, 202, 0 });
		element.add_isotope({ 203.973494, 0.068700, 204, 2 });
		table->add_element(element);

		element = Element("Tl");
		element.add_isotope({ 202.972344, 0.295200, 203, -2 });
		element.add_isotope({ 204.974427, 0.704800, 205, 0 });
		table->add_element(element);

		element = Element("Pb");
		element.add_isotope({ 203.973044, 0.014000, 204, -4 });
		element.add_isotope({ 205.974465, 0.241000, 206, -2 });
		element.add_isotope({ 206.975897, 0.221000, 207, -1 });
		element.add_isotope({ 207.976652, 0.524000, 208, 0 });
		table->add_element(element);

		element = Element("Bi");
		element.add_isotope({ 208.980399, 1.000000, 209, 0 });
		table->add_element(element);

		element = Element("Pa");
		element.add_isotope({ 231.035884, 1.000000, 231, 0 });
		table->add_element(element);

		element = Element("Th");
		element.add_isotope({ 232.038055, 1.000000, 232, 0 });
		table->add_element(element);

		element = Element("U");
		element.add_isotope({ 234.040952, 0.000054, 234, -4 });
		element.add_isotope({ 235.043930, 0.007204, 235, -3 });
		element.add_isotope({ 238.050788, 0.992742, 238, 0 });
		table->add_element(element);
		return table;
	}

	PeriodicTable::~PeriodicTable()
	{
	}
}

