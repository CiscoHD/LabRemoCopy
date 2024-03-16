import { NodeModel} from '@projectstorm/react-diagrams';
import {AbstractReactFactory } from '@projectstorm/react-canvas-core'
import React, { Component } from 'react'

export default class NodeFactory extends AbstractReactFactory{
    constructor(){
        super('js-custom-node');
    }

    generateModel(event){
        return new NodeModel();
    }

    generateReactWidget(event){

    }



  render() {
    return (
      <div>NodeFactory</div>
    )
  }
}
