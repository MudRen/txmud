//	/adm/daemons/logind.c
// Modified by Find.

#pragma optimize

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>

#include <station.h>

protected int wiz_lock_level = WIZ_LOCK_LEVEL;
protected int no_login;
protected int ST_CREDIT_POINT = 30000;
protected int MAX_ATTR_SUM = 120;	// 天赋总和

string *start_loc = ({
	"/d/changan/jiulou",



});

void set_no_login(int n)
{
	if(!previous_object() || (geteuid(previous_object()) != ROOT_UID))
		return;
	no_login = n;
}

protected void encoding(string arg, object ob);
protected void get_id(string arg, object ob);
protected void confirm_id(string yn, object ob);
protected void get_passwd(string pass, object ob);
protected void init_new_player(string yn,object ob,object user);
protected void confirm_relogin(string yn, object ob, object user);
protected void get_name(string arg, object ob);
protected void new_password(string pass, object ob,int flag);
protected void confirm_password(string pass, object ob,int flag);
//protected void get_email(string email, object ob);
protected void get_gender(string gender, object ob, object user);
object make_body(object ob);
protected int search_partner(string partner);
void welcome_user(string any,object ob);
void begain_enter(object ob);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
int all_online_players();
int check_wiz_legal_password(object ob,string pass);
string user_file(string id);
string login_file(string id);

protected void create() 
{
        seteuid(getuid());
}

void logon(object ob)
{

	if( uptime() < 30 )
	{
		write(sprintf("%s正在启动过程中，请稍候再来。\n",MUD_NAME));
		destruct(ob);
		return;
	}

	if(no_login)
	{
		write(sprintf("%s已进入重新启动处理进程，请稍候再来。\n",MUD_NAME));
		destruct(ob);
		return;
	}

#ifdef GB_AND_BIG5
	printf(read_file(TITLE));

	write("           《天下》欢迎您来访！使用国标码的玩家请键入：gb\n");
	write("           ¨﹖縒礚〃舧眤ㄓ砐ㄏノき絏產叫龄big5\n\n");
	write("         Welcome to TianXia ! Select GB or BIG5 (gb/big5):");
	input_to( (: encoding :), ob );
#else
	encoding("gb",ob);
#endif
}

void encoding(string arg,object ob)
{
	int encode;

	if(!arg || arg=="")
	{
	    write("\nSelect 国标码 GB or き絏 BIG5 (gb/big5):");
	    input_to( (: encoding :), ob );
	    return;
	}
	else if(arg[0]=='g' || arg[0]=='G')
	    encode=0;
	else if(arg[0]=='b' || arg[0]=='B')
	    encode=1;
	else
	{
	    write("\nSelect 国标码 GB or き絏 BIG5 (gb/big5):");
	    input_to( (: encoding :), ob );
	    return;
	}
	
	ob->set_encoding(encode);

	printf(REF);
	printf(read_file(WELCOME));
	//write("按任意键继续......");
	//input_to("welcome_user", ob);
	begain_enter(ob);
}

void welcome_user(string any,object ob)
{
	if(!ob)
		return;
	printf(REF);
	begain_enter(ob);
	return;
}

void begain_enter(object ob)
{
        object *usr;
        int i, wiz_cnt, ppl_cnt, login_cnt;
	//int Same_Ip;
	int count;

        if ( BAN_D->is_banned(query_ip_number( ob ),2))
        {
		write(HIR"对不起，你的IP地址在" + MUD_NAME + "不受欢迎。\n");
		destruct(ob);
		return;
        }

	printf(WHT"[本地时间]："+cctime(time())+"\n");
	printf("[运行时间]：");
	UPTIME_CMD->main();
	printf(sprintf("[游戏人数]：%s世界目前共有 %s 位居民。\n",MUD_NAME, chinese_number(count_reg_user())));
	printf("[流量统计]：");
	"/cmds/imm/bps"->main();
/*
	printf(sprintf("[物件统计]：游戏当前共载入物件 %d 个，使用记忆体总量 %s。\n\n" NOR,
		sizeof(objects()),"/cmds/imm/mem"->memory_expression(memory_info())));
*/
	usr = filter_array( children(USER_OB), (: clonep :) );
        wiz_cnt = 0;
        ppl_cnt = 0;
        login_cnt = 0;
	//Same_Ip = 0;

        for(i=0; i<sizeof(usr); i++)
        {
       	        if( !environment(usr[i]) ) login_cnt++;
               	else if( wizardp(usr[i])
			&& !usr[i]->query("env/invisibility")) wiz_cnt++;
                else ppl_cnt++;
		//if( query_ip_number(ob) == query_ip_number(usr[i]) )
		//	Same_Ip++;
        }
/*
	if (Same_Ip > MAX_SAME_IP
	&& (user_ip != "202.96.44.100")
	&& (user_ip != "127.0.0.1"))
	{
		write("对不起，你的IP登录次数太多了\n");
		destruct(ob);
		return;
	}
*/

	count = all_online_players();
	if(!count)
		printf(NOR "\n目前"); // info not available
	else
		printf(NOR HIG"\n目前共有%d位玩家在线上。"NOR+"\n本站", count+wiz_cnt+ppl_cnt );

        printf("共有 %s%d 位玩家在线上，以及 %d 位使用者尝试连线中。\n\n",
                wiz_cnt?sprintf("%d 位管理员、",wiz_cnt):"", ppl_cnt, login_cnt );

        write("您的英文名字：");
        input_to( (: get_id :), ob );
}

