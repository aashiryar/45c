#include <compare>
#include <iosfwd>
#include <string>
#include <vector>
#include <iterator>
#include "compute_grades.hpp"
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
void Student::validate() const {
	auto check_score = [](int score){ if (score<0 || score >100) throw std::domain_error("Error: invalid percentage "+std::to_string(score));};
	std::for_each(quiz.begin(), quiz.end(), check_score);
	std::for_each(hw.begin(), hw.end(), check_score);
	check_score(static_cast<int>(final_score));

}
double compute_avg(const std::vector<int>& scores) {
	if (scores.empty()) {
		return 0.0;
	}
	else {
		return static_cast<double>(std::accumulate(scores.begin(), scores.end(), 0))/scores.size();
	}

}
void Student::compute_quiz_avg() {
	if (quiz.size() > 1) {
		auto min = std::ranges::min_element(quiz);
		quiz.erase(min);
	}
	quiz_avg = compute_avg(quiz);
}
void Student::compute_hw_avg() {
	hw_avg = compute_avg(hw);
}
void Student::compute_course_score() {
	course_score = std::round(0.4*quiz_avg + 0.3*hw_avg+ 0.3*final_score);
	if (course_score >= 97) {
		course_grade = "A+";
	}
	else if (course_score >= 93) {
		course_grade = "A";
	}
	else if (course_score >= 90 ) {
		course_grade = "A";
	}
	else if (course_score >= 87) {
		course_grade = "B+";
	}
	else if (course_score >= 83) {
		course_grade = "B";
	}
	else if (course_score >= 80) {
		course_grade ="B-" ;
	}
	else if (course_score >=77 ) {
		course_grade = "C+";
	}
	else if (course_score >=73 ) {
		course_grade = "C";
	}
	else if (course_score >=70 ) {
		course_grade = "C-";
	}	
	else if (course_score >=67 ) {
		course_grade ="D+" ;
	}
	else if (course_score >=63 ) {
		course_grade = "D";
	}
	else if (course_score >=60 ) {
		course_grade = "D-";
	}
	else {
		course_grade = "F";
	}
}
void Student::compute_grade() {
	compute_hw_avg();
	compute_quiz_avg();
	compute_course_score();
}
std::strong_ordering Student::operator<=>(const Student& other) const {
	return std::tie(last_name, first_name) <=> std::tie(other.last_name, other.first_name);
}
bool Student::operator==(const Student& other) const {
	return std::tie(last_name, first_name) == std::tie(other.last_name, other.first_name);
}
std::ostream& operator<<(std::ostream& out, const Student& s) {
    out << std::left << std::setw(8) << "Name:" << s.first_name + " " + s.last_name << '\n';
    out << std::left << std::setw(8) << "HW Ave:" << s.hw_avg << '\n';
    out << std::left << std::setw(8) << "QZ Ave:" << s.quiz_avg << '\n';
    out << std::left << std::setw(8) << "Final:" << s.final_score << '\n';
    out << std::left << std::setw(8) << "Total:" << s.course_score << '\n';
    out << std::left << std::setw(8) << "Grade:" << s.course_grade << '\n';
    return out;
}
std::istream& operator>>(std::istream& in, Student& s) {
    std::string line;
    while (std::getline(in, line) && !line.empty()) {
        std::istringstream iss(line);
        std::string first;
        iss >> first;
        if (first == "Name") {
            std::string name;
            iss >> s.first_name;
            std::getline(iss, s.last_name);
            s.last_name = s.last_name.substr(1); 
        } else if (first == "Quiz") {
            s.quiz.clear();
            std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(s.quiz));
        } else if (first == "HW") {
            s.hw.clear();
            std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(s.hw));
        } else if (first == "Final") {
            iss >> s.final_score;
        }
    }
    return in;
}
void Gradebook::compute_grades() {
	std::for_each(students.begin(), students.end(), [](Student& s){s.compute_grade();});
}
void Gradebook::sort() {
	std::ranges::sort(students);
}
void Gradebook::validate() const {
	std::for_each(students.begin(), students.end(), [](const Student& s){s.validate();});
}
std::istream& operator>>(std::istream& in, Gradebook& b) {
    Student s;
    while (in >> s) {
        b.students.push_back(s);
    }
    return in;
}
std::ostream& operator<<(std::ostream& out, const Gradebook& b) {
    for (const auto& s : b.students) {
        out << s << '\n';
    }
    return out;
}
