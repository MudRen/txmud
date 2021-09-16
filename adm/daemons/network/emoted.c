// emoted.c

#include <ansi.h>

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
	if( !restore() && !mapp(emote) )
		emote = ([]);
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "emoted"; }

// command_hook() of F_COMMAND call this as an alternate command processor.
// CHANNEL_D also calls this to get emote message.
varargs mixed do_emote(object me, string verb, string arg, int channel_emote,string who,string useverb)
{
	string str, my_gender, target_gender, msg_postfix;
	object target;int mark=0;

	//write (sprintf("here in do_emote verb is %s , arg is %s\n",verb,arg));
       if( !environment(me) ) return 0;

	if ( !mapp(emote) || undefinedp(emote[verb]) ) return 0;
	
//	if ( channel_emote == 2 ) return 0;

	// Determine the pattern to be searched and the target.
	if ( stringp(arg) && arg != "" ) {
			target = present(arg, environment(me));
	           if (!target && channel_emote) target = find_player(arg);
                if (!target && channel_emote) target = find_living(arg);
            	if(!objectp(target)) {
				// If not channel emote, only search target in our environment.
			//	if(!channel_emote) return 0;
				target = find_player(arg);
				mark=1;
				if( !objectp(target) ) return 0;
						}
		
		if( !target->is_character() || !me->visible(target) )
			return notify_fail("��Ҫ��˭�����������\n"); 
            if((int)me->query("ucanemoteto"+target->query("id"))!=1){
                  if(!wizardp(me)&&wizardp(target)&&((int)target->query("noet")==1)&&(channel_emote==0))
			return notify_fail(RED"����"+target->name()+"��æ����. :)\n"NOR+CYN"�м��¾�chat��.\n"NOR); }

// added by find.
                if(target!=me
                        && !wizardp(me)
                        && channel_emote==0
                        && ((string)target->query("env/no_emote") == "all"
                        || (string) target->query("env/no_emote") == (string)me->query("id")))
                        return notify_fail("�Է��Ѿ��ر��� EMOTE Ƶ����\n");
                if(target != me && channel_emote==0 && (string)me->query("env/no_emote") == "all")
                        {
                        me->set("env/no_emote",0);
                        tell_object(me,HIY "��� EMOTE Ƶ�����ˡ�\n" NOR);
                        }
// over.



		target_gender = target->query("gender");
		if( target==me ) {
			msg_postfix = "_self";
			target = 0;
		} else msg_postfix = "_target";
	} else msg_postfix = "";

	my_gender = me->query("gender");

	if( stringp(str = emote[verb]["myself" + msg_postfix]) ) {
		if(useverb=="rumor") str = replace_string(str, "$N", who);
		else 
            str = replace_string(str, "$N", me->name());
		str = replace_string(str, "$P", gender_self(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
		if( objectp(target) ) {
       	     	str = replace_string(str, "$C", RANK_D->query_self_close(target));
                	str = replace_string(str, "$c", RANK_D->query_close(target));
                	str = replace_string(str, "$R", RANK_D->query_respect(target));
                	str = replace_string(str, "$r", RANK_D->query_rude(target));
			str = replace_string(str, "$n", target->name());
			str = replace_string(str, "$p", gender_pronoun(target_gender));
		}
		if( !channel_emote ){
		if(mark==1){
		 message("emote", CYN +"��"+ str + NOR, me);
			}
		else message("emote", CYN + str + NOR, me);

		}
	}

	if( objectp(target) && stringp(str = emote[verb]["target"]) ) {
		if(useverb=="rumor") str = replace_string(str, "$N", who);
		else 
            str = replace_string(str, "$N", me->name());
		str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                str = replace_string(str, "$C", RANK_D->query_self_close(target));
                str = replace_string(str, "$c", RANK_D->query_close(target));
                str = replace_string(str, "$R", RANK_D->query_respect(target));
                str = replace_string(str, "$r", RANK_D->query_rude(target));
		str = replace_string(str, "$n", target->name());
		str = replace_string(str, "$p", gender_self(target_gender));
		if( !channel_emote ){
		if(mark==1)
		 message("emote", CYN +"��"+ str + NOR, target);
		else 	 message("emote", CYN + str + NOR, target);
		}
	}

	if( stringp(str = emote[verb]["others"+msg_postfix]) ) {
		if(useverb=="rumor") str = replace_string(str, "$N", who);
		else 
            str = replace_string(str, "$N", me->name());
		str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
		if( objectp(target) ) {
                	str = replace_string(str, "$C", RANK_D->query_self_close(target));
                	str = replace_string(str, "$c", RANK_D->query_close(target));
                	str = replace_string(str, "$R", RANK_D->query_respect(target));
                	str = replace_string(str, "$r", RANK_D->query_rude(target));
			str = replace_string(str, "$n", target->name());
			str = replace_string(str, "$p", gender_pronoun(target_gender));
		}
		if( !channel_emote )
			{
                  if(mark==1)
			message("emote", CYN +"��"+ str + NOR, environment(me), ({me, target}));
		  else message("emote", CYN + str + NOR, environment(me), ({me, target}));
			}
		else return str;
	}


	// Let NPC know we are doing emote on him.
	if( objectp(target) ) target->relay_emote(me, verb);

	return 1;
}

int set_emote(string pattern, mapping def)
{
	emote[pattern] = def;
	save();
	return 1;
}

int delete_emote(string pattern)
{
	map_delete(emote, pattern);
	save();
	return 1;
}

mapping query_emote(string pattern)
{
	if( !undefinedp(emote[pattern]) ) return emote[pattern];
	else return ([]);
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
                return 0;

        if ( !mapp(emote) || undefinedp(emote[verb]) )
                return "No this emote";

        if( !stringp(str = emote[verb]["others_target"]) )
                return "No this action";

        else
        {
        str=replace_string(str, "$P", gender_pronoun(me->query("gender")));
        str=replace_string(str, "$S", RANK_D->query_self(me));
        str=replace_string(str, "$s", RANK_D->query_self_rude(me));

	log_file("emote",str+"\n");
        return str;
        }
}
// end.

