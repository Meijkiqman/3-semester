CREATE DATABASE IF NOT EXISTS HumanStorageDevice;
USE HumanStorageDevice;

DROP TABLE IF EXISTS Fanger;
DROP TABLE IF EXISTS Ansatte;
DROP TABLE IF EXISTS Rom;
DROP TABLE IF EXISTS Celler;
DROP TABLE IF EXISTS Bevegelser;
CREATE TABLE IF NOT EXISTS Fanger(
	FangeNR INT,
    Fornavn VARCHAR(20),
    Etternavn VARCHAR(20),
    InnsettelseDato DATE,
    LøslatelseDato DATE,
    Passord VARCHAR(20),
    SikkerhetsNivå INT,
    Personnummer LONG,
    PRIMARY KEY(FangeNR)
)Engine = INNODB;

CREATE TABLE Ansatte(
	AnsattNR INT,
    Fornavn VARCHAR(20),
    Etternavn VARCHAR(20),
    Passord VARCHAR(20),
    SikkerhetsNivå INT,
    PRIMARY KEY(AnsattNR)
)Engine = InnoDB;

CREATE TABLE Rom(
	RomNR INT, 
    SikkerhetNsivå INT,
    RomNavn varchar(20),
    primary key(RomNR)
)ENgine = INNODB;

CREATE TABLE Celler(
	CelleNR INT,
    FangeNR INT,
    PRIMARY KEY(CelleNR),
    FOREIGN KEY (FangeNR) REFERENCES Fanger(FangeNR)
)Engine = INNODB;

CREATE TABLE Bevegelser(
	RomNR INT,
    FangeNR INT,
    AnsattNR INT,
    Bevegesle VARCHAR(20),
    Tidspunkt DATETIME,
    FOREIGN KEY(RomNR) REFERENCES Rom(RomNR),
    FOREIGN KEY(FangeNR) REFERENCES Fanger(FangeNR),
    FOREIGN KEY(AnsattNR) REFERENCES Ansatte(AnsattNR)
)ENGINE = INNODB;
