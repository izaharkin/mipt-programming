#include <iostream>
#include <cstdio>

using namespace std;
// ЭЛЕМЕНТ (УЗЕЛ) СПИСКА
struct elem
{
	int info;    // Информация элемента
	
	elem* prev;  // Ссылка на предыдущий элемент списка
	elem* next;	 // Ссылка на следующий элемент списка
};

class DList              // КЛАСС - ДВУСВЯЗНЫЙ СПИСОК
{
private:
	elem* head;
	elem* tail;
	int size;
	
public:
	DList();             // Конструктор
	DList(const DList&); // Конструктор копирования
	~DList();            // Деструктор
	
	void AddFirst  (int);       // Добавить в начало списка
	void AddLast   (int);       // Добавить в конец списка
	
	void Insert (const int&, const int&);   // Вставить элемент на указанную позицию
	
	void DelFirst ();     // Удалить первый элемент списка
	void DelLast  ();     // Удалить последний элемент списка
	void DelPos   (int);  // Удалить элемент списка с заданным номером
	void DelVal   (int);  // Удалить элемент списка с заданным значением
	void DelAll   ();     // Удалить весь список
	
	void Print ();        // Вывести все элементы списка
	void Print (int);     // Вывести элемент под заданным номером
	
	int Search    (int);  // Найти элемент с заднным значением (первое вхождение)
	
	elem* GetFirst ();    // Возвращает первый элемент списка
	elem* GetElem  (int); // Возвращает элемент списка с заданным номером
	elem* GetLast  ();    // Возвращает последний элемент списка
	
	int Size ();   // Возвращает текущий размер списка
	
	void Sort ();  // Сортировка списка
	
	DList& operator = (const DList&);  // Присваивание одного списка другому
	DList  operator + (const DList&);  // Слияние списков
	
	// Операторы сравнения
   	bool operator == (const DList&);
   	bool operator != (const DList&);
   	bool operator <= (const DList&);
   	bool operator >= (const DList&);
   	bool operator <  (const DList&);
   	bool operator >  (const DList&);

