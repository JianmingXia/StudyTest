module.exports = {
  entry: "./Hyperx/index.js",
  output: {
    filename: "./Hyperx/bundle.js",
  },
  module: {
    loaders: [
      {
        test: /\.js$/,
        exclude: /node_modules/,
        loader: "babel-loader!transform-loader?hyperxify"
      }
    ]
  }
}
