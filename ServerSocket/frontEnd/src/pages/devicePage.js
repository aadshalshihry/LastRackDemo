import React, { Component } from 'react'
import { Form, Button, Message } from 'semantic-ui-react';
import { connect } from 'react-redux';


class DevicePage extends Component {
  state = {
    fliter: ""
  }
  onChange = e => {
    this.setState({
      fliter: e.target.value
    });
  }

  onSubmit = (e) => {
    e.preventDefault();
    let result = `filterName::${this.state.fliter}`
    this.props.socket.emit("filterName", result);
  }

  render() {

    return (
      <Form onSubmit={this.onSubmit}>


        <Form.Field>
          <label htmlFor="username">Search</label>
          <input
            type="text"
            id="username"
            name="username"
            placeholder="seatch"
            value={this.state.fliter}
            onChange={this.onChange.bind(this)}
          />
        </Form.Field>


        <Button primary>Search</Button>
      </Form>
    );
  }
}

function mapStateToProps(state) {
  return {
    socket: state.socket
  }
}

export default connect(mapStateToProps)(DevicePage);
