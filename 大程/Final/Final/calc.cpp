#include "stdafx.h"
using namespace std;

double Calculus::Calc(double x){

	return pre.Func_Calc(x);  //利用堆栈结构中的函数计算结果
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
				cout << "括号输入错误" << endl;
			else if (error == 0)
				cout << "非法的输入符号" << endl;
			else if (error == 3)
				cout << "积分超出指定范围" << endl;
			return;
		
		
	}
	
	cout << "积分结果是：" << r << endl;
}

void Calculus::GetFunction(){
	cout << "请按照格式输入函数" << endl;
	cin.sync();
	cin.getline(pre.func,100);   //输入函数体
}

void Calculus::GetRange(){  //输入范围
	cout << "请输入x的积分起点" << endl;
	cin.sync();
	cin >> x_from;
	cout << "请输入x的积分终点" << endl;
	cin.sync();
	cin >> x_to;
}

double Calculus::GetResult(){
	GetFunction();
	GetRange();
	double result = 0;
	double calc = 0;
	if (x_from <= x_to)
	for (double i = x_from; i < x_to; i += distance){  //在积分范围内求面积
		calc = Calc(i);
		if (calc<low || calc>high) throw 3; //超出范围抛出3
		else result += calc * distance;
	}
	else
	for (double i = x_to; i < x_from; i += distance){  //在积分范围内求面积
		calc = Calc(i);
		if (calc<low || calc>high) throw 3; //超出范围抛出3
		else result += calc * distance;
	}
	if (x_from <= x_to)
		return result;
	else return -result;
}

double stack::Func_Calc(const double& x){  //带有优先级的运算函数，以x的值作为自变量的值
	string digit = "";  //用以读取数字
	int i = 0, j = 0, k = 0; //i指向当前函数字符串中读取的位数，j指向输出数字中当前空白的一位，k指向运算符输出当前空白的一位
	bool flag = 0;
	while (func[i]){
		if ((func[i] >= '0' && func[i] <= '9') || func[i] == '.'){ //读取一连串的数字，包括小数点
			for (; (func[i] >= '0' && func[i] <= '9') || func[i] == '.'; i++){

				char d[20];
				d[0] = func[i];
				d[1] = 0;
				digit += d;  //结果以字符串的形式记录

			}
			if (!flag)
			output[j++] = atof(digit.c_str());  //将字符串转换成double存储
			else {
				output[j++] = -atof(digit.c_str());
				flag = 0;
			}
			digit = "";
		}

		else if (func[i] == 'x' || func[i] == 'X'){  //读取到X时以自变量的值存储
			if (!flag)
			output[j++] = x;
			else{
				output[j++] = -x;
				flag = 0;
			}
			i++;
		}
		else if (func[i] == 'e' || func[i] == 'E'){ //读取到e时以e的值存储
			if (!flag)
			output[j++] = 2.718281828459;
			else{
				output[j++] = -2.718281828459;
				flag = 0;
			}
			i++;
		}

		else {  //读取到运算符时
			switch (func[i]){
			case '+':  //加法时，在堆栈不空或者没有遇到‘（’括号时，所有运算符优先级都比+高，前面的计算要全部完成
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
						throw 1; //括号输入错误，抛出1
						break;
					default: throw 0; //有任何规定范围内的输入，抛出0
					}

				}
				stack_out[k++] = '+'; //运算结束后将+推入堆栈
				break;
			case '-': //与加号类似
				if ((stack_out[k - 1] == '(')) //负号，需加括号
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
			case '*': //在推入堆栈前遇到减号和加号时，加减不需运算，其他运算符要运算
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
			case '/':  //与乘号类似
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
			case '^'://在推入堆栈前，除了遇到指数运算符‘^’,其他运算符都不需要计算
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
			case '(': //直接推入堆栈
				stack_out[k++] = '(';
				break;
			case ')': //在没有遇到左括号'('时，将所有运算符的计算全部完成
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
	while (k - 1 >= 0){  //函数表达式字符串读取完成后，按顺序将堆栈中剩余的运算符计算全部完成
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
	return output[0]; //最后的计算结果保存在这里
}

/*int main(){
	Calculus test;
	cout << test.GetResult() << endl;
	system("pause");
}*/
