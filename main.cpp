#include <iostream>
#include <string>

#include "rpc_register.hpp"

using namespace std;

//��װ�ú���Ϊ���ú���������ΪԶ��������������Ϊ�������
int main()
{
	string use_function_name;//����rpc������
	rpc_register example;//rpcʵ��
	string result;//���ý��

	example.regis();//ע�����
	
	//ģ�����˳�������
	while (1) {
part1:
		use_function_name = "";
		result = "";

		cout << "input use function(class.function)\n";
		cin >> use_function_name;

		if (!example.link_to_function(use_function_name)) {
			cout << "function does not exist\n";
			goto part1;
		}
		else {
			cout << "Functions can work\n";
		}

		cout << "input use function parameter(a,b,c,d)\n";
		use_function_name = "";
		cin >> use_function_name;
		result = example.call_action(use_function_name);
		

		cout << "call result is:" << result << "\n";


		cout << "rpc once over.\n\n";
	}

	return 0;
}


