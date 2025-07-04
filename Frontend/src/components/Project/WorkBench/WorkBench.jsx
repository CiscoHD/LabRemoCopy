import { useCallback, useRef, useState, useEffect, useContext } from "react";

import {
  Controls,
  Background,
  ReactFlow,
  useNodesState,
  useEdgesState,
  addEdge,
} from "@xyflow/react";
import "@xyflow/react/dist/style.css";

import { MenuContext } from "@/context/MenuContext";

import Stock from "./NodesStock/Stock";
import RenderNodes from "./RenderNodes";

import ImageNode from "./ImageNode";
import EdgeStyle from "./EdgeStyle";
import DropMenu from "../Menu/DropMenu";

import NodeContextMenu from "./NodeContextMenu";
import EdgeContextMenu from "./EdgeContextMenu";

const nodeTypes = { imageNode: ImageNode };
const edgeTypes = { edgeStyle: EdgeStyle };

const WorkBench = () => {
  const ref = useRef(null);
  const [nodes, setNodes, onNodesChange] = useNodesState([]);
  const [edges, setEdges, onEdgesChange] = useEdgesState([]);
  const [selectedEdge, setSelectedEdge] = useState(null);
  const [nodeMenu, setNodeMenu] = useState(null);
  const [edgeMenu, setEdgeMenu] = useState(null);

  const [rfInsatnce, setRfInstance] = useState(null); // Próximamente lo usaremos para poder hacer el guardado de la sesión

  const [sessionConnections, setSessionConnections] = useState([]); // Almacenaremos las conexiones para enviarlas al back

  const { boardChoosen, reactFlowInstance } = useContext(MenuContext);

  // Función para actualizar la rotación de un nodo
  const handleRotationChange = useCallback((nodeId, newRotation) => {
    setNodes((nodes) =>
      nodes.map((node) => {
        if (node.id === nodeId) {
          return {
            ...node,
            data: {
              ...node.data,
              rotation: newRotation,
            },
          };
        }
        return node;
      })
    );
  }, [setNodes]);

  // Función para guardar el último programable seleccionado
  const saveLastProgramable = useCallback((boardName) => {
    try {
      localStorage.setItem('lastProgramable', boardName);
    } catch (error) {
      console.error('Error saving last programable:', error);
    }
  }, []);

  // Función para cargar el último programable seleccionado
  const loadLastProgramable = useCallback(() => {
    try {
      return localStorage.getItem('lastProgramable');
    } catch (error) {
      console.error('Error loading last programable:', error);
    }
    return null;
  }, []);

  // Cargar o crear nodo programable al inicializar
  useEffect(() => {
    if (boardChoosen && nodes.length === 0) {
      // Guardar el programable actual
      saveLastProgramable(boardChoosen);
      
      // Asegurarse de que el contenedor de React Flow está montado
      if (ref.current) {
        const reactFlowBounds = ref.current.getBoundingClientRect();

        // Calcular la posición central
        const position = {
          x: reactFlowBounds.width / 2,
          y: reactFlowBounds.height / 2,
        };

        //CREAMOS EL NODO DE LA TARJETA SELECCIONADA
        const initialBoard = Stock[boardChoosen];
        const newNode = RenderNodes({
          id: initialBoard.name,
          name: initialBoard.name,
          position: position,
          url: initialBoard.url,
          nodeType: initialBoard.type,
          size: initialBoard.size,
          handles: initialBoard.handles,
          onRotationChange: handleRotationChange,
        });
        
        setNodes([newNode]);
      }
    }
  }, [boardChoosen, saveLastProgramable, handleRotationChange, nodes.length, setNodes]);

  const onEdgeClick = useCallback(
    (event, edge) => {
      event.stopPropagation(); // Evita que otros eventos se disparen
      setSelectedEdge(edge.id); // Guarda el edge seleccionado

      // Removeremos el edge seleccionado para volverlo a renderizar y que se vea sobre los demás
      setEdges((eds) => {
        // Filtra para eliminar el edge seleccionado
        const remainingEdges = eds.filter((e) => e.id !== edge.id);

        // Cambia el tipo del edge seleccionado a 'edgeStyle' para la animación
        const updatedEdge = {
          ...edge,
          style: {
            ...edge.style, // Conservamos los estilos de la edge elegida
          },
          type: "edgeStyle",
        };

        // Re-agregar el edge al final de la lista para simular el cambio de zIndex
        return [...remainingEdges, updatedEdge];
      });
    },
    [setEdges],
  );

  const onPaneClick = useCallback(() => {
    setNodeMenu(null);
    // Deselecciona el edge al hacer clic fuera
    setSelectedEdge(null);
    setEdgeMenu(null);
    setEdges((eds) =>
      eds.map((e) => ({
        ...e,
        type: "smoothstep", // Mantén smoothstep para los demás
      })),
    );
  }, [selectedEdge, nodeMenu, edgeMenu, setEdges]);

  const onConnect = useCallback(
    (params) => {
      const randomColor = () => {
        let color = "#";
        const letters = "0123456789ABCDEF";
        for (let i = 0; i < 6; i++) {
          color += letters[Math.floor(Math.random() * 16)];
        }
        return color;
      };

      const isConnected = edges.some(
        (edge) =>
          edge.targetHandle === params.targetHandle &&
          params.source === edge.source &&
          params.target === edge.target,
      );

      const sourceEdgeType = nodes.find((nd) => nd.id === params.source);
      const targetEdgeType = nodes.find((nd) => nd.id === params.target);

      if (!isConnected) {
        const newEdge = {
          ...params,
          sourceType: sourceEdgeType.nodeType,
          targetType: targetEdgeType.nodeType,
          style: {
            stroke: randomColor(),
            strokeWidth: 3,
          },
          type: "smoothstep",
        };

        setEdges((eds) => addEdge(newEdge, eds));

        /**
         *  Cada identificador se separa por un "-"
         *  <ID del source>-<ID del handle usado por parte del source>-<ID del target>-<ID del hendle usado por parte del target>
         */
        setSessionConnections([
          ...sessionConnections,
          `${params.source}-${params.sourceHandle}-${params.targetHandle}-${params.target}`,
        ]);
      } else {
        // TODO: Añadir Modal
        return;
      }
    },
    [edges, nodes, setEdges, sessionConnections],
  );

  // Manejador para el drag de nodos existentes
  const onNodeDragStop = useCallback((event, node) => {
    // Asegurar que el nodo se quede en la posición exacta donde se soltó
    setNodes((nodes) =>
      nodes.map((n) => {
        if (n.id === node.id) {
          return {
            ...n,
            position: node.position,
          };
        }
        return n;
      })
    );
  }, [setNodes]);

  //TODO: Eliminar el drag y drop
  const onDragOver = useCallback((event) => {
    event.preventDefault();
    event.dataTransfer.dropEffect = "move";
  }, []);

  //Manejar el OnDrop
  const onDrop = useCallback(
    (event) => {
      event.preventDefault();
      const data = event.dataTransfer.getData("application/reactflow");
      const node = JSON.parse(data);

      // check if the dropped element is valid
      if (typeof node.name === "undefined" || !node.name) {
        return;
      }

      // Obtener el contenedor de React Flow
      const reactFlowBounds = ref.current.getBoundingClientRect();

      let position;

      // Si tenemos una instancia de React Flow, usar coordenadas transformadas
      if (rfInsatnce) {
        position = rfInsatnce.screenToFlowPosition({
          x: event.clientX,
          y: event.clientY,
        });
      } else {
        // Fallback: calcular coordenadas relativas al contenedor
        position = {
          x: event.clientX - reactFlowBounds.left,
          y: event.clientY - reactFlowBounds.top,
        };
      }

      const newNode = RenderNodes({
        id: `${node.name}_${+new Date()}`,
        name: node.name,
        position: position,
        url: node.url,
        nodeType: node.type,
        size: node.size,
        handles: node.handles,
        onRotationChange: handleRotationChange,
      });

      setNodes((prevNodes) => [...prevNodes, newNode]);
    },
    [rfInsatnce, setNodes, handleRotationChange],
  );

  //Menu Contextual para Nodos
  const nodeContextMenu = useCallback(
    (event, node) => {
      //Evitamos que salga el menu contextual por defecto
      event.preventDefault();

      setNodes((nds) =>
        nds.map((n) =>
          n.id === node.id && node.nodeType !== "programable"
            ? { ...n, selected: true }
            : { ...n, selected: false },
        ),
      );

      //Calculamos la posición de nuestro mouse para desplegar el menu en este lugar
      const pane = ref.current.getBoundingClientRect();

      setNodeMenu({
        id: node.id,
        top: event.clientY - 120,
        left: event.clientX,
        right: event.clientX >= pane.width - 200 && pane.width - event.clientX,
        bottom:
          event.clientY >= pane.height - 200 && pane.height - event.clientY,
        type: node.nodeType,
        onClick: setNodeMenu,
        onDelete: setSessionConnections,
      });
    },
    [setNodeMenu, setNodes],
  );

  //Menu Contextual para Edges
  const edgeContextMenu = useCallback(
    (event, edge) => {
      //Evitamos que salga el menu contextual por defecto
      event.preventDefault();

      //Calculamos la posición de nuestro mouse para desplegar el menu en este lugar
      const pane = ref.current.getBoundingClientRect();

      setEdges((eds) => {
        // Filtra para eliminar el edge seleccionado
        const remainingEdges = eds.filter((e) => e.id !== edge.id);

        // Cambia el tipo del edge seleccionado a 'edgeStyle' para la animación
        const updatedEdge = {
          ...edge,
          style: {
            ...edge.style, // Conservamos los estilos de la edge elegida
          },
        };

        // Re-agregar el edge al final de la lista para simular el cambio de zIndex
        return [...remainingEdges, updatedEdge];
      });

      setEdgeMenu({
        id: edge.id,
        top: event.clientY - 120,
        left: event.clientX,
        right: event.clientX >= pane.width - 200 && pane.width - event.clientX,
        bottom:
          event.clientY >= pane.height - 200 && pane.height - event.clientY,
        type: edge.nodeType,
        currentColor: edge.style.stroke,
        onClick: setEdgeMenu,
        onDelete: setSessionConnections,
      });
      setSelectedEdge(edge.id);
    },
    [setEdgeMenu, setEdges],
  );

  // Cerrar el menú al hacer clic o presionar una tecla
  useEffect(() => {
    const handleClickOrKeydown = () => {
      setNodeMenu(null); // Cierra el menú contextual del nodo al hacer clic o presionar cualquier tecla
      setEdgeMenu(null); // Cierra el menú contextual del edge al hacer clic o presionar cualquier tecla
      setNodes((nds) => nds.map((node) => ({ ...node, selected: false })));
    };

    window.addEventListener("keydown", handleClickOrKeydown);

    return () => {
      window.removeEventListener("keydown", handleClickOrKeydown);
    };
  }, [nodeMenu, edgeMenu, setNodes]);

  return (
    <div
      style={{
        height: "var(--Content-height)",
        background: "var(--blue-background)",
      }}
    >
      {/* Ocultar la marca de agua */}
      <style>{`.react-flow__attribution { display: none; }
      `}</style>

      <DropMenu />
      <ReactFlow
        ref={ref}
        nodes={nodes} //Agregamos los nodos
        edges={edges.map((edge) => ({
          ...edge,
          animated: edge.id === selectedEdge,
        }))}
        onInit={setRfInstance}
        onNodesChange={onNodesChange} //Evento cuando agregemos un nodo
        onEdgesChange={onEdgesChange} //Evento cuando agregemos un cable
        onEdgeClick={onEdgeClick} //Evento al presionar un cable
        onPaneClick={onPaneClick} //Nos permite dar click en donde sea para dejar de seleccionar el cable
        onConnect={onConnect} //Evento al conectar componentes
        onDrop={onDrop} //Evento de posicionamiento **Pendiente para quitarlo
        onDragOver={onDragOver} //Evento de arrastre **Pendiente para quitarlo
        nodeTypes={nodeTypes} //Para poder renderizar las imágenes
        edgeTypes={edgeTypes}
        onNodeContextMenu={nodeContextMenu}
        onEdgeContextMenu={edgeContextMenu}
        fitView
        onNodeDragStop={onNodeDragStop}
      >
        <Background variant="dots" color="#000" />
        <Controls showInteractive={false} />
        {nodeMenu && <NodeContextMenu onClick={onPaneClick} {...nodeMenu} />}
        {edgeMenu && <EdgeContextMenu onClick={onPaneClick} {...edgeMenu} />}
      </ReactFlow>
    </div>
  );
};
export default WorkBench;
