onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /mux_8x1/a
add wave -noupdate /mux_8x1/sel
add wave -noupdate /mux_8x1/s
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {600 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ps
update
WaveRestoreZoom {50 ps} {1050 ps}
view wave 
wave clipboard store
wave create -driver freeze -pattern counter -startvalue 000 -endvalue 111 -type Range -direction Up -period 50ps -step 1 -repeat forever -range 2 0 -starttime 0ps -endtime 1000ps sim:/mux_8x1/sel 
WaveExpandAll -1
WaveCollapseAll -1
wave clipboard restore
