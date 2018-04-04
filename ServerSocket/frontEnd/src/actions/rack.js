import {SHOW_ALL_INFO, SOCKET_CREATED} from './types';
import api from './api';
import socketIOClient from "socket.io-client";


export const showAllInfoAction = (data) => ({
  type: SHOW_ALL_INFO,
  data
})

export const socketCreated = (socket) => ({
  type: SOCKET_CREATED,
  data: socket
})

export const showAllInfo = () => dispatch => 
  api.rack.showAllInfo().then(res => {
    let data = {
      rack: res[0].data.rack,
      device: res[1].data.device,
      vm: res[2].data.vm
    }
    dispatch(showAllInfoAction(data));
    // console.log(res, data);
  })

export const createSocket = () => dispatch => {
  const socket = socketIOClient("http://localhost:4001");
  dispatch(socketCreated(socket));
}

//===============================
/*
export const userLoggedIn = (user) => ({type: USER_LOGGED_IN, user});

export const userLoggedOut = () => ({type: USER_LOGGED_OUT});

export const login = credentials => dispatch => 
	api.user.login(credentials).then(user => {
	  localStorage.arabsandboxJWT = user.token;
	  setAuthorizationHeader(user.token);
	  dispatch(userLoggedIn(user))
	});

export const logout = () => dispatch => {
  localStorage.removeItem('arabsandboxJWT');
  setAuthorizationHeader();
  dispatch(userLoggedOut());
};

export const confirm = (token) => (dispatch) => 
  api.user.confirm(token).then(user => {
    localStorage.arabsandboxJWT = user.token;
    dispatch(userLoggedIn(user))
  });

export const resetPasswordRequest = ({email}) => () => api.user.resetPasswordRequest(email)

export const validateToken = (token) => () => api.user.validateToken(token)

export const setNewPassword = (data) => () => api.user.setNewPassword(data)
*/