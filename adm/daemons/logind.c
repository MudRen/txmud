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
protected int MAX_ATTR_SUM = 120;	// Ìì¸³×ÜºÍ

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
		write(sprintf("%sÕıÔÚÆô¶¯¹ı³ÌÖĞ£¬ÇëÉÔºòÔÙÀ´¡£\n",MUD_NAME));
		destruct(ob);
		return;
	}

	if(no_login)
	{
		write(sprintf("%sÒÑ½øÈëÖØĞÂÆô¶¯´¦Àí½ø³Ì£¬ÇëÉÔºòÔÙÀ´¡£\n",MUD_NAME));
		destruct(ob);
		return;
	}

#ifdef GB_AND_BIG5
	printf(read_file(TITLE));

	write("           ¡¶ÌìÏÂ¡·»¶Ó­ÄúÀ´·Ã£¡Ê¹ÓÃ¹ú±êÂëµÄÍæ¼ÒÇë¼üÈë£ºgb\n");
	write("           ¡§©t¿WµL¦W¡¨Åwªï±z¨Ó³X¡I¨Ï¥Î¤j¤­½Xªºª±®a½ĞÁä¤J¡Gbig5\n\n");
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
	    write("\nSelect ¹ú±êÂë GB or ¤j¤­½X BIG5 (gb/big5):");
	    input_to( (: encoding :), ob );
	    return;
	}
	else if(arg[0]=='g' || arg[0]=='G')
	    encode=0;
	else if(arg[0]=='b' || arg[0]=='B')
	    encode=1;
	else
	{
	    write("\nSelect ¹ú±êÂë GB or ¤j¤­½X BIG5 (gb/big5):");
	    input_to( (: encoding :), ob );
	    return;
	}
	
	ob->set_encoding(encode);

	printf(REF);
	printf(read_file(WELCOME));
	//write("°´ÈÎÒâ¼ü¼ÌĞø......");
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
		write(HIR"¶Ô²»Æğ£¬ÄãµÄIPµØÖ·ÔÚ" + MUD_NAME + "²»ÊÜ»¶Ó­¡£\n");
		destruct(ob);
		return;
        }

	printf(WHT"[±¾µØÊ±¼ä]£º"+cctime(time())+"\n");
	printf("[ÔËĞĞÊ±¼ä]£º");
	UPTIME_CMD->main();
	printf(sprintf("[ÓÎÏ·ÈËÊı]£º%sÊÀ½çÄ¿Ç°¹²ÓĞ %s Î»¾ÓÃñ¡£\n",MUD_NAME, chinese_number(count_reg_user())));
	printf("[Á÷Á¿Í³¼Æ]£º");
	"/cmds/imm/bps"->main();
/*
	printf(sprintf("[Îï¼şÍ³¼Æ]£ºÓÎÏ·µ±Ç°¹²ÔØÈëÎï¼ş %d ¸ö£¬Ê¹ÓÃ¼ÇÒäÌå×ÜÁ¿ %s¡£\n\n" NOR,
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
		write("¶Ô²»Æğ£¬ÄãµÄIPµÇÂ¼´ÎÊıÌ«¶àÁË\n");
		destruct(ob);
		return;
	}
*/

	count = all_online_players();
	if(!count)
		printf(NOR "\nÄ¿Ç°"); // info not available
	else
		printf(NOR HIG"\nÄ¿Ç°¹²ÓĞ%dÎ»Íæ¼ÒÔÚÏßÉÏ¡£"NOR+"\n±¾Õ¾", count+wiz_cnt+ppl_cnt );

        printf("¹²ÓĞ %s%d Î»Íæ¼ÒÔÚÏßÉÏ£¬ÒÔ¼° %d Î»Ê¹ÓÃÕß³¢ÊÔÁ¬ÏßÖĞ¡£\n\n",
                wiz_cnt?sprintf("%d Î»¹ÜÀíÔ±¡¢",wiz_cnt):"", ppl_cnt, login_cnt );

        write("ÄúµÄÓ¢ÎÄÃû×Ö£º");
        input_to( (: get_id :), ob );
}

