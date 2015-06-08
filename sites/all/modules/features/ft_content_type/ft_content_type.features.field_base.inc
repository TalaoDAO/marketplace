<!DOCTYPE html>
<html lang='en'>
<head>
<meta charset='utf-8'>
<meta content='GitLab Community Edition' name='description'>
<title>
emindhub/sites/all/modules/features/ft_content_type/ft_content_type.features.field_base.inc at master - Yoann Babel / emindhub | 
GitLab
</title>
<link href="/assets/favicon-baaa14bade1248aa6165e9d34e7d83c0.ico" rel="shortcut icon" type="image/vnd.microsoft.icon" />
<link href="/assets/application-2ac58be704fef592dcfa8a14124e2688.css" media="all" rel="stylesheet" />
<link href="/assets/print-1df3ea9b8ff148a6745321899e0cb213.css" media="print" rel="stylesheet" />
<script src="/assets/application-5f3c67da81199dd3da676a30746cf17f.js"></script>
<meta content="authenticity_token" name="csrf-param" />
<meta content="mJv0IOS5D3OYzeFqOUj3Ui0ETsYSFZYQ5TBLG27H/yg=" name="csrf-token" />
<script type="text/javascript">
//<![CDATA[
window.gon={};gon.default_issues_tracker="gitlab";gon.api_version="v3";gon.relative_url_root="";gon.default_avatar_url="http://gitemindhub/assets/no_avatar-adffbfe10d45b20495cd2a9b88974150.png";gon.current_user_id=8;gon.api_token="tjV2QssUejpneZEouTVp";
//]]>
</script>
<meta content='width=device-width, initial-scale=1.0' name='viewport'>


</head>

<body class='ui_mars dark_theme project' data-page='projects:blob:show' data-project-id='3'>

<header class='navbar navbar-fixed-top navbar-gitlab'>
<div class='navbar-inner'>
<div class='container'>
<div class='app_logo'>
<a class="home has_bottom_tooltip" href="/" title="Dashboard"><h1>GITLAB</h1>
</a></div>
<h1 class='title'><span><a href="/u/yoann.babel">Yoann Babel</a> / <a href="/yoann.babel/emindhub">emindhub</a></span></h1>
<button class='navbar-toggle' data-target='.navbar-collapse' data-toggle='collapse' type='button'>
<span class='sr-only'>Toggle navigation</span>
<i class='fa fa-bars'></i>
</button>
<div class='navbar-collapse collapse'>
<ul class='nav navbar-nav'>
<li class='hidden-sm hidden-xs'>
<div class='search'>
<form accept-charset="UTF-8" action="/search" class="navbar-form pull-left" method="get"><div style="display:none"><input name="utf8" type="hidden" value="&#x2713;" /></div>
<input class="search-input" id="search" name="search" placeholder="Search in this project" type="search" />
<input id="group_id" name="group_id" type="hidden" />
<input id="project_id" name="project_id" type="hidden" value="3" />
<input id="search_code" name="search_code" type="hidden" value="true" />
<input id="repository_ref" name="repository_ref" type="hidden" value="master" />

<div class='search-autocomplete-opts hide' data-autocomplete-path='/search/autocomplete' data-autocomplete-project-id='3' data-autocomplete-project-ref='master'></div>
</form>

</div>
<script>
  $('.search-input').on('keyup', function(e) {
    if (e.keyCode == 27) {
      $('.search-input').blur()
    }
  })
</script>

