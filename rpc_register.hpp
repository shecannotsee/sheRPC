#ifndef __RPC_REGISTER_HPP_
#define __RPC_REGISTER_HPP_
#include <vector>
#include <string>
#include "rpc_function.hpp"

class rpc_register
{
public:
	rpc_register();
	~rpc_register();

	void regis();

	//�Դ���������м��,rpc_function.j_add
	int link_to_function(std::string class_function_name);

	//���ù���
	std::string call_action(std::string function_parameter);

private:
	std::string m_class_name;//��һ�ε��õ�����,��ÿ�ε���֮���������
	std::string m_function_name;//��һ�ε��õĺ�����,��ÿ�ε���֮���������
	std::string m_function_parameter;//��һ�ε��õĺ�������,��ÿ�ε���֮���������

	std::vector<std::string> m_regis_class;//��ע����
	std::vector<std::string> m_regis_function;//��ע�ắ��

	std::string m_rpc_result;//���ý��

	void fool(std::string function_parameter);
	

};

rpc_register::rpc_register()
{
	m_class_name = "";
	m_function_name = "";
	m_function_parameter = "";

	m_rpc_result = "";
}

rpc_register::~rpc_register()
{
}

//����Ҫʹ�õ�Զ�̵��õ���ͺ���ע���ȥ
void rpc_register::regis()
{
	m_regis_class.push_back("rpc_function");
	m_regis_function.push_back("rpc_function::j_add");
	m_regis_function.push_back("rpc_function::j_subtraction");
	m_regis_function.push_back("rpc_function::c_multiplication");
}
//��Ӧ����
void rpc_register::fool(std::string function_parameter)
{
	//1.����ת��Ϊ���ò���
	std::vector<int> use_para;
	int temp = 0;
	for (int i = 0; i < function_parameter.size(); i++) {
		if (function_parameter[i] != ',') {
			temp *= 10;
			temp += function_parameter[i] - '0';
		}
		else {
			use_para.push_back(temp);
			temp = 0;
		}
	}
	use_para.push_back(temp);
	temp = 0;

	//2.��ʵ�����е��ã����ҽ��������m_result
	rpc_function rpc_function_example;
	if (m_class_name == "rpc_function") {
		if (m_function_name == "j_add")
			m_rpc_result = std::to_string(rpc_function_example.j_add(use_para[0], use_para[1]));
		else if (m_function_name == "j_subtraction")
			m_rpc_result = std::to_string(rpc_function_example.j_subtraction(use_para[0], use_para[1]));
		else if (m_function_name == "c_multiplication")
			m_rpc_result = std::to_string(rpc_function_example.c_multiplication(use_para[0], use_para[1]));
	}
}

//���
int rpc_register::link_to_function(std::string class_function_name)
{
	m_class_name = "";
	m_function_name = "";
	m_function_parameter = "";
	//1.����class��function
	std::string temp = "";
	for (int i = 0; i < class_function_name.size(); i++) {
		if (class_function_name[i] != '.') {
			temp += class_function_name[i];
		}
		else {
			m_class_name = temp;
			temp = "";
		}
	}
	m_function_name = temp;

	//2.�Խ�����м�飬�Ƿ��ж�Ӧ����ͺ�������ʹ��
	temp = "";
	temp += m_class_name;
	temp += "::";
	temp += m_function_name;
	for (int i = 0; i < m_regis_function.size(); i++) {
		if (temp == m_regis_function[i]) {
			return 1;//�ж�Ӧ�ĺ�������
		}
	}
	return 0;//�޿��ú���
}

//����
std::string rpc_register::call_action(std::string function_parameter)
{
	fool(function_parameter);
	return m_rpc_result;
}


#endif // !__RPC_REGISTER_HPP_
