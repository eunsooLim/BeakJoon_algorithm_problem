#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef struct node {

	int key;
	string data;

}happp;
void show(vector<node> nodes) {
	for (int i = 0; i < nodes.size(); i++) {
		cout << (i + 1) << "��° ����� Ű�� ������" << nodes[i].key << "," << nodes[i].data << endl;
	}
}
int main(void) {

	vector<node> vector_nodes;
	cout << "������ ����" << endl;
	happp temp;
	temp.key = 3;
	temp.data = "hello";
	vector_nodes.push_back(temp);
	temp.key = 5;
	temp.data = "toto";
	vector_nodes.push_back(temp);
	temp.key = 33333;
	temp.data = "hello222";
	vector_nodes.push_back(temp);
	cout << "���� �� " << endl;
	show(vector_nodes);
	vector_nodes.pop_back();
	cout << "�� �� ���� �� " << endl;
	show(vector_nodes);
	temp.key = 13;
	temp.data = "sdhello";
	vector_nodes.push_back(temp);
	happp temp2 = vector_nodes.front();
	cout << "�Ǿ��� ���:" << temp2.key << "," << temp2.data << endl;
	cout << "Size" << vector_nodes.size() << endl;
	cout << endl;
	show(vector_nodes);

	cout << vector_nodes[0].key << endl;
	cout << vector_nodes[1].data << endl;


}