</li>
<li class='visible-sm visible-xs'>
<a class="has_bottom_tooltip" data-original-title="Search area" href="/search" title="Search"><i class='fa fa-search'></i>
</a></li>
<li>
<a class="has_bottom_tooltip" data-original-title="Help" href="/help" title="Help"><i class='fa fa-question-circle'></i>
</a></li>
<li>
<a class="has_bottom_tooltip" data-original-title="Public area" href="/explore" title="Explore"><i class='fa fa-globe'></i>
</a></li>
<li>
<a class="has_bottom_tooltip" data-original-title="My snippets" href="/s/laetitia.debruyne" title="My snippets"><i class='fa fa-clipboard'></i>
</a></li>
<li>
<a class="has_bottom_tooltip" data-original-title="New project" href="/projects/new" title="New project"><i class='fa fa-plus'></i>
</a></li>
<li>
<a class="has_bottom_tooltip" data-original-title="Profile settings&quot;" href="/profile" title="Profile settings"><i class='fa fa-user'></i>
</a></li>
<li>
<a class="has_bottom_tooltip" data-method="delete" data-original-title="Logout" href="/users/sign_out" rel="nofollow" title="Logout"><i class='fa fa-sign-out'></i>
</a></li>
<li class='hidden-xs'>
<a class="profile-pic" href="/u/laetitia.debruyne" id="profile-pic"><img alt="User activity" src="/assets/no_avatar-adffbfe10d45b20495cd2a9b88974150.png" />
</a></li>
</ul>
</div>
</div>
</div>
</header>


<script>
  GitLab.GfmAutoComplete.dataSource = "/yoann.babel/emindhub/autocomplete_sources?type=NilClass&type_id=master%2Fsites%2Fall%2Fmodules%2Ffeatures%2Fft_content_type%2Fft_content_type.features.field_base.inc"
  GitLab.GfmAutoComplete.setup();
</script>

<div class='page-with-sidebar'>
<div class='sidebar-wrapper'>
<ul class='project-navigation nav nav-sidebar'>
<li class="home"><a class="shortcuts-project" href="/yoann.babel/emindhub" title="Project"><i class='fa fa-dashboard'></i>
<span>
Project
</span>
</a></li><li class="active"><a class="shortcuts-tree" href="/yoann.babel/emindhub/tree/master"><i class='fa fa-files-o'></i>
<span>
Files
</span>
</a></li><li class=""><a class="shortcuts-commits" href="/yoann.babel/emindhub/commits/master"><i class='fa fa-history'></i>
<span>
Commits
</span>
</a></li><li class=""><a class="shortcuts-network" href="/yoann.babel/emindhub/network/master"><i class='fa fa-code-fork'></i>
<span>
Network
</span>
</a></li><li class=""><a class="shortcuts-graphs" href="/yoann.babel/emindhub/graphs/master"><i class='fa fa-area-chart'></i>
<span>
Graphs
</span>
</a></li><li class=""><a class="shortcuts-issues" href="/yoann.babel/emindhub/issues"><i class='fa fa-exclamation-circle'></i>
<span>
Issues
<span class='count issue_counter'>56</span>
</span>
</a></li><li class=""><a class="shortcuts-merge_requests" href="/yoann.babel/emindhub/merge_requests"><i class='fa fa-tasks'></i>
<span>
Merge Requests
<span class='count merge_counter'>0</span>
</span>
</a></li><li class=""><a class="shortcuts-wiki" href="/yoann.babel/emindhub/wikis/home"><i class='fa fa-book'></i>
<span>
Wiki
</span>
</a></li></ul>

</div>
<div class='content-wrapper'>
<div class='container-fluid'>
<div class='content'>
<div class='flash-container'>
</div>

<div class='clearfix'>
<div class='tree-ref-holder'>
<form accept-charset="UTF-8" action="/yoann.babel/emindhub/refs/switch" class="project-refs-form" method="get"><div style="display:none"><input name="utf8" type="hidden" value="&#x2713;" /></div>
<select class="project-refs-select select2 select2-sm" id="ref" name="ref"><optgroup label="Branches"><option selected="selected" value="master">master</option></optgroup><optgroup label="Tags"></optgroup></select>
<input id="destination" name="destination" type="hidden" value="blob" />
<input id="path" name="path" type="hidden" value="sites/all/modules/features/ft_content_type/ft_content_type.features.field_base.inc" />
</form>


