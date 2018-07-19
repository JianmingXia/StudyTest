const LocalStrategy = require('passport-local').Strategy;

const system_users = [{
    username: "ryoma",
    password: "123"
}];

module.exports = app => {
    // 挂载 strategy
    app.passport.use(new LocalStrategy({
        passReqToCallback: true,
    }, (req, username, password, done) => {
        const user = {
            provider: 'local',
            username,
            password,
        };
        console.log(user);

        for (let system_user of system_users) {
            if (system_user.username === user.username && system_user.password === user.password) {
                return done(null, user);
            } else {
                return done(null, false);
            }
        }
    }));

    // 处理用户信息
    app.passport.verify(async (ctx, user) => {});
    app.passport.serializeUser(async (ctx, user) => {});
    app.passport.deserializeUser(async (ctx, user) => {});
};