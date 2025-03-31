#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"


using std::max;

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::ostream;
using std::setprecision;
using std::setw;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main () {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	for (Student_info record; read(cin, record);) {
		maxlen = max(maxlen, record.name.size());
		student.push_back(record);
	}

	sort(student.begin(), student.end(), compare);

	for (vector<Student_info>::size_type i = 0; i != student.size(); ++i) {

		cout << student[i].name
		     << string(maxlen + 4 - student[i].name.size()/2, ' ');

		try {
			double final_grade = grade(student[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}

		cout << endl;
	}

	return 0;
}