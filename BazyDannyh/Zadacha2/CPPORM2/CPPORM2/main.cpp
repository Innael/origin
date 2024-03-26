#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <Windows.h>
#pragma execution_character_set ( "utd-8" )
#include <vector>




class Book;
class Stock;
class Shop;
class Sale;



class Publisher {
public:	

	std::string name = "";
	Wt::Dbo::collection <Wt::Dbo::ptr<Book>> book ;

	template<class Action>
	void persist(Action& a){		
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

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);
	//setlocale(LC_ALL, "Russian");

	try {
		std::string connectionString =
			"host = localhost"
			" port=5432"
			" dbname=Book_Sales"
			" user=TS_user"
			" password=secretPassvord7742";		

		auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
		Wt::Dbo::Session session;
		session.setConnection(std::move(postgres));
		session.mapClass<Publisher>("publisher");
		session.mapClass<Book>("book");
		session.mapClass<Stock>("stock");
		session.mapClass<Shop>("shop");
		session.mapClass<Sale>("sale");

		int c = 0, search_id = 0;
		std::string search_name;

		std::vector<std::string> isd{ "Moria", "Valinor", "Angband", "Numenor", "Beleriand" };
		std::vector<std::string> bk{ "Two Trees", "Dagor Bragollach", "Secret Kingdom", "Glory of Atlante", "Lunar Silver of the Depths" };
		std::vector<std::string> shp{ "Dwarven reading", "Elven Chronicles", "Fairy tales for the most hobbits", "Books for everyone", "Orc Real Authentic Truth" };
		
		Wt::Dbo::Transaction transaction{ session };

		while (c != 1 && c != 2) {

			std::cout << "Do you want to create tables?\n 1)Yes\n 2)No\n ";
			std::cin >> c;

			if (c == 1) {

				session.createTables();

				std::unique_ptr<Publisher> publisher1{ new Publisher() };
				publisher1->name = isd[1 - 1];
				Wt::Dbo::ptr<Publisher> publisherPtr1 = session.add(std::move(publisher1));

				std::unique_ptr<Publisher> publisher2{ new Publisher() };
				publisher2->name = isd[2 - 1];
				Wt::Dbo::ptr<Publisher> publisherPtr2 = session.add(std::move(publisher2));

				std::unique_ptr<Publisher> publisher3{ new Publisher() };
				publisher3->name = isd[3 - 1];
				Wt::Dbo::ptr<Publisher> publisherPtr3 = session.add(std::move(publisher3));

				std::unique_ptr<Publisher> publisher4{ new Publisher() };
				publisher4->name = isd[4 - 1];
				Wt::Dbo::ptr<Publisher> publisherPtr4 = session.add(std::move(publisher4));

				std::unique_ptr<Publisher> publisher5{ new Publisher() };
				publisher5->name = isd[5 - 1];
				Wt::Dbo::ptr<Publisher> publisherPtr5 = session.add(std::move(publisher5));


				std::unique_ptr<Book> book1{ new Book() };
				book1->title = bk[1 - 1];
				Wt::Dbo::ptr<Book> bookPtr1 = session.add(std::move(book1));
				bookPtr1.modify()->id_publisher = publisherPtr2;

				std::unique_ptr<Book> book2{ new Book() };
				book2->title = bk[2 - 1];
				Wt::Dbo::ptr<Book> bookPtr2 = session.add(std::move(book2));
				bookPtr2.modify()->id_publisher = publisherPtr3;

				std::unique_ptr<Book> book3{ new Book() };
				book3->title = bk[3 - 1];
				Wt::Dbo::ptr<Book> bookPtr3 = session.add(std::move(book3));
				bookPtr3.modify()->id_publisher = publisherPtr5;

				std::unique_ptr<Book> book4{ new Book() };
				book4->title = bk[4 - 1];
				Wt::Dbo::ptr<Book> bookPtr4 = session.add(std::move(book4));
				bookPtr4.modify()->id_publisher = publisherPtr4;

				std::unique_ptr<Book> book5{ new Book() };
				book5->title = bk[5 - 1];
				Wt::Dbo::ptr<Book> bookPtr5 = session.add(std::move(book5));
				bookPtr5.modify()->id_publisher = publisherPtr1;


				std::unique_ptr<Shop> shop1{ new Shop() };
				shop1->name = shp[1 - 1];
				Wt::Dbo::ptr<Shop> shopPtr1 = session.add(std::move(shop1));

				std::unique_ptr<Shop> shop2{ new Shop() };
				shop2->name = shp[2 - 1];
				Wt::Dbo::ptr<Shop> shopPtr2 = session.add(std::move(shop2));

				std::unique_ptr<Shop> shop3{ new Shop() };
				shop3->name = shp[3 - 1];
				Wt::Dbo::ptr<Shop> shopPtr3 = session.add(std::move(shop3));

				std::unique_ptr<Shop> shop4{ new Shop() };
				shop4->name = shp[4 - 1];
				Wt::Dbo::ptr<Shop> shopPtr4 = session.add(std::move(shop4));

				std::unique_ptr<Shop> shop5{ new Shop() };
				shop5->name = shp[5 - 1];
				Wt::Dbo::ptr<Shop> shopPtr5 = session.add(std::move(shop5));


				std::unique_ptr<Stock> stock1{ new Stock() };
				stock1->count = 30;
				Wt::Dbo::ptr<Stock> stockPtr1 = session.add(std::move(stock1));
				stockPtr1.modify()->id_book = bookPtr1;
				stockPtr1.modify()->id_shop = shopPtr3;

				std::unique_ptr<Stock> stock2{ new Stock() };
				stock2->count = 19232;
				Wt::Dbo::ptr<Stock> stockPtr2 = session.add(std::move(stock2));
				stockPtr2.modify()->id_book = bookPtr2;
				stockPtr2.modify()->id_shop = shopPtr5;

				std::unique_ptr<Stock> stock3{ new Stock() };
				stock3->count = 27;
				Wt::Dbo::ptr<Stock> stockPtr3 = session.add(std::move(stock3));
				stockPtr3.modify()->id_book = bookPtr3;
				stockPtr3.modify()->id_shop = shopPtr2;

				std::unique_ptr<Stock> stock4{ new Stock() };
				stock4->count = 335;
				Wt::Dbo::ptr<Stock> stockPtr4 = session.add(std::move(stock4));
				stockPtr4.modify()->id_book = bookPtr4;
				stockPtr4.modify()->id_shop = shopPtr4;

				std::unique_ptr<Stock> stock5{ new Stock() };
				stock5->count = 1316;
				Wt::Dbo::ptr<Stock> stockPtr5 = session.add(std::move(stock5));
				stockPtr5.modify()->id_book = bookPtr5;
				stockPtr5.modify()->id_shop = shopPtr1;


				std::unique_ptr<Sale> sale1{ new Sale() };
				sale1->price = 999.99;
				sale1->date_sale = "3023-07-04";
				sale1->count = 4201;
				Wt::Dbo::ptr<Sale> salePtr1 = session.add(std::move(sale1));
				salePtr1.modify()->id_stok = stockPtr2;

				std::unique_ptr<Sale> sale2{ new Sale() };
				sale2->price = 33.29;
				sale2->date_sale = "3023-07-05";
				sale2->count = 12;
				Wt::Dbo::ptr<Sale> salePtr2 = session.add(std::move(sale2));
				salePtr2.modify()->id_stok = stockPtr1;

				std::unique_ptr<Sale> sale3{ new Sale() };
				sale3->price = 77.00;
				sale3->date_sale = "3023-09-23";
				sale3->count = 10;
				Wt::Dbo::ptr<Sale> salePtr3 = session.add(std::move(sale3));
				salePtr3.modify()->id_stok = stockPtr4;

				std::unique_ptr<Sale> sale4{ new Sale() };
				sale4->price = 129.32;
				sale4->date_sale = "3025-01-01";
				sale4->count = 1;
				Wt::Dbo::ptr<Sale> salePtr4 = session.add(std::move(sale4));
				salePtr4.modify()->id_stok = stockPtr5;

				std::unique_ptr<Sale> sale5{ new Sale() };
				sale5->price = 9731;
				sale5->date_sale = "3027-05-09";
				sale5->count = 3;
				Wt::Dbo::ptr<Sale> salePtr5 = session.add(std::move(sale5));
				salePtr5.modify()->id_stok = stockPtr3;

				//transaction.commit();  - почему то не требуется
			}
		}

		typedef Wt::Dbo::collection<Wt::Dbo::ptr<Book>> Books;
		typedef Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> Stocks;
		typedef Wt::Dbo::collection<Wt::Dbo::ptr<Shop>> Shops;
		c = 0;

		while (c != 3) {
			std::cout << '\n';
			std::cout << "What parameters should you use to search for a publisher?\n 1)Name\n 2)id\n 3)Quit the program\n";
			std::cin >> c;
			if (c == 1) {
				std::cout << "Which publisher are you interested in: ";
				std::cin >> search_name;

				Wt::Dbo::ptr<Publisher> searchPtr = session.find<Publisher>().where("name = ?").bind(search_name);				

				std::cout << "Publisher: " << searchPtr->name << "\tPublisher id: " << searchPtr.id() << std::endl;

				Books books = session.find<Book>().where("publisher_id = ?").bind(searchPtr.id());
				

				std::cout << " Published books: ";

				for (const Wt::Dbo::ptr<Book>& bk : books) {
					std::cout << bk->title << " , " << std::endl;
					Stocks stocks = session.find<Stock>().where("book_id = ?").bind(bk.id());
					for (const Wt::Dbo::ptr<Stock>& st : stocks) {
						Wt::Dbo::ptr<Shop> shopPtr = session.find<Shop>().where("id = ?").bind(st->id_shop);
						std::cout << " Shop where you can find books from this publisher: " << shopPtr->name << " , " << std::endl;
					}
				}			

			}
			else if (c == 2) {
				std::cout << '\n';
				std::cout << "Enter publisher id: ";
				std::cin >> search_id;				

				Wt::Dbo::ptr<Publisher> searchPtr = session.find<Publisher>().where("id = ?").bind(search_id);

				std::cout << "Publisher: " << searchPtr->name << "\tPublisher id: " << searchPtr.id() << std::endl;

				Books books = session.find<Book>().where("publisher_id = ?").bind(searchPtr.id());


				std::cout << " Published books: ";

				for (const Wt::Dbo::ptr<Book>& bk : books) {
					std::cout << bk->title << " , " << std::endl;
					Stocks stocks = session.find<Stock>().where("book_id = ?").bind(bk.id());
					for (const Wt::Dbo::ptr<Stock>& st : stocks) {
						Wt::Dbo::ptr<Shop> shopPtr = session.find<Shop>().where("id = ?").bind(st->id_shop);
						std::cout << " Shop where you can find books from this publisher: " << shopPtr->name << " , " << std::endl;
					}
				}
			}

		}

	}catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}