#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

#define LF "\n"

/** 이미 작성된 코드들은 사용하지 않아도 무관합니다.
** 필요하다면 수정/삭제하고 스스로 작성하세요.
*/


/** 입력으로 주어진 모든 줄들을 입력받아 벡터에 채워주는 반환해주는 함수 **/
void readAllLines(vector<string> &lines);


int main() {
	ios_base::sync_with_stdio(false);

	//모든 줄을 입력받아 준다
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

