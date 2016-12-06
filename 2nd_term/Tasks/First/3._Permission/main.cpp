#include "Permission.h"

int main()
{
	Human hh("a", "b");
	Student stt("a", "b"), st_pp("a", "b");
	Worker ww("a", "b");

	Human *h = &hh;
	Student *st = &stt, *st_p = &st_pp;
	Worker *w = &ww;

	Study_B GK;
	Lab L;

	L.GivePermission(st_p);

	cout << GK.Permission(h) << " ";
	cout << GK.Permission(st) << " ";
	cout << GK.Permission(st_p) << " ";
	cout << GK.Permission(w) << "\n";

	cout << L.Permission(h) << " ";
	cout << L.Permission(st) << " ";
	cout << L.Permission(st_p) << " ";
	cout << L.Permission(w) << "\n";

	system("PAUSE");

	return 0;
}