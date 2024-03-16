#!/bin/bash
psql -U postgres -c "CREATE DATABASE labremdb;"
psql -U postgres -c "CREATE USER trabajo WITH PASSWORD '************';"
psql -U postgres -c "CREATE SCHEMA myschema AUTHORIZATION trabajo;"
psql -U postgres -c "ALTER ROLE trabajo SET client_encoding TO 'utf8';"
psql -U postgres -c "ALTER ROLE trabajo SET default_transaction_isolation TO 'read committed';"
psql -U postgres -c "ALTER ROLE trabajo SET timezone TO 'UTC';"
