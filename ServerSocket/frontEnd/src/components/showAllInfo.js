import React, {Component} from 'react';

class ShowAllInfo extends Component {
  state = {
    res: false
   };

  render() {
    const { racks, devices, vms } = this.props;

    console.log("showAllInfo", racks, devices, vms);
    return (
      <div>
          { racks && racks.map(val => {
            return(
              <div key={val._id + "/"}>
                <h3 key={val._id}>{val.rackName}</h3>
                { devices && devices.map(d => {
                  if(d.rackId === val.rackId){
                    return <h3 key={d._id}>{d.deviceName}</h3>
                  }
                })}
              </div>
            )
          })}
      </div>
    );
  }
}


export default ShowAllInfo;
