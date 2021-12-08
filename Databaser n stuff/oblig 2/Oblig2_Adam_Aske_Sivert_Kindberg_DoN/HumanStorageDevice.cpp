#include <iostream>
#include <stdlib.h>
#include <string>
#include <mysql.h>
#include <iomanip>
#include <fstream>
void RegistrerBevegelse();
void FindAllMovementsOfAPrisoner();
void InsertANewPrisoner();
int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
const char* q;
std::string query;

int main()
{
    
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "", "HumanStorageDevice", 3306,NULL, 0);

    if (conn) {
        puts("Succsessful connection to database!");
        RegistrerBevegelse();
        FindAllMovementsOfAPrisoner();
        InsertANewPrisoner();
    }
    else {
        std::cout << "Didnt connect to database!";
            return 0;
    }
    return 0;
}



void RegistrerBevegelse()
{
    std::string fangeNr, RomNr;
    std::cout << "What prisoner is entering(By FangeNR or AnsattNR)?\n";
    getline(std::cin, fangeNr);
    std::cout << "What room are you entering(By RomNR)?\n";
    getline(std::cin, RomNr);
    query = "INSERT INTO Bevegelser("+ RomNr + ", NULL, "+ fangeNr+", 'UT', SYSDATE()); ";
    
    q = query.c_str();
    qstate = mysql_query(conn, q);
    if (!qstate) {
        std::cout << "\nInsertion sucsefull!\n";
    }
    else {
        std::cout << mysql_error(conn) << std::endl;
    }
}

void FindAllMovementsOfAPrisoner()
{
    std::string fangeNr;
    std::cout << "\nWhat prisoner's movement are you looking for?(By FangeNR)?\n";
    getline(std::cin, fangeNr);
    query = "SELECT * FROM Bevegelser WHERE FangeNR = " + fangeNr + " OR AnsattNR = '" + fangeNr + "";
    q = query.c_str();
    qstate = mysql_query(conn, q);
    if (!qstate) {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res)) {
            printf("RomNR: %s, Tidspunkt: %s, Bevegelse: %s\n", row[0], row[1], row[2]);
        }
    }
    else {
        std::cout << mysql_error(conn);
    }
}

void InsertANewPrisoner()
{
    std::string fangeNR, fornavn, etternavn, innsetelsedato, løslatelsedato, passord, sikkerhetsnivå, personnummer;
    std::cout << "FangeNR: ";
    getline(std::cin, fangeNR);
    std::cout << "Fornavn: ";
    getline(std::cin, fornavn);
    std::cout << "Etternavn: ";
    getline(std::cin, etternavn);
    
   query = "INSERT INTO Fanger VALUES(" + fangeNR + ", '" +  fornavn + "', '" + etternavn + "', '2012-5-13', '2022-12-24', '4132', 1, 04069749959); ";
    q = query.c_str();
    qstate = mysql_query(conn, q);
    if (!qstate) {
        res = mysql_store_result(conn);
        std::cout << "\nInsertion completed!\n";
    }
    else {
        std::cout << mysql_error(conn);
    }
}