protected void get_id(string arg, object ob)
{
        object ppl,user;
	string where;

        arg = lower_case(arg);
        if( !check_legal_id(arg))
	{
		write("ÄúµÄÓ¢ÎÄÃû×Ö£º");
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
                        write("¶Ô²»Æğ£¬" + MUD_NAME + "µÄÊ¹ÓÃÕßÒÑ¾­Ì«¶àÁË£¬Çë´ı»áÔÙÀ´¡£\n");
                        destruct(ob);
                        return;
                }
        }

        if( wiz_level(arg) < wiz_lock_level )
	{
		write("¶Ô²»Æğ£¬" + MUD_NAME + "Ä¿Ç°ÏŞÖÆÎ×Ê¦µÈ¼¶ " +   wiz_level_name(wiz_lock_level)
			+ " ÒÔÉÏµÄÈË²ÅÄÜÁ¬Ïß¡£\n");
		destruct(ob);
		return;
	}

	if(AHACK_D->query_block(arg))
	{
		write(HIY"Õâ¸öÕËºÅ±»ÔİÊ±·âËøÁË£¬ÇëÓÃ guest ÈËÎïµÇÈëÓëÔÚÏßÎ×Ê¦ÁªÏµ¡£\n"NOR);
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
			write("Ä¿Ç° guest ÕËºÅÒÑÓĞÈËÔÚÊ¹ÓÃ£¬ÇëµÈÒ»ÏÂÔÙµÇÂ½¡£\n");
			destruct(ob);
			return;
		}

		ob->set("body", USER_OB);
		if( !objectp(user = make_body(ob)) )
		{
			destruct(ob);
			return;
		}
		user->set("name","ÁÙÊ±ÈËÎï");
		user->set("gender","ÄĞĞÔ");
		user->set("title", "ÆÕÍ¨°ÙĞÕ");
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
			if(!ob->query("password")) // µµ°¸²»ÍêÕû.
			{
				rm(login_file(arg));
				if(file_size(user_file(arg)) >= 0)
					rename(user_file(arg),BACKUP_DIR+arg+".o");
				write("ÄúµÄµµ°¸²»ÍêÕû£¬ÇëÖØĞÂ´´½¨Õâ¸öÈËÎï¡£\n");
				confirm_id("y", ob);
				return;
			}
                        write("Õâ¸öÃû×ÖÒÑ¾­×¢²á£¬ÇëÊäÈë×¢²áÃÜÂë£º");
                        input_to( (: get_passwd :), 1, ob);
                        return;
                }
                write("ÄúµÄÈËÎï´¢´æµ²³öÁËÒ»Ğ©ÎÊÌâ£¬ÇëÀûÓÃ guest ÈËÎïÍ¨ÖªÎ×Ê¦´¦Àí¡£\n");
                destruct(ob);
                return;
        }

#ifdef REFUSE_NEW_PLAYER
        write("¶Ô²»Æğ£¬ÓÉÓÚ·¢ËÍÓÊ¼ş·şÎñÆ÷³öÏÖÎÊÌâ£¬\nÄ¿Ç°"+MUD_NAME+"ÔİÊ±²»½ÓÊÜĞÂÍæ¼ÒµÇ¼Ç¡£\nÇë·ÃÎÊÓÎÏ·Ö÷Ò³£ºhttp://www.mudtx.com »ñµÃÏêÏ¸µÄÑ¶Ï¢¡£\n");
	destruct(ob);
	return;
#endif

	where = query_register_station(arg);
	if(stringp(where) && (where != ""))
	{
		write(sprintf("[%s] Õâ¸ö ID ÒÑ¾­ÔÚ%s×¢²áÁË\nÇëÈ¥ÄÇÀïµÇÂ½½øÈëÓÎÏ·¡£\n",
			arg,!undefinedp(stations[where])?stations[where]:"±ğµÄµØ·½"));
		destruct(ob);
		return;
	}

        write("Ê¹ÓÃ " + (string)ob->query("id") + " Õâ¸öÃû×Ö½«»á´´ÔìÒ»¸öĞÂµÄÈËÎï£¬ÄúÈ·¶¨Âğ(y/n)£¿");
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
		sys_log("same_ip",sprintf("µÇÂ½%s(%s)ÓëÔÚÏß%s %s µÄIPµØÖ·ÏàÍ¬£¬%s\n",
			(flag)?"Î×Ê¦":"Íæ¼Ò",geteuid(user),(flag)?"ÈËÎï":"Î×Ê¦",
			implode(ids,"¡¢"),ctime(time())));
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
		write("\nÃÜÂë´íÎó£¡\n");
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
		write("ÇëÖØĞÂÉè¶¨ÄúµÄÃÜÂë£º");
		input_to( (: new_password :), 1, ob, 1);
		return;
	}
