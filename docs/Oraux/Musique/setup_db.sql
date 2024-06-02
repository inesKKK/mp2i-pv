PRAGMA foreign_keys = ON;

CREATE TABLE artistes (id INTEGER PRIMARY KEY AUTOINCREMENT, nom TEXT UNIQUE, debut INTEGER, fin INTEGER);
CREATE TABLE albums (id INTEGER PRIMARY KEY AUTOINCREMENT, nom TEXT, id_artiste INTEGER, annee INTEGER, note REAL, FOREIGN KEY (id_artiste) REFERENCES artistes(id));

--INSERT INTO artistes (nom, debut, fin) VALUES ();
--INSERT INTO albums (nom, id_artiste, annee, note) VALUES ();

INSERT INTO artistes (nom, debut, fin) VALUES ('Nirvana', 1987, 1994);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Nevermind', 1, 1991, 7.8);

INSERT INTO artistes (nom, debut, fin) VALUES ('Pink Floyd', 1965, 1994);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('The Dark Side of the Moon', 2, 1973, 8.3);

INSERT INTO artistes (nom, debut, fin) VALUES ('Daft Punk', 1993, 2021);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Random Access Memories', 3, 2013, 6.7);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Discovery', 3, 2001, 7.8);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('The Wall', 2, 1979, 7.9);

INSERT INTO artistes (nom, debut, fin) VALUES ('The Doors', 1965, 1973);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('The Doors', 4, 1967, 8.3);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Wish You Were Here', 2, 1975, 8.5);

INSERT INTO artistes (nom, debut) VALUES ('Gorillaz', 1998);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Demon Days', 5, 2005, 7.5);

INSERT INTO artistes (nom, debut, fin) VALUES ('Michael Jackson', 1964, 2009);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Thriller', 6, 1982, 7.8);

INSERT INTO artistes (nom, debut, fin) VALUES ('The Beatles', 1960, 1970);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Abbey Road', 7, 1969, 8.1);

INSERT INTO artistes (nom, debut, fin) VALUES ('Radiohead', 1985, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('OK Computer', 8, 1997, 8.1);

INSERT INTO artistes (nom, debut, fin) VALUES ('Stromae', 2000, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Racine carrée', 9, 2013, 6.3);

INSERT INTO artistes (nom, debut, fin) VALUES ('IAM', 1989, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('L école du micro d argent', 10, 1997, 8.0);

INSERT INTO artistes (nom, debut, fin) VALUES ('Rage Against the Machine', 1991, 2000);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Rage Against the Machine', 11, 1992, 7.9);

INSERT INTO artistes (nom, debut, fin) VALUES ('The Clash', 1976, 1986);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('London Calling (Remastered)', 12, 1979, 7.9);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Homework', 3, 1997, 7.4);

INSERT INTO artistes (nom, debut, fin) VALUES ('Led Zeppelin', 1968, 1980);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('[Led Zeppelin IV]', 13, 1971, 8.3);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Sgt. Peppers Lonely Hearts Club Band', 7, 1967, 8.1);

INSERT INTO artistes (nom, debut, fin) VALUES ('Muse', 1994, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Origin of Symmetry', 14, 2001, 7.3);

INSERT INTO artistes (nom, debut, fin) VALUES ('Red Hot Chili Peppers', 1982, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Californication', 15, 1999, 7.1);

INSERT INTO artistes (nom, debut, fin) VALUES ('Eminem', 1988, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('The Eminem Show', 16, 2002, 7.6);

INSERT INTO artistes (nom, debut, fin) VALUES ('Orelsan', 2002, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Le Chant des Sirènes', 17, 2011, 6.5);

INSERT INTO artistes (nom, debut, fin) VALUES ('System of a down', 1994, 2006);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Toxicity', 18, 2001, 7.3);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Led Zeppelin', 13, 1969, 8.2);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('La Fête est finie', 17, 2017, 6.7);

INSERT INTO artistes (nom, debut, fin) VALUES ('David Bowie', 1962, 2016);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('The Rise and Fall of Ziggy Stardust and the Spiders From Mars', 19, 1972, 8.4);

INSERT INTO artistes (nom, debut, fin) VALUES ('Massive Attack', 1988, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Mezzanine', 20, 1998, 8.0);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Gorillaz', 5, 2001, 7.4);

INSERT INTO artistes (nom, debut, fin) VALUES ('Lana Del Rey', 2005, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Born to Die', 21, 2012, 6.7);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('The Beatles', 7, 1968, 8.1);

INSERT INTO artistes (nom, debut, fin) VALUES ('Louise Attaque', 1997, 2001);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Louise Attaque', 22, 1997, 6.8);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Absolution', 14, 2003, 7.0);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('MTV Unplugged in New York (Live)', 1, 1994, 8.1);

INSERT INTO artistes (nom, debut, fin) VALUES ('Woodkid', 2006, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('The Golden Age', 23, 2013, 6.9);

INSERT INTO artistes (nom, debut, fin) VALUES ('AC/DC', 1973, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Back in Black', 24, 1980, 7.5);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Animals', 2, 1977, 8.0);

INSERT INTO artistes (nom, debut, fin) VALUES ('Joy Division', 1976, 1980);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Unknown Pleasures', 25, 1979, 8.0);

INSERT INTO artistes (nom, debut, fin) VALUES ('Neil Young', 1963, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Harvest', 26, 1972, 8.2);

INSERT INTO artistes (nom, debut, fin) VALUES ('alt-J', 2007, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('An Awesome Wave', 27, 2012, 7.5);

INSERT INTO artistes (nom, debut, fin) VALUES ('Serge Gainsbourg', 1957, 1991);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Histoire de Melody Nelson', 28, 1971, 8.2);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Kid A', 8, 2000, 7.9);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('In Utero', 1, 1993, 7.6);

INSERT INTO artistes (nom, debut, fin) VALUES ('King Crimson', 1968, 1974);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('In the Court of the Crimson King', 29, 1969, 8.4);

INSERT INTO artistes (nom, debut, fin) VALUES ('Yann Tiersen', 1995, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Le Fabuleux Destin d Amélie Poulain', 30, 2001, 7.5);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('The Resistance', 14, 2009, 6.0);

INSERT INTO artistes (nom, debut, fin) VALUES ('Miles Davis', 1944, 1975);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Kind of Blue', 31, 1959, 8.5);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Highway to Hell', 24, 1979, 7.5);

INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('The Marshall Mathers LP', 16, 2000, 7.9);

INSERT INTO artistes (nom, debut, fin) VALUES ('Arctic Monkeys', 2002, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Whatever People Say I Am, That s What I m Not', 32, 2006, 7.5);

INSERT INTO artistes (nom, debut, fin) VALUES ('Metallica', 1981, NULL);
INSERT INTO albums (nom, id_artiste, annee, note) VALUES ('Master of Puppets', 33, 1986, 7.6);
