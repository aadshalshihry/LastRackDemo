import React, { Component } from 'react';
import {Route} from 'react-router-dom';
import { connect } from 'react-redux';
import { Container, Menu, Segment, Button, Icon } from 'semantic-ui-react'
import { Link } from 'react-router-dom';
import DeviceChangeComponent from './components/DeviceChangeComponent';
import ShowAllInfo from './components/showAllInfo';
import ShowRackList from './pages/showRackListPage';
import RackPage from './pages/rackPage';
import DevicePage from './pages/devicePage';
import VmPage from './pages/vmPage';
import MyRoute from './components/routes/MyRoute';
import {createSocket} from './actions/rack';

import './App.css';
// import RackPage from './pages/rackPage';
// import VmPage from './pages/vmPage';


class App extends Component {
  constructor() {
    super();
    this.state = {
      responseRack: false,
      responseDevice: false,
      responseVm: false,
      racks: [],
      devices: [],
      vms: [],
      activeItem: 'showRackList'
    };

  }

  handleItemClick = (e, { name }) => this.setState({ activeItem: name })
  componentWillMount() {
    this.props.createSocket();
  }

  SendToQtBtn = (e) => {
    e.preventDefault();
    this.props.socket.emit("loadData");
  }

  render() {
    const { activeItem, location } = this.state;
    console.log("App...", this.state)
    return (
      <Container>
        <Menu pointing>
          <Menu.Item
            as={Link}
            to="/"
            name='showRackList'
            active={activeItem === 'showRackList'} onClick={this.handleItemClick} />
          <Menu.Item
            as={Link}
          	to="/rack"
            name='Rack'
            active={activeItem === 'Rack'} onClick={this.handleItemClick} />
          <Menu.Item
            as={Link}
            to="/device"
            name='Device'
            active={activeItem === 'Device'} onClick={this.handleItemClick} />
          <Menu.Item
            as={Link}
            to="/vm"
            name='VM'
            active={activeItem === 'VM'} onClick={this.handleItemClick} />
        </Menu>

        <Container>
          <Button icon
            labelPosition='right'
            onClick={this.SendToQtBtn}
            >
            Send to Qt
            <Icon name='right arrow' />
          </Button>
        </Container>

        <Segment>
          <Route location={location} path="/" exact component={ShowRackList} />
          <Route location={location} path="/rack" exact component={RackPage} />
          <Route location={location} path="/device" exact component={DevicePage} />
          <Route location={location} path="/vm" exact component={VmPage} />
        </Segment>


      </Container>
    );
  }
}
function mapStateToProps(state) {
	return {
		socket: state.socket
	}
}

export default connect(mapStateToProps, {createSocket})(App);
