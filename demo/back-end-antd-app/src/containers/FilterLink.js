import { connect } from 'react-redux';
import { setFilterType } from "../actions/index";
import Link from "../components/Link";

const mapStateToProps = (state, ownProps) => ({
  active: state.filterType === ownProps.filter,
})

const mapDispatchToProps = (dispatch, ownProps) => ({
  onClick: () => dispatch(setFilterType(ownProps.filter)),
})

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(Link)
