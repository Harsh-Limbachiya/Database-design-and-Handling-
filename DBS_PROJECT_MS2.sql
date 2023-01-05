/*
Group 13 :Online Banking System
Members : 
Name: Harsh Limbachiya     Email: hvlimbachiya@myseneca.ca    Student Id: 157295197
Name: Krish Patel          Email: kpatel387@myseneca.ca       Student Id: 124193210
Name: Roohi				         Email: r55@myseneca.ca             Student Id: 120835210
Milestone 2 
DATE: 02-04-2022
*/

SET AUTOCOMMIT ON;

/*branch Table */
CREATE TABLE  branch(
    branchCode INT NOT NULL,
    branchName VARCHAR2(25) NOT NULL,
    branchAddress VARCHAR2(35) NOT NULL,
    country VARCHAR2(25) NOT NULL,
    postalCode VARCHAR2(10),
    CONSTRAINT PK_branchCode PRIMARY KEY(branchCode) 
);
/*employee*/
CREATE TABLE employee(
    empNumber INT NOT NULL,
    empFirstName  VARCHAR(20) NOT NULL, 
    empLastName VARCHAR(20) NOT NULL,
    empEmail VARCHAR(30) NOT NULL,
    empDepartmentId INT NOT NULL,
    empJobTitle VARCHAR(20),
    CONSTRAINT pk_empNumber PRIMARY KEY (empNumber),
    CONSTRAINT fk_departmentID
    FOREIGN KEY (empDepartmentId)
    REFERENCES department (departmentCode)   
);
/*department Table */
CREATE TABLE department (
    departmentCode INT NOT NULL,
    departmentName VARCHAR2(30) NOT NULL,
    managerId INT NOT NULL,
    managerName VARCHAR(30) NOT NULL,
    branchCode INT NOT NULL,
    CONSTRAINT department_pk PRIMARY KEY (departmentCode),
    CONSTRAINT fk_managerID 
    FOREIGN KEY (managerId)
    REFERENCES employee (empNumber),
    CONSTRAINT fk_branchCode
    FOREIGN KEY (branchCode)
    REFERENCES branch (branchCode)
);
/*acount Details table */
CREATE TABLE accountDetail(
    accountId INT NOT NULL,
    accountType VARCHAR2(15),
    custId INT NOT NULL,
    custName VARCHAR2(40),
    CONSTRAINT pk_account_Id PRIMARY KEY (accountId)
);
/*customer table */
CREATE TABLE customer(
    custId  INT NOT NULL,
    custFirstName VARCHAR2(20) NOT NULL,
    custLastName VARCHAR2(20) NOT NULL,
    custPhone VARCHAR2(14) NOT NULL,
    custEmail VARCHAR2(20) NOT NULL,
    custAddress VARCHAR2(30) NOT NULL,
    city VARCHAR2(20),
    country VARCHAR2(20),
    empId INT NOT NULL,
    CONSTRAINT pk_custId PRIMARY KEY (custId),
    CONSTRAINT fk_empId 
    FOREIGN KEY (empId)
    REFERENCES employee (empNumber) 
);
/*Loan Table*/
CREATE TABLE loan(
   loanId INT NOT NULL,
   loanType VARCHAR2(20),
   loanAmount INT,
   custId INT NOT NULL,
   loanSanctioned DATE,
   loanExpiry DATE,
   empNumber INT,
   CONSTRAINT pk_loanId PRIMARY KEY(loanId),
   CONSTRAINT FK_custId 
   FOREIGN KEY (custId)
   REFERENCES customer (custId)
);
/*Payment method */
CREATE TABLE payment(
 paymentNo INT NOT NULL,
 paymentMethod  VARCHAR2(10),
 paymentAmount DECIMAL NOT NULL,
 custId INT NOT NULL,
 CONSTRAINT pk_paymentNo PRIMARY KEY (paymentNo),
 CONSTRAINT fk_payment_custId 
 FOREIGN KEY (custId)
 REFERENCES customer (custId) 
);

/*insertting data into  accountDetails table*/
INSERT ALL 
    INTO accountDetail (accountId, accountType, custId, custName)
    VALUES (111, 'SAVING', 1234, 'Jonny')
    INTO accountDetail (accountId, accountType, custId, custName)
    VALUES (112, 'SAVING', 1235, 'David')
    INTO accountDetail (accountId, accountType, custId, custName)
    VALUES (113, 'CURRENT', 1236, 'Roy')
    INTO accountDetail (accountId, accountType, custId, custName)
    VALUES (114, 'SAVING', 1237, 'Allen')
    INTO accountDetail (accountId, accountType, custId, custName)
    VALUES (115, 'CURRENT', 1238, 'Anselm')
    INTO accountDetail (accountId, accountType, custId, custName)
    VALUES (116, 'SAVING', 1239, 'Harry')
    INTO accountDetail (accountId, accountType, custId, custName)
    VALUES (117, 'SAVING', 1240, 'Harsh')
    INTO accountDetail (accountId, accountType, custId, custName)
    VALUES (118, 'CURRENT', 1241, 'Ronny')
    INTO accountDetail (accountId, accountType, custId, custName)
    VALUES (119, 'SAVING', 1242, 'Saim')
    INTO accountDetail (accountId, accountType, custId, custName)
    VALUES (120, 'CURRENT', 1243, 'Joy')
    SELECT * FROM dual;
    
    SELECT * FROM accountDetail;

