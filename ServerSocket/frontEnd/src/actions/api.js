import axios from 'axios';

export default {
  rack: {
    showAllInfo: () => axios.all([
      axios.get('http://localhost:4001/racks'),
      axios.get('http://localhost:4001/devices'),
      axios.get('http://localhost:4001/vms')
    ])
    // .then(axios.spread((racksRes, devicesRes, vmsRes) => {
    //   let data = {
    //     racks: racksRes.data.rack,
    //     devices: devicesRes.data.device,
    //     vms: vmsRes.data.vm 
    //   };
    //   console.log(data);
      
    //   return data;
    // })),
  },
  user: {
    login: credentials => axios.post('/api/auth/login', {credentials})
      .then(res => res.data.user),

    signup: user => axios.post('/api/users/signup', {user})
      .then(res => res.data.user),

    confirm: token => axios.post('/api/auth/confirmation', {token})
      .then(res => res.data.user),

    resetPasswordRequest: email =>
      axios.post('/api/auth/reset_password_request', {email}),

    validateToken: token => axios.post('/api/auth/validate_tokne', {token}),

    setNewPassword: (data) => axios.post('/api/auth/set_new_password', {data})
  },
  coder: {
    loadCoderList: () => 
      axios.get('/api/coder/coder-list').then(res => res.data.data),

    loadCoderInfo: (data) => axios.post('/api/coder/coder-info', data)
      .then(res => res.data.coder),

    submitCode: (data) => axios.post('/api/coder/coder-submit', data)
      .then(res => res.data.coder)
    
  }
};
