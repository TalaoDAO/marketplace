var admin_pathConfig = {};

admin_pathConfig.array = [
'/user/logout',
'/',
'/contact',
'/node/add/request',
'/circles',
'/admin/reports/status',
//'/admin/reports/dblog',
'/admin/emindhub/credits', 
'/admin/emindhub/credits/transaction-log',
'/user',
'/user/1/edit',
'/content/cercle-de-test',
'/admin/people'
]

module.exports.admin_paths = admin_pathConfig;

var ybabel_pathConfig = {};

ybabel_pathConfig.array = [
'/user/logout',
'/',
'/contact',
'/node/add/request',
'/circles',
'/user',
'/user/3/edit',
'/answers/my',
'/answers/to-me',
'/requests',
'/request/manage',
'/request/selection',
'/buy-credits',
'/credits',
'/node/1980',
'/user/3/change-password'
]

module.exports.ybabel_paths = ybabel_pathConfig;


var anon_pathConfig = {};

anon_pathConfig.array = ['/',
'/contact',
'/legal/document/terms-of-use',
'/client/register',
'/expert/register',
'/how-it-works',
'/about-us',
'/open-requests',
'/publications',
'/domains',
'/legal/document/terms-of-use',
'/faq-client',
'/faq-expert',
'/content/legal-notices',
'/fr/comment-ça-marche',
'/fr/domains',
'/fr/open-requests',
'/fr/publications',
'/fr/legal/document/terms-of-use'
]


module.exports.anon_paths = anon_pathConfig;

