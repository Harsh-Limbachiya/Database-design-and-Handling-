/*
Group 13 :Online Banking System
Members :
Name: Harsh Limbachiya     Email: hvlimbachiya@myseneca.ca    Student Id: 157295197
Name: Krish Patel          Email: kpatel387@myseneca.ca       Student Id: 124193210
Name: Roohi				   Email: r55@myseneca.ca             Student Id: 120835210
Milestone 2
DATE: 02-04-2022
*/

#include<iostream>
#include<iomanip>
#include<occi.h>

using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;


//############################################################################################
struct Customer
{
	int custID;
	string firstName;
	string lastName;
	string phone;
	string email;
	string addLine;
	string city;
	string country;
	int empId;
};

int findCustomer(Connection* conn, int customerId);
void displayCustomer(Connection* conn, struct Customer customer);
void displayAllCustomer(Connection* conn);
//########################################################################################
struct Employee
{
	int employeeNumber;
	string firstName;
	string lastName;
	string email;
	int departmentId;
	string jobTitle;
};

int findEmployee(Connection* conn, int empId);
void displayEmployee(Connection* conn, struct Employee employee);
void displayAllEmployee(Connection* conn);

//#######################################################################################

struct Payment
{
	int paymentNumber;
	string paymentMethod;
	double paymentAmount;
	int custId;
};

int findPayment(Connection* conn, int pay);
void displayPayment(Connection* conn, struct Payment payment);
void displayAllPayment(Connection* conn);


