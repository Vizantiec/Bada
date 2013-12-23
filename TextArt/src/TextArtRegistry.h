#ifndef TEXTARTREGISTRY_H_
#define TEXTARTREGISTRY_H_

#include <FBase.h>
#include <FIo.h>

using namespace Osp::Io;
using namespace Osp::Base;
using namespace Osp::Base::Collection;

class TextArtRegistry {
public:

	static bool updaterecent;
	static bool updatefavourites;

	static result Setup() {
		updaterecent = true;
		updatefavourites = true;

		Database database;

		String dbName(L"/Home/textart");
		String sql, sql2;

		result r = E_SUCCESS;

		r = database.Construct(dbName, true);

		// create database table
		sql.Append(L"CREATE TABLE IF NOT EXISTS recent ( id INTEGER PRIMARY KEY AUTOINCREMENT, ancii TEXT )");
		sql2.Append(L"CREATE TABLE IF NOT EXISTS favourites ( id INTEGER PRIMARY KEY AUTOINCREMENT, ancii TEXT UNIQUE )");
		r = database.ExecuteSql(sql, true);
		r = database.ExecuteSql(sql2, true);

		return r;
	}

	static void AddRecent(String value) {
		updaterecent = true;

		Database database;

		String dbName(L"/Home/textart");
		String statement, sql2, sql3;
		DbStatement* pStmt;
		DbEnumerator* pEnum;

		result r = E_SUCCESS;

		r = database.Construct(dbName, true);

		// DELETE
		database.BeginTransaction();
		sql2.Append(L"DELETE FROM recent WHERE ancii = ?");
		pStmt = database.CreateStatementN(sql2);
		pStmt->BindString(0, value);
		pEnum = database.ExecuteStatementN(*pStmt);
		database.CommitTransaction();

		// INSERT
		database.BeginTransaction();
		statement.Append(L"INSERT INTO recent (ancii) VALUES (?)");
		pStmt = database.CreateStatementN(statement);
		pStmt->BindString(0, value);
		pEnum = database.ExecuteStatementN(*pStmt);
		database.CommitTransaction();

		// DELETE
		database.BeginTransaction();
		sql3.Append(L"DELETE FROM recent WHERE id in (SELECT id FROM recent ORDER BY id DESC LIMIT 9, 1)");
		r = database.ExecuteSql(sql3, true);
		database.CommitTransaction();

		delete pStmt;
		delete pEnum;
	}

	static ArrayList* GetRecent() {
		ArrayList *data = new ArrayList;
		data->Construct();

		result r = E_SUCCESS;

		if(updaterecent) {

			Database database;

			String dbName(L"/Home/textart");
			String sql;


			r = database.Construct(dbName, true);

			sql.Append(L"SELECT ancii FROM recent ORDER BY id DESC");

			DbStatement* pStmt;
			pStmt = database.CreateStatementN(sql);

			DbEnumerator* pEnum;
			pEnum = database.ExecuteStatementN(*pStmt);
			if(pEnum) {
				updaterecent = false;
				pEnum->Reset();
				r = pEnum->MoveNext();
				while(r != E_OUT_OF_RANGE) {
					String item;
					pEnum->GetStringAt(0, item);
					data->Add(*(new String(item)));
					r = pEnum->MoveNext();
				}

				delete pEnum;
			}

			delete pStmt;

		}

		return data;
	}


	static void AddFavourite(String value) {
		updatefavourites = true;

		Database database;

		String dbName(L"/Home/textart");
		String statement, sql2;
		DbStatement* pStmt;
		DbEnumerator* pEnum;

		result r = E_SUCCESS;

		r = database.Construct(dbName, true);

		// DELETE

		// INSERT
		database.BeginTransaction();
		statement.Append(L"INSERT OR IGNORE INTO favourites (ancii) VALUES (?)");
		pStmt = database.CreateStatementN(statement);
		pStmt->BindString(0, value);
		pEnum = database.ExecuteStatementN(*pStmt);
		database.CommitTransaction();

		delete pStmt;
		delete pEnum;
	}


	static ArrayList* GetFavourites() {
		ArrayList *data = new ArrayList;
		data->Construct();

		result r = E_SUCCESS;

		if(updatefavourites) {

			Database database;

			String dbName(L"/Home/textart");
			String sql;


			r = database.Construct(dbName, true);

			sql.Append(L"SELECT ancii FROM favourites ORDER BY id DESC");

			DbStatement* pStmt;
			pStmt = database.CreateStatementN(sql);

			DbEnumerator* pEnum;
			pEnum = database.ExecuteStatementN(*pStmt);
			if(pEnum) {
				updatefavourites = false;
				pEnum->Reset();
				r = pEnum->MoveNext();
				while(r != E_OUT_OF_RANGE) {
					String item;
					pEnum->GetStringAt(0, item);
					data->Add(*(new String(item)));
					r = pEnum->MoveNext();
				}
				delete pEnum;
			}

			delete pStmt;

		}

		return data;
	}

	static void RemoveFavourite(String value) {
		updatefavourites = true;
		Database database;

		String dbName(L"/Home/textart");
		String sql;
		DbStatement* pStmt;
		DbEnumerator* pEnum;

		result r = E_SUCCESS;

		r = database.Construct(dbName, true);

		// DELETE
		database.BeginTransaction();
		sql.Append(L"DELETE FROM favourites WHERE ancii = ?");
		pStmt = database.CreateStatementN(sql);
		pStmt->BindString(0, value);
		pEnum = database.ExecuteStatementN(*pStmt);
		database.CommitTransaction();

		delete pStmt;
		delete pEnum;
	}

};

#endif