   	DList operator - ();   // Переворачивание списка
};
// КОНСТРУКТОР
DList:: DList ()
{
	head = tail = NULL;
	size = 0;
}
// КОНСТРУКТОР КОПИРОВАНИЯ
DList:: DList (const DList& L)
{
   head = tail = NULL;
   size = 0;

   elem* temp = L.head;

   while ( temp != NULL )
   {
      AddLast(temp->info);
      
      temp = temp->next;
   }
}
// ДОБАВИТЬ В НАЧАЛО
void DList:: AddFirst (int x)
{
	elem* temp = new elem;
	
	temp->info = x;
	temp->next = head;
	temp->prev = NULL;
	
	if ( head != NULL ) 
	{
		head->prev = temp;
		head = temp;
	}
	else head = tail = temp;
	
	size++;
}
// ДОБАВИТЬ В КОНЕЦ
void DList:: AddLast (int x)
{
	elem *temp = new elem;
	
	temp->info = x;
	temp->next = NULL;
	temp->prev = tail;
	
	if ( head != NULL )
	{
		tail->next = temp;
		tail = temp;	
	}
	else head = tail = temp;
	
	size++;
}
// ВСТАВКА ЭЛЕМЕНТА В k-УЮ ПОЗИЦИЮ
void DList:: Insert (const int& x, const int& k)
{
   	if ( k == 1 )
   	{
      	AddFirst(x);
      	return;
   	}
   	
   	if ( k > size )
   	{
      	AddLast(x);
      	return;
   	}

   	elem* p = head;
   	
   	for (int i = 1; i < k-1; i++) p = p->next;
   	
   	elem* temp = new elem;
   	temp->info = x;
   	
   	temp->next = p->next;
   	temp->prev = p;
   	p->next->prev = temp;
	p->next = temp;	

   	size++;
}
// УДАЛИТЬ САМЫЙ ПЕРВЫЙ ЭЛЕМЕНТ СПИСКА
void DList:: DelFirst ()
{
	if ( size == 0 ) return;
	
	elem* temp = head;
	
	head = head->next;
	
	delete temp;
	
	size--;
}
// УДАЛИТЬ САМЫЙ ПОСЛЕДНИЙ ЭЛЕМЕНТ СПИСКА
void DList:: DelLast()
{
	if ( size == 0 ) return;
	
	elem *temp;

	temp = tail;
	tail = tail->prev;
	if ( size > 1 ) tail->next = NULL;
	
	delete temp;
	
	size--;
}
// НАЙТИ ЭЛЕМЕНТ С ЗАДАННЫМ ЗНАЧЕНИЕМ И ВЕРНУТЬ ЕГО НОМЕР ПО ПОРЯДКУ ИЛИ НОЛЬ
int DList:: Search (int x)
{
	elem* temp = head;
	
	int i = 1;
	while ( temp->info != x && temp != NULL ) temp = temp->next, i++;
	
	if ( temp == NULL ) return 0;
	else                return i;
}
// УДАЛЯЕТ ЭЛЕМЕНТ, КОТОРЫЙ СТОИТ В k-ОЙ ПОЗИЦИИ
void DList:: DelPos (int k)
{
	if ( k > size ) return;
	
	if ( k == 1 )
	{
		DelFirst();
		return;
	}
	
	elem* p = head;
	for (int i = 1; i < k-1; i++) p = p->next;
	
	elem* temp = p->next;
	p->next = temp->next;
	temp->next->prev = p;
	
	delete temp;
	
	size--;
}
// УДАЛИТЬ ЭЛЕМЕНТ С УКАЗАННЫМ ЗНАЧЕНИЕМ
void DList:: DelVal (int x)
{
	elem* p = head;
	
	int f = Search(x);
	
	if 	( f )
	{
		if ( f == 1 ) DelFirst();
		else          DelPos(f);
	}
}
// УДАЛИТЬ ВСЕ ЭЛЕМЕНТЫ СПИСКА (ИЗ ПАМЯТИ)
void DList:: DelAll ()
{
	while ( head != NULL ) DelFirst();
}
// ВЕРНУТЬ РАЗМЕР (КОЛИЧЕСТВО ЭЛЕМЕНТОВ) ТЕКУЩЕГО СПИСКА
int DList:: Size ()
{
	return size;
}
// ВЫВОДИТ ВСЕ ЭЛЕМЕНТЫ ТЕКУЩЕГО СПИСКА
void DList:: Print ()
{
	elem* p = head;
	
	while ( p != NULL )
	{
		printf("%d ", p->info);
		p = p->next;
	}
	printf("\n");
}
// ВЫВОДИТ k-ЫЙ ЭЛЕМЕНТ СПИСКА
void DList:: Print (int k)
{
	elem* p = head;
	
	for (int i = 1; i < k; i++, p = p->next);
	
	printf("%d ", p->info);
}
// ВОЗВРАЩАЕТ ПЕРВЫЙ ЭЛЕМЕНТ СПИСКА
elem* DList:: GetFirst ()
{
	return head;
}
// ВОЗВРАЩАЕТ УКАЗАТЕЛЬ НА k-ЫЙ ЭЛЕМЕНТ СПИСКА
elem* DList:: GetElem (int k)
{
	elem* p = head;
	
	for (int i = 1; i < k; i++) p = p->next;
	
	return p;
}
// ВОЗВРАЩАЕТ ПОСЛЕДНИЙ ЭЛЕМЕНТ СПИСКА
elem* DList:: GetLast ()
{
	return tail;
}
// ДЕСТРУКТОР
DList:: ~DList ()
{
	DelAll();
}
// ОПЕРАТОР ПРИСВАИВАНИЯ ДЛЯ СПИСКОВ
DList& DList:: operator = (const DList& L)
{
    // Проверка присваивания элемента "самому себе"
    if ( this == &L ) return *this;

   // удаление старого списка
   this->~DList(); // DelAll();

   elem* temp = L.head;

   // Копируем элементы
   while ( temp != NULL )
   {
      AddLast(temp->info);
      
      temp = temp->next;
   }

   return *this;
}
// СЛОЖЕНИЕ (СЛИЯНИЕ) ДВУХ СПИСКОВ
DList DList::operator + (const DList& L)
{
   // Заносим во временный список элементы первого списка
   DList res(*this);
	
   elem* temp = L.head;

   // Добавляем во временный список элементы второго списка
   while ( temp != NULL )
   {
      res.AddLast(temp->info);
      
      temp = temp->next;
   }

   return res;
}

// ОПЕРАТОРЫ СРАВНЕНИЯ ДВУХ СПИСКОВ

bool DList:: operator == (const DList& L)
{
   	// Сравнение по количеству
   	if ( size != L.size ) return false;

   	elem *t1, *t2;

   	t1 = head;
   	t2 = L.head;

   	// Сравнение по содержанию
   	while ( t1 != tail )
   	{
      	if( t1->info != t2->info ) return false;
		
      	t1 = t1->next;
      	t2 = t2->next;
  	}

   	return true;
}

bool DList:: operator != (const DList& L)
{
   	return !( *this == L );
}

bool DList:: operator >= (const DList& L)
{
    return (( size > L.size || *this == L ) ? true : false);
}

bool DList:: operator <= (const DList& L)
{
   	return (( size < L.size || *this == L ) ? true : false); 
}

bool DList:: operator > (const DList& L)
{
   	return ( size > L.size ? true : false );
}

bool DList:: operator < (const DList& L)
{
   	return ( size < L.size ? true : false );
}

// ОПЕРАТОР ПЕРЕВОРОТА СПИСКА
DList DList:: operator - ()
{
   DList res;
   
   elem* temp = head;
   
   while ( temp != NULL )
   {
       res.AddFirst(temp->info);
       
       temp = temp->next;
   }

   return res;
}

int main()
{
	DList L;

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int x;
	while ( cin >> x )
		L.AddFirst(x);	   	
   
	while ( L.Size() )
	{
		cout << L.GetFirst() << "\n";
		L.DelFirst();
	}
   
   	return 0;
}
