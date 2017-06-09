const gulp = require('gulp');
const clean = require('gulp-clean');
const concat = require('gulp-concat');
const cssmin = require('gulp-cssmin');
const eslint = require('gulp-eslint');
const less = require('gulp-less');
const livereload = require('gulp-livereload');
const rename = require('gulp-rename');
const sourcemaps = require('gulp-sourcemaps');
const uglify = require('gulp-uglify');
const gutil = require('gulp-util');

// Clean before everything else!
gulp.task('clean-styles', function () {
    return gulp.src('dist/*.css', {read: false})
        .pipe(clean());
});
gulp.task('clean-scripts', function () {
    return gulp.src('dist/*.js', {read: false})
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

gulp.task('concat', () => {
    return gulp.src([
        'js/theme/**/*.js'
    ])
    .pipe(concat('script.min.js'))
    .pipe(gulp.dest('dist'))
    .pipe(livereload());
});

gulp.task('uglify', ['clean-scripts', 'concat'], () => {
    return gulp.src(['dist/*.js'])
        .pipe(uglify({
            preserveComments: false,
            compress: false,
            mangle: false,

            output: {
                beautify: false,
                quote_keys: true,
                ascii_only: true
            }
        }))
        .on('error', function (err) { gutil.log(gutil.colors.red('[Error]'), err.toString()); })
        .pipe(gulp.dest('dist'));
});

// Watch
gulp.task('watch', () => {
    livereload.listen();
    gulp.watch(['js/**/*.js'], ['concat']);
    gulp.watch(['less/**/*.less'], ['less']);
});

gulp.task('lint', () => {
    return gulp.src(['js/theme/*.js', '!node_modules/**', '!vendor/**', '!dist/**'])
        .pipe(eslint())
        .pipe(eslint.format())
        .pipe(eslint.failAfterError());
});

// Default tasks
gulp.task('default', ['lint', 'css', 'javascript']);
gulp.task('default', ['css', 'javascript']);
gulp.task('dev', ['less', 'concat']);
gulp.task('css', ['less', 'cssmin']);
gulp.task('javascript', ['concat', 'uglify']);
