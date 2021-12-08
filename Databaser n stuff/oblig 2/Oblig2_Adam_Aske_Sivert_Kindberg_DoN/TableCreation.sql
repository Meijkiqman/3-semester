use humanstoragedevice;
DROP TABLE IF EXISTS Fanger;
DROP TABLE IF exists Ansatte;
DROP TABLE IF exists Celler;
DROP TABLE IF exists Rom;
DROP TABLE IF exists RomLog;

CREATE TABLE Fanger(
	FangeNR INT,
    Fornavn VARCHAR(20),
    Etternavn VARCHAR(20),
    InnsettelseDato DATE,
    LøslatelseDato DATE,
    Passord VARCHAR(20),
    SikkerhetRang INT,
    PersonNR INT,
    PRIMARY KEY(FangeNR)
)Engine = InnoDB;

CREATE TABLE Ansatte(
	AnsattNR INT,
    Fornavn VARCHAR(20),
    Etternavn VARCHAR(20),
    Passord VARCHAR(20),
    SikkerhetRang INT,
    primary key(AnsattNr)
)Engine = InnoDB;

CREATE TABLE Celler(
	CelleNR INT,
    FangeNR INT,
    Låst BOOL,
    PRIMARY KEY(CelleNR),
    foreign key (FangeNR) REFERENCES Fanger(FangeNR)
)Engine = INNODB;

CREATE TABLE Rom(
	RomNR INT, 
    SikkerhetNivå INT,
    RomNavn varchar(20),
    primary key(RomNR)
)ENgine = INNODB;

CREATE TABLE RomLog(
	RomNR INT, 
    FangeNR INT,
    GåttInnTid DATE,
    GåtUtTid DATE,
    foreign key(RomNR) REFERENCES Rom(RomNR)
)ENgine = INNODB;

CREATE TABLE Jobber(
	JobbNR INT,
    JobbNavn VARCHAR(20),
    JobbBeskrivelse varchar(20)
)Engine=InnoDB;
