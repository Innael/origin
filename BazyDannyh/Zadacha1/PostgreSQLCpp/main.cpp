#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>
#pragma execution_character_set ( "utd-8" )


class Client_Base {

public:

	void create_bs(pqxx::connection& con) {

		pqxx::transaction tr{ con };

		static const char* bs_str =
			"CREATE TABLE IF NOT EXISTS client_base(        \
             id SERIAL PRIMARY KEY,                         \
             name varchar(100) NOT NULL,                    \
             last_name varchar(100) NOT NULL,               \
             email varchar(100)  NOT NULL UNIQUE            \
             ); ";

		static const char* bs_addon =
			"CREATE TABLE IF NOT EXISTS client_phone(       \
			 id SERIAL PRIMARY KEY,                         \
             name varchar(100) NOT NULL,                    \
             last_name varchar(100) NOT NULL,               \
             phone_number varchar(60) NOT NULL UNIQUE       \
             ); ";

		

		tr.exec(bs_str);

		tr.exec(bs_addon);

		tr.commit();
	}

	void add_client(pqxx::connection& con) {

		pqxx::work ac{ con };

		std::string name, last_name, email;

		std::cout << "Enter client name: ";
		std::cin >> name; 
		
		std::cout << "Enter client's last name: ";
		std::cin >> last_name;

		std::cout << "Enter client's email: ";
		std::cin >> email;

		ac.exec("INSERT INTO client_base (name, last_name, email)"
		"VALUES ('" + ac.esc(name) + "', '" + ac.esc(last_name) + "', '" + ac.esc(email) + "' );");

		ac.commit();

	}

	void add_phone(pqxx::connection& con) {
	    
		pqxx::work ap{ con };

		std::string name, last_name, phone;

		std::cout << "Enter the name of the client whose number you want to add: ";
		std::cin >> name;

		std::cout << "Enter the last name of the client whose number you want to add: ";
		std::cin >> last_name;

		std::cout << "Enter the phone number you want to add: ";
		std::cin >> phone;		
		
		int a = ap.query_value<int>("SELECT id FROM client_base WHERE name = '" + ap.esc(name) + "' AND last_name = '" + ap.esc(last_name) + "' ");

		if (a == 0) {
			std::cout << "The specified client does not exist in this database." << std::endl; // - на случай если в базе есть подходящее имя у одного клиента, и подходящая фамилия у другого
		}
		
		ap.exec("INSERT INTO client_phone (name, last_name, phone_number)"
			"VALUES ('" + ap.esc(name) + "', '" + ap.esc(last_name) + "', '" + ap.esc(phone) + "' ) ");

		ap.commit();
	}

