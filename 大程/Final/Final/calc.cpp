#include "stdafx.h"
using namespace std;

double Calculus::Calc(double x){

	return pre.Func_Calc(x);  //���ö�ջ�ṹ�еĺ���������
}
void Calculus::function()
{
	double r;
	try
	{
		r = GetResult();
	}
	catch (int &error)
	{
		
			if (error == 1)
				cout << "�����������" << endl;
			else if (error == 0)
				cout << "�Ƿ����������" << endl;
			else if (error == 3)
				cout << "���ֳ���ָ����Χ" << endl;
			return;
		
		
	}
	
	cout << "���ֽ���ǣ�" << r << endl;
}

void Calculus::GetFunction(){
	cout << "�밴�ո�ʽ���뺯��" << endl;
	cin.sync();
	cin.getline(pre.func,100);   //���뺯����
}

void Calculus::GetRange(){  //���뷶Χ
	cout << "������x�Ļ������" << endl;
	cin.sync();
	cin >> x_from;
	cout << "������x�Ļ����յ�" << endl;
	cin.sync();
	cin >> x_to;
}

double Calculus::GetResult(){
	GetFunction();
	GetRange();
	double result = 0;
	double calc = 0;
	if (x_from <= x_to)
	for (double i = x_from; i < x_to; i += distance){  //�ڻ��ַ�Χ�������
		calc = Calc(i);
		if (calc<low || calc>high) throw 3; //������Χ�׳�3
		else result += calc * distance;
	}
	else
	for (double i = x_to; i < x_from; i += distance){  //�ڻ��ַ�Χ�������
		calc = Calc(i);
		if (calc<low || calc>high) throw 3; //������Χ�׳�3
		else result += calc * distance;
	}
	if (x_from <= x_to)
		return result;
	else return -result;
}

