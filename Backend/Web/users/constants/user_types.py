class UserTypeConfig:
    """Configuración centralizada para tipos de usuario"""
    _TYPES = {
        'STUDENT': ('EST', 'Estudiante'),
        'TEACHER': ('PRO', 'Profesor'),
        'STAFF': ('STA', 'Staff'),
        'ADMIN': ('ADM', 'Administrador'),
    }
    
    # Constantes
    STUDENT, TEACHER, STAFF, ADMIN = (t[0] for t in _TYPES.values())
    
    # Estructuras derivadas
    TYPE_CHOICES = tuple((code, name) for code, name in _TYPES.values())
    GROUP_NAMES = {code: name for code, name in _TYPES.values()}
    
    @classmethod
    def get_display_name(cls, code):
        return dict(cls.TYPE_CHOICES).get(code, '')