#endif

	if(!ob)	return;
        // Check if we are already playing.
        user = find_body(ob->query("id"));

	if(user && !environment(user)) /* ÕâÖÖ×´Ì¬ÊÇ²»Ó¦³öÏÖµÄ */
		destruct(user);

        if(user)
	{
		if( user->query_temp("netdead") )
		{
                        reconnect(ob, user);
                        return;
                }

		write("ÄúÒª½«ÁíÒ»¸öÁ¬ÏßÖĞµÄÏàÍ¬ÈËÎï¸Ï³öÈ¥£¬È¡¶ø´úÖ®Âğ£¿(y/n)");
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
        write("ÇëÄúÖØĞÂ´´ÔìÕâ¸öÈËÎï¡£\n");
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
		write("ÄúÒª½«ÁíÒ»¸öÁ¬ÏßÖĞµÄÏàÍ¬ÈËÎï¸Ï³öÈ¥£¬È¡¶ø´úÖ®Âğ£¿(y/n)\n");
		input_to( (: confirm_relogin :), ob, user);
		return;
        }

        if( yn[0]!='y' && yn[0]!='Y' )
	{
		write("ºÃ°É£¬»¶Ó­ÏÂ´ÎÔÙÀ´¡£\n");
		destruct(ob);
		return;
        }

	else
	{
		tell_object(user, "ÓĞÈË´Ó±ğ´¦( " + query_ip_number(ob) + " )Á¬ÏßÈ¡´úÄãËù¿ØÖÆµÄÈËÎï¡£\n");
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
                write("\nÊ¹ÓÃÕâ¸öÃû×Ö½«»á´´ÔìÒ»¸öĞÂµÄÈËÎï£¬ÄúÈ·¶¨Âğ(y/n)£¿");
                input_to( (: confirm_id :), ob);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("\nºÃ°É£¬ÄÇÃ´ÇëÖØĞÂÊäÈëÄúµÄÓ¢ÎÄÃû×Ö£º");
                input_to( (: get_id :), ob);
                return;
        }

        write( @TEXT

ÇëÄúÏëÒ»¸öÓĞÆøÖÊ£¬ÓĞ¸öĞÔ£¬ÓÖ²»»áÌ«Ææ¹ÖµÄÖĞÎÄÃû×Ö£¬ÌØ±ğÒªÌáĞÑÄú
µÄÊÇ£¬±¾ mud ÊÇÒ»¸öÒÔ¹ÅÖĞ¹úÓë¶«·½Îª±³¾°µÄÊÀ½ç £¬Çë²»ÒªÈ¡Ò»Ğ©²»
ÑÅ»òÊÇÈİÒ×Ôì³ÉËûÈËÀ§ÈÅµÄÃû×Ö£¬Õâ¸öÃû×Ö½«´ú±íÄãµÄÈËÎï£¬¶øÇÒÍùºó
½«ºÜÄÑÔÙ¸ü¸Ä£¬ÇëÎñ±ØÉ÷ÖØ¡£
  ^^^^^^^^^^
[1;33m(³ıÁËÃû×ÖÖ®Íâ£¬±¾ mud ÓĞĞí¶àÈ¡´ÂºÅ¡¢±ğ³ÆµÄÉè¼Æ£¬ËùÒÔÖ£ÖØ½¨ÒéÄú
 È¡Ò»¸ö±È½ÏÏñÃû×ÖµÄÖĞÎÄÃû×Ö¡£Èç¹ûÄúµÄÃû×Ö±»ÈÏÎª¶Ô±¾ÓÎÏ·ºÍÓÎÏ·ÄÚ
 µÄÆäËüÍæ¼ÒÔì³É²»ºÃµÄÓ°Ïì£¬½«»á±»Ç¿ÖÆ¸Ä±ä»òÉ¾³ıµµ°¸¡£)
[2;37;0m
TEXT
        );
        write("ÄúµÄÖĞÎÄÃû×Ö£º");
        input_to( (: get_name :), ob);
}

protected void get_name(string arg, object ob)
{
	if(!ob)
		return;

        if( !check_legal_name(arg) )
	{
		write("ÄúµÄÖĞÎÄÃû×Ö£º");
		input_to( (: get_name :), ob);
		return;
        }

        //printf("%O\n", ob);
        ob->set("name", arg);
        write("ÇëÉè¶¨ÄúµÄÃÜÂë£º");
        input_to( (: new_password :), 1, ob);
}

protected void new_password(string pass, object ob,int flag)
{
        write("\n");
        if( strlen(pass)<5 )
	{
                write("\nÃÜÂëµÄ³¤¶ÈÖÁÉÙÒªÎå¸ö×ÖÔª£¬ÇëÖØÉèÄúµÄÃÜÂë£º");
                input_to( (: new_password :), 1, ob);
                return;
        }

	if(flag && !check_wiz_legal_password(ob,pass))
	{
		write("ÇëÖØĞÂÉè¶¨ÄúµÄÃÜÂë£º");
		input_to( (: new_password :), 1, ob, 1);
		return;
	}

        ob->set("password", crypt(pass,0) );
        write("ÇëÔÙÊäÈëÒ»´ÎÄúµÄÃÜÂë£¬ÒÔÈ·ÈÏÄúÃ»¼Ç´í£º");
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
                write("ÄúÁ½´ÎÊäÈëµÄÃÜÂë²¢²»Ò»Ñù£¬ÇëÖØĞÂÉè¶¨Ò»´ÎÃÜÂë£º");
                input_to( (: new_password :), 1, ob, flag);
                return;
        }

	if(flag)
	{
		write("ÇëÊäÈëÃÜÂë£º");
		input_to( (: get_passwd :), 1, ob);
		return;
	}

        ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) )
	{
		destruct(ob);
                return;
	}

	write("ÄúÒª°çÑİÄĞĞÔ(m)µÄ½ÇÉ«»òÅ®ĞÔ(f)µÄ½ÇÉ«£¿");
	input_to( (: get_gender :), ob, user);
