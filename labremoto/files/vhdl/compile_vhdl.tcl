#Este archivo se utiliza en la action VhdlToBit para compilar de vhdl a bit usando los constrains

set project_name "labo_remoto"; #Creando el proyecto de vivado
set project_dir [file dirname [info script]];  #Estableciendo la ruta del proyecto


# Obtén las rutas de los archivos desde los argumentos al llamar el comando
set part [lindex $argv 0]
set vhdl_file [lindex $argv 1]  ; # Primer argumento: archivo VHDL
set xdc_file [lindex $argv 2]   ; # Segundo argumento: archivo XDC (Constrains)

puts "Device using: $part"; #Imprimiendo la tarjeta empleada

create_project $project_name $project_dir -part $part; #Iniciando proyecto

#Agregar los archivos al proyecto
add_files $vhdl_file
add_files $xdc_file

# Ejecutar la síntesis
launch_runs synth_1 -jobs 4

# Ejecutar la implementación
launch_runs impl_1 -jobs 4

# Generar el archivo bitstream
launch_runs impl_1 -to_step write_bitstream

# Guardar el proyecto
save_project_as $project_name"_final"