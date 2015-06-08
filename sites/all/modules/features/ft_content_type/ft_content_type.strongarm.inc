<!DOCTYPE html>
<html lang='en'>
<head>
<meta charset='utf-8'>
<meta content='GitLab Community Edition' name='description'>
<title>
emindhub/sites/all/modules/features/ft_content_type/ft_content_type.strongarm.inc at master - Yoann Babel / emindhub | 
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
  GitLab.GfmAutoComplete.dataSource = "/yoann.babel/emindhub/autocomplete_sources?type=NilClass&type_id=master%2Fsites%2Fall%2Fmodules%2Ffeatures%2Fft_content_type%2Fft_content_type.strongarm.inc"
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
<input id="path" name="path" type="hidden" value="sites/all/modules/features/ft_content_type/ft_content_type.strongarm.inc" />
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
<a href="/yoann.babel/emindhub/blob/master/sites/all/modules/features/ft_content_type/ft_content_type.strongarm.inc"><strong>
ft_content_type.strongarm.inc
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
ft_content_type.strongarm.inc
<small>41.7 KB</small>
</span>
<span class='options hidden-xs'><div class='btn-group tree-btn-group'>
<span class="btn btn-small disabled">Edit</span>
<a class="btn btn-small" href="/yoann.babel/emindhub/raw/master/sites/all/modules/features/ft_content_type/ft_content_type.strongarm.inc" target="_blank">Raw</a>
<a class="btn btn-small" href="/yoann.babel/emindhub/blame/master/sites/all/modules/features/ft_content_type/ft_content_type.strongarm.inc">Blame</a>
<a class="btn btn-small" href="/yoann.babel/emindhub/commits/master/sites/all/modules/features/ft_content_type/ft_content_type.strongarm.inc">History</a>
<a class="btn btn-small" href="/yoann.babel/emindhub/blob/53b708ba7a40b598c372ea3984de6d8f95546b83/sites/all/modules/features/ft_content_type/ft_content_type.strongarm.inc">Permalink</a>
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
</a><a href="#L41" id="L41" rel="#L41"><i class='fa fa-link'></i>
41
</a><a href="#L42" id="L42" rel="#L42"><i class='fa fa-link'></i>
42
</a><a href="#L43" id="L43" rel="#L43"><i class='fa fa-link'></i>
43
</a><a href="#L44" id="L44" rel="#L44"><i class='fa fa-link'></i>
44
</a><a href="#L45" id="L45" rel="#L45"><i class='fa fa-link'></i>
45
</a><a href="#L46" id="L46" rel="#L46"><i class='fa fa-link'></i>
46
</a><a href="#L47" id="L47" rel="#L47"><i class='fa fa-link'></i>
47
</a><a href="#L48" id="L48" rel="#L48"><i class='fa fa-link'></i>
48
</a><a href="#L49" id="L49" rel="#L49"><i class='fa fa-link'></i>
49
</a><a href="#L50" id="L50" rel="#L50"><i class='fa fa-link'></i>
50
</a><a href="#L51" id="L51" rel="#L51"><i class='fa fa-link'></i>
51
</a><a href="#L52" id="L52" rel="#L52"><i class='fa fa-link'></i>
52
</a><a href="#L53" id="L53" rel="#L53"><i class='fa fa-link'></i>
53
</a><a href="#L54" id="L54" rel="#L54"><i class='fa fa-link'></i>
54
</a><a href="#L55" id="L55" rel="#L55"><i class='fa fa-link'></i>
55
</a><a href="#L56" id="L56" rel="#L56"><i class='fa fa-link'></i>
56
</a><a href="#L57" id="L57" rel="#L57"><i class='fa fa-link'></i>
57
</a><a href="#L58" id="L58" rel="#L58"><i class='fa fa-link'></i>
58
</a><a href="#L59" id="L59" rel="#L59"><i class='fa fa-link'></i>
59
</a><a href="#L60" id="L60" rel="#L60"><i class='fa fa-link'></i>
60
</a><a href="#L61" id="L61" rel="#L61"><i class='fa fa-link'></i>
61
</a><a href="#L62" id="L62" rel="#L62"><i class='fa fa-link'></i>
62
</a><a href="#L63" id="L63" rel="#L63"><i class='fa fa-link'></i>
63
</a><a href="#L64" id="L64" rel="#L64"><i class='fa fa-link'></i>
64
</a><a href="#L65" id="L65" rel="#L65"><i class='fa fa-link'></i>
65
</a><a href="#L66" id="L66" rel="#L66"><i class='fa fa-link'></i>
66
</a><a href="#L67" id="L67" rel="#L67"><i class='fa fa-link'></i>
67
</a><a href="#L68" id="L68" rel="#L68"><i class='fa fa-link'></i>
68
</a><a href="#L69" id="L69" rel="#L69"><i class='fa fa-link'></i>
69
</a><a href="#L70" id="L70" rel="#L70"><i class='fa fa-link'></i>
70
</a><a href="#L71" id="L71" rel="#L71"><i class='fa fa-link'></i>
71
</a><a href="#L72" id="L72" rel="#L72"><i class='fa fa-link'></i>
72
</a><a href="#L73" id="L73" rel="#L73"><i class='fa fa-link'></i>
73
</a><a href="#L74" id="L74" rel="#L74"><i class='fa fa-link'></i>
74
</a><a href="#L75" id="L75" rel="#L75"><i class='fa fa-link'></i>
75
</a><a href="#L76" id="L76" rel="#L76"><i class='fa fa-link'></i>
76
</a><a href="#L77" id="L77" rel="#L77"><i class='fa fa-link'></i>
77
</a><a href="#L78" id="L78" rel="#L78"><i class='fa fa-link'></i>
78
</a><a href="#L79" id="L79" rel="#L79"><i class='fa fa-link'></i>
79
</a><a href="#L80" id="L80" rel="#L80"><i class='fa fa-link'></i>
80
</a><a href="#L81" id="L81" rel="#L81"><i class='fa fa-link'></i>
81
</a><a href="#L82" id="L82" rel="#L82"><i class='fa fa-link'></i>
82
</a><a href="#L83" id="L83" rel="#L83"><i class='fa fa-link'></i>
83
</a><a href="#L84" id="L84" rel="#L84"><i class='fa fa-link'></i>
84
</a><a href="#L85" id="L85" rel="#L85"><i class='fa fa-link'></i>
85
</a><a href="#L86" id="L86" rel="#L86"><i class='fa fa-link'></i>
86
</a><a href="#L87" id="L87" rel="#L87"><i class='fa fa-link'></i>
87
</a><a href="#L88" id="L88" rel="#L88"><i class='fa fa-link'></i>
88
</a><a href="#L89" id="L89" rel="#L89"><i class='fa fa-link'></i>
89
</a><a href="#L90" id="L90" rel="#L90"><i class='fa fa-link'></i>
90
</a><a href="#L91" id="L91" rel="#L91"><i class='fa fa-link'></i>
91
</a><a href="#L92" id="L92" rel="#L92"><i class='fa fa-link'></i>
92
</a><a href="#L93" id="L93" rel="#L93"><i class='fa fa-link'></i>
93
</a><a href="#L94" id="L94" rel="#L94"><i class='fa fa-link'></i>
94
</a><a href="#L95" id="L95" rel="#L95"><i class='fa fa-link'></i>
95
</a><a href="#L96" id="L96" rel="#L96"><i class='fa fa-link'></i>
96
</a><a href="#L97" id="L97" rel="#L97"><i class='fa fa-link'></i>
97
</a><a href="#L98" id="L98" rel="#L98"><i class='fa fa-link'></i>
98
</a><a href="#L99" id="L99" rel="#L99"><i class='fa fa-link'></i>
99
</a><a href="#L100" id="L100" rel="#L100"><i class='fa fa-link'></i>
100
</a><a href="#L101" id="L101" rel="#L101"><i class='fa fa-link'></i>
101
</a><a href="#L102" id="L102" rel="#L102"><i class='fa fa-link'></i>
102
</a><a href="#L103" id="L103" rel="#L103"><i class='fa fa-link'></i>
103
</a><a href="#L104" id="L104" rel="#L104"><i class='fa fa-link'></i>
104
</a><a href="#L105" id="L105" rel="#L105"><i class='fa fa-link'></i>
105
</a><a href="#L106" id="L106" rel="#L106"><i class='fa fa-link'></i>
106
</a><a href="#L107" id="L107" rel="#L107"><i class='fa fa-link'></i>
107
</a><a href="#L108" id="L108" rel="#L108"><i class='fa fa-link'></i>
108
</a><a href="#L109" id="L109" rel="#L109"><i class='fa fa-link'></i>
109
</a><a href="#L110" id="L110" rel="#L110"><i class='fa fa-link'></i>
110
</a><a href="#L111" id="L111" rel="#L111"><i class='fa fa-link'></i>
111
</a><a href="#L112" id="L112" rel="#L112"><i class='fa fa-link'></i>
112
</a><a href="#L113" id="L113" rel="#L113"><i class='fa fa-link'></i>
113
</a><a href="#L114" id="L114" rel="#L114"><i class='fa fa-link'></i>
114
</a><a href="#L115" id="L115" rel="#L115"><i class='fa fa-link'></i>
115
</a><a href="#L116" id="L116" rel="#L116"><i class='fa fa-link'></i>
116
</a><a href="#L117" id="L117" rel="#L117"><i class='fa fa-link'></i>
117
</a><a href="#L118" id="L118" rel="#L118"><i class='fa fa-link'></i>
118
</a><a href="#L119" id="L119" rel="#L119"><i class='fa fa-link'></i>
119
</a><a href="#L120" id="L120" rel="#L120"><i class='fa fa-link'></i>
120
</a><a href="#L121" id="L121" rel="#L121"><i class='fa fa-link'></i>
121
</a><a href="#L122" id="L122" rel="#L122"><i class='fa fa-link'></i>
122
</a><a href="#L123" id="L123" rel="#L123"><i class='fa fa-link'></i>
123
</a><a href="#L124" id="L124" rel="#L124"><i class='fa fa-link'></i>
124
</a><a href="#L125" id="L125" rel="#L125"><i class='fa fa-link'></i>
125
</a><a href="#L126" id="L126" rel="#L126"><i class='fa fa-link'></i>
126
</a><a href="#L127" id="L127" rel="#L127"><i class='fa fa-link'></i>
127
</a><a href="#L128" id="L128" rel="#L128"><i class='fa fa-link'></i>
128
</a><a href="#L129" id="L129" rel="#L129"><i class='fa fa-link'></i>
129
</a><a href="#L130" id="L130" rel="#L130"><i class='fa fa-link'></i>
130
</a><a href="#L131" id="L131" rel="#L131"><i class='fa fa-link'></i>
131
</a><a href="#L132" id="L132" rel="#L132"><i class='fa fa-link'></i>
132
</a><a href="#L133" id="L133" rel="#L133"><i class='fa fa-link'></i>
133
</a><a href="#L134" id="L134" rel="#L134"><i class='fa fa-link'></i>
134
</a><a href="#L135" id="L135" rel="#L135"><i class='fa fa-link'></i>
135
</a><a href="#L136" id="L136" rel="#L136"><i class='fa fa-link'></i>
136
</a><a href="#L137" id="L137" rel="#L137"><i class='fa fa-link'></i>
137
</a><a href="#L138" id="L138" rel="#L138"><i class='fa fa-link'></i>
138
</a><a href="#L139" id="L139" rel="#L139"><i class='fa fa-link'></i>
139
</a><a href="#L140" id="L140" rel="#L140"><i class='fa fa-link'></i>
140
</a><a href="#L141" id="L141" rel="#L141"><i class='fa fa-link'></i>
141
</a><a href="#L142" id="L142" rel="#L142"><i class='fa fa-link'></i>
142
</a><a href="#L143" id="L143" rel="#L143"><i class='fa fa-link'></i>
143
</a><a href="#L144" id="L144" rel="#L144"><i class='fa fa-link'></i>
144
</a><a href="#L145" id="L145" rel="#L145"><i class='fa fa-link'></i>
145
</a><a href="#L146" id="L146" rel="#L146"><i class='fa fa-link'></i>
146
</a><a href="#L147" id="L147" rel="#L147"><i class='fa fa-link'></i>
147
</a><a href="#L148" id="L148" rel="#L148"><i class='fa fa-link'></i>
148
</a><a href="#L149" id="L149" rel="#L149"><i class='fa fa-link'></i>
149
</a><a href="#L150" id="L150" rel="#L150"><i class='fa fa-link'></i>
150
</a><a href="#L151" id="L151" rel="#L151"><i class='fa fa-link'></i>
151
</a><a href="#L152" id="L152" rel="#L152"><i class='fa fa-link'></i>
152
</a><a href="#L153" id="L153" rel="#L153"><i class='fa fa-link'></i>
153
</a><a href="#L154" id="L154" rel="#L154"><i class='fa fa-link'></i>
154
</a><a href="#L155" id="L155" rel="#L155"><i class='fa fa-link'></i>
155
</a><a href="#L156" id="L156" rel="#L156"><i class='fa fa-link'></i>
156
</a><a href="#L157" id="L157" rel="#L157"><i class='fa fa-link'></i>
157
</a><a href="#L158" id="L158" rel="#L158"><i class='fa fa-link'></i>
158
</a><a href="#L159" id="L159" rel="#L159"><i class='fa fa-link'></i>
159
</a><a href="#L160" id="L160" rel="#L160"><i class='fa fa-link'></i>
160
</a><a href="#L161" id="L161" rel="#L161"><i class='fa fa-link'></i>
161
</a><a href="#L162" id="L162" rel="#L162"><i class='fa fa-link'></i>
162
</a><a href="#L163" id="L163" rel="#L163"><i class='fa fa-link'></i>
163
</a><a href="#L164" id="L164" rel="#L164"><i class='fa fa-link'></i>
164
</a><a href="#L165" id="L165" rel="#L165"><i class='fa fa-link'></i>
165
</a><a href="#L166" id="L166" rel="#L166"><i class='fa fa-link'></i>
166
</a><a href="#L167" id="L167" rel="#L167"><i class='fa fa-link'></i>
167
</a><a href="#L168" id="L168" rel="#L168"><i class='fa fa-link'></i>
168
</a><a href="#L169" id="L169" rel="#L169"><i class='fa fa-link'></i>
169
</a><a href="#L170" id="L170" rel="#L170"><i class='fa fa-link'></i>
170
</a><a href="#L171" id="L171" rel="#L171"><i class='fa fa-link'></i>
171
</a><a href="#L172" id="L172" rel="#L172"><i class='fa fa-link'></i>
172
</a><a href="#L173" id="L173" rel="#L173"><i class='fa fa-link'></i>
173
</a><a href="#L174" id="L174" rel="#L174"><i class='fa fa-link'></i>
174
</a><a href="#L175" id="L175" rel="#L175"><i class='fa fa-link'></i>
175
</a><a href="#L176" id="L176" rel="#L176"><i class='fa fa-link'></i>
176
</a><a href="#L177" id="L177" rel="#L177"><i class='fa fa-link'></i>
177
</a><a href="#L178" id="L178" rel="#L178"><i class='fa fa-link'></i>
178
</a><a href="#L179" id="L179" rel="#L179"><i class='fa fa-link'></i>
179
</a><a href="#L180" id="L180" rel="#L180"><i class='fa fa-link'></i>
180
</a><a href="#L181" id="L181" rel="#L181"><i class='fa fa-link'></i>
181
</a><a href="#L182" id="L182" rel="#L182"><i class='fa fa-link'></i>
182
</a><a href="#L183" id="L183" rel="#L183"><i class='fa fa-link'></i>
183
</a><a href="#L184" id="L184" rel="#L184"><i class='fa fa-link'></i>
184
</a><a href="#L185" id="L185" rel="#L185"><i class='fa fa-link'></i>
185
</a><a href="#L186" id="L186" rel="#L186"><i class='fa fa-link'></i>
186
</a><a href="#L187" id="L187" rel="#L187"><i class='fa fa-link'></i>
187
</a><a href="#L188" id="L188" rel="#L188"><i class='fa fa-link'></i>
188
</a><a href="#L189" id="L189" rel="#L189"><i class='fa fa-link'></i>
189
</a><a href="#L190" id="L190" rel="#L190"><i class='fa fa-link'></i>
190
</a><a href="#L191" id="L191" rel="#L191"><i class='fa fa-link'></i>
191
</a><a href="#L192" id="L192" rel="#L192"><i class='fa fa-link'></i>
192
</a><a href="#L193" id="L193" rel="#L193"><i class='fa fa-link'></i>
193
</a><a href="#L194" id="L194" rel="#L194"><i class='fa fa-link'></i>
194
</a><a href="#L195" id="L195" rel="#L195"><i class='fa fa-link'></i>
195
</a><a href="#L196" id="L196" rel="#L196"><i class='fa fa-link'></i>
196
</a><a href="#L197" id="L197" rel="#L197"><i class='fa fa-link'></i>
197
</a><a href="#L198" id="L198" rel="#L198"><i class='fa fa-link'></i>
198
</a><a href="#L199" id="L199" rel="#L199"><i class='fa fa-link'></i>
199
</a><a href="#L200" id="L200" rel="#L200"><i class='fa fa-link'></i>
200
</a><a href="#L201" id="L201" rel="#L201"><i class='fa fa-link'></i>
201
</a><a href="#L202" id="L202" rel="#L202"><i class='fa fa-link'></i>
202
</a><a href="#L203" id="L203" rel="#L203"><i class='fa fa-link'></i>
203
</a><a href="#L204" id="L204" rel="#L204"><i class='fa fa-link'></i>
204
</a><a href="#L205" id="L205" rel="#L205"><i class='fa fa-link'></i>
205
</a><a href="#L206" id="L206" rel="#L206"><i class='fa fa-link'></i>
206
</a><a href="#L207" id="L207" rel="#L207"><i class='fa fa-link'></i>
207
</a><a href="#L208" id="L208" rel="#L208"><i class='fa fa-link'></i>
208
</a><a href="#L209" id="L209" rel="#L209"><i class='fa fa-link'></i>
209
</a><a href="#L210" id="L210" rel="#L210"><i class='fa fa-link'></i>
210
</a><a href="#L211" id="L211" rel="#L211"><i class='fa fa-link'></i>
211
</a><a href="#L212" id="L212" rel="#L212"><i class='fa fa-link'></i>
212
</a><a href="#L213" id="L213" rel="#L213"><i class='fa fa-link'></i>
213
</a><a href="#L214" id="L214" rel="#L214"><i class='fa fa-link'></i>
214
</a><a href="#L215" id="L215" rel="#L215"><i class='fa fa-link'></i>
215
</a><a href="#L216" id="L216" rel="#L216"><i class='fa fa-link'></i>
216
</a><a href="#L217" id="L217" rel="#L217"><i class='fa fa-link'></i>
217
</a><a href="#L218" id="L218" rel="#L218"><i class='fa fa-link'></i>
218
</a><a href="#L219" id="L219" rel="#L219"><i class='fa fa-link'></i>
219
</a><a href="#L220" id="L220" rel="#L220"><i class='fa fa-link'></i>
220
</a><a href="#L221" id="L221" rel="#L221"><i class='fa fa-link'></i>
221
</a><a href="#L222" id="L222" rel="#L222"><i class='fa fa-link'></i>
222
</a><a href="#L223" id="L223" rel="#L223"><i class='fa fa-link'></i>
223
</a><a href="#L224" id="L224" rel="#L224"><i class='fa fa-link'></i>
224
</a><a href="#L225" id="L225" rel="#L225"><i class='fa fa-link'></i>
225
</a><a href="#L226" id="L226" rel="#L226"><i class='fa fa-link'></i>
226
</a><a href="#L227" id="L227" rel="#L227"><i class='fa fa-link'></i>
227
</a><a href="#L228" id="L228" rel="#L228"><i class='fa fa-link'></i>
228
</a><a href="#L229" id="L229" rel="#L229"><i class='fa fa-link'></i>
229
</a><a href="#L230" id="L230" rel="#L230"><i class='fa fa-link'></i>
230
</a><a href="#L231" id="L231" rel="#L231"><i class='fa fa-link'></i>
231
</a><a href="#L232" id="L232" rel="#L232"><i class='fa fa-link'></i>
232
</a><a href="#L233" id="L233" rel="#L233"><i class='fa fa-link'></i>
233
</a><a href="#L234" id="L234" rel="#L234"><i class='fa fa-link'></i>
234
</a><a href="#L235" id="L235" rel="#L235"><i class='fa fa-link'></i>
235
</a><a href="#L236" id="L236" rel="#L236"><i class='fa fa-link'></i>
236
</a><a href="#L237" id="L237" rel="#L237"><i class='fa fa-link'></i>
237
</a><a href="#L238" id="L238" rel="#L238"><i class='fa fa-link'></i>
238
</a><a href="#L239" id="L239" rel="#L239"><i class='fa fa-link'></i>
239
</a><a href="#L240" id="L240" rel="#L240"><i class='fa fa-link'></i>
240
</a><a href="#L241" id="L241" rel="#L241"><i class='fa fa-link'></i>
241
</a><a href="#L242" id="L242" rel="#L242"><i class='fa fa-link'></i>
242
</a><a href="#L243" id="L243" rel="#L243"><i class='fa fa-link'></i>
243
</a><a href="#L244" id="L244" rel="#L244"><i class='fa fa-link'></i>
244
</a><a href="#L245" id="L245" rel="#L245"><i class='fa fa-link'></i>
245
</a><a href="#L246" id="L246" rel="#L246"><i class='fa fa-link'></i>
246
</a><a href="#L247" id="L247" rel="#L247"><i class='fa fa-link'></i>
247
</a><a href="#L248" id="L248" rel="#L248"><i class='fa fa-link'></i>
248
</a><a href="#L249" id="L249" rel="#L249"><i class='fa fa-link'></i>
249
</a><a href="#L250" id="L250" rel="#L250"><i class='fa fa-link'></i>
250
</a><a href="#L251" id="L251" rel="#L251"><i class='fa fa-link'></i>
251
</a><a href="#L252" id="L252" rel="#L252"><i class='fa fa-link'></i>
252
</a><a href="#L253" id="L253" rel="#L253"><i class='fa fa-link'></i>
253
</a><a href="#L254" id="L254" rel="#L254"><i class='fa fa-link'></i>
254
</a><a href="#L255" id="L255" rel="#L255"><i class='fa fa-link'></i>
255
</a><a href="#L256" id="L256" rel="#L256"><i class='fa fa-link'></i>
256
</a><a href="#L257" id="L257" rel="#L257"><i class='fa fa-link'></i>
257
</a><a href="#L258" id="L258" rel="#L258"><i class='fa fa-link'></i>
258
</a><a href="#L259" id="L259" rel="#L259"><i class='fa fa-link'></i>
259
</a><a href="#L260" id="L260" rel="#L260"><i class='fa fa-link'></i>
260
</a><a href="#L261" id="L261" rel="#L261"><i class='fa fa-link'></i>
261
</a><a href="#L262" id="L262" rel="#L262"><i class='fa fa-link'></i>
262
</a><a href="#L263" id="L263" rel="#L263"><i class='fa fa-link'></i>
263
</a><a href="#L264" id="L264" rel="#L264"><i class='fa fa-link'></i>
264
</a><a href="#L265" id="L265" rel="#L265"><i class='fa fa-link'></i>
265
</a><a href="#L266" id="L266" rel="#L266"><i class='fa fa-link'></i>
266
</a><a href="#L267" id="L267" rel="#L267"><i class='fa fa-link'></i>
267
</a><a href="#L268" id="L268" rel="#L268"><i class='fa fa-link'></i>
268
</a><a href="#L269" id="L269" rel="#L269"><i class='fa fa-link'></i>
269
</a><a href="#L270" id="L270" rel="#L270"><i class='fa fa-link'></i>
270
</a><a href="#L271" id="L271" rel="#L271"><i class='fa fa-link'></i>
271
</a><a href="#L272" id="L272" rel="#L272"><i class='fa fa-link'></i>
272
</a><a href="#L273" id="L273" rel="#L273"><i class='fa fa-link'></i>
273
</a><a href="#L274" id="L274" rel="#L274"><i class='fa fa-link'></i>
274
</a><a href="#L275" id="L275" rel="#L275"><i class='fa fa-link'></i>
275
</a><a href="#L276" id="L276" rel="#L276"><i class='fa fa-link'></i>
276
</a><a href="#L277" id="L277" rel="#L277"><i class='fa fa-link'></i>
277
</a><a href="#L278" id="L278" rel="#L278"><i class='fa fa-link'></i>
278
</a><a href="#L279" id="L279" rel="#L279"><i class='fa fa-link'></i>
279
</a><a href="#L280" id="L280" rel="#L280"><i class='fa fa-link'></i>
280
</a><a href="#L281" id="L281" rel="#L281"><i class='fa fa-link'></i>
281
</a><a href="#L282" id="L282" rel="#L282"><i class='fa fa-link'></i>
282
</a><a href="#L283" id="L283" rel="#L283"><i class='fa fa-link'></i>
283
</a><a href="#L284" id="L284" rel="#L284"><i class='fa fa-link'></i>
284
</a><a href="#L285" id="L285" rel="#L285"><i class='fa fa-link'></i>
285
</a><a href="#L286" id="L286" rel="#L286"><i class='fa fa-link'></i>
286
</a><a href="#L287" id="L287" rel="#L287"><i class='fa fa-link'></i>
287
</a><a href="#L288" id="L288" rel="#L288"><i class='fa fa-link'></i>
288
</a><a href="#L289" id="L289" rel="#L289"><i class='fa fa-link'></i>
289
</a><a href="#L290" id="L290" rel="#L290"><i class='fa fa-link'></i>
290
</a><a href="#L291" id="L291" rel="#L291"><i class='fa fa-link'></i>
291
</a><a href="#L292" id="L292" rel="#L292"><i class='fa fa-link'></i>
292
</a><a href="#L293" id="L293" rel="#L293"><i class='fa fa-link'></i>
293
</a><a href="#L294" id="L294" rel="#L294"><i class='fa fa-link'></i>
294
</a><a href="#L295" id="L295" rel="#L295"><i class='fa fa-link'></i>
295
</a><a href="#L296" id="L296" rel="#L296"><i class='fa fa-link'></i>
296
</a><a href="#L297" id="L297" rel="#L297"><i class='fa fa-link'></i>
297
</a><a href="#L298" id="L298" rel="#L298"><i class='fa fa-link'></i>
298
</a><a href="#L299" id="L299" rel="#L299"><i class='fa fa-link'></i>
299
</a><a href="#L300" id="L300" rel="#L300"><i class='fa fa-link'></i>
300
</a><a href="#L301" id="L301" rel="#L301"><i class='fa fa-link'></i>
301
</a><a href="#L302" id="L302" rel="#L302"><i class='fa fa-link'></i>
302
</a><a href="#L303" id="L303" rel="#L303"><i class='fa fa-link'></i>
303
</a><a href="#L304" id="L304" rel="#L304"><i class='fa fa-link'></i>
304
</a><a href="#L305" id="L305" rel="#L305"><i class='fa fa-link'></i>
305
</a><a href="#L306" id="L306" rel="#L306"><i class='fa fa-link'></i>
306
</a><a href="#L307" id="L307" rel="#L307"><i class='fa fa-link'></i>
307
</a><a href="#L308" id="L308" rel="#L308"><i class='fa fa-link'></i>
308
</a><a href="#L309" id="L309" rel="#L309"><i class='fa fa-link'></i>
309
</a><a href="#L310" id="L310" rel="#L310"><i class='fa fa-link'></i>
310
</a><a href="#L311" id="L311" rel="#L311"><i class='fa fa-link'></i>
311
</a><a href="#L312" id="L312" rel="#L312"><i class='fa fa-link'></i>
312
</a><a href="#L313" id="L313" rel="#L313"><i class='fa fa-link'></i>
313
</a><a href="#L314" id="L314" rel="#L314"><i class='fa fa-link'></i>
314
</a><a href="#L315" id="L315" rel="#L315"><i class='fa fa-link'></i>
315
</a><a href="#L316" id="L316" rel="#L316"><i class='fa fa-link'></i>
316
</a><a href="#L317" id="L317" rel="#L317"><i class='fa fa-link'></i>
317
</a><a href="#L318" id="L318" rel="#L318"><i class='fa fa-link'></i>
318
</a><a href="#L319" id="L319" rel="#L319"><i class='fa fa-link'></i>
319
</a><a href="#L320" id="L320" rel="#L320"><i class='fa fa-link'></i>
320
</a><a href="#L321" id="L321" rel="#L321"><i class='fa fa-link'></i>
321
</a><a href="#L322" id="L322" rel="#L322"><i class='fa fa-link'></i>
322
</a><a href="#L323" id="L323" rel="#L323"><i class='fa fa-link'></i>
323
</a><a href="#L324" id="L324" rel="#L324"><i class='fa fa-link'></i>
324
</a><a href="#L325" id="L325" rel="#L325"><i class='fa fa-link'></i>
325
</a><a href="#L326" id="L326" rel="#L326"><i class='fa fa-link'></i>
326
</a><a href="#L327" id="L327" rel="#L327"><i class='fa fa-link'></i>
327
</a><a href="#L328" id="L328" rel="#L328"><i class='fa fa-link'></i>
328
</a><a href="#L329" id="L329" rel="#L329"><i class='fa fa-link'></i>
329
</a><a href="#L330" id="L330" rel="#L330"><i class='fa fa-link'></i>
330
</a><a href="#L331" id="L331" rel="#L331"><i class='fa fa-link'></i>
331
</a><a href="#L332" id="L332" rel="#L332"><i class='fa fa-link'></i>
332
</a><a href="#L333" id="L333" rel="#L333"><i class='fa fa-link'></i>
333
</a><a href="#L334" id="L334" rel="#L334"><i class='fa fa-link'></i>
334
</a><a href="#L335" id="L335" rel="#L335"><i class='fa fa-link'></i>
335
</a><a href="#L336" id="L336" rel="#L336"><i class='fa fa-link'></i>
336
</a><a href="#L337" id="L337" rel="#L337"><i class='fa fa-link'></i>
337
</a><a href="#L338" id="L338" rel="#L338"><i class='fa fa-link'></i>
338
</a><a href="#L339" id="L339" rel="#L339"><i class='fa fa-link'></i>
339
</a><a href="#L340" id="L340" rel="#L340"><i class='fa fa-link'></i>
340
</a><a href="#L341" id="L341" rel="#L341"><i class='fa fa-link'></i>
341
</a><a href="#L342" id="L342" rel="#L342"><i class='fa fa-link'></i>
342
</a><a href="#L343" id="L343" rel="#L343"><i class='fa fa-link'></i>
343
</a><a href="#L344" id="L344" rel="#L344"><i class='fa fa-link'></i>
344
</a><a href="#L345" id="L345" rel="#L345"><i class='fa fa-link'></i>
345
</a><a href="#L346" id="L346" rel="#L346"><i class='fa fa-link'></i>
346
</a><a href="#L347" id="L347" rel="#L347"><i class='fa fa-link'></i>
347
</a><a href="#L348" id="L348" rel="#L348"><i class='fa fa-link'></i>
348
</a><a href="#L349" id="L349" rel="#L349"><i class='fa fa-link'></i>
349
</a><a href="#L350" id="L350" rel="#L350"><i class='fa fa-link'></i>
350
</a><a href="#L351" id="L351" rel="#L351"><i class='fa fa-link'></i>
351
</a><a href="#L352" id="L352" rel="#L352"><i class='fa fa-link'></i>
352
</a><a href="#L353" id="L353" rel="#L353"><i class='fa fa-link'></i>
353
</a><a href="#L354" id="L354" rel="#L354"><i class='fa fa-link'></i>
354
</a><a href="#L355" id="L355" rel="#L355"><i class='fa fa-link'></i>
355
</a><a href="#L356" id="L356" rel="#L356"><i class='fa fa-link'></i>
356
</a><a href="#L357" id="L357" rel="#L357"><i class='fa fa-link'></i>
357
</a><a href="#L358" id="L358" rel="#L358"><i class='fa fa-link'></i>
358
</a><a href="#L359" id="L359" rel="#L359"><i class='fa fa-link'></i>
359
</a><a href="#L360" id="L360" rel="#L360"><i class='fa fa-link'></i>
360
</a><a href="#L361" id="L361" rel="#L361"><i class='fa fa-link'></i>
361
</a><a href="#L362" id="L362" rel="#L362"><i class='fa fa-link'></i>
362
</a><a href="#L363" id="L363" rel="#L363"><i class='fa fa-link'></i>
363
</a><a href="#L364" id="L364" rel="#L364"><i class='fa fa-link'></i>
364
</a><a href="#L365" id="L365" rel="#L365"><i class='fa fa-link'></i>
365
</a><a href="#L366" id="L366" rel="#L366"><i class='fa fa-link'></i>
366
</a><a href="#L367" id="L367" rel="#L367"><i class='fa fa-link'></i>
367
</a><a href="#L368" id="L368" rel="#L368"><i class='fa fa-link'></i>
368
</a><a href="#L369" id="L369" rel="#L369"><i class='fa fa-link'></i>
369
</a><a href="#L370" id="L370" rel="#L370"><i class='fa fa-link'></i>
370
</a><a href="#L371" id="L371" rel="#L371"><i class='fa fa-link'></i>
371
</a><a href="#L372" id="L372" rel="#L372"><i class='fa fa-link'></i>
372
</a><a href="#L373" id="L373" rel="#L373"><i class='fa fa-link'></i>
373
</a><a href="#L374" id="L374" rel="#L374"><i class='fa fa-link'></i>
374
</a><a href="#L375" id="L375" rel="#L375"><i class='fa fa-link'></i>
375
</a><a href="#L376" id="L376" rel="#L376"><i class='fa fa-link'></i>
376
</a><a href="#L377" id="L377" rel="#L377"><i class='fa fa-link'></i>
377
</a><a href="#L378" id="L378" rel="#L378"><i class='fa fa-link'></i>
378
</a><a href="#L379" id="L379" rel="#L379"><i class='fa fa-link'></i>
379
</a><a href="#L380" id="L380" rel="#L380"><i class='fa fa-link'></i>
380
</a><a href="#L381" id="L381" rel="#L381"><i class='fa fa-link'></i>
381
</a><a href="#L382" id="L382" rel="#L382"><i class='fa fa-link'></i>
382
</a><a href="#L383" id="L383" rel="#L383"><i class='fa fa-link'></i>
383
</a><a href="#L384" id="L384" rel="#L384"><i class='fa fa-link'></i>
384
</a><a href="#L385" id="L385" rel="#L385"><i class='fa fa-link'></i>
385
</a><a href="#L386" id="L386" rel="#L386"><i class='fa fa-link'></i>
386
</a><a href="#L387" id="L387" rel="#L387"><i class='fa fa-link'></i>
387
</a><a href="#L388" id="L388" rel="#L388"><i class='fa fa-link'></i>
388
</a><a href="#L389" id="L389" rel="#L389"><i class='fa fa-link'></i>
389
</a><a href="#L390" id="L390" rel="#L390"><i class='fa fa-link'></i>
390
</a><a href="#L391" id="L391" rel="#L391"><i class='fa fa-link'></i>
391
</a><a href="#L392" id="L392" rel="#L392"><i class='fa fa-link'></i>
392
</a><a href="#L393" id="L393" rel="#L393"><i class='fa fa-link'></i>
393
</a><a href="#L394" id="L394" rel="#L394"><i class='fa fa-link'></i>
394
</a><a href="#L395" id="L395" rel="#L395"><i class='fa fa-link'></i>
395
</a><a href="#L396" id="L396" rel="#L396"><i class='fa fa-link'></i>
396
</a><a href="#L397" id="L397" rel="#L397"><i class='fa fa-link'></i>
397
</a><a href="#L398" id="L398" rel="#L398"><i class='fa fa-link'></i>
398
</a><a href="#L399" id="L399" rel="#L399"><i class='fa fa-link'></i>
399
</a><a href="#L400" id="L400" rel="#L400"><i class='fa fa-link'></i>
400
</a><a href="#L401" id="L401" rel="#L401"><i class='fa fa-link'></i>
401
</a><a href="#L402" id="L402" rel="#L402"><i class='fa fa-link'></i>
402
</a><a href="#L403" id="L403" rel="#L403"><i class='fa fa-link'></i>
403
</a><a href="#L404" id="L404" rel="#L404"><i class='fa fa-link'></i>
404
</a><a href="#L405" id="L405" rel="#L405"><i class='fa fa-link'></i>
405
</a><a href="#L406" id="L406" rel="#L406"><i class='fa fa-link'></i>
406
</a><a href="#L407" id="L407" rel="#L407"><i class='fa fa-link'></i>
407
</a><a href="#L408" id="L408" rel="#L408"><i class='fa fa-link'></i>
408
</a><a href="#L409" id="L409" rel="#L409"><i class='fa fa-link'></i>
409
</a><a href="#L410" id="L410" rel="#L410"><i class='fa fa-link'></i>
410
</a><a href="#L411" id="L411" rel="#L411"><i class='fa fa-link'></i>
411
</a><a href="#L412" id="L412" rel="#L412"><i class='fa fa-link'></i>
412
</a><a href="#L413" id="L413" rel="#L413"><i class='fa fa-link'></i>
413
</a><a href="#L414" id="L414" rel="#L414"><i class='fa fa-link'></i>
414
</a><a href="#L415" id="L415" rel="#L415"><i class='fa fa-link'></i>
415
</a><a href="#L416" id="L416" rel="#L416"><i class='fa fa-link'></i>
416
</a><a href="#L417" id="L417" rel="#L417"><i class='fa fa-link'></i>
417
</a><a href="#L418" id="L418" rel="#L418"><i class='fa fa-link'></i>
418
</a><a href="#L419" id="L419" rel="#L419"><i class='fa fa-link'></i>
419
</a><a href="#L420" id="L420" rel="#L420"><i class='fa fa-link'></i>
420
</a><a href="#L421" id="L421" rel="#L421"><i class='fa fa-link'></i>
421
</a><a href="#L422" id="L422" rel="#L422"><i class='fa fa-link'></i>
422
</a><a href="#L423" id="L423" rel="#L423"><i class='fa fa-link'></i>
423
</a><a href="#L424" id="L424" rel="#L424"><i class='fa fa-link'></i>
424
</a><a href="#L425" id="L425" rel="#L425"><i class='fa fa-link'></i>
425
</a><a href="#L426" id="L426" rel="#L426"><i class='fa fa-link'></i>
426
</a><a href="#L427" id="L427" rel="#L427"><i class='fa fa-link'></i>
427
</a><a href="#L428" id="L428" rel="#L428"><i class='fa fa-link'></i>
428
</a><a href="#L429" id="L429" rel="#L429"><i class='fa fa-link'></i>
429
</a><a href="#L430" id="L430" rel="#L430"><i class='fa fa-link'></i>
430
</a><a href="#L431" id="L431" rel="#L431"><i class='fa fa-link'></i>
431
</a><a href="#L432" id="L432" rel="#L432"><i class='fa fa-link'></i>
432
</a><a href="#L433" id="L433" rel="#L433"><i class='fa fa-link'></i>
433
</a><a href="#L434" id="L434" rel="#L434"><i class='fa fa-link'></i>
434
</a><a href="#L435" id="L435" rel="#L435"><i class='fa fa-link'></i>
435
</a><a href="#L436" id="L436" rel="#L436"><i class='fa fa-link'></i>
436
</a><a href="#L437" id="L437" rel="#L437"><i class='fa fa-link'></i>
437
</a><a href="#L438" id="L438" rel="#L438"><i class='fa fa-link'></i>
438
</a><a href="#L439" id="L439" rel="#L439"><i class='fa fa-link'></i>
439
</a><a href="#L440" id="L440" rel="#L440"><i class='fa fa-link'></i>
440
</a><a href="#L441" id="L441" rel="#L441"><i class='fa fa-link'></i>
441
</a><a href="#L442" id="L442" rel="#L442"><i class='fa fa-link'></i>
442
</a><a href="#L443" id="L443" rel="#L443"><i class='fa fa-link'></i>
443
</a><a href="#L444" id="L444" rel="#L444"><i class='fa fa-link'></i>
444
</a><a href="#L445" id="L445" rel="#L445"><i class='fa fa-link'></i>
445
</a><a href="#L446" id="L446" rel="#L446"><i class='fa fa-link'></i>
446
</a><a href="#L447" id="L447" rel="#L447"><i class='fa fa-link'></i>
447
</a><a href="#L448" id="L448" rel="#L448"><i class='fa fa-link'></i>
448
</a><a href="#L449" id="L449" rel="#L449"><i class='fa fa-link'></i>
449
</a><a href="#L450" id="L450" rel="#L450"><i class='fa fa-link'></i>
450
</a><a href="#L451" id="L451" rel="#L451"><i class='fa fa-link'></i>
451
</a><a href="#L452" id="L452" rel="#L452"><i class='fa fa-link'></i>
452
</a><a href="#L453" id="L453" rel="#L453"><i class='fa fa-link'></i>
453
</a><a href="#L454" id="L454" rel="#L454"><i class='fa fa-link'></i>
454
</a><a href="#L455" id="L455" rel="#L455"><i class='fa fa-link'></i>
455
</a><a href="#L456" id="L456" rel="#L456"><i class='fa fa-link'></i>
456
</a><a href="#L457" id="L457" rel="#L457"><i class='fa fa-link'></i>
457
</a><a href="#L458" id="L458" rel="#L458"><i class='fa fa-link'></i>
458
</a><a href="#L459" id="L459" rel="#L459"><i class='fa fa-link'></i>
459
</a><a href="#L460" id="L460" rel="#L460"><i class='fa fa-link'></i>
460
</a><a href="#L461" id="L461" rel="#L461"><i class='fa fa-link'></i>
461
</a><a href="#L462" id="L462" rel="#L462"><i class='fa fa-link'></i>
462
</a><a href="#L463" id="L463" rel="#L463"><i class='fa fa-link'></i>
463
</a><a href="#L464" id="L464" rel="#L464"><i class='fa fa-link'></i>
464
</a><a href="#L465" id="L465" rel="#L465"><i class='fa fa-link'></i>
465
</a><a href="#L466" id="L466" rel="#L466"><i class='fa fa-link'></i>
466
</a><a href="#L467" id="L467" rel="#L467"><i class='fa fa-link'></i>
467
</a><a href="#L468" id="L468" rel="#L468"><i class='fa fa-link'></i>
468
</a><a href="#L469" id="L469" rel="#L469"><i class='fa fa-link'></i>
469
</a><a href="#L470" id="L470" rel="#L470"><i class='fa fa-link'></i>
470
</a><a href="#L471" id="L471" rel="#L471"><i class='fa fa-link'></i>
471
</a><a href="#L472" id="L472" rel="#L472"><i class='fa fa-link'></i>
472
</a><a href="#L473" id="L473" rel="#L473"><i class='fa fa-link'></i>
473
</a><a href="#L474" id="L474" rel="#L474"><i class='fa fa-link'></i>
474
</a><a href="#L475" id="L475" rel="#L475"><i class='fa fa-link'></i>
475
</a><a href="#L476" id="L476" rel="#L476"><i class='fa fa-link'></i>
476
</a><a href="#L477" id="L477" rel="#L477"><i class='fa fa-link'></i>
477
</a><a href="#L478" id="L478" rel="#L478"><i class='fa fa-link'></i>
478
</a><a href="#L479" id="L479" rel="#L479"><i class='fa fa-link'></i>
479
</a><a href="#L480" id="L480" rel="#L480"><i class='fa fa-link'></i>
480
</a><a href="#L481" id="L481" rel="#L481"><i class='fa fa-link'></i>
481
</a><a href="#L482" id="L482" rel="#L482"><i class='fa fa-link'></i>
482
</a><a href="#L483" id="L483" rel="#L483"><i class='fa fa-link'></i>
483
</a><a href="#L484" id="L484" rel="#L484"><i class='fa fa-link'></i>
484
</a><a href="#L485" id="L485" rel="#L485"><i class='fa fa-link'></i>
485
</a><a href="#L486" id="L486" rel="#L486"><i class='fa fa-link'></i>
486
</a><a href="#L487" id="L487" rel="#L487"><i class='fa fa-link'></i>
487
</a><a href="#L488" id="L488" rel="#L488"><i class='fa fa-link'></i>
488
</a><a href="#L489" id="L489" rel="#L489"><i class='fa fa-link'></i>
489
</a><a href="#L490" id="L490" rel="#L490"><i class='fa fa-link'></i>
490
</a><a href="#L491" id="L491" rel="#L491"><i class='fa fa-link'></i>
491
</a><a href="#L492" id="L492" rel="#L492"><i class='fa fa-link'></i>
492
</a><a href="#L493" id="L493" rel="#L493"><i class='fa fa-link'></i>
493
</a><a href="#L494" id="L494" rel="#L494"><i class='fa fa-link'></i>
494
</a><a href="#L495" id="L495" rel="#L495"><i class='fa fa-link'></i>
495
</a><a href="#L496" id="L496" rel="#L496"><i class='fa fa-link'></i>
496
</a><a href="#L497" id="L497" rel="#L497"><i class='fa fa-link'></i>
497
</a><a href="#L498" id="L498" rel="#L498"><i class='fa fa-link'></i>
498
</a><a href="#L499" id="L499" rel="#L499"><i class='fa fa-link'></i>
499
</a><a href="#L500" id="L500" rel="#L500"><i class='fa fa-link'></i>
500
</a><a href="#L501" id="L501" rel="#L501"><i class='fa fa-link'></i>
501
</a><a href="#L502" id="L502" rel="#L502"><i class='fa fa-link'></i>
502
</a><a href="#L503" id="L503" rel="#L503"><i class='fa fa-link'></i>
503
</a><a href="#L504" id="L504" rel="#L504"><i class='fa fa-link'></i>
504
</a><a href="#L505" id="L505" rel="#L505"><i class='fa fa-link'></i>
505
</a><a href="#L506" id="L506" rel="#L506"><i class='fa fa-link'></i>
506
</a><a href="#L507" id="L507" rel="#L507"><i class='fa fa-link'></i>
507
</a><a href="#L508" id="L508" rel="#L508"><i class='fa fa-link'></i>
508
</a><a href="#L509" id="L509" rel="#L509"><i class='fa fa-link'></i>
509
</a><a href="#L510" id="L510" rel="#L510"><i class='fa fa-link'></i>
510
</a><a href="#L511" id="L511" rel="#L511"><i class='fa fa-link'></i>
511
</a><a href="#L512" id="L512" rel="#L512"><i class='fa fa-link'></i>
512
</a><a href="#L513" id="L513" rel="#L513"><i class='fa fa-link'></i>
513
</a><a href="#L514" id="L514" rel="#L514"><i class='fa fa-link'></i>
514
</a><a href="#L515" id="L515" rel="#L515"><i class='fa fa-link'></i>
515
</a><a href="#L516" id="L516" rel="#L516"><i class='fa fa-link'></i>
516
</a><a href="#L517" id="L517" rel="#L517"><i class='fa fa-link'></i>
517
</a><a href="#L518" id="L518" rel="#L518"><i class='fa fa-link'></i>
518
</a><a href="#L519" id="L519" rel="#L519"><i class='fa fa-link'></i>
519
</a><a href="#L520" id="L520" rel="#L520"><i class='fa fa-link'></i>
520
</a><a href="#L521" id="L521" rel="#L521"><i class='fa fa-link'></i>
521
</a><a href="#L522" id="L522" rel="#L522"><i class='fa fa-link'></i>
522
</a><a href="#L523" id="L523" rel="#L523"><i class='fa fa-link'></i>
523
</a><a href="#L524" id="L524" rel="#L524"><i class='fa fa-link'></i>
524
</a><a href="#L525" id="L525" rel="#L525"><i class='fa fa-link'></i>
525
</a><a href="#L526" id="L526" rel="#L526"><i class='fa fa-link'></i>
526
</a><a href="#L527" id="L527" rel="#L527"><i class='fa fa-link'></i>
527
</a><a href="#L528" id="L528" rel="#L528"><i class='fa fa-link'></i>
528
</a><a href="#L529" id="L529" rel="#L529"><i class='fa fa-link'></i>
529
</a><a href="#L530" id="L530" rel="#L530"><i class='fa fa-link'></i>
530
</a><a href="#L531" id="L531" rel="#L531"><i class='fa fa-link'></i>
531
</a><a href="#L532" id="L532" rel="#L532"><i class='fa fa-link'></i>
532
</a><a href="#L533" id="L533" rel="#L533"><i class='fa fa-link'></i>
533
</a><a href="#L534" id="L534" rel="#L534"><i class='fa fa-link'></i>
534
</a><a href="#L535" id="L535" rel="#L535"><i class='fa fa-link'></i>
535
</a><a href="#L536" id="L536" rel="#L536"><i class='fa fa-link'></i>
536
</a><a href="#L537" id="L537" rel="#L537"><i class='fa fa-link'></i>
537
</a><a href="#L538" id="L538" rel="#L538"><i class='fa fa-link'></i>
538
</a><a href="#L539" id="L539" rel="#L539"><i class='fa fa-link'></i>
539
</a><a href="#L540" id="L540" rel="#L540"><i class='fa fa-link'></i>
540
</a><a href="#L541" id="L541" rel="#L541"><i class='fa fa-link'></i>
541
</a><a href="#L542" id="L542" rel="#L542"><i class='fa fa-link'></i>
542
</a><a href="#L543" id="L543" rel="#L543"><i class='fa fa-link'></i>
543
</a><a href="#L544" id="L544" rel="#L544"><i class='fa fa-link'></i>
544
</a><a href="#L545" id="L545" rel="#L545"><i class='fa fa-link'></i>
545
</a><a href="#L546" id="L546" rel="#L546"><i class='fa fa-link'></i>
546
</a><a href="#L547" id="L547" rel="#L547"><i class='fa fa-link'></i>
547
</a><a href="#L548" id="L548" rel="#L548"><i class='fa fa-link'></i>
548
</a><a href="#L549" id="L549" rel="#L549"><i class='fa fa-link'></i>
549
</a><a href="#L550" id="L550" rel="#L550"><i class='fa fa-link'></i>
550
</a><a href="#L551" id="L551" rel="#L551"><i class='fa fa-link'></i>
551
</a><a href="#L552" id="L552" rel="#L552"><i class='fa fa-link'></i>
552
</a><a href="#L553" id="L553" rel="#L553"><i class='fa fa-link'></i>
553
</a><a href="#L554" id="L554" rel="#L554"><i class='fa fa-link'></i>
554
</a><a href="#L555" id="L555" rel="#L555"><i class='fa fa-link'></i>
555
</a><a href="#L556" id="L556" rel="#L556"><i class='fa fa-link'></i>
556
</a><a href="#L557" id="L557" rel="#L557"><i class='fa fa-link'></i>
557
</a><a href="#L558" id="L558" rel="#L558"><i class='fa fa-link'></i>
558
</a><a href="#L559" id="L559" rel="#L559"><i class='fa fa-link'></i>
559
</a><a href="#L560" id="L560" rel="#L560"><i class='fa fa-link'></i>
560
</a><a href="#L561" id="L561" rel="#L561"><i class='fa fa-link'></i>
561
</a><a href="#L562" id="L562" rel="#L562"><i class='fa fa-link'></i>
562
</a><a href="#L563" id="L563" rel="#L563"><i class='fa fa-link'></i>
563
</a><a href="#L564" id="L564" rel="#L564"><i class='fa fa-link'></i>
564
</a><a href="#L565" id="L565" rel="#L565"><i class='fa fa-link'></i>
565
</a><a href="#L566" id="L566" rel="#L566"><i class='fa fa-link'></i>
566
</a><a href="#L567" id="L567" rel="#L567"><i class='fa fa-link'></i>
567
</a><a href="#L568" id="L568" rel="#L568"><i class='fa fa-link'></i>
568
</a><a href="#L569" id="L569" rel="#L569"><i class='fa fa-link'></i>
569
</a><a href="#L570" id="L570" rel="#L570"><i class='fa fa-link'></i>
570
</a><a href="#L571" id="L571" rel="#L571"><i class='fa fa-link'></i>
571
</a><a href="#L572" id="L572" rel="#L572"><i class='fa fa-link'></i>
572
</a><a href="#L573" id="L573" rel="#L573"><i class='fa fa-link'></i>
573
</a><a href="#L574" id="L574" rel="#L574"><i class='fa fa-link'></i>
574
</a><a href="#L575" id="L575" rel="#L575"><i class='fa fa-link'></i>
575
</a><a href="#L576" id="L576" rel="#L576"><i class='fa fa-link'></i>
576
</a><a href="#L577" id="L577" rel="#L577"><i class='fa fa-link'></i>
577
</a><a href="#L578" id="L578" rel="#L578"><i class='fa fa-link'></i>
578
</a><a href="#L579" id="L579" rel="#L579"><i class='fa fa-link'></i>
579
</a><a href="#L580" id="L580" rel="#L580"><i class='fa fa-link'></i>
580
</a><a href="#L581" id="L581" rel="#L581"><i class='fa fa-link'></i>
581
</a><a href="#L582" id="L582" rel="#L582"><i class='fa fa-link'></i>
582
</a><a href="#L583" id="L583" rel="#L583"><i class='fa fa-link'></i>
583
</a><a href="#L584" id="L584" rel="#L584"><i class='fa fa-link'></i>
584
</a><a href="#L585" id="L585" rel="#L585"><i class='fa fa-link'></i>
585
</a><a href="#L586" id="L586" rel="#L586"><i class='fa fa-link'></i>
586
</a><a href="#L587" id="L587" rel="#L587"><i class='fa fa-link'></i>
587
</a><a href="#L588" id="L588" rel="#L588"><i class='fa fa-link'></i>
588
</a><a href="#L589" id="L589" rel="#L589"><i class='fa fa-link'></i>
589
</a><a href="#L590" id="L590" rel="#L590"><i class='fa fa-link'></i>
590
</a><a href="#L591" id="L591" rel="#L591"><i class='fa fa-link'></i>
591
</a><a href="#L592" id="L592" rel="#L592"><i class='fa fa-link'></i>
592
</a><a href="#L593" id="L593" rel="#L593"><i class='fa fa-link'></i>
593
</a><a href="#L594" id="L594" rel="#L594"><i class='fa fa-link'></i>
594
</a><a href="#L595" id="L595" rel="#L595"><i class='fa fa-link'></i>
595
</a><a href="#L596" id="L596" rel="#L596"><i class='fa fa-link'></i>
596
</a><a href="#L597" id="L597" rel="#L597"><i class='fa fa-link'></i>
597
</a><a href="#L598" id="L598" rel="#L598"><i class='fa fa-link'></i>
598
</a><a href="#L599" id="L599" rel="#L599"><i class='fa fa-link'></i>
599
</a><a href="#L600" id="L600" rel="#L600"><i class='fa fa-link'></i>
600
</a><a href="#L601" id="L601" rel="#L601"><i class='fa fa-link'></i>
601
</a><a href="#L602" id="L602" rel="#L602"><i class='fa fa-link'></i>
602
</a><a href="#L603" id="L603" rel="#L603"><i class='fa fa-link'></i>
603
</a><a href="#L604" id="L604" rel="#L604"><i class='fa fa-link'></i>
604
</a><a href="#L605" id="L605" rel="#L605"><i class='fa fa-link'></i>
605
</a><a href="#L606" id="L606" rel="#L606"><i class='fa fa-link'></i>
606
</a><a href="#L607" id="L607" rel="#L607"><i class='fa fa-link'></i>
607
</a><a href="#L608" id="L608" rel="#L608"><i class='fa fa-link'></i>
608
</a><a href="#L609" id="L609" rel="#L609"><i class='fa fa-link'></i>
609
</a><a href="#L610" id="L610" rel="#L610"><i class='fa fa-link'></i>
610
</a><a href="#L611" id="L611" rel="#L611"><i class='fa fa-link'></i>
611
</a><a href="#L612" id="L612" rel="#L612"><i class='fa fa-link'></i>
612
</a><a href="#L613" id="L613" rel="#L613"><i class='fa fa-link'></i>
613
</a><a href="#L614" id="L614" rel="#L614"><i class='fa fa-link'></i>
614
</a><a href="#L615" id="L615" rel="#L615"><i class='fa fa-link'></i>
615
</a><a href="#L616" id="L616" rel="#L616"><i class='fa fa-link'></i>
616
</a><a href="#L617" id="L617" rel="#L617"><i class='fa fa-link'></i>
617
</a><a href="#L618" id="L618" rel="#L618"><i class='fa fa-link'></i>
618
</a><a href="#L619" id="L619" rel="#L619"><i class='fa fa-link'></i>
619
</a><a href="#L620" id="L620" rel="#L620"><i class='fa fa-link'></i>
620
</a><a href="#L621" id="L621" rel="#L621"><i class='fa fa-link'></i>
621
</a><a href="#L622" id="L622" rel="#L622"><i class='fa fa-link'></i>
622
</a><a href="#L623" id="L623" rel="#L623"><i class='fa fa-link'></i>
623
</a><a href="#L624" id="L624" rel="#L624"><i class='fa fa-link'></i>
624
</a><a href="#L625" id="L625" rel="#L625"><i class='fa fa-link'></i>
625
</a><a href="#L626" id="L626" rel="#L626"><i class='fa fa-link'></i>
626
</a><a href="#L627" id="L627" rel="#L627"><i class='fa fa-link'></i>
627
</a><a href="#L628" id="L628" rel="#L628"><i class='fa fa-link'></i>
628
</a><a href="#L629" id="L629" rel="#L629"><i class='fa fa-link'></i>
629
</a><a href="#L630" id="L630" rel="#L630"><i class='fa fa-link'></i>
630
</a><a href="#L631" id="L631" rel="#L631"><i class='fa fa-link'></i>
631
</a><a href="#L632" id="L632" rel="#L632"><i class='fa fa-link'></i>
632
</a><a href="#L633" id="L633" rel="#L633"><i class='fa fa-link'></i>
633
</a><a href="#L634" id="L634" rel="#L634"><i class='fa fa-link'></i>
634
</a><a href="#L635" id="L635" rel="#L635"><i class='fa fa-link'></i>
635
</a><a href="#L636" id="L636" rel="#L636"><i class='fa fa-link'></i>
636
</a><a href="#L637" id="L637" rel="#L637"><i class='fa fa-link'></i>
637
</a><a href="#L638" id="L638" rel="#L638"><i class='fa fa-link'></i>
638
</a><a href="#L639" id="L639" rel="#L639"><i class='fa fa-link'></i>
639
</a><a href="#L640" id="L640" rel="#L640"><i class='fa fa-link'></i>
640
</a><a href="#L641" id="L641" rel="#L641"><i class='fa fa-link'></i>
641
</a><a href="#L642" id="L642" rel="#L642"><i class='fa fa-link'></i>
642
</a><a href="#L643" id="L643" rel="#L643"><i class='fa fa-link'></i>
643
</a><a href="#L644" id="L644" rel="#L644"><i class='fa fa-link'></i>
644
</a><a href="#L645" id="L645" rel="#L645"><i class='fa fa-link'></i>
645
</a><a href="#L646" id="L646" rel="#L646"><i class='fa fa-link'></i>
646
</a><a href="#L647" id="L647" rel="#L647"><i class='fa fa-link'></i>
647
</a><a href="#L648" id="L648" rel="#L648"><i class='fa fa-link'></i>
648
</a><a href="#L649" id="L649" rel="#L649"><i class='fa fa-link'></i>
649
</a><a href="#L650" id="L650" rel="#L650"><i class='fa fa-link'></i>
650
</a><a href="#L651" id="L651" rel="#L651"><i class='fa fa-link'></i>
651
</a><a href="#L652" id="L652" rel="#L652"><i class='fa fa-link'></i>
652
</a><a href="#L653" id="L653" rel="#L653"><i class='fa fa-link'></i>
653
</a><a href="#L654" id="L654" rel="#L654"><i class='fa fa-link'></i>
654
</a><a href="#L655" id="L655" rel="#L655"><i class='fa fa-link'></i>
655
</a><a href="#L656" id="L656" rel="#L656"><i class='fa fa-link'></i>
656
</a><a href="#L657" id="L657" rel="#L657"><i class='fa fa-link'></i>
657
</a><a href="#L658" id="L658" rel="#L658"><i class='fa fa-link'></i>
658
</a><a href="#L659" id="L659" rel="#L659"><i class='fa fa-link'></i>
659
</a><a href="#L660" id="L660" rel="#L660"><i class='fa fa-link'></i>
660
</a><a href="#L661" id="L661" rel="#L661"><i class='fa fa-link'></i>
661
</a><a href="#L662" id="L662" rel="#L662"><i class='fa fa-link'></i>
662
</a><a href="#L663" id="L663" rel="#L663"><i class='fa fa-link'></i>
663
</a><a href="#L664" id="L664" rel="#L664"><i class='fa fa-link'></i>
664
</a><a href="#L665" id="L665" rel="#L665"><i class='fa fa-link'></i>
665
</a><a href="#L666" id="L666" rel="#L666"><i class='fa fa-link'></i>
666
</a><a href="#L667" id="L667" rel="#L667"><i class='fa fa-link'></i>
667
</a><a href="#L668" id="L668" rel="#L668"><i class='fa fa-link'></i>
668
</a><a href="#L669" id="L669" rel="#L669"><i class='fa fa-link'></i>
669
</a><a href="#L670" id="L670" rel="#L670"><i class='fa fa-link'></i>
670
</a><a href="#L671" id="L671" rel="#L671"><i class='fa fa-link'></i>
671
</a><a href="#L672" id="L672" rel="#L672"><i class='fa fa-link'></i>
672
</a><a href="#L673" id="L673" rel="#L673"><i class='fa fa-link'></i>
673
</a><a href="#L674" id="L674" rel="#L674"><i class='fa fa-link'></i>
674
</a><a href="#L675" id="L675" rel="#L675"><i class='fa fa-link'></i>
675
</a><a href="#L676" id="L676" rel="#L676"><i class='fa fa-link'></i>
676
</a><a href="#L677" id="L677" rel="#L677"><i class='fa fa-link'></i>
677
</a><a href="#L678" id="L678" rel="#L678"><i class='fa fa-link'></i>
678
</a><a href="#L679" id="L679" rel="#L679"><i class='fa fa-link'></i>
679
</a><a href="#L680" id="L680" rel="#L680"><i class='fa fa-link'></i>
680
</a><a href="#L681" id="L681" rel="#L681"><i class='fa fa-link'></i>
681
</a><a href="#L682" id="L682" rel="#L682"><i class='fa fa-link'></i>
682
</a><a href="#L683" id="L683" rel="#L683"><i class='fa fa-link'></i>
683
</a><a href="#L684" id="L684" rel="#L684"><i class='fa fa-link'></i>
684
</a><a href="#L685" id="L685" rel="#L685"><i class='fa fa-link'></i>
685
</a><a href="#L686" id="L686" rel="#L686"><i class='fa fa-link'></i>
686
</a><a href="#L687" id="L687" rel="#L687"><i class='fa fa-link'></i>
687
</a><a href="#L688" id="L688" rel="#L688"><i class='fa fa-link'></i>
688
</a><a href="#L689" id="L689" rel="#L689"><i class='fa fa-link'></i>
689
</a><a href="#L690" id="L690" rel="#L690"><i class='fa fa-link'></i>
690
</a><a href="#L691" id="L691" rel="#L691"><i class='fa fa-link'></i>
691
</a><a href="#L692" id="L692" rel="#L692"><i class='fa fa-link'></i>
692
</a><a href="#L693" id="L693" rel="#L693"><i class='fa fa-link'></i>
693
</a><a href="#L694" id="L694" rel="#L694"><i class='fa fa-link'></i>
694
</a><a href="#L695" id="L695" rel="#L695"><i class='fa fa-link'></i>
695
</a><a href="#L696" id="L696" rel="#L696"><i class='fa fa-link'></i>
696
</a><a href="#L697" id="L697" rel="#L697"><i class='fa fa-link'></i>
697
</a><a href="#L698" id="L698" rel="#L698"><i class='fa fa-link'></i>
698
</a><a href="#L699" id="L699" rel="#L699"><i class='fa fa-link'></i>
699
</a><a href="#L700" id="L700" rel="#L700"><i class='fa fa-link'></i>
700
</a><a href="#L701" id="L701" rel="#L701"><i class='fa fa-link'></i>
701
</a><a href="#L702" id="L702" rel="#L702"><i class='fa fa-link'></i>
702
</a><a href="#L703" id="L703" rel="#L703"><i class='fa fa-link'></i>
703
</a><a href="#L704" id="L704" rel="#L704"><i class='fa fa-link'></i>
704
</a><a href="#L705" id="L705" rel="#L705"><i class='fa fa-link'></i>
705
</a><a href="#L706" id="L706" rel="#L706"><i class='fa fa-link'></i>
706
</a><a href="#L707" id="L707" rel="#L707"><i class='fa fa-link'></i>
707
</a><a href="#L708" id="L708" rel="#L708"><i class='fa fa-link'></i>
708
</a><a href="#L709" id="L709" rel="#L709"><i class='fa fa-link'></i>
709
</a><a href="#L710" id="L710" rel="#L710"><i class='fa fa-link'></i>
710
</a><a href="#L711" id="L711" rel="#L711"><i class='fa fa-link'></i>
711
</a><a href="#L712" id="L712" rel="#L712"><i class='fa fa-link'></i>
712
</a><a href="#L713" id="L713" rel="#L713"><i class='fa fa-link'></i>
713
</a><a href="#L714" id="L714" rel="#L714"><i class='fa fa-link'></i>
714
</a><a href="#L715" id="L715" rel="#L715"><i class='fa fa-link'></i>
715
</a><a href="#L716" id="L716" rel="#L716"><i class='fa fa-link'></i>
716
</a><a href="#L717" id="L717" rel="#L717"><i class='fa fa-link'></i>
717
</a><a href="#L718" id="L718" rel="#L718"><i class='fa fa-link'></i>
718
</a><a href="#L719" id="L719" rel="#L719"><i class='fa fa-link'></i>
719
</a><a href="#L720" id="L720" rel="#L720"><i class='fa fa-link'></i>
720
</a><a href="#L721" id="L721" rel="#L721"><i class='fa fa-link'></i>
721
</a><a href="#L722" id="L722" rel="#L722"><i class='fa fa-link'></i>
722
</a><a href="#L723" id="L723" rel="#L723"><i class='fa fa-link'></i>
723
</a><a href="#L724" id="L724" rel="#L724"><i class='fa fa-link'></i>
724
</a><a href="#L725" id="L725" rel="#L725"><i class='fa fa-link'></i>
725
</a><a href="#L726" id="L726" rel="#L726"><i class='fa fa-link'></i>
726
</a><a href="#L727" id="L727" rel="#L727"><i class='fa fa-link'></i>
727
</a><a href="#L728" id="L728" rel="#L728"><i class='fa fa-link'></i>
728
</a><a href="#L729" id="L729" rel="#L729"><i class='fa fa-link'></i>
729
</a><a href="#L730" id="L730" rel="#L730"><i class='fa fa-link'></i>
730
</a><a href="#L731" id="L731" rel="#L731"><i class='fa fa-link'></i>
731
</a><a href="#L732" id="L732" rel="#L732"><i class='fa fa-link'></i>
732
</a><a href="#L733" id="L733" rel="#L733"><i class='fa fa-link'></i>
733
</a><a href="#L734" id="L734" rel="#L734"><i class='fa fa-link'></i>
734
</a><a href="#L735" id="L735" rel="#L735"><i class='fa fa-link'></i>
735
</a><a href="#L736" id="L736" rel="#L736"><i class='fa fa-link'></i>
736
</a><a href="#L737" id="L737" rel="#L737"><i class='fa fa-link'></i>
737
</a><a href="#L738" id="L738" rel="#L738"><i class='fa fa-link'></i>
738
</a><a href="#L739" id="L739" rel="#L739"><i class='fa fa-link'></i>
739
</a><a href="#L740" id="L740" rel="#L740"><i class='fa fa-link'></i>
740
</a><a href="#L741" id="L741" rel="#L741"><i class='fa fa-link'></i>
741
</a><a href="#L742" id="L742" rel="#L742"><i class='fa fa-link'></i>
742
</a><a href="#L743" id="L743" rel="#L743"><i class='fa fa-link'></i>
743
</a><a href="#L744" id="L744" rel="#L744"><i class='fa fa-link'></i>
744
</a><a href="#L745" id="L745" rel="#L745"><i class='fa fa-link'></i>
745
</a><a href="#L746" id="L746" rel="#L746"><i class='fa fa-link'></i>
746
</a><a href="#L747" id="L747" rel="#L747"><i class='fa fa-link'></i>
747
</a><a href="#L748" id="L748" rel="#L748"><i class='fa fa-link'></i>
748
</a><a href="#L749" id="L749" rel="#L749"><i class='fa fa-link'></i>
749
</a><a href="#L750" id="L750" rel="#L750"><i class='fa fa-link'></i>
750
</a><a href="#L751" id="L751" rel="#L751"><i class='fa fa-link'></i>
751
</a><a href="#L752" id="L752" rel="#L752"><i class='fa fa-link'></i>
752
</a><a href="#L753" id="L753" rel="#L753"><i class='fa fa-link'></i>
753
</a><a href="#L754" id="L754" rel="#L754"><i class='fa fa-link'></i>
754
</a><a href="#L755" id="L755" rel="#L755"><i class='fa fa-link'></i>
755
</a><a href="#L756" id="L756" rel="#L756"><i class='fa fa-link'></i>
756
</a><a href="#L757" id="L757" rel="#L757"><i class='fa fa-link'></i>
757
</a><a href="#L758" id="L758" rel="#L758"><i class='fa fa-link'></i>
758
</a><a href="#L759" id="L759" rel="#L759"><i class='fa fa-link'></i>
759
</a><a href="#L760" id="L760" rel="#L760"><i class='fa fa-link'></i>
760
</a><a href="#L761" id="L761" rel="#L761"><i class='fa fa-link'></i>
761
</a><a href="#L762" id="L762" rel="#L762"><i class='fa fa-link'></i>
762
</a><a href="#L763" id="L763" rel="#L763"><i class='fa fa-link'></i>
763
</a><a href="#L764" id="L764" rel="#L764"><i class='fa fa-link'></i>
764
</a><a href="#L765" id="L765" rel="#L765"><i class='fa fa-link'></i>
765
</a><a href="#L766" id="L766" rel="#L766"><i class='fa fa-link'></i>
766
</a><a href="#L767" id="L767" rel="#L767"><i class='fa fa-link'></i>
767
</a><a href="#L768" id="L768" rel="#L768"><i class='fa fa-link'></i>
768
</a><a href="#L769" id="L769" rel="#L769"><i class='fa fa-link'></i>
769
</a><a href="#L770" id="L770" rel="#L770"><i class='fa fa-link'></i>
770
</a><a href="#L771" id="L771" rel="#L771"><i class='fa fa-link'></i>
771
</a><a href="#L772" id="L772" rel="#L772"><i class='fa fa-link'></i>
772
</a><a href="#L773" id="L773" rel="#L773"><i class='fa fa-link'></i>
773
</a><a href="#L774" id="L774" rel="#L774"><i class='fa fa-link'></i>
774
</a><a href="#L775" id="L775" rel="#L775"><i class='fa fa-link'></i>
775
</a><a href="#L776" id="L776" rel="#L776"><i class='fa fa-link'></i>
776
</a><a href="#L777" id="L777" rel="#L777"><i class='fa fa-link'></i>
777
</a><a href="#L778" id="L778" rel="#L778"><i class='fa fa-link'></i>
778
</a><a href="#L779" id="L779" rel="#L779"><i class='fa fa-link'></i>
779
</a><a href="#L780" id="L780" rel="#L780"><i class='fa fa-link'></i>
780
</a><a href="#L781" id="L781" rel="#L781"><i class='fa fa-link'></i>
781
</a><a href="#L782" id="L782" rel="#L782"><i class='fa fa-link'></i>
782
</a><a href="#L783" id="L783" rel="#L783"><i class='fa fa-link'></i>
783
</a><a href="#L784" id="L784" rel="#L784"><i class='fa fa-link'></i>
784
</a><a href="#L785" id="L785" rel="#L785"><i class='fa fa-link'></i>
785
</a><a href="#L786" id="L786" rel="#L786"><i class='fa fa-link'></i>
786
</a><a href="#L787" id="L787" rel="#L787"><i class='fa fa-link'></i>
787
</a><a href="#L788" id="L788" rel="#L788"><i class='fa fa-link'></i>
788
</a><a href="#L789" id="L789" rel="#L789"><i class='fa fa-link'></i>
789
</a><a href="#L790" id="L790" rel="#L790"><i class='fa fa-link'></i>
790
</a><a href="#L791" id="L791" rel="#L791"><i class='fa fa-link'></i>
791
</a><a href="#L792" id="L792" rel="#L792"><i class='fa fa-link'></i>
792
</a><a href="#L793" id="L793" rel="#L793"><i class='fa fa-link'></i>
793
</a><a href="#L794" id="L794" rel="#L794"><i class='fa fa-link'></i>
794
</a><a href="#L795" id="L795" rel="#L795"><i class='fa fa-link'></i>
795
</a><a href="#L796" id="L796" rel="#L796"><i class='fa fa-link'></i>
796
</a><a href="#L797" id="L797" rel="#L797"><i class='fa fa-link'></i>
797
</a><a href="#L798" id="L798" rel="#L798"><i class='fa fa-link'></i>
798
</a><a href="#L799" id="L799" rel="#L799"><i class='fa fa-link'></i>
799
</a><a href="#L800" id="L800" rel="#L800"><i class='fa fa-link'></i>
800
</a><a href="#L801" id="L801" rel="#L801"><i class='fa fa-link'></i>
801
</a><a href="#L802" id="L802" rel="#L802"><i class='fa fa-link'></i>
802
</a><a href="#L803" id="L803" rel="#L803"><i class='fa fa-link'></i>
803
</a><a href="#L804" id="L804" rel="#L804"><i class='fa fa-link'></i>
804
</a><a href="#L805" id="L805" rel="#L805"><i class='fa fa-link'></i>
805
</a><a href="#L806" id="L806" rel="#L806"><i class='fa fa-link'></i>
806
</a><a href="#L807" id="L807" rel="#L807"><i class='fa fa-link'></i>
807
</a><a href="#L808" id="L808" rel="#L808"><i class='fa fa-link'></i>
808
</a><a href="#L809" id="L809" rel="#L809"><i class='fa fa-link'></i>
809
</a><a href="#L810" id="L810" rel="#L810"><i class='fa fa-link'></i>
810
</a><a href="#L811" id="L811" rel="#L811"><i class='fa fa-link'></i>
811
</a><a href="#L812" id="L812" rel="#L812"><i class='fa fa-link'></i>
812
</a><a href="#L813" id="L813" rel="#L813"><i class='fa fa-link'></i>
813
</a><a href="#L814" id="L814" rel="#L814"><i class='fa fa-link'></i>
814
</a><a href="#L815" id="L815" rel="#L815"><i class='fa fa-link'></i>
815
</a><a href="#L816" id="L816" rel="#L816"><i class='fa fa-link'></i>
816
</a><a href="#L817" id="L817" rel="#L817"><i class='fa fa-link'></i>
817
</a><a href="#L818" id="L818" rel="#L818"><i class='fa fa-link'></i>
818
</a><a href="#L819" id="L819" rel="#L819"><i class='fa fa-link'></i>
819
</a><a href="#L820" id="L820" rel="#L820"><i class='fa fa-link'></i>
820
</a><a href="#L821" id="L821" rel="#L821"><i class='fa fa-link'></i>
821
</a><a href="#L822" id="L822" rel="#L822"><i class='fa fa-link'></i>
822
</a><a href="#L823" id="L823" rel="#L823"><i class='fa fa-link'></i>
823
</a><a href="#L824" id="L824" rel="#L824"><i class='fa fa-link'></i>
824
</a><a href="#L825" id="L825" rel="#L825"><i class='fa fa-link'></i>
825
</a><a href="#L826" id="L826" rel="#L826"><i class='fa fa-link'></i>
826
</a><a href="#L827" id="L827" rel="#L827"><i class='fa fa-link'></i>
827
</a><a href="#L828" id="L828" rel="#L828"><i class='fa fa-link'></i>
828
</a><a href="#L829" id="L829" rel="#L829"><i class='fa fa-link'></i>
829
</a><a href="#L830" id="L830" rel="#L830"><i class='fa fa-link'></i>
830
</a><a href="#L831" id="L831" rel="#L831"><i class='fa fa-link'></i>
831
</a><a href="#L832" id="L832" rel="#L832"><i class='fa fa-link'></i>
832
</a><a href="#L833" id="L833" rel="#L833"><i class='fa fa-link'></i>
833
</a><a href="#L834" id="L834" rel="#L834"><i class='fa fa-link'></i>
834
</a><a href="#L835" id="L835" rel="#L835"><i class='fa fa-link'></i>
835
</a><a href="#L836" id="L836" rel="#L836"><i class='fa fa-link'></i>
836
</a><a href="#L837" id="L837" rel="#L837"><i class='fa fa-link'></i>
837
</a><a href="#L838" id="L838" rel="#L838"><i class='fa fa-link'></i>
838
</a><a href="#L839" id="L839" rel="#L839"><i class='fa fa-link'></i>
839
</a><a href="#L840" id="L840" rel="#L840"><i class='fa fa-link'></i>
840
</a><a href="#L841" id="L841" rel="#L841"><i class='fa fa-link'></i>
841
</a><a href="#L842" id="L842" rel="#L842"><i class='fa fa-link'></i>
842
</a><a href="#L843" id="L843" rel="#L843"><i class='fa fa-link'></i>
843
</a><a href="#L844" id="L844" rel="#L844"><i class='fa fa-link'></i>
844
</a><a href="#L845" id="L845" rel="#L845"><i class='fa fa-link'></i>
845
</a><a href="#L846" id="L846" rel="#L846"><i class='fa fa-link'></i>
846
</a><a href="#L847" id="L847" rel="#L847"><i class='fa fa-link'></i>
847
</a><a href="#L848" id="L848" rel="#L848"><i class='fa fa-link'></i>
848
</a><a href="#L849" id="L849" rel="#L849"><i class='fa fa-link'></i>
849
</a><a href="#L850" id="L850" rel="#L850"><i class='fa fa-link'></i>
850
</a><a href="#L851" id="L851" rel="#L851"><i class='fa fa-link'></i>
851
</a><a href="#L852" id="L852" rel="#L852"><i class='fa fa-link'></i>
852
</a><a href="#L853" id="L853" rel="#L853"><i class='fa fa-link'></i>
853
</a><a href="#L854" id="L854" rel="#L854"><i class='fa fa-link'></i>
854
</a><a href="#L855" id="L855" rel="#L855"><i class='fa fa-link'></i>
855
</a><a href="#L856" id="L856" rel="#L856"><i class='fa fa-link'></i>
856
</a><a href="#L857" id="L857" rel="#L857"><i class='fa fa-link'></i>
857
</a><a href="#L858" id="L858" rel="#L858"><i class='fa fa-link'></i>
858
</a><a href="#L859" id="L859" rel="#L859"><i class='fa fa-link'></i>
859
</a><a href="#L860" id="L860" rel="#L860"><i class='fa fa-link'></i>
860
</a><a href="#L861" id="L861" rel="#L861"><i class='fa fa-link'></i>
861
</a><a href="#L862" id="L862" rel="#L862"><i class='fa fa-link'></i>
862
</a><a href="#L863" id="L863" rel="#L863"><i class='fa fa-link'></i>
863
</a><a href="#L864" id="L864" rel="#L864"><i class='fa fa-link'></i>
864
</a><a href="#L865" id="L865" rel="#L865"><i class='fa fa-link'></i>
865
</a><a href="#L866" id="L866" rel="#L866"><i class='fa fa-link'></i>
866
</a><a href="#L867" id="L867" rel="#L867"><i class='fa fa-link'></i>
867
</a><a href="#L868" id="L868" rel="#L868"><i class='fa fa-link'></i>
868
</a><a href="#L869" id="L869" rel="#L869"><i class='fa fa-link'></i>
869
</a><a href="#L870" id="L870" rel="#L870"><i class='fa fa-link'></i>
870
</a><a href="#L871" id="L871" rel="#L871"><i class='fa fa-link'></i>
871
</a><a href="#L872" id="L872" rel="#L872"><i class='fa fa-link'></i>
872
</a><a href="#L873" id="L873" rel="#L873"><i class='fa fa-link'></i>
873
</a><a href="#L874" id="L874" rel="#L874"><i class='fa fa-link'></i>
874
</a><a href="#L875" id="L875" rel="#L875"><i class='fa fa-link'></i>
875
</a><a href="#L876" id="L876" rel="#L876"><i class='fa fa-link'></i>
876
</a><a href="#L877" id="L877" rel="#L877"><i class='fa fa-link'></i>
877
</a><a href="#L878" id="L878" rel="#L878"><i class='fa fa-link'></i>
878
</a><a href="#L879" id="L879" rel="#L879"><i class='fa fa-link'></i>
879
</a><a href="#L880" id="L880" rel="#L880"><i class='fa fa-link'></i>
880
</a><a href="#L881" id="L881" rel="#L881"><i class='fa fa-link'></i>
881
</a><a href="#L882" id="L882" rel="#L882"><i class='fa fa-link'></i>
882
</a><a href="#L883" id="L883" rel="#L883"><i class='fa fa-link'></i>
883
</a><a href="#L884" id="L884" rel="#L884"><i class='fa fa-link'></i>
884
</a><a href="#L885" id="L885" rel="#L885"><i class='fa fa-link'></i>
885
</a><a href="#L886" id="L886" rel="#L886"><i class='fa fa-link'></i>
886
</a><a href="#L887" id="L887" rel="#L887"><i class='fa fa-link'></i>
887
</a><a href="#L888" id="L888" rel="#L888"><i class='fa fa-link'></i>
888
</a><a href="#L889" id="L889" rel="#L889"><i class='fa fa-link'></i>
889
</a><a href="#L890" id="L890" rel="#L890"><i class='fa fa-link'></i>
890
</a><a href="#L891" id="L891" rel="#L891"><i class='fa fa-link'></i>
891
</a><a href="#L892" id="L892" rel="#L892"><i class='fa fa-link'></i>
892
</a><a href="#L893" id="L893" rel="#L893"><i class='fa fa-link'></i>
893
</a><a href="#L894" id="L894" rel="#L894"><i class='fa fa-link'></i>
894
</a><a href="#L895" id="L895" rel="#L895"><i class='fa fa-link'></i>
895
</a><a href="#L896" id="L896" rel="#L896"><i class='fa fa-link'></i>
896
</a><a href="#L897" id="L897" rel="#L897"><i class='fa fa-link'></i>
897
</a><a href="#L898" id="L898" rel="#L898"><i class='fa fa-link'></i>
898
</a><a href="#L899" id="L899" rel="#L899"><i class='fa fa-link'></i>
899
</a><a href="#L900" id="L900" rel="#L900"><i class='fa fa-link'></i>
900
</a><a href="#L901" id="L901" rel="#L901"><i class='fa fa-link'></i>
901
</a><a href="#L902" id="L902" rel="#L902"><i class='fa fa-link'></i>
902
</a><a href="#L903" id="L903" rel="#L903"><i class='fa fa-link'></i>
903
</a><a href="#L904" id="L904" rel="#L904"><i class='fa fa-link'></i>
904
</a><a href="#L905" id="L905" rel="#L905"><i class='fa fa-link'></i>
905
</a><a href="#L906" id="L906" rel="#L906"><i class='fa fa-link'></i>
906
</a><a href="#L907" id="L907" rel="#L907"><i class='fa fa-link'></i>
907
</a><a href="#L908" id="L908" rel="#L908"><i class='fa fa-link'></i>
908
</a><a href="#L909" id="L909" rel="#L909"><i class='fa fa-link'></i>
909
</a><a href="#L910" id="L910" rel="#L910"><i class='fa fa-link'></i>
910
</a><a href="#L911" id="L911" rel="#L911"><i class='fa fa-link'></i>
911
</a><a href="#L912" id="L912" rel="#L912"><i class='fa fa-link'></i>
912
</a><a href="#L913" id="L913" rel="#L913"><i class='fa fa-link'></i>
913
</a><a href="#L914" id="L914" rel="#L914"><i class='fa fa-link'></i>
914
</a><a href="#L915" id="L915" rel="#L915"><i class='fa fa-link'></i>
915
</a><a href="#L916" id="L916" rel="#L916"><i class='fa fa-link'></i>
916
</a><a href="#L917" id="L917" rel="#L917"><i class='fa fa-link'></i>
917
</a><a href="#L918" id="L918" rel="#L918"><i class='fa fa-link'></i>
918
</a><a href="#L919" id="L919" rel="#L919"><i class='fa fa-link'></i>
919
</a><a href="#L920" id="L920" rel="#L920"><i class='fa fa-link'></i>
920
</a><a href="#L921" id="L921" rel="#L921"><i class='fa fa-link'></i>
921
</a><a href="#L922" id="L922" rel="#L922"><i class='fa fa-link'></i>
922
</a><a href="#L923" id="L923" rel="#L923"><i class='fa fa-link'></i>
923
</a><a href="#L924" id="L924" rel="#L924"><i class='fa fa-link'></i>
924
</a><a href="#L925" id="L925" rel="#L925"><i class='fa fa-link'></i>
925
</a><a href="#L926" id="L926" rel="#L926"><i class='fa fa-link'></i>
926
</a><a href="#L927" id="L927" rel="#L927"><i class='fa fa-link'></i>
927
</a><a href="#L928" id="L928" rel="#L928"><i class='fa fa-link'></i>
928
</a><a href="#L929" id="L929" rel="#L929"><i class='fa fa-link'></i>
929
</a><a href="#L930" id="L930" rel="#L930"><i class='fa fa-link'></i>
930
</a><a href="#L931" id="L931" rel="#L931"><i class='fa fa-link'></i>
931
</a><a href="#L932" id="L932" rel="#L932"><i class='fa fa-link'></i>
932
</a><a href="#L933" id="L933" rel="#L933"><i class='fa fa-link'></i>
933
</a><a href="#L934" id="L934" rel="#L934"><i class='fa fa-link'></i>
934
</a><a href="#L935" id="L935" rel="#L935"><i class='fa fa-link'></i>
935
</a><a href="#L936" id="L936" rel="#L936"><i class='fa fa-link'></i>
936
</a><a href="#L937" id="L937" rel="#L937"><i class='fa fa-link'></i>
937
</a><a href="#L938" id="L938" rel="#L938"><i class='fa fa-link'></i>
938
</a><a href="#L939" id="L939" rel="#L939"><i class='fa fa-link'></i>
939
</a><a href="#L940" id="L940" rel="#L940"><i class='fa fa-link'></i>
940
</a><a href="#L941" id="L941" rel="#L941"><i class='fa fa-link'></i>
941
</a><a href="#L942" id="L942" rel="#L942"><i class='fa fa-link'></i>
942
</a><a href="#L943" id="L943" rel="#L943"><i class='fa fa-link'></i>
943
</a><a href="#L944" id="L944" rel="#L944"><i class='fa fa-link'></i>
944
</a><a href="#L945" id="L945" rel="#L945"><i class='fa fa-link'></i>
945
</a><a href="#L946" id="L946" rel="#L946"><i class='fa fa-link'></i>
946
</a><a href="#L947" id="L947" rel="#L947"><i class='fa fa-link'></i>
947
</a><a href="#L948" id="L948" rel="#L948"><i class='fa fa-link'></i>
948
</a><a href="#L949" id="L949" rel="#L949"><i class='fa fa-link'></i>
949
</a><a href="#L950" id="L950" rel="#L950"><i class='fa fa-link'></i>
950
</a><a href="#L951" id="L951" rel="#L951"><i class='fa fa-link'></i>
951
</a><a href="#L952" id="L952" rel="#L952"><i class='fa fa-link'></i>
952
</a><a href="#L953" id="L953" rel="#L953"><i class='fa fa-link'></i>
953
</a><a href="#L954" id="L954" rel="#L954"><i class='fa fa-link'></i>
954
</a><a href="#L955" id="L955" rel="#L955"><i class='fa fa-link'></i>
955
</a><a href="#L956" id="L956" rel="#L956"><i class='fa fa-link'></i>
956
</a><a href="#L957" id="L957" rel="#L957"><i class='fa fa-link'></i>
957
</a><a href="#L958" id="L958" rel="#L958"><i class='fa fa-link'></i>
958
</a><a href="#L959" id="L959" rel="#L959"><i class='fa fa-link'></i>
959
</a><a href="#L960" id="L960" rel="#L960"><i class='fa fa-link'></i>
960
</a><a href="#L961" id="L961" rel="#L961"><i class='fa fa-link'></i>
961
</a><a href="#L962" id="L962" rel="#L962"><i class='fa fa-link'></i>
962
</a><a href="#L963" id="L963" rel="#L963"><i class='fa fa-link'></i>
963
</a><a href="#L964" id="L964" rel="#L964"><i class='fa fa-link'></i>
964
</a><a href="#L965" id="L965" rel="#L965"><i class='fa fa-link'></i>
965
</a><a href="#L966" id="L966" rel="#L966"><i class='fa fa-link'></i>
966
</a><a href="#L967" id="L967" rel="#L967"><i class='fa fa-link'></i>
967
</a><a href="#L968" id="L968" rel="#L968"><i class='fa fa-link'></i>
968
</a><a href="#L969" id="L969" rel="#L969"><i class='fa fa-link'></i>
969
</a><a href="#L970" id="L970" rel="#L970"><i class='fa fa-link'></i>
970
</a><a href="#L971" id="L971" rel="#L971"><i class='fa fa-link'></i>
971
</a><a href="#L972" id="L972" rel="#L972"><i class='fa fa-link'></i>
972
</a><a href="#L973" id="L973" rel="#L973"><i class='fa fa-link'></i>
973
</a><a href="#L974" id="L974" rel="#L974"><i class='fa fa-link'></i>
974
</a><a href="#L975" id="L975" rel="#L975"><i class='fa fa-link'></i>
975
</a><a href="#L976" id="L976" rel="#L976"><i class='fa fa-link'></i>
976
</a><a href="#L977" id="L977" rel="#L977"><i class='fa fa-link'></i>
977
</a><a href="#L978" id="L978" rel="#L978"><i class='fa fa-link'></i>
978
</a><a href="#L979" id="L979" rel="#L979"><i class='fa fa-link'></i>
979
</a><a href="#L980" id="L980" rel="#L980"><i class='fa fa-link'></i>
980
</a><a href="#L981" id="L981" rel="#L981"><i class='fa fa-link'></i>
981
</a><a href="#L982" id="L982" rel="#L982"><i class='fa fa-link'></i>
982
</a><a href="#L983" id="L983" rel="#L983"><i class='fa fa-link'></i>
983
</a><a href="#L984" id="L984" rel="#L984"><i class='fa fa-link'></i>
984
</a><a href="#L985" id="L985" rel="#L985"><i class='fa fa-link'></i>
985
</a><a href="#L986" id="L986" rel="#L986"><i class='fa fa-link'></i>
986
</a><a href="#L987" id="L987" rel="#L987"><i class='fa fa-link'></i>
987
</a><a href="#L988" id="L988" rel="#L988"><i class='fa fa-link'></i>
988
</a><a href="#L989" id="L989" rel="#L989"><i class='fa fa-link'></i>
989
</a><a href="#L990" id="L990" rel="#L990"><i class='fa fa-link'></i>
990
</a><a href="#L991" id="L991" rel="#L991"><i class='fa fa-link'></i>
991
</a><a href="#L992" id="L992" rel="#L992"><i class='fa fa-link'></i>
992
</a><a href="#L993" id="L993" rel="#L993"><i class='fa fa-link'></i>
993
</a><a href="#L994" id="L994" rel="#L994"><i class='fa fa-link'></i>
994
</a><a href="#L995" id="L995" rel="#L995"><i class='fa fa-link'></i>
995
</a><a href="#L996" id="L996" rel="#L996"><i class='fa fa-link'></i>
996
</a><a href="#L997" id="L997" rel="#L997"><i class='fa fa-link'></i>
997
</a><a href="#L998" id="L998" rel="#L998"><i class='fa fa-link'></i>
998
</a><a href="#L999" id="L999" rel="#L999"><i class='fa fa-link'></i>
999
</a><a href="#L1000" id="L1000" rel="#L1000"><i class='fa fa-link'></i>
1000
</a><a href="#L1001" id="L1001" rel="#L1001"><i class='fa fa-link'></i>
1001
</a><a href="#L1002" id="L1002" rel="#L1002"><i class='fa fa-link'></i>
1002
</a><a href="#L1003" id="L1003" rel="#L1003"><i class='fa fa-link'></i>
1003
</a><a href="#L1004" id="L1004" rel="#L1004"><i class='fa fa-link'></i>
1004
</a><a href="#L1005" id="L1005" rel="#L1005"><i class='fa fa-link'></i>
1005
</a><a href="#L1006" id="L1006" rel="#L1006"><i class='fa fa-link'></i>
1006
</a><a href="#L1007" id="L1007" rel="#L1007"><i class='fa fa-link'></i>
1007
</a><a href="#L1008" id="L1008" rel="#L1008"><i class='fa fa-link'></i>
1008
</a><a href="#L1009" id="L1009" rel="#L1009"><i class='fa fa-link'></i>
1009
</a><a href="#L1010" id="L1010" rel="#L1010"><i class='fa fa-link'></i>
1010
</a><a href="#L1011" id="L1011" rel="#L1011"><i class='fa fa-link'></i>
1011
</a><a href="#L1012" id="L1012" rel="#L1012"><i class='fa fa-link'></i>
1012
</a><a href="#L1013" id="L1013" rel="#L1013"><i class='fa fa-link'></i>
1013
</a><a href="#L1014" id="L1014" rel="#L1014"><i class='fa fa-link'></i>
1014
</a><a href="#L1015" id="L1015" rel="#L1015"><i class='fa fa-link'></i>
1015
</a><a href="#L1016" id="L1016" rel="#L1016"><i class='fa fa-link'></i>
1016
</a><a href="#L1017" id="L1017" rel="#L1017"><i class='fa fa-link'></i>
1017
</a><a href="#L1018" id="L1018" rel="#L1018"><i class='fa fa-link'></i>
1018
</a><a href="#L1019" id="L1019" rel="#L1019"><i class='fa fa-link'></i>
1019
</a><a href="#L1020" id="L1020" rel="#L1020"><i class='fa fa-link'></i>
1020
</a><a href="#L1021" id="L1021" rel="#L1021"><i class='fa fa-link'></i>
1021
</a><a href="#L1022" id="L1022" rel="#L1022"><i class='fa fa-link'></i>
1022
</a><a href="#L1023" id="L1023" rel="#L1023"><i class='fa fa-link'></i>
1023
</a><a href="#L1024" id="L1024" rel="#L1024"><i class='fa fa-link'></i>
1024
</a><a href="#L1025" id="L1025" rel="#L1025"><i class='fa fa-link'></i>
1025
</a><a href="#L1026" id="L1026" rel="#L1026"><i class='fa fa-link'></i>
1026
</a><a href="#L1027" id="L1027" rel="#L1027"><i class='fa fa-link'></i>
1027
</a><a href="#L1028" id="L1028" rel="#L1028"><i class='fa fa-link'></i>
1028
</a><a href="#L1029" id="L1029" rel="#L1029"><i class='fa fa-link'></i>
1029
</a><a href="#L1030" id="L1030" rel="#L1030"><i class='fa fa-link'></i>
1030
</a><a href="#L1031" id="L1031" rel="#L1031"><i class='fa fa-link'></i>
1031
</a><a href="#L1032" id="L1032" rel="#L1032"><i class='fa fa-link'></i>
1032
</a><a href="#L1033" id="L1033" rel="#L1033"><i class='fa fa-link'></i>
1033
</a><a href="#L1034" id="L1034" rel="#L1034"><i class='fa fa-link'></i>
1034
</a><a href="#L1035" id="L1035" rel="#L1035"><i class='fa fa-link'></i>
1035
</a><a href="#L1036" id="L1036" rel="#L1036"><i class='fa fa-link'></i>
1036
</a><a href="#L1037" id="L1037" rel="#L1037"><i class='fa fa-link'></i>
1037
</a><a href="#L1038" id="L1038" rel="#L1038"><i class='fa fa-link'></i>
1038
</a><a href="#L1039" id="L1039" rel="#L1039"><i class='fa fa-link'></i>
1039
</a><a href="#L1040" id="L1040" rel="#L1040"><i class='fa fa-link'></i>
1040
</a><a href="#L1041" id="L1041" rel="#L1041"><i class='fa fa-link'></i>
1041
</a><a href="#L1042" id="L1042" rel="#L1042"><i class='fa fa-link'></i>
1042
</a><a href="#L1043" id="L1043" rel="#L1043"><i class='fa fa-link'></i>
1043
</a><a href="#L1044" id="L1044" rel="#L1044"><i class='fa fa-link'></i>
1044
</a><a href="#L1045" id="L1045" rel="#L1045"><i class='fa fa-link'></i>
1045
</a><a href="#L1046" id="L1046" rel="#L1046"><i class='fa fa-link'></i>
1046
</a><a href="#L1047" id="L1047" rel="#L1047"><i class='fa fa-link'></i>
1047
</a><a href="#L1048" id="L1048" rel="#L1048"><i class='fa fa-link'></i>
1048
</a><a href="#L1049" id="L1049" rel="#L1049"><i class='fa fa-link'></i>
1049
</a><a href="#L1050" id="L1050" rel="#L1050"><i class='fa fa-link'></i>
1050
</a><a href="#L1051" id="L1051" rel="#L1051"><i class='fa fa-link'></i>
1051
</a><a href="#L1052" id="L1052" rel="#L1052"><i class='fa fa-link'></i>
1052
</a><a href="#L1053" id="L1053" rel="#L1053"><i class='fa fa-link'></i>
1053
</a><a href="#L1054" id="L1054" rel="#L1054"><i class='fa fa-link'></i>
1054
</a><a href="#L1055" id="L1055" rel="#L1055"><i class='fa fa-link'></i>
1055
</a><a href="#L1056" id="L1056" rel="#L1056"><i class='fa fa-link'></i>
1056
</a><a href="#L1057" id="L1057" rel="#L1057"><i class='fa fa-link'></i>
1057
</a><a href="#L1058" id="L1058" rel="#L1058"><i class='fa fa-link'></i>
1058
</a><a href="#L1059" id="L1059" rel="#L1059"><i class='fa fa-link'></i>
1059
</a><a href="#L1060" id="L1060" rel="#L1060"><i class='fa fa-link'></i>
1060
</a><a href="#L1061" id="L1061" rel="#L1061"><i class='fa fa-link'></i>
1061
</a><a href="#L1062" id="L1062" rel="#L1062"><i class='fa fa-link'></i>
1062
</a><a href="#L1063" id="L1063" rel="#L1063"><i class='fa fa-link'></i>
1063
</a><a href="#L1064" id="L1064" rel="#L1064"><i class='fa fa-link'></i>
1064
</a><a href="#L1065" id="L1065" rel="#L1065"><i class='fa fa-link'></i>
1065
</a><a href="#L1066" id="L1066" rel="#L1066"><i class='fa fa-link'></i>
1066
</a><a href="#L1067" id="L1067" rel="#L1067"><i class='fa fa-link'></i>
1067
</a><a href="#L1068" id="L1068" rel="#L1068"><i class='fa fa-link'></i>
1068
</a><a href="#L1069" id="L1069" rel="#L1069"><i class='fa fa-link'></i>
1069
</a><a href="#L1070" id="L1070" rel="#L1070"><i class='fa fa-link'></i>
1070
</a><a href="#L1071" id="L1071" rel="#L1071"><i class='fa fa-link'></i>
1071
</a><a href="#L1072" id="L1072" rel="#L1072"><i class='fa fa-link'></i>
1072
</a><a href="#L1073" id="L1073" rel="#L1073"><i class='fa fa-link'></i>
1073
</a><a href="#L1074" id="L1074" rel="#L1074"><i class='fa fa-link'></i>
1074
</a><a href="#L1075" id="L1075" rel="#L1075"><i class='fa fa-link'></i>
1075
</a><a href="#L1076" id="L1076" rel="#L1076"><i class='fa fa-link'></i>
1076
</a><a href="#L1077" id="L1077" rel="#L1077"><i class='fa fa-link'></i>
1077
</a><a href="#L1078" id="L1078" rel="#L1078"><i class='fa fa-link'></i>
1078
</a><a href="#L1079" id="L1079" rel="#L1079"><i class='fa fa-link'></i>
1079
</a><a href="#L1080" id="L1080" rel="#L1080"><i class='fa fa-link'></i>
1080
</a><a href="#L1081" id="L1081" rel="#L1081"><i class='fa fa-link'></i>
1081
</a><a href="#L1082" id="L1082" rel="#L1082"><i class='fa fa-link'></i>
1082
</a><a href="#L1083" id="L1083" rel="#L1083"><i class='fa fa-link'></i>
1083
</a><a href="#L1084" id="L1084" rel="#L1084"><i class='fa fa-link'></i>
1084
</a><a href="#L1085" id="L1085" rel="#L1085"><i class='fa fa-link'></i>
1085
</a><a href="#L1086" id="L1086" rel="#L1086"><i class='fa fa-link'></i>
1086
</a><a href="#L1087" id="L1087" rel="#L1087"><i class='fa fa-link'></i>
1087
</a><a href="#L1088" id="L1088" rel="#L1088"><i class='fa fa-link'></i>
1088
</a><a href="#L1089" id="L1089" rel="#L1089"><i class='fa fa-link'></i>
1089
</a><a href="#L1090" id="L1090" rel="#L1090"><i class='fa fa-link'></i>
1090
</a><a href="#L1091" id="L1091" rel="#L1091"><i class='fa fa-link'></i>
1091
</a><a href="#L1092" id="L1092" rel="#L1092"><i class='fa fa-link'></i>
1092
</a><a href="#L1093" id="L1093" rel="#L1093"><i class='fa fa-link'></i>
1093
</a><a href="#L1094" id="L1094" rel="#L1094"><i class='fa fa-link'></i>
1094
</a><a href="#L1095" id="L1095" rel="#L1095"><i class='fa fa-link'></i>
1095
</a><a href="#L1096" id="L1096" rel="#L1096"><i class='fa fa-link'></i>
1096
</a><a href="#L1097" id="L1097" rel="#L1097"><i class='fa fa-link'></i>
1097
</a><a href="#L1098" id="L1098" rel="#L1098"><i class='fa fa-link'></i>
1098
</a><a href="#L1099" id="L1099" rel="#L1099"><i class='fa fa-link'></i>
1099
</a><a href="#L1100" id="L1100" rel="#L1100"><i class='fa fa-link'></i>
1100
</a><a href="#L1101" id="L1101" rel="#L1101"><i class='fa fa-link'></i>
1101
</a><a href="#L1102" id="L1102" rel="#L1102"><i class='fa fa-link'></i>
1102
</a><a href="#L1103" id="L1103" rel="#L1103"><i class='fa fa-link'></i>
1103
</a><a href="#L1104" id="L1104" rel="#L1104"><i class='fa fa-link'></i>
1104
</a><a href="#L1105" id="L1105" rel="#L1105"><i class='fa fa-link'></i>
1105
</a><a href="#L1106" id="L1106" rel="#L1106"><i class='fa fa-link'></i>
1106
</a><a href="#L1107" id="L1107" rel="#L1107"><i class='fa fa-link'></i>
1107
</a><a href="#L1108" id="L1108" rel="#L1108"><i class='fa fa-link'></i>
1108
</a><a href="#L1109" id="L1109" rel="#L1109"><i class='fa fa-link'></i>
1109
</a><a href="#L1110" id="L1110" rel="#L1110"><i class='fa fa-link'></i>
1110
</a><a href="#L1111" id="L1111" rel="#L1111"><i class='fa fa-link'></i>
1111
</a><a href="#L1112" id="L1112" rel="#L1112"><i class='fa fa-link'></i>
1112
</a><a href="#L1113" id="L1113" rel="#L1113"><i class='fa fa-link'></i>
1113
</a><a href="#L1114" id="L1114" rel="#L1114"><i class='fa fa-link'></i>
1114
</a><a href="#L1115" id="L1115" rel="#L1115"><i class='fa fa-link'></i>
1115
</a><a href="#L1116" id="L1116" rel="#L1116"><i class='fa fa-link'></i>
1116
</a><a href="#L1117" id="L1117" rel="#L1117"><i class='fa fa-link'></i>
1117
</a><a href="#L1118" id="L1118" rel="#L1118"><i class='fa fa-link'></i>
1118
</a><a href="#L1119" id="L1119" rel="#L1119"><i class='fa fa-link'></i>
1119
</a><a href="#L1120" id="L1120" rel="#L1120"><i class='fa fa-link'></i>
1120
</a><a href="#L1121" id="L1121" rel="#L1121"><i class='fa fa-link'></i>
1121
</a><a href="#L1122" id="L1122" rel="#L1122"><i class='fa fa-link'></i>
1122
</a><a href="#L1123" id="L1123" rel="#L1123"><i class='fa fa-link'></i>
1123
</a><a href="#L1124" id="L1124" rel="#L1124"><i class='fa fa-link'></i>
1124
</a><a href="#L1125" id="L1125" rel="#L1125"><i class='fa fa-link'></i>
1125
</a><a href="#L1126" id="L1126" rel="#L1126"><i class='fa fa-link'></i>
1126
</a><a href="#L1127" id="L1127" rel="#L1127"><i class='fa fa-link'></i>
1127
</a><a href="#L1128" id="L1128" rel="#L1128"><i class='fa fa-link'></i>
1128
</a><a href="#L1129" id="L1129" rel="#L1129"><i class='fa fa-link'></i>
1129
</a><a href="#L1130" id="L1130" rel="#L1130"><i class='fa fa-link'></i>
1130
</a><a href="#L1131" id="L1131" rel="#L1131"><i class='fa fa-link'></i>
1131
</a><a href="#L1132" id="L1132" rel="#L1132"><i class='fa fa-link'></i>
1132
</a><a href="#L1133" id="L1133" rel="#L1133"><i class='fa fa-link'></i>
1133
</a><a href="#L1134" id="L1134" rel="#L1134"><i class='fa fa-link'></i>
1134
</a><a href="#L1135" id="L1135" rel="#L1135"><i class='fa fa-link'></i>
1135
</a><a href="#L1136" id="L1136" rel="#L1136"><i class='fa fa-link'></i>
1136
</a><a href="#L1137" id="L1137" rel="#L1137"><i class='fa fa-link'></i>
1137
</a><a href="#L1138" id="L1138" rel="#L1138"><i class='fa fa-link'></i>
1138
</a><a href="#L1139" id="L1139" rel="#L1139"><i class='fa fa-link'></i>
1139
</a><a href="#L1140" id="L1140" rel="#L1140"><i class='fa fa-link'></i>
1140
</a><a href="#L1141" id="L1141" rel="#L1141"><i class='fa fa-link'></i>
1141
</a><a href="#L1142" id="L1142" rel="#L1142"><i class='fa fa-link'></i>
1142
</a><a href="#L1143" id="L1143" rel="#L1143"><i class='fa fa-link'></i>
1143
</a><a href="#L1144" id="L1144" rel="#L1144"><i class='fa fa-link'></i>
1144
</a><a href="#L1145" id="L1145" rel="#L1145"><i class='fa fa-link'></i>
1145
</a><a href="#L1146" id="L1146" rel="#L1146"><i class='fa fa-link'></i>
1146
</a><a href="#L1147" id="L1147" rel="#L1147"><i class='fa fa-link'></i>
1147
</a><a href="#L1148" id="L1148" rel="#L1148"><i class='fa fa-link'></i>
1148
</a><a href="#L1149" id="L1149" rel="#L1149"><i class='fa fa-link'></i>
1149
</a><a href="#L1150" id="L1150" rel="#L1150"><i class='fa fa-link'></i>
1150
</a><a href="#L1151" id="L1151" rel="#L1151"><i class='fa fa-link'></i>
1151
</a><a href="#L1152" id="L1152" rel="#L1152"><i class='fa fa-link'></i>
1152
</a><a href="#L1153" id="L1153" rel="#L1153"><i class='fa fa-link'></i>
1153
</a><a href="#L1154" id="L1154" rel="#L1154"><i class='fa fa-link'></i>
1154
</a><a href="#L1155" id="L1155" rel="#L1155"><i class='fa fa-link'></i>
1155
</a><a href="#L1156" id="L1156" rel="#L1156"><i class='fa fa-link'></i>
1156
</a><a href="#L1157" id="L1157" rel="#L1157"><i class='fa fa-link'></i>
1157
</a><a href="#L1158" id="L1158" rel="#L1158"><i class='fa fa-link'></i>
1158
</a><a href="#L1159" id="L1159" rel="#L1159"><i class='fa fa-link'></i>
1159
</a><a href="#L1160" id="L1160" rel="#L1160"><i class='fa fa-link'></i>
1160
</a><a href="#L1161" id="L1161" rel="#L1161"><i class='fa fa-link'></i>
1161
</a><a href="#L1162" id="L1162" rel="#L1162"><i class='fa fa-link'></i>
1162
</a><a href="#L1163" id="L1163" rel="#L1163"><i class='fa fa-link'></i>
1163
</a><a href="#L1164" id="L1164" rel="#L1164"><i class='fa fa-link'></i>
1164
</a><a href="#L1165" id="L1165" rel="#L1165"><i class='fa fa-link'></i>
1165
</a><a href="#L1166" id="L1166" rel="#L1166"><i class='fa fa-link'></i>
1166
</a><a href="#L1167" id="L1167" rel="#L1167"><i class='fa fa-link'></i>
1167
</a><a href="#L1168" id="L1168" rel="#L1168"><i class='fa fa-link'></i>
1168
</a><a href="#L1169" id="L1169" rel="#L1169"><i class='fa fa-link'></i>
1169
</a><a href="#L1170" id="L1170" rel="#L1170"><i class='fa fa-link'></i>
1170
</a><a href="#L1171" id="L1171" rel="#L1171"><i class='fa fa-link'></i>
1171
</a><a href="#L1172" id="L1172" rel="#L1172"><i class='fa fa-link'></i>
1172
</a><a href="#L1173" id="L1173" rel="#L1173"><i class='fa fa-link'></i>
1173
</a><a href="#L1174" id="L1174" rel="#L1174"><i class='fa fa-link'></i>
1174
</a><a href="#L1175" id="L1175" rel="#L1175"><i class='fa fa-link'></i>
1175
</a><a href="#L1176" id="L1176" rel="#L1176"><i class='fa fa-link'></i>
1176
</a><a href="#L1177" id="L1177" rel="#L1177"><i class='fa fa-link'></i>
1177
</a><a href="#L1178" id="L1178" rel="#L1178"><i class='fa fa-link'></i>
1178
</a></div>
<div class='highlight'>
<pre><code class='ft_content_type.strongarm.inc'>&lt;?php
/**
 * @file
 * ft_content_type.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ft_content_type_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_anonymous_article';
  $strongarm-&gt;value = 0;
  $export['comment_anonymous_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_anonymous_challenge';
  $strongarm-&gt;value = 0;
  $export['comment_anonymous_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_anonymous_circle';
  $strongarm-&gt;value = 0;
  $export['comment_anonymous_circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_anonymous_corporate';
  $strongarm-&gt;value = 0;
  $export['comment_anonymous_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_anonymous_page';
  $strongarm-&gt;value = 0;
  $export['comment_anonymous_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_anonymous_question1';
  $strongarm-&gt;value = 0;
  $export['comment_anonymous_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_anonymous_webform';
  $strongarm-&gt;value = 0;
  $export['comment_anonymous_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_anonymous_working_group';
  $strongarm-&gt;value = 0;
  $export['comment_anonymous_working_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_article';
  $strongarm-&gt;value = '2';
  $export['comment_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_challenge';
  $strongarm-&gt;value = '2';
  $export['comment_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_circle';
  $strongarm-&gt;value = '0';
  $export['comment_circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_corporate';
  $strongarm-&gt;value = '0';
  $export['comment_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_mode_article';
  $strongarm-&gt;value = 1;
  $export['comment_default_mode_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_mode_challenge';
  $strongarm-&gt;value = 1;
  $export['comment_default_mode_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_mode_circle';
  $strongarm-&gt;value = 1;
  $export['comment_default_mode_circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_mode_corporate';
  $strongarm-&gt;value = 1;
  $export['comment_default_mode_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_mode_page';
  $strongarm-&gt;value = 1;
  $export['comment_default_mode_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_mode_question1';
  $strongarm-&gt;value = 1;
  $export['comment_default_mode_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_mode_webform';
  $strongarm-&gt;value = 1;
  $export['comment_default_mode_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_mode_working_group';
  $strongarm-&gt;value = 1;
  $export['comment_default_mode_working_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_per_page_article';
  $strongarm-&gt;value = '50';
  $export['comment_default_per_page_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_per_page_challenge';
  $strongarm-&gt;value = '50';
  $export['comment_default_per_page_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_per_page_circle';
  $strongarm-&gt;value = '50';
  $export['comment_default_per_page_circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_per_page_corporate';
  $strongarm-&gt;value = '50';
  $export['comment_default_per_page_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_per_page_page';
  $strongarm-&gt;value = '50';
  $export['comment_default_per_page_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_per_page_question1';
  $strongarm-&gt;value = '50';
  $export['comment_default_per_page_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_per_page_webform';
  $strongarm-&gt;value = '50';
  $export['comment_default_per_page_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_default_per_page_working_group';
  $strongarm-&gt;value = '50';
  $export['comment_default_per_page_working_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_form_location_article';
  $strongarm-&gt;value = 1;
  $export['comment_form_location_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_form_location_challenge';
  $strongarm-&gt;value = 0;
  $export['comment_form_location_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_form_location_circle';
  $strongarm-&gt;value = 1;
  $export['comment_form_location_circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_form_location_corporate';
  $strongarm-&gt;value = 1;
  $export['comment_form_location_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_form_location_page';
  $strongarm-&gt;value = 1;
  $export['comment_form_location_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_form_location_question1';
  $strongarm-&gt;value = 1;
  $export['comment_form_location_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_form_location_webform';
  $strongarm-&gt;value = 1;
  $export['comment_form_location_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_form_location_working_group';
  $strongarm-&gt;value = 1;
  $export['comment_form_location_working_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_page';
  $strongarm-&gt;value = '0';
  $export['comment_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_preview_article';
  $strongarm-&gt;value = '1';
  $export['comment_preview_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_preview_challenge';
  $strongarm-&gt;value = '1';
  $export['comment_preview_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_preview_circle';
  $strongarm-&gt;value = '1';
  $export['comment_preview_circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_preview_corporate';
  $strongarm-&gt;value = '1';
  $export['comment_preview_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_preview_page';
  $strongarm-&gt;value = '1';
  $export['comment_preview_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_preview_question1';
  $strongarm-&gt;value = '1';
  $export['comment_preview_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_preview_webform';
  $strongarm-&gt;value = '1';
  $export['comment_preview_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_preview_working_group';
  $strongarm-&gt;value = '1';
  $export['comment_preview_working_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_question1';
  $strongarm-&gt;value = '2';
  $export['comment_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_subject_field_article';
  $strongarm-&gt;value = 1;
  $export['comment_subject_field_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_subject_field_challenge';
  $strongarm-&gt;value = 0;
  $export['comment_subject_field_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_subject_field_circle';
  $strongarm-&gt;value = 1;
  $export['comment_subject_field_circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_subject_field_corporate';
  $strongarm-&gt;value = 1;
  $export['comment_subject_field_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_subject_field_page';
  $strongarm-&gt;value = 1;
  $export['comment_subject_field_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_subject_field_question1';
  $strongarm-&gt;value = 1;
  $export['comment_subject_field_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_subject_field_webform';
  $strongarm-&gt;value = 1;
  $export['comment_subject_field_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_subject_field_working_group';
  $strongarm-&gt;value = 1;
  $export['comment_subject_field_working_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_webform';
  $strongarm-&gt;value = '0';
  $export['comment_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'comment_working_group';
  $strongarm-&gt;value = '2';
  $export['comment_working_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'field_bundle_settings_node__article';
  $strongarm-&gt;value = array(
    'view_modes' =&gt; array(
      'teaser' =&gt; array(
        'custom_settings' =&gt; TRUE,
      ),
      'full' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'rss' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'search_index' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'search_result' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'diff_standard' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'token' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'revision' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
    ),
    'extra_fields' =&gt; array(
      'form' =&gt; array(
        'title' =&gt; array(
          'weight' =&gt; '-5',
        ),
        'path' =&gt; array(
          'weight' =&gt; '30',
        ),
      ),
      'display' =&gt; array(),
    ),
  );
  $export['field_bundle_settings_node__article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'field_bundle_settings_node__challenge';
  $strongarm-&gt;value = array(
    'view_modes' =&gt; array(
      'teaser' =&gt; array(
        'custom_settings' =&gt; TRUE,
      ),
      'full' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'rss' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'search_index' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'search_result' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'diff_standard' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'token' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'revision' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
    ),
    'extra_fields' =&gt; array(
      'display' =&gt; array(),
      'form' =&gt; array(
        'title' =&gt; array(
          'weight' =&gt; '0',
        ),
        'og_menu' =&gt; array(
          'weight' =&gt; '0',
        ),
        'path' =&gt; array(
          'weight' =&gt; '8',
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'field_bundle_settings_node__circle';
  $strongarm-&gt;value = array(
    'view_modes' =&gt; array(
      'full' =&gt; array(
        'custom_settings' =&gt; TRUE,
      ),
      'teaser' =&gt; array(
        'custom_settings' =&gt; TRUE,
      ),
      'rss' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'search_index' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'search_result' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'question' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'token' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
    ),
    'extra_fields' =&gt; array(
      'form' =&gt; array(
        'title' =&gt; array(
          'weight' =&gt; '0',
        ),
        'og_menu' =&gt; array(
          'weight' =&gt; '0',
        ),
        'path' =&gt; array(
          'weight' =&gt; '2',
        ),
      ),
      'display' =&gt; array(
        'og_extras_nodes_entity_view_1' =&gt; array(
          'default' =&gt; array(
            'weight' =&gt; '10',
            'visible' =&gt; TRUE,
          ),
          'full' =&gt; array(
            'weight' =&gt; '3',
            'visible' =&gt; TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'field_bundle_settings_node__corporate';
  $strongarm-&gt;value = array(
    'view_modes' =&gt; array(),
    'extra_fields' =&gt; array(
      'form' =&gt; array(
        'title' =&gt; array(
          'weight' =&gt; '-5',
        ),
        'path' =&gt; array(
          'weight' =&gt; '30',
        ),
      ),
      'display' =&gt; array(),
    ),
  );
  $export['field_bundle_settings_node__corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'field_bundle_settings_node__page';
  $strongarm-&gt;value = array(
    'view_modes' =&gt; array(
      'teaser' =&gt; array(
        'custom_settings' =&gt; TRUE,
      ),
      'full' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'rss' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'search_index' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'search_result' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'diff_standard' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'token' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'revision' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
    ),
    'extra_fields' =&gt; array(
      'form' =&gt; array(
        'title' =&gt; array(
          'weight' =&gt; '-5',
        ),
        'path' =&gt; array(
          'weight' =&gt; '30',
        ),
      ),
      'display' =&gt; array(
        'language' =&gt; array(
          'default' =&gt; array(
            'weight' =&gt; '1',
            'visible' =&gt; FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'field_bundle_settings_node__question1';
  $strongarm-&gt;value = array(
    'view_modes' =&gt; array(
      'teaser' =&gt; array(
        'custom_settings' =&gt; TRUE,
      ),
      'full' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'rss' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'search_index' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'search_result' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'diff_standard' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'token' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'revision' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
    ),
    'extra_fields' =&gt; array(
      'form' =&gt; array(
        'title' =&gt; array(
          'weight' =&gt; '0',
        ),
        'path' =&gt; array(
          'weight' =&gt; '6',
        ),
      ),
      'display' =&gt; array(),
    ),
  );
  $export['field_bundle_settings_node__question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'field_bundle_settings_node__webform';
  $strongarm-&gt;value = array(
    'view_modes' =&gt; array(
      'teaser' =&gt; array(
        'custom_settings' =&gt; TRUE,
      ),
      'full' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'rss' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'search_index' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'search_result' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'diff_standard' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'token' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
      'revision' =&gt; array(
        'custom_settings' =&gt; FALSE,
      ),
    ),
    'extra_fields' =&gt; array(
      'form' =&gt; array(
        'title' =&gt; array(
          'weight' =&gt; '0',
        ),
        'path' =&gt; array(
          'weight' =&gt; '8',
        ),
      ),
      'display' =&gt; array(
        'webform' =&gt; array(
          'default' =&gt; array(
            'weight' =&gt; '18',
            'visible' =&gt; TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'field_bundle_settings_node__working_group';
  $strongarm-&gt;value = array(
    'view_modes' =&gt; array(),
    'extra_fields' =&gt; array(
      'form' =&gt; array(
        'title' =&gt; array(
          'weight' =&gt; '-5',
        ),
        'og_menu' =&gt; array(
          'weight' =&gt; '0',
        ),
        'path' =&gt; array(
          'weight' =&gt; '30',
        ),
      ),
      'display' =&gt; array(),
    ),
  );
  $export['field_bundle_settings_node__working_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'i18n_node_extended_challenge';
  $strongarm-&gt;value = 1;
  $export['i18n_node_extended_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'i18n_node_extended_corporate';
  $strongarm-&gt;value = 1;
  $export['i18n_node_extended_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'i18n_node_extended_question1';
  $strongarm-&gt;value = 1;
  $export['i18n_node_extended_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'i18n_node_extended_webform';
  $strongarm-&gt;value = 1;
  $export['i18n_node_extended_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'i18n_node_options_challenge';
  $strongarm-&gt;value = array();
  $export['i18n_node_options_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'i18n_node_options_corporate';
  $strongarm-&gt;value = array();
  $export['i18n_node_options_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'i18n_node_options_question1';
  $strongarm-&gt;value = array();
  $export['i18n_node_options_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'i18n_node_options_webform';
  $strongarm-&gt;value = array();
  $export['i18n_node_options_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'language_content_type_article';
  $strongarm-&gt;value = '0';
  $export['language_content_type_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'language_content_type_challenge';
  $strongarm-&gt;value = '0';
  $export['language_content_type_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'language_content_type_circle';
  $strongarm-&gt;value = '0';
  $export['language_content_type_circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'language_content_type_corporate';
  $strongarm-&gt;value = '0';
  $export['language_content_type_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'language_content_type_page';
  $strongarm-&gt;value = '2';
  $export['language_content_type_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'language_content_type_question1';
  $strongarm-&gt;value = '0';
  $export['language_content_type_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'language_content_type_webform';
  $strongarm-&gt;value = '0';
  $export['language_content_type_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'language_content_type_working_group';
  $strongarm-&gt;value = '0';
  $export['language_content_type_working_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_options_article';
  $strongarm-&gt;value = array(
    0 =&gt; 'main-menu',
  );
  $export['menu_options_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_options_challenge';
  $strongarm-&gt;value = array(
    0 =&gt; 'main-menu',
  );
  $export['menu_options_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_options_circle';
  $strongarm-&gt;value = array(
    0 =&gt; 'main-menu',
  );
  $export['menu_options_circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_options_corporate';
  $strongarm-&gt;value = array(
    0 =&gt; 'main-menu',
  );
  $export['menu_options_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_options_page';
  $strongarm-&gt;value = array(
    0 =&gt; 'main-menu',
  );
  $export['menu_options_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_options_question1';
  $strongarm-&gt;value = array(
    0 =&gt; 'main-menu',
  );
  $export['menu_options_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_options_webform';
  $strongarm-&gt;value = array(
    0 =&gt; 'main-menu',
  );
  $export['menu_options_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_options_working_group';
  $strongarm-&gt;value = array(
    0 =&gt; 'main-menu',
  );
  $export['menu_options_working_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_parent_article';
  $strongarm-&gt;value = 'main-menu:0';
  $export['menu_parent_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_parent_challenge';
  $strongarm-&gt;value = 'main-menu:0';
  $export['menu_parent_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_parent_circle';
  $strongarm-&gt;value = 'main-menu:0';
  $export['menu_parent_circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_parent_corporate';
  $strongarm-&gt;value = 'main-menu:0';
  $export['menu_parent_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_parent_page';
  $strongarm-&gt;value = 'main-menu:0';
  $export['menu_parent_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_parent_question1';
  $strongarm-&gt;value = 'main-menu:0';
  $export['menu_parent_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_parent_webform';
  $strongarm-&gt;value = 'main-menu:0';
  $export['menu_parent_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'menu_parent_working_group';
  $strongarm-&gt;value = 'main-menu:0';
  $export['menu_parent_working_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_options_article';
  $strongarm-&gt;value = array(
    0 =&gt; 'status',
    1 =&gt; 'promote',
  );
  $export['node_options_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_options_challenge';
  $strongarm-&gt;value = array(
    0 =&gt; 'status',
    1 =&gt; 'promote',
  );
  $export['node_options_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_options_circle';
  $strongarm-&gt;value = array(
    0 =&gt; 'status',
    1 =&gt; 'promote',
  );
  $export['node_options_circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_options_corporate';
  $strongarm-&gt;value = array(
    0 =&gt; 'status',
    1 =&gt; 'promote',
  );
  $export['node_options_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_options_page';
  $strongarm-&gt;value = array(
    0 =&gt; 'status',
  );
  $export['node_options_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_options_question1';
  $strongarm-&gt;value = array(
    0 =&gt; 'status',
    1 =&gt; 'promote',
  );
  $export['node_options_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_options_webform';
  $strongarm-&gt;value = array(
    0 =&gt; 'status',
    1 =&gt; 'promote',
  );
  $export['node_options_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_options_working_group';
  $strongarm-&gt;value = array(
    0 =&gt; 'status',
    1 =&gt; 'promote',
  );
  $export['node_options_working_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_preview_article';
  $strongarm-&gt;value = '1';
  $export['node_preview_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_preview_challenge';
  $strongarm-&gt;value = '1';
  $export['node_preview_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_preview_circle';
  $strongarm-&gt;value = '1';
  $export['node_preview_circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_preview_corporate';
  $strongarm-&gt;value = '1';
  $export['node_preview_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_preview_page';
  $strongarm-&gt;value = '1';
  $export['node_preview_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_preview_question1';
  $strongarm-&gt;value = '1';
  $export['node_preview_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_preview_webform';
  $strongarm-&gt;value = '1';
  $export['node_preview_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_preview_working_group';
  $strongarm-&gt;value = '1';
  $export['node_preview_working_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_submitted_article';
  $strongarm-&gt;value = 1;
  $export['node_submitted_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_submitted_challenge';
  $strongarm-&gt;value = 1;
  $export['node_submitted_challenge'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_submitted_circle';
  $strongarm-&gt;value = 1;
  $export['node_submitted_circle'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_submitted_corporate';
  $strongarm-&gt;value = 1;
  $export['node_submitted_corporate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_submitted_page';
  $strongarm-&gt;value = 0;
  $export['node_submitted_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_submitted_question1';
  $strongarm-&gt;value = 1;
  $export['node_submitted_question1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_submitted_webform';
  $strongarm-&gt;value = 1;
  $export['node_submitted_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm-&gt;disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm-&gt;api_version = 1;
  $strongarm-&gt;name = 'node_submitted_working_group';
  $strongarm-&gt;value = 1;
  $export['node_submitted_working_group'] = $strongarm;

  return $export;
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
