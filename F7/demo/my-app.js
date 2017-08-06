// Initialize app and store it to myApp variable for futher access to its methods
var myApp = new Framework7();

// We need to use custom DOM library, let's save it to $$ variable:
var $$ = Dom7;

// Add view
var mainView = myApp.addView('.view-main', {
    // Because we want to use dynamic navbar, we need to enable it for this view:
    dynamicNavbar: true,
    animateNavBackIcon: true,
    hideToolbarOnPageScroll: true,
    showToolbarOnPageScroll: true
});

$$('.hide-navbar').on('click', function () {
    mainView.hideNavbar();
});

$$('.show-navbar').on('click', function () {
    mainView.showNavbar();
});

$$('.hide-toolbar').on('click', function () {
    mainView.hideToolbar();
});

$$('.show-toolbar').on('click', function () {
    mainView.showToolbar();
});