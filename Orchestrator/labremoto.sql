CREATE DATABASE IF NOT EXISTS labremoto;
USE labremoto;

-- TABLAS CATALOGOS

CREATE TABLE IF NOT EXISTS CONTRATOS (
	IdContrato integer primary key,
    NameContrato varchar(255),
    DescContrato varchar(255)
);


CREATE TABLE IF NOT EXISTS OPERACIONES (
	IdOperacion integer primary key,
    NameOperacion varchar(255),
    DescOperacion varchar(255)
);

CREATE TABLE IF NOT EXISTS TRANSACCIONES (
	IdTransaccion integer primary key,
    NameTransaccion varchar(255),
    DescTransaccion varchar(255)
);


CREATE TABLE IF NOT EXISTS REVISARCONTRATOOPERACION (
    IdContrato integer,
    FOREIGN KEY (IdContrato) REFERENCES CONTRATOS(IdContrato),
    IdOperacion integer,
    FOREIGN KEY (IdOperacion) REFERENCES OPERACIONES(IdOperacion)
);

CREATE TABLE IF NOT EXISTS REVISARCONTRATOTRANSACCION (
    IdContrato integer,
    FOREIGN KEY (IdContrato) REFERENCES CONTRATOS(IdContrato),
    IdTransaccion integer,
    FOREIGN KEY (IdTransaccion) REFERENCES TRANSACCIONES(IdTransaccion)
);

CREATE TABLE IF NOT EXISTS TOPICS(
	IdTopic integer primary key,
    NameTopic varchar(255),
    Token varchar(255),
    DateUpdate timestamp,
    Estado boolean
);

CREATE TABLE IF NOT EXISTS NODES (
	IdNode integer primary key,
    NameClase varchar(255),
    NameScript varchar(255)
);

CREATE TABLE IF NOT EXISTS MENSAJES (
	IdMensaje integer primary key,
    NameMensaje varchar(255),
    DescrMensaje varchar(255),
    VarMensaje varchar(255)
);


CREATE TABLE IF NOT EXISTS ACCIONES (
	IdAccion integer primary key,
    NameAccion varchar(255),
    DescrAccion varchar(255),
    InputAccion varchar(255),
    OutputAcccion varchar(255),
    FeedbackAccion varchar(255)
);

CREATE TABLE IF NOT EXISTS SERVICIOS (
	IdServicio integer primary key,
    NameServicio varchar(255),
    DescrServicio varchar(255),
    InputServicio varchar(255),
    OutputServicio varchar(255)
);

CREATE TABLE IF NOT EXISTS COMPONENTES (
	IdComponente integer primary key,
    IdNode integer,
    TipoComponente varchar(255),
    IdTopic integer,
    IdMensaje integer,
    FOREIGN KEY (IdNode) REFERENCES NODES(IdNode),
    FOREIGN KEY (IdTopic) REFERENCES TOPICS(IdTopic),
    FOREIGN KEY (IdMensaje) REFERENCES MENSAJES(IdMensaje)
);


CREATE TABLE IF NOT EXISTS AUDITOROPERACIONES (
	IdResgistroOperacion integer,
    IdOperacion integer,
    EstatusOperacion integer,
    FechaOperacion timestamp,
    IdComponente integer,
    LogOperacion varchar(255),
	FOREIGN KEY (IdOperacion) REFERENCES OPERACIONES(IdOperacion),
   	FOREIGN KEY (IdComponente) REFERENCES COMPONENTES(IdComponente)
);


CREATE TABLE IF NOT EXISTS PUTS (
	IdPuts integer primary key,
    TipoPuts varchar(255)
);

CREATE TABLE IF NOT EXISTS COMPONENTESELECTRONICOS (
	IdComponente integer primary key,
    TipoPuts varchar(255),
    NameComponente varchar(255),
    TipoComponente Varchar(255),
    Especificaciones Varchar(255)
);

CREATE TABLE IF NOT EXISTS CONEXIONES (
	IdPuts integer,
    IdComponente integer,
    FOREIGN KEY (IdPuts) REFERENCES PUTS(IdPuts),
    FOREIGN KEY (IdComponente) REFERENCES COMPONENTESELECTRONICOS(IdComponente)
    );

CREATE TABLE IF NOT EXISTS MAQUETAS(
IdMaqueta integer primary key,
Disponibilidad boolean
);

CREATE TABLE IF NOT EXISTS DESTINAR(
	IdMaqueta integer,
    IdComponente integer,
    FOREIGN KEY (IdMaqueta) REFERENCES MAQUETAS(IdMaqueta),
    FOREIGN KEY (IdComponente) REFERENCES COMPONENTESELECTRONICOS(IdComponente)
    );
    

CREATE TABLE IF NOT EXISTS TIPOUSUARIOS (
	IdTipoUsuario integer primary key,
    IsAvailable boolean,
    TipoUsuario varchar(255)
);
    

CREATE TABLE IF NOT EXISTS USUARIOS (
	IdUsuario integer primary key,
	IsAvailable boolean,
	IdTipoUsuario integer,
    UserName varchar(255) UNIQUE,
    email varchar(255),
    Credits integer,
    FOREIGN KEY (IdTipoUsuario) REFERENCES TIPOUSUARIOS(IdTipoUsuario)
);
    
