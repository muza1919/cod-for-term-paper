#include <iostream>
#include <string>
#include <stdlib.h>



using namespace std;

class Person
{
protected:
	int findcad;
public:
	virtual void Choice()
	{
		cout << "Виберiть варiант" << endl;
		cin >> findcad;
	}
};

class Authorisation : public Person
{
public:
	int option;
	string email;
	string password;
	string name;
	string surname;
	string middle;
	int passport;
	int ident;



	void Choice()
	{
		cout << "1. В мене вже є аккаунт" << endl;
		cout << "2. В мене немає аккаунту" << endl;
		cin >> option;
	}

	void For_old_ac()
	{
		cout << "Введiть свою назву своєї електронної пошти: " << endl;

		while (cin >> email)
		{
			if (email != "kur@gmail.com")
			{
				cout << "Пошта не вiрна, перевiрте правильнiсть" << endl;
			}
			else
			{
				break;
			}
		}

		cout << "Введiть пароль: " << endl;

		while (cin >> password)
		{
			if (password != "19112003")
			{
				cout << "Пароль не вiрний, перевiрте правильнiсть" << endl;
			}
			else
			{
				break;

			}
		}
	}

	void Old_ac()
	{
		cout << "Прiзвище: Muzalevska" << endl;
		cout << "Iм'я: Aliona" << endl;
		cout << "По-батьковi: Dmitrivna" << endl;
		cout << "Номер паспорту: 000437589" << endl;
		cout << "Iдентифiкацiйний код: 123456789123" << endl;
	}

	void New_ac()
	{
		cout << "Ваше прiзвище: " << endl;
		cin >> surname;
		cout << "Ваше iм'я: " << endl;
		cin >> name;
		cout << "Ваше iм'я по-батьковi: " << endl;
		cin >> middle;
		cout << "Ваш номер паспорту: " << endl;
		cin >> passport;
		cout << "Ваш iдентифiкацiйний код: " << endl;
		cin >> ident;
	}

	void Account()
	{
		if (option == 1)
		{
			For_old_ac();
			Old_ac();
		}
		else if (option == 2)
		{
			New_ac();
		}
	}
};

class Cadastral_number : public Person
{
private:
	class Permission
	{
	public:
		int doc;

		void Rights()
		{
			cout << "Чи ви володiєте документами, якi пiдтверджують ваше право власностi?" << endl;
			cout << "1. Так, володiю." << endl;
			cout << "2. Нi, не володiю." << endl;
			cin >> doc;

			if (doc == 1)
			{
				cout << "Ви маєте сплатити адмiнiстративний збiр." << endl;
			}
			else
			{
				cout << "Звернiть увагу, без вiдповiдних документiв неможливо отримати право на власнiсть!" << endl;
				abort();
			}
		}
	};

public:
	int amount;
	int fee;
	int cad_number;

	void Admin_fee()
	{
		cout << "Виберiть варiант, який найбiльше вас влаштовує (розмiр збору та час, за який державна реєстрацiя права власностi буде зроблена:" << endl;
		cout << "1) 230 UAH - у строк, що не перевищує 5 робочих днiв з дня реєстрацiї" << endl;
		cout << "2) 2270 UAH -  у строк два робочi днi" << endl;
		cout << "3) 4540 UAH - у строк один робочий день" << endl;
		cout << "4) 11350 UAH - у строк двi години" << endl;
		cin >> amount;
	}

	void Response()
	{
		if (amount == 1)
		{
			cout << "Ви вибрали перший варiант, що передбачає сплату адмiнiстративного збору в розмiрi 230 UAH" << endl;
			fee = 230;
		}
		else if (amount == 2)
		{
			cout << "Ви вибрали другий варiант, що передбачає сплату адмiнiстративного збору в розмiрi 2270 UAH" << endl;
			fee = 2270;
		}
		else if (amount == 3)
		{
			cout << "Ви вибрали третiй варiант, що передбачає сплату адмiнiстративного збору в розмiрi 4540 UAH" << endl;
			fee = 4540;
		}
		else if (amount == 4)
		{
			cout << "Ви вибрали четвертий варiант, що передбачає сплату адмiнiстративного збору в розмiрi 11350 UAH" << endl;
			fee = 11350;
		}
	}