protected void get_id(string arg, object ob)
{
        object ppl,user;
	string where;

        arg = lower_case(arg);
        if( !check_legal_id(arg))
	{
		write("您的英文名字：");
                input_to( (: get_id :), ob);
                return;
        }

	if((wiz_level(arg) > 0) && !IP_D->identify_ip(arg, query_ip_number(ob)))
	{
		destruct(ob);
		return;
	}

        if( (string)SECURITY_D->get_status(arg)=="(player)"
          && sizeof(users()) >= MAX_USERS )
	{
                ppl = find_body(arg);
                if( !ppl || !interactive(ppl) )
		{
                        write("对不起，" + MUD_NAME + "的使用者已经太多了，请待会再来。\n");
                        destruct(ob);
                        return;
                }
        }

        if( wiz_level(arg) < wiz_lock_level )
	{
		write("对不起，" + MUD_NAME + "目前限制巫师等级 " +   wiz_level_name(wiz_lock_level)
			+ " 以上的人才能连线。\n");
		destruct(ob);
		return;
	}

	if(AHACK_D->query_block(arg))
	{
		write(HIY"这个账号被暂时封锁了，请用 guest 人物登入与在线巫师联系。\n"NOR);
		destruct(ob);
		return;
	}

        if( (string)ob->set("id", arg) != arg )
	{
		write("Failed setting user name.\n");
                destruct(ob);
                return;
        }

        if( arg=="guest" )
        {
		user = find_body("guest");
		if(user)
		{
			write("目前 guest 账号已有人在使用，请等一下再登陆。\n");
			destruct(ob);
			return;
		}

		ob->set("body", USER_OB);
		if( !objectp(user = make_body(ob)) )
		{
			destruct(ob);
			return;
		}
		user->set("name","临时人物");
		user->set("gender","男性");
		user->set("title", "普通百姓");
		user->set("food", 500);
		user->set("water",500);
		user->set("channels", ({ "chat", "rumor", "menpai" }) );
		user->set("str",20);
		user->set("int",20);
		user->set("cor",20);
		user->set("con",20);
		user->set("per",20);
		user->set("kar",20);
		enter_world(ob,user);
		return;
        }
        
        else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 )
        {
                if( ob->restore() )
                {
			if(!ob->query("password")) // 档案不完整.
			{
				rm(login_file(arg));
				if(file_size(user_file(arg)) >= 0)
					rename(user_file(arg),BACKUP_DIR+arg+".o");
				write("您的档案不完整，请重新创建这个人物。\n");
				confirm_id("y", ob);
				return;
			}
                        write("这个名字已经注册，请输入注册密码：");
                        input_to( (: get_passwd :), 1, ob);
                        return;
                }
                write("您的人物储存挡出了一些问题，请利用 guest 人物通知巫师处理。\n");
                destruct(ob);
                return;
        }

#ifdef REFUSE_NEW_PLAYER
        write("对不起，由于发送邮件服务器出现问题，\n目前"+MUD_NAME+"暂时不接受新玩家登记。\n请访问游戏主页：http://www.mudtx.com 获得详细的讯息。\n");
	destruct(ob);
	return;
#endif

	where = query_register_station(arg);
	if(stringp(where) && (where != ""))
	{
		write(sprintf("[%s] 这个 ID 已经在%s注册了\n请去那里登陆进入游戏。\n",
			arg,!undefinedp(stations[where])?stations[where]:"别的地方"));
		destruct(ob);
		return;
	}

        write("使用 " + (string)ob->query("id") + " 这个名字将会创造一个新的人物，您确定吗(y/n)？");
        input_to("confirm_id", ob);
}
/*
protected void check_same_ip_number(object user)
{
	object *objs;
	string *ids = ({}),me_ip_number;
	int flag;

	if(!objectp(user))
		return;

	if(wizardp(user))
		flag = 1;
	else flag = 0;

	me_ip_number = query_ip_number(user);

	objs = filter_array(children(USER_OB),(: clonep :));

	for(int i=0;i<sizeof(objs);i++)
	{
		if(objs[i] == user)
			continue;
		if(flag)
		{
			if(query_ip_number(objs[i]) == me_ip_number)
				ids += ({ geteuid(objs[i]) });
		}
		else if(wizardp(objs[i]) && query_ip_number(objs[i]) == me_ip_number)
			ids += ({ geteuid(objs[i]) });
	}

	if(!sizeof(ids))
		return;
	else
		sys_log("same_ip",sprintf("登陆%s(%s)与在线%s %s 的IP地址相同，%s\n",
			(flag)?"巫师":"玩家",geteuid(user),(flag)?"人物":"巫师",
			implode(ids,"、"),ctime(time())));
}
*/

