import { combineReducers } from 'redux';
import rack, {socketReducer} from './rack';


export default combineReducers({
    rack,
    socket: socketReducer
});