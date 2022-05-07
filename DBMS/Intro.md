*** Evolution ***
1. File Based(User code directly interacted with the data stored on OS's filesystem. User has to himself take care of several issues like consistency, redundancy, security, concurrency, performance etc.)

2. Relational DBMS(User code interacts with DBMS layer above the OS's filesystem)(Relational DBMS stores data in form of tables and each table has a schema) e.g. Oracle, mySQL etc. Relational DBMS provides structured query language(sql) using which the user can interact with the DB. They can also provide admin panels to configure several aspects of the DBMS.

3. NoSQL: RDBMS requires all of the data to follow the structure/schema. NoSQL DBMS are used in case data do not fit into any particular schema. e.g. MongoDB, DynamoDB,Cassandra
