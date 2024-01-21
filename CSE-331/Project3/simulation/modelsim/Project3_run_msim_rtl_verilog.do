transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/boran/GTU-Private/CSE-331/Project3/ControlRelated {C:/Users/boran/GTU-Private/CSE-331/Project3/ControlRelated/function_code_to_alu_ctr.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/GTU-Private/CSE-331/Project3/ControlRelated {C:/Users/boran/GTU-Private/CSE-331/Project3/ControlRelated/alu_control.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/GTU-Private/CSE-331/Project3/AluRelated/muxes {C:/Users/boran/GTU-Private/CSE-331/Project3/AluRelated/muxes/mux2x1_4bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/GTU-Private/CSE-331/Project3/AluRelated/ands {C:/Users/boran/GTU-Private/CSE-331/Project3/AluRelated/ands/and_4bit.v}
vlog -vlog01compat -work work +incdir+C:/Users/boran/GTU-Private/CSE-331/Project3/AluRelated/ands {C:/Users/boran/GTU-Private/CSE-331/Project3/AluRelated/ands/and_4.v}

vlog -vlog01compat -work work +incdir+C:/Users/boran/GTU-Private/CSE-331/Project3/ControlRelated {C:/Users/boran/GTU-Private/CSE-331/Project3/ControlRelated/control_tb.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cyclonev_ver -L cyclonev_hssi_ver -L cyclonev_pcie_hip_ver -L rtl_work -L work -voptargs="+acc"  control_tb

add wave *
view structure
view signals
run -all
