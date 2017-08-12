var webpack = require('webpack');
var HtmlWebpackPlugin = require('html-webpack-plugin');

var plugins = [
  new webpack.optimize.CommonsChunkPlugin({
    name: 'vendor',
    filename: 'vendor.min.js',
  }),
  new HtmlWebpackPlugin({
    title: 'My App',
    filename: 'index.html',
    template: "./src/index.html"
  })
];

var yargs = require('yargs');
var env = yargs.argv.env;
var tmp_global_var = {
  local_develop: false,
  is_production: false
};

switch (env) {
  case "local":
    tmp_global_var.local_develop = true;
    break;
  default:
    tmp_global_var.is_production = true;
    break;
}

plugins.push(new webpack.DefinePlugin({
  LOCAL_DEVELOP: JSON.stringify(tmp_global_var["local_develop"]),
  IS_PRODUCTION: JSON.stringify(tmp_global_var["is_production"])
}));

module.exports = {
  entry: "./src/index.ts",
  output: {
    filename: "bundle.js",
    path: __dirname + "/dist"
  },
  plugins: plugins,

  // Enable sourcemaps for debugging webpack's output.
  devtool: "source-map",

  resolve: {
    // Add '.ts' and '.tsx' as resolvable extensions.
    extensions: [".ts", ".tsx", ".js", ".json"]
  },

  module: {
    rules: [
      // All files with a '.ts' or '.tsx' extension will be handled by 'awesome-typescript-loader'.
      {
        test: /\.tsx?$/,
        loader: "awesome-typescript-loader"
      },

      // All output '.js' files will have any sourcemaps re-processed by 'source-map-loader'.
      {
        enforce: "pre",
        test: /\.js$/,
        loader: "source-map-loader"
      }
    ]
  }
};