double stack::Func_Calc(const double& x){  //�������ȼ������㺯������x��ֵ��Ϊ�Ա�����ֵ
	string digit = "";  //���Զ�ȡ����
	int i = 0, j = 0, k = 0; //iָ��ǰ�����ַ����ж�ȡ��λ����jָ����������е�ǰ�հ׵�һλ��kָ������������ǰ�հ׵�һλ
	bool flag = 0;
	while (func[i]){
		if ((func[i] >= '0' && func[i] <= '9') || func[i] == '.'){ //��ȡһ���������֣�����С����
			for (; (func[i] >= '0' && func[i] <= '9') || func[i] == '.'; i++){

				char d[20];
				d[0] = func[i];
				d[1] = 0;
				digit += d;  //������ַ�������ʽ��¼

			}
			if (!flag)
			output[j++] = atof(digit.c_str());  //���ַ���ת����double�洢
			else {
				output[j++] = -atof(digit.c_str());
				flag = 0;
			}
			digit = "";
		}

		else if (func[i] == 'x' || func[i] == 'X'){  //��ȡ��Xʱ���Ա�����ֵ�洢
			if (!flag)
			output[j++] = x;
			else{
				output[j++] = -x;
				flag = 0;
			}
			i++;
		}
		else if (func[i] == 'e' || func[i] == 'E'){ //��ȡ��eʱ��e��ֵ�洢
			if (!flag)
			output[j++] = 2.718281828459;
			else{
				output[j++] = -2.718281828459;
				flag = 0;
			}
			i++;
		}

		else {  //��ȡ�������ʱ
			switch (func[i]){
			case '+':  //�ӷ�ʱ���ڶ�ջ���ջ���û����������������ʱ��������������ȼ�����+�ߣ�ǰ��ļ���Ҫȫ�����
				while ((k - 1 >= 0) && (stack_out[k - 1] != '(')){
					switch (stack_out[k - 1]){
					case '+':
						k--;
						j--;
						output[j - 1] = output[j - 1] + output[j];
						break;
					case '-':
						k--;
						j--;
						output[j - 1] = output[j - 1] - output[j];
						break;
					case '*':
						k--;
						j--;
						output[j - 1] = output[j - 1] * output[j];
						break;
					case '/':
						k--;
						j--;
						output[j - 1] = output[j - 1] / output[j];
						break;
					case '^':
						k--;
						j--;
						output[j - 1] = pow(output[j - 1], output[j]);
						break;
					case ')':
						throw 1; //������������׳�1
						break;
					default: throw 0; //���κι涨��Χ�ڵ����룬�׳�0
					}

				}
				stack_out[k++] = '+'; //���������+�����ջ
				break;
			case '-': //��Ӻ�����
				if ((stack_out[k - 1] == '(')) //���ţ��������
				{
					flag = 1;
				}
				else{
					while ((k - 1 >= 0) && (stack_out[k - 1] != '(')){
						switch (stack_out[k - 1]){
						case '+':
							k--;
							j--;
							output[j - 1] = output[j - 1] + output[j];
							break;
						case '-':
							k--;
							j--;
							output[j - 1] = output[j - 1] - output[j];
							break;
						case '*':
							k--;
							j--;
							output[j - 1] = output[j - 1] * output[j];
							break;
						case '/':
							k--;
							j--;
							output[j - 1] = output[j - 1] / output[j];
							break;
						case '^':
							k--;
							j--;
							output[j - 1] = pow(output[j - 1], output[j]);
							break;
						case ')':
							throw 1;
							break;
						default: throw 0;
						}

					}

					stack_out[k++] = '-';
				}
					break;
			case '*': //�������ջǰ�������źͼӺ�ʱ���Ӽ��������㣬���������Ҫ����
				while ((k - 1 >= 0) && (stack_out[k - 1] != '(') && (stack_out[k - 1] != '+') && (stack_out[k - 1] != '-')){
					switch (stack_out[k - 1]){
					case '*':
						k--;
						j--;
						output[j - 1] = output[j - 1] * output[j];
						break;
					case '/':
						k--;
						j--;
						output[j - 1] = output[j - 1] / output[j];
						break;
					case '^':
						k--;
						j--;
						output[j - 1] = pow(output[j - 1], output[j]);
						break;
					case ')':
						throw 1;
						break;
					default: throw 0;
					}

				}
				stack_out[k++] = '*';
				
				break;
			case '/':  //��˺�����
				while ((k - 1 >= 0) && (stack_out[k - 1] != '(') && (stack_out[k - 1] != '+') && (stack_out[k - 1] != '-')){
					switch (stack_out[k - 1]){
					case '*':
						k--;
						j--;
						output[j - 1] = output[j - 1] * output[j];
						break;
					case '/':
						k--;
						j--;
						output[j - 1] = output[j - 1] / output[j];
						break;
					case '^':
						k--;
						j--;
						output[j - 1] = pow(output[j - 1], output[j]);
						break;
					case ')':
						throw 1;
						break;
					default: throw 0;
					}

				}
				stack_out[k++] = '/';
				break;
			case '^'://�������ջǰ����������ָ���������^��,���������������Ҫ����
				while ((k - 1 >= 0) && (stack_out[k - 1] != '(') && (stack_out[k - 1] != '+') && (stack_out[k - 1] != '-') && (stack_out[k - 1] != '*') && (stack_out[k - 1] != '/')){
					switch (stack_out[k - 1]){
					case '^':
						k--;
						j--;
						output[j - 1] = pow(output[j - 1], output[j]);
						break;
					case ')':
						throw 1;
						break;
					default: throw 0;
					}

				}
				stack_out[k++] = '^';
				break;
			case '(': //ֱ�������ջ
				stack_out[k++] = '(';
				break;
			case ')': //��û������������'('ʱ��������������ļ���ȫ�����
				while ((k - 1 >= 0) && (stack_out[k - 1] != '(')){
					switch (stack_out[k - 1]){
					case '+':
						k--;
						j--;
						output[j - 1] = output[j - 1] + output[j];
						break;
					case '-':
						k--;
						j--;
						output[j - 1] = output[j - 1] - output[j];
						break;
					case '*':
						k--;
						j--;
						output[j - 1] = output[j - 1] * output[j];
						break;
					case '/':
						k--;
						j--;
						output[j - 1] = output[j - 1] / output[j];
						break;

					case ')':
						throw 1;
						break;
					default: throw 0;
					}
				}
				if (stack_out[k - 1] != '(') throw 1;
				else k--;
				break;
			default: throw 0;
			}
			i++;
		}
	}
	while (k - 1 >= 0){  //�������ʽ�ַ�����ȡ��ɺ󣬰�˳�򽫶�ջ��ʣ������������ȫ�����
		switch (stack_out[k - 1]){
		case '+':
			k--;
			j--;
			output[j - 1] = output[j - 1] + output[j];
			break;
		case '-':
			k--;
			j--;
			output[j - 1] = output[j - 1] - output[j];
			break;
		case '*':
			k--;
			j--;
			output[j - 1] = output[j - 1] * output[j];
			break;
		case '/':
			k--;
			j--;
			output[j - 1] = output[j - 1] / output[j];
			break;
		case '^':
			k--;
			j--;
			output[j - 1] = pow(output[j - 1], output[j]);
			break;
		case ')':
			throw 1;
			break;
		default: throw 0;
		}
		k--;
	}
	return output[0]; //���ļ���������������
}

/*int main(){
	Calculus test;
	cout << test.GetResult() << endl;
	system("pause");
}*/
