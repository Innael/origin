#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

class Book;
class Stock;
class Shop;
class Sale;



class Publisher {
public:

	std::string name = "";
	Wt::Dbo::collection <Wt::Dbo::ptr<Book>> book;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, book, Wt::Dbo::ManyToOne, "publisher");
	}

};

class Book {
public:

	std::string title = "";
	Wt::Dbo::ptr<Publisher> id_publisher;
	Wt::Dbo::collection <Wt::Dbo::ptr<Stock>> stock;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, title, "title");
		Wt::Dbo::belongsTo(a, id_publisher, "publisher");
		Wt::Dbo::hasMany(a, stock, Wt::Dbo::ManyToOne, "book");
	}
};

class Stock {
public:

	Wt::Dbo::ptr<Book> id_book;
	Wt::Dbo::ptr<Shop> id_shop;
	int count = 0;
	Wt::Dbo::weak_ptr <Sale> sale;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::belongsTo(a, id_book, "book");
		Wt::Dbo::belongsTo(a, id_shop, "shop");
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::hasOne(a, sale, "stock");
	}
};

class Shop {
public:

	std::string name = "";
	Wt::Dbo::collection <Wt::Dbo::ptr<Stock>> stock;

	template <class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, stock, Wt::Dbo::ManyToOne, "shop");
	}
};

class Sale {
public:

	double price = 0;
	std::string date_sale = "";
	Wt::Dbo::ptr<Stock> id_stok;
	int count = 0;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, price, "price");
		Wt::Dbo::field(a, date_sale, "date_sale");
		Wt::Dbo::belongsTo(a, id_stok, "stock");
		Wt::Dbo::field(a, count, "count");
	}
};


int main()
{


	return 0;
}