protected void get_passwd(string pass, object ob)
{
        string my_pass;
        object user;

        write("\n");
        my_pass = ob->query("password");
        if( crypt(pass, my_pass) != my_pass )
	{
		write("\n密码错误！\n");
#ifdef BLOCK_HACK_WIZ	/* define in 'login.h' */
		if( wiz_level((string)ob->query("id")) >0 )
#endif
#if defined(BLOCK_HACK_WIZ) || defined(BLOCK_HACK_ALL)
		AHACK_D->passwd_mistake((string)ob->query("id"),query_ip_number(ob));
#endif
		destruct(ob);
                return;
        }

#if defined(BLOCK_HACK_WIZ) || defined(BLOCK_HACK_ALL)
	AHACK_D->success_login((string)ob->query("id"));
#endif

#ifdef WIZ_PASSWD_CHK
	if( (string)SECURITY_D->get_status((string)ob->query("id")) != "(player)"
	&& !check_wiz_legal_password(ob,pass) )
	{
		write("请重新设定您的密码：");
		input_to( (: new_password :), 1, ob, 1);
		return;
	}
#endif

	if(!ob)	return;
        // Check if we are already playing.
        user = find_body(ob->query("id"));

	if(user && !environment(user)) /* 这种状态是不应出现的 */
		destruct(user);

        if(user)
	{
		if( user->query_temp("netdead") )
		{
                        reconnect(ob, user);
                        return;
                }

		write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
		input_to( (: confirm_relogin :), ob, user);
		return;
	}

	if(objectp(user = make_body(ob)) )
	{
		if( user->restore() )
		{
			log_file( "USAGE", sprintf("%s(%s) loggined from %s (%s)\n",
				user->query("name"), user->query("id"),
				query_ip_name(ob), ctime(time()) ) );
			enter_world(ob, user);
                        return;
		}
		else
                        destruct(user);
        }
        write("请您重新创造这个人物。\n");
        confirm_id("y", ob);
}

protected void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

	if(!objectp(ob) || !objectp(user))
	{
		if(objectp(ob))
			destruct(ob);
		if(objectp(user))
			destruct(user);
		return;
	}

	if( yn=="" )
	{
		write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)\n");
		input_to( (: confirm_relogin :), ob, user);
		return;
        }

        if( yn[0]!='y' && yn[0]!='Y' )
	{
		write("好吧，欢迎下次再来。\n");
		destruct(ob);
		return;
        }

	else
	{
		tell_object(user, "有人从别处( " + query_ip_number(ob) + " )连线取代你所控制的人物。\n");
                log_file( "USAGE", sprintf("%s(%s) replaced by %s (%s)\n",
			user->query("name"),user->query("id"),
                        query_ip_name(ob), ctime(time()) ) );
        }

        old_link = user->query_temp("link_ob");
        if( old_link )
	{
                exec(old_link, user);
                destruct(old_link);
        }

        reconnect(ob, user);    
}

protected void confirm_id(string yn, object ob)
{
	if(!ob)
		return;
	if( yn=="" )
	{
                write("\n使用这个名字将会创造一个新的人物，您确定吗(y/n)？");
                input_to( (: confirm_id :), ob);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("\n好吧，那么请重新输入您的英文名字：");
                input_to( (: get_id :), ob);
                return;
        }

        write( @TEXT

请您想一个有气质，有个性，又不会太奇怪的中文名字，特别要提醒您
的是，本 mud 是一个以古中国与东方为背景的世界 ，请不要取一些不
雅或是容易造成他人困扰的名字，这个名字将代表你的人物，而且往后
将很难再更改，请务必慎重。
  ^^^^^^^^^^
[1;33m(除了名字之外，本 mud 有许多取绰号、别称的设计，所以郑重建议您
 取一个比较像名字的中文名字。如果您的名字被认为对本游戏和游戏内
 的其它玩家造成不好的影响，将会被强制改变或删除档案。)
[2;37;0m
TEXT
        );
        write("您的中文名字：");
        input_to( (: get_name :), ob);
}

protected void get_name(string arg, object ob)
{
	if(!ob)
		return;

        if( !check_legal_name(arg) )
	{
		write("您的中文名字：");
		input_to( (: get_name :), ob);
		return;
        }

        //printf("%O\n", ob);
        ob->set("name", arg);
        write("请设定您的密码：");
        input_to( (: new_password :), 1, ob);
}

protected void new_password(string pass, object ob,int flag)
{
        write("\n");
        if( strlen(pass)<5 )
	{
                write("\n密码的长度至少要五个字元，请重设您的密码：");
                input_to( (: new_password :), 1, ob);
                return;
        }

	if(flag && !check_wiz_legal_password(ob,pass))
	{
		write("请重新设定您的密码：");
		input_to( (: new_password :), 1, ob, 1);
		return;
	}

        ob->set("password", crypt(pass,0) );
        write("请再输入一次您的密码，以确认您没记错：");
        input_to( (: confirm_password :), 1, ob, flag);
}

protected void confirm_password(string pass, object ob,int flag)
{
        string old_pass;
	object user;

        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass )
	{
                write("您两次输入的密码并不一样，请重新设定一次密码：");
                input_to( (: new_password :), 1, ob, flag);
                return;
        }

	if(flag)
	{
		write("请输入密码：");
		input_to( (: get_passwd :), 1, ob);
		return;
	}

        ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) )
	{
		destruct(ob);
                return;
	}

	write("您要扮演男性(m)的角色或女性(f)的角色？");
	input_to( (: get_gender :), ob, user);
