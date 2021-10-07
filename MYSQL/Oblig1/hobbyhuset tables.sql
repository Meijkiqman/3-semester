USE hobbyhuset;

CREATE TABLE Vare (
              Id Int,
              Navn VARCHAR(20), 
              Antall INT,
              Pris INT,
              Kategori VARCHAR(20),
	CONSTRAINT PRIMARY KEY(Id)
);
CREATE TABLE PrisEndring (
	PEId INT,
	Id Int,
	Dato DATE,
	GammelPris INT,
	NyPris INT,
	CONSTRAINT PRIMARY KEY(PEId),
	CONSTRAINT FOREIGN KEY(Id) REFERENCES Vare(Id)
);
INSERT INTO Vare VALUES (1003, 'Hammer', 10, 50, 'Verktøy');
INSERT INTO Vare VALUES (1013, 'Maling, 3 liter', 5, 129, 'Maling');
INSERT INTO Vare VALUES (1014, 'Maling, 1 liter', 50, 59, 'Maling');
INSERT INTO Vare VALUES (1029, 'Spikerpakke XY', 75, 60, 'Småting');
INSERT INTO PrisEndring VALUES (1, 1003, '2014-08-10', 40, 45);
INSERT INTO PrisEndring VALUES (2, 1003, '2014-08-10', 40, 45);
INSERT INTO PrisEndring VALUES (3, 1029, '2014-08-10', 40, 45);
