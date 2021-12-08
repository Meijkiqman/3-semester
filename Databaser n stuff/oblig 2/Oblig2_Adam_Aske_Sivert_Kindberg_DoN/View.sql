use HUMANSTOrAGEDEVICE;
DROP VIEW IF exists FangerCeller;
CREATE VIEW FangerCeller
AS
SELECT
CelleNR,
FangeNR
FROM 
Celler
INNER JOIN
	Fanger USING (FangeNR);
    
select * from FangerCeller;