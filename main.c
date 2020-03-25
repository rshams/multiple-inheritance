#include <stdio.h>

class base_t {
public:
	int x;
	base_t() {
		printf("base class constructor called\n");
		x = 0;
	}

	virtual int show() {
		printf("base\t\tx: %d\n\n", x);
	}
};

class der1_t: virtual public base_t {
public:
	der1_t() {
		printf("der1 class constructor called\n");
		x = 1;
	}

	int show() {
		printf("derived 1\tx: %d\n\n", x);
	}
};

class der2_t: virtual public base_t {
public:
	der2_t() {
		printf("der2 class constructor called\n");
		x = 2;
	}

	int show() {
		printf("derived 2\tx: %d\n\n", x);
	}
};

class der3_t: public der1_t, public der2_t {
public:
	der3_t() {
		printf("der3 class constructor called\n");
		//x = 3;
	}

	int show() {
		printf("derived 3\tx: %d\n\n", x);
	}
};

int main() {
	base_t *base_ptr; // !!! i'm aware of memory leakage !!!

	base_ptr = new base_t();
	base_ptr->show();

	base_ptr = new der1_t();
	base_ptr->show();
	
	base_ptr = new der2_t();
	base_ptr->show();
	
	base_ptr = new der3_t();
	base_ptr->show();
}