/*
	write("您的电子邮件地址：");
#ifdef MAIL_REG
	if(ob->query("id") != "guest")
	write(HIY"(注册过程将要使用您的邮件地址,请务必认真填写)"NOR);
#endif
      input_to( (: get_email :),  ob);
*/
}
/*
protected void get_email(string email, object ob)
{
        object user;
	if(!ob) return;

	ob->set("email", email);

        ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) )
	{
		destruct(ob);
                return;
	}

        write("您要扮演男性(m)的角色或女性(f)的角色？");
        input_to( (: get_gender :), ob, user);
}
*/
protected void get_gender(string gender, object ob, object user)
{
        if( gender=="" )
	{
		write("您要扮演男性(m)的角色或女性(f)的角色？");
		input_to( (: get_gender :), ob, user);
		return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "男性");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "女性" );
        else
	{
                write("对不起，您只能选择男性(m)或女性(f)的角色：");
                input_to( (: get_gender :), ob, user);
                return;
        }

	user->set("str", 15);
	user->set("int", 15);
	user->set("cor", 15);
	user->set("con", 15);
	user->set("per", 15);
	user->set("kar", 15);

        init_new_player("",ob,user);
}

object make_body(object ob)
{
	string err,usr_file;
	object user;

	if(base_name(ob) != LOGIN_OB)
		return 0;

