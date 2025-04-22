#import "@preview/cetz:0.3.2": draw
#import "src/lib.typ": *

#set page(width: auto, height: auto, margin: .5cm)

#circuit({
  element.block(x: 0, y: 0, w: 8, h: 4, id: "dp", fill: util.colors.pink, name: "Datapath", ports: (north: (
    (id: "clk", clock: true, small: true),
    (id: "Zero"),
    (id: "Regsrc"),
    (id: "PCSrc"),
    (id: "ResultSrc"),
    (id: "ALUControl"),
    (id: "ImmSrc"),
    (id: "RegWrite"),
    (id: "dummy"),
  ), east: (
    (id: "PC", name: "PC"),
    (id: "Instr", name: "Instr"),
    (id: "ALUResult", name: "ALUResult"),
    (id: "dummy"),
    (id: "WriteData", name: "WriteData"),
    (id: "ReadData", name: "ReadData"),
  ), west: ((id: "rst"),)), ports-margins: (north: (0%, 0%), west: (0%, 70%)))
})