//########################################################################################
int main(void)
{
	Environment* env = nullptr;
	Connection* conn = nullptr;
	string str;
	string usr = "dbs211_221f18";
	string pass = "12003169";
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
	struct Customer customer;
	struct Employee employee;
	struct Payment payment;
	try
	{
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(usr, pass, srv);
		cout << "                         Database Connection is successful!" << endl;
		cout << "                            Project Milestone 1 and 2" << endl;
		cout << "                                  COURSE: DBS211" << endl;
		cout << "                         PURPOSE: DBS211_PROJECT_MILESTONE2" << endl;
		cout << "                                  GROUP: 13" << endl;
		cout << "                                GROUP MEMBERS: "<< endl;
		cout << "Name: Harsh Limbachiya     Email: hvlimbachiya@myseneca.ca    Student Id: 157295197" << endl;
		cout << "Name: Krish Patel          Email: kpatel387@myseneca.ca       Student Id: 124193210" << endl;
		cout << "Name: Roohi                Email: r55@myseneca.ca             Student Id: 120835210" << endl;
		cout << "                                 Milestone 2" << endl;
		cout << "                                DATE: 02-04-2022" << endl;
		int input = 0;
		do
		{
			cout << "\nHR MENU";
			cout << "\n1. Find Customer";
			cout << "\n2. Find Employee";
			cout << "\n3. Find Payment";
			cout << "\n4. Display Customer";
			cout << "\n5. Display Employee";
			cout << "\n6. Display Payment";
			cout << "\n7. Display All Customer";
			cout << "\n8. Display All Employee";
			cout << "\n9. Display All Payment";
			cout << "\n0. Exit";
			cout << "\n Enter Your Choice: ";
			cin >> input;
			if (input == 1)
			{
				cout << "\n Entering choice to find an customer";
				int cust;
				cout << "\n Enter Customer Number: ";
				cin >> cust;
				if (findCustomer(conn, cust) == 1)
				{
					cout << "\nValid Customer Number\n";
				}
				else
				{
					cout << "\nInvalid Customer Number\n";
				}
			}
			else if (input == 2)
			{
				cout << "\n Entering choice to find an employee";
				int emp;
				cout << "\n Enter Employee Number: ";
				cin >> emp;
				if (findEmployee(conn, emp) == 1)
				{
					cout << "\nValid Employee Number\n";
				}
				else
				{
					cout << "\nInvalid Employee Number\n";
				}
			}
			else if (input == 3)
			{
				cout << "\n Entering choice to find an Payment";
				int pay;
				cout << "\n Enter Payment Number: ";
				cin >> pay;
				if (findPayment(conn, pay) == 1)
				{
					cout << "\nValid Payment Number\n";
				}
				else
				{
					cout << "\nInvalid Payment Number\n";
				}
			}
			else if (input == 4)
			{
				cout << "\nEntering choice to display an Customer";
				displayCustomer(conn, customer);
			}
			else if (input == 5)
			{

				cout << "\nEntering choice to display an Employee";
				displayEmployee(conn, employee);
			}
			else if (input == 6)
			{
				cout << "\nEntering choice to display an Payment";
				displayPayment(conn, payment);
			}
			else if (input == 7)
			{
				cout << "\nEntering choice to display all customers\n";
				displayAllCustomer(conn);
			}else if(input == 8)
			{ 
				cout << "\nEntering choice to display all employees\n";
				displayAllEmployee(conn);
			}
			else if (input == 9)
			{
				cout << "\nEntering choice to display all employees\n";
				displayAllPayment(conn);
			}
		} while (input != 0);

		Statement* stmt = conn->createStatement();
		ResultSet* rs = stmt->executeQuery("SELECT custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId FROM customer ORDER BY custId");

		conn->terminateStatement(stmt);
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}

//###########################################################################################################

int findCustomer(Connection* conn, int customerId)
{
	Statement* stmt = conn->createStatement();
	ResultSet* rs = stmt->executeQuery("SELECT  custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId FROM customer WHERE custId =" + to_string(customerId));
	if (rs->next())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//############################################################################################################
void displayCustomer(Connection* conn, Customer customer)
{
	int ecode;
	bool correctCode = false;
	do
	{
		cout << "\nEnter customer number: ";
		cin >> ecode;
		if (!cin || findCustomer(conn, ecode) != 1)
		{
			correctCode = false;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nInvalid Customer number\n";
		}
		else
		{
			correctCode = true;
			cout << "\nValid Input";
			cout << "\nSearch in table ..." << endl;
			try
			{
				Statement* stmt2 = conn->createStatement();
				ResultSet* rs2 = stmt2->executeQuery("SELECT custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId FROM customer WHERE custId =" + to_string(ecode));
				while (rs2->next())
				{
					cout << "\n-------------- Customer Information --------------" << endl;
					customer.custID = rs2->getInt(1);
					customer.firstName = rs2->getString(2);
					customer.lastName = rs2->getString(3);
					customer.phone = rs2->getString(4);
					customer.email = rs2->getString(5);
					customer.addLine = rs2->getString(6);
					customer.city = rs2->getString(7);
					customer.country = rs2->getString(8);
					customer.empId = rs2->getInt(9);
					cout << "\n";
					cout << "Customer Id: ";
					cout << customer.custID;

					cout << "\n";
					cout << "Customer First Name: ";
					cout << customer.firstName;

					cout << "\n";
					cout << "Customer Last Name: ";
					cout << customer.lastName;

					cout << "\n";
					cout << "Customer Phone: ";
					cout << customer.phone;

					cout << "\n";
					cout << "Customer Email: ";
					cout << customer.email;

					cout << "\n";
					cout << "Customer Address: ";
					cout << customer.addLine;

					cout << "\n";
					cout << "Customer City: ";
					cout << customer.city;

					cout << "\n";
					cout << "Customer Country: ";
					cout << customer.country;

					cout << "\n";
					cout << "Custome EmpId: ";
					cout << customer.empId << endl;
				}
			}
			catch (SQLException& sqlExcp)
			{
				cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
			}//check this line 
		}
	} while (correctCode == false); //check this line 
};
//#################################################################################################################

void displayAllCustomer(Connection* conn)
{
	try
	{
		Statement* stmt3 = conn->createStatement();
		ResultSet* rs2 = stmt3->executeQuery("SELECT custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId FROM customer");
		cout.width(10);
		cout.setf(ios::left);
		cout << "#custId";
		cout.unsetf(ios::left);
		cout << " ";
		cout.width(15);
		cout.setf(ios::left);
		cout << "FirstName";
		cout.width(12);
		cout.setf(ios::left);
		cout << "LastName";

		cout.width(14);
		cout.setf(ios::left);
		cout << "phone";
		//cout << " ";
		cout.width(20);
		cout.setf(ios::left);
		cout << "Email";
		//cout << " ";
		cout.width(30);
		cout.setf(ios::left);
		cout << "addline";
		cout.width(17);
		cout.setf(ios::left);
		cout << "city";
		cout.width(12);
		cout.setf(ios::left);
		cout << "country";
		cout.width(15);
		cout.setf(ios::left);
		cout << "EmpId" << endl;
		cout.unsetf(ios::left);
		Customer cust;
		while (rs2->next())
		{
			cust.custID = rs2->getInt(1);
			cust.firstName = rs2->getString(2);
			cust.lastName = rs2->getString(3);
			cust.phone = rs2->getString(4);
			cust.email = rs2->getString(5);
			cust.addLine = rs2->getString(6);
			cust.city = rs2->getString(7);
			cust.country = rs2->getString(8);
			cust.empId = rs2->getInt(9);

			cout << " ";
			cout.width(10);
			cout.setf(ios::left);
			cout << cust.custID;
			cout.unsetf(ios::left);
			cout.width(15);
			cout.setf(ios::left);
			cout << cust.firstName;
			cout.unsetf(ios::left);

			cout.width(12);
			cout.setf(ios::left);
			cout << cust.lastName;
			cout.unsetf(ios::left);

			cout.width(14);
			cout.setf(ios::left);
			cout << cust.phone;
			cout.unsetf(ios::left);

			cout.width(20);
			cout.setf(ios::left);
			cout << cust.email;
			cout.unsetf(ios::left);

			cout.width(30);
			cout.setf(ios::left);
			cout << cust.addLine;
			cout.unsetf(ios::left);

			cout.width(17);
			cout.setf(ios::left);
			cout << cust.city;
			cout.unsetf(ios::left);

			cout.width(12);
			cout.setf(ios::left);
			cout << cust.country;
			cout.unsetf(ios::left);

			cout.width(15);
			cout.setf(ios::left);
			cout << cust.empId;
			cout.unsetf(ios::left);
			cout << endl;
		}
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}


//################################################################################################


int findEmployee(Connection* conn, int emp)
{
	Statement* stmt = conn->createStatement();
	ResultSet* rs = stmt->executeQuery("SELECT empNumber, empFirstName, empLastName,  empEmail, empDepartmentId, empJobTitle FROM employee WHERE empNumber=" + to_string(emp));
	if (rs->next())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//###########################################################################################################
void displayEmployee(Connection* conn, Employee employee)
{
	int ecode;
	bool correctCode = false;
	do
	{
		cout << "\nEnter employee number: ";
		cin >> ecode;
		if (!cin || findEmployee(conn, ecode) != 1)
		{
			correctCode = false;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nInvalid Employee number\n";
		}
		else
		{
			correctCode = true;
			cout << "\nValid Input";
			cout << "\nSearch in table ..." << endl;
			try
			{
				Statement* stmt2 = conn->createStatement();
				ResultSet* rs2 = stmt2->executeQuery("SELECT empNumber, empFirstName, empLastName,  empEmail, empDepartmentId, empJobTitle FROM employee WHERE empNumber=" + to_string(ecode));
				while (rs2->next())
				{
					cout << "\n-------------- Employee Information --------------" << endl;
					employee.employeeNumber = rs2->getInt(1);
					employee.firstName = rs2->getString(2);
					employee.lastName = rs2->getString(3);
					employee.email = rs2->getString(4);
					employee.departmentId = rs2->getInt(5);
					employee.jobTitle = rs2->getString(6);
					cout << "\n";
					cout << "Employee Id: ";
					cout << employee.employeeNumber;

					cout << "\n";
					cout << "Employee First Name: ";
					cout << employee.firstName;

					cout << "\n";
					cout << "Employee Last Name: ";
					cout << employee.lastName;

					cout << "\n";
					cout << "Employee Email: ";
					cout << employee.email;

					cout << "\n";
					cout << "Employee Department Id: ";
					cout << employee.departmentId;

					cout << "\n";
					cout << "Employee JobTitle ";
					cout << employee.jobTitle << endl;
				}
			}
			catch (SQLException& sqlExcp)
			{
				cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
			}//check this line 
		}
	} while (correctCode == false); //check this line 
};

//################################################################################################################


void displayAllEmployee(Connection* conn)
{
	try
	{
		Statement* stmt3 = conn->createStatement();
		ResultSet* rs2 = stmt3->executeQuery("SELECT empNumber, empFirstName, empLastName,  empEmail, empDepartmentId, empJobTitle FROM employee");
		cout.width(10);
		cout.setf(ios::left);
		cout << "#empId";
		cout.unsetf(ios::left);
		cout << " ";
		cout.width(15);
		cout.setf(ios::left);
		cout << "FirstName";
		cout.width(12);
		cout.setf(ios::left);
		cout << "LastName";
		cout.width(20);
		cout.setf(ios::left);
		cout << "Email";
		cout.width(15);
		cout.setf(ios::left);
		cout << "Department No";
		cout.width(17);
		cout.setf(ios::left);
		cout << "jobTitle" << endl;
		cout.unsetf(ios::left);
		Employee employee;
		while (rs2->next())
		{
			employee.employeeNumber = rs2->getInt(1);
			employee.firstName = rs2->getString(2);
			employee.lastName = rs2->getString(3);
			employee.email = rs2->getString(4);
			employee.departmentId = rs2->getInt(5);
			employee.jobTitle = rs2->getString(6);

			cout << " ";
			cout.width(10);
			cout.setf(ios::left);
			cout << employee.employeeNumber;
			cout.unsetf(ios::left);
			cout.width(15);
			cout.setf(ios::left);
			cout << employee.firstName;
			cout.unsetf(ios::left);

			cout.width(12);
			cout.setf(ios::left);
			cout << employee.lastName;
			cout.unsetf(ios::left);

			cout.width(20);
			cout.setf(ios::left);
			cout << employee.email;
			cout.unsetf(ios::left);

			cout.width(15);
			cout.setf(ios::left);
			cout << employee.departmentId;
			cout.unsetf(ios::left);

			cout.width(17);
			cout.setf(ios::left);
			cout << employee.jobTitle;
			cout.unsetf(ios::left);
			cout << endl;
		}
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}

//###############################################################################################



int findPayment(Connection* conn, int pay)
{
	Statement* stmt = conn->createStatement();
	ResultSet* rs = stmt->executeQuery("SELECT paymentNo, paymentMethod, paymentAmount, custId FROM payment WHERE paymentNo=" + to_string(pay));
	if (rs->next())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//##################################################################################################



void displayPayment(Connection* conn, Payment payment)
{
	int ecode;
	bool correctCode = false;
	do
	{
		cout << "\nEnter Payment number: ";
		cin >> ecode;
		if (!cin || findPayment(conn, ecode) != 1)
		{
			correctCode = false;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nInvalid Payment number\n";
		}
		else
		{
			correctCode = true;
			cout << "\nValid Input";
			cout << "\nSearch in table ..." << endl;
			try
			{
				Statement* stmt2 = conn->createStatement();
				ResultSet* rs2 = stmt2->executeQuery("SELECT paymentNo, paymentMethod, paymentAmount, custId FROM payment WHERE paymentNo=" + to_string(ecode));
				while (rs2->next())
				{
					cout << "\n-------------- Payment Information --------------" << endl;
					payment.paymentNumber = rs2->getInt(1);
					payment.paymentMethod = rs2->getString(2);
					payment.paymentAmount = rs2->getDouble(3);
					payment.custId = rs2->getInt(4);
					cout << "\n";
					cout << "Payment No: ";
					cout << payment.paymentNumber;

					cout << "\n";
					cout << "Payment Method: ";
					cout << payment.paymentMethod;

					cout << "\n";
					cout << "Payment Amount: ";
					cout << payment.paymentAmount;

					cout << "\n";
					cout << "Customer Id: ";
					cout << payment.custId << endl;
				}
			}
			catch (SQLException& sqlExcp)
			{
				cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
			}//check this line 
		}
	} while (correctCode == false); //check this line 
};

//######################################################################################################


void displayAllPayment(Connection* conn)
{
	try
	{
		Statement* stmt3 = conn->createStatement();
		ResultSet* rs2 = stmt3->executeQuery("SELECT paymentNo, paymentMethod, paymentAmount, custId FROM payment");
		cout.width(15);
		cout.setf(ios::left);
		cout << "#PaymentNo";
		cout.unsetf(ios::left);
		cout << " ";
		cout.width(15);
		cout.setf(ios::left);
		cout << "Payment Method";
		cout.width(15);
		cout.setf(ios::left);
		cout << "PaymentAmount";
		cout.width(7);
		cout.setf(ios::left);
		cout << "custId" << endl;
		Payment payment;
		while (rs2->next())
		{
			payment.paymentNumber = rs2->getInt(1);
			payment.paymentMethod = rs2->getString(2);
			payment.paymentAmount = rs2->getDouble(3);
			payment.custId = rs2->getInt(4);
			cout << " ";
			cout.width(15);
			cout.setf(ios::left);
			cout << payment.paymentNumber;
			cout.unsetf(ios::left);
			cout.width(15);
			cout.setf(ios::left);
			cout << payment.paymentMethod;
			cout.unsetf(ios::left);
			cout.width(15);
			cout.setf(ios::left);
			cout << payment.paymentAmount;
			cout.unsetf(ios::left);
			cout.width(7);
			cout.setf(ios::left);
			cout << payment.custId << endl;
			cout.unsetf(ios::left);
		}
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}

//######################################################################################################