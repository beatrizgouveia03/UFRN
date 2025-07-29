onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /mux_16x1/a
add wave -noupdate /mux_16x1/sel
add wave -noupdate /mux_16x1/s0
add wave -noupdate /mux_16x1/s1
add wave -noupdate /mux_16x1/s2
add wave -noupdate /mux_16x1/s3
add wave -noupdate /mux_16x1/sel0
add wave -noupdate /mux_16x1/sel1
add wave -noupdate /mux_16x1/s
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {998 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 40
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
WaveRestoreZoom {0 ps} {1054 ps}
view wave 
wave clipboard store
wave create -driver freeze -pattern counter -startvalue 0000 -endvalue 1111 -type Range -direction Up -period 50ps -step 1 -repeat forever -range 3 0 -starttime 0ps -endtime 1000ps sim:/mux_16x1/sel 
WaveExpandAll -1
WaveCollapseAll -1
wave clipboard restore
