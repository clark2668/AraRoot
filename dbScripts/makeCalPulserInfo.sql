CREATE TABLE TESTBED(antCalId integer primary key, holeName text, antName text, pulserName text, antType text, polType text, antLocationX real, antLocationY real, antLocationZ real, cableDelay real, calibAntLocationX real, calibAntLocationY real, calibAntLocationZ real, calibCableDelay real);
CREATE TABLE ARA01(antCalId integer primary key, holeName text, antName text, pulserName text, antType text, polType text, antLocationX real, antLocationY real, antLocationZ real, cableDelay real, calibAntLocationX real, calibAntLocationY real, calibAntLocationZ real, calibCableDelay real);

CREATE TABLE ARA02(antCalId integer primary key, holeName text, antName text, pulserName text, antType text, polType text, antLocationX real, antLocationY real, antLocationZ real, cableDelay real, calibAntLocationX real, calibAntLocationY real, calibAntLocationZ real, calibCableDelay real);

CREATE TABLE ARA03(antCalId integer primary key, holeName text, antName text, pulserName text, antType text, polType text, antLocationX real, antLocationY real, antLocationZ real, cableDelay real, calibAntLocationX real, calibAntLocationY real, calibAntLocationZ real, calibCableDelay real);

CREATE TABLE ARA04(antCalId integer primary key, holeName text, antName text, pulserName text, antType text, polType text, antLocationX real, antLocationY real, antLocationZ real, cableDelay real, calibAntLocationX real, calibAntLocationY real, calibAntLocationZ real, calibCableDelay real);

CREATE TABLE ARA05(antCalId integer primary key, holeName text, antName text, pulserName text, antType text, polType text, antLocationX real, antLocationY real, antLocationZ real, cableDelay real, calibAntLocationX real, calibAntLocationY real, calibAntLocationZ real, calibCableDelay real);

CREATE TABLE ARA06(antCalId integer primary key, holeName text, antName text, pulserName text, antType text, polType text, antLocationX real, antLocationY real, antLocationZ real, cableDelay real, calibAntLocationX real, calibAntLocationY real, calibAntLocationZ real, calibCableDelay real);
--TESTBED Calpulsers
--Ant position only supplied for the pulser not the individual antennas

insert into TESTBED VALUES(0,"BH5","CH1","P1","kQuadSlot","kHorizontal",
0.17,-30.01,-17.61,0,
0.17,-30.01,-17.61,0
);
insert into TESTBED VALUES(1,"BH5","CV1","P1","kBicone","kVertical",
0.17,-30.01,-22.61,0,
0.17,-30.01,-22.61,0
);
insert into TESTBED VALUES(2,"BH6","CH2","P2","kQuadSlot","kHorizontal",
25.86,15.31,-34.26,0,
25.86,15.31,-34.26,0
);
insert into TESTBED VALUES(3,"BH6","CV2","P2","kBicone","kVertical",
25.86,15.31,-29.26,0,
25.86,15.31,-29.26,0
);
--Stick with only the 4 calibration pulsers since the other two aren't 
--And the AraStationInfo code needs fixing to handle more

--Insert into TESTBED VALUES(4,"BH7","CH3","P3","kQuadSlot","kHorizontal",
---26.81,13.2,-0.4,0,
---26.81,13.2,-0.4,0
--);
--insert into TESTBED VALUES(5,"BH7","CV3","P3","kBicone","kVertical",
---26.45,14.75,-0.4,0,
---26.45,14.75,-0.4,0
--);






--ARA01 Calpulers
--Ant position only supplied for the pulser not the individual antennas
--delay unkown (and not needed?)

insert into ARA01 VALUES(0,"BH5","CH1","P1","kQuadSlot","kHorizontal",
16.41430296,34.8273624,-36.1239816,0,
16.41430296,34.8273624,-36.1239816,0);
insert into ARA01 VALUES(1,"BH5","CV1","P1","kBicone","kVertical",
16.41430296,34.8273624,-36.1239816,0,
16.41430296,34.8273624,-36.1239816,0);
insert into ARA01 VALUES(2,"BH6","CH2","P2","kQuadSlot","kHorizontal",
36.585144,-18.2905908,-42.141648,0,
36.585144,-18.2905908,-42.141648,0);
insert into ARA01 VALUES(3,"BH6","CV2","P2","kBicone","kVertical",
36.585144,-18.2905908,-42.141648,0,
6.585144,-18.2905908,-42.141648,0);  


