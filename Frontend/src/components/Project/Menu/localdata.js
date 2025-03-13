
const actuadores =  [
    {'submenuItem': 'DC Motor G', 'submenuItems': null, 'action': 'dcmotorg'},
    {'submenuItem': 'Módulo A,', 'submenuItems': null, 'action': 'moduloa,'},
    {'submenuItem': 'DC Motor Y x2', 'submenuItems': null, 'action': 'dcmotoryx2'},
    {'submenuItem': 'Módulo B', 'submenuItems': null, 'action': 'modulob'},
    {'submenuItem': 'Stepper', 'submenuItems': null, 'action': 'stepper'},
    {'submenuItem': 'Módulo C', 'submenuItems': null, 'action': 'moduloc'},
    {'submenuItem': 'Módulo D', 'submenuItems': null, 'action': 'modulod'},
    {'submenuItem': 'Servomotor', 'submenuItems': null, 'action': 'servomotor'},
    {'submenuItem': 'Módulo E', 'submenuItems': null, 'action': 'moduloe'},
    {'submenuItem': 'Brushless', 'submenuItems': null, 'action': 'brushless'},
    {'submenuItem': 'Módulo F', 'submenuItems': null, 'action': 'modulof'},
    {'submenuItem': 'Solenoide', 'submenuItems': null, 'action': 'solenoide'},
    {'submenuItem': 'Módulo G', 'submenuItems': null, 'action': 'modulog'},
]

const luces = [
    {'submenuItem': 'Luces x4 RGB', 'submenuItems':null, 'action': 'lucesx4rgb'},
    {'submenuItem': 'Módulo H', 'submenuItems':null, 'action': 'moduloh'},
    {'submenuItem': 'Cubo Led x27', 'submenuItems':null, 'action': 'cuboledx27'},
    {'submenuItem': 'Módulo I', 'submenuItems':null, 'action': 'moduloi'},
    {'submenuItem': 'Display 7 seg', 'submenuItems':null, 'action': 'display7seg'},
    {'submenuItem': 'Módulo J', 'submenuItems':null, 'action': 'moduloj'},
    {'submenuItem': 'Pantalla Gráfica', 'submenuItems':null, 'action': 'pantallagráfica'},
    {'submenuItem': 'Módulo K', 'submenuItems':null, 'action': 'modulok'},
]

const sensores = [
    {'submenuItem': 'Sensor de luminosidad', 'submenuItems':null, 'action': 'sensordeluminosidad'} ,
    {'submenuItem': 'Módulo L', 'submenuItems':null, 'action': 'modulol'} ,
    {'submenuItem': 'Sensor de temperatura y humedad', 'submenuItems':null, 'action': 'sensordetemperaturayhumedad'} ,
    {'submenuItem': 'Módulo M', 'submenuItems':null, 'action': 'modulom'} ,
    {'submenuItem': 'Sensor de efecto hall', 'submenuItems':null, 'action': 'sensordeefectohall'} ,
    {'submenuItem': 'Módulo N', 'submenuItems':null, 'action': 'modulon'} ,
    {'submenuItem': 'Sensor de proximidad', 'submenuItems':null, 'action': 'sensordeproximidad'} ,
    {'submenuItem': 'Módulo O', 'submenuItems':null, 'action': 'moduloo'} ,
]

const programables = [
    {'submenuItem': 'ESP32', 'submenuItems':null, 'action': 'esp32'} ,
]

const menu = [
    {
        'menuItem':'Archivo',
        'submenuItems':[
            {'submenuItem':'Restaurar',
             'submenuItems': null,
             'action':'restore'
            },
            {'submenuItem':'Guardar',
             'submenuItems': null,
             'action':'save'
            },
            {'submenuItem':'Compartir',
            'submenuItems': null,
            'action':'share'
           },
           {'submenuItem':'Salir',
           'submenuItems': null,
           'action':'exit'
          },
        ]
    },
    {
        'menuItem':'Editar',
        'submenuItems':[
            {'submenuItem':'Deshacer',
            'submenuItems': null,
            'action':'undo'
           },
           {'submenuItem':'Rehacer',
            'submenuItems': null,
            'action':'redo'
           },
           {'submenuItem':'Buscar',
            'submenuItems': null,
            'action':'search'
           },
           {'submenuItem':'Remplazar',
            'submenuItems': null,
            'action':'Replace'
           },
           {'submenuItem':'...otros',
            'submenuItems': null,
            'action':'others'
           },
           {'submenuItem':'...otros2',
           'submenuItems': null,
           'action':'others'
          },
        ]
    },
    {
        'menuItem':'Insertar',
        'submenuItems':[
            {'submenuItem':'Actuadores',
            'submenuItems': actuadores,
            'action': null
           },
           {'submenuItem':'Luces',
            'submenuItems': luces,
            'action': null
           },
           {'submenuItem':'Sensores',
            'submenuItems': sensores,
            'action': null
           },
           {'submenuItem':'Programables',
            'submenuItems': programables,
            'action': null
           },
        ]
    },
    {
        'menuItem':'Configuracion',
        'submenuItems':[
            {'submenuItem':'Configurar maqueta',
             'submenuItems': null,
             'action':'configure'
            },
            {'submenuItem':'Resetear maqueta',
            'submenuItems': null,
            'action':'reset'
           },
           {'submenuItem':'Testear maqueta',
           'submenuItems': null,
           'action':'test'
          },
        ]
    },
]

const menu2 = [
    {
        'menuItem':'Conectar',
        'submenuItems':null,
        'action': 'conect',
    },
    {
        'menuItem':'Cargar',
        'submenuItems':null,
        'action': 'load',
    },
    {
        'menuItem':'Transformar',
        'submenuItems':null,
        'action': 'transform',
    },
    {
        'menuItem':'Ejecutar',
        'submenuItems':null,
        'action': 'execute',
    },
]

export {actuadores,luces,sensores,programables,menu,menu2}