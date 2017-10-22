#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

typedef struct node {

	int key;
	string data;

}happp;
void show(vector<node> nodes) {
	for (int i = 0; i < nodes.size(); i++) {
		cout << (i + 1) << "번째 노드의 키와 데이터" << nodes[i].key << "," << nodes[i].data << endl;
	}
}
int main(void) {
	
	map<string, int> maptest1 = { {"eunsoo",1},{"s",2},{"h",3},{"j",4} };
	cout << maptest1["h"] << endl;

	vector<node> vector_nodes;
	cout << "데이터 삽입" << endl;
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
	cout << "삽입 후 " << endl;
	show(vector_nodes);
	vector_nodes.pop_back();
	cout << "맨 뒤 삭제 후 " << endl;
	show(vector_nodes);
	temp.key = 13;
	temp.data = "sdhello";
	vector_nodes.push_back(temp);
	happp temp2 = vector_nodes.front();
	cout << "맨앞의 노드:" << temp2.key << "," << temp2.data << endl;
	cout << "Size" << vector_nodes.size() << endl;
	cout << endl;
	show(vector_nodes);

	cout << vector_nodes[0].key << endl;
	cout << vector_nodes[1].data << endl;


}