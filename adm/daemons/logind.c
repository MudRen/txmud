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
protected int MAX_ATTR_SUM = 120;	// �츳�ܺ�

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
		write(sprintf("%s�������������У����Ժ�������\n",MUD_NAME));
		destruct(ob);
		return;
	}

	if(no_login)
	{
		write(sprintf("%s�ѽ�����������������̣����Ժ�������\n",MUD_NAME));
		destruct(ob);
		return;
	}

#ifdef GB_AND_BIG5
	printf(read_file(TITLE));

	write("           �����¡���ӭ�����ã�ʹ�ù�������������룺gb\n");
	write("           ���t�W�L�W���w��z�ӳX�I�ϥΤj���X�����a����J�Gbig5\n\n");
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
	    write("\nSelect ������ GB or �j���X BIG5 (gb/big5):");
	    input_to( (: encoding :), ob );
	    return;
	}
	else if(arg[0]=='g' || arg[0]=='G')
	    encode=0;
	else if(arg[0]=='b' || arg[0]=='B')
	    encode=1;
	else
	{
	    write("\nSelect ������ GB or �j���X BIG5 (gb/big5):");
	    input_to( (: encoding :), ob );
	    return;
	}
	
	ob->set_encoding(encode);

	printf(REF);
	printf(read_file(WELCOME));
	//write("�����������......");
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
		write(HIR"�Բ������IP��ַ��" + MUD_NAME + "���ܻ�ӭ��\n");
		destruct(ob);
		return;
        }

	printf(WHT"[����ʱ��]��"+cctime(time())+"\n");
	printf("[����ʱ��]��");
	UPTIME_CMD->main();
	printf(sprintf("[��Ϸ����]��%s����Ŀǰ���� %s λ����\n",MUD_NAME, chinese_number(count_reg_user())));
	printf("[����ͳ��]��");
	"/cmds/imm/bps"->main();
/*
	printf(sprintf("[���ͳ��]����Ϸ��ǰ��������� %d ����ʹ�ü��������� %s��\n\n" NOR,
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
		write("�Բ������IP��¼����̫����\n");
		destruct(ob);
		return;
	}
*/

	count = all_online_players();
	if(!count)
		printf(NOR "\nĿǰ"); // info not available
	else
		printf(NOR HIG"\nĿǰ����%dλ��������ϡ�"NOR+"\n��վ", count+wiz_cnt+ppl_cnt );

        printf("���� %s%d λ��������ϣ��Լ� %d λʹ���߳��������С�\n\n",
                wiz_cnt?sprintf("%d λ����Ա��",wiz_cnt):"", ppl_cnt, login_cnt );

        write("����Ӣ�����֣�");
        input_to( (: get_id :), ob );
}

protected void get_id(string arg, object ob)
{
        object ppl,user;
	string where;

        arg = lower_case(arg);
        if( !check_legal_id(arg))
	{
		write("����Ӣ�����֣�");
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
                        write("�Բ���" + MUD_NAME + "��ʹ�����Ѿ�̫���ˣ������������\n");
                        destruct(ob);
                        return;
                }
        }

        if( wiz_level(arg) < wiz_lock_level )
	{
		write("�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� " +   wiz_level_name(wiz_lock_level)
			+ " ���ϵ��˲������ߡ�\n");
		destruct(ob);
		return;
	}

	if(AHACK_D->query_block(arg))
	{
		write(HIY"����˺ű���ʱ�����ˣ����� guest ���������������ʦ��ϵ��\n"NOR);
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
			write("Ŀǰ guest �˺���������ʹ�ã����һ���ٵ�½��\n");
			destruct(ob);
			return;
		}

		ob->set("body", USER_OB);
		if( !objectp(user = make_body(ob)) )
		{
			destruct(ob);
			return;
		}
		user->set("name","��ʱ����");
		user->set("gender","����");
		user->set("title", "��ͨ����");
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
			if(!ob->query("password")) // ����������.
			{
				rm(login_file(arg));
				if(file_size(user_file(arg)) >= 0)
					rename(user_file(arg),BACKUP_DIR+arg+".o");
				write("���ĵ����������������´���������\n");
				confirm_id("y", ob);
				return;
			}
                        write("��������Ѿ�ע�ᣬ������ע�����룺");
                        input_to( (: get_passwd :), 1, ob);
                        return;
                }
                write("�������ﴢ�浲����һЩ���⣬������ guest ����֪ͨ��ʦ����\n");
                destruct(ob);
                return;
        }

