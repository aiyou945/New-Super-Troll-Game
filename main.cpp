#include<bits/stdc++.h>
#include<Windows.h>
#include<io.h>
#include<fstream>
#include<thread>
#include<cstdlib>
#include "init.hpp"
using namespace std;
int coin = 0;
int ac[2] = {0,0};
int cs[3];
int c[4] = {0,2,0,0};
string content = "";
void read(HANDLE handle){
	scolor(handle,gray);
	cout << "离线登录" << endl; 
	scolor(handle,light_green);
	cout << "请输入读档码(./file/userdata.txt)" << endl;
	colorclear(handle);
	string input;
	cin >> input;
	coin = in_coin(input);
	char_change(input[2],ac,handle);
	if(input[1] != '0' && input[1] != 'p' && input[1] != 'f'){
		cs[1] = input[1] - 'a' + 1;
		if(cs[1] >= 5 || (input[1] >= '1' && input[1] <= '9')){
			scolor(handle,light_red); cout << "读入存档码错误,代码:0x01" << endl;
			wait(1);
			colorclear(handle);
			throw 1;
		}
	}
	else if(input[1] == 'p') cs[1] = 4;
	else if(input[1] == 'f') cs[1] = 5;
	else cs[1] = 0;
	scolor(handle,light_green);
	cout << "是否允许该程序访问您的网络?(0/1)" << endl;
	colorclear(handle);
	int input2;
	cin >> input2;
	if(input2 == 1){
		system("curl -s https://aiyou945.github.io/ckg/data.txt > data.txt");
		ifstream file("data.txt");
		getline(file,content);
		file.close();
	}
	else if(input2 != 1 && input2 != 0){
		scolor(handle,light_red); cout << "读入数据错误,代码:0x11" << endl;
		wait(1);
		colorclear(handle);
		throw -1; 
	}
	cls();
}
void output(string str){
	ofstream("userdata.txt") << str;
}
string notice_in(){
	ifstream file("./strings/notice1.ckg");
	string content,line;
	while(getline(file,line)){
		content += line + "\n";
	} 
	file.close();
	return content;
}
void print(string str,HANDLE handle){
	scolor(handle,light_purple);
	for(int i = 0;i < str.size();i++){
		if(str[i] != ' ') cout << str[i];
		else cout << endl;
		wait(0.03);
	}
	colorclear(handle);
	cout << endl;
}
void case1(HANDLE handle){
	cls();
	if(cs[1] == 0 && c[2] == 0){
		string s1 = "你重重摔落在地上,你环顾四周,发现自己身处在一个黑暗且潮湿的通道中 你不禁联想到这几天电视播报的人口失踪案件,警方目前没有找到任何线索 你根本记不清你是怎么来到这里的,不管如何,你打算先从这里出去 殊不知,你将会在这个亿--点都不坑的矩阵里找到一个惊天的秘密...... ";
		print(s1,handle);
		cout << "按任意键继续游戏" << endl; 
		pause();
	}
	cls();
	int mp[10][10] = {1,1,1,1,1,1,1,1,1,1,
					  1,0,0,0,0,0,0,0,0,1,
					  1,0,1,1,1,1,1,1,0,1,
					  1,0,1,1,1,1,1,1,0,1,
					  1,0,0,0,0,0,0,1,0,1,
					  1,1,1,1,1,1,0,0,0,1,
					  1,0,0,0,0,0,1,1,0,1,
					  1,1,1,1,1,0,0,0,0,1,
					  1,2,0,0,0,0,1,1,1,1,
					  1,1,1,1,1,1,1,1,1,1};
	int x = 1,y = 1;
	bool door = false,y1 = false,y2 = false;
	int times = 0;
	while(true){
		cls();
		scolor(handle,light_purple);
		if(door == false && y1 == false && y2 == false) cout << "尝试着使用W,A,S,D控制角色进入大门吧!" << endl << endl;
		else if(door == true && y1 == false && y2 == false) cout << "你没有钥匙打不开门,钥匙就在地图的某个角落,加油!" << endl << endl;
		else if(door == true && y1 == true && y2 == false) cout << "钥匙:我先溜了,再见~~~" << endl << endl;
		else if(door == true && y1 == true && y2 == true) cout << "钥匙:还想抓住我?没门!!!!!" << endl << endl;
		else cout << "你把钥匙成功制服了,快去开门吧!\n钥匙:嘤嘤嘤,为我花生~" << endl << endl;
		for(int i = 0;i < 10;i++){
			for(int j = 0;j < 10;j++){
				if(x == i && y == j){
					colorclear(handle);
					cout << "我";
				} else if(mp[i][j] == 1){
					scolor(handle,light_green);
					cout << "墙";
				} else if(mp[i][j] == 0){
					cout << "  ";
				} else if(mp[i][j] == 2){
					scolor(handle,light_blue);
					cout << "门";
				} else if(mp[i][j] == 3){
					scolor(handle,light_yellow);
					cout << "钥";
				}
			}
			cout << endl;
		}
		colorclear(handle);
		pause();
		if(KEY_DOWN(68) && y + 1 <= 8 && mp[x][y + 1] != 1) y++;
		if(KEY_DOWN(65) && y - 1 >= 1 && mp[x][y - 1] != 1) y--;
		if(KEY_DOWN(83) && x + 1 <= 8 && mp[x + 1][y] != 1) x++;
		if(KEY_DOWN(87) && x - 1 >= 1 && mp[x - 1][y] != 1) x--;
		if(door == false && y1 == false && y2 == false && x == 8 && y == 1){
			door = true;
			if(c[1] == 2 || c[1] == 3){
				times = 2;
				x = 7,y = 5;
			}
			mp[1][8] = 3;
		}
		if(times == 2 && (x == 6 || y == 6)) times = -1;
		if(door == true && y1 == false && y2 == false && x == 8 && y == 1 && (c[1] == 2 || c[1] == 3) && times == 2) break;
		if(door == true && y1 == false && y2 == false && x == 1 && y == 8){
			y1 = true;
			mp[1][8] = 0;
			mp[6][1] = 3;
		}
		if(door == true && y1 == true && y2 == false && x == 6 && y == 1){
			y2 = true;
			mp[6][1] = 0;
			mp[1][2] = 3;
		}
		if(door == true && y1 == true && y2 == true && x == 1 && y == 2){
			y1 = false;
			mp[1][2] = 0;
		}
		if(door == true && y1 == true && y2 == true && x == 8 && y == 1){
			if(c[1] == 1) break;
			else{
				cls();
				string s1 = "你没有带来钥匙,门十分生气, 你还想辩解几句,但门根本不听,把你秒杀了 通关失败";
				print(s1,handle);
				cout << endl << "按任意键返回首页" << endl;
				return ;
			}
		}
		if(door == true && y1 == false && y2 == true && x == 8 && y == 1){
			cls();
			string s1 = "你带着制服了的钥匙来到门前,门却生气地把你秒杀了 原来这把钥匙是门失散多年的哥哥,他以为是你绑架了他 通关失败";
			print(s1,handle);
			cout << endl << "按任意键返回首页" << endl;
			return ;
		}
		cout << endl;
	}
	cls();
	string s1 = "";
	if(c[1] == 1) s1 = "你虽然没有带来钥匙,但门看在你很努力的份上,就勉为其难地帮你指引了出口的方向 你赶紧走出门,却发现自己来到了一个新的迷宫中 原来这是一个巨大的矩阵,你必须通过好几个迷宫才能逃出生天 恭喜解锁第二关:千万别手欠!";
	else s1 = "你生气极了,觉得自己被门戏弄了,你一脚向门踹去 哐当一声,可怜的门被你踹飞了出去,在天空中划出了一道完美的曲线...... 你赶紧走出去,却发现自己来到了一个新的迷宫中 原来这是一个巨大的矩阵,你必须通过好几个迷宫才能逃出生天 恭喜解锁第二关:千万别手欠!";
	print(s1,handle);
	if(cs[1] == 0){
		cs[1] = 1;
		string str = out(coin,1,ac,0);
		output(str);
	}
	return ;
}
void case2(HANDLE handle){
	cls();
	string s2 = "";
	if(cs[1] == 1 && c[2] == 0){
		s2 = "你的头上出现了一个提示:千万别手欠! 你瞬间回想起在一款名为超坑小游戏v2.5.0的游戏里的惨痛经历...... 好在你积攒了足够的经验,继续努力吧!";
		print(s2,handle);
		cout << endl << "按任意键继续游戏" << endl;
		pause();
	}
	int mp[12][12] = {1,3,1,1,1,1,1,1,1,1,1,1,
	                  1,0,0,0,0,0,0,0,0,0,0,1,
					  1,9,1,1,1,1,1,1,1,1,0,1,
					  1,0,0,0,0,0,0,0,0,0,0,1,
					  1,0,1,1,1,1,1,1,1,1,1,1,
					  1,0,0,0,0,0,0,0,0,0,0,1,
					  1,9,1,1,1,1,1,1,1,1,0,1,
					  1,0,0,0,0,0,0,0,0,0,0,1,
					  1,0,1,1,1,1,1,1,1,1,1,1,
					  1,0,0,0,0,0,0,0,0,0,0,3,
					  1,1,1,1,1,1,1,1,1,1,2,1,
					  1,1,1,1,1,1,1,1,1,1,1,1};
	if(c[1] == 3) mp[9][11] = 1;
	if(c[1] == 1){mp[2][1] = 1;mp[6][1] = 1;}
	int x = 1,y = 1;
	bool left = false,right = false;
	int K = 0,I = 0,L = 0;
	while(true){
		cls();
		scolor(handle,light_purple);
		if(left == false && right == false) cout << "任务1:不要向左走!" << endl << endl;
		else if(left == true && right == false) cout << "任务2:不要向右走!" << endl << endl;
		else if(left == true && right == true && c[1] <= 2) cout << "任务3:不要进门!" << endl << endl;
		else {scolor(handle,red);cout << "任务3:不要进门!" << endl << endl;}
		for(int i = 0;i < 12;i++){
			for(int j = 0;j < 12;j++){
				if(x == i && y == j){
					colorclear(handle);
					cout << "我";
				} else if(mp[i][j] == 1){
					scolor(handle,light_green);
					cout << "墙";
				} else if(mp[i][j] == 0){
					cout << "  ";
				} else if(mp[i][j] == 2){
					scolor(handle,light_blue);
					cout << "门";
				} else if(mp[i][j] == 3){
					scolor(handle,light_green);
					cout << "樯";
				} else if(mp[i][j] == 9){
					scolor(handle,green);
					cout << "墙";
				}
			}
			cout << endl;
		}
		colorclear(handle);
		pause();
		if(KEY_DOWN(68)){
			if(left == true && right == true && c[1] <= 2){
				if(x == 9 && y == 10){
					left = false;
					cls();
					break;
				}
			}
			if(left == true && right == false){
				cls();
				break;
			}
			if(y + 1 <= 10 && mp[x][y + 1] != 1){
				y++;
			}
		}
		if(KEY_DOWN(65)){
			if(left == false && right == false){
				cls();
				break;
			}
			if(left == true && right == false){
				cls();
				s2 = "因为第一次的成功,你得意极了,以为自己学会了穿墙术 你猛地撞向矩阵的墙壁,墙壁质量巨好,你疼的呜哇乱叫";
				print(s2,handle);
				cout << endl << "按任意键继续游戏" << endl;
				pause();
			} else if(y - 1 >= 1 && mp[x][y - 1] != 1){
				y--;
			}
		}
		if(KEY_DOWN(83)){
			if(left == true && right == false){
				if(x + 1 <= 10 && mp[x + 1][y] != 1){
					
				} else{
					cls();
					s2 = "因为第一次的成功,你得意极了,以为自己学会了穿墙术 你猛地撞向矩阵的墙壁,墙壁质量巨好,你疼的呜哇乱叫";
					print(s2,handle);
					cout << endl << "按任意键继续游戏" << endl;
					pause();
				}
			} else if(x + 1 <= 10 && mp[x + 1][y] != 1){
				x++;
			}
		}
		if(x == 10 && y == 10 && left == true && right == true){
			cls();
			break;
		}
		if(KEY_DOWN(87)){
			if(x == 1 && y == 1 && c[1] == 1){
				left = true;
				x = 9;
				mp[8][1] = 1;
				cls();
				s2 = "你想起了在家里打游戏玩坑图时的情景,每次都被幻象方块坑到 你试图穿越方块,你成功了, 你在地图的另一个地方出现......";
				print(s2,handle);
				cout << endl << "按任意键继续游戏" << endl;
				pause();
			} else if(x == 1 && y == 1 && c[1] > 1){
				cls();
				s2 = "你自以为发现了一面假墙,你十分兴奋,一头撞了上去 你的头上鼓起了一个大包,你仔细一看, 发现这面墙上只是涂了一层荧光涂料......";
				print(s2,handle);
				cout << endl << "按任意键继续游戏" << endl;
				pause();
			} else if(x - 1 >= 1 && mp[x - 1][y] != 1){
				x--;
			}
		}
		if(left == true && right == false && KEY_DOWN(84)){
			cls();
			if(c[1] <= 2){
				right = true;
				y = 10; 
				s2 = "因为一直被坑,你非常气恼,打算开指令过关,没想到真成功了 你输入了/tp指令来到了门前 但新的规则却给了你1000点暴击......";
				print(s2,handle);
				cout << endl << "按任意键继续游戏" << endl;
				pause();
			}
			else{
				s2 = "你试图开指令过关,没想到作者开了防作弊系统 看来这个办法是行不通了,你只能另寻他路...... 作者:哈哈,没想到吧!";
				print(s2,handle);
				cout << endl << "按任意键继续游戏" << endl;
				pause();
			}
		}
		if(left == true && right == false && KEY_DOWN(75) && c[1] == 3) K++;
		if(left == true && right == false && KEY_DOWN(73) && c[1] == 3) I++;
		if(left == true && right == false && KEY_DOWN(76) && c[1] == 3) L++;
		if(x == 9 && y == 1 && c[1] != 1 && left == false && right == false){
			cls();
			s2 = "你发现了有几堵墙的颜色不正常! 你试着用手触摸它们,果然是空心的!你赶紧顺着他们钻了进去 你成功了,你来到了地图的另一个地方......";
			print(s2,handle);
			cout << endl << "按任意键继续游戏" << endl;
			pause();
			left = true;
		}
		if(K == 1 && I == 1 && L == 2 && c[1] == 3 && left == true && right == false){
			cls();
			right = true;
			y = 10;
			s2 = "你觉得作者太玩不起了,干脆输入了/kill,没想到这个指令生效了 你赶紧在门前面设置了重生点,你被瞬间传送到门前 但新的规则却给了你1000点暴击......";
			print(s2,handle);
			cout << endl << "按任意键继续游戏" << endl;
			pause();
		}
	}
	if(left == true && right == false){
		s2 = "你因为通过了规则1感到得意,你试图打破规则向右走,你认为规则很菜, 却发现你的面前出现了一个弹簧,你被弹飞了起来,变成了一只自由的小鸟 过关失败";
		print(s2,handle);
		cout << endl << "按任意键回到首页" << endl;
		pause();
		return ;
	}
	if(left == false && right == false){
		s2 = "你试图打破规则向左走,你认为规则很菜, 却忘记了在超坑小游戏v2.5.0里的惨痛经历 你被突然出现的尖刺扎成了刺猬 过关失败";
		print(s2,handle);
		cout << endl << "按任意键回到首页" << endl;
		pause();
		return ;
	}
	if(left == true && right == true && c[1] <= 2){
		s2 = "作为一个勇士,你用尽全身力气朝门撞去,但门的弹性很好 你以牛顿不能理解的角度在矩阵中托马斯回旋 过关失败";
		print(s2,handle);
		cout << endl << "按任意键回到首页" << endl;
		pause();
		return ; 
	}
	if(left == true && right == true && c[1] == 3){
		s2 = "作为一个细心的小盆友,你发现规则的颜色不对! 你用尽全身力气朝门撞去,果然, 门以牛顿不能理解的角度在矩阵中托马斯回旋 你赶紧跑了出去 已解锁第三关:我的密码!";
		print(s2,handle);
		cout << endl << "通关成功,按任意键回到首页" << endl;
		pause();
	}
	if(left == false && right == true){
		s2 = "你发现墙上有一个洞,你钻了过去,眼前豁然开朗 已解锁第三关:我的密码!";
		print(s2,handle);
	}
	if(cs[1] == 1){
		cs[1] = 2;
		string str = out(coin,2,ac,0);
		output(str);
	}
	return ;
}
void case3(HANDLE handle){
	cls();
	string s3 = "";
	if(cs[1] == 2 && c[2] == 0){
		s3 = "密码游戏,都玩过吧? 特别是那种靠推理获取信息的游戏? 你钻过那个洞后,眼前豁然开朗,眼前有一扇巨大的密码门 上面显示:请输入3位密码 继续探索这里,试着找找关于密码的线索吧!";
		print(s3,handle);
		pause();
	}
	int mp[12][12] = {1,1,1,1,1,1,1,1,1,1,1,1,
	                  1,0,0,0,1,0,0,0,1,1,2,1,
	                  1,0,1,0,1,1,1,0,0,1,0,1,
	                  1,3,1,0,0,0,0,0,1,1,0,1,
	                  1,0,0,0,1,1,1,0,1,1,0,1,
	                  1,1,1,0,0,0,0,1,0,1,0,1,
	                  1,0,0,0,0,1,0,0,0,0,5,1,
	                  1,1,1,1,0,0,0,1,1,1,0,1,
	                  1,0,0,1,0,1,0,1,0,0,0,1,
	                  1,1,0,0,0,0,0,0,0,1,1,1,
	                  1,0,0,1,1,0,1,0,1,1,1,1,
	                  1,1,1,1,1,1,1,1,1,1,1,1};
	if(c[1] >= 2){
		mp[3][1] = 4;
		mp[2][3] = 1;
	}
	int x = 1,y = 1;
	bool flower = false,door = false;
	int D_times = -1;
	int mm = rand() % 9 + 1;
	int pq = rand() % 9 + 1;
	if(c[1] <= 2) pq = 7;
	while(true){
		cls();
		scolor(handle,light_purple);
		if(flower == false) cout << "你在起点处发现一张纸条:你只有1次机会输入密码" << endl << endl;
		else if(flower == true && c[1] <= 2) cout << "你在地上发现了三朵小花,十分漂亮" << endl << endl;
		else cout << "你在地上发现了" << mm << "朵小花,十分漂亮,小花旁边放着一张纸条:一人站杆顶" << endl << endl;
		for(int i = 0;i < 12;i++){
			for(int j = 0;j < 12;j++){
				if(x == i && y == j){
					colorclear(handle);
					cout << "我";
				} else if(mp[i][j] == 1){
					scolor(handle,light_green);
					cout << "墙";
				} else if(mp[i][j] == 0){
					cout << "  ";
				} else if(mp[i][j] == 2){
					scolor(handle,blue);
					cout << "门";
				} else if(mp[i][j] == 3){
					scolor(handle,light_red);
					cout << "糖";
				} else if(mp[i][j] == 4){
					scolor(handle,red);
					cout << "糖";
				} else if(mp[i][j] == 5){
					scolor(handle,light_yellow);
					cout << "花"; 
				} else if(mp[i][j] == 6){
					scolor(handle,light_blue);
					if(c[1] == 1) cout << "石";
					else cout << "怪";
				}
			}
			cout << endl;
		}
		colorclear(handle);
		pause();
		if(KEY_DOWN(68) && y + 1 <= 10){
			if(D_times != -1){
				D_times++;
				if(D_times == pq){
					mp[1][4] = 0;
					D_times = -1;
					mp[10][1] = 6;
				}
			}
			if(mp[x][y + 1] != 1) y++;
		}
		if(KEY_DOWN(65) && y - 1 >= 1 && mp[x][y - 1] != 1){
			y--;
		}
		if(KEY_DOWN(83) && x + 1 <= 10 && mp[x + 1][y] != 1){
			x++;
		}
		if(KEY_DOWN(87) && x - 1 >= 1 && mp[x - 1][y] != 1){
			x--;
		}
		if(mp[x][y] == 3){
			cls();
			s3 = "你发现了一颗糖果,你觉得应该挺好吃的, 你把糖果放进嘴里,甜滋滋的,你高兴极了, 唱着《七里香》继续前进";
			print(s3,handle);
			cout << endl << "按任意键继续游戏" << endl;
			pause();
			mp[3][1] = 0;
			mp[8][4] = 4;
			door = true;
			mp[10][1] = 6;
		}
		if(mp[x][y] == 4){
			cls();
			s3 = "你发现了一颗糖果,你高兴极了, 觉得多吃这些糖果能让你变成超人 你一口吞下了糖果,不久就腹痛难忍,口吐白沫 你在闭上眼睛的最后一刻喊道:nm的这糖果有毒!!!";
			print(s3,handle);
			cout << endl << "过关失败,按任意键返回主页" << endl;
			pause();
			return ;
		}
		if(x == 1 && y == 3 && D_times == -1 && c[1] >= 2){
			D_times = 0;
		}
		if(mp[x][y] == 5){
			flower = true;
		}
		if(mp[x][y] == 2){
			cls();
			s3 = "你来到门前,发现这个门的颜色有点不对! 你刚想离开,门自动打开了,里面漆黑一片 出于好奇,你往里面看去, 你在门内发现了一具s体 你刚想跑,一股巨大的吸力把你吸了进去";
			print(s3,handle);
			cout << endl << "过关失败,按任意键返回主页" << endl;
			pause();
			return ;
		}
		if(mp[x][y] == 6){
			break;
		}
		cout << endl;
	}
	cls();
	if(c[1] == 1) s3 = "你来到突然出现的石头前,原来它才是真正的大门! 你用手触碰上面的符文,一个显示屏凭空出现 请输入密码";
	else s3 = "你来到突然出现的怪物前,怪物一口把你吞了,你来到了一个密室里! 密室里有一块石头,你用手触碰上面的符文, 一个显示屏凭空出现:请输入密码!";
	print(s3,handle);
	int mima;
	cin >> mima;
	if(c[1] == 3){
		if(mima % 10 != mm || (mima / 10) % 10 != pq || mima / 100 != 1){
			cls();
			s3 = "你输完密码,却只听见一阵刺耳的警报声: 密码错误!密码错误! 地上突然裂开一个口子,你尖叫着掉了下去";
			print(s3,handle);
			cout << endl << "过关失败,按任意键返回主页" << endl;
			pause();
			return ;
		}
	}
	if(mima != 173 && mima != 137 && mima != 713 && mima != 731 && mima != 317 && mima != 371 && c[1] <= 2){
		cls();
		s3 = "你输完密码,却只听见一阵刺耳的警报声: 密码错误!密码错误! 地上突然裂开一个口子,你尖叫着掉了下去";
		print(s3,handle);
		cout << endl << "过关失败,按任意键返回主页" << endl;
		pause();
		return ;
	}
	cls();
	s3 = "你输完密码,石头上突然出现一条裂痕,你掉了下去 再次睁开眼时,你发现自己身处一个温馨的房间 难道......你已经回到家了吗?";
	print(s3,handle);
	cout << endl << "按任意键返回首页" << endl;
	pause();
	if(cs[1] == 2){
		cs[1] = 3;
		string str = out(coin,3,ac,0);
		output(str);
	}
	return ;
}
void case4(HANDLE handle){
	cls();
	string s4 = "";
	if(cs[1] == 3 && c[2] == 0){
		if(c[1] == 1) s4 = "你发现自己居然回到了自己的房间里 你还没高兴0.145秒钟,你两边的墙壁就突然向你压了过来 作为数学天才的你一下子就计算出你还有走6步的时间逃离这里 请动动你聪明的脑袋,尽快离开这里吧!";
		else s4 = "你发现自己居然回到了自己的房间里 你还没高兴0.145秒钟,你两边的墙壁就突然向你压了过来 作为数学天才的你一下子就计算出你还有走5步的时间逃离这里 请动动你聪明的脑袋,尽快离开这里吧!";
		print(s4,handle);
		cout << endl << "按任意键继续游戏" << endl;
		pause();
	}
	int mp[15][15] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	                  1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					  1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					  1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					  1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					  1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					  1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					  1,2,0,0,0,0,0,0,0,0,0,3,0,0,1,
					  1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					  1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					  1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					  1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					  1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					  1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int tx1 = 0,tx2 = 14;
	if(c[1] == 2) tx1 = 1,tx2 = 13;
	int x = 7,y = 9,die = 0,tv = 0,stv = 0;
	int KEY = 0,ph = 0,great = 0,th = 0;
	while(true){
		cls();
		if(ph == 1){scolor(handle,light_green);cout << "听了机哥的离谱发言,你十分生气,1+1=2才对!你掏出手机打算投诉" << endl;}
		else if(ph == 2){scolor(handle,light_green);cout << "你掏出手机,却发现电视里的机哥凭空出现了!" << endl;}
		else if(KEY >= 3 && tx1 != x && tx2 != x){scolor(handle,light_green);cout << "慢慢靠近的墙壁似乎停下了......" << endl;}
		else if(tv == 0) cout << endl;
		else if(stv == 1){
			scolor(handle,light_green);cout << "电视里正在播放一段知名哲学家机哥的名言:一加一等于三\n(提示:得数是一条关键线索)" << endl;
			if(ac[0] == 0) cout << "恭喜解锁成就:[数学天才!]" << endl;
			ac[0] = 1;
		}
		else{scolor(handle,light_green);cout << "你发现了一台电视,按E键和电视交互" << endl;}
		for(int i = 0;i < 15;i++){
			for(int j = 0;j < 15;j++){
				if(i <= tx1 || i >= tx2){scolor(handle,gray);cout << "刺";}
				else if(x == i && y == j){colorclear(handle);cout << "我";}
				else if(mp[i][j] == 1){scolor(handle,light_purple);cout << "墙";}
				else if(mp[i][j] == 2){scolor(handle,light_blue);cout << "门";}
				else if(mp[i][j] == 3){scolor(handle,light_green);cout << "电";}
				else if(mp[i][j] == 9){scolor(handle,green);cout << "机";}
				else cout << "  ";
			}
			cout << endl;
		}
		if(x <= tx1 || x >= tx2){
			if(c[1] <= 2) die = 1;
			else if(c[1] == 3){
				if(y == 11 && th == 0){
					th = 1;
				}
				else if(y != 11)die = 1;
			}
			if(die == 1) break;
		}
		if(y == 11 && (x <= tx1 || x >= tx2) && th == 1){
			break;
		}
		pause();
		if(KEY_DOWN(65) && y > 1) y--;
		if(KEY_DOWN(68) && y < 13) y++;
		if(KEY_DOWN(87)) x--;
		if(KEY_DOWN(83)) x++;
		if(KEY_DOWN('1') && KEY < 2 && c[1] == 1) KEY++;
		if(KEY_DOWN('3') && KEY == 2 && c[1] == 1) KEY++;
		if(KEY_DOWN('2') && stv == 1 && c[1] == 2){
			ph = 1;
			mp[7][10] = 9;
		}
		if(mp[x][y] == 9) ph = 2;
		if(KEY_DOWN(75) && mp[x][y] == 9){
			great = 1;
			break;
		}
		if(mp[x][y] == 3) tv = 1;
		if(KEY_DOWN(69) && tv == 1){
			cls();
			stv = 1;
		}
		if(mp[x][y] == 2) break;
		if(KEY < 3){tx1++;tx2--;}
	}
	cls();
	if(die){
		scolor(handle,light_yellow);
		cout << "你被尖刺扎成了刺猬,通关失败\n按任意键返回首页" << endl;
		colorclear(handle);
		pause();
		return ;
	}
	if(!great && c[1] == 1) s4 = "你赶紧抓住机会向大门跑去,你进入了一片黑暗中......";
	else if(c[1] == 2) s4 = "你开始和发表离谱言论的机哥争论,但他坚持不听 你气愤地输入了/kill指令 趁着机哥倒下,尖刺都在为他悲伤,你趁机溜了出去, 进入了一片黑暗中......";
	else s4 = "你发现了一面可以穿过去的刺墙,你用尽全身力气向它撞去 你进入了一片黑暗中......";
	print(s4,handle);
	cout << endl << "按任意键返回首页" << endl;
	pause();
	if(cs[1] == 3){
		cs[1] = 4;
		string str = out(coin,4,ac,0);
		output(str);
	}
}
void case5(HANDLE handle){
	cls();
	string s5 = "你来到了一个黑暗的空间,你根本看不清前面有什么东西, 回去的路也被阻断了,你只能在黑暗中继续探索 你只能看到以自己为中心一定范围内的路况 你只能尽可能快地离开了...";
	if(cs[1] == 4 && c[2] == 0){
		print(s5,handle);
		cout << endl << "按任意键继续游戏" << endl;
		pause();
	}
	cls();
	int mp[10][30] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	                  1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,1,2,1,
					  1,0,1,1,1,1,1,0,1,1,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,
					  1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,1,0,1,1,1,1,0,1,0,0,0,1,
					  1,0,0,0,0,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,1,1,1,0,1,0,1,0,1,
					  1,0,1,0,0,1,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,
					  1,1,0,0,0,1,1,0,0,1,0,1,0,1,1,0,0,0,0,0,1,0,1,1,0,0,0,0,1,1,
					  1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,1,1,0,1,0,1,0,1,1,0,1,0,0,0,1,
					  1,3,0,0,0,1,1,0,0,0,5,1,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,
					  1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int tx1 = 0,tx2 = 14;
	int mx = 8,my = 10;
	int x = 1,y = 1;
	int sx = 1,sy = 1;
	int torch = 0,od = 0,ms = 0;
	while(true){
		cls();
		if(ms == 1){sx = 5,sy = 5;scolor(handle,light_purple);cout << "你发现了一只怪物,怪物也发现了你..." << endl;}
		else if(torch == 1 && od == 0){sx = 3,sy = 3;scolor(handle,light_purple);cout << "你拾取了道具:手电筒x1\n你可以看到更大范围内的物品了..." << endl;}
		else if(torch == 1 && od == 1){scolor(handle,yellow);cout << "你拾取了道具:钥匙x1\n快去寻找通关的大门吧!" << endl;}
		int i1 = x - sx; if(i1 < 0) i1 = 0;
		int i2 = x + sx; if(i2 > 9) i2 = 9;
		int j1 = y - sy; if(j1 < 0) j1 = 0;
		int j2 = y + sy; if(j2 > 29) j2 = 29;
		for(int i = 0;i < 10;i++){
			for(int j = 0;j < 30;j++){
				if(i == x && j == y){
					colorclear(handle);
					cout << "我";
				}
				else if(i >= i1 && i <= i2 && j >= j1 && j <= j2){
					if(mp[i][j] == 0) cout << "  ";
					else if(mp[i][j] == 1){scolor(handle,light_green);cout << "墙";}
					else if(mp[i][j] == 2){scolor(handle,light_blue);cout << "门";}
					else if(mp[i][j] == 3){scolor(handle,light_red);cout << "电";}
					else if(mp[i][j] == 4){scolor(handle,yellow);cout << "钥";}
					else if(mp[i][j] == 5){colorclear(handle);cout << "怪";}
				} else{
					scolor(handle,gray); cout << "??";
				}
			}
			cout << endl;
		}
		pause();
		if(KEY_DOWN(68) && y + 1 <= 29 && mp[x][y + 1] != 1) y++;
		if(KEY_DOWN(65) && y - 1 >= 1 && mp[x][y - 1] != 1) y--;
		if(KEY_DOWN(83) && x + 1 <= 9 && mp[x + 1][y] != 1) x++;
		if(KEY_DOWN(87) && x - 1 >= 1 && mp[x - 1][y] != 1) x--;
		if(mp[x][y] == 3){
			mp[x][y] = 0;
			torch = 1;
			mp[1][10] = 4;
		}
		if(mp[x][y] == 4){
			mp[x][y] = 0;
			od = 1;
			mp[2][28] = 0;
		}
		if(ms == 1){
			mp[mx][my] = 0;
			if(x < mx){
				mp[mx - 1][my] = 0;
				mx -= 2;
			}
			else if(x > mx){
				mp[mx + 1][my] = 0;
				mx += 2;
			}
			else if(y < my){
				mp[mx][my - 1] = 0;
				my -= 2;
			}
			else{
				mp[mx][my + 1] = 0;
				my += 2;
			}
			mp[mx][my] = 5;
			if(mp[x][y] == 5){
				ms = 2;
				break;
			}
		}
		if(x + 3 >= 8 && y == 10) ms = 1;
		if(mp[x][y] == 2) break;
	}
	cls();
	if(ms == 2){
		s5 = "你被怪物抓住了 过关失败";
		print(s5,handle);
		cout << endl << "按下任意键返回首页" << endl;
		pause();
		return ;
	}
	s5 = "在你的不懈努力下,终于找到了这个矩阵的出口 你赶紧推开大门,耀眼的阳光瞬间穿透了整个矩阵 你赶紧大步迈了出去...";
	print(s5,handle);
	scolor(handle,light_yellow);
	cout << "恭喜通关超坑小游戏v0.5所有关卡\n更多关卡正在赶来,敬请期待!" << endl << endl; colorclear(handle);
	cout << "按下任意键返回首页";
	pause();
	if(cs[1] == 4){
		cs[1] = 5;
		string str = out(coin,5,ac,0);
		output(str);
	}
}
void ch_case1(HANDLE handle){
	while(true){
		cls();
		scolor(handle,gray);
		cout << "开始冒险吧!" << endl;
		colorclear(handle);
		if(cs[1] >= 1){
			scolor(handle,light_green); cout << "第一关:初探矩阵(已通关)" << endl;
		} else{
			scolor(handle,light_red); cout << "第一关:初探矩阵(冒险中)" << endl;
		}
		if(cs[1] >= 2){
			scolor(handle,light_green); cout << "第二关:千万别手欠!(已通关)" << endl;
		} else if(cs[1] >= 1){
			scolor(handle,light_red); cout << "第二关:千万别手欠!(冒险中)" << endl;
		} else{
			if(c[3] == 0){scolor(handle,gray); cout << "第二关:暂未解锁" << endl;}
			else{scolor(handle,gray); cout << "第二关:千万别手欠!(未解锁)" << endl;}
		}
		if(cs[1] >= 3){
			scolor(handle,light_green); cout << "第三关:我的密码!(已通关)" << endl;
		} else if(cs[1] >= 2){
			scolor(handle,light_red); cout << "第三关:我的密码!(冒险中)" << endl;
		} else{
			if(c[3] == 0){scolor(handle,gray); cout << "第三关:暂未解锁" << endl;}
			else{scolor(handle,gray); cout << "第三关:我的密码!(未解锁)" << endl;}
		}
		if(cs[1] >= 4){
			scolor(handle,light_green); cout << "第四关:两面夹击(已通关)" << endl;
		} else if(cs[1] >= 3){
			scolor(handle,light_red); cout << "第四关:两面夹击(冒险中)" << endl;
		} else{
			if(c[3] == 0){scolor(handle,gray); cout << "第四关:暂未解锁" << endl;}
			else{scolor(handle,gray); cout << "第四关:两面夹击(未解锁)" << endl;}
		}
		if(cs[1] >= 5){
			scolor(handle,light_green); cout << "第五关:天黑请闭眼(已通关)" << endl;
		} else if(cs[1] >= 4){
			scolor(handle,light_red); cout << "第五关:天黑请闭眼(冒险中)" << endl;
		} else{
			if(c[3] == 0){scolor(handle,gray); cout << "第五关:暂未解锁" << endl;}
			else{scolor(handle,gray); cout << "第五关:天黑请闭眼(未解锁)" << endl;}
		}
		scolor(handle,gray);
		if(c[3] == 0) cout << "第六关:暂未制作,敬请期待!" << endl << endl;
		else cout << "第六关:大逃亡(敬请期待)" << endl << endl;
		scolor(handle,light_blue); cout << "如果想游玩关卡,请按下关卡编号+3对应的数字按键\n小贴士:单击按键B即可返回首页!" << endl << endl;
		colorclear(handle);
		pause();
		if(KEY_DOWN('4')){
			cls();
			logo(handle); cout << "第一关:初探矩阵" << endl;
			scolor(handle,gray); cout << "当前难度:";
			if(c[1] == 1){
				scolor(handle,light_green); cout << "简单模式" << endl;
				scolor(handle,light_purple); cout << "综合难度:1.0 坑人指数:0.5" << endl;
			} else{
				if(c[1] == 2){scolor(handle,light_yellow); cout << "普通模式" << endl;}
				else if(c[1] == 3){scolor(handle,light_red); cout << "困难模式" << endl;}
				scolor(handle,light_purple); cout << "综合难度:1.0 坑人指数:0.6" << endl;
			}
			scolor(handle,blue | green); cout << "游戏将在3秒后开始" << endl;
			wait(3);
			case1(handle);
			break;
		} else if(KEY_DOWN('5') && cs[1] >= 1){
			cls();
			logo(handle); cout << "第二关:千万别手欠!" << endl;
			scolor(handle,gray); cout << "当前难度:";
			if(c[1] == 1){
				if(c[1] == 1){scolor(handle,light_green); cout << "简单模式" << endl;}
				scolor(handle,light_purple); cout << "综合难度:1.1 坑人指数:0.6" << endl;
			} else if(c[1] == 2){
				if(c[1] == 2){scolor(handle,light_yellow); cout << "普通模式" << endl;}
				scolor(handle,light_purple); cout << "综合难度:1.1 坑人指数:0.7" << endl;
			} else if(c[1] == 3){
				scolor(handle,light_red); cout << "困难模式" << endl;
				scolor(handle,light_purple); cout << "综合难度:1.1 坑人指数:0.8" << endl;
			}
			scolor(handle,blue | green); cout << "游戏将在3秒后开始" << endl;
			wait(3);
			case2(handle);
			break;
		} else if(KEY_DOWN('6') && cs[1] >= 2){
			cls();
			logo(handle); cout << "第三关:我的密码!" << endl;
			scolor(handle,gray); cout << "当前难度:";
			if(c[1] == 1){
				scolor(handle,light_green); cout << "简单模式" << endl;
				scolor(handle,light_purple); cout << "综合难度:1.0 坑人指数:0.9" << endl;
			} else if(c[1] == 2){
				scolor(handle,light_yellow); cout << "普通模式" << endl;
				scolor(handle,light_purple); cout << "综合难度:1.0 坑人指数:1.0" << endl;
			} else if(c[1] == 3){
				scolor(handle,light_red); cout << "困难模式" << endl;
				scolor(handle,light_purple); cout << "综合难度:1.1 坑人指数:1.0" << endl;
			}
			scolor(handle,blue | green); cout << "游戏将在3秒后开始" << endl;
			wait(3);
			case3(handle);
			break;
		} else if(KEY_DOWN('7') && cs[1] >= 3){
			cls();
			logo(handle); cout << "第四关:两面夹击" << endl;
			scolor(handle,gray); cout << "当前难度:";
			if(c[1] == 1){
				scolor(handle,light_green); cout << "简单模式" << endl;
				scolor(handle,light_purple); cout << "综合难度:1.0 坑人指数:0.9" << endl;
				
			} else if(c[1] == 2){
				scolor(handle,light_yellow); cout << "普通模式" << endl;
				scolor(handle,light_purple); cout << "综合难度:1.1 坑人指数:1.0" << endl;
			} else if(c[1] == 3){
				scolor(handle,light_red); cout << "困难模式" << endl;
				scolor(handle,light_purple); cout << "综合难度:1.2 坑人指数:1.0" << endl; 
			}
			scolor(handle,blue | green); cout << "游戏将在3秒后开始" << endl;
			wait(3);
			case4(handle);
			break;
		} else if(KEY_DOWN('8') && cs[1] >= 4){
			cls();
			logo(handle); cout << "第五关:天黑请闭眼" << endl;
			scolor(handle,gray); cout << "当前难度:";
			if(cs[1] == 1){
				scolor(handle,light_green); cout << "简单模式" << endl;
				scolor(handle,light_purple); cout << "综合难度:1.1 坑人指数:0.9" << endl;
			} else if(c[1] == 2){
				scolor(handle,light_yellow); cout << "普通模式" << endl;
				scolor(handle,light_purple); cout << "综合难度:1.1 坑人指数:0.9" << endl;
			} else if(c[1] == 3){
				scolor(handle,light_red); cout << "困难模式" << endl;
				scolor(handle,light_purple); cout << "综合难度:1.2 坑人指数:1.0" << endl;
			}
			wait(3);
			case5(handle);
			break;
		}else if(KEY_DOWN(66)){
			return ;
		}
	}
}
void atimet(HANDLE handle){
	scolor(handle,light_blue); cout << "成就列表(2)" << endl;
	if(ac[0] == 1){scolor(handle,light_green);cout << "成就1:[数学天才!]" << endl;colorclear(handle);cout << "获得难度:简单\n获得条件:在第四关内使用电视收听机哥的发言\n描述:谁教你这么计算的???" << endl;}
	else{scolor(handle,gray);cout << "成就1:[数学天才!]" << endl;colorclear(handle);cout << "获得难度:简单\n获得条件:-\n描述:-\n该成就暂未解锁,快去冒险模式探险吧!" << endl;}
	if(ac[1] == 1){scolor(handle,light_green);cout << "成就2:[极限拉扯I]" << endl;colorclear(handle);cout << "获得难度:中等\n获得条件:在第五关触发机制怪并在追逐中成功抵达终点\n描述:都说怪物很厉害,原来不过如此!" << endl;}
	else{scolor(handle,gray);cout << "成就2:[极限拉扯I]" << endl;colorclear(handle);cout << "获得难度:中等\n获得条件:-\n描述:-\n该成就暂未解锁,快去冒险模式探险吧!" << endl;}
	cout << endl << "按任意键返回首页" << endl;
	pause();
}
void ctrl(HANDLE handle,HWND hWnd){
	int page = 1;
	while(true){
		cls();
		if(page == 1){
			scolor(handle,gray);
			cout << "控制台(第1页)" << endl;
			scolor(handle,light_green);
			cout << "1.简单模式";
			if(c[1] == 1) cout << "(已选择)";
			scolor(handle,light_yellow);
			cout << endl << "2.普通模式";
			if(c[1] == 2) cout << "(已选择)";
			scolor(handle,light_red);
			cout << endl << "3.困难模式";
			if(c[1] == 3) cout << "(已选择)";
			scolor(handle,purple);
			cout << endl << "4.噩梦模式(未开发)" << endl;
			scolor(handle,gray);
			cout << "按下对应数字调整难度\n" << endl;
			scolor(handle,light_blue);
			cout << "D->下一页\n单击B返回首页" << endl;
			colorclear(handle);
			pause();
			if(KEY_DOWN('1')){
				c[1] = 1;
			} else if(KEY_DOWN('2')){
				c[1] = 2;
			} else if(KEY_DOWN('3')){
				c[1] = 3;
			} else if(KEY_DOWN(68)){
				page = 2;
			} else if(KEY_DOWN(66)){
				return ;
			} else{
				qd(hWnd);
			}
		} else{
			scolor(handle,gray);
			cout << "控制台(第2页)" << endl;
			scolor(handle,light_green);
			cout << "游戏剧情设置:剧情显示调节(0/1)" << endl;
			scolor(handle,light_red);
			if(c[2] == 0) cout << "目前状态:显示剧情" << endl;
			else cout << "目前状态:不显示剧情" << endl;
			scolor(handle,light_green);
			cout << "游戏设置:关卡名显示调节(y/n)" << endl;
			scolor(handle,light_red);
			if(c[3] == 0) cout << "目前状态:只显示已通过的关卡" << endl << endl;
			else cout << "目前状态:显示所有关卡" << endl << endl;
			scolor(handle,light_blue);
			cout << "A<-上一页\n单击B返回首页" << endl;
			colorclear(handle);
			pause();
			if(KEY_DOWN('0')){
				c[2] = 0;
			} else if(KEY_DOWN('1')){
				c[2] = 1;
			} else if(KEY_DOWN(89)){
				c[3] = 1;
			} else if(KEY_DOWN(78)){
				c[3] = 0;
			} else if(KEY_DOWN(65)){
				page = 1;
			} else if(KEY_DOWN(66)){
				return ;
			}
		}
	}
}
void notice(HANDLE handle){
	string nt = notice_in();
	scolor(handle,light_blue);
	for(int i = 0;i <= 16;i++) cout << nt[i];
	cout << endl;
	colorclear(handle);
	for(int i = 17;i < nt.size();i++){
		if(nt[i] == ' ') cout << endl;
		else if(nt[i] == 'L') logo(handle);
		else if(nt[i] == 'D') cout << "                                                      ";
		else if(nt[i] == 'E') cout << "                                                 ";
		else cout << nt[i];
	}
	cout << endl << "按任意键返回首页" << endl;
	pause();
}
int main(){
	srand(time(0));
	HANDLE handle;
	handle = GetStdHandle(S_O_H);
	HWND hWnd;
	hWnd = GetConsoleWindow();
	memset(cs,0,sizeof(cs));
	read(handle);
	while(true){
		cls();
		logo(handle);
		scolor(handle,gray);
		cout << "请选择想要游玩的章节:" << endl;
		if(cs[1] < 5){
			scolor(handle,light_red);
			cout << "第一章节:矩阵探秘(冒险中)" << endl;
		} else{
			scolor(handle,light_green);
			cout << "第一章节:矩阵探秘(已通关)" << endl;
		}
		scolor(handle,gray); cout << "第二章节:敬请期待" << endl;
		colorclear(handle); cout << "成就列表:按下数字9查看" << endl << endl;
		scolor(handle,light_blue); cout << "想要查看游戏动态?按Ctrl+Z查看公告!" << endl;
		scolor(handle,light_yellow); cout << "冷知识:按下Ctrl+E即可进入控制台!" << endl;
		scolor(handle,light_purple); cout << "按数字0对游戏进度进行存档" << endl << endl;
		scolor(handle,light_yellow); cout << "当前版本:v0.5 ";
		if(content == "1"){
			scolor(handle,light_red); cout << "最新版本:v1.0+" << endl;
		}
		cout << endl;
		colorclear(handle);
		pause();
		if(KEY_DOWN('0')){
			string str = out(coin,cs[1],ac,0);
			output(str);
			scolor(handle,red);
			cout << "./file/userdata.txt修改已生效:" << str << endl;
			colorclear(handle);
			wait(1);
		}
		if(KEY_DOWN('9')){
			cls();
			atimet(handle);
		}
		if(Ctrl_E()){
			cls();
			ctrl(handle,hWnd);
		}
		if(exit()){
			cls();
			notice(handle);
		}
		if(KEY_DOWN('1')){
			cls();
			ch_case1(handle);
		}
	}
	return 0;
}
