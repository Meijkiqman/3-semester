USE Oblig1;

CREATE TABLE IF NOT EXISTS Customers (	
	KNr INT,
    Lastname VARCHAR(20) NOT NULL,
    Firstname VARCHAR(20),
    Adress VARCHAR(20),
    Zipcode INT,
    CONSTRAINT PK_Customers PRIMARY KEY(KNr)
    ) Engine=InnoDB;
    
    INSERT INTO Customers Values
    (1, 'Mo','Kari', 'GateVeien 5', 1312),
    (2, 'Morgan', 'Arthur', 'VeiGata 13', 1153),
    (3, 'Castro','Fidel', 'CubaParken', 1953);