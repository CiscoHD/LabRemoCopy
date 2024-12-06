# constraints.xdc
# Asignaciones de pines para la FPGA

# Asignación del pin para la señal de reloj (clk)
set_property PACKAGE_PIN P15 [get_ports {clk}]
set_property IOSTANDARD LVCMOS33 [get_ports {clk}]

# Asignación del pin para la señal de reset
set_property PACKAGE_PIN N17 [get_ports {reset}]
set_property IOSTANDARD LVCMOS33 [get_ports {reset}]

# Asignación de pines para la salida count (4 bits)
set_property PACKAGE_PIN T8 [get_ports {count[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {count[0]}]

set_property PACKAGE_PIN T7 [get_ports {count[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {count[1]}]

set_property PACKAGE_PIN T6 [get_ports {count[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {count[2]}]

set_property PACKAGE_PIN T5 [get_ports {count[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {count[3]}]
