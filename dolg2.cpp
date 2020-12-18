// dolg2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>

class Kladovshikov
{
public:
	Kladovshikov() {}
	virtual Kladovshikov* Copy()
	{
		return new Kladovshikov(*this);
	}
	virtual ~Kladovshikov() {}
};
class Dmitry : public Kladovshikov
{
public:
	Dmitry() {}
	Dmitry* Copy()
	{
		return new Dmitry(*this);
	}
	~Dmitry() {}
};
int main()
{
	{
		std::list <Kladovshikov*> list1, list2;
		list1.push_back(new Kladovshikov());
		list1.push_back(new Dmitry());
		for (std::list <Kladovshikov*>::iterator it = list1.begin(); it != list1.end(); ++it)
		{
			list2.push_back((*it)->Copy());
		}
		for (std::list <Kladovshikov*>::iterator it = list1.begin(); it != list1.end(); ++it)
		{
			delete* it;
		}
		for (std::list <Kladovshikov*>::iterator it = list2.begin(); it != list2.end(); ++it)
		{
			delete* it;
		}
	}
	_CrtDumpMemoryLeaks();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
