var gulp         = require('gulp');
var less         = require('gulp-less');
var notify       = require('gulp-notify');
var rename       = require('gulp-rename');
var sourcemaps   = require('gulp-sourcemaps');

// var minifycss    = require('gulp-minify-css');
// var clean        = require('gulp-clean');
// var concat       = require('gulp-concat');
// var cache        = require('gulp-cache');
var debug        = require('gulp-debug');
// var path         = require('path');


var theme_path  = "./www/sites/all/themes/emindhub/";
var watch_files = [theme_path + 'less/**/*.less'];
var src_less    = [theme_path + 'less/style.less'];


w = process.cwd();

gulp.task('less', function () {
  gulp.src(src_less)
    .pipe(sourcemaps.init())
    .pipe(debug({title: 'unicorn:'}))
    .pipe(less())
    .pipe(rename("style.css"))
    .pipe(sourcemaps.write('.', { sourceRoot: '../less' }))
    .pipe(gulp.dest(theme_path + './css'))
    .pipe(notify({message: 'Less compilation complete'}));
});

gulp.task('default', ['less']);

gulp.task('watch', function() {
  gulp.watch(watch_files, ['less']);
});
