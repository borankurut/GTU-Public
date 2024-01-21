transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/ors {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/ors/or_4.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/ors {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/ors/or_3.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/ands {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/ands/and_32_bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/ands {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/ands/and_4.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/muxes {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/muxes/mux2x1_32bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/muxes {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/muxes/mux2x1_4bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/adders {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/adders/fulladder_gm.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/adders {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/adders/cla_gen_4.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/adders {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/adders/cl_adder_4.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/adders {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/adders/adder_16.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/ands {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/ands/and_4bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/muxes {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/muxes/mux8x1_32bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/ors {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/ors/or_32_bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/nors {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/nors/nor_32_bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/xors {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/xors/xor_32_bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/adders {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/adders/adder_32.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/subtractors {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/subtractors/subtractor_32.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/nots {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/nots/not_32_bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/lessthan {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/lessthan/lessthan_32.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/muxes {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/muxes/mux_2x1.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/mod_related {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/mod_related/mod_cu.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/mod_related {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/mod_related/mod_dp.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/mod_related {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/mod_related/mod.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2 {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/alu.v}

vlog -vlog01compat -work work +incdir+C:/Users/boran/Homeworks-and-Solutions/cse331/Project2 {C:/Users/boran/Homeworks-and-Solutions/cse331/Project2/my_testbench.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cyclonev_ver -L cyclonev_hssi_ver -L cyclonev_pcie_hip_ver -L rtl_work -L work -voptargs="+acc"  my_testbench

add wave *
view structure
view signals
run -all
