import React, {Component} from 'react';
import { connect } from 'react-redux';
import ShowDeviceVmCard from './showDeviceVmCard';

import '../style.css';

class showRackCard extends Component {
  state = {
    rackId: 0
  };

  

  render() {
    const {rackId, device, vm} = this.props;
    return (
      <div key={rackId} className="rackDiv">
        {device && device.map(dv => {
          if(rackId === dv.rackId){
            return <ShowDeviceVmCard
              key={dv._id}
              device={dv}
              rackId={rackId}
              deviceId={dv.deviceId}
              deviceName={dv.deviceName}
              vm={vm}
              deviceStateChange={this.onClickHandler}
             />
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

export default connect(mapStateToProps)(showRackCard);
