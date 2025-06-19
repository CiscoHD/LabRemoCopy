import ZedBoard from "@/assets/media/Nodes/Programables/Zedboard.png";

const defaultHandleSize = {width: 3, height: 3}; 
const firstLeft = "12%";
const secondLeft = "14.8%";

export default {
  name: "ZedBoard",
  url: ZedBoard,
  type: "programable",
  size: { x: "250px", y: "250px" },
  handles: [
    {
      id: "JE4",
      type: "source",
      position: "left",
      style: { left: firstLeft, top: "45%",   },
    },
    {
      id: "JE3",
      type: "source",
      position: "left",
      style: { left: firstLeft, top: "47.2%",   },
    },
    {
      id: "JE2",
      type: "source",
      position: "left",
      style: { left: firstLeft, top: "49.5%",   },
    },
    {
      id: "JE1",
      type: "source",
      position: "left",
      style: { left: firstLeft, top: "51.5%",   },
    },
    {
      id: "JE4_1",
      type: "source",
      position: "left",
      style: { left: secondLeft, top: "45%",   },
    },
    {
      id: "JE3_1",
      type: "source",
      position: "left",
      style: { left: secondLeft, top: "47.2%",   },
    },
    {
      id: "JE2_1",
      type: "source",
      position: "left",
      style: { left: secondLeft, top: "49.5%",   },
    },
    {
      id: "JE1_1",
      type: "source",
      position: "left",
      style: { left: secondLeft, top: "51.5%",   },
    },
    {
      id: "JD4",
      type: "source",
      position: "left",
      style: { left: firstLeft, top: "57%",   },
    },
    {
      id: "JD3",
      type: "source",
      position: "left",
      style: { left: firstLeft, top: "59.3%",   },
    },
    {
      id: "JD2",
      type: "source",
      position: "left",
      style: { left: firstLeft, top: "61.5%",   },
    },
    {
      id: "JD1",
      type: "source",
      position: "left",
      style: { left: firstLeft, top: "63.5%",   },
    },
    {
      id: "JD4_1",
      type: "source",
      position: "left",
      style: { left: secondLeft, top: "57%",   },
    },
    {
      id: "JD3_1",
      type: "source",
      position: "left",
      style: { left: secondLeft, top: "59.3%",   },
    },
    {
      id: "JD2_1",
      type: "source",
      position: "left",
      style: { left: secondLeft, top: "61.5%",   },
    },
    {
      id: "JD1_1",
      type: "source",
      position: "left",
      style: { left: secondLeft, top: "63.5%",   },
    },
    {
      id: "JC4",
      type: "source",
      position: "left",
      style: { left: firstLeft, top: "70%",   },
    },
    {
      id: "JC3",
      type: "source",
      position: "left",
      style: { left: firstLeft, top: "72%",   },
    },
    {
      id: "JC2",
      type: "source",
      position: "left",
      style: { left: firstLeft, top: "74%",   },
    },
    {
      id: "JC1",
      type: "source",
      position: "left",
      style: { left: firstLeft, top: "76%",   },
    },
    {
      id: "JC4_1",
      type: "source",
      position: "left",
      style: { left: secondLeft, top: "70%",   },
    },
    {
      id: "JC3_1",
      type: "source",
      position: "left",
      style: { left: secondLeft, top: "72%",   },
    },
    {
      id: "JC2_1",
      type: "source",
      position: "left",
      style: { left: secondLeft, top: "74%",   },
    },
    {
      id: "JC1_1",
      type: "source",
      position: "left",
      style: { left: secondLeft, top: "76%",   },
    },
  ].map((handle) => ({
    ...handle,
    style: {
      ...defaultHandleSize,
      ...handle.style,
    },
  })),
};