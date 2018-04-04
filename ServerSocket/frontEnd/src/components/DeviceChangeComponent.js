import React, {Component} from 'react';
// import PropTypes from 'prop-types';

class DeviceChangeComponent extends Component {
  state = {
  	socket: this.props.socket,
  	state: 'Faulted',
    rackId: 0,
    deviceId: 0,
  };


  changeState = () => {
    console.log("changeDeviceState...", this.state);
    const { state, rackId, deviceId} = this.state;

    const a = {
      state, 
      rackId,
      deviceId
    }
    this.state.socket.emit("changeDeviceState", a);
  }

  stateChange = (e) => {
    this.setState({
      state: e.target.value
    });
  }

  rackIdChange = (e) => {
    this.setState({
      rackId: e.target.value
    });
  }

  deviceIdChange = (e) => {
    this.setState({
      deviceId: e.target.value
    });
  }
  render() {
    return (
      <div>
        
        <button onClick={this.changeState}>Change State</button>

        <p>Device State</p>
        <select value={this.state.state} onChange={this.stateChange}>
          <option defaultValue value="Faulted">Faulted</option>
          <option value="Offline">Offline</option>
          <option value="Degraded">Degraded</option>
        </select>
        <p>RackId</p>
        <input type="number" value={this.state.rackId} onChange={this.rackIdChange}/>

        <p>DeviceId</p>
        <input type="number" value={this.state.deviceId} onChange={this.deviceIdChange}/>

      </div>
    );
  }
}

// DeviceChangeComponent.propTypes = {}

export default DeviceChangeComponent;