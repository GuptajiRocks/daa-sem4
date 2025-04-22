+-------------------------+
|     Client (React)     |
|------------------------|
| - User Interface       |
| - QR Code Scanner      |
| - Transaction History  |
| - Dispute Form         |
+-----------+------------+
            |
            | HTTP Requests (REST API)
            v
+-----------+------------+
|   Server (Node.js)     |
|------------------------|
| - Express.js Framework |
| - API Routes           |
| - Business Logic       |
+-----------+------------+
            |
            | Database Queries
            v
+-----------+------------+
|   Database (MongoDB)   |
|------------------------|
| - Users Collection     |
| - Transactions         |
| - Disputes             |
+------------------------+


+------------------+
|      User        |
+------------------+
| - id             |
| - name           |
| - phoneNumber    |
| - email          |
| - password       |
| - balance        |
+------------------+
| + register()     |
| + login()        |
| + viewBalance()  |
| + sendMoney()    |
| + viewHistory()  |
| + raiseDispute() |
+------------------+

+----------------------+
|    Transaction       |
+----------------------+
| - id                 |
| - senderId           |
| - receiverId         |
| - amount             |
| - timestamp          |
| - status             |
+----------------------+
| + createTransaction()|
| + getTransaction()   |
+----------------------+

+----------------------+
|      Dispute         |
+----------------------+
| - id                 |
| - transactionId      |
| - userId             |
| - reason             |
| - status             |
+----------------------+
| + raiseDispute()     |
| + resolveDispute()   |
| + rejectDispute()    |
+----------------------+


User -> Client: Scan QR Code
Client -> Server: POST /transactions {receiverId, amount}
Server -> Database: Create Transaction Record
Database -> Server: Confirmation
Server -> Client: Transaction Success Response
Client -> User: Display Success Message
