//	/adm/daemons/emoted.c
// Modified by Find.

#define NO_VERB		"No this emote"
#define NO_ACTION	"No this action"

#define TIME_DISTANCE	15
#define CHAT_NUM	10
/* 15 ����֮�ڶ������� 10 ��,��Ƶ�� */


#include <ansi.h>
#include <net/macros.h>	// by Find.
inherit F_SAVE;

mapping emote;

//	The emote mapping contains the data base of emote definitions. Each emote
//	is defined in a sub-mapping with the following structure:
//
//	myself	- the message emoter will see
//	target	- the message the target will see when targeted
//	others	- the message others will see when no argument.
//
//	The emote mapping is indexed with the emote 'pattern' instead of emote
//	verb. For example, typing "smile" without argument will cause the daemon
//	search the emote mapping with "smile" as key, and typing "smile someone"
//	will cause the daemon search the emote mapping with "smile $" pattern as
//	the key, while $ means one argument.
//
//	In the message string, the following substitutions will be applied before
//	sending the messages:
//
//	$N		- name of emoter
//	$n		- name of target
//	$P		- pronoun of emoter
//	$p		- pronoun of target
//
//	Original by Annihilator@ESII (11/09/94)
//      $C              - very close call of emoter
//      $c              - close call of target
//      $R              - respect calling of target
//      $r              - rude calling of target
//      $S              - self calling of emoter
//      $s              - self-rude calling of emoter
//      aboved added by Xiang@XKX


void create()
{
	if(clonep())
		return;
	seteuid(getuid());
	if( !restore() && !mapp(emote) )
		emote = ([]);
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "emoted"; }