/*insertting data into branch table*/    
    INSERT ALL 
    INTO branch (branchCode , branchName, branchAddress, country, postalCode)
    VALUES(01, 'Roseland Branch', '32 Jump st', 'Canada', 'L12R0W')
    INTO branch (branchCode , branchName, branchAddress, country, postalCode)
    VALUES(02, 'Kingston Branch', ' Kingston st', 'Canada', 'L1W32I')
    INTO branch (branchCode , branchName, branchAddress, country, postalCode)
    VALUES(03, 'Harbour Branch', 'Middle Harbour st', 'Australia', 'wQ901k')
    INTO branch (branchCode , branchName, branchAddress, country, postalCode)
    VALUES(04, 'Qatar Branch', 'Al-Mohammed Rd ', 'Qatar', 'L1SOWH')
    INTO branch (branchCode , branchName, branchAddress, country, postalCode)
    VALUES(05, 'India Branch', 'Vasai Gandhi Rd', 'India', '4002323')
    INTO branch (branchCode , branchName, branchAddress, country, postalCode)
    VALUES(06, 'England Branch', 'Pat Tower, Quinton rd', 'ENGLAND', 'LOU221')
    INTO branch (branchCode , branchName, branchAddress, country, postalCode)
    VALUES(07, 'Newyork Branch', 'NY Square, Hamad Towers', 'America', 'PO12FI')
    INTO branch (branchCode , branchName, branchAddress, country, postalCode)
    VALUES(08, 'Ontario Branch', 'Beverly st', 'Canada', 'L1OP0W')
    INTO branch (branchCode , branchName, branchAddress, country, postalCode)
    VALUES(09, 'Germany Branch', 'Yumink  Manisto st', 'Germany', '298LKQ')
    INTO branch (branchCode , branchName, branchAddress, country, postalCode)
    VALUES(10, 'Africa Branch', '1403 Tanzo st', 'Africa', '43TQO2')
    SELECT * FROM dual;
    
    SELECT * FROM branch;
    
    
    /*insertting data into department table*/
    INSERT ALL 
    INTO department(departmentCode, departmentName, managerId, managerName, branchCode)
    VALUES(5001, 'president', 2010, 'Henry Stuart', 01)
    INTO department(departmentCode, departmentName, managerId, managerName, branchCode)
    VALUES(5002, 'VP Sales', 2011, 'Mark Martin', 02)
    INTO department(departmentCode, departmentName, managerId, managerName, branchCode)
    VALUES(5003, 'VP Marketing', 2012, 'John Smith', 03)
    INTO department(departmentCode, departmentName, managerId, managerName, branchCode)
    VALUES(5004, 'Sales Manager', 2013, 'will paterson', 04)
    INTO department(departmentCode, departmentName, managerId, managerName, branchCode)
    VALUES(5005, 'Sales rep', 2013, 'will patterson', 04)
    INTO department(departmentCode, departmentName, managerId, managerName, branchCode)
    VALUES(5006, 'Loan', 2013, 'will patterson', 05)
    INTO department(departmentCode, departmentName, managerId, managerName, branchCode)
    VALUES(5007, 'cash Handler', 2011, 'Mark Martin', 02)
    INTO department(departmentCode, departmentName, managerId, managerName, branchCode)
    VALUES(5008, 'accouting', 2010, 'Henry Stuart', 03)
    SELECT * FROM dual;
    COMMIT;
    
    
    /*insertting data into employee table*/
    INSERT ALL
    INTO employee(empNumber, empFirstName, empLastName, empEmail, empDepartmentId, empJobTitle)
    VALUES (2010, 'Henry', 'stuart', 'hstuart@gmail.com', 5001, 'President')
    INTO employee(empNumber, empFirstName, empLastName, empEmail, empDepartmentId, empJobTitle)
    VALUES (2011, 'Mark', 'martin', 'mMartin@gmail.com', 5002, 'VP Sales')
    INTO employee(empNumber, empFirstName, empLastName, empEmail, empDepartmentId, empJobTitle)
    VALUES (2012, 'John', 'smith', 'jsmith@gmail.com', 5003, 'VP Marketing')
    INTO employee(empNumber, empFirstName, empLastName, empEmail, empDepartmentId, empJobTitle)
    VALUES (2013, 'will', 'patterson', 'wpaterson@gmail.com', 5004, 'Sale Manager')
    INTO employee(empNumber, empFirstName, empLastName, empEmail, empDepartmentId, empJobTitle)
    VALUES (2014, 'Julie', 'firrelli', 'Juliefirr@gmail.com', 5005, 'Sales Rep') 
    INTO employee(empNumber, empFirstName, empLastName, empEmail, empDepartmentId, empJobTitle)
    VALUES (2015, 'nishi', 'mani', 'NishiMani@gmail.com', 5005, 'Sales Rep')
    INTO employee(empNumber, empFirstName, empLastName, empEmail, empDepartmentId, empJobTitle)
    VALUES (2016, 'marsh', 'peter', 'mpeter@gmail.com', 5005, 'Sales Rep')
    INTO employee(empNumber, empFirstName, empLastName, empEmail, empDepartmentId, empJobTitle)
    VALUES (2017, 'Andy', 'bernard', 'abernard@gmail.com', 5006, 'Loan')
    INTO employee(empNumber, empFirstName, empLastName, empEmail, empDepartmentId, empJobTitle)
    VALUES (2018, 'george', 'vanuaf', 'gvanuaf@gmail.com', 5007, 'cash handler')
    INTO employee(empNumber, empFirstName, empLastName, empEmail, empDepartmentId, empJobTitle)
    VALUES (2019, 'fardard', 'stanny', 'fstanny@gmail.com', 5008, 'acounting')
    SELECT * FROM dual;
    COMMIT;
    
    
    /*insertting data into  customer table*/
    INSERT ALL 
     INTO customer (custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId)
     VALUES(1234, 'Murphy', 'Diane', '+1736376737', 'dmurphy@classic.com', '8489 Strong St.', 'Las Vegas', 'USA', 2010)
     INTO customer (custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId)
     VALUES(1235, 'Ferguson','Peter', '7025551838',  'fp@classic.com', '636 St Kilda Road', 'Melbourne', 'Australia', 2011)
     INTO customer (custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId)
     VALUES(1236, 'Ford', 'Peter', '62628278992', 'fpet@gmail.com', 'Lyonerstr. 34', 'Frankfurt', 'Germany', 2012)
     INTO customer (custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId)
     VALUES(1237, 'Patrik', 'Dsouza', '+1-8282999200', 'pDsou@yahoo.com', '5557 North Pendale Street', 'San Francisco', 'USA', 2013)
     INTO customer (custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId)
     VALUES(1238, 'Harry', 'Fensika', '8278220211', 'hfens@gmail.com', '897 Long Airport Avenue', 'NYC', 'USA', 2014)
     INTO customer (custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId)
     VALUES(1239, 'Will', 'Willy', '+1437828292', 'wwil@classic.com', 'Berguvsv�gen  8', 'Lulea', 'Sweden', 2015)
     INTO customer (custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId)
     VALUES(1240, 'Sean', 'Gustia', '8217273323', 'sGus@yahoo.com', 'Vinb�ltet 34', 'Kobenhavn', 'Denmark', 2016)
     INTO customer (custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId)
     VALUES(1241, 'Damian', 'Marley' ,'+12275667151', 'dMarl@gmail.com', '7586 Pompton St.', 'AllenTown', 'USA' ,2017)
     INTO customer (custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId)
     VALUES(1242, 'Eric', 'Kenny', '+2-1829988191', 'eKenn@yahoo.com', 'Bronz Apt. 3/6 Tesvikiye', 'Singapore', 'Singapore', 2018)
     INTO customer (custId, custFirstName, custLastName, custPhone, custEmail, custAddress, city, country, empId)
     VALUES(1243, 'Kato', 'Gerrard', '+1-9228882922', 'kGerra@gmail.com', '4658 Baden Av.', 'Cambridge', 'USA', 2019)
     SELECT * FROM dual;
     COMMIT;
     
        INSERT ALL 
        INTO payment (paymentNo, paymentMethod, paymentAmount,custId)
        VALUES(1, 'Online', 1000.90, 1234)
        INTO payment (paymentNo, paymentMethod, paymentAmount,custId)
        VALUES(2, 'Credit', 500, 1235)
        INTO payment (paymentNo, paymentMethod, paymentAmount,custId)
        VALUES(3, 'Debit', 200, 1236)
        INTO payment (paymentNo, paymentMethod, paymentAmount,custId)
        VALUES(4, 'Cash', 100, 1237)
        INTO payment (paymentNo, paymentMethod, paymentAmount,custId)
        VALUES(5, 'Mobile', 120.98, 1238)
        SELECT * FROM dual;
        COMMIT;