	if( previous_object() && (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	usr_file = ob->query("body");
	if(!usr_file)
		usr_file = "/obj/user/user";

        user = new(usr_file);
	if(!user)
	{
		write("现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
                write(err+"\n");
                return 0;
        }

        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());
        user->set("id", ob->query("id"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        return user;
}

protected void display_tianfu(object who)
{
	if(!objectp(who))
		return;

        printf("\n%s你当前的天赋为：%s\n %s膂力(str)：[%d]  胆识(cor)：[%d]  悟性(int)：[%d]%s\n"
               " %s容貌(per)：[%d]  根骨(con)：[%d]  福缘(kar)：[%d]\n\n"NOR,
		BWHT HIB, NOR,
		BWHT HIB,
		who->query("str"),
		who->query("cor"),
		who->query("int"),
		NOR, BWHT HIB,
		who->query("per"),
		who->query("con"),
		who->query("kar"));
}

protected void display_select_guide()
{
	printf("≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡
 游戏初始提供给玩家一部分天赋点数，你可以根据喜好
 自由分配，每项天赋的最小数值为 15，最大数值为 30。
≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡

     分配方法为：  天赋 [+|-]数值

例如：你希望给臂力分配 5 点，可以输入：str +5
      你希望减少悟性 4 点，可以输入： con -4

  %s◆◆ 如果希望由游戏帮助你随机分配请输入 0 ◆◆
" NOR, BWHT HIY);
}

protected void random_select_tianfu(object user)
{
	if(!objectp(user))
		return;

	user->set("kar",0);
	while( !user->query("kar") )
	{
		int n;
		user->set("str", 15 + random(15));
		user->set("int", 15 + random(15));
		user->set("cor", 15 + random(15));
		user->set("con", 15 + random(15));
		user->set("per", 15 + random(15));
		n = user->query("str") + user->query("int")+ user->query("cor") +
			user->query("con") + user->query("per");
		if( (n > MAX_ATTR_SUM)
		|| (MAX_ATTR_SUM - n < 15)
		|| (MAX_ATTR_SUM - n > 30) )
			user->set("kar",0);
		else
			user->set("kar",MAX_ATTR_SUM - n);   
        }
}

protected void set_new_player(object ob,object user)
{
	if(!ob || !user)
	{
		if(user) destruct(user);
		if(ob) destruct(ob);
		return;
        }

	user->set("title", "普通百姓");
	user->set("birthday", time() );
	user->set("potential", 99);
	user->set("combat_exp",100);

	log_file( "USAGE", sprintf("%s(%s) was created from %s (%s)\n", 
		user->query("name"),user->query("id"),
		query_ip_name(ob), ctime(time()) ) );

	user->set("new_begin",1);

	ob->set("birthday", ctime(time()) );

	CHAR_D->setup_char(user);
	user->set("food", user->max_food_capacity());
	user->set("water", user->max_water_capacity());

	if(!wiz_level(user->query("id")))
		user->set("channels", ({ "chat", "rumor", "menpai", "tx" }) );
	else
		user->set("channels", ({ "chat", "rumor", "wiz", "sys", "menpai", "tx" }) );

	user->add_credit_point(ST_CREDIT_POINT);
	enter_world(ob, user);
}

protected void init_new_player(string yn,object ob,object user)
{
	int left,Tcon,Tper,Tint,Tstr,Tcor,Tkar,Tchange;
	string which, plus, *all_tianfu = ({ "str", "cor", "int", "per", "con", "kar" });

	if(!ob || !user)
	{
		if(user) destruct(user);
		if(ob) destruct(ob);
		return;
        }

	printf("\n");
	if( (yn == "0") || (yn == "o") )
	{
		random_select_tianfu(user);
		display_tianfu(user);
		printf("你是否决定选用这一组天赋？[y/n]：");
		input_to( (: init_new_player :),ob,user);
		return;
	}

	Tstr = (int)user->query("str");
	Tcor = (int)user->query("cor");
	Tint = (int)user->query("int");
	Tper = (int)user->query("per");
	Tcon = (int)user->query("con");
	Tkar = (int)user->query("kar");

	if( (sizeof(yn) && (yn[0] == 'n'))
	|| (Tstr > 30) || (Tstr < 15)	// 查错
	|| (Tcor > 30) || (Tcor < 15)
	|| (Tint > 30) || (Tint < 15)
	|| (Tper > 30) || (Tper < 15)
	|| (Tcon > 30) || (Tcon < 15)
	|| (Tkar > 30) || (Tkar < 15)
	|| ( (left = MAX_ATTR_SUM - (Tstr + Tcor + Tint + Tper + Tcon + Tkar)) < 0) )
	{
		user->set("str", 15);
		user->set("int", 15);
		user->set("cor", 15);
		user->set("con", 15);
		user->set("per", 15);
		user->set("kar", 15);
		display_tianfu(user);
		display_select_guide();
		printf("你目前有 30 点天赋点数可用于分配，请设定：");
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if(left == 0) // 完成
	{
		set_new_player(ob, user);
		return;
	}

	if(!yn || (yn == "") || sscanf(yn,"%s %s%d",which, plus, Tchange) != 3)
	{
		display_tianfu(user);
		display_select_guide();
		printf("你目前有 %d 点天赋点数可用于分配，请设定：",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	which = replace_string(which," ","");
	if(member_array(which,all_tianfu) == -1)
	{
		printf(HIG"\n[请从六种天赋中选择你要设定的天赋]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("你目前有 %d 点天赋点数可用于分配，请设定：",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if(!Tchange)
	{
		printf(HIG"\n[请用阿拉伯数字表明你要修改的数值量]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("你目前有 %d 点天赋点数可用于分配，请设定：",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	plus = replace_string(plus," ","");
	if(plus == "")
		plus = "+";
	if( (plus != "+") && (plus != "-") )
	{
		printf(HIG"\n[请选用正确的增(+)、减(-)符号]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("你目前有 %d 点天赋点数可用于分配，请设定：",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if( (plus == "+") && (Tchange > left) )
	{
		printf(HIG"\n[你目前只剩下 %d 个可分配的天赋点数]\n"NOR,left);
		display_tianfu(user);
		display_select_guide();
		printf("你目前有 %d 点天赋点数可用于分配，请设定：",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if( (plus == "+") && (user->query(which) + Tchange > 30) )
	{
		printf(HIG"\n[每项天赋的最大数值是 30 点]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("你目前有 %d 点天赋点数可用于分配，请设定：",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if( (plus == "-") && (user->query(which) - Tchange < 15) )
	{
		printf(HIG"\n[每项天赋的最小数值是 15 点]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("你目前有 %d 点天赋点数可用于分配，请设定：",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	printf(BWHT HIG"\n [%s%s %d 点] \n"NOR,capitalize(which),plus=="+"?"增加":"减少",Tchange);
	user->add(which,(plus=="+"?Tchange:-Tchange));

	display_tianfu(user);
	if(plus == "+")
		left -= Tchange;
	else
		left += Tchange;

	if(!left)
		printf("你是否决定选用这一组天赋？[y/n]：");

	else
	{
		display_select_guide();
		printf("你目前有 %s 点天赋点数可用于分配，请设定：",sprintf(HIC"%d"NOR,left));
	}

	input_to( (: init_new_player :),ob,user);
	return;
}

varargs void enter_world(object ob, object user, int silent)
{
        object cloth,shoes,marrycard,mailbox;
        string startroom,self_cloth;
        int n;
        object couple_ob;
        string tmpstr, tmpstr1;
	mapping marry;

	if(!ob || !user)
	{
		if(ob)
			destruct(ob);
		if(user)
			destruct(user);
		return;
	}

	if( previous_object() && (geteuid(previous_object()) != ROOT_UID) )
		return;

        ob->set("last_on", time());
	user->set_encoding(ob->query_encoding());
        exec(user, ob);
        write("目前权限：" + wizhood(user) + "\n");
        user->setup();
        user->save();
        ob->save();

	//check_same_ip_number(user);

        cloth = new(ARMOR_DIR"cloth");
        shoes = new(ARMOR_DIR"boot");

	if(!cloth->move(user) || !shoes->move(user))
	{
		write(HIY ">>>>>>>> 你已超重. <<<<<<<<\n" NOR );  // 防止超重判断.
		destruct(cloth);
                destruct(shoes);
	}

	else
	{
		cloth->wear();
		shoes->wear();
//                if(wizardp(user))
//		shoes->set("name",HIY "无敌风火轮" NOR);

		if(wizardp(user))
		cloth->set("name",HIY "巫师四季袍" NOR);
//		shoes->set("name",HIY "无敌风火轮" NOR);

		else if(stringp(self_cloth = user->query("self_cloth"))
		&& self_cloth != "")
			cloth->set("name",self_cloth);
		else

		switch (user->query("class"))
		{
			case "taxue":
				if(user->query("gender") != "男性") 
				cloth->set("name",WHT "素白羽衣" NOR);
				else
				cloth->set("name",WHT "貂皮长袍" NOR); 
				break;

                        case "gaibang":
                                cloth->set("name",YEL "百衲结衣" NOR);
                                break;

                        case "rain":
                                cloth->set("name",HIG "翠绿衣衫" NOR);
                                break;

                        case "huashan":
                                if(user->query("gender") != "男性")
                                cloth->set("name",CYN "素青长裙" NOR);
                                else
                                cloth->set("name",WHT "紧身劲装" NOR);
                                break;

                        case "tangmen":
                                if(user->query("gender") != "男性")
                                cloth->set("name",MAG "轻纱长裙" NOR);
                                else
                                cloth->set("name",WHT "素白锦衣" NOR);
                                break;

                        case "jinghai":
                                cloth->set("name",BLU "鱼皮水装" NOR);
//				shoes->set("name",GRN "草鞋" NOP);
                                break;

                        case "shaolin":
                                cloth->set("name",CYN "青布袈裟" NOR);
                                break;
			default:
		}

/*
		switch (NATURE_D->query_season())
		{
			case (1):	// 春 
			case (3):	// 秋 
				cloth->set("name",(user->query("gender") == "男性")?
					"夹袄":"棉裙");
				break;
			case (2):	// 夏 
				cloth->set("name",(user->query("gender") == "男性")?
					"布褂":"布裙");
				break;
			case (4):	// 冬 
				cloth->set("name",(user->query("gender") == "男性")?
					"棉袄":"花棉袄");
				break;
		}
*/
	}

	/* 14 岁不能典当，鬼魂不能 restore 当票 */
	if(user->query("age") > 14
	&& !user->is_ghost()
	&& user->query("combat_exp") >= 20000)
		PAWN_D->restore_players_pawnstamp(user);

        if( !silent )
	{
		mapping renyi;

		if(wizardp(user) && file_size( WIZMOTD ) > 0)
			printf(read_file(WIZMOTD));
		else if(file_size( MOTD ) > 0)
			printf(read_file(MOTD));

		if(user->query("new_begin"))
			newbie_buildup(user->query("id"),user->name());

		if(user->query("id") == "guest")
			startroom = START_ROOM;

		else if( user->is_ghost() )
                        startroom = DEATH_ROOM;
#ifdef MAIL_REG
		else if(user->query("new_begin"))
			startroom = REGISTER_ROOM;
		else if(user->query("have_reg"))
		{
			user->delete("have_reg");
			newbie_success_reg(user->query("id"));
			startroom = WELCOME_ROOM;
			NEWS_D->add_news_item( sprintf("新玩家 %s(%s) 注册进入这个疯狂的世界。\n",
				user->query("name"),capitalize(user->query("id"))),"w", 1);
		}
#else
		else if(user->query("new_begin"))
		{
			startroom = WELCOME_ROOM;
			NEWS_D->add_news_item( sprintf("新玩家 %s(%s) 投入这个疯狂的世界。\n",
			user->query("name"),capitalize(user->query("id"))),"p", 1);
		}
#endif

                else if( !stringp(startroom = user->query("startroom")) )
                        startroom = start_loc[random(sizeof(start_loc))];

		if(!user->is_ghost() && (startroom == DEATH_ROOM))
			startroom = START_ROOM;

		if(!wizardp(user) && !sscanf(startroom,"/d/%*s"))
			startroom = START_ROOM;

                if( (file_size(startroom+".c") > 0) && !catch(load_object(startroom)) )
		{
                        user->move(startroom);
			user->set("startroom", startroom);
		}

		else
		{
                        user->move(START_ROOM);
                        startroom = START_ROOM;
                        user->set("startroom", START_ROOM);
		}

		if(mapp(renyi = user->query("enyi_class")) && sizeof(renyi))
		{
			if(!RENYI_D->query_have_killer_quest(user->query("id")))
				user->delete("enyi_class");
			else if(renyi["a_id"] && renyi["a_name"])
			{
				user->set_mask_name( renyi["a_name"] );
				user->set_mask_id( renyi["a_id"] );
			}
		}
		tell_room(startroom, user->name() + "连线进入这个世界。\n",
		filter_array( all_inventory(environment(user)), "filter_invisible", this_object(),user ) );
		user->load_all_my_ob();
        }

	if (user->query("force")>2*user->query("max_force")*2)
		user->set("force",2*user->query("max_force"));

	message("channel:sys",sprintf(HIR"【连线精灵】：%s(%s)由 %s 连线进入。\n"NOR,
		user->name(1),user->query("id"),query_ip_number(user) ),
		filter_array(users(),(: wizardp :)));

        UPDATE_D->check_user(user);

	if( (user->query("id") != "guest") && (startroom != WELCOME_ROOM) )
		NEWS_D->display_news(user);

	if(!user->query("new_begin"))
	{
		mailbox = new(MAILBOX_OB);
		if(!mailbox->move(user))
		{
			write(HIY ">>>> 你已超重，无法载入你的邮箱。<<<<\n" NOR );  // 防止超重判断.
			destruct(mailbox);
		}

		else
			write(sprintf(GRN"\n邮差来到你的面前，一拱手说道：这位英雄请了，这里是您的信箱。%s\n\
一眨眼的功夫,邮差走了。。。。\n"NOR,(n=mailbox->query_unread_count())?
		sprintf(HIY"\n>> 您有 %d 封新邮件没有看。<<"NOR GRN,n):"" ));
	}

	/*	marry 部分标记:
		marry/id : <ID>
		marry/name : 伴侣中文名
		marry/date : 结婚日期  (年月日)
	*/

	if( mapp(marry = user->query("marry")) && sizeof(marry) )
	{
		marrycard = new(MARRYCARD_OB);
		marrycard->set_master( user->name(),
				geteuid(user),
				marry["name"],
				marry["id"],
				marry["date"]);

		if(!marrycard->move(user))
		{
			write(HIY ">>>>>>>> 你已超重. <<<<<<<<\n" NOR );    // 防止超重判断.
			destruct(marrycard);
		}
                marrycard->init_emote();

		couple_ob = find_player(marry["id"]);

		if(couple_ob)
		{
			if((string)user->query("gender") != "男性")
			{
				tmpstr1 = "夫君"; 
				tmpstr = "爱妻";
                        }

			else
			{
                                tmpstr1 = "爱妻";
                                tmpstr = "夫君";
                        }
			write(sprintf( BWHT HIM "\n你的%s%s已经在这等了你好久了，\n快去找%s吧。。。\n"NOR,
				tmpstr1,couple_ob->name(),gender_pronoun(couple_ob->query("gender"))));
			tell_object(couple_ob ,sprintf( BWHT HIM "\n你的%s%s抑制不住对你的思念跑来看你啦，\n快去和%s打个招呼吧。。。\n" NOR,
				tmpstr,user->name(),gender_pronoun(user->query("gender"))));
		}

		else if(!search_partner(marry["id"]))
		{
			tell_object(user,HIR"你的伴侣已经永远的离开了这个世界。\n"NOR);
			user->delete("marry");
			user->save();
			if(marrycard)
				destruct(marrycard);
		}
	}

	user->set_temp("newlogin",1);

	if(user->query("id") == "guest")
	{
		write("欢迎来到这里参观。\n");
		user->guest_count();
	}

	else if(user->query("new_begin"))
	{
#ifndef MAIL_REG
		user->delete("new_begin");
#endif
		write(HIG"\n>>>>> 欢迎你第一次来到这个世界！:)\n\n"NOR);
	}

	else
		write("\n你上次连线是从" + HIG +ob->query("last_from") + NOR + " 进入的，退出时间为："
			+ HIG +ctime(ob->query("last_out"))+ NOR + "\n\n");

        if(wizardp(user))
        {
		if(!user->query("change_passwd"))
			user->set("change_passwd",user->query("birthday"));
		if( (time()-(int)user->query("change_passwd")) >= 2592000 )
			write(HIY BOLD BLINK "\n您上一次更换密码是在"
			+chinese_number( (int)((time()-(int)user->query("change_passwd"))/86400))+
			"天以前，请及时更换密码！\n\n" NOR);
        }

	call_out("del_newlogin", 179, user);
}

int filter_invisible(object ob,object user)
{
	if(ob == user)
		return 1;
	if( !userp(ob) )
		return 1;
	if( !ob->visible(user) )
		return 1;
	return 0;
}

protected int search_partner(string part)
{
	object ob;

	ob = new(LOGIN_OB);
	ob->set("id", part);
        if( !ob->restore() )
	{
		destruct(ob);
		return 0;
	}
	destruct(ob);
	return 1;
}

varargs void reconnect(object ob, object user, int silent)
{
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);

	if( !exec(user, ob) )
	{
		write("无法重新连线，请尝试重新登陆。\n\n");
		if(objectp(user))
			destruct(user);
		if(objectp(ob))
			destruct(ob);
		return;
	}

        user->reconnect();
        if( !silent )
	{
		tell_room(environment(user), user->query("name") + "重新连线回到这个世界。\n",
		filter_array( all_inventory(environment(user)), "filter_invisible", this_object(),user ) );
        }

	message("channel:sys",sprintf(HIR"【连线精灵】：%s(%s)由%s重新连线进入。\n"NOR,
		user->name(),user->query("id"),query_ip_number(user) ),
		filter_array(users(),(: wizardp :)));
        UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
        int *m = ({}), i = strlen(id);
        
	if( (strlen(id) < 3) || (strlen(id) > 10 ) )
	{
                write("\n对不起，你的英文名字必须是 3 到 10 个英文字母。\n");
                return 0;
        }

	while(i--)
	{
		if( id[i]<'a' || id[i]>'z' )
		{
                        write("\n对不起，你的英文名字只能用英文小写字母。\n");
                        return 0;
                }
		if(member_array(id[i],m) == -1)
			m += ({ id[i] });
	}

	if(sizeof(m) < 2)
	{
		write("--> 这个 ID 过于平淡，请再想一个有个性的 ID 。\n");
		return 0;
	}

	if((strlen(id) > 3) && (strsrch(id, "fuke") != -1))
	{
		write("\n这个 ID 是禁止使用的。\n");
		return 0;
	}

	if ( BAN_D->is_banned(id,1))
	{
		write(HIR"\n对不起，\""+id+"\" 这个 ID 在" + MUD_NAME + "里是禁止使用的。\n"NOR);
		return 0;
        }

        return 1;
}

int check_wiz_legal_password(object ob,string pass)
{
	string id;
	int i;
	int capitalize = 0,lower_case = 0,symbol = 0;

	if( strlen(pass) < 10)
	{
		write("\n对不起，作为巫师你的密码至少 10 个字符。\n");
		return 0;
	}

	id = ob->query("id");
	if( strsrch(id,lower_case(pass)) != -1
	|| strsrch(lower_case(pass),id) != -1
	|| strsrch(lower_case(pass),id[1..]) != -1
	|| strsrch(lower_case(pass),id[0..<2]) != -1)
	{
		write("\n对不起，你的密码和你的相似处过多。\n");
			return 0;
	}

	i = strlen(pass);
	while(i--)
	{
                if( pass[i]<='Z' && pass[i] >='A' )
		{
			capitalize++;
			continue;
		}
		else if( pass[i]<='z' && pass[i] >='a' )
		{
			lower_case++;
			continue;
		}
		else if( pass[i]<='~' && pass[i] >='!' )
		{
			symbol++;
			continue;
		}
        }

	if(!capitalize || !lower_case || !symbol)
	{
		write("\n作为巫师你的密码必须包含大写、小写英文字母和特殊符号。\n");
		return 0;
	}
	return 1;
}

int check_legal_name(string name)
{
        int i;

	if( strsrch(name,"　") != -1)
        {
		write("\n对不起，你的中文名字不能用空格。\n");
                return 0;
        }

	if( strsrch(name,"爸") != -1)
        {
		write(HIR"\n对不起，这个名字在" + MUD_NAME + "里是禁止使用的。\n"NOR);
                return 0;
        }

	if( strsrch(name,"爹") != -1)
        {
		write(HIR"\n对不起，这个名字在" + MUD_NAME + "里是禁止使用的。\n"NOR);
                return 0;
        }

	if( strsrch(name,"妈") != -1)
        {
		write(HIR"\n对不起，这个名字在" + MUD_NAME + "里是禁止使用的。\n"NOR);
                return 0;
        }

	if( strsrch(name,"屎") != -1)
        {
		write(HIR"\n对不起，这个名字在" + MUD_NAME + "里是禁止使用的。\n"NOR);
                return 0;
        }

        i = strlen(name);
        
	if( (strlen(name) < 2) || (strlen(name) > 12 ) )
	{
		write("\n对不起，你的中文名字必须是 1 到 6 个中文字。\n");
		return 0;
        }

	while(i--)
	{
		int section;

                if( name[i]<128 )
		{
			write("\n对不起，请您用「中文」取名字。\n");
                        return 0;
                }

		if( i%2==0 )
		{
			section = name[i] - 160;

			if( (section < 16)
			|| (section > 87) )
			{
				write("\n对不起，请您使用常用「汉字」取名字。\n");
				return 0;
			}
		}
	}

	if ( BAN_D->is_banned(name,3))
	{
		write(HIR"\n对不起，这个名字在" + MUD_NAME + "里是禁止使用的。\n"NOR);
		return 0;
	}

	if(name[0..1] == "唐")
	{
		write("'唐'这个姓氏和游戏内容有冲突，请另外换一个姓氏。\n");
		return 0;
	}

        if(name[0..3] == "踏雪")
        {
                write("'踏雪'这个姓氏和游戏内容有冲突，请另外换一个姓氏。\n");
                return 0;
        }

	if(permit_add_cname(name))
	{
		write("\n*** 对不起，这个名字已经有人使用了，再想一个吧。***\n"NOR);
		return 0;
	}

        return 1;
}

object find_body(string name)
{
        object ob, *body;

        if( objectp(ob = find_player(name)) )
                return ob;

        body = children(USER_OB);
        for(int i=0; i<sizeof(body); i++)
		if( clonep(body[i]) && getuid(body[i]) == name )
			return body[i];
        return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}

void del_newlogin(object me)
{
	if (objectp(me) &&  me->query_temp("newlogin"))
		me->delete_temp("newlogin");
}

int all_online_players()
{
	mapping listnodes;
	string *muds;
	int i,num=0;

	if( !find_object(DNS_MASTER) )
		return 0;

	listnodes = (mapping)DNS_MASTER->query_muds();

	muds = keys(listnodes);

	for(i=0;i<sizeof(muds);i++)
	{
		if(muds[i] == mud_nname())
			continue;
		if( !undefinedp(listnodes[muds[i]]["USERS"]))
			num += atoi(listnodes[muds[i]]["USERS"]);
        }

	return num;
}

void report_netdead(object me)
{
	if(!me || !userp(me))
		return;

	message("channel:sys",sprintf(HIR"【连线精灵】：%s(%s)断线了。\n"NOR,
		me->name(),me->query("id") ),
		filter_array(users(),(: wizardp :)));
}

string user_file(string id)
{
	if(!stringp(id) || id == "")
		return "";

	return sprintf(DATA_DIR+"user/%c/%s%s",id[0],id,__SAVE_EXTENSION__);
}

string login_file(string id)
{
	if(!stringp(id) || id == "")
		return "";

	return sprintf(DATA_DIR+"login/%c/%s%s",id[0],id,__SAVE_EXTENSION__);
}