varargs mixed do_emote(object me, string verb, string arg, int channel_emote,string who,string useverb,int intermud)
{
	string str, my_gender, target_gender, msg_postfix;
	object target;int mark=0;
	int time,count,last_chat;

	if( !environment(me) ) return 0;

	if(environment(me)->query("room_lable") == "welcome" && !wizardp(me))
		return 0;	/* In welcome room can't make emote. */

	if( !mapp(emote) || undefinedp(emote[verb]) )
	{
		if(channel_emote)
			return notify_fail(CYN"û�ж������ emote ��\n"NOR);
		else
			return 0;
	}

	if(userp(me) && me->is_ghost() && !wizardp(me))	// by Find
		return notify_fail(CYN "���Ѿ�û��������������......\n" NOR);

	time=time();
	count=me->query("channel/chat_count");
	last_chat=me->query("channel/last_chat");

	if(me->query("channel/chat_block")
	&& (time - me->query("channel/chat_block"))<0 )
		return notify_fail("��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");

	if(me->query("chblk_on"))
		return notify_fail("��Ľ�̸Ƶ���ر��ˡ�\n");

	if( time - last_chat > TIME_DISTANCE )
	{
		me->set("channel/last_chat",time);
		me->set("channel/chat_count",0);
	}
	else
	{
		count++;
		if( count >= CHAT_NUM && !wizardp(me) )
		{
			me->set("channel/chat_block",time+180);
				return notify_fail("��Ϊ��ʱ���ڶ���̫�࣬��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");
		}
		me->set("channel/chat_count",count);
	}

	if( stringp(arg) && arg != "" )
	{
		target = present(arg, environment(me));
		if(!target && channel_emote)
			target = find_player(arg);
		if(!target && channel_emote)
			target = find_living(arg);
		if(!objectp(target))
		{
			target = find_player(arg);
			mark=1;
			if( !objectp(target) )
				return notify_fail(CYN"��Ҫ��˭�����������\n"NOR);
		}
		
		if( !target->is_character() || !me->visible(target) )
			return notify_fail(CYN"��Ҫ��˭�����������\n"NOR);

		if(target!=me
		&& !wizardp(me)
		&& !channel_emote
		&& ((string)target->query("env/no_emote") == "all"
		|| (string) target->query("env/no_emote") == (string)me->query("id")))
			return notify_fail("�Է��Ѿ��ر��� EMOTE Ƶ����\n");

		if(!wizardp(me)
		&& (target != me)
		&& !channel_emote
		&& ((string)me->query("env/no_emote") == "all"))
		{
			me->delete("env/no_emote");
			tell_object(me,HIY "��� EMOTE Ƶ�����ˡ�\n" NOR);
		}

		target_gender = target->query("gender");
		if( target==me )
		{
			msg_postfix = "_self";
			target = 0;
		}
		else msg_postfix = "_target";
	}
		else msg_postfix = "";

	my_gender = me->query("gender");

	if( stringp(str = emote[verb]["myself" + msg_postfix]) )
	{
		if(useverb=="rumor")
			str = replace_string(str, "$N", who);
		else
		{
			if(intermud)
				replace_string(str, "$N", sprintf( "%s(%s@%s)",me->name(1),capitalize(geteuid(me)),Mud_name()) );

			else
				replace_string(str, "$N", me->name(1) );
		}

		str = replace_string(str, "$P", gender_self(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
		if( objectp(target) )
		{
			str = replace_string(str, "$C", RANK_D->query_self_close(target));
                	str = replace_string(str, "$c", RANK_D->query_close(target));
                	str = replace_string(str, "$R", RANK_D->query_respect(target));
                	str = replace_string(str, "$r", RANK_D->query_rude(target));

			if(intermud)
				str = replace_string(str, "$n", sprintf("%s(%s@%s)",target->name(1),capitalize(target->query("id")),Mud_name()) );
			else if( channel_emote || (environment(me) != environment(target)) )
				str = replace_string(str, "$n", target->name(1));
			else
				str = replace_string(str, "$n", target->name());

			str = replace_string(str, "$p", gender_pronoun(target_gender));
		}

		if( !channel_emote )
		{
			if(mark==1)
				message("emote", CYN +"��"+ str + NOR, me);
			else
				message("emote", CYN + str + NOR, me);
		}
	}

	if( objectp(target) && stringp(str = emote[verb]["target"]) )
	{
		if(useverb=="rumor")
			str = replace_string(str, "$N", who);
		else if(intermud)
			str = replace_string(str, "$N", sprintf("%s(%s@%s)",me->name(1),capitalize(geteuid(me)),Mud_name()) );
		else if( channel_emote || (environment(me) != environment(target)) )
			str = replace_string(str, "$N", me->name(1) );
		else
			str = replace_string(str, "$N", me->name() );

		str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                str = replace_string(str, "$C", RANK_D->query_self_close(target));
                str = replace_string(str, "$c", RANK_D->query_close(target));
                str = replace_string(str, "$R", RANK_D->query_respect(target));
                str = replace_string(str, "$r", RANK_D->query_rude(target));

		if(intermud)
			str = replace_string(str, "$n", sprintf("%s(%s@%s)",target->name(1),capitalize(target->query("id")),Mud_name()) );
		else
			str = replace_string(str, "$n", target->name(1) );

		str = replace_string(str, "$p", gender_self(target_gender));
		if( !channel_emote )
		{
			if(mark==1)
				message("emote", CYN +"��"+ str + NOR, target);
			else
				message("emote", CYN + str + NOR, target);
		}
	}

	if( stringp(str = emote[verb]["others"+msg_postfix]) )
	{
		if(useverb=="rumor")
			str = replace_string(str, "$N", who);
		else if(intermud)
			str = replace_string(str, "$N", sprintf("%s(%s@%s)",me->name(1),capitalize(geteuid(me)),Mud_name()) );
		else if(channel_emote)
			str = replace_string(str, "$N", me->name(1) );
		else
			str = replace_string(str, "$N", me->name() );

		str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
		if( objectp(target) )
		{
                	str = replace_string(str, "$C", RANK_D->query_self_close(target));
                	str = replace_string(str, "$c", RANK_D->query_close(target));
                	str = replace_string(str, "$R", RANK_D->query_respect(target));
                	str = replace_string(str, "$r", RANK_D->query_rude(target));

			if(intermud)
				str = replace_string(str, "$n", sprintf("%s(%s@%s)",target->name(1),capitalize(target->query("id")),Mud_name()) );
			else if(channel_emote || (environment(me) != environment(target)) )
				str = replace_string(str, "$n", target->name(1) );
			else
				str = replace_string(str, "$n", target->name() );

			str = replace_string(str, "$p", gender_pronoun(target_gender));
		}
		if( !channel_emote )
		{
			if(mark==1)
				message("emote", CYN +"��"+ str + NOR, environment(me), ({me, target}));
			else
				message("emote", CYN + str + NOR, environment(me), ({me, target}));
		}
		else
			return str;
	}

	if( objectp(target) )
		target->relay_emote(me, verb);
	else if(environment(me))
		all_inventory(environment(me))->find_emote(me,verb);

	return 1;
}

int set_emote(string pattern, mapping def)
{
	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return 0;
	emote[pattern] = def;
	save();
	return 1;
}

int delete_emote(string pattern)
{
	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return 0;
	if(undefinedp(emote[pattern]))
		return 0;
	map_delete(emote, pattern);
	save();
	return 1;
}

mapping query_emote(string pattern)
{
	if( !undefinedp(emote[pattern]) )
		return emote[pattern];
	else
		return ([]);
}

string *query_all_emote()
{
	return keys(emote);
}

// added by Find.
string query_intermud_emote(object me,string verb)
{
        string str;

        if ( !mapp(emote) || undefinedp(emote[verb]) )
		return NO_VERB;

        if( !stringp(str = emote[verb]["others_target"]) )
		return NO_ACTION;

        else
        {
        str=replace_string(str, "$P", gender_pronoun(me->query("gender")));
        str=replace_string(str, "$S", RANK_D->query_self(me));
        str=replace_string(str, "$s", RANK_D->query_self_rude(me));

        return str;
        }
}

mapping search_emote(string arg)
{
	string *all,a_emote;
	mapping result = ([]);

	if(!stringp(arg) || arg == "" || !sizeof(emote))
		return 0;

	all = keys(emote);
	foreach(a_emote in all)
	{
		if(!undefinedp(emote[a_emote]["others_target"])
		&& strsrch(emote[a_emote]["others_target"],arg) >= 0)
		{
			result += ([ a_emote : emote[a_emote]["others_target"] ]);
			continue;
		}
		if(!undefinedp(emote[a_emote]["others_self"])
		&& strsrch(emote[a_emote]["others_self"],arg) >= 0)
		{
			result += ([ a_emote : emote[a_emote]["others_self"] ]);
			continue;
		}
		if( !undefinedp(emote[a_emote]["others"])
		&&strsrch(emote[a_emote]["others"],arg) >= 0)
		{
			result += ([ a_emote : emote[a_emote]["others"] ]);
			continue;
		}
	}

	return result;
}