/*
	write("ÄúµÄµç×ÓÓÊ¼şµØÖ·£º");
#ifdef MAIL_REG
	if(ob->query("id") != "guest")
	write(HIY"(×¢²á¹ı³Ì½«ÒªÊ¹ÓÃÄúµÄÓÊ¼şµØÖ·,ÇëÎñ±ØÈÏÕæÌîĞ´)"NOR);
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

        write("ÄúÒª°çÑİÄĞĞÔ(m)µÄ½ÇÉ«»òÅ®ĞÔ(f)µÄ½ÇÉ«£¿");
        input_to( (: get_gender :), ob, user);
}
*/
protected void get_gender(string gender, object ob, object user)
{
        if( gender=="" )
	{
		write("ÄúÒª°çÑİÄĞĞÔ(m)µÄ½ÇÉ«»òÅ®ĞÔ(f)µÄ½ÇÉ«£¿");
		input_to( (: get_gender :), ob, user);
		return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "ÄĞĞÔ");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "Å®ĞÔ" );
        else
	{
                write("¶Ô²»Æğ£¬ÄúÖ»ÄÜÑ¡ÔñÄĞĞÔ(m)»òÅ®ĞÔ(f)µÄ½ÇÉ«£º");
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
		write("ÏÖÔÚ¿ÉÄÜÓĞÈËÕıÔÚĞŞ¸ÄÊ¹ÓÃÕßÎï¼şµÄ³ÌÊ½£¬ÎŞ·¨½øĞĞ¸´ÖÆ¡£\n");
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

        printf("\n%sÄãµ±Ç°µÄÌì¸³Îª£º%s\n %sëöÁ¦(str)£º[%d]  µ¨Ê¶(cor)£º[%d]  ÎòĞÔ(int)£º[%d]%s\n"
               " %sÈİÃ²(per)£º[%d]  ¸ù¹Ç(con)£º[%d]  ¸£Ôµ(kar)£º[%d]\n\n"NOR,
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
	printf("¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô
 ÓÎÏ·³õÊ¼Ìá¹©¸øÍæ¼ÒÒ»²¿·ÖÌì¸³µãÊı£¬Äã¿ÉÒÔ¸ù¾İÏ²ºÃ
 ×ÔÓÉ·ÖÅä£¬Ã¿ÏîÌì¸³µÄ×îĞ¡ÊıÖµÎª 15£¬×î´óÊıÖµÎª 30¡£
¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô

     ·ÖÅä·½·¨Îª£º  Ìì¸³ [+|-]ÊıÖµ

ÀıÈç£ºÄãÏ£Íû¸ø±ÛÁ¦·ÖÅä 5 µã£¬¿ÉÒÔÊäÈë£ºstr +5
      ÄãÏ£Íû¼õÉÙÎòĞÔ 4 µã£¬¿ÉÒÔÊäÈë£º con -4

  %s¡ô¡ô Èç¹ûÏ£ÍûÓÉÓÎÏ·°ïÖúÄãËæ»ú·ÖÅäÇëÊäÈë 0 ¡ô¡ô
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

	user->set("title", "ÆÕÍ¨°ÙĞÕ");
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
		printf("ÄãÊÇ·ñ¾ö¶¨Ñ¡ÓÃÕâÒ»×éÌì¸³£¿[y/n]£º");
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
	|| (Tstr > 30) || (Tstr < 15)	// ²é´í
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
		printf("ÄãÄ¿Ç°ÓĞ 30 µãÌì¸³µãÊı¿ÉÓÃÓÚ·ÖÅä£¬ÇëÉè¶¨£º");
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if(left == 0) // Íê³É
	{
		set_new_player(ob, user);
		return;
	}

	if(!yn || (yn == "") || sscanf(yn,"%s %s%d",which, plus, Tchange) != 3)
	{
		display_tianfu(user);
		display_select_guide();
		printf("ÄãÄ¿Ç°ÓĞ %d µãÌì¸³µãÊı¿ÉÓÃÓÚ·ÖÅä£¬ÇëÉè¶¨£º",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	which = replace_string(which," ","");
	if(member_array(which,all_tianfu) == -1)
	{
		printf(HIG"\n[Çë´ÓÁùÖÖÌì¸³ÖĞÑ¡ÔñÄãÒªÉè¶¨µÄÌì¸³]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("ÄãÄ¿Ç°ÓĞ %d µãÌì¸³µãÊı¿ÉÓÃÓÚ·ÖÅä£¬ÇëÉè¶¨£º",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if(!Tchange)
	{
		printf(HIG"\n[ÇëÓÃ°¢À­²®Êı×Ö±íÃ÷ÄãÒªĞŞ¸ÄµÄÊıÖµÁ¿]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("ÄãÄ¿Ç°ÓĞ %d µãÌì¸³µãÊı¿ÉÓÃÓÚ·ÖÅä£¬ÇëÉè¶¨£º",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	plus = replace_string(plus," ","");
	if(plus == "")
		plus = "+";
	if( (plus != "+") && (plus != "-") )
	{
		printf(HIG"\n[ÇëÑ¡ÓÃÕıÈ·µÄÔö(+)¡¢¼õ(-)·ûºÅ]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("ÄãÄ¿Ç°ÓĞ %d µãÌì¸³µãÊı¿ÉÓÃÓÚ·ÖÅä£¬ÇëÉè¶¨£º",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if( (plus == "+") && (Tchange > left) )
	{
		printf(HIG"\n[ÄãÄ¿Ç°Ö»Ê£ÏÂ %d ¸ö¿É·ÖÅäµÄÌì¸³µãÊı]\n"NOR,left);
		display_tianfu(user);
		display_select_guide();
		printf("ÄãÄ¿Ç°ÓĞ %d µãÌì¸³µãÊı¿ÉÓÃÓÚ·ÖÅä£¬ÇëÉè¶¨£º",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if( (plus == "+") && (user->query(which) + Tchange > 30) )
	{
		printf(HIG"\n[Ã¿ÏîÌì¸³µÄ×î´óÊıÖµÊÇ 30 µã]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("ÄãÄ¿Ç°ÓĞ %d µãÌì¸³µãÊı¿ÉÓÃÓÚ·ÖÅä£¬ÇëÉè¶¨£º",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	if( (plus == "-") && (user->query(which) - Tchange < 15) )
	{
		printf(HIG"\n[Ã¿ÏîÌì¸³µÄ×îĞ¡ÊıÖµÊÇ 15 µã]\n"NOR);
		display_tianfu(user);
		display_select_guide();
		printf("ÄãÄ¿Ç°ÓĞ %d µãÌì¸³µãÊı¿ÉÓÃÓÚ·ÖÅä£¬ÇëÉè¶¨£º",left);
		input_to( (: init_new_player :),ob,user);
		return;
	}

	printf(BWHT HIG"\n [%s%s %d µã] \n"NOR,capitalize(which),plus=="+"?"Ôö¼Ó":"¼õÉÙ",Tchange);
	user->add(which,(plus=="+"?Tchange:-Tchange));

	display_tianfu(user);
	if(plus == "+")
		left -= Tchange;
	else
		left += Tchange;

	if(!left)
		printf("ÄãÊÇ·ñ¾ö¶¨Ñ¡ÓÃÕâÒ»×éÌì¸³£¿[y/n]£º");

	else
	{
		display_select_guide();
		printf("ÄãÄ¿Ç°ÓĞ %s µãÌì¸³µãÊı¿ÉÓÃÓÚ·ÖÅä£¬ÇëÉè¶¨£º",sprintf(HIC"%d"NOR,left));
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
        write("Ä¿Ç°È¨ÏŞ£º" + wizhood(user) + "\n");
        user->setup();
        user->save();
        ob->save();

	//check_same_ip_number(user);

        cloth = new(ARMOR_DIR"cloth");
        shoes = new(ARMOR_DIR"boot");

	if(!cloth->move(user) || !shoes->move(user))
	{
		write(HIY ">>>>>>>> ÄãÒÑ³¬ÖØ. <<<<<<<<\n" NOR );  // ·ÀÖ¹³¬ÖØÅĞ¶Ï.
		destruct(cloth);
                destruct(shoes);
	}

	else
	{
		cloth->wear();
		shoes->wear();

		if(wizardp(user))
		{
		cloth->set("name",HIY "Î×Ê¦ËÄ¼¾ÅÛ" NOR);
		shoes->set("name",HIY "ÎŞµĞ·ç»ğÂÖ" NOR);
		}

		else if(stringp(self_cloth = user->query("self_cloth"))
		&& self_cloth != "")
			cloth->set("name",self_cloth);
		else

		switch (user->query("class"))
		{
			case "taxue":
				if(user->query("gender") != "ÄĞĞÔ") 
				{
				cloth->set("name",WHT "ËØ°×ÓğÒÂ" NOR);
				shoes->set("name",WHT "ÊŞÆ¤³¤Ñ¥" NOR);
				}
				else
				{
				cloth->set("name",WHT "õõÆ¤³¤ÅÛ" NOR); 
				shoes->set("name",WHT "ÊŞÆ¤³¤Ñ¥" NOR);
				}
				break;

                        case "gaibang":
                                if(user->query("gender") != "ÄĞĞÔ")
                                {
                                cloth->set("name",YEL "°ÙñÄ½áÒÂ" NOR);
				shoes->set("name",GRN "ÆÆ¾É²İĞ¬" NOR);
                                }
                                else
                                {
				cloth->set("name",YEL "°ÙñÄ½áÒÂ" NOR);
                                shoes->set("name",GRN "ÆÆ¾É²İĞ¬" NOR);
                                }
                                break;

                        case "rain":
                                if(user->query("gender") != "ÄĞĞÔ")
                                {
				cloth->set("name",HIG "´äÂÌÒÂÉÀ" NOR);
                                shoes->set("name",HIR "Ğå»¨ºìĞ¬" NOR);
                                }
                                else
                                {
			        cloth->set("name",HIG "´äÂÌÒÂÉÀ" NOR);
                                shoes->set("name",HIR "Ğå»¨ºìĞ¬" NOR);
                                }
                                break;

                        case "huashan":
                                if(user->query("gender") != "ÄĞĞÔ")
				{
                                cloth->set("name",CYN "ËØÇà³¤È¹" NOR);
				shoes->set("name",MAG "Ğå»¨Ğ¡Ğ¬" NOR);
                                }
				else
				{
                                cloth->set("name",WHT "½ôÉí¾¢×°" NOR);
				shoes->set("name",CYN "¼±¾¢²¼Ñ¥" NOR);
				}
                                break;

                        case "tangmen":
                                if(user->query("gender") != "ÄĞĞÔ")
				{
                                cloth->set("name",MAG "ÇáÉ´³¤È¹" NOR);
                                shoes->set("name",RED "Ñ©ºç²¼Ñ¥" NOR);
				}
				else
				{
                                cloth->set("name",WHT "ËØ°×½õÒÂ" NOR);
                                shoes->set("name",GRN "ÎŞ¶úÂéĞ¬" NOR);
				}
				break;

                        case "jinghai":
				if(user->query("gender") != "ÄĞĞÔ")
                                {
                                cloth->set("name",WHT "ÓãÁÛ³ñÉÀ" NOR);
                                shoes->set("name",WHT "ÓãÆ¤³¤Ñ¥" NOR);
                                }
				else
				{
                                cloth->set("name",YEL "»Æ¸ğ¶ÌÉÀ" NOR);
				shoes->set("name",WHT "´ÖÂé²¼Ñ¥" NOR);
                                }
				break;

                        case "shaolin":
				if ((int)user->query("family/generation",1) >=37)
				{
                                cloth->set("name",HIR "»¤·¨ôÂôÄ" NOR);
				shoes->set("name",HIC "É®Ğ¬" NOR);
				}
				else
				{
				cloth->set("name",CYN "Çà²¼ôÂôÄ" NOR);
                                shoes->set("name",HIC "É®Ğ¬" NOR);
                                }
                                break;
			default:
		}

/*
		switch (NATURE_D->query_season())
		{
			case (1):	// ´º 
			case (3):	// Çï 
				cloth->set("name",(user->query("gender") == "ÄĞĞÔ")?
					"¼Ğ°À":"ÃŞÈ¹");
				break;
			case (2):	// ÏÄ 
				cloth->set("name",(user->query("gender") == "ÄĞĞÔ")?
					"²¼¹Ó":"²¼È¹");
				break;
			case (4):	// ¶¬ 
				cloth->set("name",(user->query("gender") == "ÄĞĞÔ")?
					"ÃŞ°À":"»¨ÃŞ°À");
				break;
		}
*/
	}

	/* 14 Ëê²»ÄÜµäµ±£¬¹í»ê²»ÄÜ restore µ±Æ± */
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
			NEWS_D->add_news_item( sprintf("ĞÂÍæ¼Ò %s(%s) ×¢²á½øÈëÕâ¸ö·è¿ñµÄÊÀ½ç¡£\n",
				user->query("name"),capitalize(user->query("id"))),"w", 1);
		}
#else
		else if(user->query("new_begin"))
		{
			startroom = WELCOME_ROOM;
			NEWS_D->add_news_item( sprintf("ĞÂÍæ¼Ò %s(%s) Í¶ÈëÕâ¸ö·è¿ñµÄÊÀ½ç¡£\n",
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
		tell_room(startroom, user->name() + "Á¬Ïß½øÈëÕâ¸öÊÀ½ç¡£\n",
		filter_array( all_inventory(environment(user)), "filter_invisible", this_object(),user ) );
		user->load_all_my_ob();
        }

	if (user->query("force")>2*user->query("max_force")*2)
		user->set("force",2*user->query("max_force"));

	message("channel:sys",sprintf(HIR"¡¾Á¬Ïß¾«Áé¡¿£º%s(%s)ÓÉ %s Á¬Ïß½øÈë¡£\n"NOR,
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
			write(HIY ">>>> ÄãÒÑ³¬ÖØ£¬ÎŞ·¨ÔØÈëÄãµÄÓÊÏä¡£<<<<\n" NOR );  // ·ÀÖ¹³¬ÖØÅĞ¶Ï.
			destruct(mailbox);
		}

		else
			write(sprintf(GRN"\nÓÊ²îÀ´µ½ÄãµÄÃæÇ°£¬Ò»¹°ÊÖËµµÀ£ºÕâÎ»Ó¢ĞÛÇëÁË£¬ÕâÀïÊÇÄúµÄĞÅÏä¡£%s\n\
Ò»Õ£ÑÛµÄ¹¦·ò,ÓÊ²î×ßÁË¡£¡£¡£¡£\n"NOR,(n=mailbox->query_unread_count())?
		sprintf(HIY"\n>> ÄúÓĞ %d ·âĞÂÓÊ¼şÃ»ÓĞ¿´¡£<<"NOR GRN,n):"" ));
	}

	/*	marry ²¿·Ö±ê¼Ç:
		marry/id : <ID>
		marry/name : °éÂÂÖĞÎÄÃû
		marry/date : ½á»éÈÕÆÚ  (ÄêÔÂÈÕ)
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
			write(HIY ">>>>>>>> ÄãÒÑ³¬ÖØ. <<<<<<<<\n" NOR );    // ·ÀÖ¹³¬ÖØÅĞ¶Ï.
			destruct(marrycard);
		}
                marrycard->init_emote();

		couple_ob = find_player(marry["id"]);

		if(couple_ob)
		{
			if((string)user->query("gender") != "ÄĞĞÔ")
			{
				tmpstr1 = "·ò¾ı"; 
				tmpstr = "°®ÆŞ";
                        }

			else
			{
                                tmpstr1 = "°®ÆŞ";
                                tmpstr = "·ò¾ı";
                        }
			write(sprintf( BWHT HIM "\nÄãµÄ%s%sÒÑ¾­ÔÚÕâµÈÁËÄãºÃ¾ÃÁË£¬\n¿ìÈ¥ÕÒ%s°É¡£¡£¡£\n"NOR,
				tmpstr1,couple_ob->name(),gender_pronoun(couple_ob->query("gender"))));
			tell_object(couple_ob ,sprintf( BWHT HIM "\nÄãµÄ%s%sÒÖÖÆ²»×¡¶ÔÄãµÄË¼ÄîÅÜÀ´¿´ÄãÀ²£¬\n¿ìÈ¥ºÍ%s´ò¸öÕĞºô°É¡£¡£¡£\n" NOR,
				tmpstr,user->name(),gender_pronoun(user->query("gender"))));
		}

		else if(!search_partner(marry["id"]))
		{
			tell_object(user,HIR"ÄãµÄ°éÂÂÒÑ¾­ÓÀÔ¶µÄÀë¿ªÁËÕâ¸öÊÀ½ç¡£\n"NOR);
			user->delete("marry");
			user->save();
			if(marrycard)
				destruct(marrycard);
		}
	}

	user->set_temp("newlogin",1);

	if(user->query("id") == "guest")
	{
		write("»¶Ó­À´µ½ÕâÀï²Î¹Û¡£\n");
		user->guest_count();
	}

	else if(user->query("new_begin"))
	{
#ifndef MAIL_REG
		user->delete("new_begin");
#endif
		write(HIG"\n>>>>> »¶Ó­ÄãµÚÒ»´ÎÀ´µ½Õâ¸öÊÀ½ç£¡:)\n\n"NOR);
	}

	else
		write("\nÄãÉÏ´ÎÁ¬ÏßÊÇ´Ó" + HIG +ob->query("last_from") + NOR + " ½øÈëµÄ£¬ÍË³öÊ±¼äÎª£º"
			+ HIG +ctime(ob->query("last_out"))+ NOR + "\n\n");

        if(wizardp(user))
        {
		if(!user->query("change_passwd"))
			user->set("change_passwd",user->query("birthday"));
		if( (time()-(int)user->query("change_passwd")) >= 2592000 )
			write(HIY BOLD BLINK "\nÄúÉÏÒ»´Î¸ü»»ÃÜÂëÊÇÔÚ"
			+chinese_number( (int)((time()-(int)user->query("change_passwd"))/86400))+
			"ÌìÒÔÇ°£¬Çë¼°Ê±¸ü»»ÃÜÂë£¡\n\n" NOR);
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
		write("ÎŞ·¨ÖØĞÂÁ¬Ïß£¬Çë³¢ÊÔÖØĞÂµÇÂ½¡£\n\n");
		if(objectp(user))
			destruct(user);
		if(objectp(ob))
			destruct(ob);
		return;
	}

        user->reconnect();
        if( !silent )
	{
		tell_room(environment(user), user->query("name") + "ÖØĞÂÁ¬Ïß»Øµ½Õâ¸öÊÀ½ç¡£\n",
		filter_array( all_inventory(environment(user)), "filter_invisible", this_object(),user ) );
        }

	message("channel:sys",sprintf(HIR"¡¾Á¬Ïß¾«Áé¡¿£º%s(%s)ÓÉ%sÖØĞÂÁ¬Ïß½øÈë¡£\n"NOR,
		user->name(),user->query("id"),query_ip_number(user) ),
		filter_array(users(),(: wizardp :)));
        UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
        int *m = ({}), i = strlen(id);
        
	if( (strlen(id) < 3) || (strlen(id) > 10 ) )
	{
                write("\n¶Ô²»Æğ£¬ÄãµÄÓ¢ÎÄÃû×Ö±ØĞëÊÇ 3 µ½ 10 ¸öÓ¢ÎÄ×ÖÄ¸¡£\n");
                return 0;
        }

	while(i--)
	{
		if( id[i]<'a' || id[i]>'z' )
		{
                        write("\n¶Ô²»Æğ£¬ÄãµÄÓ¢ÎÄÃû×ÖÖ»ÄÜÓÃÓ¢ÎÄĞ¡Ğ´×ÖÄ¸¡£\n");
                        return 0;
                }
		if(member_array(id[i],m) == -1)
			m += ({ id[i] });
	}

	if(sizeof(m) < 2)
	{
		write("--> Õâ¸ö ID ¹ıÓÚÆ½µ­£¬ÇëÔÙÏëÒ»¸öÓĞ¸öĞÔµÄ ID ¡£\n");
		return 0;
	}

	if((strlen(id) > 3) && (strsrch(id, "fuke") != -1))
	{
		write("\nÕâ¸ö ID ÊÇ½ûÖ¹Ê¹ÓÃµÄ¡£\n");
		return 0;
	}

	if ( BAN_D->is_banned(id,1))
	{
		write(HIR"\n¶Ô²»Æğ£¬\""+id+"\" Õâ¸ö ID ÔÚ" + MUD_NAME + "ÀïÊÇ½ûÖ¹Ê¹ÓÃµÄ¡£\n"NOR);
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
		write("\n¶Ô²»Æğ£¬×÷ÎªÎ×Ê¦ÄãµÄÃÜÂëÖÁÉÙ 10 ¸ö×Ö·û¡£\n");
		return 0;
	}

	id = ob->query("id");
	if( strsrch(id,lower_case(pass)) != -1
	|| strsrch(lower_case(pass),id) != -1
	|| strsrch(lower_case(pass),id[1..]) != -1
	|| strsrch(lower_case(pass),id[0..<2]) != -1)
	{
		write("\n¶Ô²»Æğ£¬ÄãµÄÃÜÂëºÍÄãµÄÏàËÆ´¦¹ı¶à¡£\n");
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
		write("\n×÷ÎªÎ×Ê¦ÄãµÄÃÜÂë±ØĞë°üº¬´óĞ´¡¢Ğ¡Ğ´Ó¢ÎÄ×ÖÄ¸ºÍÌØÊâ·ûºÅ¡£\n");
		return 0;
	}
	return 1;
}

int check_legal_name(string name)
{
        int i;

	if( strsrch(name,"¡¡") != -1)
        {
		write("\n¶Ô²»Æğ£¬ÄãµÄÖĞÎÄÃû×Ö²»ÄÜÓÃ¿Õ¸ñ¡£\n");
                return 0;
        }

	if( strsrch(name,"°Ö") != -1)
        {
		write(HIR"\n¶Ô²»Æğ£¬Õâ¸öÃû×ÖÔÚ" + MUD_NAME + "ÀïÊÇ½ûÖ¹Ê¹ÓÃµÄ¡£\n"NOR);
                return 0;
        }

	if( strsrch(name,"µù") != -1)
        {
		write(HIR"\n¶Ô²»Æğ£¬Õâ¸öÃû×ÖÔÚ" + MUD_NAME + "ÀïÊÇ½ûÖ¹Ê¹ÓÃµÄ¡£\n"NOR);
                return 0;
        }

	if( strsrch(name,"Âè") != -1)
        {
		write(HIR"\n¶Ô²»Æğ£¬Õâ¸öÃû×ÖÔÚ" + MUD_NAME + "ÀïÊÇ½ûÖ¹Ê¹ÓÃµÄ¡£\n"NOR);
                return 0;
        }

	if( strsrch(name,"Êº") != -1)
        {
		write(HIR"\n¶Ô²»Æğ£¬Õâ¸öÃû×ÖÔÚ" + MUD_NAME + "ÀïÊÇ½ûÖ¹Ê¹ÓÃµÄ¡£\n"NOR);
                return 0;
        }

        i = strlen(name);
        
	if( (strlen(name) < 2) || (strlen(name) > 12 ) )
	{
		write("\n¶Ô²»Æğ£¬ÄãµÄÖĞÎÄÃû×Ö±ØĞëÊÇ 1 µ½ 6 ¸öÖĞÎÄ×Ö¡£\n");
		return 0;
        }

	while(i--)
	{
		int section;

                if( name[i]<128 )
		{
			write("\n¶Ô²»Æğ£¬ÇëÄúÓÃ¡¸ÖĞÎÄ¡¹È¡Ãû×Ö¡£\n");
                        return 0;
                }

		if( i%2==0 )
		{
			section = name[i] - 160;

			if( (section < 16)
			|| (section > 87) )
			{
				write("\n¶Ô²»Æğ£¬ÇëÄúÊ¹ÓÃ³£ÓÃ¡¸ºº×Ö¡¹È¡Ãû×Ö¡£\n");
				return 0;
			}
		}
	}

	if ( BAN_D->is_banned(name,3))
	{
		write(HIR"\n¶Ô²»Æğ£¬Õâ¸öÃû×ÖÔÚ" + MUD_NAME + "ÀïÊÇ½ûÖ¹Ê¹ÓÃµÄ¡£\n"NOR);
		return 0;
	}

	if(name[0..1] == "ÌÆ")
	{
		write("'ÌÆ'Õâ¸öĞÕÊÏºÍÓÎÏ·ÄÚÈİÓĞ³åÍ»£¬ÇëÁíÍâ»»Ò»¸öĞÕÊÏ¡£\n");
		return 0;
	}

        if(name[0..3] == "Ì¤Ñ©")
        {
                write("'Ì¤Ñ©'Õâ¸öĞÕÊÏºÍÓÎÏ·ÄÚÈİÓĞ³åÍ»£¬ÇëÁíÍâ»»Ò»¸öĞÕÊÏ¡£\n");
                return 0;
        }

	if(permit_add_cname(name))
	{
		write("\n*** ¶Ô²»Æğ£¬Õâ¸öÃû×ÖÒÑ¾­ÓĞÈËÊ¹ÓÃÁË£¬ÔÙÏëÒ»¸ö°É¡£***\n"NOR);
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

	message("channel:sys",sprintf(HIR"¡¾Á¬Ïß¾«Áé¡¿£º%s(%s)¶ÏÏßÁË¡£\n"NOR,
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
