--------------------------------------------------------
--  File created - Saturday-December-07-2024   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table MACHINE
--------------------------------------------------------

  CREATE TABLE "TERRANOVA"."MACHINE" 
   (	"MACHINEID" NUMBER, 
	"SERIAL_NUMBER" NUMBER, 
	"TYPE" VARCHAR2(50 BYTE), 
	"MACHINE_STATUS" VARCHAR2(20 BYTE), 
	"LAST_MAINTENANCE_DATE" VARCHAR2(30 BYTE), 
	"FACTORY_ID" VARCHAR2(30 BYTE), 
	"NEXT_MAINTENANCE_DATE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table DELIVERY
--------------------------------------------------------

  CREATE TABLE "TERRANOVA"."DELIVERY" 
   (	"DELIVERY_ID" VARCHAR2(30 BYTE), 
	"CE_CLIENT_ID" VARCHAR2(30 BYTE), 
	"CE_EMPLOYEE_ID" VARCHAR2(30 BYTE), 
	"DELIVERY_ADDRESS" VARCHAR2(30 BYTE), 
	"STATUS" VARCHAR2(30 BYTE), 
	"DELIVERY_DATE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CLIENT
--------------------------------------------------------

  CREATE TABLE "TERRANOVA"."CLIENT" 
   (	"CLIENT_ID" VARCHAR2(30 BYTE), 
	"NAME" VARCHAR2(30 BYTE), 
	"PHONE_NUMBER" NUMBER(*,0), 
	"EMAIL" VARCHAR2(30 BYTE), 
	"ADRESS" VARCHAR2(30 BYTE), 
	"TOTAL_ORDERS" NUMBER(*,0)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FACTORY
--------------------------------------------------------

  CREATE TABLE "TERRANOVA"."FACTORY" 
   (	"FACTORY_ID" VARCHAR2(20 BYTE), 
	"LOCATION" VARCHAR2(30 BYTE), 
	"CAPACITY" VARCHAR2(30 BYTE), 
	"TOTAL_EMPLOYEES" VARCHAR2(30 BYTE), 
	"TOTAL_MACHINES" VARCHAR2(30 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table ADMIN
--------------------------------------------------------

  CREATE TABLE "TERRANOVA"."ADMIN" 
   (	"ADMIN_ID" VARCHAR2(20 BYTE), 
	"NAME" VARCHAR2(30 BYTE), 
	"PASSWORD" VARCHAR2(30 BYTE), 
	"EMAIL" VARCHAR2(30 BYTE), 
	"IMAGE" BLOB
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" 
 LOB ("IMAGE") STORE AS BASICFILE (
  TABLESPACE "SYSTEM" ENABLE STORAGE IN ROW CHUNK 8192 RETENTION 
  NOCACHE LOGGING 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)) ;
--------------------------------------------------------
--  DDL for Table PRESENCE
--------------------------------------------------------

  CREATE TABLE "TERRANOVA"."PRESENCE" 
   (	"PRESENCE_ID" VARCHAR2(30 BYTE), 
	"EMPLOYEE_ID" VARCHAR2(30 BYTE), 
	"CHECK_IN" DATE, 
	"CHECK_OUT" DATE, 
	"WORKING_HOURS" NUMBER(5,2), 
	"STATUS" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CLIENTS
--------------------------------------------------------

  CREATE TABLE "TERRANOVA"."CLIENTS" 
   (	"CLIENTID" NUMBER, 
	"PHONE_NUMBER_C" NUMBER, 
	"EMAIL" VARCHAR2(20 BYTE), 
	"ADRESS" VARCHAR2(20 BYTE), 
	"TOTAL_ORDERS" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EMPLOYEE
--------------------------------------------------------

  CREATE TABLE "TERRANOVA"."EMPLOYEE" 
   (	"EMPLOYEE_ID" VARCHAR2(30 BYTE), 
	"NAME" VARCHAR2(30 BYTE), 
	"EMAIL" VARCHAR2(30 BYTE), 
	"PHONE_NUMBER" NUMBER(*,0), 
	"POSITION" VARCHAR2(30 BYTE), 
	"RFID_UID" VARCHAR2(30 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table DASHBOARD
--------------------------------------------------------

  CREATE TABLE "TERRANOVA"."DASHBOARD" 
   (	"DASHBOARDID" NUMBER, 
	"TOTAL_EMPLOYEES" NUMBER, 
	"TOTAL_MACHIJNES" NUMBER, 
	"TOTAL_FACTORIES" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table SUPERVISER
--------------------------------------------------------

  CREATE TABLE "TERRANOVA"."SUPERVISER" 
   (	"EMPLOYEE_ID" VARCHAR2(30 BYTE), 
	"FACTORY_ID" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table TABLEH
--------------------------------------------------------

  CREATE TABLE "TERRANOVA"."TABLEH" 
   (	"PRESENCEID" VARCHAR2(50 BYTE), 
	"EMPLOYEEID" VARCHAR2(20 BYTE), 
	"CHECK_IN" TIMESTAMP (6), 
	"CHECK_OUT" TIMESTAMP (6), 
	"WORKING_HOURS" NUMBER(5,2)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table TEMPERATURE
--------------------------------------------------------

  CREATE TABLE "TERRANOVA"."TEMPERATURE" 
   (	"MAX_TEMP" NUMBER, 
	"MIN_TEMP" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into TERRANOVA.MACHINE
SET DEFINE OFF;
Insert into TERRANOVA.MACHINE (MACHINEID,SERIAL_NUMBER,TYPE,MACHINE_STATUS,LAST_MAINTENANCE_DATE,FACTORY_ID,NEXT_MAINTENANCE_DATE) values (123456,987541,'Packaging Machines','working','12/04/2024','1',null);
Insert into TERRANOVA.MACHINE (MACHINEID,SERIAL_NUMBER,TYPE,MACHINE_STATUS,LAST_MAINTENANCE_DATE,FACTORY_ID,NEXT_MAINTENANCE_DATE) values (121213,101114,'food processing machines','not working','14/12/2024','1','26/12/2024');
REM INSERTING into TERRANOVA.DELIVERY
SET DEFINE OFF;
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D003','C3','E141','789 Pine Road','In Progress','22-11-24');
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D002','C23','E135','456 Oak Avenue','Ordered','2024-11-23');
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D004','C25','E183','101 Maple Lane','In Progress','2024-11-21');
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D005','C26','E245','202 Birch Blvd','Delivered','2024-11-20');
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D006','C3','E241','123 Main Street','Ordered','2024-11-01');
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D007','C3','E242','456 Park Avenue','In Progress','2024-11-02');
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D008','C23','E243','789 Elm Street','Delivered','2024-11-03');
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D009','C24','E244','321 Oak Lane','In Progress','22-11-24');
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D0010','C25','E245','654 Maple Drive','In Progress','2024-11-05');
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D0011','C26','E201','987 Pine Road','In Progress','2024-11-06');
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D0012','C27','E183','147 Cedar Street','Ordered','2024-11-07');
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D0013','C26','E184','258 Birch Boulevard','Delivered','2024-11-08');
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D0014','C23','E141','369 Ash Avenue','In Progress','2024-11-09');
Insert into TERRANOVA.DELIVERY (DELIVERY_ID,CE_CLIENT_ID,CE_EMPLOYEE_ID,DELIVERY_ADDRESS,STATUS,DELIVERY_DATE) values ('D0015','C24','E135','741 Willow Way','Delivered','2024-11-10');
REM INSERTING into TERRANOVA.CLIENT
SET DEFINE OFF;
Insert into TERRANOVA.CLIENT (CLIENT_ID,NAME,PHONE_NUMBER,EMAIL,ADRESS,TOTAL_ORDERS) values ('C3','sami',12457896,'sami@gmail.com','Ariana',1);
Insert into TERRANOVA.CLIENT (CLIENT_ID,NAME,PHONE_NUMBER,EMAIL,ADRESS,TOTAL_ORDERS) values ('C23','Alice Smith',1234567890,'alice.smith@example.com','123 Elm Street',10);
Insert into TERRANOVA.CLIENT (CLIENT_ID,NAME,PHONE_NUMBER,EMAIL,ADRESS,TOTAL_ORDERS) values ('C24','Bob Johnson',9876543210,'bob.johnson@example.com','456 Oak Avenue',5);
Insert into TERRANOVA.CLIENT (CLIENT_ID,NAME,PHONE_NUMBER,EMAIL,ADRESS,TOTAL_ORDERS) values ('C25','Catherine Brown',4561237890,'catherine.brown@example.com','789 Pine Road',7);
Insert into TERRANOVA.CLIENT (CLIENT_ID,NAME,PHONE_NUMBER,EMAIL,ADRESS,TOTAL_ORDERS) values ('C26','Daniel Green',3216549870,'daniel.green@example.com','101 Maple Lane',3);
Insert into TERRANOVA.CLIENT (CLIENT_ID,NAME,PHONE_NUMBER,EMAIL,ADRESS,TOTAL_ORDERS) values ('C27','Emma White',6549873210,'emma.white@example.com','202 Birch Blvd',8);
REM INSERTING into TERRANOVA.FACTORY
SET DEFINE OFF;
Insert into TERRANOVA.FACTORY (FACTORY_ID,LOCATION,CAPACITY,TOTAL_EMPLOYEES,TOTAL_MACHINES) values ('12','tunis','120','1','1');
REM INSERTING into TERRANOVA.ADMIN
SET DEFINE OFF;
Insert into TERRANOVA.ADMIN (ADMIN_ID,NAME,PASSWORD,EMAIL) values ('A20','rayen','rayen','rayen@gmail.com');
Insert into TERRANOVA.ADMIN (ADMIN_ID,NAME,PASSWORD,EMAIL) values ('A21','rayen','rayeen','mohamedrayen.rebai@esprit.tn');
REM INSERTING into TERRANOVA.PRESENCE
SET DEFINE OFF;
Insert into TERRANOVA.PRESENCE (PRESENCE_ID,EMPLOYEE_ID,CHECK_IN,CHECK_OUT,WORKING_HOURS,STATUS) values ('P21','E130',to_date('07-OCT-24','DD-MON-RR'),to_date('07-NOV-24','DD-MON-RR'),752,'Present');
Insert into TERRANOVA.PRESENCE (PRESENCE_ID,EMPLOYEE_ID,CHECK_IN,CHECK_OUT,WORKING_HOURS,STATUS) values ('P22','E130',to_date('07-NOV-24','DD-MON-RR'),to_date('07-NOV-24','DD-MON-RR'),8,'Present');
Insert into TERRANOVA.PRESENCE (PRESENCE_ID,EMPLOYEE_ID,CHECK_IN,CHECK_OUT,WORKING_HOURS,STATUS) values ('P42','E130',to_date('08-NOV-24','DD-MON-RR'),to_date('08-NOV-24','DD-MON-RR'),8,'Present');
REM INSERTING into TERRANOVA.CLIENTS
SET DEFINE OFF;
REM INSERTING into TERRANOVA.EMPLOYEE
SET DEFINE OFF;
Insert into TERRANOVA.EMPLOYEE (EMPLOYEE_ID,NAME,EMAIL,PHONE_NUMBER,POSITION,RFID_UID) values ('E130','ahmedd','ahmed@gmail.com',12345678,'Tech','B3318920');
Insert into TERRANOVA.EMPLOYEE (EMPLOYEE_ID,NAME,EMAIL,PHONE_NUMBER,POSITION,RFID_UID) values ('E241','John Doe','john.doe@example.com',1112223334,'Delivery Driver',null);
Insert into TERRANOVA.EMPLOYEE (EMPLOYEE_ID,NAME,EMAIL,PHONE_NUMBER,POSITION,RFID_UID) values ('E141','khaleddd','khaled@outlook.fr',54936175,'Tech',null);
Insert into TERRANOVA.EMPLOYEE (EMPLOYEE_ID,NAME,EMAIL,PHONE_NUMBER,POSITION,RFID_UID) values ('E183','SOUSOU','yes@gmail.fr',20604891,'Chef Cuisine',null);
Insert into TERRANOVA.EMPLOYEE (EMPLOYEE_ID,NAME,EMAIL,PHONE_NUMBER,POSITION,RFID_UID) values ('E201','hamadi','hamadi@esprit.tn',30584157,'Manager',null);
Insert into TERRANOVA.EMPLOYEE (EMPLOYEE_ID,NAME,EMAIL,PHONE_NUMBER,POSITION,RFID_UID) values ('E184','adazdaz','ZAAZE@gmail.com',14257485,'Manager',null);
Insert into TERRANOVA.EMPLOYEE (EMPLOYEE_ID,NAME,EMAIL,PHONE_NUMBER,POSITION,RFID_UID) values ('E135','souhaaa','souha@gmail.com',67891234,'Tech',null);
Insert into TERRANOVA.EMPLOYEE (EMPLOYEE_ID,NAME,EMAIL,PHONE_NUMBER,POSITION,RFID_UID) values ('E242','Jane Smith','jane.smith@example.com',2223334445,'Delivery Manager',null);
Insert into TERRANOVA.EMPLOYEE (EMPLOYEE_ID,NAME,EMAIL,PHONE_NUMBER,POSITION,RFID_UID) values ('E243','Robert Brown','robert.brown@example.com',3334445556,'Warehouse Manager',null);
Insert into TERRANOVA.EMPLOYEE (EMPLOYEE_ID,NAME,EMAIL,PHONE_NUMBER,POSITION,RFID_UID) values ('E244','Laura Green','laura.green@example.com',4445556667,'Logistics Specialist',null);
Insert into TERRANOVA.EMPLOYEE (EMPLOYEE_ID,NAME,EMAIL,PHONE_NUMBER,POSITION,RFID_UID) values ('E245','Michael Johnson','michael.johnson@example.com',5556667778,'Delivery Driver',null);
REM INSERTING into TERRANOVA.DASHBOARD
SET DEFINE OFF;
REM INSERTING into TERRANOVA.SUPERVISER
SET DEFINE OFF;
REM INSERTING into TERRANOVA.TABLEH
SET DEFINE OFF;
Insert into TERRANOVA.TABLEH (PRESENCEID,EMPLOYEEID,CHECK_IN,CHECK_OUT,WORKING_HOURS) values ('15','E130',to_timestamp('06-DEC-24 09.24.38.000000000 AM','DD-MON-RR HH.MI.SSXFF AM'),null,0);
Insert into TERRANOVA.TABLEH (PRESENCEID,EMPLOYEEID,CHECK_IN,CHECK_OUT,WORKING_HOURS) values ('16','E130',to_timestamp('06-DEC-24 09.26.49.000000000 AM','DD-MON-RR HH.MI.SSXFF AM'),null,0);
Insert into TERRANOVA.TABLEH (PRESENCEID,EMPLOYEEID,CHECK_IN,CHECK_OUT,WORKING_HOURS) values ('9','E130',to_timestamp('05-DEC-24 10.57.42.000000000 PM','DD-MON-RR HH.MI.SSXFF AM'),null,0);
Insert into TERRANOVA.TABLEH (PRESENCEID,EMPLOYEEID,CHECK_IN,CHECK_OUT,WORKING_HOURS) values ('10','E130',to_timestamp('05-DEC-24 11.01.49.000000000 PM','DD-MON-RR HH.MI.SSXFF AM'),null,0);
Insert into TERRANOVA.TABLEH (PRESENCEID,EMPLOYEEID,CHECK_IN,CHECK_OUT,WORKING_HOURS) values ('11','E130',to_timestamp('05-DEC-24 11.16.21.000000000 PM','DD-MON-RR HH.MI.SSXFF AM'),null,0);
Insert into TERRANOVA.TABLEH (PRESENCEID,EMPLOYEEID,CHECK_IN,CHECK_OUT,WORKING_HOURS) values ('12','E130',to_timestamp('05-DEC-24 11.16.34.000000000 PM','DD-MON-RR HH.MI.SSXFF AM'),null,0);
Insert into TERRANOVA.TABLEH (PRESENCEID,EMPLOYEEID,CHECK_IN,CHECK_OUT,WORKING_HOURS) values ('13','E130',to_timestamp('05-DEC-24 11.24.13.000000000 PM','DD-MON-RR HH.MI.SSXFF AM'),null,0);
Insert into TERRANOVA.TABLEH (PRESENCEID,EMPLOYEEID,CHECK_IN,CHECK_OUT,WORKING_HOURS) values ('14','E130',to_timestamp('06-DEC-24 09.23.48.000000000 AM','DD-MON-RR HH.MI.SSXFF AM'),null,0);
REM INSERTING into TERRANOVA.TEMPERATURE
SET DEFINE OFF;
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (23,21.7999992);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (24.1000004,22.2000008);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
Insert into TERRANOVA.TEMPERATURE (MAX_TEMP,MIN_TEMP) values (-1000,1000);
--------------------------------------------------------
--  DDL for Index MACHINE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "TERRANOVA"."MACHINE_PK" ON "TERRANOVA"."MACHINE" ("MACHINEID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index DELIVERY_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "TERRANOVA"."DELIVERY_PK" ON "TERRANOVA"."DELIVERY" ("DELIVERY_ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index CLIENT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "TERRANOVA"."CLIENT_PK" ON "TERRANOVA"."CLIENT" ("CLIENT_ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index FACTORY_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "TERRANOVA"."FACTORY_PK" ON "TERRANOVA"."FACTORY" ("FACTORY_ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index SYS_C007336
--------------------------------------------------------

  CREATE UNIQUE INDEX "TERRANOVA"."SYS_C007336" ON "TERRANOVA"."ADMIN" ("ADMIN_ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index SYS_C007342
--------------------------------------------------------

  CREATE UNIQUE INDEX "TERRANOVA"."SYS_C007342" ON "TERRANOVA"."PRESENCE" ("PRESENCE_ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index CLIENTID
--------------------------------------------------------

  CREATE UNIQUE INDEX "TERRANOVA"."CLIENTID" ON "TERRANOVA"."CLIENTS" ("CLIENTID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index EMPLOYEE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "TERRANOVA"."EMPLOYEE_PK" ON "TERRANOVA"."EMPLOYEE" ("EMPLOYEE_ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index DASHBOARDID
--------------------------------------------------------

  CREATE UNIQUE INDEX "TERRANOVA"."DASHBOARDID" ON "TERRANOVA"."DASHBOARD" ("DASHBOARDID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index SUPERVISER_FK
--------------------------------------------------------

  CREATE UNIQUE INDEX "TERRANOVA"."SUPERVISER_FK" ON "TERRANOVA"."SUPERVISER" ("EMPLOYEE_ID", "FACTORY_ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Trigger TRG_CLIENT_ID
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "TERRANOVA"."TRG_CLIENT_ID" 
BEFORE INSERT ON client
FOR EACH ROW
BEGIN
    IF :new.client_id IS NULL THEN
        -- Assign the next value from the sequence to client_id, prefixed with 'C'
        SELECT 'C' || TO_CHAR(client_seq.NEXTVAL) INTO :new.client_id FROM dual;
    END IF;
END;



/
ALTER TRIGGER "TERRANOVA"."TRG_CLIENT_ID" ENABLE;
--------------------------------------------------------
--  DDL for Trigger TRG_FACTORY_ID
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "TERRANOVA"."TRG_FACTORY_ID" 
BEFORE INSERT ON FACTORY
FOR EACH ROW
BEGIN
    IF :new.factory_id IS NULL THEN
        -- Assign the next value from the sequence to factory_id, prefixed with 'F'
        SELECT 'F' || TO_CHAR(factory_seq.NEXTVAL) INTO :new.factory_id FROM dual;
    END IF;
END;



/
ALTER TRIGGER "TERRANOVA"."TRG_FACTORY_ID" ENABLE;
--------------------------------------------------------
--  DDL for Trigger TRG_ADMIN_ID
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "TERRANOVA"."TRG_ADMIN_ID" 
BEFORE INSERT ON admin
FOR EACH ROW
BEGIN
    IF :new.admin_id IS NULL THEN
        -- Assign the next value from the sequence to admin_id, prefixed with 'A'
        SELECT 'A' || TO_CHAR(admin_seq.NEXTVAL) INTO :new.admin_id FROM dual;
    END IF;
END;


/
ALTER TRIGGER "TERRANOVA"."TRG_ADMIN_ID" ENABLE;
--------------------------------------------------------
--  DDL for Trigger TRG_CALCULATE_WORKING_HOURS
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "TERRANOVA"."TRG_CALCULATE_WORKING_HOURS" 
BEFORE INSERT OR UPDATE ON TERRANOVA.PRESENCE
FOR EACH ROW
BEGIN
    -- Calculate WORKING_HOURS if both CHECK_IN and CHECK_OUT are provided
    IF :new.CHECK_IN IS NOT NULL AND :new.CHECK_OUT IS NOT NULL THEN
        :new.WORKING_HOURS := ( :new.CHECK_OUT - :new.CHECK_IN ) * 24;
    END IF;
END;



/
ALTER TRIGGER "TERRANOVA"."TRG_CALCULATE_WORKING_HOURS" ENABLE;
--------------------------------------------------------
--  DDL for Trigger TRG_PRESENCE_ID
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "TERRANOVA"."TRG_PRESENCE_ID" 
BEFORE INSERT ON PRESENCE
FOR EACH ROW
BEGIN
    IF :new.presence_id IS NULL THEN
        -- Assign the next value from the sequence to delivery_id, prefixed with 'D'
        SELECT 'P' || TO_CHAR(presence_seq.NEXTVAL) INTO :new.presence_id FROM dual;
    END IF;
END;




/
ALTER TRIGGER "TERRANOVA"."TRG_PRESENCE_ID" ENABLE;
--------------------------------------------------------
--  DDL for Trigger TRG_VALIDATE_CHECK_OUT_DATE
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "TERRANOVA"."TRG_VALIDATE_CHECK_OUT_DATE" 
BEFORE INSERT OR UPDATE ON TERRANOVA.PRESENCE
FOR EACH ROW
BEGIN
    -- Check if CHECK_OUT is before CHECK_IN
    IF :new.CHECK_OUT IS NOT NULL AND :new.CHECK_IN IS NOT NULL AND :new.CHECK_OUT < :new.CHECK_IN THEN
        RAISE_APPLICATION_ERROR(-20001, 'Check-out date cannot be before check-in date.');
    END IF;
END;



/
ALTER TRIGGER "TERRANOVA"."TRG_VALIDATE_CHECK_OUT_DATE" ENABLE;
--------------------------------------------------------
--  DDL for Trigger TRG_EMPLOYEE_ID
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "TERRANOVA"."TRG_EMPLOYEE_ID" 
BEFORE INSERT ON employee
FOR EACH ROW
BEGIN
    IF :new.employee_id IS NULL THEN
        -- Assign the next value from the sequence to delivery_id, prefixed with 'D'
        SELECT 'E' || TO_CHAR(employee_seq.NEXTVAL) INTO :new.employee_id FROM dual;
    END IF;
END;



/
ALTER TRIGGER "TERRANOVA"."TRG_EMPLOYEE_ID" ENABLE;
--------------------------------------------------------
--  DDL for Trigger TRG_BEFORE_INSERT_TABLEH
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "TERRANOVA"."TRG_BEFORE_INSERT_TABLEH" 
BEFORE INSERT ON TABLEH
FOR EACH ROW
BEGIN
   :NEW.PRESENCEID := PRESENCEID_SEQ.NEXTVAL;
END;

/
ALTER TRIGGER "TERRANOVA"."TRG_BEFORE_INSERT_TABLEH" ENABLE;
--------------------------------------------------------
--  Constraints for Table MACHINE
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."MACHINE" MODIFY ("TYPE" NOT NULL ENABLE);
  ALTER TABLE "TERRANOVA"."MACHINE" ADD CONSTRAINT "MACHINE_PK" PRIMARY KEY ("MACHINEID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "TERRANOVA"."MACHINE" MODIFY ("MACHINEID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table DELIVERY
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."DELIVERY" MODIFY ("CE_EMPLOYEE_ID" NOT NULL ENABLE);
  ALTER TABLE "TERRANOVA"."DELIVERY" MODIFY ("CE_CLIENT_ID" NOT NULL ENABLE);
  ALTER TABLE "TERRANOVA"."DELIVERY" MODIFY ("DELIVERY_ID" NOT NULL ENABLE);
  ALTER TABLE "TERRANOVA"."DELIVERY" ADD CONSTRAINT "DELIVERY_PK" PRIMARY KEY ("DELIVERY_ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table CLIENT
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."CLIENT" ADD CONSTRAINT "CLIENT_PK" PRIMARY KEY ("CLIENT_ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "TERRANOVA"."CLIENT" MODIFY ("CLIENT_ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table FACTORY
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."FACTORY" MODIFY ("FACTORY_ID" NOT NULL DISABLE VALIDATE);
  ALTER TABLE "TERRANOVA"."FACTORY" ADD CONSTRAINT "FACTORY_PK" PRIMARY KEY ("FACTORY_ID") DISABLE VALIDATE;
--------------------------------------------------------
--  Constraints for Table ADMIN
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."ADMIN" ADD PRIMARY KEY ("ADMIN_ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "TERRANOVA"."ADMIN" MODIFY ("PASSWORD" NOT NULL ENABLE);
  ALTER TABLE "TERRANOVA"."ADMIN" MODIFY ("NAME" NOT NULL ENABLE);
  ALTER TABLE "TERRANOVA"."ADMIN" MODIFY ("EMAIL" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PRESENCE
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."PRESENCE" ADD PRIMARY KEY ("PRESENCE_ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "TERRANOVA"."PRESENCE" MODIFY ("PRESENCE_ID" NOT NULL ENABLE);
  ALTER TABLE "TERRANOVA"."PRESENCE" MODIFY ("EMPLOYEE_ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table CLIENTS
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."CLIENTS" MODIFY ("ADRESS" NOT NULL ENABLE);
  ALTER TABLE "TERRANOVA"."CLIENTS" ADD CONSTRAINT "CLIENTID" PRIMARY KEY ("CLIENTID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "TERRANOVA"."CLIENTS" MODIFY ("PHONE_NUMBER_C" NOT NULL ENABLE);
  ALTER TABLE "TERRANOVA"."CLIENTS" MODIFY ("CLIENTID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table EMPLOYEE
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."EMPLOYEE" ADD CONSTRAINT "EMPLOYEE_PK" PRIMARY KEY ("EMPLOYEE_ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "TERRANOVA"."EMPLOYEE" MODIFY ("EMPLOYEE_ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table DASHBOARD
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."DASHBOARD" ADD CONSTRAINT "DASHBOARDID" PRIMARY KEY ("DASHBOARDID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
--------------------------------------------------------
--  Constraints for Table SUPERVISER
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."SUPERVISER" ADD CONSTRAINT "SUPERVISER_FK" PRIMARY KEY ("EMPLOYEE_ID", "FACTORY_ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "TERRANOVA"."SUPERVISER" MODIFY ("FACTORY_ID" NOT NULL ENABLE);
  ALTER TABLE "TERRANOVA"."SUPERVISER" MODIFY ("EMPLOYEE_ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table DELIVERY
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."DELIVERY" ADD CONSTRAINT "DELIVERY_FK" FOREIGN KEY ("CE_CLIENT_ID")
	  REFERENCES "TERRANOVA"."CLIENT" ("CLIENT_ID") ENABLE;
  ALTER TABLE "TERRANOVA"."DELIVERY" ADD CONSTRAINT "DELIVERY_FK1" FOREIGN KEY ("CE_EMPLOYEE_ID")
	  REFERENCES "TERRANOVA"."EMPLOYEE" ("EMPLOYEE_ID") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table PRESENCE
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."PRESENCE" ADD CONSTRAINT "PRESENCE_FK" FOREIGN KEY ("EMPLOYEE_ID")
	  REFERENCES "TERRANOVA"."EMPLOYEE" ("EMPLOYEE_ID") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table SUPERVISER
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."SUPERVISER" ADD CONSTRAINT "SUPER_FK" FOREIGN KEY ("EMPLOYEE_ID")
	  REFERENCES "TERRANOVA"."EMPLOYEE" ("EMPLOYEE_ID") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table TABLEH
--------------------------------------------------------

  ALTER TABLE "TERRANOVA"."TABLEH" ADD CONSTRAINT "FK_EMPLOYEE" FOREIGN KEY ("EMPLOYEEID")
	  REFERENCES "TERRANOVA"."EMPLOYEE" ("EMPLOYEE_ID") ENABLE;