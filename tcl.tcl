# save_cropped.tcl
gtkwave::loadFile "original.fst"
gtkwave::setStartTime "10ns"  ;# 起始时间
gtkwave::setEndTime "20ns"    ;# 结束时间
gtkwave::saveFile "cropped.fst" ;# 自动保留格式
