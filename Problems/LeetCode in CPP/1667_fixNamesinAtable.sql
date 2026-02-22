-- create
CREATE TABLE Users (
  user_id INTEGER PRIMARY KEY,
  name VARCHAR NOT NULL
);

-- insert
INSERT INTO Users VALUES (0001, 'aLice');
INSERT INTO Users VALUES (0002, 'bOB');

-- fetch (Leetcode submission)
SELECT user_id, 
  CONCAT(UPPER(SUBSTRING(name FROM 1 FOR 1)), LOWER(SUBSTRING(name FROM 2))) AS name
FROM Users
ORDER BY user_id;

