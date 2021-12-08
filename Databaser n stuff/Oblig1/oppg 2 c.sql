USE Oblig1;

CREATE TABLE IF NOT EXISTS Invoice (	
	INr INT,
    Name VARCHAR(30) NOT NULL,
    KID INT,
    Adress VARCHAR(20),
    Cash Float,
    CONSTRAINT PK_Customers PRIMARY KEY(INr)
    ) Engine=InnoDB;
    
    INSERT INTO Invoice Values
    (11, 'Mo',1234, 'GateVeien 5', 100.00),
    (22, 'Mo',1434, 'GateVeien 5', 150.00),
    (33, 'Morgan',7945, 'GateVeien 5', 160.00),
    (44, 'Castro',0083, 'GateVeien 5', 1990.00);
    
    

     
    