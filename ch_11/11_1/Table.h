struct Element {
	int key;
	int * dataArray;
	int dataArraySize;
};

typedef struct Element Element;

struct Table {
	Element ** slots;
	int size;
};

typedef struct Table Table;