</div>
<div class='tree-holder' id='tree-holder'>
<ul class='breadcrumb repo-breadcrumb'>
<li>
<i class='fa fa-angle-right'></i>
<a href="/yoann.babel/emindhub/tree/master">emindhub
</a></li>
<li>
<a href="/yoann.babel/emindhub/tree/master/sites">sites</a>
</li>
<li>
<a href="/yoann.babel/emindhub/tree/master/sites/all">all</a>
</li>
<li>
<a href="/yoann.babel/emindhub/tree/master/sites/all/modules">modules</a>
</li>
<li>
<a href="/yoann.babel/emindhub/tree/master/sites/all/modules/features">features</a>
</li>
<li>
<a href="/yoann.babel/emindhub/tree/master/sites/all/modules/features/ft_content_type">ft_content_type</a>
</li>
<li>
<a href="/yoann.babel/emindhub/blob/master/sites/all/modules/features/ft_content_type/ft_content_type.features.field_base.inc"><strong>
ft_content_type.features.field_base.inc
</strong>
</a></li>
</ul>
<ul class='blob-commit-info bs-callout bs-callout-info hidden-xs'>
<li class='commit js-toggle-container'>
<div class='commit-row-title'>
<a class="commit_short_id" href="/yoann.babel/emindhub/commit/99e9d706b618c9fd60265943fcd2174de776ae0e">99e9d706</a>
&nbsp;
<span class='str-truncated'>
<a class="commit-row-message" href="/yoann.babel/emindhub/commit/99e9d706b618c9fd60265943fcd2174de776ae0e">Big feature update</a>
</span>
<a class="pull-right" href="/yoann.babel/emindhub/tree/99e9d706b618c9fd60265943fcd2174de776ae0e">Browse Code »</a>
<div class='notes_count'>
</div>
</div>
<div class='commit-row-info'>
<a class="commit-author-link has_tooltip" data-original-title="ybabel@free.fr" href="mailto:ybabel@free.fr"><img alt="" class="avatar s16" src="/assets/no_avatar-adffbfe10d45b20495cd2a9b88974150.png" width="16" /> <span class="commit-author-name">Administrator</span></a>
<div class='committed_ago'>
<time class='time_ago' data-placement='top' data-toggle='tooltip' datetime='2015-06-05T12:17:22Z' title='Jun 05, 2015 2:17pm'>2015-06-05 14:17:22 +0200</time>
<script>$('.time_ago').timeago().tooltip()</script>
 &nbsp;
</div>
</div>
</li>

