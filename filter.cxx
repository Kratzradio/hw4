/*task: filter noisy signal
	replace signal values: f[i], i=0, ...,N-1
	 by local average: g[i] = (f[i-1]+f[i]+f[i+1])/3
	
	write program which reads data from file into array, filters the 		 data and writes results into new file...DYNAMIC ALLOCATION
	1 function to filter the data (function periodic: f[N]=f[0])
	 overwrite previous array
	 (try filtering several times)
	final result in extra function into a file, keep original data
	all memory via "new" should be deleted

	compare original and filtered data
	
*/
//#include<iostream>
#include <string>
#include <fstream>

using namespace std;

void reading(double* const p, const int N, const string fname){
	ifstream in(fname.c_str());
	for(int i=0; i<N; i++){
		in >> p[i];	
	}
	in.close();
}
void funky(double* p, const int N){
	double a = p[N-1];		//reason: periodicity
	double b = p[0];
	double c = p[0];
	for(int i=0; i<N-1; i++){
		b = p[i];
		p[i] = (p[i]+a+p[i+1])/3;
		a = b;
	}
	p[N-1] = (a + c + p[N-1])/3;
}

void output(const double* const p, const int N, const string nfname){	
	ofstream out(nfname.c_str());
	for(int i=0; i<N; i++){
		out << p[i] << endl;
	}
	out.close();
}

int main(){
const int N=237;
const string fname = "noisy.txt";	
const string nfname = "filtered.txt";	
double* p = new double[N];		//memory should be allocated inside reading funciton, but I don't see the point.

reading(p, N, fname);
	for(int i=0; i<10; i++){
		funky(p, N);
	}

output(p, N, nfname);

delete[] p;
return 0;
}