	void ap_data(pqxx::connection& con) {

		pqxx::work ad{ con };

		std::string name, last_name, email, phone, new_name, new_last_name, new_phone;
		int c = 0;

		std::cout << "Enter the name of the client whose details you want to change: ";
		std::cin >> name;

		std::cout << "Enter the last name of the client whose data you want to change: ";
		std::cin >> last_name;

		while (c != 6) {
			std::cout << "Select what you want to change: 1) First name 2) Last name 3) Email address 4) Phone 5) All together 6) Nothing \n";
			std::cin >> c;


			if (c == 1) {

				std::cout << "Enter a new name: ";
				std::cin >> new_name;

				ad.exec("UPDATE client_base SET name = '" + ad.esc(new_name) + "' WHERE  name = '" + ad.esc(name) + "' AND last_name = '" + ad.esc(last_name) + "' ");
				ad.exec("UPDATE client_phone SET name = '" + ad.esc(new_name) + "' WHERE  name = '" + ad.esc(name) + "' AND last_name = '" + ad.esc(last_name) + "' ");
			}
			else if (c == 2) {

				std::cout << "Enter a new last name: ";
				std::cin >> new_last_name;

				ad.exec("UPDATE client_base SET  last_name = '" + ad.esc(new_last_name) + "' WHERE  name = '" + ad.esc(name) + "' AND last_name = '" + ad.esc(last_name) + "' ");
				ad.exec("UPDATE client_phone SET last_name = '" + ad.esc(new_last_name) + "' WHERE  name = '" + ad.esc(name) + "' AND last_name = '" + ad.esc(last_name) + "' ");
			}
			else if (c == 3) {

				std::cout << "Enter a new email: ";
				std::cin >> email;

				ad.exec("UPDATE client_base SET  email = '" + ad.esc(email) + "' WHERE  name = '" + ad.esc(name) + "' AND last_name = '" + ad.esc(last_name) + "' ");
			}
			else if (c == 4) {

				std::cout << "Enter the phone number you want to replace: ";
				std::cin >> phone;

				std::cout << "Enter a new phone number: ";
				std::cin >> new_phone;

				ad.exec("UPDATE client_phone SET  phone_number = '" + ad.esc(new_phone) + "' WHERE  name = '" + ad.esc(name) + "' AND last_name = '" + ad.esc(last_name) + "' AND phone_number = '" + ad.esc(phone) + "' ");
			}
			else if (c == 5) {

				std::cout << "Enter a new name: ";
				std::cin >> new_name;

				ad.exec("UPDATE client_base SET name = '" + ad.esc(new_name) + "' WHERE  name = '" + ad.esc(name) + "' AND last_name = '" + ad.esc(last_name) + "' ");

				std::cout << "Enter a new last name: ";
				std::cin >> new_last_name;

				ad.exec("UPDATE client_base SET  last_name = '" + ad.esc(new_last_name) + "' WHERE  name = '" + ad.esc(new_name) + "' AND last_name = '" + ad.esc(last_name) + "' ");

				std::cout << "Enter a new email: ";
				std::cin >> email;

				ad.exec("UPDATE client_base SET  email = '" + ad.esc(email) + "' WHERE  name = '" + ad.esc(new_name) + "' AND last_name = '" + ad.esc(new_last_name) + "' ");

				std::cout << "Enter the phone number you want to replace: ";
				std::cin >> phone;

				std::cout << "Enter a new phone number: ";
				std::cin >> new_phone;

				ad.exec("UPDATE client_phone SET name = '" + ad.esc(new_name) + "' WHERE  name = '" + ad.esc(name) + "' AND last_name = '" + ad.esc(last_name) + "' ");
				ad.exec("UPDATE client_phone SET last_name = '" + ad.esc(new_last_name) + "' WHERE  name = '" + ad.esc(new_name) + "' AND last_name = '" + ad.esc(last_name) + "' ");
				ad.exec("UPDATE client_phone SET phone_number = '" + ad.esc(new_phone) + "' WHERE  name = '" + ad.esc(new_name) + "' AND last_name = '" + ad.esc(new_last_name) + "' AND phone_number = '" + ad.esc(phone) + "' ");
				
			}

		}

		ad.commit();
	}

	void del_phone(pqxx::connection& con) {
	
		pqxx::work dp { con };

		std::string name, last_name, phone;

		std::cout << "Enter the name of the client whose phone number you want to delete: ";
		std::cin >> name;

		std::cout << "Enter the last name of the client whose phone number you want to delete: ";
		std::cin >> last_name;

		std::cout << "Enter the phone number you want to delete: ";
		std::cin >> phone;

		dp.exec("DELETE FROM client_phone WHERE  name = '" + dp.esc(name) + "' AND last_name = '" + dp.esc(last_name) + "' AND phone_number = '" + dp.esc(phone) + "' ");

		dp.commit();
	}

	void del_client(pqxx::connection& con) {

		pqxx::work dc{ con };

		std::string name, last_name, email;

		std::cout << "Enter the name of the client you want to delete: ";
		std::cin >> name;

		std::cout << "Enter the last name of the client you want to delete: ";
		std::cin >> last_name;

		std::cout << "Enter the email of the client you want to delete: ";
		std::cin >> email;

		dc.exec("DELETE FROM client_base WHERE  name = '" + dc.esc(name) + "' AND last_name = '" + dc.esc(last_name) + "' AND email = '" + dc.esc(email) + "' ");

		dc.exec("DELETE FROM client_phone WHERE  name = '" + dc.esc(name) + "' AND last_name = '" + dc.esc(last_name) + "' ");

		dc.commit();
	}

