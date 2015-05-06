/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/

#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n);
#define pdl(n) printf("%lf\n",n);
#define pin(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (ll)(1e9 + 7)
#define ll long long int
#define MAX 1000006
#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif
ll B[] = {1,500000004,166666668,0,766666672,0,23809524,0,766666672,0,348484851,0,469963373,0,166666669,0,413725486,0,865914848,0,948484326,0,427542427,0,469876793,0,168092185,0,980747753,0,678176322,0,297409831,0,781306726,0,35337905,0,482221937,0,83084250,0,310292012,0,334581823,0,437628892,0,708314481,0,860344292,0,643009310,0,159517512,0,742356578,0,392872747,0,465850017,0,647900229,0,431346688,0,461733065,0,255588829,0,307276324,0,610411531,0,197137262,0,18565655,0,852238879,0,284923925,0,483196916,0,208794235,0,148591948,0,244784253,0,416223553,0,138705149,0,711847843,0,394739272,0,39530788,0,94103270,0,944699132,0,555008829,0,134395782,0,775574192,0,526027076,0,366329102,0,997501812,0,64960653,0,917154602,0,537182455,0,171713000,0,799849313,0,974650756,0,764681019,0,129465940,0,514970793,0,185828032,0,874015104,0,8063031,0,637955273,0,873230471,0,104279039,0,836586090,0,597557491,0,392225623,0,676908015,0,88768944,0,498487309,0,451730794,0,566607730,0,444106794,0,181463496,0,127835995,0,763021163,0,570276863,0,393273175,0,462754189,0,379663078,0,318486088,0,208134750,0,178450624,0,960012260,0,180738104,0,756632653,0,645210773,0,79148833,0,45135138,0,965798517,0,513668750,0,569147985,0,377199181,0,822327589,0,256265266,0,791964162,0,29587355,0,327610019,0,862621077,0,549923786,0,132821305,0,674078980,0,961947656,0,919724059,0,689243733,0,72331329,0,586420422,0,773720988,0,443408114,0,908991031,0,207009656,0,296402826,0,77102696,0,369815072,0,310161627,0,631457613,0,604069632,0,716006985,0,510023389,0,167568388,0,694658101,0,706710536,0,838416939,0,240289128,0,696217436,0,343729523,0,34462081,0,373123193,0,279501781,0,519692461,0,869446785,0,529273692,0,499794482,0,658700293,0,493702151,0,342395770,0,729371213,0,301819236,0,128980415,0,132306570,0,241791898,0,492800463,0,663928117,0,609246064,0,742804971,0,191205480,0,733562164,0,534291334,0,100454741,0,680938365,0,112611490,0,518509669,0,515895557,0,650367989,0,482520941,0,608281652,0,132944223,0,980310087,0,492175239,0,276254120,0,937618650,0,342877120,0,603124736,0,499580133,0,956083803,0,647937936,0,391675275,0,551847266,0,189330612,0,536587296,0,137527475,0,634139293,0,547079242,0,62582319,0,874691594,0,953985920,0,123065123,0,102680251,0,598629189,0,765865958,0,122003913,0,5388217,0,985831463,0,35749021,0,5485253,0,610847551,0,957553266,0,966107971,0,434637748,0,891023940,0,368937249,0,743121746,0,647582764,0,394861194,0,259611444,0,401218546,0,280958587,0,146726474,0,73728156,0,420484782,0,860432061,0,263555720,0,171370950,0,288940895,0,433962809,0,12810405,0,389000258,0,232347992,0,457377160,0,611980685,0,931117158,0,528373281,0,776924478,0,895196991,0,52260137,0,103734862,0,534188375,0,528819173,0,515009883,0,358459629,0,411876639,0,110831030,0,369807092,0,151928066,0,481598434,0,213781569,0,946564591,0,22612993,0,147058031,0,705049590,0,671160341,0,274407250,0,803279265,0,296028218,0,829477416,0,627699152,0,889545991,0,602277421,0,440283672,0,574919593,0,151551215,0,467285232,0,590802585,0,914358666,0,760187446,0,475666672,0,666337315,0,666685349,0,972161058,0,141242138,0,210381798,0,330198584,0,489119877,0,165342809,0,412027566,0,35036448,0,301656123,0,275725170,0,723660845,0,97140868,0,687293653,0,756858419,0,740061355,0,477765430,0,978160109,0,170517295,0,603571894,0,856182503,0,315060077,0,604702699,0,188059190,0,746154800,0,590957649,0,598277218,0,632775339,0,664543162,0,2176347,0,672563104,0,128051225,0,589594871,0,122041955,0,448233270,0,648217760,0,348479553,0,3463898,0,601897670,0,948217634,0,981358001,0,667164726,0,394191524,0,925543283,0,325843658,0,541338833,0,746489435,0,91488040,0,715678547,0,750655274,0,814132750,0,116397711,0,914346845,0,556250432,0,324132590,0,690119570,0,828813439,0,239695356,0,365272463,0,666187216,0,195595943,0,421967346,0,775431091,0,962497750,0,26142436,0,83393779,0,705969466,0,91227746,0,753015148,0,413503277,0,931653254,0,580717169,0,154398267,0,837431357,0,350394676,0,451728855,0,255961371,0,646092315,0,193948002,0,229698568,0,24114743,0,600293174,0,92511515,0,119801205,0,836131171,0,11051624,0,402298382,0,379031843,0,726940835,0,701472598,0,810405972,0,232826697,0,66223100,0,314900196,0,714385546,0,432605375,0,653849391,0,215662321,0,305796813,0,198384728,0,360640745,0,597797231,0,962965419,0,233437891,0,390675234,0,358927306,0,440784360,0,416144987,0,736130703,0,923999423,0,421227050,0,937497055,0,904911796,0,177537196,0,832966398,0,955747054,0,769028146,0,217829919,0,121312046,0,642425322,0,16482376,0,595844855,0,577119793,0,317026562,0,954366898,0,828469135,0,962293354,0,385244332,0,665114228,0,410022759,0,112347819,0,168547779,0,152521210,0,52115211,0,578426471,0,541479976,0,259759934,0,328695806,0,816904224,0,959827211,0,507215664,0,910936985,0,547178368,0,134666216,0,270841805,0,188889050,0,204016097,0,373911022,0,516605109,0,809450330,0,867867022,0,412200713,0,123461364,0,54686621,0,335364566,0,565701631,0,761346648,0,375958382,0,291271867,0,169228778,0,929819070,0,344008620,0,397270941,0,341713260,0,557438041,0,975894363,0,220974084,0,304187612,0,82742958,0,747790793,0,622077487,0,170945937,0,907505719,0,908097107,0,327932984,0,351751775,0,134879555,0,330690210,0,395457038,0,466835879,0,914274480,0,739247533,0,91394730,0,109420689,0,785342130,0,511158008,0,964424181,0,792887384,0,422772213,0,513370334,0,606290202,0,267324432,0,619123502,0,268619297,0,455319584,0,949580630,0,294472744,0,251873935,0,194966337,0,977958395,0,453441611,0,202648831,0,469022610,0,921283067,0,592849363,0,825258420,0,146297264,0,729026590,0,717160336,0,365993381,0,92261170,0,219584935,0,315450728,0,403464842,0,960156873,0,69810174,0,435551605,0,1412253,0,941905734,0,698038089,0,717005321,0,77477037,0,270474705,0,601555224,0,635487116,0,841345296,0,322347063,0,67096504,0,839915524,0,406371237,0,528931370,0,18278769,0,247546212,0,875698645,0,23327113,0,35115245,0,80637764,0,973745532,0,515280823,0,341936397,0,67429829,0,765714429,0,574598713,0,840447354,0,206666322,0,674749538,0,842767205,0,16011385,0,881411065,0,79476894};

ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
ll choose[1003][1003];
ll inverse[MAX];
inline ll checkit(ll n)
{
	ll calc=n;
	if(calc<0)
	{
		calc=-calc;
		calc%=mod;
		calc*=(mod-1);
	}
	calc%=mod;
	return calc;
}
int main()
{
	ll i,j,k,ans,n,calc,c,t,c1,fin;
	FOR(i,0,1003)
	{
		choose[i][i]=choose[i][0]=1;
	}
	FOR(i,1,1003)
	{
		FOR(j,1,i)
		{
			choose[i][j]=choose[i-1][j-1]+choose[i-1][j];
			choose[i][j]%=mod;
		}
	}
	sl(t);
	while(t--)
	{
		sl(n); sl(k);
		n%=mod
		calc=modpow(k+1, mod-2, mod);
		ans=0;
		rep(i,k+1)
		{
			c=choose[k+1][i]*B[i];
			c=checkit(c);
			c1=modpow(n,k+1-i,mod);
			fin=c*c1;
			fin=checkit(fin);
			//trace6(i,k+1,choose[k+1][i], B[i], c, c1);
			ans+=fin;
			//trace1(fin);
			ans=checkit(ans);
		}
		ans*=calc;
		ans=checkit(ans);
		pln(ans);
	}
	return 0;
}












