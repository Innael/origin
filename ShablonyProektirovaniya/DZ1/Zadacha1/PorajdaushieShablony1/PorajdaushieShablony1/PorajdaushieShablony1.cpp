#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>

#pragma execution_character_set ( "utf-8" )

class SqlSelectQueryBuilder {
public:
	std::vector<std::string> sel_collumn{ 20 ,"" };
	std::vector<std::pair<std::string, std::string>> where_vec{ 20 };
	std::string column_pool;
	std::string table_name;	
	int* iterator1 = new int;
	int* iterator2 = new int;

	SqlSelectQueryBuilder() {
		*iterator1 = 0;
		*iterator2 = 0;
	}

	SqlSelectQueryBuilder& AddColumn(std::string col) {
		int chek = 0;
		for (auto const& elem : sel_collumn) {
			if (elem == col) {
				chek = 1;
			}
			if (chek == 0) {
				sel_collumn[*iterator1] = col;
				++*iterator1;
			}
			return*this;
		}
	}

	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept {		
		for (auto const& columns_elem : columns){			
					sel_collumn[*iterator1] = columns_elem;
					++*iterator1;								
		}
		return*this;
	}

	void AddFrom(std::string table) {
		table_name = table;
	}

	SqlSelectQueryBuilder& AddWhere(std::string col, std::string name) {
		where_vec[*iterator2] = make_pair(col, name);
		++*iterator2;
		return*this;
	}

	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept {
		for (auto const& elem : kv) {
			where_vec[*iterator2] = elem;
			++*iterator2;
		}
		return*this;
	}

	std::string virtual BuildQuery() {
		std::string s, s1, s2, sc, s3, res;
		if (*iterator2 > 0) {
			for (int i = 0; i < *iterator2; ++i) {
				s1 = where_vec[i].first;
				s2 = where_vec[i].second;
				if (i == 0) {
					if (s1 == "id") {
						s = "WHERE " + s1 + " = " + s2;
					}
					else {
						s2 = "'" + s2 + "'";
						s = "WHERE " + s1 + " = " + s2;
					}
				}
				else {
					if (s1 == "id") {
						s = s + " AND " + s1 + " = " + s2;
					}
					else {
						s2 = "'" + s2 + "'";
						s = s + " AND " + s1 + " = " + s2;
					}
				}
			}
		}		
		if (*iterator1 == 0) {
			res = "SELECT * FROM " + table_name + " " + s;						
		}
		else {			
			for (int i = 0; i < *iterator1; ++i) {
				if (*iterator1 == 1) {
					sc = sel_collumn[i];									
				}
				else {
					if (i == 0) sc = sel_collumn[i];
					else {
						s3 = ", " + sel_collumn[i];
						sc += s3;
					}
				}
			}
			res = "SELECT " + sc + " FROM " + table_name + " " + s;								
		}


		for (int i = 0; i < *iterator1; ++i) {
			sel_collumn[i] = "";
		}

		for (int i = 0; i < *iterator2; ++i) {
			where_vec[i].first = "";
			where_vec[i].second = "";
		}

		*iterator1 = 0;
		*iterator2 = 0;
		return res;
	}

	~SqlSelectQueryBuilder() {
		delete iterator1;
		delete iterator2;
	}
};




class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder{
public:
	void AddAdditionalCondition(std::string c1, std::string c2, std::string c3) {
		con_vec[0] = c1;
		con_vec[1] = c2;
		con_vec[2] = c3;
	}

	std::string BuildQuery() override {
		std::string s, s1, s2, s_sim, sc, s3, res;
		if (*iterator2 > 0) {
			for (int i = 0; i < *iterator2; ++i) {
				s1 = where_vec[i].first;
				s2 = where_vec[i].second;
				if (i == 0) {					
					if (s1 == "id") {
						s = "WHERE " + s1 + " = " + s2;
					}
					else {
						s2 = "'" + s2 + "'";
						s = "WHERE " + s1 + " = " + s2;
					}
				}
				else {
					if (s1 == "id") {
						s = s + " AND " + s1 + " = " + s2;
					}
					else {
						s2 = "'" + s2 + "'";
						s = s + " AND " + s1 + " = " + s2;
					}
				}
			}
			if (con_vec[0] != "") {
				s1 = con_vec[0];
				s_sim = con_vec[1];
				s2 = con_vec[2];
				if (s1 == "id") {
					s = s + " AND " + s1 + " " + s_sim + " " + s2;
				}
				else {
					s2 = "'" + s2 + "'";
					s = s + " AND " + s1 + " " + s_sim + " " + s2;
				}
			}
		}

		if (*iterator2 == 0 && con_vec[0] != "") {
			s1 = con_vec[0];
			s_sim = con_vec[1];
			s2 = con_vec[2];
			if (s1 == "id") {
				s = "WHERE " + s1 + " " + s_sim + " " + s2;
			}
			else {
				s2 = "'" + s2 + "'";
				s = "WHERE " + s1 + " " + s_sim + " " + s2;
			}
		}

		if (*iterator1 == 0) {
			res = "SELECT * FROM " + table_name + " " + s;
		}
		else {			
			for (int i = 0; i < *iterator1; ++i) {
				if (*iterator1 == 1) {
					sc = sel_collumn[i];
				}
				else {
					if (i == 0) sc = sel_collumn[i];
					else {
						s3 = ", " + sel_collumn[i];
						sc += s3;
					}
				}
			}
			res = "SELECT " + sc + " FROM " + table_name + " " + s;
		}


		for (int i = 0; i < *iterator1; ++i) {
			sel_collumn[i] = "";
		}

		for (int i = 0; i < *iterator2; ++i) {
			where_vec[i].first = "";
			where_vec[i].second = "";
		}

		for (int i = 0; i < 3; ++i) {
			con_vec[i] = "";
		}

		*iterator1 = 0;
		*iterator2 = 0;
		return res;
	}

private:
	std::vector<std::string> con_vec{ 3, "" };
};

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	std::map<std::string, std::string> conditions_map = { {"id", "43"} , {"name", "Erika"} };
	std::vector<std::string> columns_vector {"name", "last_name", "phone"};

	SqlSelectQueryBuilder query_builder;

	//query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddColumns(columns_vector);
	query_builder.AddFrom("students");
	//query_builder.AddWhere("id", "42").AddWhere("name", "John");
	query_builder.AddWhere(conditions_map);
	//query_builder.AddWhere("last_name", "Wood").AddWhere("name", "Steeve");
	std::string result = query_builder.BuildQuery();
	
	std::cout << "Итоговая строка запроса: \n";

	std::cout << result << "\n\n";

	AdvancedSqlSelectQueryBuilder adv_q_b;

	adv_q_b.AddColumn("name").AddColumn("phone");
	adv_q_b.AddFrom("teachers");
	adv_q_b.AddAdditionalCondition("id", ">", "15");

	result = adv_q_b.BuildQuery();

	std::cout << "Итоговая строка запроса продвинутого класса: \n";

	std::cout << result << "\n\n";
    
	return 0;
}

