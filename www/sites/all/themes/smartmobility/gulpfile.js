const gulp = require('gulp');
const clean = require('gulp-clean');
const cssmin = require('gulp-cssmin');
const less = require('gulp-less');
const livereload = require('gulp-livereload');
const rename = require('gulp-rename');
const sourcemaps = require('gulp-sourcemaps');
const gutil = require('gulp-util');

// Clean before everything else!
gulp.task('clean-styles', function () {
    return gulp.src('dist/*.css', {read: false})
        .pipe(clean());
});

// CSS
gulp.task('less', ['clean-styles'], () => {
    return gulp.src('./less/style.less')
        .pipe(sourcemaps.init())
        .pipe(less().on('error', function (e) {
            gutil.log(e.message, 'in', e.filename);
            this.emit('end');
        }))
        .pipe(sourcemaps.write())
        .pipe(rename({
            basename: 'style.min'
        }))
        .pipe(gulp.dest('dist'))
        .pipe(livereload());
});

gulp.task('cssmin', ['less'], () => {
    return gulp.src('./dist/*.css')
        .pipe(cssmin({
            keepSpecialComments: 0
        }))
        .pipe(gulp.dest('dist'))
        .pipe(livereload());
});

// Watch
gulp.task('watch', () => {
    livereload.listen();
    gulp.watch(['less/**/*.less'], ['less']);
});

// Default tasks
gulp.task('default', ['css']);
gulp.task('dev', ['less']);
gulp.task('css', ['less', 'cssmin']);
