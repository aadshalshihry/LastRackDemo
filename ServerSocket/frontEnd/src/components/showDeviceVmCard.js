import React, {Component} from 'react';
import { Button, Icon, Input } from 'semantic-ui-react'
import { connect } from 'react-redux';

import '../style.css';

class showDeviceVmCard extends Component {
  state = {
  	rackId: this.props.rackId,
    deviceId: this.props.deviceId,
  	deviceName: this.props.deviceName,
    deviceNameInputShow: false,

  };

  onDeviceClickHandler = (e) => {
  	const {rackId, deviceId} = this.state;
    let val = e.target.value
  	const a = {
  		state: val,
  		rackId,
  		deviceId
  	}
  	this.props.socket.emit("changeDeviceState", a);
  }

  onVmClickHandler = (e, vmId) => {
  	const {rackId, deviceId} = this.state;
    let val = e.target.value
  	const a = {
  		state: val,
  		rackId,
  		deviceId,
  		vmId
  	}
  	this.props.socket.emit("changeVMState", a);
  }

  writeClickHandlerBtn = (e) => {
    this.setState({
      deviceNameInputShow: !this.state.deviceNameInputShow
    })
    // console.log("Clicked...",  this.state);
  }

  changeDNameHandler = (e) => {
    this.setState({
      deviceName: e.target.value,
    })
  }

  sendDNameChangeHandler = (e) => {
    if (e.key === 'Enter') {
      const {rackId, deviceId} = this.state;
      let val = e.target.value

      const a = {
        rackId,
        deviceId,
        deviceName: val
      }
      this.props.socket.emit("changeDeviceName", a);

      this.setState({
        deviceNameInputShow: false
      })
    }
  }

  render() {
  	const { rackId, device, deviceId, vm, deviceStateChange } = this.props;
    const { deviceNameInputShow, deviceName } = this.state;
    return (
        <div className="deviceDiv">
        	<div className="deviceTitleButtons">
            {deviceNameInputShow ? <Input type="text"
                                    className="deviceInput"
                                    value={deviceName}
                                    onChange={this.changeDNameHandler}
                                    onKeyPress={this.sendDNameChangeHandler}
                                    autoFocus
                                    />
              :
        	    <h2 className="listTitleDevice">{deviceName}
                <Icon className="listTitleDeviceIcon" onClick={this.writeClickHandlerBtn} name="write" />
              </h2>
            }

        		<div>
              <Button size="small" color='green' value="Operational" onClick={this.onDeviceClickHandler}>&nbsp;</Button>
        			<Button size="small" color='red' value="Faulted" onClick={this.onDeviceClickHandler}>&nbsp;</Button>
      		    <Button size="small" color='yellow' value="Offline" onClick={this.onDeviceClickHandler}>&nbsp;</Button>
      		    <Button size="small" color='orange' value="Degraded" onClick={this.onDeviceClickHandler}>&nbsp;</Button>
              <Button size="small" color='black' value="Disconnected" onClick={this.onDeviceClickHandler}>&nbsp;</Button>
        		</div>
        	</div>

          {vm && vm.map(vv => {
            if(device.deviceId === vv.deviceId && rackId === vv.rackId) {
              return(
                <div key={vv._id} className="vmDiv">
                	<div className="vmTitleButtons">
                  	<h3 className="listTitleVm">{vv.vmName}</h3>
                    <div>
                      <Button size="mini" color='green' value="Operational" 
                      onClick={(e) => this.onVmClickHandler(e, vv.vmId)}>&nbsp;</Button>

                      <Button size="mini" color='red' value="Faulted" 
                        onClick={(e) => this.onVmClickHandler(e, vv.vmId)}>&nbsp;</Button>

                      <Button size="mini" color='yellow' value="Offline" 
                        onClick={(e) => this.onVmClickHandler(e, vv.vmId)}>&nbsp;</Button>

                      <Button size="mini" color='orange' value="Degraded" 
                        onClick={(e) => this.onVmClickHandler(e, vv.vmId)}>&nbsp;</Button>

                      <Button size="mini" color='black' value="Disconnected" 
                      onClick={(e) => this.onVmClickHandler(e, vv.vmId)}>&nbsp;</Button>

                    </div>
                		
                	</div>
                </div>
              )
            }
          })}
        </div>
    );
  }
}

function mapStateToProps(state) {
	return {
		socket: state.socket
	}
}

export default connect(mapStateToProps)(showDeviceVmCard);
