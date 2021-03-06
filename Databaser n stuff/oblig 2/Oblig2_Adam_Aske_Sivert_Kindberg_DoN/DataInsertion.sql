use HumanStorageDevice;

INSERT INTO Fanger VALUES
(1234, 'Gunnar', 'Stoltenberg', '2012-5-13', '2022-12-24', '4132', 1, 04069749959),
(1432, 'Einar', 'Solberg', '2001-1-15', '2022-12-24', '4642', 1, 12069749359),
(1743, 'Rune', 'Olavsen', '2008-2-01', '2022-12-24', '3132', 1, 03069742159),
(7942, 'Steinar', 'as', '2002-10-10', '2022-12-24', '4182', 1, 11069749123),
(0923, 'Johnatan', 'Erikson', '2001-7-21', '2022-12-24', '4562', 1, 03069749359),
(7865, 'Jonas', 'Erikson', '1999-7-19', '2022-12-24', '1252', 1, 030697431239),
(4378, 'Sunniva', 'Erikson', '2018-12-24', '2022-12-24', '7642', 1, 0306974719),
(6234, 'Marte', 'Erikson', '2019-11-23', '2022-12-24', '4832', 1, 23069749959),
(8193, 'Sofie', 'Erikson', '2012-7-27', '2022-12-24', '4342', 1, 21069731659),
(3712, 'Truls', 'Erikson', '2014-8-21', '2022-12-24', '4442', 1, 03069125959),
(0532, 'Josefine', 'Erikson', '2005-3-15','2022-12-24', '3422', 1, 03069745959),
(1134, 'Elise', 'Erikson', '2003-7-16', '2022-12-24', '1112', 1, 0306974947),
(3512, 'Geir', 'Erikson', '2009-1-04', '2022-12-24', '2122', 1, 03069717959);

INSERT INTO Ansatte VALUES
(412, 'Sivert', 'Kindberg', 'Ae3219b', 3),
(251, 'Adam', 'Aske', '68be31', 3),
(835, 'Eivind', 'Gundersrud', '18ghE3', 3),
(619, 'Knut-Olav', 'Utistog', 'A3bC123', 3),
(934, 'Marthe', 'Knausgård', 'Passord123', 3);

INSERT INTO Rom VALUES
(1, 3, 'Bibliotek'),
(2, 2, 'Gymsal'),
(3, 2, 'Kantine'),
(4, 3, 'Kjøkken'),
(5, 3, 'TV-sal');

INSERT INTO Celler VALUES
(1, 1234),
(2, 1743),
(3, 7942),
(4, 1432),
(5, 0923),
(6, 7865),
(7, 4378),
(8, 6234),
(9, 8193),
(10, 3712),
(11, 0532),
(12, 1134),
(13, 3512);

INSERT INTO Bevegelser VALUES
(1, NULL, 412, 'UT', '2021-10-01 01:27:31');
