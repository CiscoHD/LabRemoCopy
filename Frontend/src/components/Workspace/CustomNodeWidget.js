import React, { Component } from 'react';
import {AbstractReactFactory} from '@projectstorm/react-canvas-core';
import { PortWidget } from '@projectstorm/react-diagrams';

export default class CustomNodeWidget extends Component {
  render() {
    return (
      <div className="custom-node">
        <PortWidget engine={this.props.engine} port={this.props.getPort('in')} >
            <div className="circle-port" />
        </PortWidget>
        <PortWidget engine={this.props.engine} port={this.props.getPort('out')} >
          <div className="circle-port" />
        </PortWidget>
        <div className="custom-node-color" style={{
            backgroundColor: this.props.node.color
        }} />
    </div>
    )
  }
}
