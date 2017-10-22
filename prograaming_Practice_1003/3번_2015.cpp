#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

#define LF "\n"

/** �̹� �ۼ��� �ڵ���� ������� �ʾƵ� �����մϴ�.
** �ʿ��ϴٸ� ����/�����ϰ� ������ �ۼ��ϼ���.
*/


/** �Է����� �־��� ��� �ٵ��� �Է¹޾� ���Ϳ� ä���ִ� ��ȯ���ִ� �Լ� **/
void readAllLines(vector<string> &lines);


int main() {
	ios_base::sync_with_stdio(false);

	//��� ���� �Է¹޾� �ش�
	vector<string> lines;
	readAllLines(lines);
	for(int i=0;i<lines.size();i++)
		cout << lines[i];
	cout << endl;

	vector<string> words;

	lines.push_back("\n"); 
	string word = "";
	char moum[5] = { 'a','e','i','o','u' };
	map<string, int> maph;
	map<string, int>::iterator iter;
	for (int i = 0; i < lines.size(); i++)
	{

		if (lines[i] == " " || lines[i] == "\n" || (stoi(lines[i])<65) ) {

			//words.push_back(word);
			iter = maph.find(word);
			if (iter != maph.end()) {
				iter->second = iter->second + 1;
			}
			else maph.insert(make_pair(word, 0));
			
			word = "";

		}
		else word = word + lines[i];

	}
	return 0;
}


void readAllLines(vector<string> &lines)
{
	lines.clear();
	std::string line;
	while (std::getline(std::cin, line))
	{
		lines.push_back(line);
		
	}
}

