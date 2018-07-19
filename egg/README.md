# DOC
- http://eggjs.org/zh-cn/tutorials/progressive.html

## [渐进式开发](http://eggjs.org/zh-cn/tutorials/progressive.html)
得益于Egg强大的插件机制，在开发中：
- 有可能复用的代码，放到```lib/plugin```中，如egg-ua
- 当插件功能稳定后，可以独立出来作为一个node module
- 如此，复用性较强的代码会逐渐独立为单独的插件
- 当我们的应用逐步进化到针对某业务场景的解决方案时，将其抽象为独立的framework进行发布
- 至此，整个团队的效率也会有极大的提升。
