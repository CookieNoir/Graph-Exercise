#include <iostream>
#include <fstream>
#include "v2.h"
#include "graph.h"

using namespace std;

void drawLine() {
	std::cout << "----------------\n"; //16 -
}


bool check(int*& reg, int level, int value) {
	for (int i = 0; i < level; ++i)
		if (reg[i] == value) return false;
	return true;
}

bool traverse(graph<Vector2>::node* curNode, int*& reg, int level, int levels) {
	if (level == levels) return true;
	else {
		graph<Vector2>::edge* p = curNode->connected;
		while (p) {
			if (check(reg, level, p->number)) {
				reg[level] = p->number;
				if (traverse(curNode->next, reg, level + 1, levels)) return true;
				else p = p->next;
			}
			else p = p->next;
		}
		if (!p) return false;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	char* str = new char[128];
	cout << "Введите имя файла (должен содержать число n, n размеров писем, n размеров конвертов) :\n";
	cin.getline(str, 127);
	ifstream file(str);
	while (!file) {
		cout << "Файл не обнаружен. Попробуйте снова.\n";
		cout << "Введите имя файла :\n";
		cin.getline(str, 127);
		file.open(str);
	}
	int n;
	file >> n;
	Vector2* array = new Vector2[n + n];
	graph<Vector2> myGraph;
	for (int i = 0; i < n+n; ++i) {
		int x, y;
		file >> x >> y;
		array[i].set(x, y);
		myGraph.addVertice(array[i]);
	}
	file.close();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (array[i].fitsIn(array[n+j])) myGraph.connectVertex(myGraph.getNodeWithNumber(i), myGraph.getNodeWithNumber(n+j));
		}
	}
	drawLine();
	myGraph.show();
	drawLine();
	int* reg = new int[n];
	if (traverse(myGraph.getNodeWithNumber(0),reg,0,n)) cout << "Возможно.\n";
	else cout << "Невозможно.\n";
	system("pause");
	return 0;
}