	void search(pqxx::connection& con) {  

		pqxx::work sr{ con };

		std::string v_name, v_last_name, v_email, v_phone;
		int c = 0;

		while(c < 1 || c > 4) {
			std::cout << "By what parameter to search for a client: 1) First name 2) Last name 3) Email address 4) Phone \n";
			std::cin >> c;
		}

		if (c == 1) {

			std::cout << "Enter the name: ";
			std::cin >> v_name;
		
			for (auto [nm, ln, em] : sr.query<std::string, std::string, std::string>(
				"SELECT name, last_name, email FROM client_base WHERE name = '" + sr.esc(v_name) + "'  "))
			{
				std::cout << nm << "\t" << ln << "\t" << em << std::endl;
			}
			std::cout << "\n";

			for (auto [nm, ln, pn] : sr.query<std::string, std::string, std::string>(
				"SELECT client_phone.name, client_phone.last_name, phone_number FROM client_phone WHERE name = '" + sr.esc(v_name) + "'  "))
			{
				std::cout << nm << "\t" << ln << "\t" << pn << std::endl;
			}
		}
		else if (c == 2) {

			std::cout << "Enter the last name: ";
			std::cin >> v_last_name;

			for (auto [nm, ln, em] : sr.query<std::string, std::string, std::string>(
				"SELECT name, last_name, email FROM client_base WHERE last_name = '" + sr.esc(v_last_name) + "'  "))
			{
				std::cout << nm << "\t" << ln << "\t" << em << std::endl;
			}
			std::cout << "\n";

			for (auto [nm, ln, pn] : sr.query<std::string, std::string, std::string>(
				"SELECT client_phone.name, client_phone.last_name, phone_number FROM client_phone WHERE last_name = '" + sr.esc(v_last_name) + "'  "))
			{
				std::cout << nm << "\t" << ln << "\t" << pn << std::endl;
			}
		}
		else if (c == 3) {

			std::cout << "Enter the email: ";
			std::cin >> v_email;

			for (auto [nm, ln, em] : sr.query<std::string, std::string, std::string>(
				"SELECT name, last_name, email FROM client_base WHERE email = '" + sr.esc(v_email) + "'  "))
			{
				std::cout << nm << "\t" << ln << "\t" << em << std::endl;
			}
			std::cout << "\n";

			for (auto [nm, ln, em, pn] : sr.query<std::string, std::string, std::string, std::string>(
				"SELECT client_phone.name, client_phone.last_name, client_base.email, phone_number FROM client_phone    \
                 JOIN client_base ON client_phone.name = client_base.name  AND client_phone.last_name = client_base.last_name\
                 WHERE email = '" + sr.esc(v_email) + "'  "))
			{
				std::cout << nm << "\t" << ln << "\t" << pn << std::endl;
			}
		}
		else if (c == 4) {

			std::cout << "Enter the phone number: ";
			std::cin >> v_phone;

			for (auto [nm, ln, em, pn] : sr.query<std::string, std::string, std::string, std::string>(
				"SELECT client_phone.name, client_phone.last_name, email, phone_number FROM client_base \
                JOIN client_phone ON client_base.name = client_phone.name AND client_base.last_name = client_phone.last_name\
                WHERE phone_number = '" + sr.esc(v_phone) + "'  "))
			{
				std::cout << nm << "\t" << ln << "\t" << em << "\t" << pn << std::endl;
			}
			std::cout << "\n";

			for (auto [nm, ln, pn] : sr.query<std::string, std::string, std::string>(
				"SELECT name, last_name, phone_number FROM client_phone WHERE last_name = '" + sr.esc(v_last_name) + "'  "))
			{
				std::cout << nm << "\t" << ln << "\t" << pn << std::endl;
			}
		}
	}

};

int main()
{
	
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);
	//setlocale(LC_ALL, "Russian");

	try {

		pqxx::connection con(
			"host = localhost"
			" port=5432"
			" dbname=DZPhone"
			" user=TS_user"
			" password=secretPassvord7742");

		int c = 0,c2 = 0;
		Client_Base clbs;

		while (c != 1 && c != 2) {
			std::cout << "Do you want to create a new database? \n 1)Yes, yes, I really want to! \n 2) No, no, I don't want to at all \n";
			std::cin >> c;

			if (c == 1) {
				clbs.create_bs(con);
			}
		}
		
		while (c2 != 7) {
			std::cout << "Choose an action: 1) Add a client 2) Add a new phone number 3) Change client details 4) Delete phone number 5) Remove a client from the database 6) Get data on request 7) End database operations \n";
			std::cin >> c2;

			if (c2 == 1) {
				clbs.add_client(con);
			}
			else if (c2 == 2) {
				clbs.add_phone(con);
			}
			else if (c2 == 3) {
				clbs.ap_data(con);
			}
			else if (c2 == 4) {
				clbs.del_phone(con);
			}
			else if (c2 == 5) {
				clbs.del_client(con);
			}
			else if (c2 == 6) {
				clbs.search(con);
			}
		}		


	}catch (const std::exception& e )
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	return 0;
}