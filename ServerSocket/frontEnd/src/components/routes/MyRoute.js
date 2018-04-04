import React from 'react';
import PropTypes from 'prop-types';
import { connect } from 'react-redux';
import { Route, Redirect } from 'react-router-dom';

const MyRoute = ({ component: Component, ...rest }) => (
  <Route {...rest} render={props =><Component {...props} />} />
 
);

export default MyRoute;