import { SHOW_ALL_INFO, SOCKET_CREATED } from '../actions/types';

export default function rack(state = {}, action = {}) {
  switch (action.type) {
  	case SHOW_ALL_INFO:
      return action.data;

    default:
      return state;

  }
}

export function socketReducer(state = {}, action = {}) {
	switch(action.type) {
		case SOCKET_CREATED:
			return action.data;

		default:
			return state;
	}
}

// export function coder(state = {}, action = {}) {
//   switch(action.type) {
//     case CODER_LOADED_INFO:
//     case CODER_LOADED_SUBMIT:
//       return action.coder;
//     case CLEAR_CODE_OBJ:
//       return action.coder

//     default:
//       return state;
//   }
// }