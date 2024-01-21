transcript on
if {[file exists gate_work]} {
	vdel -lib gate_work -all
}
vlib gate_work
vmap work gate_work

vlog -vlog01compat -work work +incdir+. {Project3.vo}

vlog -vlog01compat -work work +incdir+C:/Users/boran/GTU-Private/CSE-331/Project3/AluRelated {C:/Users/boran/GTU-Private/CSE-331/Project3/AluRelated/alu_testbench.v}

vsim -t 1ps -L altera_ver -L altera_lnsim_ver -L cyclonev_ver -L lpm_ver -L sgate_ver -L cyclonev_hssi_ver -L altera_mf_ver -L cyclonev_pcie_hip_ver -L gate_work -L work -voptargs="+acc"  alu_testbench

add wave *
view structure
view signals
run -all
