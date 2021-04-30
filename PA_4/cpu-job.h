#ifndef CPU_JOB_H
#define CPU_JOB_H

#include <iostream>

/*
 * CPU_Job holds information for a process to run on the processor
 */
struct CPU_Job {
    int ID;     // process ID
    int length; // process length
    int prior;  // process priority
    CPU_Job(int a = 0, int b = 0, int c = 0) : ID(a), length(b), prior(c) {};
};

/*
 * Operator declarations
 */
bool operator<(const CPU_Job& lhs, const CPU_Job& rhs) {
	if (lhs.prior > rhs.prior) return false;
	if (lhs.length < rhs.length || lhs.prior < rhs.prior) return true;
	if (lhs.ID < rhs.ID && lhs.length == rhs.length) return true;
	return false;
};

std::istream& operator>>(std::istream& in, CPU_Job& job) {
	int ID, length, prior;
	in >> ID >> length >> prior;
	job.ID = ID;
	job.length = length;
	job.prior = prior;
	return in;
};

std::ostream& operator<<(std::ostream& out, const CPU_Job& job) {
	out << "Job " << job.ID << " with length " << job.length 
	<< " and priority " << job.prior;
	return out;
};

#endif