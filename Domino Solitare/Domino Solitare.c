#include<iostream.h>
using namespace std;

inline int read() {
	register char c;
	do {
		c = getchar_unlocked();
	} while(c<'0' || c>'9');
	int x = 0;
	do {
		x = (x<<1) + (x<<3) + c - '0';
		c = getchar_unlocked();
	} while(c >= '0' && c <= '9');
	return x;
}

int main() {
	std::ios::sync_with_stdio(false);
	int n = read();
	n++;

	int a[n], b[n];

	for(int i=1; i<n; i++) {
		a[i] = read();
	}

	for(int i=1; i<n; i++) {
		b[i] = read();
	}
	
	a[0] = a[1];
	b[0] = b[1];
	
	int s = 0, sp = 0;
	
	for(int i=1; i<n; i++) {
		int h = abs(a[i] - b[i]);
		int v = abs(a[i] - a[i-1]) + abs(b[i]-b[i-1]);
	
		int sn = max(s + h, sp + v);
		sp = s;
		s = sn;
		//cout << "h " << h  << " v " << v << endl;
	}
	
	cout << s << endl;
		
}

