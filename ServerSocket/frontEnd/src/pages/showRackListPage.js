import React, { Component } from 'react'
import {connect} from 'react-redux';
import { Select } from 'semantic-ui-react'

import {showAllInfo} from '../actions/rack';
import ShowRackCard from '../components/showRackCard';
import '../style.css';

class ShowRackListPage extends Component {
  state ={
    rackId: 0,
    state: "Faulted"
  }

  componentWillMount(){
    this.props.showAllInfo()
  }

  rackIdChange = (e) => {
    this.setState({
      rackId: e.target.value
    });
  }


  render() {
    console.log("ShowRackListPage.js", this.props, this.state);
    const { rack, device, vm } = this.props.data;

    return (
      <div className="container">
        <h2 className="listTitleRack">Racks List</h2>
        <select
          className="listSelect"
          value={this.state.rackId}
          onChange={this.rackIdChange}>
          {rack && rack.map(val => {
            return <option
            className="listSelectOption"
            key={val._id}
            defaultValue={val.rackId === 0 ? "true" : ""}
            value={val.rackId}
            > Name: {val.rackName} - Id: {val.rackId}</option>
          })}
        </select>
        <p className="rackTitle">Title: {rack && rack[this.state.rackId].rackName}</p>
        <ShowRackCard
          rackId={parseInt(this.state.rackId)}
          device={device}
          vm={vm}
        />

      </div>
    )
  }
}

function mapStateToProps(state) {
  return {
    data: state.rack
  }
}

export default connect(mapStateToProps, {showAllInfo})(ShowRackListPage);