#ifdef REFUSE_NEW_PLAYER
        write("�Բ������ڷ����ʼ��������������⣬\nĿǰ"+MUD_NAME+"��ʱ����������ҵǼǡ�\n�������Ϸ��ҳ��http://www.mudtx.com �����ϸ��ѶϢ��\n");
	destruct(ob);
	return;
#endif

	where = query_register_station(arg);
	if(stringp(where) && (where != ""))
	{
		write(sprintf("[%s] ��� ID �Ѿ���%sע����\n��ȥ�����½������Ϸ��\n",
			arg,!undefinedp(stations[where])?stations[where]:"��ĵط�"));
		destruct(ob);
		return;
	}

        write("ʹ�� " + (string)ob->query("id") + " ������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
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
		sys_log("same_ip",sprintf("��½%s(%s)������%s %s ��IP��ַ��ͬ��%s\n",
			(flag)?"��ʦ":"���",geteuid(user),(flag)?"����":"��ʦ",
			implode(ids,"��"),ctime(time())));
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
		write("\n�������\n");
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
		write("�������趨�������룺");
		input_to( (: new_password :), 1, ob, 1);
		return;
	}
#endif

	if(!ob)	return;
        // Check if we are already playing.
        user = find_body(ob->query("id"));

	if(user && !environment(user)) /* ����״̬�ǲ�Ӧ���ֵ� */
		destruct(user);

        if(user)
	{
		if( user->query_temp("netdead") )
		{
                        reconnect(ob, user);
                        return;
                }

		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
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
        write("�������´���������\n");
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
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)\n");
		input_to( (: confirm_relogin :), ob, user);
		return;
        }

        if( yn[0]!='y' && yn[0]!='Y' )
	{
		write("�ðɣ���ӭ�´�������\n");
		destruct(ob);
		return;
        }

	else
	{
		tell_object(user, "���˴ӱ�( " + query_ip_number(ob) + " )����ȡ���������Ƶ����\n");
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
                write("\nʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
                input_to( (: confirm_id :), ob);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("\n�ðɣ���ô��������������Ӣ�����֣�");
                input_to( (: get_id :), ob);
                return;
        }

        write( @TEXT

������һ�������ʣ��и��ԣ��ֲ���̫��ֵ��������֣��ر�Ҫ������
���ǣ��� mud ��һ���Թ��й��붫��Ϊ���������� ���벻ҪȡһЩ��
�Ż�����������������ŵ����֣�������ֽ�������������������
�������ٸ��ģ���������ء�
  ^^^^^^^^^^
[1;33m(��������֮�⣬�� mud �����ȡ�ºš���Ƶ���ƣ�����֣�ؽ�����
 ȡһ���Ƚ������ֵ��������֡�����������ֱ���Ϊ�Ա���Ϸ����Ϸ��
 �����������ɲ��õ�Ӱ�죬���ᱻǿ�Ƹı��ɾ��������)
[2;37;0m
TEXT
        );
        write("�����������֣�");
        input_to( (: get_name :), ob);
}

protected void get_name(string arg, object ob)
{
	if(!ob)
		return;

        if( !check_legal_name(arg) )
	{
		write("�����������֣�");
		input_to( (: get_name :), ob);
		return;
        }

        //printf("%O\n", ob);
        ob->set("name", arg);
        write("���趨�������룺");
        input_to( (: new_password :), 1, ob);
}

protected void new_password(string pass, object ob,int flag)
{
        write("\n");
        if( strlen(pass)<5 )
	{
                write("\n����ĳ�������Ҫ�����Ԫ���������������룺");
                input_to( (: new_password :), 1, ob);
                return;
        }

	if(flag && !check_wiz_legal_password(ob,pass))
	{
		write("�������趨�������룺");
		input_to( (: new_password :), 1, ob, 1);
		return;
	}

        ob->set("password", crypt(pass,0) );
        write("��������һ���������룬��ȷ����û�Ǵ�");
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
                write("��������������벢��һ�����������趨һ�����룺");
                input_to( (: new_password :), 1, ob, flag);
                return;
        }

	if(flag)
	{
		write("���������룺");
		input_to( (: get_passwd :), 1, ob);
		return;
	}

        ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) )
	{
		destruct(ob);
                return;
	}

	write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
	input_to( (: get_gender :), ob, user);