--ARA02 Calpulers
--Ant positions from Amy

insert into ARA02 VALUES(0,"BH5","CH1","P1","kQuadSlot","kHorizontal",
37.8746,-18.0508,-189.6406,0,
37.8746,-18.0508,-189.6406,0
);
insert into ARA02 VALUES(1,"BH5","CV1","P1","kBicone","kVertical",
37.8746,-18.0508,-192.9258,0,
37.8746,-18.0508,-192.9258,0
);
insert into ARA02 VALUES(2,"BH6","CH2","P2","kQuadSlot","kHorizontal",
17.7477,35.3359,-164.6540,0,
17.7477,35.3359,-164.6540,0
);

insert into ARA02 VALUES(3,"BH6","CV2","P2","kBicone","kVertical",
17.7477,35.3359,-167.9392,0,
17.7477,35.3359,-167.9392,0
);

--updated 15-07-13

--ARA03 Calpulers

insert into ARA03 VALUES(0,"BH5","CH1","P1","kQuadSlot","kHorizontal",
38.0057,-16.3989,-194.8979,0,
38.0057,-16.3989,-194.8979,0
);
insert into ARA03 VALUES(1,"BH5","CV1","P1","kBicone","kVertical",
38.0057,-16.3989,-198.1828,0,
38.0057,-16.3989,-198.1828,0
);
insert into ARA03 VALUES(2,"BH6","CH2","P2","kQuadSlot","kHorizontal",
17.9354,36.3856,-184.7263,0,
17.9354,36.3856,-184.7263,0
);
insert into ARA03 VALUES(3,"BH6","CV2","P2","kBicone","kVertical",
17.9354,36.3856,-188.0112,0,
17.9354,36.3856,-188.0112,0
);

--updated 15-07-13

--ARA04 Calpulers

insert into ARA04 VALUES(0,"BH5","CH1","P1","kQuadSlot","kHorizontal",
38.0057,-16.3989,-194.8979,0,
38.0057,-16.3989,-194.8979,0
);
insert into ARA04 VALUES(1,"BH5","CV1","P1","kBicone","kVertical",
38.0057,-16.3989,-198.1828,0,
38.0057,-16.3989,-198.1828,0
);
insert into ARA04 VALUES(2,"BH6","CH2","P2","kQuadSlot","kHorizontal",
17.9354,36.3856,-184.7263,0,
17.9354,36.3856,-184.7263,0
);
insert into ARA04 VALUES(3,"BH6","CV2","P2","kBicone","kVertical",
17.9354,36.3856,-188.0112,0,
17.9354,36.3856,-188.0112,0
);

--updated 17-05-17

--ARA04 Calpulers

insert into ARA05 VALUES(0,"BH5","CH1","P1","kQuadSlot","kHorizontal",
38.0057,-16.3989,-194.8979,0,
38.0057,-16.3989,-194.8979,0
);
insert into ARA05 VALUES(1,"BH5","CV1","P1","kBicone","kVertical",
38.0057,-16.3989,-198.1828,0,
38.0057,-16.3989,-198.1828,0
);
insert into ARA05 VALUES(2,"BH6","CH2","P2","kQuadSlot","kHorizontal",
17.9354,36.3856,-184.7263,0,
17.9354,36.3856,-184.7263,0
);
insert into ARA05 VALUES(3,"BH6","CV2","P2","kBicone","kVertical",
17.9354,36.3856,-188.0112,0,
17.9354,36.3856,-188.0112,0
);

--updated 17-05-17

--ARA04 Calpulers

insert into ARA06 VALUES(0,"BH5","CH1","P1","kQuadSlot","kHorizontal",
38.0057,-16.3989,-194.8979,0,
38.0057,-16.3989,-194.8979,0
);
insert into ARA06 VALUES(1,"BH5","CV1","P1","kBicone","kVertical",
38.0057,-16.3989,-198.1828,0,
38.0057,-16.3989,-198.1828,0
);
insert into ARA06 VALUES(2,"BH6","CH2","P2","kQuadSlot","kHorizontal",
17.9354,36.3856,-184.7263,0,
17.9354,36.3856,-184.7263,0
);
insert into ARA06 VALUES(3,"BH6","CV2","P2","kBicone","kVertical",
17.9354,36.3856,-188.0112,0,
17.9354,36.3856,-188.0112,0
);

--updated 17-05-17
