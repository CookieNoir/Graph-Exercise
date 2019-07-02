#include <iostream>
template <class T> class graph {
public:
	struct edge {
		int number;
		edge* next;
		edge() = default;
		edge(int num) {
			number = num;
			next = nullptr;
		}
	};
	struct node {
		int number;
		T data;
		node* next;
		edge* connected;
		node() = default;
		node(int num, T newData) {
			number = num;
			data = newData;
			next = nullptr;
			connected = nullptr;
		}
	};
private:
	node* entry;
	node* end;
	int count;
public:
	graph() {
		entry = new node();
		entry = nullptr;
		end = entry;
		count = 0;
	}
	void addVertice(T newData);
	void connectVertex(node* first, node* second); //makes a directed connection (1,2)
	node* getNodeWithNumber(int num);
	int size();
	void show();
};

template <class T> void graph<T>::addVertice(T newData) {
	node* newNode = new node(count, newData);
	if (!entry) entry = newNode;
	else end->next = newNode;
	end = newNode;
	count++;
}

template <class T> int graph<T>::size() {
	return count;
}

template <class T> void graph<T>::connectVertex(node* first, node* second) {
	edge* r = first->connected;
	if (!r) first->connected = new edge(second->number);
	else {
		while (r->next) r = r->next;
		r->next = new edge(second->number);
	}
}

template <class T> graph<T>::template node* graph<T>::getNodeWithNumber(int num) {
	node* p = entry;
	while (p->number != num) p = p->next;
	return p;
}

template <class T> void graph<T>::show() {
	std::cout << "     Graph\n";
	node* p = entry;
	edge* q;
	while (p) {
		std::cout << std::endl <<"Vertex "<< p->number << std::endl <<"Connected with : ";
		//p->data.show();
		q = p->connected;
		while (q) { std::cout << q->number << " "; q = q->next; }
		std::cout << std::endl;
		p = p->next;
	}
}