	void Choice()
	{
		cout << "Чи ви маєте кадастровий номер земельної дiлянки?" << endl;
		cout << "1. Так, маю." << endl;
		cout << "2. Нi, не маю." << endl;
		cin >> findcad;
	}

	void Response_cad()
	{
		if (findcad == 1)
		{
			cout << "Вкажiть свiй кадастровий номер: " << endl;
			cin >> cad_number;
		}
		else
		{
			cout << "Вам потрiбно отримати кадастровий номер. Бiльше детальної iнформацiю ви зможете знайти на офiцiйному сайтi Державного земельного кадастру." << endl;
			abort();
		}
	}

	Permission proper;
	void Rights()
	{
		proper.Rights();
	}

};

class Payment : public Authorisation
{
public:

	int pay;
	int card;

	void Pay_method()
	{
		cout << "1. Сплата готiвкою в одному з центрiв ЦНАП вашого мiста" << endl;
		cout << "2. Банкiвською картою на офiцiйному сайтi ЦНАП" << endl;
		cin >> pay;

		if (pay == 1)
		{
			cout << "Звернiться, до одного з центрiв ЦНАП вашого мiста з заявою, яку ви отримаєте в кiнцi" << endl;

		}
		else if (pay == 2)
		{
			cout << "Будь ласка, введiть номер картки:" << endl;
			cin >> card;
		}
	}
};

class Statement : public Authorisation, public Cadastral_number, public Payment
{
public:

	void Statement_method(int option, string surname, string name, string middle, int ident, int passport, int cad_number, int amount, int pay, int card)
	{
		cout << endl;
		cout << endl;
		cout << "^------------------- Заява про реєстрацiю права власностi на земельну дiлянку --------------------^" << endl;
		cout << endl;


		if (option == 1)
		{
			cout << "Прiзвище: Muzalevska" << endl;
			cout << "Iм'я: Aliona" << endl;
			cout << "По-батьковi: Dmitrivna" << endl;
			cout << "Номер паспорту: 000437589" << endl;
			cout << "Iдентифiкацiйний код: 123456789123" << endl;
		}
		else if (option == 2)
		{
			cout << "Прiзвище: " << name << endl;
			cout << "Iм'я: " << surname << endl;
			cout << "По-батьковi: " << middle << endl;
			cout << "Номер паспорту: " << passport << endl;
			cout << "Iдентифiкацiйний код: " << ident << endl;
		}

		cout << endl;
		cout << "1) Кадастровий номер земельної дiлянки, право власностi на яку ви реєструєте: " << endl;
		cout << endl;

		cout << cad_number << endl;

		cout << endl;
		cout << "2) Строк реєстрацiї права власностi та розмiр адмiнiстративного збору:" << endl;
		cout << endl;

		if (amount == 1)
		{
			cout << "Строк, що не перевищує 5 робочих днiв - 230 UAH" << endl;
		}
		else if (amount == 2)
		{
			cout << "Строк два робочi днi - 2270 UAH" << endl;
		}
		else if (amount == 3)
		{
			cout << "Строк один робочий день - 4540 UAH" << endl;
		}
		else if (amount == 4)
		{
			cout << "Строк 2 години - 11350 UAH" << endl;
		}

		cout << endl;
		cout << "3) Вид сплати: " << endl;
		cout << endl;

		if (pay == 1)
		{
			cout << "Сплата готiвкою в одному з центрiв ЦНАП вашого мiста." << endl;
		}
		else if (pay == 2)
		{
			cout << "Сплата банкiвською картою на офiцiйному сайтi ЦНАП." << endl;
			cout << "Номер карти: " << card << endl;
		}

		cout << endl;
		cout << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << "Вiтаємо, якщо ви бажаєте оформити заяву про реєстрацiю права властностi на землю, будь ласка, виберiть один з варiантiв" << endl;

	Authorisation auth;

	Person* city;
	city = &auth;
	city->Choice();

	auth.Account();

	Cadastral_number cd;
	city = &cd;
	city->Choice();

	cd.Response_cad();

	cd.Rights();
	cd.Admin_fee();
	cd.Response();

	cout << "Варiант сплати:" << endl;

	Payment pay;
	pay.Pay_method();


	Statement st;
	st.Statement_method(auth.option, auth.name, auth.surname, auth.middle, auth.ident, auth.passport, cd.cad_number, cd.amount, pay.pay, pay.card);


}
