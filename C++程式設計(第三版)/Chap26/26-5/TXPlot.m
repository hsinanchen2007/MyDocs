clear all
X = [
 0.50000  0.00000;
 0.49959  -0.02061;
 0.49833  -0.04246;
 0.49618  -0.06560;
 0.49307  -0.09008;
 0.48895  -0.11597;
 0.48377  -0.14334;
 0.47746  -0.17227;
 0.46997  -0.20285;
 0.46121  -0.23519;
 0.45113  -0.26942;
 0.43963  -0.30567;
 0.42664  -0.34410;
 0.41207  -0.38490;
 0.39582  -0.42827;
 0.37777  -0.47443;
 0.35782  -0.52365;
 0.33584  -0.57622;
 0.31168  -0.63243;
 0.28519  -0.69262;
 0.25621  -0.75717;
 0.22455  -0.82644;
 0.19003  -0.90083;
 0.15241  -0.98070;
 0.11149  -1.06639;
 0.06702  -1.15819;
 0.01875  -1.25626;
-0.03356  -1.36058;
-0.09017  -1.47088;
-0.15130  -1.58651;
-0.21715  -1.70633;
-0.28784  -1.82856;
-0.36343  -1.95062;
-0.44385  -2.06903;
-0.52885  -2.17928;
-0.61801  -2.27592;
-0.71066  -2.35275;
-0.80587  -2.40322;
-0.90248  -2.42115;
-0.99907  -2.40151;
-1.09406  -2.34140;
-1.18583  -2.24069;
-1.27281  -2.10245;
-1.35361  -1.93274;
-1.42712  -1.73984;
-1.49261  -1.53320;
-1.54972  -1.32222;
-1.59844  -1.11521;
-1.63908  -0.91873;
-1.67215  -0.73734;
-1.69830  -0.57364;
-1.71829  -0.42863;
-1.73284  -0.30203;
-1.74268  -0.19275;
-1.74847  -0.09921;
-1.75080  -0.01960;
-1.75020  0.04794;
-1.74710  0.10516;
-1.74190  0.15368;
-1.73491  0.19494;
-1.72639  0.23017;
-1.71656  0.26044;
-1.70561  0.28665;
-1.69367  0.30956;
-1.68088  0.32979;
-1.66732  0.34787;
-1.65307  0.36424;
-1.63820  0.37925;
-1.62274  0.39322;
-1.60675  0.40639;
-1.59024  0.41898;
-1.57324  0.43118;
-1.55575  0.44313;
-1.53779  0.45497;
-1.51935  0.46684;
-1.50044  0.47883;
-1.48104  0.49104;
-1.46115  0.50357;
-1.44075  0.51652;
-1.41982  0.52996;
-1.39835  0.54399;
-1.37629  0.55870;
-1.35364  0.57419;
-1.33035  0.59056;
-1.30638  0.60792;
-1.28170  0.62638;
-1.25625  0.64608;
-1.22999  0.66716;
-1.20286  0.68979;
-1.17479  0.71414;
-1.14570  0.74041;
-1.11553  0.76884;
-1.08416  0.79968;
-1.05152  0.83323;
-1.01747  0.86983;
-0.98188  0.90986;
-0.94462  0.95377;
-0.90552  1.00205;
-0.86440  1.05528;
-0.82103  1.11412;
-0.77518  1.17932;
-0.72659  1.25174;
-0.67493  1.33233;
-0.61988  1.42218;
-0.56102  1.52245;
-0.49792  1.63442;
-0.43009  1.75939;
-0.35698  1.89867;
-0.27799  2.05335;
-0.19250  2.22421;
-0.09984  2.41131;
 0.00061  2.61356;
 0.10941  2.82811;
 0.22695  3.04958;
 0.35335  3.26918;
 0.48829  3.47405;
 0.63085  3.64706;
 0.77936  3.76767;
 0.93128  3.81443;
 1.08328  3.76911;
 1.23144  3.62165;
 1.37168  3.37444;
 1.50028  3.04345;
 1.61439  2.65555;
 1.71239  2.24253;
 1.79386  1.83438;
 1.85952  1.45438;
 1.91079  1.11704;
 1.94953  0.82857;
 1.97773  0.58897;
 1.99725  0.39424;
 2.00979  0.23851;
 2.01677  0.11535;
 2.01937  0.01863;
 2.01854  -0.05703;
 2.01502  -0.11616;
 2.00941  -0.16245;
 2.00216  -0.19882;
 1.99361  -0.22759;
 1.98403  -0.25052;
 1.97363  -0.26901;
 1.96255  -0.28411;
 1.95093  -0.29662;
 1.93885  -0.30718;
 1.92638  -0.31626;
 1.91356  -0.32422;
 1.90045  -0.33135;
 1.88707  -0.33786;
 1.87343  -0.34392;
 1.85956  -0.34967;
 1.84546  -0.35520;
 1.83114  -0.36061;
 1.81661  -0.36595;
 1.80187  -0.37128;
 1.78691  -0.37664;
 1.77173  -0.38208;
 1.75634  -0.38763;
 1.74072  -0.39330;
 1.72487  -0.39914;
 1.70879  -0.40516;
 1.69246  -0.41139;
 1.67587  -0.41785;
 1.65903  -0.42456;
 1.64191  -0.43154;
 1.62450  -0.43882;
 1.60679  -0.44643;
 1.58878  -0.45439;
 1.57044  -0.46273;
 1.55176  -0.47148;
 1.53271  -0.48067;
 1.51330  -0.49034;
 1.49348  -0.50054;
 1.47325  -0.51129;
 1.45257  -0.52266;
 1.43142  -0.53470;
 1.40978  -0.54746;
 1.38762  -0.56101;
 1.36489  -0.57542;
 1.34157  -0.59078;
 1.31762  -0.60717;
 1.29298  -0.62471;
 1.26762  -0.64351;
 1.24148  -0.66368;
 1.21451  -0.68540;
 1.18663  -0.70881;
 1.15778  -0.73411;
 1.12787  -0.76152;
 1.09682  -0.79128;
 1.06453  -0.82366;
 1.03089  -0.85900;
 0.99577  -0.89764;
 0.95903  -0.94002;
 0.92051  -0.98661;
 0.88004  -1.03795;
 0.83740  -1.09469;
 0.79238  -1.15753;
 0.74471  -1.22729;
 0.69409  -1.30489;
 0.64020  -1.39138;
 0.58265  -1.48789;
 0.52102  -1.59566;
 0.45483  -1.71601;
 0.38355  -1.85024;
 0.30661  -1.99955;
 0.22337  -2.16485;
 0.13320  -2.34650;
 0.03544  -2.54387;
-0.07049  -2.75480;
-0.18506  -2.97487;
-0.30850  -3.19656;
-0.44066  -3.40845;
-0.58084  -3.59481;
-0.72764  -3.73607;
-0.87884  -3.81066;
-1.03134  -3.79864;
-1.18139  -3.68658;
-1.32490  -3.47223;
-1.45795  -3.16704;
-1.57736  -2.79476;
-1.68105  -2.38629;
-1.76820  -1.97299;
-1.83917  -1.58089;
-1.89519  -1.22756;
-1.93802  -0.92187;
-1.96961  -0.66569;
-1.99189  -0.45611;
-2.00664  -0.28771;
-2.01537  -0.15409;
-2.01935  -0.04897;
-2.01960  0.03333;
-2.01692  0.09764;
-2.01197  0.14794;
-2.00523  0.18739;
-1.99709  0.21851;
-1.98784  0.24325;
-1.97770  0.26311;
-1.96684  0.27925;
-1.95539  0.29255;
-1.94346  0.30371;
-1.93112  0.31323;
-1.91842  0.32153;
-1.90541  0.32891;
-1.89212  0.33560;
-1.87857  0.34179;
-1.86478  0.34762;
-1.85076  0.35321;
-1.83652  0.35865;
-1.82207  0.36400;
-1.80740  0.36932;
-1.79252  0.37466;
-1.77743  0.38006;
-1.76212  0.38556;
-1.74658  0.39118;
-1.73082  0.39695;
-1.71483  0.40290;
-1.69859  0.40905;
-1.68210  0.41541;
-1.66535  0.42202;
-1.64833  0.42890;
-1.63103  0.43607;
-1.61344  0.44355;
-1.59555  0.45138;
-1.57733  0.45957;
-1.55877  0.46816;
-1.53987  0.47719;
-1.52059  0.48667;
-1.50093  0.49667;
-1.48085  0.50721;
-1.46034  0.51834;
-1.43938  0.53012;
-1.41792  0.54260;
-1.39596  0.55585;
-1.37345  0.56993;
-1.35035  0.58493;
-1.32664  0.60092;
-1.30226  0.61802;
-1.27718  0.63633;
-1.25134  0.65598;
-1.22468  0.67710;
-1.19715  0.69986;
-1.16867  0.72443;
-1.13917  0.75103;
-1.10856  0.77987;
-1.07674  0.81124;
-1.04362  0.84544;
-1.00907  0.88280;
-0.97295  0.92373;
-0.93511  0.96868;
-0.89539  1.01818;
-0.85359  1.07283;
-0.80949  1.13330;
-0.76284  1.20037;
-0.71336  1.27493;
-0.66073  1.35797;
-0.60459  1.45060;
-0.54454  1.55402;
-0.48011  1.66951;
-0.41080  1.79841;
-0.33604  1.94196;
-0.25523  2.10121;
-0.16773  2.27677;
-0.07288  2.46842;
 0.02994  2.67467;
 0.14125  2.89202;
 0.26137  3.11422;
 0.39032  3.33137;
 0.52762  3.52938;
 0.67217  3.68995;
 0.82204  3.79196;
 0.97446  3.81432;
 1.12590  3.74056;
 1.27233  3.56382;
 1.40971  3.29036;
 1.53452  2.93975;
 1.64425  2.54100;
 1.73759  2.12608;
 1.81450  1.72353;
 1.87592  1.35423;
 1.92345  1.03021;
 1.95900  0.75567;
 1.98454  0.52923;
 2.00192  0.34618;
 2.01273  0.20033;
 2.01835  0.08527;
 2.01989  -0.00494;
 2.01822  -0.07546;
 2.01405  -0.13058;
 2.00793  -0.17375;
 2.00028  -0.20773;
 1.99141  -0.23466;
 1.98158  -0.25618;
 1.97097  -0.27359;
 1.95973  -0.28787;
 1.94797  -0.29976;
 1.93577  -0.30984;
 1.92320  -0.31856;
 1.91030  -0.32624;
 1.89711  -0.33317;
 1.88366  -0.33953;
 1.86995  -0.34548;
 1.85602  -0.35115;
 1.84187  -0.35663;
 1.82749  -0.36200;
 1.81291  -0.36733;
 1.79811  -0.37266;
 1.78309  -0.37804;
 1.76786  -0.38349;
 1.75241  -0.38907;
 1.73673  -0.39478;
 1.72083  -0.40066;
 1.70468  -0.40673;
 1.68829  -0.41301;
 1.67164  -0.41953;
 1.65472  -0.42630;
 1.63753  -0.43336;
 1.62005  -0.44072;
 1.60227  -0.44842;
 1.58417  -0.45647;
 1.56574  -0.46491;
 1.54697  -0.47376;
 1.52784  -0.48307;
 1.50832  -0.49287;
 1.48840  -0.50321;
 1.46805  -0.51411;
 1.44726  -0.52564;
 1.42599  -0.53786;
 1.40422  -0.55081;
 1.38192  -0.56457;
 1.35905  -0.57921;
 1.33557  -0.59483;
 1.31145  -0.61150;
 1.28663  -0.62935;
 1.26108  -0.64848;
 1.23474  -0.66903;
 1.20754  -0.69116;
 1.17942  -0.71503;
 1.15031  -0.74084;
 1.12012  -0.76882;
 1.08877  -0.79922;
 1.05615  -0.83232;
 1.02215  -0.86845;
 0.98663  -0.90800;
 0.94945  -0.95139;
 0.91046  -0.99913;
 0.86946  -1.05178;
 0.82624  -1.10999;
 0.78058  -1.17450;
 0.73219  -1.24615;
 0.68078  -1.32590;
 0.62599  -1.41481;
 0.56745  -1.51405;
 0.50471  -1.62489;
 0.43729  -1.74863;
 0.36464  -1.88657;
 0.28616  -2.03986;
 0.20123  -2.20929;
 0.10920  -2.39503;
 0.00942  -2.59611;
-0.09866  -2.80988;
-0.21547  -3.03122;
-0.34115  -3.25167;
-0.47543  -3.45875;
-0.61745  -3.63567;
-0.76561  -3.76210;
-0.91745  -3.81649;
-1.06971  -3.78005;
-1.21849  -3.64178;
-1.35971  -3.40281;
-1.48957  -3.07800;
-1.60515  -2.69350;
-1.70468  -2.28097;
-1.78766  -1.87089;
-1.85470  -1.48730;
-1.90720  -1.14550;
-1.94700  -0.85240;
-1.97605  -0.60842;
-1.99628  -0.40984;
-2.00937  -0.25085;
-2.01679  -0.12503;
-2.01973  -0.02619;
-2.01917  0.05114;
-2.01586  0.11156;
-2.01042  0.15884;
-2.00329  0.19597;
-1.99484  0.22531;
-1.98535  0.24869;
-1.97501  0.26750;
-1.96399  0.28285;
-1.95242  0.29556;
-1.94037  0.30626;
-1.92794  0.31544;
-1.91515  0.32348;
-1.90207  0.33066;
-1.88871  0.33721;
-1.87510  0.34330;
-1.86125  0.34906;
-1.84718  0.35460;
-1.83289  0.36001;
-1.81838  0.36534;
-1.80366  0.37067;
-1.78872  0.37602;
-1.77358  0.38144;
-1.75821  0.38697;
-1.74262  0.39263;
-1.72679  0.39844;
-1.71074  0.40444;
-1.69444  0.41064;
-1.67788  0.41706;
-1.66107  0.42374;
-1.64398  0.43069;
-1.62661  0.43793;
-1.60894  0.44550;
-1.59097  0.45342;
-1.57266  0.46171;
-1.55402  0.47040;
-1.53503  0.47954;
-1.51565  0.48915;
-1.49589  0.49928;
-1.47570  0.50997;
-1.45508  0.52126;
-1.43399  0.53321;
-1.41241  0.54588;
-1.39031  0.55933;
-1.36766  0.57364;
-1.34441  0.58888;
-1.32053  0.60514;
-1.29598  0.62254;
-1.27071  0.64117;
-1.24467  0.66118;
-1.21780  0.68270;
-1.19003  0.70590;
-1.16130  0.73096;
-1.13153  0.75811;
-1.10062  0.78757;
-1.06849  0.81962;
-1.03501  0.85458;
-1.00008  0.89280;
-0.96354  0.93471;
-0.92525  0.98076;
-0.88502  1.03150;
-0.84265  1.08756;
-0.79793  1.14962;
-0.75059  1.21850;
-0.70035  1.29511;
-0.64687  1.38047;
-0.58978  1.47571;
-0.52866  1.58206;
-0.46305  1.70082;
-0.39242  1.83332;
-0.31619  1.98075;
-0.23374  2.14410;
-0.14444  2.32379;
-0.04763  2.51935;
 0.05729  2.72883;
 0.17081  2.94813;
 0.29318  3.17015;
 0.42432  3.38396;
 0.56359  3.57436;
 0.70970  3.72217;
 0.86051  3.80591;
 1.01304  3.80521;
];
h = 0.04000;
t=[0:500]*h;
set(0, 'defaultaxeslinestyleorder','-|-.');
set(0, 'defaultaxescolororder', [0 0 0]);
plot(t,X), legend('X_1', 'X_2')
title ('van der Pol Oscillator 變化圖')
xlabel('時間 (sec)')
ylabel('X_1 和 X_2')
grid on