/*
	write("���ĵ����ʼ���ַ��");
#ifdef MAIL_REG
	if(ob->query("id") != "guest")
	write(HIY"(ע����̽�Ҫʹ�������ʼ���ַ,�����������д)"NOR);
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

        write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
        input_to( (: get_gender :), ob, user);
}
*/
protected void get_gender(string gender, object ob, object user)
{
        if( gender=="" )
	{
		write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
		input_to( (: get_gender :), ob, user);
		return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "����");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "Ů��" );
        else
	{
                write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
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
		write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
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

        printf("\n%s�㵱ǰ���츳Ϊ��%s\n %s����(str)��[%d]  ��ʶ(cor)��[%d]  ����(int)��[%d]%s\n"
               " %s��ò(per)��[%d]  ����(con)��[%d]  ��Ե(kar)��[%d]\n\n"NOR,
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
	printf("�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�
 ��Ϸ��ʼ�ṩ�����һ�����츳����������Ը���ϲ��
 ���ɷ��䣬ÿ���츳����С��ֵΪ 15�������ֵΪ 30��
�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�

     ���䷽��Ϊ��  �츳 [+|-]��ֵ

���磺��ϣ������������ 5 �㣬�������룺str +5
      ��ϣ���������� 4 �㣬�������룺 con -4

  %s���� ���ϣ������Ϸ������������������� 0 ����
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

	user->set("title", "��ͨ����");
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
		printf("���Ƿ����ѡ����һ���츳��[y/n]��");
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
	|| (Tstr > 30) || (Tstr < 15)	// ���
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
		printf("��Ŀǰ�� 30 ���츳���������ڷ��䣬���趨��");
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if(left == 0) // ���
	{
		set_new_player(ob, user);
		return;
	}

	if(!yn || (yn == "") || sscanf(yn,"%s %s%d",which, plus, Tchange) != 3)
	{
		display_tianfu(user);
		display_select_guide();
		printf("��Ŀǰ�� %d ���츳���������ڷ��䣬���趨��",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	which = replace_string(which," ","");
	if(member_array(which,all_tianfu) == -1)
	{
		printf(HIG"\n[��������츳��ѡ����Ҫ�趨���츳]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("��Ŀǰ�� %d ���츳���������ڷ��䣬���趨��",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if(!Tchange)
	{
		printf(HIG"\n[���ð��������ֱ�����Ҫ�޸ĵ���ֵ��]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("��Ŀǰ�� %d ���츳���������ڷ��䣬���趨��",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	plus = replace_string(plus," ","");
	if(plus == "")
		plus = "+";
	if( (plus != "+") && (plus != "-") )
	{
		printf(HIG"\n[��ѡ����ȷ����(+)����(-)����]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("��Ŀǰ�� %d ���츳���������ڷ��䣬���趨��",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if( (plus == "+") && (Tchange > left) )
	{
		printf(HIG"\n[��Ŀǰֻʣ�� %d ���ɷ�����츳����]\n"NOR,left);
		display_tianfu(user);
		display_select_guide();
		printf("��Ŀǰ�� %d ���츳���������ڷ��䣬���趨��",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if( (plus == "+") && (user->query(which) + Tchange > 30) )
	{
		printf(HIG"\n[ÿ���츳�������ֵ�� 30 ��]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("��Ŀǰ�� %d ���츳���������ڷ��䣬���趨��",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if( (plus == "-") && (user->query(which) - Tchange < 15) )
	{
		printf(HIG"\n[ÿ���츳����С��ֵ�� 15 ��]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("��Ŀǰ�� %d ���츳���������ڷ��䣬���趨��",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	printf(BWHT HIG"\n [%s%s %d ��] \n"NOR,capitalize(which),plus=="+"?"����":"����",Tchange);
	user->add(which,(plus=="+"?Tchange:-Tchange));

	display_tianfu(user);
	if(plus == "+")
		left -= Tchange;
	else
		left += Tchange;

	if(!left)
		printf("���Ƿ����ѡ����һ���츳��[y/n]��");

	else
	{
		display_select_guide();
		printf("��Ŀǰ�� %s ���츳���������ڷ��䣬���趨��",sprintf(HIC"%d"NOR,left));
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
        write("ĿǰȨ�ޣ�" + wizhood(user) + "\n");
        user->setup();
        user->save();
        ob->save();

	//check_same_ip_number(user);

        cloth = new(ARMOR_DIR"cloth");
        shoes = new(ARMOR_DIR"boot");

	if(!cloth->move(user) || !shoes->move(user))
	{
		write(HIY ">>>>>>>> ���ѳ���. <<<<<<<<\n" NOR );  // ��ֹ�����ж�.
		destruct(cloth);
                destruct(shoes);
	}

	else
	{
		cloth->wear();
		shoes->wear();

		if(wizardp(user))
		{
		cloth->set("name",HIY "��ʦ�ļ���" NOR);
		shoes->set("name",HIY "�޵з����" NOR);
		}

		else if(stringp(self_cloth = user->query("self_cloth"))
		&& self_cloth != "")
			cloth->set("name",self_cloth);
		else

		switch (user->query("class"))
		{
			case "taxue":
				if(user->query("gender") != "����") 
				{
				cloth->set("name",WHT "�ذ�����" NOR);
				shoes->set("name",WHT "��Ƥ��ѥ" NOR);
				}
				else
				{
				cloth->set("name",WHT "��Ƥ����" NOR); 
				shoes->set("name",WHT "��Ƥ��ѥ" NOR);
				}
				break;

                        case "gaibang":
                                if(user->query("gender") != "����")
                                {
                                cloth->set("name",YEL "���Ľ���" NOR);
				shoes->set("name",GRN "�ƾɲ�Ь" NOR);
                                }
                                else
                                {
				cloth->set("name",YEL "���Ľ���" NOR);
                                shoes->set("name",GRN "�ƾɲ�Ь" NOR);
                                }
                                break;

                        case "rain":
                                if(user->query("gender") != "����")
                                {
				cloth->set("name",HIG "��������" NOR);
                                shoes->set("name",HIR "�廨��Ь" NOR);
                                }
                                else
                                {
			        cloth->set("name",HIG "��������" NOR);
                                shoes->set("name",HIR "�廨��Ь" NOR);
                                }
                                break;

                        case "huashan":
                                if(user->query("gender") != "����")
				{
                                cloth->set("name",CYN "���೤ȹ" NOR);
				shoes->set("name",MAG "�廨СЬ" NOR);
                                }
				else
				{
                                cloth->set("name",WHT "����װ" NOR);
				shoes->set("name",CYN "������ѥ" NOR);
				}
                                break;

                        case "tangmen":
                                if(user->query("gender") != "����")
				{
                                cloth->set("name",MAG "��ɴ��ȹ" NOR);
                                shoes->set("name",RED "ѩ�粼ѥ" NOR);
				}
				else
				{
                                cloth->set("name",WHT "�ذ׽���" NOR);
                                shoes->set("name",GRN "�޶���Ь" NOR);
				}
				break;

                        case "jinghai":
				if(user->query("gender") != "����")
                                {
                                cloth->set("name",WHT "���۳���" NOR);
                                shoes->set("name",WHT "��Ƥ��ѥ" NOR);
                                }
				else
				{
                                cloth->set("name",YEL "�Ƹ����" NOR);
				shoes->set("name",WHT "���鲼ѥ" NOR);
                                }
				break;

                        case "shaolin":
				if ((int)user->query("family/generation",1) >=37)
				{
                                cloth->set("name",HIR "��������" NOR);
				shoes->set("name",HIC "ɮЬ" NOR);
				}
				else
				{
				cloth->set("name",CYN "�಼����" NOR);
                                shoes->set("name",HIC "ɮЬ" NOR);
                                }
                                break;
			default:
		}

/*
		switch (NATURE_D->query_season())
		{
			case (1):	// �� 
			case (3):	// �� 
				cloth->set("name",(user->query("gender") == "����")?
					"�а�":"��ȹ");
				break;
			case (2):	// �� 
				cloth->set("name",(user->query("gender") == "����")?
					"����":"��ȹ");
				break;
			case (4):	// �� 
				cloth->set("name",(user->query("gender") == "����")?
					"�ް�":"���ް�");
				break;
		}
*/
	}

	/* 14 �겻�ܵ䵱����겻�� restore ��Ʊ */
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
			NEWS_D->add_news_item( sprintf("����� %s(%s) ע���������������硣\n",
				user->query("name"),capitalize(user->query("id"))),"w", 1);
		}
#else
		else if(user->query("new_begin"))
		{
			startroom = WELCOME_ROOM;
			NEWS_D->add_news_item( sprintf("����� %s(%s) Ͷ������������硣\n",
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
		tell_room(startroom, user->name() + "���߽���������硣\n",
		filter_array( all_inventory(environment(user)), "filter_invisible", this_object(),user ) );
		user->load_all_my_ob();
        }

	if (user->query("force")>2*user->query("max_force")*2)
		user->set("force",2*user->query("max_force"));

	message("channel:sys",sprintf(HIR"�����߾��顿��%s(%s)�� %s ���߽��롣\n"NOR,
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
			write(HIY ">>>> ���ѳ��أ��޷�����������䡣<<<<\n" NOR );  // ��ֹ�����ж�.
			destruct(mailbox);
		}

		else
			write(sprintf(GRN"\n�ʲ����������ǰ��һ����˵������λӢ�����ˣ��������������䡣%s\n\
һգ�۵Ĺ���,�ʲ����ˡ�������\n"NOR,(n=mailbox->query_unread_count())?
		sprintf(HIY"\n>> ���� %d �����ʼ�û�п���<<"NOR GRN,n):"" ));
	}

	/*	marry ���ֱ��:
		marry/id : <ID>
		marry/name : ����������
		marry/date : �������  (������)
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
			write(HIY ">>>>>>>> ���ѳ���. <<<<<<<<\n" NOR );    // ��ֹ�����ж�.
			destruct(marrycard);
		}
                marrycard->init_emote();

		couple_ob = find_player(marry["id"]);

		if(couple_ob)
		{
			if((string)user->query("gender") != "����")
			{
				tmpstr1 = "���"; 
				tmpstr = "����";
                        }

			else
			{
                                tmpstr1 = "����";
                                tmpstr = "���";
                        }
			write(sprintf( BWHT HIM "\n���%s%s�Ѿ����������þ��ˣ�\n��ȥ��%s�ɡ�����\n"NOR,
				tmpstr1,couple_ob->name(),gender_pronoun(couple_ob->query("gender"))));
			tell_object(couple_ob ,sprintf( BWHT HIM "\n���%s%s���Ʋ�ס�����˼��������������\n��ȥ��%s����к��ɡ�����\n" NOR,
				tmpstr,user->name(),gender_pronoun(user->query("gender"))));
		}

		else if(!search_partner(marry["id"]))
		{
			tell_object(user,HIR"��İ����Ѿ���Զ���뿪��������硣\n"NOR);
			user->delete("marry");
			user->save();
			if(marrycard)
				destruct(marrycard);
		}
	}

	user->set_temp("newlogin",1);

	if(user->query("id") == "guest")
	{
		write("��ӭ��������ιۡ�\n");
		user->guest_count();
	}

	else if(user->query("new_begin"))
	{
#ifndef MAIL_REG
		user->delete("new_begin");
#endif
		write(HIG"\n>>>>> ��ӭ���һ������������磡:)\n\n"NOR);
	}

	else
		write("\n���ϴ������Ǵ�" + HIG +ob->query("last_from") + NOR + " ����ģ��˳�ʱ��Ϊ��"
			+ HIG +ctime(ob->query("last_out"))+ NOR + "\n\n");

        if(wizardp(user))
        {
		if(!user->query("change_passwd"))
			user->set("change_passwd",user->query("birthday"));
		if( (time()-(int)user->query("change_passwd")) >= 2592000 )
			write(HIY BOLD BLINK "\n����һ�θ�����������"
			+chinese_number( (int)((time()-(int)user->query("change_passwd"))/86400))+
			"����ǰ���뼰ʱ�������룡\n\n" NOR);
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
		write("�޷��������ߣ��볢�����µ�½��\n\n");
		if(objectp(user))
			destruct(user);
		if(objectp(ob))
			destruct(ob);
		return;
	}

        user->reconnect();
        if( !silent )
	{
		tell_room(environment(user), user->query("name") + "�������߻ص�������硣\n",
		filter_array( all_inventory(environment(user)), "filter_invisible", this_object(),user ) );
        }

	message("channel:sys",sprintf(HIR"�����߾��顿��%s(%s)��%s�������߽��롣\n"NOR,
		user->name(),user->query("id"),query_ip_number(user) ),
		filter_array(users(),(: wizardp :)));
        UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
        int *m = ({}), i = strlen(id);
        
	if( (strlen(id) < 3) || (strlen(id) > 10 ) )
	{
                write("\n�Բ������Ӣ�����ֱ����� 3 �� 10 ��Ӣ����ĸ��\n");
                return 0;
        }

	while(i--)
	{
		if( id[i]<'a' || id[i]>'z' )
		{
                        write("\n�Բ������Ӣ������ֻ����Ӣ��Сд��ĸ��\n");
                        return 0;
                }
		if(member_array(id[i],m) == -1)
			m += ({ id[i] });
	}

	if(sizeof(m) < 2)
	{
		write("--> ��� ID ����ƽ����������һ���и��Ե� ID ��\n");
		return 0;
	}

	if((strlen(id) > 3) && (strsrch(id, "fuke") != -1))
	{
		write("\n��� ID �ǽ�ֹʹ�õġ�\n");
		return 0;
	}

	if ( BAN_D->is_banned(id,1))
	{
		write(HIR"\n�Բ���\""+id+"\" ��� ID ��" + MUD_NAME + "���ǽ�ֹʹ�õġ�\n"NOR);
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
		write("\n�Բ�����Ϊ��ʦ����������� 10 ���ַ���\n");
		return 0;
	}

	id = ob->query("id");
	if( strsrch(id,lower_case(pass)) != -1
	|| strsrch(lower_case(pass),id) != -1
	|| strsrch(lower_case(pass),id[1..]) != -1
	|| strsrch(lower_case(pass),id[0..<2]) != -1)
	{
		write("\n�Բ�����������������ƴ����ࡣ\n");
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
		write("\n��Ϊ��ʦ���������������д��СдӢ����ĸ��������š�\n");
		return 0;
	}
	return 1;
}

int check_legal_name(string name)
{
        int i;

	if( strsrch(name,"��") != -1)
        {
		write("\n�Բ�������������ֲ����ÿո�\n");
                return 0;
        }

	if( strsrch(name,"��") != -1)
        {
		write(HIR"\n�Բ������������" + MUD_NAME + "���ǽ�ֹʹ�õġ�\n"NOR);
                return 0;
        }

	if( strsrch(name,"��") != -1)
        {
		write(HIR"\n�Բ������������" + MUD_NAME + "���ǽ�ֹʹ�õġ�\n"NOR);
                return 0;
        }

	if( strsrch(name,"��") != -1)
        {
		write(HIR"\n�Բ������������" + MUD_NAME + "���ǽ�ֹʹ�õġ�\n"NOR);
                return 0;
        }

	if( strsrch(name,"ʺ") != -1)
        {
		write(HIR"\n�Բ������������" + MUD_NAME + "���ǽ�ֹʹ�õġ�\n"NOR);
                return 0;
        }

        i = strlen(name);
        
	if( (strlen(name) < 2) || (strlen(name) > 12 ) )
	{
		write("\n�Բ�������������ֱ����� 1 �� 6 �������֡�\n");
		return 0;
        }

	while(i--)
	{
		int section;

                if( name[i]<128 )
		{
			write("\n�Բ��������á����ġ�ȡ���֡�\n");
                        return 0;
                }

		if( i%2==0 )
		{
			section = name[i] - 160;

			if( (section < 16)
			|| (section > 87) )
			{
				write("\n�Բ�������ʹ�ó��á����֡�ȡ���֡�\n");
				return 0;
			}
		}
	}

	if ( BAN_D->is_banned(name,3))
	{
		write(HIR"\n�Բ������������" + MUD_NAME + "���ǽ�ֹʹ�õġ�\n"NOR);
		return 0;
	}

	if(name[0..1] == "��")
	{
		write("'��'������Ϻ���Ϸ�����г�ͻ�������⻻һ�����ϡ�\n");
		return 0;
	}

        if(name[0..3] == "̤ѩ")
        {
                write("'̤ѩ'������Ϻ���Ϸ�����г�ͻ�������⻻һ�����ϡ�\n");
                return 0;
        }

	if(permit_add_cname(name))
	{
		write("\n*** �Բ�����������Ѿ�����ʹ���ˣ�����һ���ɡ�***\n"NOR);
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

	message("channel:sys",sprintf(HIR"�����߾��顿��%s(%s)�����ˡ�\n"NOR,
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
