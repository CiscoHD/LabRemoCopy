CREATE DATABASE Labremoto;
USE Labremoto;



-- CATALOGOS
CREATE TABLE IF NOT EXISTS PRACTICES(
	id_practica integer primary key,
    name varchar(255),
    is_available boolean,
    create_date timestamp,
    serialized_set varchar(255)
);

CREATE TABLE IF NOT EXISTS COMPONENTS(

);


CREATE TABLE IF NOT EXISTS TOPICS(
	id_topic integer primary key,
    topic varchar(255),
    token varchar(255),
    date_create timestamp,
    satatus boolean
);

CREATE TABLE IF NOT EXISTS USERTYPES(
	id_user_type integer primary key,
	user_type varchar(255),
    description varchar(255)
);


CREATE TABLE IF NOT EXISTS USERS(
	id_user integer primary key,
    user_name varchar(255),
    email varchar(255),
    is_available boolean,
    id_user_type integer,
     foreign key (id_user_type) references USERSTYPE(id_user_type)
);

