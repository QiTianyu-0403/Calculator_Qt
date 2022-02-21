# Calculator_Qt
This is a calculator program based on Qt visualization. The main functions are as follows: addition, subtraction, multiplication, division, trigonometric functions, square root, square, remainder, logarithmic calculation, reciprocal calculation, factorial calculation, inverse number calculation, ``pi`` and natural base ``e``, all clear operation, backspace operation, clear digital register operation, etc.

## Enviroment

1. Operation System: Win7
2. Development Platform: Qt-5.15.1 

## Class

The part of this system that involves the internal computing function of the calculator defines the following categories: Calculator, Operator, Factory, Node and Stack.

- Calculator

```
class Calculator{ 
private:
	Stack<double> m_num; // 数字栈 
	Stack<shared_ptr<Operator>> m_opr; // 运算符栈 
	...
}
```

- Operator

```
class Operator { 
public:
	Operator(string c, int numOprd, int pre) :m_symbol(c), m_numOprand(numOprd), m_precedence(pre) {} 
	string symbol() const { return m_symbol; } 
	int numOprand() const { return m_numOprand; } 
	int precedence() const { return m_precedence; } 
	virtual double get(double a, double b) const = 0; 
	virtual ~Operator() {} 
protected:
	const string m_symbol; // 运算符符号 
	const int m_numOprand; // 运算符目数 
	const int m_precedence; };
 ```
 
 - Factory

```
#define REGISTRAR(T, Key)	Factory::RegisterClass<T> reg_##T(Key);
class Factory {
public:
	template<typename T>
	struct RegisterClass {
		RegisterClass(string opr) {
				Factory::ms_operator.emplace(opr, [] {return make_shared<T>(); });
		} 
	};
	static shared_ptr<Operator> create(string opr); 
	static map<string, function<shared_ptr<Operator>()>> ms_operator;
};
```

- Node

```
template<typename T> 
class Node { 
	friend class Stack<T>; 
	T m_value; 
	Node* m_next = nullptr; 
public:
	Node() = default; // 默认构造函数 
	Node(const Node& rhs) = delete; // 禁用拷贝构造函数 
	Node& operator =(const Node& rhs) = delete; 
	Node(const T& val) :m_value(val) {} // 含参构造函数 
	Node(T&& val) :m_value(std::move(val)) { } // 含参移动构造函数 
	const T& value() const { return m_value; } 
	Node* next() { return m_next; }
};
```

- Stack

```
template<typename T> 
class Stack { 
	Node<T>* m_top = nullptr; 
public:
	Stack() = default; 
	Stack(const Stack&) = delete; 
	Stack& operator=(const Stack&) = delete; 
	~Stack(); void clear(); 
	void push(const T& val); 
	void push(T&& val); \
	void pop(); 
	bool empty()const ； 
	const T& top() ；
};
```

## Results

<img src="https://github.com/QiTianyu-0403/Calculator_Qt/blob/main/1.png" width="350" > <img src="https://github.com/QiTianyu-0403/Calculator_Qt/blob/main/2.png" width="350" >

<img src="https://github.com/QiTianyu-0403/Calculator_Qt/blob/main/3.png" width="350" > <img src="https://github.com/QiTianyu-0403/Calculator_Qt/blob/main/4.png" width="350" >

## More

If you want to know more about this code, you can click [the detailed explanation](https://zhuanlan.zhihu.com/p/469891113) of this code or contact me via the link above.😊


