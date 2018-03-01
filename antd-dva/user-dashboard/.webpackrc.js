export default {
    "proxy": {
        // "/api": {
        //     "target": "http://localhost:3000/",
        //     "changeOrigin": true
        // }
        "/api": {
            "target": "http://jsonplaceholder.typicode.com/",
            "changeOrigin": true,
            "pathRewrite": { "^/api": "" }
        }
    }
}