</ul>
<div class='tree-content-holder' id='tree-content-holder'>
<article class='file-holder'>
<div class='file-title clearfix'>
<i class='fa fa-file'></i>
<span class='file_name'>
ft_content_type.features.field_base.inc
<small>841 Bytes</small>
</span>
<span class='options hidden-xs'><div class='btn-group tree-btn-group'>
<span class="btn btn-small disabled">Edit</span>
<a class="btn btn-small" href="/yoann.babel/emindhub/raw/master/sites/all/modules/features/ft_content_type/ft_content_type.features.field_base.inc" target="_blank">Raw</a>
<a class="btn btn-small" href="/yoann.babel/emindhub/blame/master/sites/all/modules/features/ft_content_type/ft_content_type.features.field_base.inc">Blame</a>
<a class="btn btn-small" href="/yoann.babel/emindhub/commits/master/sites/all/modules/features/ft_content_type/ft_content_type.features.field_base.inc">History</a>
<a class="btn btn-small" href="/yoann.babel/emindhub/blob/53b708ba7a40b598c372ea3984de6d8f95546b83/sites/all/modules/features/ft_content_type/ft_content_type.features.field_base.inc">Permalink</a>
</div>
</span>
</div>
<div class='file-content code'>
<div class='highlighted-data white'>
<div class='line-numbers'>
<a href="#L1" id="L1" rel="#L1"><i class='fa fa-link'></i>
1
</a><a href="#L2" id="L2" rel="#L2"><i class='fa fa-link'></i>
2
</a><a href="#L3" id="L3" rel="#L3"><i class='fa fa-link'></i>
3
</a><a href="#L4" id="L4" rel="#L4"><i class='fa fa-link'></i>
4
</a><a href="#L5" id="L5" rel="#L5"><i class='fa fa-link'></i>
5
</a><a href="#L6" id="L6" rel="#L6"><i class='fa fa-link'></i>
6
</a><a href="#L7" id="L7" rel="#L7"><i class='fa fa-link'></i>
7
</a><a href="#L8" id="L8" rel="#L8"><i class='fa fa-link'></i>
8
</a><a href="#L9" id="L9" rel="#L9"><i class='fa fa-link'></i>
9
</a><a href="#L10" id="L10" rel="#L10"><i class='fa fa-link'></i>
10
</a><a href="#L11" id="L11" rel="#L11"><i class='fa fa-link'></i>
11
</a><a href="#L12" id="L12" rel="#L12"><i class='fa fa-link'></i>
12
</a><a href="#L13" id="L13" rel="#L13"><i class='fa fa-link'></i>
13
</a><a href="#L14" id="L14" rel="#L14"><i class='fa fa-link'></i>
14
</a><a href="#L15" id="L15" rel="#L15"><i class='fa fa-link'></i>
15
</a><a href="#L16" id="L16" rel="#L16"><i class='fa fa-link'></i>
16
</a><a href="#L17" id="L17" rel="#L17"><i class='fa fa-link'></i>
17
</a><a href="#L18" id="L18" rel="#L18"><i class='fa fa-link'></i>
18
</a><a href="#L19" id="L19" rel="#L19"><i class='fa fa-link'></i>
19
</a><a href="#L20" id="L20" rel="#L20"><i class='fa fa-link'></i>
20
</a><a href="#L21" id="L21" rel="#L21"><i class='fa fa-link'></i>
21
</a><a href="#L22" id="L22" rel="#L22"><i class='fa fa-link'></i>
22
</a><a href="#L23" id="L23" rel="#L23"><i class='fa fa-link'></i>
23
</a><a href="#L24" id="L24" rel="#L24"><i class='fa fa-link'></i>
24
</a><a href="#L25" id="L25" rel="#L25"><i class='fa fa-link'></i>
25
</a><a href="#L26" id="L26" rel="#L26"><i class='fa fa-link'></i>
26
</a><a href="#L27" id="L27" rel="#L27"><i class='fa fa-link'></i>
27
</a><a href="#L28" id="L28" rel="#L28"><i class='fa fa-link'></i>
28
</a><a href="#L29" id="L29" rel="#L29"><i class='fa fa-link'></i>
29
</a><a href="#L30" id="L30" rel="#L30"><i class='fa fa-link'></i>
30
</a><a href="#L31" id="L31" rel="#L31"><i class='fa fa-link'></i>
31
</a><a href="#L32" id="L32" rel="#L32"><i class='fa fa-link'></i>
32
</a><a href="#L33" id="L33" rel="#L33"><i class='fa fa-link'></i>
33
</a><a href="#L34" id="L34" rel="#L34"><i class='fa fa-link'></i>
34
</a><a href="#L35" id="L35" rel="#L35"><i class='fa fa-link'></i>
35
</a><a href="#L36" id="L36" rel="#L36"><i class='fa fa-link'></i>
36
</a><a href="#L37" id="L37" rel="#L37"><i class='fa fa-link'></i>
37
</a><a href="#L38" id="L38" rel="#L38"><i class='fa fa-link'></i>
38
</a><a href="#L39" id="L39" rel="#L39"><i class='fa fa-link'></i>
39
</a><a href="#L40" id="L40" rel="#L40"><i class='fa fa-link'></i>
40
</a></div>
<div class='highlight'>
<pre><code class='ft_content_type.features.field_base.inc'>&lt;?php
/**
 * @file
 * ft_content_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ft_content_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_working_field'
  $field_bases['field_working_field'] = array(
    'active' =&gt; 1,
    'cardinality' =&gt; 1,
    'deleted' =&gt; 0,
    'entity_types' =&gt; array(),
    'field_name' =&gt; 'field_working_field',
    'indexes' =&gt; array(
      'value' =&gt; array(
        0 =&gt; 'value',
      ),
    ),
    'locked' =&gt; 0,
    'module' =&gt; 'list',
    'settings' =&gt; array(
      'allowed_values' =&gt; array(
        0 =&gt; '',
        1 =&gt; '',
      ),
      'allowed_values_function' =&gt; '',
      'entity_translation_sync' =&gt; FALSE,
    ),
    'translatable' =&gt; 0,
    'type' =&gt; 'list_boolean',
  );

  return $field_bases;
}
</code></pre>
</div>
</div>

</div>

</article>
</div>

</div>

</div>
</div>
</div>
</div>
</div>


</body>
</html>
