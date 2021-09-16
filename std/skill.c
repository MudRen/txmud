//	SKill.c
//
// 	This is the standard skill daemon object. All objects defining a skill
//	should inherit this as its skeleton.

// Modified by Find.

#include <origin.h>

inherit F_CLEAN_UP;

// by Find.
#define PUBLIC_SKILL	({"basic","public"})
#define NPC_SKILL	"npc_skill"	/* npc ר�õ��书 */
int valid_action(object me); 
private string pai;
private int yin_yang = 0;
// end.

void create()
{
	seteuid(getuid());
}

//
// valid_learn()
//
// This function is to check if a character should be able to 
// learn/study/practice the skill. The default function just
// returns 1 to allow any characters improve the skill. However,
// a good skill should has its own feature and restriction. Redefine
// this function in your skill object and make it reasonable 
// according to the power of the skill.

int valid_learn(object me) { return 1; }

int valid_effect(object me, object weapon, string action_name, int skill) 
{ 
	return 1;
}

// 
// type()
//
// This function should return the type of the skill. The skill type now
// affects if the skill requires combat exp in order to be learned (see
// /cmds/std/learn.c ) and the ranking of a skill level (see 
// /cmds/usr/skills.c )��
// Currently we have only 2 types of skill: "martial" and "knowledge".

string type() { return "martial"; }

//
// skill_improved()
//
// This function is called when a character's skill has gained a new level.
// You can make some modify to a character according to the skill.

void skill_improved(object me) {}

//
// exert_function()
//
//     This function is used by the "exert" command as specific skill's 
// command parser. This function parses the arguments in the standard form
// (that is, exert <function> [<target>]). When <target> is not present,
// use the character himself as default.
//     In order to use this default exert command parser, you must define
// a function called exert_function_file(string func) in the skill object
// that takes the function name as argument and return the file name that
// defines the specified function. 

int exert_function(object me, string arg)
{
	string func, target, file;
	object target_ob;

	if(!living(me)) return 0; // by Find.

	if( sscanf(arg, "%s %s", func, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) return notify_fail("����û�� " + target + "��\n");
	} else {
		func = arg;
		target_ob = me;
	}

	if( !stringp(file = (string)this_object()->exert_function_file(func))
	||	file_size(file + ".c") <= 0 )
		return 0;

	if(!valid_action(me))
		return notify_fail("��"+pai+"���Ӳ������ñ��Ź�����\n"); // by Find.

	return (int)call_other( file, "exert", me, target_ob);
}

int perform_action(object me, string arg, int flag /* left hand flag */)
{
	string action, target, file;
	object target_ob;

	if(!living(me)) return 0; // by Find.

	if(me->is_perform_busy())
		return notify_fail("����һ�������з���ʹ���꣬��ʱ�޷���ʹ����������ʽ��\n");

	if( sscanf(arg, "%s %s", action, target)==2 )
	{
		target_ob = present(target, environment(me));
		if( !target_ob )
			return notify_fail("����û�� " + target + "��\n");
	}

	else
		action = arg;

	if( !stringp(file = (string)this_object()->perform_action_file(action))
	|| file_size(file + ".c") <= 0 )
		return 0;

	if(!valid_action(me))
		return notify_fail("��"+pai+"���Ӳ���ʹ�ñ��������з���\n"); // by Find.

	return (int)call_other( file, "perform", me, target_ob, flag);
}

int cast_spell(object me, string spell, object target)
{
	string file;

	if(!living(me)) return 0; // by Find.

	notify_fail("����ѡ�õ�����ϵ��û���������ġ�\n");

	if( !stringp(file = (string)this_object()->cast_spell_file(spell))
	||	file_size(file + ".c") <= 0 )
		return 0;

	if(!valid_action(me))
		return notify_fail("��"+pai+"���Ӳ����ñ���������\n"); // by Find.

	return (int)call_other( file, "cast", me, target);
}

int conjure_magic(object me, string spell, object target)
{
	string file;

	if(!living(me)) return 0; // by Find.

	notify_fail("����ѡ�õķ���ϵ��û�����ַ�����\n");

	if( !stringp(file = (string)this_object()->conjure_magic_file(spell))
	||	file_size(file + ".c") <= 0 )
		return 0;

	if(!valid_action(me))
		return notify_fail("��"+pai+"���Ӳ����ñ��ŷ�����\n"); // by Find.

	return (int)call_other( file, "conjure", me, target);
}

int scribe_spell(object me, object ob, string spell)
{
	string file;

	if(!living(me)) return 0; // by Find.

	if( !stringp(file = (string)this_object()->scribe_spell_file(spell))
	||	file_size(file + ".c") <= 0 ){
		return 0;
	}

	if(!valid_action(me))
		return notify_fail("��"+pai+"���Ӳ����ñ������ġ�\n"); // by Find.
	return (int)call_other( file, "scribe", me, ob );
}

// by Find.
int valid_action(object me)
{
	string name,my_class,skill_class;

	if(sscanf(file_name(this_object()),"/daemon/skill/%s/%s",skill_class,name) != 2)
		return 0;

	if(member_array(skill_class,PUBLIC_SKILL) != -1)
		return 1;

	if(!userp(me) || wizardp(me))
		return 1; /*��ʦ������Ҫ�����ܴ������ơ�*/

	pai = to_chinese(skill_class);

	if(!my_class = me->query("class"))
		return 0;

	if(my_class != skill_class)
		return 0;

	return 1;
}

nomask void set_yy(int yy)
{
	if( origin() != ORIGIN_LOCAL )
		return;

	if(!intp(yy))
		return;

	if(yy < 0)
		yin_yang = -1;
	if(yy > 0)
		yin_yang = 1;

	else
		yin_yang = 0;
}

nomask int query_yy()
{
	switch (yin_yang)
	{
		case -1:
			return -1;
		case 1:
			return 1;
		return 0;
	}
}
