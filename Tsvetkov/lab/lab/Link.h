struct Link {
	Link* next;
	int a, x, y, z, res = 0;

	Link() {
		a = 0; x = 0; y = 0; z = 0;
		next = this;
	}


};