CREATE TABLE IF NOT EXISTS TIPOARCHIVOS (
	IdTipoArchivo integer primary key,
    TipoArchivo varchar(255),
    DescArchivo varchar(255)
);

CREATE TABLE IF NOT EXISTS CURSOS(
IdCurso integer primary key,
NameCurso varchar(255)
);


CREATE TABLE IF NOT EXISTS MATERIAS(
IdMateria integer primary key,
NameMateria varchar(255)
);

CREATE TABLE IF NOT EXISTS PRACTICAS (
	IdPractica integer primary key,
    NamePractica varchar(255),
    IsAvalable boolean,
    IdMateria integer,
    FOREIGN KEY (IdMateria) REFERENCES MATERIAS(IdMateria)
);


CREATE TABLE IF NOT EXISTS ARCHIVOS (
	IdArchivo integer primary key,
    IdTipoArchivo integer,
    PathArchivo varchar(255),
    NameArchivo varchar(255),
    IdUsuario integer,
    IdPractica integer,
    FechaCarga timestamp,
    FOREIGN KEY (IdTipoArchivo) REFERENCES TIPOARCHIVOS(IdTipoArchivo),
    FOREIGN KEY (IdUsuario) REFERENCES USUARIOS(IdUsuario),
    FOREIGN KEY (IdPractica) REFERENCES PRACTICAS(IdPractica)
);
    

CREATE TABLE IF NOT EXISTS AUDITORSESIONES(
	IdAsignacion integer primary key,
    FechaAsignacion timestamp,
    IdUsuario integer,
    IdMaqueta integer,
    TiempoInicio timestamp,
    TiempoFinal timestamp,
    FOREIGN KEY (IdMaqueta) REFERENCES MAQUETAS(IdMaqueta),
    FOREIGN KEY (IdUsuario) REFERENCES USUARIOS(IdUsuario)
);

CREATE TABLE IF NOT EXISTS AUDITORTRANSACCIONES (
	IdResgistroTransaccion integer primary key,
    IdTransaccion integer,
    EstatusTransaccion integer,
    FechaTransaccion timestamp,
    IdComponente integer,
    IdSesion integer,
    LogTransaccion varchar(255),
	FOREIGN KEY (IdTransaccion) REFERENCES TRANSACCIONES(IdTransaccion),
   	FOREIGN KEY (IdComponente) REFERENCES COMPONENTES(IdComponente),
   	FOREIGN KEY (IdSesion) REFERENCES AUDITORSESIONES(IdAsignacion)
);

CREATE TABLE IF NOT EXISTS PAISES(
IdPais integer primary key,
Codi varchar(255),
Nombre varchar(255),
IsAvailable boolean
);

CREATE TABLE IF NOT EXISTS INSTITUCIONES(
	IdInstitucion integer primary key,
    NameInstitucion varchar(255),
    Siglas varchar(255),
    IsAvailable boolean,
    IdPais integer,
    foreign key (IdPais) REFERENCES PAISES(IdPais)
);

CREATE TABLE IF NOT EXISTS FACULTADES(
IdFacultad integer primary key, 
NameFaultad varchar(255),
IsAvailable boolean
);

CREATE TABLE IF NOT EXISTS CARRERAS(
 IdCarrera integer primary key, 
NameCarrera varchar(255),
IsAvailable boolean
);

CREATE TABLE IF NOT EXISTS PROFESORES(
IdProfesor integer primary key,
Nombres varchar(255),
ApellidoMaterno varchar(255),
ApellidoPaterno varchar(255),
IdFacultad integer,
IdInstitucion integer,
foreign key (IdFacultad) REFERENCES FACULTADES(IdFacultad),
foreign key (IdInstitucion) REFERENCES INSTITUCIONES(IdInstitucion)
);

CREATE TABLE IF NOT EXISTS ALUMNOS(
IdAlumno integer primary key,
Nombres varchar(255),
ApellidoMaterno varchar(255),
ApellidoPaterno varchar(255),
IdFacultad integer,
IdInstitucion integer,
IdCarrera integer,
foreign key (IdFacultad) REFERENCES FACULTADES(IdFacultad),
foreign key (IdInstitucion) REFERENCES INSTITUCIONES(IdInstitucion),
foreign key (IdCarrera) REFERENCES CARRERAS(IdCarrera)
);


CREATE TABLE IF NOT EXISTS ENCARGADOSCURSO (
IdCurso integer ,
IdProfesor integer,
Periodo varchar(255),
foreign key (IdCurso) REFERENCES CURSOS(IdCurso),
foreign key (IdProfesor) REFERENCES PROFESORES(IdProfesor)
);

CREATE TABLE IF NOT EXISTS TOMARCLASE (
IdCurso integer ,
IdAlumno integer,
Periodo varchar(255),
foreign key (IdCurso) REFERENCES CURSOS(IdCurso),
foreign key (IdAlumno) REFERENCES ALUMNOS(IdAlumno)
);

