import React, { Component } from 'react';
import {AbstractReactFactory} from '@projectstorm/react-canvas-core'

export default class CustomNodeFactory extends AbstractReactFactory {
    constructor(){
        super('js-custom-node');
    }
    
    generateModel(event){
        CustomNodeModel();
    }
    
    generateReactWidget(event){
        return <CustomNodeWidget engine={this.engine} node={event.model} />;
    }
}
